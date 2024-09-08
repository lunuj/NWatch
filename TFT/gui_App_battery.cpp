/*
 * @Author: lunuj 68381451+lunuj@users.noreply.github.com
 * @Date: 2024-03-03 19:22:36
 * @LastEditors: lunuj 68381451+lunuj@users.noreply.github.com
 * @LastEditTime: 2024-04-02 22:36:16
 * @FilePath: /TFT/gui_App_battery.cpp
 * @Description:
 *
 * Copyright (c) 2024 by ${lunuj}, All Rights Reserved.
 */
#include "gui_App_battery.h"

// 3500 2.8
//      2.5
// 2732  = 3.462/147*100
// 2753 3.368
// 2.29115646

// 83224 3024
// 122339

lv_obj_t *gui_App_battery_title;
lv_obj_t * led1;
lv_obj_t *gui_App_battery_text;
lv_obj_t *gui_App_battery_count;
lv_obj_t *gui_App_battery_bat_bar;
lv_timer_t *battery_timer;

float lastv = 0;
int lastvalue = 0;

static void event_key_handler(lv_event_t *e)
{
    switch (e->code)
    {
    case LV_EVENT_KEY:
    {
        const uint32_t key = lv_indev_get_key(lv_indev_get_act());
        lv_obj_t *obj = lv_event_get_target(e);
        SoundRing();

        if (key == LV_KEY_BACKSPACE)
        {
            lv_timer_pause(battery_timer);
            Gui_App_Show();
        }
    }
    break;
    }
}

static void get_battery_timer(lv_timer_t *timer){
    // 充电检测
    if (digitalRead(14) == 1)
    {
        lv_led_on(led1);
    }else{
        lv_led_off(led1);
    }

    char str[100];
    lastv = ((float)analogRead(35))*122339/100000000;
    sprintf(str, "电压 %.1fV", (((float)analogRead(35))*122339/100000000 + lastv) / 2);
    lv_label_set_text(gui_App_battery_text, str);
    lastvalue = (((analogRead(35)-3024)*100/450)>100)?100:((analogRead(35)-3024)*100/450);
    if (lastvalue < 40)
    {
        sprintf(str, "电量 LOW");
        lastvalue = 30;
    }else if(lastvalue < 80){
        sprintf(str, "电量 MID");
        lastvalue = 70;
    }else{
        sprintf(str, "电量 HIGH");   
        lastvalue = 100;
    }
    
    lv_label_set_text(gui_App_battery_count, str);
    lv_bar_set_value(gui_App_battery_bat_bar, lastvalue, LV_ANIM_ON);
}

void Gui_App_Battery_Init()
{
    gui_App_screen[BATTER] = lv_obj_create(NULL);
    lv_group_add_obj(group, gui_App_screen[BATTER]);
    lv_obj_add_event_cb(gui_App_screen[BATTER], event_key_handler, LV_EVENT_KEY, NULL);
    lv_obj_set_scrollbar_mode(gui_App_screen[BATTER], LV_SCROLLBAR_MODE_OFF);

    
    gui_App_battery_title = lv_label_create(gui_App_screen[BATTER]);
    lv_label_set_text(gui_App_battery_title, "状态 ");
    lv_obj_align(gui_App_battery_title, LV_ALIGN_LEFT_MID, 10, -30);
    lv_obj_set_size(gui_App_battery_title, 80, 30);
    lv_obj_set_style_radius(gui_App_battery_title, 5, 0);
    lv_obj_set_style_text_font(gui_App_battery_title, &battery_font_info, 0);
    lv_obj_set_style_text_color(gui_App_battery_title, lv_palette_main(LV_PALETTE_BLUE), 0);
    lv_obj_set_style_text_align(gui_App_battery_title, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_flex_flow(gui_App_battery_title, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(gui_App_battery_title, LV_FLEX_ALIGN_SPACE_AROUND, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_set_style_pad_left(gui_App_battery_title, 7, 0);
    lv_obj_set_style_pad_top(gui_App_battery_title, 7, 0);
    lv_obj_set_style_pad_right(gui_App_battery_title, 0, 0);
    lv_obj_set_style_border_width(gui_App_battery_title, 0, 0);
    lv_obj_set_style_shadow_width(gui_App_battery_title, 20, 0);
    lv_obj_set_style_shadow_color(gui_App_battery_title, lv_palette_main(LV_PALETTE_BLUE), 0);
    lv_obj_set_scrollbar_mode(gui_App_battery_title, LV_SCROLLBAR_MODE_OFF);


    led1  = lv_led_create(gui_App_screen[BATTER]);
    lv_obj_set_size(led1, 15 , 15);
    lv_obj_align(led1, LV_ALIGN_LEFT_MID, 65, -30);
    lv_led_set_brightness(led1, 150);
    lv_led_set_color(led1, lv_palette_main(LV_PALETTE_GREEN));
    lv_led_on(led1);

    gui_App_battery_text = lv_label_create(gui_App_screen[BATTER]);
    lv_label_set_text(gui_App_battery_text, "电压   V");
    lv_obj_align(gui_App_battery_text,LV_ALIGN_LEFT_MID, 10, 5);
    lv_obj_set_size(gui_App_battery_text, 80, 24);
    lv_obj_set_style_radius(gui_App_battery_text, 5, 0);
    lv_obj_set_style_text_font(gui_App_battery_text, &battery_font_info, 0);
    lv_obj_set_style_text_color(gui_App_battery_text, lv_palette_main(LV_PALETTE_BLUE), 0);
    lv_obj_set_style_text_align(gui_App_battery_text, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_flex_flow(gui_App_battery_text, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(gui_App_battery_text, LV_FLEX_ALIGN_SPACE_AROUND, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_set_style_pad_left(gui_App_battery_text, 2, 0);
    lv_obj_set_style_pad_top(gui_App_battery_text, 4, 0);
    lv_obj_set_style_pad_bottom(gui_App_battery_text, 0, 0);
    lv_obj_set_style_pad_right(gui_App_battery_text, 0, 0);
    lv_obj_set_style_border_width(gui_App_battery_text, 0, 0);
    lv_obj_set_style_shadow_width(gui_App_battery_text, 20, 0);
    lv_obj_set_style_shadow_color(gui_App_battery_text, lv_palette_main(LV_PALETTE_BLUE), 0);
    lv_obj_set_scrollbar_mode(gui_App_battery_text, LV_SCROLLBAR_MODE_OFF);

    gui_App_battery_count = lv_label_create(gui_App_screen[BATTER]);
    lv_label_set_text(gui_App_battery_count, "电量  ");
    lv_obj_align(gui_App_battery_count,LV_ALIGN_LEFT_MID, 10, 35);
    lv_obj_set_size(gui_App_battery_count, 80, 24);
    lv_obj_set_style_radius(gui_App_battery_count, 5, 0);
    lv_obj_set_style_text_font(gui_App_battery_count, &battery_font_info, 0);
    lv_obj_set_style_text_color(gui_App_battery_count, lv_palette_main(LV_PALETTE_BLUE), 0);
    lv_obj_set_style_text_align(gui_App_battery_count, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_flex_flow(gui_App_battery_count, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(gui_App_battery_count, LV_FLEX_ALIGN_SPACE_AROUND, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_set_style_pad_left(gui_App_battery_count, 2, 0);
    lv_obj_set_style_pad_top(gui_App_battery_count, 4, 0);
    lv_obj_set_style_pad_bottom(gui_App_battery_count, 0, 0);
    lv_obj_set_style_pad_right(gui_App_battery_count, 0, 0);
    lv_obj_set_style_border_width(gui_App_battery_count, 0, 0);
    lv_obj_set_style_shadow_width(gui_App_battery_count, 20, 0);
    lv_obj_set_style_shadow_color(gui_App_battery_count, lv_palette_main(LV_PALETTE_BLUE), 0);
    lv_obj_set_scrollbar_mode(gui_App_battery_count, LV_SCROLLBAR_MODE_OFF);

    gui_App_battery_bat_bar = lv_bar_create(gui_App_screen[BATTER]);
    lv_obj_set_style_border_color(gui_App_battery_bat_bar, lv_palette_main(LV_PALETTE_BLUE), LV_PART_MAIN);
    lv_obj_set_style_border_width(gui_App_battery_bat_bar, 2, LV_PART_MAIN);
    lv_obj_set_style_pad_all(gui_App_battery_bat_bar, 3, LV_PART_MAIN);
    lv_obj_set_style_radius(gui_App_battery_bat_bar, 7, LV_PART_MAIN);
    lv_obj_set_style_anim_time(gui_App_battery_bat_bar, 200, LV_PART_MAIN);

    lv_obj_set_style_radius(gui_App_battery_bat_bar, 0, LV_PART_INDICATOR);

    lv_obj_set_style_bg_opa(gui_App_battery_bat_bar, LV_OPA_COVER, LV_PART_INDICATOR);
    lv_obj_set_style_bg_color(gui_App_battery_bat_bar, lv_palette_main(LV_PALETTE_GREEN), LV_PART_INDICATOR);
    lv_obj_set_style_bg_grad_color(gui_App_battery_bat_bar, lv_palette_main(LV_PALETTE_RED), LV_PART_INDICATOR);
    lv_obj_set_style_bg_grad_dir(gui_App_battery_bat_bar, LV_GRAD_DIR_VER, LV_PART_INDICATOR);

    lv_obj_set_size(gui_App_battery_bat_bar, 50, 100);
    lv_bar_set_range(gui_App_battery_bat_bar, 0, 100);
    lv_bar_set_value(gui_App_battery_bat_bar, 70, LV_ANIM_OFF);
    lv_obj_align(gui_App_battery_bat_bar, LV_ALIGN_RIGHT_MID, -10, 0);

    battery_timer = lv_timer_create(get_battery_timer, 1000, NULL);
    lv_timer_pause(battery_timer);
}

void Gui_App_Battery_Begin(){
    lv_timer_resume(battery_timer);
}

int Gui_App_Battery_Get(){
    lastvalue = (((analogRead(35)-3024)*100/450)>100)?100:((analogRead(35)-3024)*100/450);
    if (lastvalue < 40)
    {
        lastvalue = 30;
    }else if(lastvalue < 80){
        lastvalue = 70;
    }else{
        lastvalue = 100;
    }
    return lastvalue;
}
#line 1 "/Users/lunuj/Documents/project/esp32/TFT/gui_App.cpp"
/*
 * @Author: lunuj 68381451+lunuj@users.noreply.github.com
 * @Date: 2024-01-08 16:40:55
 * @LastEditors: lunuj 68381451+lunuj@users.noreply.github.com
 * @LastEditTime: 2024-04-02 16:05:59
 * @FilePath: /TFT/gui_App.cpp
 * @Description:
 *
 * Copyright (c) 2024 by ${lunuj}, All Rights Reserved.
 */
#include "gui_App.h"

lv_obj_t *gui_App;
lv_obj_t *gui_app_status_bar;
lv_obj_t *gui_app_status_time;
lv_obj_t *gui_app_status_battery;
lv_obj_t *gui_app_status_alarm;
lv_obj_t *gui_app_status_sound;
lv_obj_t *cont_row_app;
lv_obj_t *label_name;
lv_obj_t *gui_App_screen[6];

int App_list[APP_LIST_LEN] = {0, 1, 2, 3};

const char *app_names_symbol[] = {
    ICON_FONT_WEATHER,
    ICON_FONT_ALARM,
    ICON_FONT_BATTER,
    ICON_FONT_SETTING};

const char *app_names[] = {"Weather", "Alarm", "Battery", "Setting"};

inline void anim_x_cb(void *var, int32_t v)
{
    lv_obj_set_x((lv_obj_t *)var, v);
}

static void icon_add_shadow(lv_obj_t *obj)
{
    lv_obj_set_style_shadow_width(obj, 24, LV_PART_MAIN);
    lv_obj_set_style_bg_color(obj, lv_palette_main(LV_PALETTE_BLUE), LV_PART_MAIN);
    lv_obj_set_style_shadow_color(obj, lv_palette_main(LV_PALETTE_BLUE), LV_PART_MAIN);
}

static void icon_remove_shadow(lv_obj_t *obj)
{
    lv_obj_set_style_shadow_width(obj, 0, LV_PART_MAIN);
    lv_obj_set_style_bg_color(obj, lv_color_white(), LV_PART_MAIN);
    lv_obj_set_style_shadow_color(obj, lv_color_white(), LV_PART_MAIN);
}

static void cont_app_list()
{

    lv_obj_align(lv_obj_get_child(cont_row_app, App_list[0]), LV_ALIGN_CENTER, 0, 0);

    for (int i = 1; i < APP_LIST_LEN - 1; i++)
    {
        lv_obj_align_to(lv_obj_get_child(cont_row_app, App_list[i]), lv_obj_get_child(cont_row_app, App_list[i - 1]), LV_ALIGN_OUT_RIGHT_TOP, 16, 0);
    }
    lv_obj_align_to(lv_obj_get_child(cont_row_app, App_list[APP_LIST_LEN - 1]), lv_obj_get_child(cont_row_app, App_list[0]), LV_ALIGN_OUT_LEFT_TOP, -16, 0);
}

static void cont_app_switch(int32_t id)
{
    uint16_t old_id = App_list[0];
    //定义动画
    lv_anim_t anim_left_1;
    lv_anim_t anim_left_2;
    lv_anim_t anim_left_3;
    lv_anim_t anim_right_1;
    lv_anim_t anim_right_2;
    lv_anim_t anim_right_3;
    icon_remove_shadow(lv_obj_get_child(cont_row_app, old_id));     //移除当前APP阴影

    if (0 > id)
    {
        for (int i = 0; i < APP_LIST_LEN; i++)
        {
            App_list[i] = (App_list[i] + APP_LIST_LEN - 1) % APP_LIST_LEN;
        }
        cont_app_list();    //排列位置
        lv_label_set_text(label_name, app_names[App_list[0]]);  //切换名称
        // 添加动画
        ANIM_LINE_ADD(&anim_left_1, anim_x_cb, lv_anim_path_overshoot, NULL, 250, 0, 0, \
        lv_obj_get_child(cont_row_app, App_list[APP_LIST_LEN - 1]), 32, -16, 0);

        ANIM_LINE_ADD(&anim_left_2, anim_x_cb, lv_anim_path_overshoot, NULL, 250, 0, 0, \
        lv_obj_get_child(cont_row_app, App_list[0]), 48, 0, 0);
        
        ANIM_LINE_ADD(&anim_left_3, anim_x_cb, lv_anim_path_overshoot, NULL, 250, 0, 0, \
        lv_obj_get_child(cont_row_app, App_list[1]), 156, 108, 0);
        
        icon_add_shadow(lv_obj_get_child(cont_row_app, App_list[0]));   //添加滚动后APP阴影

        //动画开始
        lv_anim_start(&anim_left_1);
        lv_anim_start(&anim_left_2);
        lv_anim_start(&anim_left_3);
    }
    else if (0 < id)
    {
        for (int i = 0; i < APP_LIST_LEN; i++)
        {
            App_list[i] = (App_list[i] + 1) % APP_LIST_LEN;
        }
        cont_app_list();
        lv_label_set_text(label_name, app_names[App_list[0]]);
        ANIM_LINE_ADD(&anim_right_1, anim_x_cb, lv_anim_path_overshoot, NULL, 250, 0, 0, \
        
        lv_obj_get_child(cont_row_app, App_list[APP_LIST_LEN - 1]), -64, -16, 0);
        ANIM_LINE_ADD(&anim_right_2, anim_x_cb, lv_anim_path_overshoot, NULL, 250, 0, 0, \
        
        lv_obj_get_child(cont_row_app, App_list[0]), -48, 0, 0);
        ANIM_LINE_ADD(&anim_right_3, anim_x_cb, lv_anim_path_overshoot, NULL, 250, 0, 0, \
        
        lv_obj_get_child(cont_row_app, App_list[1]), 60, 108, 0);
        icon_add_shadow(lv_obj_get_child(cont_row_app, App_list[0]));
        lv_anim_start(&anim_right_1);
        lv_anim_start(&anim_right_2);
        lv_anim_start(&anim_right_3);
    }
}

static void event_key_handler(lv_event_t *e)
{
    lv_anim_t anim;
    switch (e->code)
    {
    case LV_EVENT_KEY:
    {
        const uint32_t key = lv_indev_get_key(lv_indev_get_act());
        lv_obj_t *obj = lv_event_get_target(e);
        SoundRing();

        if (key == LV_KEY_ENTER)
        {
            lv_timer_pause(app_timer);
            lv_disp_load_scr(gui_App_screen[App_list[0]]);
            lv_group_focus_obj(gui_App_screen[App_list[0]]);
            if (App_list[0] == 0)
            {
                Gui_App_Weather_Update();
            }else if(App_list[0] == 2){
                Gui_App_Battery_Begin();
            }

        }
        else if (key == LV_KEY_BACKSPACE)
        {
            lv_timer_pause(app_timer);
            Gui_Main_Show();
        }
        else if (key == LV_KEY_LEFT)
        {
            cont_app_switch(-1);
        }
        else if (key == LV_KEY_RIGHT)
        {
            cont_app_switch(1);
        }
    }
    break;
    }
}

static void gui_app_timer(lv_timer_t *timer)
{
    gettimeofday(&tv_now, NULL);
    now = tv_now.tv_sec;
    localtime_r(&now, &timeinfo);
    if (Gui_Main_GetTimeCurrent() && Gui_App_Weather_GetUpdateStatus() && (Gui_App_Weather_GetLastupdate()/60/60/24 != now/60/60/24))
    {
        Gui_App_Weather_CleanUpdate();
    }
    Gui_StatusBar_Set(true, timeinfo.tm_hour, timeinfo.tm_min, Gui_App_Battery_Get(), Gui_App_Alarm_isClock(), soundval);
}

static void Gui_App_Cont()
{
    cont_row_app = lv_obj_create(gui_App);
    lv_group_add_obj(group, gui_App);
    lv_obj_add_event_cb(gui_App, event_key_handler, LV_EVENT_ALL, NULL);
    lv_obj_set_size(cont_row_app, 160, 78);
    lv_obj_set_style_border_width(cont_row_app, 0, 0);
    lv_obj_set_style_bg_opa(cont_row_app, LV_OPA_0, LV_PART_SCROLLBAR | LV_STATE_DEFAULT); // 禁止显示滚动条
    lv_obj_set_style_bg_opa(cont_row_app, LV_OPA_0, LV_PART_SCROLLBAR | LV_STATE_SCROLLED);
    lv_obj_set_style_pad_all(cont_row_app, 10, 0);
    lv_obj_center(cont_row_app);
}

static void Gui_App_Icon()
{

    uint8_t i;
    uint8_t len = sizeof(app_names) / sizeof(app_names[0]);
    lv_obj_t *old_obj = NULL;
    for (i = 0; i < len; i++)
    {
        lv_obj_t *obj;
        lv_obj_t *label;

        obj = lv_obj_create(cont_row_app);
        lv_group_add_obj(group, obj);
        lv_obj_add_event_cb(obj, event_key_handler, LV_EVENT_KEY, NULL);
        lv_obj_set_size(obj, 48, 48);
        lv_obj_set_style_radius(obj, LV_PCT(50), LV_PART_MAIN);
        lv_obj_clear_flag(obj, LV_OBJ_FLAG_SCROLLABLE);

        label = lv_label_create(obj);
        lv_obj_set_style_text_color(label, lv_palette_main(LV_PALETTE_DEEP_PURPLE), LV_PART_MAIN);
        lv_obj_set_style_text_font(label, &icon_font, LV_PART_MAIN);
        lv_label_set_text(label, app_names_symbol[i]);
        lv_obj_center(label);

        old_obj = obj;
    }
    cont_app_list();
    icon_add_shadow(lv_obj_get_child(cont_row_app, App_list[0]));
}

static void Gui_App_Title()
{
    label_name = lv_label_create(gui_App);
    lv_label_set_text(label_name, app_names[0]);
    lv_obj_set_style_text_color(label_name, lv_palette_main(LV_PALETTE_BLUE), LV_PART_MAIN);
    lv_obj_set_style_text_font(label_name, &lv_font_montserrat_20, LV_PART_MAIN);
    lv_obj_align(label_name, LV_ALIGN_BOTTOM_MID, 0, -1);
}

void Gui_App_Init()
{
    gui_App = lv_obj_create(NULL);
    Gui_App_Cont();
    Gui_App_Icon();
    Gui_App_Title();
    Gui_App_Weather_Init();
    Gui_App_Alarm_Init();
    Gui_App_Setting_Init();
    Gui_App_Battery_Init();

    app_timer = lv_timer_create(gui_app_timer, 1000, NULL);
    lv_timer_pause(app_timer);
}

void Gui_App_Show()
{
    Gui_Statu_Setparent(gui_App);
    lv_disp_load_scr(gui_App);
    lv_group_focus_obj(gui_App);
    lv_timer_resume(app_timer);
}
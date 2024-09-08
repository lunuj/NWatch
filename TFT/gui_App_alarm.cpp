/*
 * @Author: lunuj 68381451+lunuj@users.noreply.github.com
 * @Date: 2024-01-17 23:24:20
 * @LastEditors: lunuj 68381451+lunuj@users.noreply.github.com
 * @LastEditTime: 2024-04-02 18:13:50
 * @FilePath: /TFT/gui_App_alarm.cpp
 * @Description:
 *
 * Copyright (c) 2024 by ${lunuj}, All Rights Reserved.
 */
#include "gui_App_alarm.h"
lv_obj_t *alarm_time_row;
lv_obj_t *alarm_min_h;
lv_obj_t *alarm_min_l;
lv_obj_t *alarm_sec_h;
lv_obj_t *alarm_sec_l;
lv_obj_t *label_titel;
lv_timer_t *daojishi_timer;
lv_timer_t *zhengjishi_timer;
lv_timer_t *alarm_timer;

static int statu = 0;
static int isCheck[3] = {0, 0, 0};
static int part_selscted[3] = {0, 0, 0};

char *title[] = {"倒计时", "秒表", "闹钟"};

static int min_h[3] = {0, 0, 0};
static int min_l[3] = {0, 0, 0};
static int sec_h[3] = {0, 0, 0};
static int sec_l[3] = {0, 0, 0};

static bool isClock =  false;

static void Gui_App_Alarm_SetAlarm(u16_t min_h, u16_t min_l, u16_t sec_h, u16_t sec_l)
{
    lv_roller_set_selected(alarm_min_h, min_h % 6, LV_ANIM_ON);
    lv_roller_set_selected(alarm_min_l, min_l % 10, LV_ANIM_ON);
    lv_roller_set_selected(alarm_sec_h, sec_h % 6, LV_ANIM_ON);
    lv_roller_set_selected(alarm_sec_l, sec_l % 10, LV_ANIM_ON);
}

static void alarm_daojishi(lv_timer_t *timer)
{

    int sum = (min_h[0] * 10 + min_l[0]) * 60 + sec_h[0] * 10 + sec_l[0];
    if (sum == 0)
    {
        part_selscted[0] = 0;
        isCheck[0] = 0;
        statu = 0;
        lv_label_set_text(label_titel, title[statu]);
        Gui_App_Alarm_SetAlarm(min_h[statu], min_l[statu], sec_h[statu], sec_l[statu]);
        lv_timer_pause(daojishi_timer);
        SoundRing();
    }
    else
    {
        sum--;
        min_h[0] = (sum % 3600) / 600;
        min_l[0] = (sum % 600) / 60;
        sec_h[0] = (sum % 60) / 10;
        sec_l[0] = sum % 10;
        if (statu == 0)
        {
            Gui_App_Alarm_SetAlarm(min_h[0], min_l[0], sec_h[0], sec_l[0]);
        }
        
    }
}

static void alarm_zhengjishi(lv_timer_t *timer)
{
    int sum = (min_h[1] * 10 + min_l[1]) * 60 + sec_h[1] * 10 + sec_l[1];
    sum++;
    min_h[1] = (sum % 3600) / 600;
    min_l[1] = (sum % 600) / 60;
    sec_h[1] = (sum % 60) / 10;
    sec_l[1] = sum % 10;
    if (statu == 1)
    {
        Gui_App_Alarm_SetAlarm(min_h[1], min_l[1], sec_h[1], sec_l[1]);
    }
}

static void alarm_dingshi(lv_timer_t *timer)
{
    isClock = true;
    timeval tv_now;
    time_t now;
    struct tm timeinfo;
    static int clock_count = 0;
    gettimeofday(&tv_now, NULL);
    now = tv_now.tv_sec;
    localtime_r(&now, &timeinfo);
    if ((timeinfo.tm_hour / 10) == min_h[2])
    {
        if ((timeinfo.tm_hour % 10) == min_l[2])
        {
            if ((timeinfo.tm_min / 10) == sec_h[2])
            {
                if ((timeinfo.tm_min % 10) == sec_l[2])
                {
                    part_selscted[2] = 0;
                    isCheck[2] = 0;
                    statu = 2;
                    lv_label_set_text(label_titel, title[statu]);
                    Gui_App_Alarm_SetAlarm(min_h[statu], min_l[statu], sec_h[statu], sec_l[statu]);
                    if (clock_count++ > 5)
                    {
                        lv_timer_pause(alarm_timer);
                        isClock  = false;
                        clock_count = 0;
                    }
                    SoundRing();
                }
            }
        }
    }
}

static void turn_select(lv_color_t text_color)
{
    lv_obj_t *alarm_part = NULL;
    switch (part_selscted[statu])
    {
    case 0:
        alarm_part = alarm_min_h;
        break;
    case 1:
        alarm_part = alarm_min_l;
        break;
    case 2:
        alarm_part = alarm_sec_h;
        break;
    case 3:
        alarm_part = alarm_sec_l;
        break;
    default:
        break;
    }
    if (alarm_part == NULL)
    {
        return;
    }

    if (lv_obj_get_style_bg_color(alarm_part, LV_PART_SELECTED).full == lv_palette_main(LV_PALETTE_BLUE).full)
    {
        lv_obj_set_style_text_color(alarm_part, lv_palette_main(LV_PALETTE_BLUE), LV_PART_SELECTED);
        lv_obj_set_style_bg_color(alarm_part, lv_color_hex(0xffffff), LV_PART_SELECTED);
    }
    else
    {
        lv_obj_set_style_text_color(alarm_part, text_color, LV_PART_SELECTED);
        lv_obj_set_style_bg_color(alarm_part, lv_palette_main(LV_PALETTE_BLUE), LV_PART_SELECTED);
    }
}

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
            if (isCheck[statu] == 0)
            {
                Gui_App_Show();
            }
            else if (isCheck[statu] == 1)
            {
                // 开始设置
                isCheck[statu] = 0;
                turn_select(lv_color_hex(0xffffff));
            }
            else if (isCheck[statu] == 2)
            {
                // tingzhij
                isCheck[statu] = 1;
                turn_select(lv_color_hex(0xffffff));
                turn_select(lv_color_hex(0xffffff));
            }
            else if (isCheck[statu] == 3)
            {
                Gui_App_Show();
            }
        }
        else if (key == LV_KEY_ENTER)
        {
            if (isCheck[statu] == 0)
            {
                isCheck[statu] = 1;
                turn_select(lv_color_hex(0xffffff));
            }
            else if (isCheck[statu] == 1)
            {
                // 开始设置
                isCheck[statu] = 2;
                turn_select(lv_palette_main(LV_PALETTE_ORANGE));
                turn_select(lv_palette_main(LV_PALETTE_ORANGE));
            }
            else if (isCheck[statu] == 2)
            {
                // tingzhij
                isCheck[statu] = 3;
                turn_select(lv_color_hex(0xffffff));
                switch (statu)
                {
                case 0:
                    lv_timer_resume(daojishi_timer);
                    break;
                case 1:
                    lv_timer_resume(zhengjishi_timer);
                    break;
                case 2:
                    lv_timer_resume(alarm_timer);
                    break;
                default:
                    break;
                }
            }
            else if (isCheck[statu] == 3)
            {
                isCheck[statu] = 0;
                switch (statu)
                {
                case 0:
                    lv_timer_pause(daojishi_timer);
                    break;
                case 1:
                    lv_timer_pause(zhengjishi_timer);
                    break;
                case 2:
                    lv_timer_pause(alarm_timer);
                    isClock = false;
                    break;
                default:
                    break;
                }
            }
        }
        else if (key == LV_KEY_LEFT)
        {
            if (isCheck[statu] == 0)
            {
                statu = (statu + 2) % 3;
                lv_label_set_text(label_titel, title[statu]);
                Gui_App_Alarm_SetAlarm(min_h[statu], min_l[statu], sec_h[statu], sec_l[statu]);
            }
            else if (isCheck[statu] == 1)
            {
                turn_select(lv_color_hex(0xffffff));

                part_selscted[statu]--;
                if (part_selscted[statu] < 0)
                {
                    part_selscted[statu] = 3;
                }
                if (part_selscted[statu] > 3)
                {
                    part_selscted[statu] = 0;
                }
                turn_select(lv_color_hex(0xffffff));
            }
            else if (isCheck[statu] == 2)
            {
                switch (part_selscted[statu])
                {
                case 0:
                    min_h[statu] = (min_h[statu] + 5) % 6;
                    break;
                case 1:
                    min_l[statu] = (min_l[statu] + 9) % 10;
                    break;
                case 2:
                    sec_h[statu] = (sec_h[statu] + 5) % 6;
                    break;
                case 3:
                    sec_l[statu] = (sec_l[statu] + 9) % 10;
                    break;
                default:
                    break;
                }
                Gui_App_Alarm_SetAlarm(min_h[statu], min_l[statu], sec_h[statu], sec_l[statu]);
            }else if (isCheck[statu] == 3){
                statu = (statu + 2) % 3;
                lv_label_set_text(label_titel, title[statu]);
                Gui_App_Alarm_SetAlarm(min_h[statu], min_l[statu], sec_h[statu], sec_l[statu]);
            }
        }
        else if (key == LV_KEY_RIGHT)
        {
            if (isCheck[statu] == 0)
            {
                statu = (statu + 1) % 3;
                lv_label_set_text(label_titel, title[statu]);
                Gui_App_Alarm_SetAlarm(min_h[statu], min_l[statu], sec_h[statu], sec_l[statu]);
            }
            else if (isCheck[statu] == 1)
            {
                turn_select(lv_color_hex(0xffffff));

                part_selscted[statu]++;
                if (part_selscted[statu] < 0)
                {
                    part_selscted[statu] = 3;
                }
                if (part_selscted[statu] > 3)
                {
                    part_selscted[statu] = 0;
                }
                turn_select(lv_color_hex(0xffffff));
            }
            else if (isCheck[statu] == 2)
            {
                switch (part_selscted[statu])
                {
                case 0:
                    if(statu == 2){
                        min_h[statu] = (min_h[statu] + 1) % 3;
                    }else{
                        min_h[statu] = (min_h[statu] + 1) % 6;
                    }
                    break;
                case 1:
                    if(statu == 2){
                        min_l[statu] = (min_l[statu] + 1) % 4;
                    }else{
                        min_l[statu] = (min_l[statu] + 1) % 10;
                    }
                    break;
                case 2:
                    sec_h[statu] = (sec_h[statu] + 1) % 6;
                    break;
                case 3:
                    sec_l[statu] = (sec_l[statu] + 1) % 10;
                    break;
                default:
                    break;
                }
                Gui_App_Alarm_SetAlarm(min_h[statu], min_l[statu], sec_h[statu], sec_l[statu]);
            }else if (isCheck[statu] == 3){
                statu = (statu + 1) % 3;
                lv_label_set_text(label_titel, title[statu]);
                Gui_App_Alarm_SetAlarm(min_h[statu], min_l[statu], sec_h[statu], sec_l[statu]);
            }
        }

    }
    break;
    }
}

void Gui_App_Alarm_Init()
{

    gui_App_screen[ALARM] = lv_obj_create(NULL);
    lv_group_add_obj(group, gui_App_screen[ALARM]);
    lv_obj_add_event_cb(gui_App_screen[ALARM], event_key_handler, LV_EVENT_KEY, NULL);
    lv_obj_clear_flag(gui_App_screen[ALARM], LV_OBJ_FLAG_SCROLLABLE); /// Flags
    lv_obj_set_style_pad_all(gui_App_screen[ALARM], 0, 0);

    label_titel = lv_label_create(gui_App_screen[ALARM]);
    lv_obj_set_size(label_titel, 120, 30);
    lv_label_set_text(label_titel, "倒计时");
    lv_obj_set_style_radius(label_titel, 5, 0);
    lv_obj_align(label_titel, LV_ALIGN_TOP_MID, 0, 6);
    lv_obj_set_style_text_font(label_titel, &alarm_font_24, 0);
    lv_obj_set_style_text_color(label_titel, lv_palette_main(LV_PALETTE_BLUE), 0);
    lv_obj_set_style_text_align(label_titel, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_flex_flow(label_titel, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(label_titel, LV_FLEX_ALIGN_SPACE_AROUND, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_set_style_pad_left(label_titel, 10, 0);
    lv_obj_set_style_pad_top(label_titel, 2, 0);
    lv_obj_set_style_pad_right(label_titel, 10, 0);
    lv_obj_set_style_border_width(label_titel, 0, 0);
    lv_obj_set_style_shadow_width(label_titel, 20, 0);
    lv_obj_set_style_shadow_color(label_titel, lv_palette_main(LV_PALETTE_BLUE), 0);
    lv_obj_set_scrollbar_mode(label_titel, LV_SCROLLBAR_MODE_OFF);

    alarm_time_row = lv_obj_create(gui_App_screen[ALARM]);
    lv_obj_set_size(alarm_time_row, 140, 50);
    lv_obj_set_style_pad_all(alarm_time_row, 5, 0);
    lv_obj_align(alarm_time_row, LV_ALIGN_TOP_MID, 0, 45);
    lv_obj_set_flex_flow(alarm_time_row, LV_FLEX_FLOW_ROW);
    lv_obj_set_style_text_font(alarm_time_row, &alarm_font, 0);
    lv_obj_set_flex_align(alarm_time_row, LV_FLEX_ALIGN_SPACE_AROUND, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_set_style_pad_left(alarm_time_row, 10, 0);
    lv_obj_set_style_pad_right(alarm_time_row, 10, 0);
    lv_obj_set_style_border_width(alarm_time_row, 0, 0);
    lv_obj_set_style_shadow_width(alarm_time_row, 20, 0);
    lv_obj_set_style_shadow_color(alarm_time_row, lv_palette_main(LV_PALETTE_BLUE), 0);
    lv_obj_set_scrollbar_mode(alarm_time_row, LV_SCROLLBAR_MODE_OFF);

    // 分钟
    alarm_min_h = lv_roller_create(alarm_time_row);

    lv_obj_set_size(alarm_min_h, 28, 50);
    lv_obj_set_style_border_width(alarm_min_h, 0, 0);
    lv_obj_set_style_pad_all(alarm_min_h, 0, 0);
    lv_obj_set_style_anim_time(alarm_min_h, 350, 0);
    lv_obj_set_style_text_color(alarm_min_h, lv_palette_main(LV_PALETTE_BLUE), LV_PART_SELECTED);
    lv_obj_set_style_bg_color(alarm_min_h, lv_color_hex(0xffffff), LV_PART_SELECTED);

    lv_roller_set_options(alarm_min_h, TIME_STRING, LV_ROLLER_MODE_INFINITE);
    lv_roller_set_visible_row_count(alarm_min_h, 1);

    alarm_min_l = lv_roller_create(alarm_time_row);

    lv_obj_set_size(alarm_min_l, 28, 50);
    lv_obj_set_style_border_width(alarm_min_l, 0, 0);
    lv_obj_set_style_pad_all(alarm_min_l, 0, 0);
    lv_obj_set_style_anim_time(alarm_min_l, 350, 0);
    lv_obj_set_style_text_color(alarm_min_l, lv_palette_main(LV_PALETTE_BLUE), LV_PART_SELECTED);
    lv_obj_set_style_bg_color(alarm_min_l, lv_color_hex(0xffffff), LV_PART_SELECTED);

    lv_roller_set_options(alarm_min_l, TIME_STRING, LV_ROLLER_MODE_INFINITE);
    lv_roller_set_visible_row_count(alarm_min_l, 1);

    lv_obj_t *label_sec_dot = lv_label_create(alarm_time_row);
    lv_obj_set_width(label_sec_dot, 7);
    lv_label_set_text(label_sec_dot, ":");
    lv_obj_set_style_opa(label_sec_dot, LV_OPA_MAX, LV_PART_MAIN);
    // 秒钟
    alarm_sec_h = lv_roller_create(alarm_time_row);

    lv_obj_set_size(alarm_sec_h, 28, 50);
    lv_obj_set_style_border_width(alarm_sec_h, 0, 0);
    lv_obj_set_style_pad_all(alarm_sec_h, 0, 0);
    lv_obj_set_style_anim_time(alarm_sec_h, 100, 0);
    // lv_obj_set_style_text_font(alarm_sec_h, &lv_font_montserrat_48, 0);
    lv_obj_set_style_text_color(alarm_sec_h, lv_palette_main(LV_PALETTE_BLUE), LV_PART_SELECTED);
    lv_obj_set_style_bg_color(alarm_sec_h, lv_color_hex(0xffffff), LV_PART_SELECTED);

    lv_roller_set_options(alarm_sec_h, TIME_STRING, LV_ROLLER_MODE_INFINITE);
    lv_roller_set_visible_row_count(alarm_sec_h, 1);

    alarm_sec_l = lv_roller_create(alarm_time_row);

    lv_obj_set_size(alarm_sec_l, 28, 50);
    lv_obj_set_style_border_width(alarm_sec_l, 0, 0);
    lv_obj_set_style_pad_all(alarm_sec_l, 0, 0);
    lv_obj_set_style_anim_time(alarm_sec_l, 100, 0);
    lv_obj_set_style_text_color(alarm_sec_l, lv_palette_main(LV_PALETTE_BLUE), LV_PART_SELECTED);
    lv_obj_set_style_bg_color(alarm_sec_l, lv_color_hex(0xffffff), LV_PART_SELECTED);

    lv_roller_set_options(alarm_sec_l, TIME_STRING, LV_ROLLER_MODE_INFINITE);
    lv_roller_set_visible_row_count(alarm_sec_l, 1);

    lv_obj_t *label_date = lv_label_create(gui_App_screen[ALARM]);
    lv_obj_set_size(label_date, 160, 18);
    lv_label_set_text(label_date,"确定  返回  左移  右移");
    lv_obj_set_style_text_font(label_date, &alarm_font_info, 0);
    lv_obj_set_style_text_color(label_date, lv_palette_main(LV_PALETTE_BLUE), 0);
    lv_obj_align(label_date, LV_ALIGN_BOTTOM_MID, 0, -2);

    daojishi_timer = lv_timer_create(alarm_daojishi, 1000, NULL);
    zhengjishi_timer = lv_timer_create(alarm_zhengjishi, 1000, NULL);
    alarm_timer = lv_timer_create(alarm_dingshi, 1000, NULL);
    lv_timer_pause(daojishi_timer);
    lv_timer_pause(zhengjishi_timer);
    lv_timer_pause(alarm_timer);
}

bool Gui_App_Alarm_isClock(){
    return isClock;
}
#line 1 "/Users/lunuj/Documents/project/esp32/TFT/gui_Main.cpp"
/*
 * @Author: lunuj 68381451+lunuj@users.noreply.github.com
 * @Date: 2024-01-04 17:10:58
 * @LastEditors: lunuj 68381451+lunuj@users.noreply.github.com
 * @LastEditTime: 2024-04-01 16:43:48
 * @FilePath: /TFT/gui_Main.cpp
 * @Description: 
 * 
 * Copyright (c) 2024 by ${lunuj}, All Rights Reserved. 
 */
/*
 * @Author: lunuj 68381451+lunuj@users.noreply.github.com
 * @Date: 2024-01-04 17:10:58
 * @LastEditors: lunuj 68381451+lunuj@users.noreply.github.com
 * @LastEditTime: 2024-03-30 17:07:50
 * @FilePath: /TFT/gui_Main.cpp
 * @Description:
 *
 * Copyright (c) 2024 by ${lunuj}, All Rights Reserved.
 */
#include "gui_Main.h"

lv_obj_t *gui_Main;
lv_obj_t *cont_time_row;
lv_obj_t *roller_hour_h;
lv_obj_t *roller_hour_l;
lv_obj_t *roller_min_h;
lv_obj_t *roller_min_l;
lv_obj_t *roller_sec_h;
lv_obj_t *roller_sec_l;
lv_obj_t *bar_sec;
lv_obj_t *label_date;
lv_obj_t *cont_thp;
lv_obj_t *label_temp;
lv_obj_t *bar_temp;
lv_obj_t *label_humi;
lv_obj_t *bar_humi;
lv_obj_t *meter_press;
lv_meter_scale_t *scale;
lv_meter_indicator_t *indic_press;
lv_obj_t *label_press;

char strftime_buf[64];
unsigned int timetoupdate = 0;
unsigned long start = 0;
static bool time_current = true;

static void event_key_handler(lv_event_t *e)
{
    switch (e->code)
    {
    case LV_EVENT_KEY:
    {
        SoundRing();
        const uint32_t key = lv_indev_get_key(lv_indev_get_act());
        lv_obj_t *obj = lv_event_get_target(e);

        if (key == LV_KEY_ENTER)
        {
            lv_timer_pause(main_timer);
            Gui_App_Show();
        }
        else if (key == LV_KEY_BACKSPACE)
        {
            Gui_Oled_Off();
        }
        else if (key == LV_KEY_LEFT)
        {
            Gui_Oled_Off();
        }
        else if (key == LV_KEY_RIGHT)
        {
            Gui_Oled_Off();
        }
    }
    break;
    }
}

void Gui_Main_SetTimeCurrent(bool istime_current){
    time_current = istime_current;
}

bool Gui_Main_GetTimeCurrent(){
    return time_current;
}

void gui_main_timer(lv_timer_t *timer)
{
    
    if (Wifi_IsWiFiConnected() == 1)
    {
        if (start == 0 || (timetoupdate > 0 && millis() - start > WIFI_TIME_UPDATE*timetoupdate))
        {
            Wifi_getTime(&timeinfo);
            start = millis();
            now = mktime(&timeinfo);
            tv_now.tv_sec = now + 60 * 60 * 8;
            tv_now.tv_usec = 0;
            settimeofday(&tv_now, NULL);
            time_current = true;
        }
    }

    gettimeofday(&tv_now, NULL);
    now = tv_now.tv_sec;
    localtime_r(&now, &timeinfo);
    
    if ((Gui_App_Weather_GetLastupdate()/60/60/24 != now/60/60/24) && time_current)
    {
        if (Gui_App_Weather_GetUpdateStatus())
        {
            Gui_App_Weather_CleanUpdate();
        }else{
            Gui_App_Weather_Update();
        }
    }


    Gui_StatusBar_Set(false, timeinfo.tm_hour, timeinfo.tm_min, Gui_App_Battery_Get(), Gui_App_Alarm_isClock(), (soundval - 0x80));
    Gui_Main_SetTime(timeinfo.tm_hour, timeinfo.tm_min, timeinfo.tm_sec);
    Gui_Main_SetTimeBar(timeinfo.tm_sec);
    Gui_Main_SetData(timeinfo.tm_year + 1900, timeinfo.tm_mon + 1, timeinfo.tm_mday, (WEEK)(timeinfo.tm_wday));

    Gui_Main_SetTemp();
        
    Gui_Main_SetHpa(temperatureRead());
}

static void Gui_Main_Time()
{
    // 时间容器
    cont_time_row = lv_obj_create(gui_Main);
    lv_obj_set_size(cont_time_row, 140, 30);
    lv_obj_set_style_pad_all(cont_time_row, 5, 0);
    lv_obj_align(cont_time_row, LV_ALIGN_TOP_MID, 0, 24);
    lv_obj_set_flex_flow(cont_time_row, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(cont_time_row, LV_FLEX_ALIGN_SPACE_AROUND, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_set_style_pad_left(cont_time_row, 10, 0);
    lv_obj_set_style_pad_right(cont_time_row, 10, 0);
    lv_obj_set_style_border_width(cont_time_row, 0, 0);
    lv_obj_set_style_shadow_width(cont_time_row, 20, 0);
    lv_obj_set_style_shadow_color(cont_time_row, lv_palette_main(LV_PALETTE_BLUE), 0);
    lv_obj_set_scrollbar_mode(cont_time_row, LV_SCROLLBAR_MODE_OFF);
    // 小时
    roller_hour_h = lv_roller_create(cont_time_row);

    lv_obj_set_size(roller_hour_h, 19, 30);
    lv_obj_set_style_border_width(roller_hour_h, 0, LV_PART_MAIN);
    lv_obj_set_style_border_width(roller_hour_h, 0, LV_PART_SELECTED);
    lv_obj_set_style_pad_all(roller_hour_h, 0, LV_PART_MAIN);
    lv_obj_set_style_pad_all(roller_hour_h, 0, LV_PART_SELECTED);

    lv_obj_set_style_anim_time(roller_hour_h, 200, 0);
    lv_obj_set_style_text_font(roller_hour_h, &lv_font_montserrat_30, 0);
    lv_obj_set_style_text_color(roller_hour_h, lv_palette_main(LV_PALETTE_BLUE), LV_PART_SELECTED);
    lv_obj_set_style_bg_color(roller_hour_h, lv_color_hex(0xffffff), LV_PART_SELECTED);

    lv_roller_set_options(roller_hour_h, TIME_STRING, LV_ROLLER_MODE_INFINITE);
    lv_roller_set_visible_row_count(roller_hour_h, 1);

    roller_hour_l = lv_roller_create(cont_time_row);

    lv_obj_set_size(roller_hour_l, 19, 30);
    lv_obj_set_style_border_width(roller_hour_l, 0, 0);
    lv_obj_set_style_pad_all(roller_hour_l, 0, 0);
    lv_obj_set_style_anim_time(roller_hour_l, 200, 0);
    lv_obj_set_style_text_font(roller_hour_l, &lv_font_montserrat_30, 0);
    lv_obj_set_style_text_color(roller_hour_l, lv_palette_main(LV_PALETTE_BLUE), LV_PART_SELECTED);
    lv_obj_set_style_bg_color(roller_hour_l, lv_color_hex(0xffffff), LV_PART_SELECTED);

    lv_roller_set_options(roller_hour_l, TIME_STRING, LV_ROLLER_MODE_INFINITE);
    lv_roller_set_visible_row_count(roller_hour_l, 1);

    lv_obj_t *label_min_dot = lv_label_create(cont_time_row);
    lv_label_set_text(label_min_dot, ":");
    lv_obj_set_style_opa(label_min_dot, LV_OPA_MAX, LV_PART_MAIN);
    lv_obj_set_style_text_font(label_min_dot, &lv_font_montserrat_30, 0);
    // 分钟
    roller_min_h = lv_roller_create(cont_time_row);

    lv_obj_set_size(roller_min_h, 19, 24);
    lv_obj_set_style_border_width(roller_min_h, 0, 0);
    lv_obj_set_style_pad_all(roller_min_h, 0, 0);
    lv_obj_set_style_anim_time(roller_min_h, 200, 0);
    lv_obj_set_style_text_font(roller_min_h, &lv_font_montserrat_30, 0);
    lv_obj_set_style_text_color(roller_min_h, lv_palette_main(LV_PALETTE_BLUE), LV_PART_SELECTED);
    lv_obj_set_style_bg_color(roller_min_h, lv_color_hex(0xffffff), LV_PART_SELECTED);

    lv_roller_set_options(roller_min_h, TIME_STRING, LV_ROLLER_MODE_INFINITE);
    lv_roller_set_visible_row_count(roller_min_h, 1);

    roller_min_l = lv_roller_create(cont_time_row);

    lv_obj_set_size(roller_min_l, 19, 24);
    lv_obj_set_style_border_width(roller_min_l, 0, 0);
    lv_obj_set_style_pad_all(roller_min_l, 0, 0);
    lv_obj_set_style_anim_time(roller_min_l, 200, 0);
    lv_obj_set_style_text_font(roller_min_l, &lv_font_montserrat_30, 0);
    lv_obj_set_style_text_color(roller_min_l, lv_palette_main(LV_PALETTE_BLUE), LV_PART_SELECTED);
    lv_obj_set_style_bg_color(roller_min_l, lv_color_hex(0xffffff), LV_PART_SELECTED);

    lv_roller_set_options(roller_min_l, TIME_STRING, LV_ROLLER_MODE_INFINITE);
    lv_roller_set_visible_row_count(roller_min_l, 1);

    lv_obj_t *label_sec_dot = lv_label_create(cont_time_row);
    lv_label_set_text(label_sec_dot, ":");
    lv_obj_set_style_opa(label_sec_dot, LV_OPA_MAX, LV_PART_MAIN);
    lv_obj_set_style_text_font(label_sec_dot, &lv_font_montserrat_30, 0);
    // 秒钟
    roller_sec_h = lv_roller_create(cont_time_row);

    lv_obj_set_size(roller_sec_h, 19, 24);
    lv_obj_set_style_border_width(roller_sec_h, 0, 0);
    lv_obj_set_style_pad_all(roller_sec_h, 0, 0);
    lv_obj_set_style_anim_time(roller_sec_h, 100, 0);
    lv_obj_set_style_text_font(roller_sec_h, &lv_font_montserrat_30, 0);
    lv_obj_set_style_text_color(roller_sec_h, lv_palette_main(LV_PALETTE_BLUE), LV_PART_SELECTED);
    lv_obj_set_style_bg_color(roller_sec_h, lv_color_hex(0xffffff), LV_PART_SELECTED);

    lv_roller_set_options(roller_sec_h, TIME_STRING, LV_ROLLER_MODE_INFINITE);
    lv_roller_set_visible_row_count(roller_sec_h, 1);

    roller_sec_l = lv_roller_create(cont_time_row);

    lv_obj_set_size(roller_sec_l, 19, 24);
    lv_obj_set_style_border_width(roller_sec_l, 0, 0);
    lv_obj_set_style_pad_all(roller_sec_l, 0, 0);
    lv_obj_set_style_anim_time(roller_sec_l, 100, 0);
    lv_obj_set_style_text_font(roller_sec_l, &lv_font_montserrat_30, 0);
    lv_obj_set_style_text_color(roller_sec_l, lv_palette_main(LV_PALETTE_BLUE), LV_PART_SELECTED);
    lv_obj_set_style_bg_color(roller_sec_l, lv_color_hex(0xffffff), LV_PART_SELECTED);

    lv_roller_set_options(roller_sec_l, TIME_STRING, LV_ROLLER_MODE_INFINITE);
    lv_roller_set_visible_row_count(roller_sec_l, 1);
}

static void Gui_Main_TimeBar()
{
    bar_sec = lv_bar_create(gui_Main);

    lv_obj_set_style_border_color(bar_sec, lv_palette_main(LV_PALETTE_BLUE), LV_PART_MAIN);
    lv_obj_set_style_border_width(bar_sec, 1, LV_PART_MAIN);
    lv_obj_set_style_pad_all(bar_sec, 3, LV_PART_MAIN);
    lv_obj_set_style_anim_time(bar_sec, 200, LV_PART_MAIN);
    lv_obj_set_style_bg_color(bar_sec, lv_color_white(), LV_PART_MAIN);

    lv_obj_set_style_bg_opa(bar_sec, LV_OPA_COVER, LV_PART_INDICATOR);
    lv_obj_set_style_bg_color(bar_sec, lv_palette_main(LV_PALETTE_RED), LV_PART_INDICATOR);

    lv_obj_set_size(bar_sec, 120, 10);
    lv_bar_set_mode(bar_sec, LV_BAR_MODE_RANGE);
    lv_bar_set_range(bar_sec, 0, 59); // <--↑-->
    lv_obj_align_to(bar_sec, cont_time_row, LV_ALIGN_OUT_BOTTOM_MID, 0, 5);
    lv_bar_set_start_value(bar_sec, 0, LV_ANIM_OFF);
}

static void Gui_Main_Data()
{
    label_date = lv_label_create(gui_Main);
    lv_label_set_text(label_date, "2000/00/00  MON");
    lv_obj_set_style_text_font(label_date, &lv_font_montserrat_8, 0);
    lv_obj_set_style_text_color(label_date, lv_palette_main(LV_PALETTE_BLUE), 0);
    lv_obj_align_to(label_date, bar_sec, LV_ALIGN_OUT_BOTTOM_MID, 0, 0);
}

static void Gui_Main_Temp()
{
    cont_thp = lv_obj_create(gui_Main);
    lv_obj_set_size(cont_thp, 80, 48);
    lv_obj_align(cont_thp, LV_ALIGN_BOTTOM_LEFT, 2, 0);
    lv_obj_set_style_pad_all(cont_thp, 0, 0);
    lv_obj_set_style_bg_color(cont_thp, lv_color_hex(0xffffff), 0);
    lv_obj_set_scrollbar_mode(cont_thp, LV_SCROLLBAR_MODE_OFF);

    label_temp = lv_label_create(cont_thp);
    lv_obj_align(label_temp, LV_ALIGN_LEFT_MID, 3, -10);
    lv_obj_set_size(label_temp, 40, 10);
    lv_label_set_text(label_temp, "Na");
    lv_obj_set_style_text_font(label_temp, &lv_font_montserrat_10, 0);
    lv_obj_set_style_text_color(label_temp, lv_palette_main(LV_PALETTE_BLUE), 0);

    bar_temp = lv_bar_create(cont_thp);
    lv_obj_align(bar_temp, LV_ALIGN_RIGHT_MID, -3, -10);
    lv_obj_set_size(bar_temp, 34, 12);
    lv_obj_set_style_bg_opa(bar_temp, LV_OPA_COVER, LV_PART_INDICATOR);
    lv_obj_set_style_bg_color(bar_temp, lv_palette_main(LV_PALETTE_BLUE), LV_PART_INDICATOR);
    lv_obj_set_style_bg_grad_color(bar_temp, lv_palette_main(LV_PALETTE_RED), LV_PART_INDICATOR);
    lv_obj_set_style_bg_grad_dir(bar_temp, LV_GRAD_DIR_HOR, LV_PART_INDICATOR);
    lv_bar_set_range(bar_temp, 0, 50);

    label_humi = lv_label_create(cont_thp);
    lv_obj_align(label_humi, LV_ALIGN_LEFT_MID, 3, 10);
    lv_obj_set_size(label_humi, 40, 10);
    lv_label_set_text(label_humi, "Na");
    lv_obj_set_style_text_font(label_humi, &lv_font_montserrat_10, 0);
    lv_obj_set_style_text_color(label_humi, lv_palette_main(LV_PALETTE_BLUE), 0);

    bar_humi = lv_bar_create(cont_thp);
    lv_obj_align(bar_humi, LV_ALIGN_RIGHT_MID, -3, 10);
    lv_obj_set_size(bar_humi, 34, 12);
    lv_obj_set_style_bg_opa(bar_humi, LV_OPA_COVER, LV_PART_INDICATOR);
    lv_obj_set_style_bg_color(bar_humi, lv_palette_main(LV_PALETTE_BLUE), LV_PART_INDICATOR);
    lv_obj_set_style_bg_grad_color(bar_humi, lv_palette_main(LV_PALETTE_RED), LV_PART_INDICATOR);
    lv_obj_set_style_bg_grad_dir(bar_humi, LV_GRAD_DIR_HOR, LV_PART_INDICATOR);
    lv_bar_set_range(bar_humi, 0, 100);
}

static void Gui_Main_Hpa()
{
    meter_press = lv_meter_create(gui_Main);
    lv_obj_set_size(meter_press, 56, 56);
    lv_obj_align(meter_press, LV_ALIGN_BOTTOM_RIGHT, 0, 0);
    lv_obj_remove_style(meter_press, NULL, LV_PART_INDICATOR);
    lv_obj_set_scrollbar_mode(meter_press, LV_SCROLLBAR_MODE_OFF);
    lv_obj_set_style_clip_corner(meter_press, true, 0);

    scale = lv_meter_add_scale(meter_press);
    lv_meter_set_scale_ticks(meter_press, scale, 8, 1, 3, lv_palette_main(LV_PALETTE_GREY));
    lv_meter_set_scale_range(meter_press, scale, 0, 800, 240, 90);

    indic_press = lv_meter_add_arc(meter_press, scale, 8, lv_palette_main(LV_PALETTE_BLUE), 10);
    lv_meter_set_indicator_end_value(meter_press, indic_press, 0);

    label_press = lv_label_create(meter_press);
    lv_label_set_text(label_press, "12.6");
    lv_obj_set_style_text_align(label_press, LV_TEXT_ALIGN_CENTER, 0);
    lv_obj_set_style_text_font(label_press, &lv_font_montserrat_12, 0);
    lv_obj_set_style_text_color(label_press, lv_palette_main(LV_PALETTE_BLUE), 0);
    lv_obj_align(label_press, LV_ALIGN_BOTTOM_RIGHT, 10, -2);
}

void Gui_Main_SetTime(int hour, int min, int sec)
{
    lv_roller_set_selected(roller_sec_l, sec % 10, LV_ANIM_ON);
    lv_roller_set_selected(roller_sec_h, sec / 10, LV_ANIM_ON);
    lv_roller_set_selected(roller_min_l, min % 10, LV_ANIM_ON);
    lv_roller_set_selected(roller_min_h, min / 10, LV_ANIM_ON);
    lv_roller_set_selected(roller_hour_l, hour % 10, LV_ANIM_ON);
    lv_roller_set_selected(roller_hour_h, hour / 10, LV_ANIM_ON);
}

void Gui_Main_SetTimeBar(uint16_t sec)
{
    lv_bar_set_value(bar_sec, sec % 60, LV_ANIM_ON);
}

void Gui_Main_SetData(uint16_t year, uint16_t mon, uint16_t day, WEEK week)
{
    char str[256];
    memset(str, 256, sizeof(char));
    switch (week)
    {
    case 0:
        sprintf(str, "%4d/%02d/%02d %s", year, mon, day, "Sun");
        break;
    case 1:
        sprintf(str, "%4d/%02d/%02d %s", year, mon, day, "Mon");
        break;
    case 2:
        sprintf(str, "%4d/%02d/%02d %s", year, mon, day, "Tue");
        break;
    case 3:
        sprintf(str, "%4d/%02d/%02d %s", year, mon, day, "Wed");
        break;
    case 4:
        sprintf(str, "%4d/%02d/%02d %s", year, mon, day, "Thu");
        break;
    case 5:
        sprintf(str, "%4d/%02d/%02d %s", year, mon, day, "Fir");
        break;
    case 6:
        sprintf(str, "%4d/%02d/%02d %s", year, mon, day, "Sat");
        break;
    default:
        sprintf(str, "error");
        break;
    }
    lv_label_set_text(label_date, str);
}

void Gui_Main_SetTemp()
{
    if (Wifi_IsWiFiConnected() == 1 && time_current)
    {
        char high[10], low[10];
        Gui_App_weather_GetTemp(high, low);
        char str[128];
        memset(str, 128, sizeof(char));
        sprintf(str, "%s*C", high);
        lv_label_set_text(label_temp, str);
        lv_bar_set_value(bar_temp, atoi(high), LV_ANIM_ON);

        memset(str, 128, sizeof(char));
        sprintf(str, "%s*C", low);
        lv_label_set_text(label_humi, str);
        lv_bar_set_value(bar_humi, atoi(low), LV_ANIM_ON);
    }else{
        lv_label_set_text(label_temp, "Na");
        lv_bar_set_value(bar_temp, 0, LV_ANIM_ON);
        lv_label_set_text(label_humi, "Na");
        lv_bar_set_value(bar_humi, 0, LV_ANIM_ON);
    }
}

void Gui_Main_SetHpa(float Pa)
{
    char str[256];
    memset(str, 128, sizeof(char));
    sprintf(str, "%0.1f", Pa);
    lv_label_set_text(label_press, str);
    lv_meter_set_indicator_end_value(meter_press, indic_press, (int)(Pa*10)/1);
}

void Gui_Main_SetTimetoupdate(unsigned int time){
    switch (time%8)
    {
    case 0:
        timetoupdate = 0;   //关闭
        break;
    case 1:
        timetoupdate = 1;   //15m
        break;
    case 2:
        timetoupdate = 2;   //30m   
        break;
    case 3:
        timetoupdate = 4;   //1h   
        break;
    case 4:
        timetoupdate = 24;   //6h   
        break;
    case 5:
        timetoupdate = 48;   //12h   
        break;
    case 6:
        timetoupdate = 96;   //24h   
        break;
    default:
        timetoupdate  = 0;
        break;
    }
}

void Gui_Main_Init()
{
    gui_Main = lv_obj_create(NULL);
    lv_obj_set_size(gui_Main, 160, 128);
    timeinfo.tm_year = 2023 - 1900; // 将数组的时间赋值给日期时间结构体
    timeinfo.tm_mon = 12 - 1;
    timeinfo.tm_mday = 31;
    timeinfo.tm_hour = 23;
    timeinfo.tm_min = 59;
    timeinfo.tm_sec = 57;
    timeinfo.tm_wday = 6;
    now = mktime(&timeinfo);
    tv_now.tv_sec = now;
    tv_now.tv_usec = 0;
    settimeofday(&tv_now, NULL);

    Wifi_Config_Init();

    if (Wifi_IsWiFiConnected())
    {
        Wifi_getTime(&timeinfo);
        now = mktime(&timeinfo);
        tv_now.tv_sec = now + 60 * 60 * 8;
        tv_now.tv_usec = 0;
        settimeofday(&tv_now, NULL);
    }

    lv_group_add_obj(group, gui_Main);
    lv_obj_add_event_cb(gui_Main, event_key_handler, LV_EVENT_ALL, NULL);
    lv_obj_set_scrollbar_mode(gui_Main, LV_SCROLLBAR_MODE_OFF);

    // Gui_Main_Statusbar();
    Gui_Main_Time();
    Gui_Main_TimeBar();
    Gui_Main_Data();
    Gui_Main_Temp();
    Gui_Main_Hpa();
    main_timer = lv_timer_create(gui_main_timer, 100, NULL);
    lv_timer_pause(main_timer);
}

void Gui_Main_Show()
{
    Gui_Statu_Setparent(gui_Main);
    lv_group_focus_obj(gui_Main);
    lv_timer_resume(main_timer);
    lv_disp_load_scr(gui_Main);
}
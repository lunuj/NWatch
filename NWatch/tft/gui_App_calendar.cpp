/*
 * @Author: lunuj 68381451+lunuj@users.noreply.github.com
 * @Date: 2024-01-11 16:03:02
 * @LastEditors: lunuj 68381451+lunuj@users.noreply.github.com
 * @LastEditTime: 2024-03-31 15:12:36
 * @FilePath: /TFT/gui_App_calendar.cpp
 * @Description:
 *
 * Copyright (c) 2024 by ${lunuj}, All Rights Reserved.
 */
#include "gui_App_calendar.h"

lv_obj_t *calendar;

static void event_key_handler(lv_event_t *e)
{
    switch (e->code)
    {
    case LV_EVENT_KEY:
    {
        const uint32_t key = lv_indev_get_key(lv_indev_get_act());
        lv_obj_t *obj = lv_event_get_target(e);
        static time_t now;
        struct tm timeinfo;
        struct timeval tv_now;
        SoundRing();

        gettimeofday(&tv_now, NULL);
        if (key == LV_KEY_ENTER)
        {
            now = tv_now.tv_sec;
            localtime_r(&now, &timeinfo);
            lv_calendar_set_today_date(calendar, timeinfo.tm_year + 1900, timeinfo.tm_mon + 1, timeinfo.tm_mday);
        }
        else if (key == LV_KEY_BACKSPACE)
        {
            Gui_App_Show();
        }
        else if (key == LV_KEY_LEFT)
        {
            now -= 28 * 24 * 60 * 60;
        }
        else if (key == LV_KEY_RIGHT)
        {
            now += 28 * 24 * 60 * 60;
        }
        localtime_r(&now, &timeinfo);
        int year = timeinfo.tm_year + 1900;
        int mon = timeinfo.tm_mon + 1;
        int day = timeinfo.tm_mday;
        lv_calendar_set_showed_date(calendar, year, mon);
    }
    break;
    }
}

void Gui_App_Calendar_Init()
{
    gui_App_screen[CALENDAR] = lv_obj_create(NULL);
    lv_group_add_obj(group, gui_App_screen[CALENDAR]);
    lv_obj_add_event_cb(gui_App_screen[CALENDAR], event_key_handler, LV_EVENT_KEY, NULL);

    calendar = lv_calendar_create(gui_App_screen[CALENDAR]);
    lv_obj_set_size(calendar, 160, 128);

    timeval tv_now;
    time_t now;
    struct tm timeinfo;
    gettimeofday(&tv_now, NULL);
    now = tv_now.tv_sec;
    localtime_r(&now, &timeinfo);

    lv_calendar_set_today_date(calendar, timeinfo.tm_year + 1900, timeinfo.tm_mon + 1, timeinfo.tm_mday);
    lv_calendar_set_showed_date(calendar, timeinfo.tm_year + 1900, timeinfo.tm_mon + 1);
}

void Gui_App_Calender_Update(){
    now = tv_now.tv_sec;
    localtime_r(&now, &timeinfo);
    lv_calendar_set_today_date(calendar, timeinfo.tm_year + 1900, timeinfo.tm_mon + 1, timeinfo.tm_mday);
}
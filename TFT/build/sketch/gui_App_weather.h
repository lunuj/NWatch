#line 1 "/Users/lunuj/Documents/project/esp32/TFT/gui_App_weather.h"
/*
 * @Author: lunuj 68381451+lunuj@users.noreply.github.com
 * @Date: 2024-01-11 01:42:26
 * @LastEditors: lunuj 68381451+lunuj@users.noreply.github.com
 * @LastEditTime: 2024-03-02 15:53:12
 * @FilePath: /TFT/gui_App_weather.h
 * @Description: 
 * 
 * Copyright (c) 2024 by ${lunuj}, All Rights Reserved. 
 */
#ifndef GUI_APP_WEATHER_H
#define GUI_APP_WEATHER_H

#include <lvgl.h>
#include "gui_App.h"

extern lv_group_t *group;
extern lv_obj_t * gui_App_screen[6];

extern struct WeaInfo weainfo1;
extern struct WeaInfo weainfo2;
extern struct WeaInfo weainfo3;

void Gui_App_weather_GetTemp(char high[10], char low[10]);

void Gui_App_Weather_Init();

void Gui_App_Weather_Update();

time_t Gui_App_Weather_GetLastupdate();

void Gui_App_Weather_CleanUpdate();

bool Gui_App_Weather_GetUpdateStatus();

#endif // GUI_APP_WEATHER_H
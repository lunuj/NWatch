/*
 * @Author: lunuj 68381451+lunuj@users.noreply.github.com
 * @Date: 2024-03-03 19:22:49
 * @LastEditors: lunuj 68381451+lunuj@users.noreply.github.com
 * @LastEditTime: 2024-03-31 21:30:33
 * @FilePath: /TFT/gui_App_battery.h
 * @Description: 
 * 
 * Copyright (c) 2024 by ${lunuj}, All Rights Reserved. 
 */
#ifndef GUI_APP_BATTERY_H
#define GUI_APP_BATTERY_H

#include <lvgl.h>
#include "gui_App.h"

extern lv_group_t *group;
extern lv_obj_t * gui_App_screen[6];

void Gui_App_Battery_Init();

void Gui_App_Battery_Begin();

int Gui_App_Battery_Get();

#endif // GUI_APP_BATTERY_H


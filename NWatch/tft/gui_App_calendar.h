/*
 * @Author: lunuj 68381451+lunuj@users.noreply.github.com
 * @Date: 2024-01-11 16:02:48
 * @LastEditors: lunuj 68381451+lunuj@users.noreply.github.com
 * @LastEditTime: 2024-03-31 15:12:39
 * @FilePath: /TFT/gui_App_calendar.h
 * @Description: 
 * 
 * Copyright (c) 2024 by ${lunuj}, All Rights Reserved. 
 */

#ifndef GUI_APP_CALENDAR_H
#define GUI_APP_CALENDAR_H

#include <lvgl.h>
#include "gui_App.h"

extern lv_group_t *group;
extern lv_obj_t * gui_App_screen[6];
void Gui_App_Calendar_Init();

void Gui_App_Calender_Update();

#endif // GUI_APP_CALENDAR_H


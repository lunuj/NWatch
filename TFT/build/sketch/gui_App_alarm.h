#line 1 "/Users/lunuj/Documents/project/esp32/TFT/gui_App_alarm.h"
/*
 * @Author: lunuj 68381451+lunuj@users.noreply.github.com
 * @Date: 2024-01-17 23:23:11
 * @LastEditors: lunuj 68381451+lunuj@users.noreply.github.com
 * @LastEditTime: 2024-03-29 22:08:35
 * @FilePath: /TFT/gui_App_alarm.h
 * @Description: 
 * 
 * Copyright (c) 2024 by ${lunuj}, All Rights Reserved. 
 */
#ifndef GUI_APP_ALARM_H
#define GUI_APP_ALARM_H

#include <lvgl.h>
#include "gui_App.h"

extern lv_group_t *group;
extern lv_obj_t * gui_App_screen[6];

void Gui_App_Alarm_Init();

bool Gui_App_Alarm_isClock();

#endif // GUI_APP_ALARM_H


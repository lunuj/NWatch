/*
 * @Author: lunuj 68381451+lunuj@users.noreply.github.com
 * @Date: 2024-01-11 17:10:59
 * @LastEditors: lunuj 68381451+lunuj@users.noreply.github.com
 * @LastEditTime: 2024-03-03 13:44:47
 * @FilePath: /TFT/gui_App_setting.h
 * @Description: 
 * 
 * Copyright (c) 2024 by ${lunuj}, All Rights Reserved. 
 */
#ifndef GUI_APP_SETTING_H
#define GUI_APP_SETTING_H

#include <lvgl.h>
#include "gui_App.h"

extern lv_group_t *group;
extern lv_obj_t * gui_App_screen[6];

extern time_t now;
extern struct tm timeinfo;
extern struct timeval tv_now;

void Gui_App_Setting_Init();

#endif // GUI_APP_SETTING_H


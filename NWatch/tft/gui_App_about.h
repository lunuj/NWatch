/*
 * @Author: lunuj 68381451+lunuj@users.noreply.github.com
 * @Date: 2024-01-10 23:34:47
 * @LastEditors: lunuj 68381451+lunuj@users.noreply.github.com
 * @LastEditTime: 2024-01-13 00:18:15
 * @FilePath: /TFT/gui_App_about.h
 * @Description: 
 * 
 * Copyright (c) 2024 by ${lunuj}, All Rights Reserved. 
 */
#ifndef GUI_APP_ABOUT_H
#define GUI_APP_ABOUT_H

#include <lvgl.h>
#include "gui_App.h"

extern lv_group_t *group;
extern lv_obj_t * gui_App_screen[6];

void Gui_App_About_Init();

#endif // GUI_APP_ABOUT_H

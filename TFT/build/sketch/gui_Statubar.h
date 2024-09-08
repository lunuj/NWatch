#line 1 "/Users/lunuj/Documents/project/esp32/TFT/gui_Statubar.h"
/*
 * @Author: lunuj 68381451+lunuj@users.noreply.github.com
 * @Date: 2024-03-30 17:15:51
 * @LastEditors: lunuj 68381451+lunuj@users.noreply.github.com
 * @LastEditTime: 2024-03-30 17:43:54
 * @FilePath: /TFT/gui_Statubar.h
 * @Description: 
 * 
 * Copyright (c) 2024 by ${lunuj}, All Rights Reserved. 
 */
#ifndef GUI_STATUBAR_H
#define GUI_STATUBAR_H

#include "gui.h"
#include "gui_Main.h"

void Gui_Statubar_Init();

void Gui_StatusBar_Set(bool isAPP, uint16_t hour, uint16_t min, uint16_t bat_value, bool alarm, int sond_value);

void Gui_Statu_Setparent(lv_obj_t *parent);

#endif // GUI_STATUBAR_H


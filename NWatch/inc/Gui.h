/*
 * @Author: lunuj 68381451+lunuj@users.noreply.github.com
 * @Date: 2023-12-18 16:27:09
 * @LastEditors: lunuj 68381451+lunuj@users.noreply.github.com
 * @LastEditTime: 2023-12-27 16:05:33
 * @FilePath: /NWatch/inc/Gui.h
 * @Description: 
 * 
 * Copyright (c) 2023 by ${lunuj}, All Rights Reserved. 
 */
#ifndef __GUI_H__
#define __GUI_H__

#include "stm32f10x.h"
#include "OLED.h"
#include "Icon.h"
#include "Gui_Main.h"
#include "Timer.h"

extern int fps;
extern int check;

extern u8 Grame[8][128];
extern u8 Grames[64][128];
void Gui_Init();

void Gui_DrawGrame();

void Gui_DrawXBM(int x, int y,const uint8_t* pic);
void Gui_DrawXBM_num(int x,int y,const uint8_t* pic);

void BMP_Swarp(u8 *thumb);

void Gui_Clean();

void Gui_Mov_ATB(int ax, int ay, int bx, int by, int distance_x, int distance_y, int IsCycle);

void Gui_Transform8T64();

void Gui_Transform64T8();

void Gui_ShowFps();

#endif // __GUI_H__

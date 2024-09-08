/*
 * @Author: lunuj 68381451+lunuj@users.noreply.github.com
 * @Date: 2023-12-18 16:27:09
 * @LastEditors: lunuj 68381451+lunuj@users.noreply.github.com
 * @LastEditTime: 2023-12-22 15:33:37
 * @FilePath: /NWatch/inc/Gui_Main.h
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#ifndef __GUI_MAIN_H__
#define __GUI_MAIN_H__

#include "stm32f10x.h"
#include "MyRTC.h"
#include "Icon.h"
#include "Gui.h"

typedef struct
    XBM_NUM_TYPE {
    int width;
    int height;
    const uint8_t (*pic)[72];
} XBM_Num_Type;

extern XBM_Num_Type XBM_Num[4];

void Gui_Main_Draw_Clock();

void Gui_Main_Num_Change(int num, int x, int y, XBM_Num_Type num_type, int speed);


// void Gui_Main_Num_Change(int num,int pos,int speed);

//void Gui_Main_Num_Change(int num, int x, int y, int width, int height, int speed);

void Gui_Main_Init();

void Gui_Main_Draw_num(int x, int y, int num, XBM_Num_Type num_type);

void Gui_Main_Draw_nums(int x, int y, int num, XBM_Num_Type num_type);

int Get_Num_10_N(int num);

void Gui_Main_Draw_Char(int x, int y, char c);

void Gui_Main_Draw_Char_Spe(int x, int y, const u8 *pic, int width, int height);

void Gui_Main_Draw_String(int x, int y, char *c);

void Gui_Main_Draw_Data();

#endif // __GUI_MAIN_H__
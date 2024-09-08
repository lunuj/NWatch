/*
 * @Author: lunuj 68381451+lunuj@users.noreply.github.com
 * @Date: 2023-12-18 16:27:11
 * @LastEditors: lunuj 68381451+lunuj@users.noreply.github.com
 * @LastEditTime: 2023-12-27 16:04:08
 * @FilePath: /NWatch/src/Gui.c
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "Gui.h"


u8 Grame[8][128] = {0};
u8 Grames[64][128] = {0};


void Gui_Init(){
    OLED_Init();
    OLED_Clear();
    Gui_Main_Init();
    Timer_Init();

}

void Gui_DrawGrame()
{
    for (int i = 0; i < 8; i++) {
        OLED_SetCursor(i, 0);
           OLED_WriteGrame(Grame[i]);
    }
}

void BMP_Swarp(u8 *thumb)
{
    u8 a   = *thumb;
    *thumb = 0x00;
    for (int i = 0; i < 8; i++)
    {
        *thumb += (a/(0x80>>i))<<i;
        a=a&(0x7f>>i);
    }
}

void Gui_Clean()
{
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 32; j++) {
            Grame[i][j] = 0x00;
        }
    }
}

void Gui_Mov_ATB(int ax,int ay,int bx,int by,int distance_x,int distance_y,int IsCycle){
    Gui_Transform8T64();
    u8 thumb[64][128]={0};
    for (int i = ax; i < bx +1 ; i++)
    {
        for (int j = ay; j < by + 1; j++)
        {
            thumb[j][i] = Grames[j][i];
            Grames[j][i] = 0;
        }
    }
    for (int i = ax; i < bx +1 ; i++)
    {
        for (int j = ay; j < by + 1; j++)
        {
            Grames[j+distance_y][i+distance_x] = thumb[j][i];
        }
    }
    Gui_Transform64T8();

}


void Gui_Transform8T64(){
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 128; j++)
        {
            u8 a = Grame[i][j];
            for (int k = 0; k < 8; k++)
            {
                Grames[k+i*8][j] = ((a<<(7-k))%0x0100) / 0x80;
            }
        }
    }
}

void Gui_Transform64T8(){
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 128; j++)
        {
            u8 a = 0;
            for (int k = 0; k < 8; k++)
            {
               a += Grames[i*8+k][j] << k;
            }
            Grame[i][j] = a;
        }
    }
}

void Gui_ShowFps(){
    TIM_Cmd(TIM2, ENABLE);

    fps++;
    if (check == 1)
    {
        OLED_ShowNum(4,1,fps,3);
        check = 0;
        fps = 0;
    }
}
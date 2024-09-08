#line 1 "/Users/lunuj/Documents/project/esp32/TFT/gui.h"
/*
 * @Author: lunuj 68381451+lunuj@users.noreply.github.com
 * @Date: 2024-01-04 02:04:25
 * @LastEditors: lunuj 68381451+lunuj@users.noreply.github.com
 * @LastEditTime: 2024-03-31 14:54:36
 * @FilePath: /TFT/gui.h
 * @Description: 
 * 
 * Copyright (c) 2024 by ${lunuj}, All Rights Reserved. 
 */
#ifndef GUI_H
#define GUI_H

#include <lvgl.h>
#include <TFT_eSPI.h>
#include <lv_port_disp.h>
#include <lv_port_indev.h>
#include <wifi_config.h>
#include "gui_Main.h"
#include "gui_App.h"
#include "gui_Statubar.h"

#define GUI_MAIN_PAGE 0
#define GUI_APP_PAGE 1
/*
#define TFT_OLED_GND
#define TFT_OLED_VCC
#define TFT_OLED_SCL    D18
#define TFT_OLED_SDA    D23
#define TFT_OLED_RST    D4
#define TFT_OLED_DC     D2
#define TFT_OLED_CS     D15
#define TFT_OLED_BLK    D22
#define TFT_OLED_K4     D17
#define TFT_OLED_K3     D5
#define TFT_OLED_K2     D19
#define TFT_OLED_K1     D21
*/

extern lv_timer_t *main_timer;
extern lv_timer_t *app_timer;
extern time_t now;
extern struct tm timeinfo;
extern struct timeval tv_now;
extern u8_t soundval;
void Gui_Init();

void Gui_Draw();

unsigned long Gui_Last_Sleep_Get();

void Gui_Last_Sleep_Set(unsigned long a);

void Gui_Sleeptime_Set(int a);

unsigned long Gui_Sleeptime_Get();

void Gui_Oled_Off();

void Gui_Oled_On();

void Gui_Oled_light(int light);

bool Gui_Get_Oledstaue();

void LightSleep();

void TurnToLight();

void ObjectLight();

void AutoLight();

void SetLightTF(int a, bool b);

void SoundRing();

void SoundValSet(int volume);

void Mute(bool a);

bool GetMute();

#endif // GUI_H


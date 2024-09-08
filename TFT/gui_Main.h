/*
 * @Author: lunuj 68381451+lunuj@users.noreply.github.com
 * @Date: 2024-01-04 17:11:06
 * @LastEditors: lunuj 68381451+lunuj@users.noreply.github.com
 * @LastEditTime: 2024-03-31 23:46:16
 * @FilePath: /TFT/gui_Main.h
 * @Description: 
 * 
 * Copyright (c) 2024 by ${lunuj}, All Rights Reserved. 
 */
#ifndef GUI_MAIN_H
#define GUI_MAIN_H

#include "gui.h"
#include <wifi_config.h>

#define TIME_STRING "0\n1\n2\n3\n4\n5\n6\n7\n8\n9"
#define WIFI_TIME_UPDATE 15*60*60*1000
enum ALARM_State { ALARM_ON, ALARM_OFF };
enum Sond_value{ Sond_Mute, Sound_Mid, Sound_Max };
enum WEEK{Mon,Tue,Wed,Thu,Fir,Sat,Sun};
extern lv_group_t *group;

extern time_t now;
extern struct tm timeinfo;
extern struct timeval tv_now;

void Gui_Main_Init();

void Gui_Main_Show();

void Gui_Main_SetTime(int hour, int min, int sec);

void Gui_Main_SetTimeBar(uint16_t sec);

void Gui_Main_SetData(uint16_t year, uint16_t mon, uint16_t day, WEEK week);

void Gui_Main_SetTemp();

void Gui_Main_SetHpa(float Pa);

void Gui_Main_SetTimetoupdate(unsigned int time);

void Gui_Main_SetTimeCurrent(bool istime_current);

bool Gui_Main_GetTimeCurrent();

#endif // GUI_MAIN_H


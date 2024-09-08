/*
 * @Author: lunuj
 * @Date: 2023-09-19 21:20:05
 * @LastEditTime: 2023-12-26 23:41:30
 * @FilePath: /NWatch/inc/Timer.h
 * @Description: 
 * 
 * Copyright (c) 2023 by lunuj, All Rights Reserved. 
 */
#ifndef __TIMER_H
#define __TIMER_H

void Timer_Init(void);

void Timer_SetPeriod(uint16_t period);

void Timer_SetPrescale(uint16_t prescale);

extern int fps;
extern int check;

#endif
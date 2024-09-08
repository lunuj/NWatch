/*
 * @Author: lunuj 68381451+lunuj@users.noreply.github.com
 * @Date: 2023-12-29 16:17:00
 * @LastEditors: lunuj 68381451+lunuj@users.noreply.github.com
 * @LastEditTime: 2024-03-09 17:12:37
 * @FilePath: /NWatch/inc/Alarm.h
 * @Description: 
 * 
 * Copyright (c) 2023 by ${lunuj}, All Rights Reserved. 
 */
#ifndef ALARM_H
#define ALARM_H
#include "stm32f10x.h" // Device header
#include "Timer.h"
#include "PWM.h"

#define Alarm_GPIO_PORT		GPIOA
#define Alarm_GPIO_PIN		GPIO_Pin_6
#define Alarm_PORT		    RCC_APB2Periph_GPIOA

void Alarm_Init();

void Alarm_Ring(uint16_t picth, uint16_t ms);

#endif // ALARM_H


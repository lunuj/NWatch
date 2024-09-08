/*
 * @Author: lunuj 68381451+lunuj@users.noreply.github.com
 * @Date: 2023-12-30 19:49:38
 * @LastEditors: lunuj 68381451+lunuj@users.noreply.github.com
 * @LastEditTime: 2023-12-31 16:28:20
 * @FilePath: /NWatch/inc/Kalmen.h
 * @Description: 
 * 
 * Copyright (c) 2023 by ${lunuj}, All Rights Reserved. 
 */
#ifndef KALMEN_H
#define KALMEN_H

#include "stm32f10x.h"
#include "MPU6050.h"
#include <math.h>
#include "Serial.h"
extern float k_roll, k_pitch;

#endif // KALMEN_H

void Kalman_Init();

void show();

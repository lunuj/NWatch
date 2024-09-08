/*
 * @Author: lunuj 68381451+lunuj@users.noreply.github.com
 * @Date: 2023-12-29 14:59:52
 * @LastEditors: lunuj 68381451+lunuj@users.noreply.github.com
 * @LastEditTime: 2023-12-30 20:09:24
 * @FilePath: /NWatch/inc/MPU6050.h
 * @Description: 
 * 
 * Copyright (c) 2023 by ${lunuj}, All Rights Reserved. 
 */
#ifndef __MPU6050_H
#define __MPU6050_H

struct KalmanFilter{
    float NewP;
    float LastP;
    float Out;
    float Kg;
    float Q;
    float R;
};

void MPU6050_WriteReg(uint8_t RegAddress, uint8_t Data);
uint8_t MPU6050_ReadReg(uint8_t RegAddress);

void MPU6050_Init(void);
uint8_t MPU6050_GetID(void);
float MPU6050_GetTMP(void);
void MPU6050_GetData(float MpuData[6]);

#endif

/*
 * @Author: lunuj 68381451+lunuj@users.noreply.github.com
 * @Date: 2023-12-30 19:49:30
 * @LastEditors: lunuj 68381451+lunuj@users.noreply.github.com
 * @LastEditTime: 2024-04-04 23:02:00
 * @FilePath: /NWatch/src/Kalmen.c
 * @Description:
 *
 * Copyright (c) 2023 by ${lunuj}, All Rights Reserved.
 */
#include "Kalmen.h"
#define OFFSET_COUNT 500
#define RAD2DEG      57.29578

float ax_offset = 0, ay_offset = 0;
float gx_offset = 0, gy_offset = 0;
float pMpu[6];
float roll_v = 0, pitch_v = 0;

float dt = 0;

float gyro_roll = 0, gyro_pitch = 0;
float acc_roll = 0, acc_pitch = 0;
float k_roll = 0, k_pitch = 0;

float e_P[2][2] = {{1, 0}, {0, 1}};

float k_k[2][2] = {{0, 0}, {0, 0}};

float roll = 0, pitch = 0;
void Kalman_Init()
{
    for (int i = 0; i < OFFSET_COUNT; i++) {
        MPU6050_GetData(pMpu);
        ax_offset = ax_offset + pMpu[0];
        ay_offset = ay_offset + pMpu[1];
        gx_offset = gx_offset + pMpu[3];
        gy_offset = gy_offset + pMpu[4];
    }
    ax_offset = ax_offset / OFFSET_COUNT;
    ay_offset = ay_offset / OFFSET_COUNT;
    gx_offset = gx_offset / OFFSET_COUNT;
    gy_offset = gx_offset / OFFSET_COUNT;

    CoreDebug->DEMCR |= CoreDebug_DEMCR_TRCENA_Msk;
    DWT->CYCCNT = 0;
    DWT->CTRL |= DWT_CTRL_CYCCNTENA_Msk;
}

void Kalman_Fillter()
{
    roll  = atan(pMpu[1] / pMpu[2]) * RAD2DEG;
    pitch = atan(pMpu[0] / sqrt(pMpu[1] * pMpu[1] + pMpu[2] * pMpu[2])) * RAD2DEG;
    /*step1:计算先验估计*/
    roll_v     = (pMpu[3] + ((sin(k_pitch) * sin(k_roll)) / cos(k_pitch)) * pMpu[4] +  \
    ((sin(k_pitch) * cos(k_roll)) / cos(k_pitch)) * pMpu[5]);
    pitch_v    = cos(k_roll) * pMpu[4] - sin(k_roll) * pMpu[5];
    gyro_roll  = k_roll + dt * roll_v;
    gyro_pitch = k_pitch + dt * pitch_v;

    /*step2:计算先验误差协方差矩阵P*/
    e_P[0][0] = e_P[0][0] + 0.0025; // 这里的Q矩阵是一个对角阵且对角元均为0.0025
    e_P[0][1] = e_P[0][1] + 0;
    e_P[1][0] = e_P[1][0] + 0;
    e_P[1][1] = e_P[1][1] + 0.0025;

    /*step3:更新卡尔曼增益K*/
    k_k[0][0] = e_P[0][0] / (e_P[0][0] + 0.3);
    k_k[0][1] = 0;
    k_k[1][0] = 0;
    k_k[1][1] = e_P[1][1] / (e_P[1][1] + 0.3);

    /*step4:计算最优估计状态*/
    /*观测状态*/
    acc_roll  = atan(pMpu[1] / pMpu[2]) * RAD2DEG;
    acc_pitch = atan(pMpu[0] / sqrt(pMpu[1] * pMpu[1] + pMpu[2] * pMpu[2])) * RAD2DEG;
    /*最优估计状态*/
    k_roll  = gyro_roll + k_k[0][0] * (acc_roll - gyro_roll);
    k_pitch = gyro_pitch + k_k[1][1] * (acc_pitch - gyro_pitch);

    /*step5:更新协方差矩阵P*/
    e_P[0][0] = (1 - k_k[0][0]) * e_P[0][0];
    e_P[0][1] = 0;
    e_P[1][0] = 0;
    e_P[1][1] = (1 - k_k[1][1]) * e_P[1][1];
}

void show()
{
    dt          = (float)(DWT->CYCCNT) / 800 / 10000;
    DWT->CYCCNT = 0;
    /* do something */
    MPU6050_GetData(pMpu);
    pMpu[0] -= ax_offset;
    pMpu[1] -= ay_offset;
    pMpu[3] -= gx_offset;
    pMpu[4] -= gy_offset;
    Kalman_Fillter();
}
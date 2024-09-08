/*
 * @Author: lunuj 68381451+lunuj@users.noreply.github.com
 * @Date: 2023-12-18 16:27:05
 * @LastEditors: lunuj 68381451+lunuj@users.noreply.github.com
 * @LastEditTime: 2024-04-03 00:14:55
 * @FilePath: /NWatch/main.c
 * @Description:
 *
 * Copyright (c) 2023 by ${lunuj}, All Rights Reserved.
 */
#include "stm32f10x.h"
#include "Delay.h"
#include "Serial.h"
#include "MHSensor.h"
#include "Kalmen.h"

#include "AD.h"
#include "OLED.h"
#include "Alarm.h"
#include "DHT11.h"

#include <time.h>

void ReadESP32Procsess();
void loop();
int main(void)
{
    Serial_Init();
    Serial2_Init();

    Serial2_Printf("1");
    Serial_Printf("2");
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
    
    GPIO_InitTypeDef GPIO_InitStructure;

    GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_IN_FLOATING;
    GPIO_InitStructure.GPIO_Pin   = GPIO_Pin_2;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA, &GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_IN_FLOATING;
    GPIO_InitStructure.GPIO_Pin   = GPIO_Pin_3;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOA, &GPIO_InitStructure);
    
    OLED_Init();    // 带有自动亮度
    MPU6050_Init(); // 带有硬件I2C通信及MPU6050
    Kalman_Init();  // 带有卡尔曼滤波及姿态解算
    Alarm_Init();   // 带有定时器及蜂鸣器
    OLED_ShowString(1, 1, "Start");
    Serial_Printf("start");

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE); // 开启GPIOB的时钟
    // GPIO_InitTypeDef GPIO_InitStructure;
    GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_Out_OD;
    GPIO_InitStructure.GPIO_Pin   = GPIO_Pin_0;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOB, &GPIO_InitStructure);
    Serial_Printf("232");

    loop();
    
}

void loop(){
    while (1) {
        show();
        if (!(k_roll > 20 || k_roll < -20)) {
            GPIO_WriteBit(GPIOB, GPIO_Pin_0, Bit_SET);
            OLED_ShowChar(1,7, 'Y');
        } else {
            GPIO_WriteBit(GPIOB, GPIO_Pin_0, Bit_RESET);
            OLED_ShowChar(1,7, 'N');
        }
        OLED_ShowSignedNum(2,1,k_pitch,4);
        OLED_ShowSignedNum(3,1,k_roll,4);
        OLED_ShowSignedNum(4,1,GPIO_ReadOutputDataBit(GPIOB, GPIO_Pin_0),1);
        Serial_Printf("1224");

        OLED_ShowSignedNum(2,6,GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_2),2);
        OLED_ShowSignedNum(3,6,GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_3),2);
        if (GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_2) == 1)
        {
            Alarm_Ring(7, 1 * 100);
        }
        if (GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_3) == 1)
        {
            Alarm_Ring(3, 1 * 100);
        }
        // ReadESP32Procsess();
    }
    
}

void ReadESP32Procsess()
{
    if (Serial2_GetRxFlag() == 1) {
        u8 RxData = *(Serial2_GetRxCach());
        OLED_ShowHexNum(4, 1, RxData, 2);
        if (RxData >> 7) // 蜂鸣器
        {
            Alarm_Ring(((RxData >> 4) & 0x07), (RxData & 0x0F) * 100);
        }
    }
}
/*
 * @Author: lunuj 68381451+lunuj@users.noreply.github.com
 * @Date: 2023-12-29 16:16:53
 * @LastEditors: lunuj 68381451+lunuj@users.noreply.github.com
 * @LastEditTime: 2024-03-30 18:16:51
 * @FilePath: /NWatch/src/Alarm.c
 * @Description:
 *
 * Copyright (c) 2023 by ${lunuj}, All Rights Reserved.
 */
#include "Alarm.h"

void Alarm_Init()
{
    Timer_Init();
    PWM_Init();
}

void Alarm_Ring(uint16_t picth, uint16_t ms)
{
    if (picth == 0)
    {
        PWM_SetComparel(picth);
        TIM_Cmd(TIM2, DISABLE);
        TIM_Cmd(TIM3, DISABLE);
    }else{
        if (ms == 0)
        {
            PWM_SetComparel(picth);
            TIM_Cmd(TIM2, DISABLE);
            TIM_Cmd(TIM3, ENABLE);
        }else{
            TIM_SetCounter(TIM2, 0);
            Timer_SetPeriod(ms);
            PWM_SetComparel(picth);
            TIM_Cmd(TIM2, ENABLE);
            TIM_Cmd(TIM3, ENABLE);
        }
    }
}

void TIM2_IRQHandler(void){
    if (TIM_GetITStatus(TIM2, TIM_IT_Update)== SET)
    {
        TIM_ClearITPendingBit(TIM2, TIM_IT_Update);
        Alarm_Ring(0,0);
    }
}

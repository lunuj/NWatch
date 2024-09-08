/*
 * @Author: lunuj
 * @Date: 2023-09-19 21:19:58
 * @LastEditTime: 2024-03-27 15:47:43
 * @FilePath: /NWatch/src/Timer.c
 * @Description: 
 * 
 * Copyright (c) 2023 by lunuj, All Rights Reserved. 
 */
#include "stm32f10x.h"
#include "Timer.h"

void Timer_Init(void){
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
  
    TIM_InternalClockConfig(TIM2);
    // TIM_ETRClockMode2Config(TIM2, TIM_ExtTRGPSC_OFF, TIM_ExtTRGPolarity_NonInverted,0x00);
    TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;
    TIM_TimeBaseInitStructure.TIM_ClockDivision = TIM_CKD_DIV1;
    TIM_TimeBaseInitStructure.TIM_CounterMode = TIM_CounterMode_Up;
    TIM_TimeBaseInitStructure.TIM_Period = 1000 -1;
    TIM_TimeBaseInitStructure.TIM_Prescaler = 8000 - 1;
    TIM_TimeBaseInitStructure.TIM_RepetitionCounter = 0;
    TIM_TimeBaseInit(TIM2, &TIM_TimeBaseInitStructure);

    TIM_ClearFlag(TIM2, TIM_IT_Update);
    TIM_ITConfig(TIM2, TIM_IT_Update, ENABLE);
    
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);				//配置NVIC为分组2

    NVIC_InitTypeDef NVIC_InitSttructue;
    NVIC_InitSttructue.NVIC_IRQChannel = TIM2_IRQn;
    NVIC_InitSttructue.NVIC_IRQChannelCmd = ENABLE;
    NVIC_InitSttructue.NVIC_IRQChannelPreemptionPriority = 1;
    NVIC_InitSttructue.NVIC_IRQChannelSubPriority = 1;
    NVIC_Init(&NVIC_InitSttructue);

}

void Timer_SetPeriod(uint16_t period){
    TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;
    TIM_TimeBaseInitStructure.TIM_ClockDivision = TIM_CKD_DIV1;
    TIM_TimeBaseInitStructure.TIM_CounterMode = TIM_CounterMode_Up;
    TIM_TimeBaseInitStructure.TIM_Period = period -1;
    TIM_TimeBaseInitStructure.TIM_Prescaler = 8000 - 1;
    TIM_TimeBaseInitStructure.TIM_RepetitionCounter = 0;
    TIM_TimeBaseInit(TIM2, &TIM_TimeBaseInitStructure);
}

void Timer_SetPrescale(uint16_t prescale){
    TIM_PrescalerConfig(TIM2, prescale, TIM_PSCReloadMode_Immediate);
}


/*
 * @Author: lunuj
 * @Date: 2023-09-19 23:33:16
 * @LastEditTime: 2024-03-27 16:38:45
 * @FilePath: /NWatch/src/PWM.c
 * @Description: 
 * 
 * Copyright (c) 2023 by lunuj, All Rights Reserved. 
 */
#include "stm32f10x.h"
#include "PWM.h"
int dup = 0;
int dup_count = 0;

void PWM_Init(void){
    RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);

    TIM_InternalClockConfig(TIM3);
    // TIM_ETRClockMode2Config(TIM3, TIM_ExtTRGPSC_OFF, TIM_ExtTRGPolarity_NonInverted,0x00);
    TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;
    TIM_TimeBaseInitStructure.TIM_ClockDivision = TIM_CKD_DIV1;
    TIM_TimeBaseInitStructure.TIM_CounterMode = TIM_CounterMode_Up;
    TIM_TimeBaseInitStructure.TIM_Period = 10 -1;
    TIM_TimeBaseInitStructure.TIM_Prescaler = 8 - 1;
    TIM_TimeBaseInitStructure.TIM_RepetitionCounter = 0;
    TIM_TimeBaseInit(TIM3, &TIM_TimeBaseInitStructure);

    TIM_ClearFlag(TIM3, TIM_IT_Update);
    TIM_ITConfig(TIM3, TIM_IT_Update, ENABLE);
    
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);				//配置NVIC为分组2

    NVIC_InitTypeDef NVIC_InitSttructue;
    NVIC_InitSttructue.NVIC_IRQChannel = TIM3_IRQn;
    NVIC_InitSttructue.NVIC_IRQChannelCmd = ENABLE;
    NVIC_InitSttructue.NVIC_IRQChannelPreemptionPriority = 1;
    NVIC_InitSttructue.NVIC_IRQChannelSubPriority = 1;
    NVIC_Init(&NVIC_InitSttructue);

    // TIM_Cmd(TIM3, ENABLE);
}

void PWM_SetComparel(u16 Compare){
    dup = (3*Compare)%22;
}

void TIM3_IRQHandler(void){
    if (TIM_GetITStatus(TIM3, TIM_IT_Update)== SET)
    {
        TIM_ClearITPendingBit(TIM3, TIM_IT_Update);
        dup_count = dup_count%21 + 1;
        if (dup_count <= dup)
        {
            GPIO_WriteBit(GPIOA, GPIO_Pin_5, Bit_SET);
        }else{
            GPIO_WriteBit(GPIOA, GPIO_Pin_5, Bit_RESET);
        }
        dup_count++;
    }
}

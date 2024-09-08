#include "MHSensor.h"

void MHSensor_Init(){
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);

    GPIO_EXTILineConfig(GPIO_PortSourceGPIOA, GPIO_PinSource3);

    EXTI_InitTypeDef EXTI_InitSturcture;
    EXTI_InitSturcture.EXTI_Line = EXTI_Line3;
    EXTI_InitSturcture.EXTI_LineCmd = ENABLE;
    EXTI_InitSturcture.EXTI_Mode = EXTI_Mode_Interrupt;
    EXTI_InitSturcture.EXTI_Trigger = EXTI_Trigger_Falling;
    EXTI_Init(&EXTI_InitSturcture);

    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);

    NVIC_InitTypeDef NVIC_InitSttructue;
    NVIC_InitSttructue.NVIC_IRQChannel = EXTI3_IRQn;
    NVIC_InitSttructue.NVIC_IRQChannelCmd = ENABLE;
    NVIC_InitSttructue.NVIC_IRQChannelPreemptionPriority = 1;
    NVIC_InitSttructue.NVIC_IRQChannelSubPriority = 1;
    NVIC_Init(&NVIC_InitSttructue);

}

void EXTI3_IRQHandler(void){
    OLED_WriteCommand(0xAF);
    EXTI_ClearITPendingBit(EXTI_Line3);
}
/*
 * @Author: lunuj
 * @Date: 2023-09-19 23:33:10
 * @LastEditTime: 2023-09-20 00:08:45
 * @FilePath: \test\Hardware\PWM.h
 * @Description: 
 * 
 * Copyright (c) 2023 by lunuj, All Rights Reserved. 
 */
#ifndef __PWM_H
#define __PWM_H

void PWM_Init(void);
void PWM_SetComparel(u16 Compare);
void PWM_SetPrescaler(u16 Prescaler);
#endif
/*
 * @Author: lunuj 68381451+lunuj@users.noreply.github.com
 * @Date: 2023-12-18 16:27:09
 * @LastEditors: lunuj 68381451+lunuj@users.noreply.github.com
 * @LastEditTime: 2024-03-13 16:58:12
 * @FilePath: /NWatch/inc/Serial.h
 * @Description: 
 * 
 * Copyright (c) 2024 by ${lunuj}, All Rights Reserved. 
 */
//
// Created by lunuj on 2023/11/17.
//

#ifndef __SERIAL_H
#define __SERIAL_H
// RX Pin10
// TX Pin9

#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include <stdio.h>
#include <stdarg.h>

void Serial_Init(void);
void Serial_SendByte(u8 Byte);
void Serial_SendArrary(u8 *Arrary, u16 Length);
void Serial_SendString(char *String);
void Serial_SendNum(int Num);
void Serial_Printf(char *format, ...);
void Serial_SendPack(void);
void Serial_SetPack(u8 tx[4]);
u8 Serial_GetRxFlag(void);
u8* Serial_GetRxCach(void);



void Serial2_Init(void);
void Serial2_SendByte(u8 Byte);
void Serial2_SendArrary(u8 *Arrary, u16 Length);
void Serial2_SendString(char *String);
void Serial2_SendNum(int Num);
void Serial2_Printf(char *format, ...);
void Serial2_SendPack(void);
void Serial2_SetPack(u8 tx[4]);
u8 Serial2_GetRxFlag(void);
u8* Serial2_GetRxCach(void);

#endif

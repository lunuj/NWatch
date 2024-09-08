/*
 * @Author: lunuj
 * @Date: 2023-09-18 22:22:06
 * @LastEditTime: 2024-02-17 16:06:48
 * @FilePath: /NWatch/inc/OLED.h
 * @Description: 
 * 
 * Copyright (c) 2023 by lunuj, All Rights Reserved. 
 */
#ifndef __OLED_H
#define __OLED_H

#define OLED_W_SCL(x)		GPIO_WriteBit(GPIOB, GPIO_Pin_12, (BitAction)(x))
#define OLED_W_SDA(x)		GPIO_WriteBit(GPIOB, GPIO_Pin_13, (BitAction)(x))

void OLED_Init(void);
void OLED_Clear(void);
void OLED_I2C_Start(void);
void OLED_I2C_Stop(void);
void OLED_I2C_SendByte(uint8_t Byte);
void OLED_WriteCommand(uint8_t Command);
void OLED_WriteData(uint8_t Data);
void OLED_SetCursor(uint8_t Y, uint8_t X);
void OLED_WriteGrame(uint8_t *Data);
void OLED_ShowChar(uint8_t Line, uint8_t Column, char Char);
void OLED_ShowString(uint8_t Line, uint8_t Column, char *String);
void OLED_ShowNum(uint8_t Line, uint8_t Column, uint32_t Number, uint8_t Length);
void OLED_ShowSignedNum(uint8_t Line, uint8_t Column, int32_t Number, uint8_t Length);
void OLED_ShowHexNum(uint8_t Line, uint8_t Column, uint32_t Number, uint8_t Length);
void OLED_ShowBinNum(uint8_t Line, uint8_t Column, uint32_t Number, uint8_t Length);

void OLED_SetLight(u8 light);

void OLED_AutoLight(FunctionalState NewState);

#endif
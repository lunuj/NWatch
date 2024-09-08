/*
 * @Author: lunuj 68381451+lunuj@users.noreply.github.com
 * @Date: 2023-12-18 16:27:09
 * @LastEditors: lunuj 68381451+lunuj@users.noreply.github.com
 * @LastEditTime: 2024-03-09 15:33:32
 * @FilePath: /NWatch/inc/MyI2C.h
 * @Description: 
 * 
 * Copyright (c) 2023 by ${lunuj}, All Rights Reserved. 
 */
#ifndef __MYI2C_H
#define __MYI2C_H

#define I2C_PORT GPIOB
#define I2C_SCL GPIO_Pin_3 //定义I2C协议scl
#define I2C_SDA GPIO_Pin_4

void MyI2C_Init(void);
void MyI2C_W_SCL(u8 BitValue);
void MyI2C_W_SDA(u8 BitValue);
void MyI2C_Start(void);
void MyI2C_End(void);
void MyI2C_SendByte(u8 Byte);
u8 MyI2C_ReceiveByte(void);
void MyI2C_SendAck(u8 AckBit);
u8 MyI2C_ReceivAck(void);
#endif



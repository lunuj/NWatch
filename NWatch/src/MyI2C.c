/*
 * @Author: lunuj
 * @Date: 2023-10-05 16:19:50
 * @LastEditTime: 2024-03-09 15:30:06
 * @FilePath: /NWatch/src/MyI2C.c
 * @Description: i2c协议
 * 
 * Copyright (c) 2023 by lunuj, All Rights Reserved. 
 */
#include "stm32f10x.h"
#include "MyI2C.h"
#include "Delay.h"

/**
 * @brief I2C协议初始化
 * @retval 无
 */
void MyI2C_Init(void){
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);

	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_OD;
	GPIO_InitStructure.GPIO_Pin = I2C_SCL | I2C_SDA;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;

	GPIO_Init(GPIOB, &GPIO_InitStructure);
    GPIO_SetBits(GPIOB, I2C_SCL | I2C_SDA);
}
/**
 * @brief 修改I2C协议钟SCL处电平
 * @param {u8} BitValue: 传入0则置为低电平,其他则置为高电平
 * @retval 无
 */
void MyI2C_W_SCL(u8 BitValue){
    if (BitValue == 0)
    {
        GPIO_ResetBits(I2C_PORT, I2C_SCL);  
    } else {
        GPIO_SetBits(I2C_PORT, I2C_SCL);
    }
    Delay_us(10);
}

/**
 * @brief 修改I2C协议钟SDA处电平
 * @param {u8} BitValue: 传入0则置为低电平,其他则置为高电平
 * @retval 无
 */
void MyI2C_W_SDA(u8 BitValue){
    if (BitValue == 0)
    {
        GPIO_ResetBits(I2C_PORT, I2C_SDA);  
    } else {
        GPIO_SetBits(I2C_PORT, I2C_SDA);
    }
    Delay_us(10);
}

/**
 * @brief 读取I2C协议SDA处电平
 * @retval {u8} 读取的电平数值
 */
u8 MyI2C_R_SDA(void){
    return GPIO_ReadInputDataBit(I2C_PORT, I2C_SDA);
}

/**
 * @brief I2C协议开始时序
 * @retval 无
 */
void MyI2C_Start(void){
    MyI2C_W_SDA(1);
    MyI2C_W_SCL(1);
    MyI2C_W_SDA(0);
    MyI2C_W_SCL(0);
}

/**
 * @brief I2C协议结束时序
 * @retval 无
 */
void MyI2C_End(void){
    MyI2C_W_SDA(0);
    MyI2C_W_SCL(1);
    MyI2C_W_SDA(1);
}

/**
 * @brief I2C协议发送一字节数据
 * @param {u8} Byte: 要发送的字节数据
 * @retval 无
 */
void MyI2C_SendByte(u8 Byte){
    for (int i = 0; i < 8; i++)
    {
        MyI2C_W_SDA(Byte & (0x80 >> i));
        MyI2C_W_SCL(1);
        MyI2C_W_SCL(0);
    }
}

/**
 * @brief I2C协议接收一个字节数据
 * @retval {u8} 接收到的数据
 */
u8 MyI2C_ReceiveByte(void){
    u8 Byte = 0;
    MyI2C_W_SDA(1);
    for (int i = 0; i < 8; i++)
    {
        MyI2C_W_SCL(1);
        Byte |= (MyI2C_R_SDA() << (7 - i));
        MyI2C_W_SCL(0);
    }
    return Byte;
}

/**
 * @brief I2C协议发送应答
 * @param {u8} AckBit: 要发送的应答数据
 * @retval 无
 */
void MyI2C_SendAck(u8 AckBit){
    MyI2C_W_SDA(AckBit);
    MyI2C_W_SCL(1);
    MyI2C_W_SCL(0);
}

/**
 * @brief I2C协议接收应答
 * @retval {u8} 接收的应答数据
 */
u8 MyI2C_ReceivAck(void){
    u8 AckBit;
    MyI2C_W_SDA(1);
    MyI2C_W_SCL(1);
    AckBit = MyI2C_R_SDA();
    MyI2C_W_SCL(0);
    return AckBit;
}
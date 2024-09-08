/*
 * @Author: lunuj
 * @Date: 2023-09-18 22:00:16
 * @LastEditTime: 2023-09-18 22:08:26
 * @FilePath: \test\Hardware\LightSensor.h
 * @Description: 
 * 
 * Copyright (c) 2023 by lunuj, All Rights Reserved. 
 */
#ifndef __LIGHT_SENSOR_G
#define __LIGHT_SENSOR_G

#define LIGHTSENSOR_PORT GPIO_Pin_2

void LightSensor_Init(void);
u8 LightSensor_Get(void);

void LightSensor_Test();

#endif
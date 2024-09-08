#ifndef MHSENSOR_H
#define MHSENSOR_H

#include "stm32f10x.h"
#include "OLED.h"
#define MHSensor_GPIO_PORT		GPIOA
#define MHSensor_GPIO_PIN		GPIO_Pin_3
#define MHSensor_PORT		    RCC_APB2Periph_GPIOA

void MHSensor_Init();


#endif // MHSENSOR_H


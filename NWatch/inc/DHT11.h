#ifndef __DHT11_H
#define __DHT11_H

#define DHT_GPIO_PORT		GPIOB
#define DHT_GPIO_PIN		GPIO_Pin_1
#define DHT_RCC_PORT		RCC_APB2Periph_GPIOB

uint8_t DHT_Get_Temp_Humi_Data(uint8_t buffer[]);

#endif
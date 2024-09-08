
/*
 * @Author: lunuj 68381451+lunuj@users.noreply.github.com
 * @Date: 2024-01-01 20:15:12
 * @LastEditors: lunuj 68381451+lunuj@users.noreply.github.com
 * @LastEditTime: 2024-04-04 11:43:34
 * @FilePath: /TFT/TFT.ino
 * @Description:
 *
 * Copyright (c) 2024 by ${lunuj}, All Rights Reserved.
 */

#include "gui.h"

/*
增加GPIO口  pin34 作为开关睡眠唤醒
           pin25 六轴唤醒
           pin12 pwen
           pin14  
*/


void setup()
{
    Serial.begin(115200);
    pinMode(26, OUTPUT);            //外设使能   高电平关闭外设   
    pinMode(27, OUTPUT);            //外设使能   高电平关闭外设   
    digitalWrite(26, LOW);
    digitalWrite(27, LOW);

    pinMode(12, OUTPUT);            //外设使能   高电平关闭外设   
    digitalWrite(12, LOW);
    pinMode(14, INPUT);             //充电检测
    pinMode(16, OUTPUT);            //翻转唤醒
    pinMode(22, OUTPUT);            //亮度控制
    //pin25 mpu唤醒
    //pin32 亮度检测
    pinMode(33, INPUT_PULLUP);      //物体唤醒
    pinMode(34, INPUT_PULLUP);      //按键唤醒
    pinMode(35, INPUT_PULLDOWN);    //电量检测

    digitalWrite(22, HIGH);
    digitalWrite(16, HIGH);
    ledcAttachPin(22, 0);
    ledcSetup(0, 10000, 1000);
    analogReadResolution(16);

    gpio_wakeup_enable(GPIO_NUM_34, GPIO_INTR_LOW_LEVEL);
    esp_sleep_enable_gpio_wakeup();
    Gui_Init();
    AutoLight();
    Gui_Draw();
    WiFi_program();
    LightSleep();
    
    Gui_Oled_On();
}


void loop()
{
    if (Gui_Get_Oledstaue())
    {
        AutoLight();
        Gui_Draw();
        WiFi_program();
        LightSleep();
    }
    else
    {
        if (key_read() == 3 || esp_sleep_get_wakeup_cause() == ESP_SLEEP_WAKEUP_GPIO)
        {
            Gui_Draw();
            Gui_Oled_On();
            Gui_Last_Sleep_Set(millis());
            delay(300);
        }
    }
}


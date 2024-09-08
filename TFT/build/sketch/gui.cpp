#line 1 "/Users/lunuj/Documents/project/esp32/TFT/gui.cpp"
/*
 * @Author: lunuj 68381451+lunuj@users.noreply.github.com
 * @Date: 2024-01-04 02:04:20
 * @LastEditors: lunuj 68381451+lunuj@users.noreply.github.com
 * @LastEditTime: 2024-03-31 22:42:48
 * @FilePath: /TFT/gui.cpp
 * @Description:
 *
 * Copyright (c) 2024 by ${lunuj}, All Rights Reserved.
 */

#include "gui.h"

lv_timer_t *main_timer;
lv_timer_t *app_timer;

time_t now;
struct tm timeinfo;
struct timeval tv_now;
u8_t soundval = 0;

static bool oled_power = true;
static bool turnlight = false;
static bool objectlight = false;
static bool autolight = false;
static bool mute = false;

static int lightval = 10;
static unsigned long last_sleep = 0;
static unsigned long sleep_time = 0;

void Gui_Init()
{
    lv_init();
    lv_port_disp_init();
    lv_port_indev_init();
    
    ledcWrite(0, 0);
    TFT_eSPI_Write_Command(0x28);
    
    Gui_Statubar_Init();
    Gui_Main_Init();
    Gui_App_Init();
    Gui_Main_Show();
    // Gui_App_Show();
}

void Gui_Draw()
{
    lv_timer_handler(); /* let the GUI do its work */
}

unsigned long Gui_Last_Sleep_Get()
{
    return last_sleep;
}

void Gui_Last_Sleep_Set(unsigned long a)
{
    last_sleep = a;
}

void Gui_Sleeptime_Set(int a)
{
    switch (a % 8)
    {
    case 0:
        sleep_time = 0;
        break;
    case 1:
        sleep_time = 15000;
        break;
    case 2:
        sleep_time = 30000;
        break;
    case 4:
        sleep_time = 60000;
        break;
    case 5:
        sleep_time = 300000;
        break;
    case 6:
        sleep_time = 600000;
        break;
    case 7:
        sleep_time = 900000;
        break;
    default:
        break;
    }
}

unsigned long Gui_Sleeptime_Get()
{
    return sleep_time;
}

void Gui_Oled_Off()
{
    TurnToLight();
    ObjectLight();
    ledcWrite(0, 0);
    TFT_eSPI_Write_Command(0x28);
    oled_power = false;
    esp_light_sleep_start();
}

void Gui_Oled_On()
{
    TFT_eSPI_Write_Command(0x29);
    ledcWrite(0, lightval*10);
    oled_power = true;
}

void Gui_Oled_light(int light)
{
    if (!autolight)
    {
        if (light > 0)
        {
            lightval = light;
        }
        ledcWrite(0, light*10);
    }
}

bool Gui_Get_Oledstaue()
{
    return oled_power;
}

void LightSleep()
{
    if (Gui_Sleeptime_Get() != 0)
    {
        if (key_read() != 0)
        {
            Gui_Last_Sleep_Set(millis());
        }
        if ((millis() - Gui_Last_Sleep_Get() > Gui_Sleeptime_Get()))
        {
            Gui_Oled_Off();
        }
    }
}

void TurnToLight()
{
    if (turnlight)
    {
        gpio_wakeup_enable(GPIO_NUM_16, GPIO_INTR_LOW_LEVEL);
        esp_sleep_enable_gpio_wakeup();
    }else{
        gpio_wakeup_disable(GPIO_NUM_16);
        esp_sleep_enable_gpio_wakeup();
    }
}

void ObjectLight()
{
    if (objectlight)
    {
        pinMode(33, INPUT_PULLUP);      //物体唤醒
        gpio_wakeup_enable(GPIO_NUM_33, GPIO_INTR_LOW_LEVEL);
        esp_sleep_enable_gpio_wakeup();
    }else{
        gpio_wakeup_disable(GPIO_NUM_33);
        esp_sleep_enable_gpio_wakeup();
        pinMode(33, OUTPUT);
        digitalWrite(33, HIGH);
    }
}

void AutoLight()
{
    if (autolight)
    {
        ledcWrite(0, (10 - analogRead(32)*10/4100)*10);
    }
}

void SetLightTF(int a, bool b){
    switch (a%3)
    {
    case 0:
        autolight = b;
        break;
    case 1:
        turnlight = b;
        break;
    case 2:
        objectlight = b;
        break;
    default:
        break;
    }
}

void SoundRing(){
    if(!mute){
        if (soundval == 0)
        {
            digitalWrite(27, HIGH);
            delay(100);
            digitalWrite(27, LOW);
        }else if(soundval == 1){
            digitalWrite(26, HIGH);
            delay(100);
            digitalWrite(26, LOW);
        }
    }
}

void SoundValSet(int volume){
    soundval = volume;
    SoundRing();
}

void Mute(bool a){
    mute = a;
}

bool GetMute(){
    return mute;
}
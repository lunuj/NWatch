/*
 * @Author: lunuj 68381451+lunuj@users.noreply.github.com
 * @Date: 2024-01-09 20:05:29
 * @LastEditors: lunuj 68381451+lunuj@users.noreply.github.com
 * @LastEditTime: 2024-02-24 19:47:26
 * @FilePath: /TFT/wifi_config.h
 * @Description:
 *
 * Copyright (c) 2024 by ${lunuj}, All Rights Reserved.
 */
#ifndef WIFI_CONFIG_H
#define WIFI_CONFIG_H

#include <WiFiManager.h> // https://github.com/tzapu/WiFiManager
#include <time.h>
#include <stdio.h>

struct WeaInfo{
    char data[100];
    char codeday[10];
    char high[10];
    char low[10];
    char rainfall[30];
    char precip[30];
    char wind_direction[50];
    char wind_speed[50];
    char wind_scale[10];
    char humidity[30];
};


extern struct WeaInfo weainfo1;
extern struct WeaInfo weainfo2;
extern struct WeaInfo weainfo3;

void Wifi_Config_Init();

void Wifi_getTime(tm * timeinfo);

void Wifi_getWeather(char *city);

void Wifi_autoConnect();

void Wifi_getWeatherInfo();

void Wifi_Open_Portal();

void WiFi_Close_Portal();

int Wifi_IsWiFiConnected();

bool WiFi_IsPortalActive();

#endif // WIFI_CONFIG_H


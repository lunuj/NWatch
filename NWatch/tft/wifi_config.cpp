/*
 * @Author: lunuj 68381451+lunuj@users.noreply.github.com
 * @Date: 2024-01-09 20:05:21
 * @LastEditors: lunuj 68381451+lunuj@users.noreply.github.com
 * @LastEditTime: 2024-02-24 20:01:39
 * @FilePath: /TFT/wifi_config.cpp
 * @Description:
 *
 * Copyright (c) 2024 by ${lunuj}, All Rights Reserved.
 */
#include <ArduinoJson.h>
#include "wifi_config.h"
// #include "configWiFi.h"

WiFiManager wm;

// TEST OPTION FLAGS
bool TEST_CP = false;     // always start the configportal, even if ap found
int TESP_CP_TIMEOUT = 90; // test cp timeout
bool WMISBLOCKING = true; // use blocking or non blocking mode, non global params wont work in non blocking


struct WeaInfo weainfo1;
struct WeaInfo weainfo2;
struct WeaInfo weainfo3;

// void wifiInfo()
// {
//     // can contain gargbage on esp32 if wifi is not ready yet
//     Serial.println("[WIFI] WIFI INFO DEBUG");
//     Serial.println("[WIFI] SAVED: " + (String)(wm.getWiFiIsSaved() ? "YES" : "NO"));
//     Serial.println("[WIFI] SSID: " + (String)wm.getWiFiSSID());
//     Serial.println("[WIFI] PASS: " + (String)wm.getWiFiPass());
//     Serial.println("[WIFI] HOSTNAME: " + (String)WiFi.getHostname());
// }

void Wifi_Config_Init()
{
    Serial.printf("WiFiManager Starting\n");

    // wm.setDarkMode(true);
    // std::vector<const char *> menu;
    // menu.push_back("wifi");
    // menu.push_back("info");
    // menu.push_back("close");
    // menu.push_back("restart");
    // menu.push_back("exit");

    // wm.setMenu(menu); // custom menu, pass vector
    // wm.setConfigPortalBlocking(true);
    // wm.setHostname("ESP32_lunuj");
    // wm.autoConnect();

}

void Wifi_getTime(struct tm *timeinfo)
{
    int tz = 8;
    int dst = 0;
    time_t now = time(nullptr);
    unsigned timeout = 5000; // try for timeout
    unsigned start = millis();
    configTime(tz * 3600, dst * 3600, "ntp.aliyun.com", "pool.ntp.org", "time.nist.gov");
    while (now < 8 * 3600 * 2)
    { // what is this ?
        delay(100);
        Serial.print(".");
        now = time(nullptr);
        if ((millis() - start) > timeout)
        {
            Serial.println("\n[ERROR] Failed to get NTP time.");
            return;
        }
    }
    gmtime_r(&now, timeinfo);
}

void Wifi_getWeather(char *city)
{
    if (WiFi.status() == WL_CONNECTED)
    {
        WiFiClient client;
        const int httpPort = 80;
        if (!client.connect("api.seniverse.com", httpPort))
        {
            Serial.println("connection failed"); // 网络请求无响应打印连接失败
            return;
        }
        // URL请求地址
        String url = "/v3/weather/now.json?key=SEPYhqtf176Q4dNNQ&location=" + (String)city + "&language=en&unit=c";
        // 发送网络请求
        // https://api.seniverse.com/v3/weather/daily.json?key=SEPYhqtf176Q4dNNQ&location=beijing&language=zh-Hans&unit=c&start=0&days=5
        client.print(String("GET ") + url + " HTTP/1.1\r\n" +
                     "Host: " + "api.seniverse.com" + "\r\n" +
                     "Connection: close\r\n\r\n");
        delay(5000);
        // 定义answer变量用来存放请求网络服务器后返回的数据
        String answer;
        while (client.available())
        {
            String line = client.readStringUntil('\r');
            answer += line;
        }
        // 断开服务器连接
        client.stop();
        Serial.println();
        Serial.println("closing connection");
        // 获得json格式的数据
        String jsonAnswer;
        int jsonIndex;
        // 找到有用的返回数据位置i 返回头不要
        for (int i = 0; i < answer.length(); i++)
        {
            if (answer[i] == '{')
            {
                jsonIndex = i;
                break;
            }
        }
        jsonAnswer = answer.substring(jsonIndex);
        Serial.println();
        Serial.println("JSON answer: ");
        Serial.println(jsonAnswer);

        StaticJsonDocument<512> doc;

        DeserializationError error = deserializeJson(doc, jsonAnswer);

        JsonObject results_0 = doc["results"][0];

        JsonObject results_0_location = results_0["location"];
        const char *results_0_location_id = results_0_location["id"];                           // "WTVMWP4TCFT7"
        const char *results_0_location_name = results_0_location["name"];                       // "盐城"
        const char *results_0_location_country = results_0_location["country"];                 // "CN"
        const char *results_0_location_path = results_0_location["path"];                       // "盐城,盐城,江苏,中国"
        const char *results_0_location_timezone = results_0_location["timezone"];               // "Asia/Shanghai"
        const char *results_0_location_timezone_offset = results_0_location["timezone_offset"]; // "+08:00"

        JsonObject results_0_now = results_0["now"];
        const char *results_0_now_text = results_0_now["text"];               // "晴"
        const char *results_0_now_code = results_0_now["code"];               // "0"
        const char *results_0_now_temperature = results_0_now["temperature"]; // "13"

        // Serial.print("Now address:");
        // Serial.println(results_0_location_name);
        // Serial.print("Now weather:");
        // Serial.println(results_0_now_text);
        // Serial.print("Now temperature:");
        // Serial.println(results_0_now_temperature);
    }
}

void Wifi_getWeather_3Day(char *city)
{
    if (WiFi.status() == WL_CONNECTED)
    {
        WiFiClient client;
        const int httpPort = 80;
        if (!client.connect("api.seniverse.com", httpPort))
        {
            Serial.println("connection failed"); // 网络请求无响应打印连接失败
            return;
        }
        // URL请求地址
        // String url = "/v3/weather/now.json?key=SEPYhqtf176Q4dNNQ&location=" + (String)city + "&language=en&unit=c";
        // 发送网络请求
        String url = "/v3/weather/daily.json?key=SEPYhqtf176Q4dNNQ&location=" + (String)city + "&language=en&unit=c&start=0&days=5";
        client.print(String("GET ") + url + " HTTP/1.1\r\n" +
                     "Host: " + "api.seniverse.com" + "\r\n" +
                     "Connection: close\r\n\r\n");
        delay(5000);
        // 定义answer变量用来存放请求网络服务器后返回的数据
        String answer;
        while (client.available())
        {
            String line = client.readStringUntil('\r');
            answer += line;
        }
        // 断开服务器连接
        client.stop();
        // Serial.println();
        // Serial.println("closing connection");
        // 获得json格式的数据
        String jsonAnswer;
        int jsonIndex;
        // 找到有用的返回数据位置i 返回头不要
        for (int i = 0; i < answer.length(); i++)
        {
            if (answer[i] == '{')
            {
                jsonIndex = i;
                break;
            }
        }
        jsonAnswer = answer.substring(jsonIndex);
        // Serial.println();
        // Serial.println("JSON answer: ");
        // Serial.println(jsonAnswer);

        StaticJsonDocument<1536> doc;

        DeserializationError error = deserializeJson(doc, jsonAnswer);

        if (error)
        {
            Serial.print("deserializeJson() failed: ");
            Serial.println(error.c_str());
            return;
        }

        JsonObject results_0 = doc["results"][0];

        JsonObject results_0_location = results_0["location"];
        const char *results_0_location_id = results_0_location["id"];                           // "WX4FBXXFKE4F"
        const char *results_0_location_name = results_0_location["name"];                       // "北京"
        const char *results_0_location_country = results_0_location["country"];                 // "CN"
        const char *results_0_location_path = results_0_location["path"];                       // "北京,北京,中国"
        const char *results_0_location_timezone = results_0_location["timezone"];               // "Asia/Shanghai"
        const char *results_0_location_timezone_offset = results_0_location["timezone_offset"]; // "+08:00"
        int i = 0;
        for (JsonObject results_0_daily_item : results_0["daily"].as<JsonArray>())
        {
            const char *results_0_daily_item_date = results_0_daily_item["date"];                     // "2024-01-13", "2024-01-14", ...
            const char *results_0_daily_item_text_day = results_0_daily_item["text_day"];             // "多云", "晴", "晴"
            const char *results_0_daily_item_code_day = results_0_daily_item["code_day"];             // "4", "0", "0"
            const char *results_0_daily_item_text_night = results_0_daily_item["text_night"];         // "晴", "晴", "晴"
            const char *results_0_daily_item_code_night = results_0_daily_item["code_night"];         // "1", "1", "1"
            const char *results_0_daily_item_high = results_0_daily_item["high"];                     // "3", "4", "4"
            const char *results_0_daily_item_low = results_0_daily_item["low"];                       // "-4", "-9", "-8"
            const char *results_0_daily_item_rainfall = results_0_daily_item["rainfall"];             // "0.00", "0.00", "0.00"
            const char *results_0_daily_item_precip = results_0_daily_item["precip"];                 // "0.00", "0.00", "0.00"
            const char *results_0_daily_item_wind_direction = results_0_daily_item["wind_direction"]; // "北", "东北", ...
            const char *results_0_daily_item_wind_direction_degree = results_0_daily_item["wind_direction_degree"];
            const char *results_0_daily_item_wind_speed = results_0_daily_item["wind_speed"]; // "8.4", "3.0", "3.0"
            const char *results_0_daily_item_wind_scale = results_0_daily_item["wind_scale"]; // "2", "1", "1"
            const char *results_0_daily_item_humidity = results_0_daily_item["humidity"];     // "89", "41", "46"
            struct WeaInfo weainfo;
            sprintf(weainfo.data, results_0_daily_item_date);
            sprintf(weainfo.codeday, results_0_daily_item_code_day);
            sprintf(weainfo.high, results_0_daily_item_high);
            sprintf(weainfo.low, results_0_daily_item_low);
            sprintf(weainfo.rainfall, results_0_daily_item_rainfall);
            sprintf(weainfo.precip, results_0_daily_item_precip);
            sprintf(weainfo.wind_direction, results_0_daily_item_wind_direction);
            sprintf(weainfo.wind_speed, results_0_daily_item_wind_speed);
            sprintf(weainfo.wind_scale, results_0_daily_item_wind_scale);
            sprintf(weainfo.humidity, results_0_daily_item_humidity);
            switch (i)
            {
            case 0:
                weainfo1 = weainfo;
                break;
            case 1:
                weainfo2 = weainfo;
                break;
            case 2:
                weainfo3 = weainfo;
                break;
            default:
                break;
            }
            i++;
        }

        const char *results_0_last_update = results_0["last_update"]; // "2024-01-12T08:00:00+08:00"
    }
}

void Wifi_autoConnect(){
    wm.autoConnect();
}

void Wifi_getWeatherInfo()
{
    Wifi_getWeather_3Day("hainan");
}

void Wifi_Open_Portal()
{
    wm.startConfigPortal("ESP32_WiFi", "lunuj9527");
}

void WiFi_Close_Portal()
{
    wm.stopConfigPortal();
}

int Wifi_IsWiFiConnected()
{
    int status = 0;
    switch (WiFi.status())
    {
    case WL_IDLE_STATUS:    // 未连接任何热点
    case WL_SCAN_COMPLETED: // 扫描已完成。
    case WL_CONNECTED:      // 已连接到 Wi-Fi 热点。
        status = 1;
        break;
    case WL_CONNECT_FAILED:  // 连接失败
    case WL_CONNECTION_LOST: // 连接丢失
    case WL_DISCONNECTED:    // 已断开连接
    default:
        break;
    }
    return status;
}

bool WiFi_IsPortalActive()
{
    return wm.getWebPortalActive();
}
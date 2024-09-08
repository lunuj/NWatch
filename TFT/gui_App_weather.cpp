/*
 * @Author: lunuj 68381451+lunuj@users.noreply.github.com
 * @Date: 2024-01-11 01:43:15
 * @LastEditors: lunuj 68381451+lunuj@users.noreply.github.com
 * @LastEditTime: 2024-04-01 16:19:40
 * @FilePath: /TFT/gui_App_weather.cpp
 * @Description:
 *
 * Copyright (c) 2024 by ${lunuj}, All Rights Reserved.
 */
#include "gui_App_weather.h"

lv_obj_t *gui_WeaDate;
lv_obj_t *gui_WeaTemp;
lv_obj_t *ui_WeaImage;
lv_obj_t *gui_WeaHL;
lv_obj_t *label_precip;
lv_obj_t *label_fengxiang;
lv_obj_t *label_jiangyu;
lv_obj_t *label_fengsu;
lv_obj_t *label_shidu;

bool isUpdate = false;
int weainfo_index = 0;
time_t lastupdate = 0;

static void Gui_App_Weather_Title()
{
    lv_obj_t *ui_WeatherData = lv_obj_create(gui_App_screen[WEATHER]);
    lv_obj_align(ui_WeatherData, LV_ALIGN_TOP_MID, 0, 0);
    lv_obj_set_size(ui_WeatherData, 160, 20);
    lv_obj_set_style_pad_all(ui_WeatherData, 0, 0);
    lv_obj_set_style_bg_color(ui_WeatherData, lv_color_hex(0xffffff), 0);
    lv_obj_set_scrollbar_mode(ui_WeatherData, LV_SCROLLBAR_MODE_OFF);

    gui_WeaDate = lv_label_create(ui_WeatherData);
    lv_obj_align(gui_WeaDate, LV_ALIGN_TOP_MID, 0, 2);
    lv_label_set_text(gui_WeaDate, weainfo1.data);
    lv_obj_set_size(gui_WeaDate, 160, 18);
    lv_obj_set_style_text_font(gui_WeaDate, &weather_font_title, 0);
    lv_obj_set_style_text_color(gui_WeaDate, lv_palette_main(LV_PALETTE_BLUE), 0);
    lv_obj_set_style_text_align(gui_WeaDate, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
}

static void Gui_App_Weather_Temp()
{
    lv_obj_t *ui_WeatherToday = lv_obj_create(gui_App_screen[WEATHER]);
    lv_obj_align(ui_WeatherToday, LV_ALIGN_TOP_MID, 0, 20);
    lv_obj_set_size(ui_WeatherToday, 160, 44);
    lv_obj_set_style_pad_all(ui_WeatherToday, 0, 0);
    lv_obj_set_style_bg_color(ui_WeatherToday, lv_color_hex(0xffffff), 0);
    lv_obj_set_scrollbar_mode(ui_WeatherToday, LV_SCROLLBAR_MODE_OFF);

    ui_WeaImage = lv_img_create(ui_WeatherToday);
    LV_IMG_CREATE(qing, ui_WeaImage, 32, 32, 0, 0, 256, LV_ALIGN_LEFT_MID, 12, 0);

    gui_WeaTemp = lv_label_create(ui_WeatherToday);
    lv_obj_align(gui_WeaTemp, LV_ALIGN_LEFT_MID, 52, 0);
    lv_obj_set_size(gui_WeaTemp, 64, 38); /// 1
    lv_obj_set_style_text_color(gui_WeaTemp, lv_palette_main(LV_PALETTE_BLUE), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(gui_WeaTemp, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(gui_WeaTemp, &weather_font, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_label_set_text(gui_WeaTemp, "");

    gui_WeaHL = lv_label_create(ui_WeatherToday);
    lv_obj_align(gui_WeaHL, LV_ALIGN_RIGHT_MID, 0, -10);
    lv_obj_set_size(gui_WeaHL, 48, 14);
    lv_label_set_text(gui_WeaHL, "");
    lv_obj_set_style_text_font(gui_WeaHL, &lv_font_montserrat_14, 0);
    lv_obj_set_style_text_color(gui_WeaHL, lv_palette_main(LV_PALETTE_BLUE), 9);

    lv_obj_t *ui_WeaImage_rain = lv_img_create(ui_WeatherToday);
    LV_IMG_CREATE(xiayu, ui_WeaImage_rain, 16, 16, 0, 0, 256, LV_ALIGN_RIGHT_MID, -34, 9);

    label_precip = lv_label_create(ui_WeatherToday);
    lv_obj_align(label_precip, LV_ALIGN_RIGHT_MID, 0, 9);
    lv_obj_set_size(label_precip, 32, 14);
    lv_label_set_text(label_precip, "");
    lv_obj_set_style_text_font(label_precip, &lv_font_montserrat_14, 0);
    lv_obj_set_style_text_color(label_precip, lv_palette_main(LV_PALETTE_BLUE), 0);
}

static void Gui_App_Weather_Info()
{
    lv_obj_t *ui_WeatherToday_Info = lv_obj_create(gui_App_screen[WEATHER]);
    lv_obj_align(ui_WeatherToday_Info, LV_ALIGN_BOTTOM_MID, 0, 0);
    lv_obj_set_size(ui_WeatherToday_Info, 160, 64);
    lv_obj_set_style_pad_all(ui_WeatherToday_Info, 0, 0);
    lv_obj_set_style_bg_color(ui_WeatherToday_Info, lv_color_hex(0xffffff), 0);
    lv_obj_set_scrollbar_mode(ui_WeatherToday_Info, LV_SCROLLBAR_MODE_OFF);

    lv_obj_t *ui_WeaImage_fengsu = lv_img_create(ui_WeatherToday_Info);
    LV_IMG_CREATE(fengxiang, ui_WeaImage_fengsu, 32, 32, 0, 0, 256, LV_ALIGN_TOP_LEFT, 0, 0);
    lv_obj_t *ui_WeaImage_fengxiang = lv_img_create(ui_WeatherToday_Info);
    LV_IMG_CREATE(fengsu, ui_WeaImage_fengxiang, 32, 32, 0, 0, 256, LV_ALIGN_BOTTOM_LEFT, 0, 0);
    lv_obj_t *ui_WeaImage_jiangyu = lv_img_create(ui_WeatherToday_Info);
    LV_IMG_CREATE(jiangyu, ui_WeaImage_jiangyu, 32, 32, 0, 0, 64, LV_ALIGN_TOP_RIGHT, -48, 0);
    lv_obj_t *ui_WeaImage_shidu = lv_img_create(ui_WeatherToday_Info);
    LV_IMG_CREATE(shidu, ui_WeaImage_shidu, 32, 32, 0, 0, 256, LV_ALIGN_BOTTOM_RIGHT, -48, 0);

    label_fengxiang = lv_label_create(ui_WeatherToday_Info);
    lv_obj_align(label_fengxiang, LV_ALIGN_TOP_LEFT, 40, 8);
    lv_obj_set_size(label_fengxiang, 48, 16);
    lv_label_set_text(label_fengxiang, "");
    lv_obj_set_style_text_font(label_fengxiang, &weather_font_info, 0);
    lv_obj_set_style_text_color(label_fengxiang, lv_palette_main(LV_PALETTE_BLUE), 0);

    label_jiangyu = lv_label_create(ui_WeatherToday_Info);
    lv_obj_align(label_jiangyu, LV_ALIGN_TOP_RIGHT, 4, 8);
    lv_obj_set_size(label_jiangyu, 48, 16);
    lv_label_set_text(label_jiangyu, "");
    lv_obj_set_style_text_font(label_jiangyu, &lv_font_montserrat_16, 0);
    lv_obj_set_style_text_color(label_jiangyu, lv_palette_main(LV_PALETTE_BLUE), 0);

    label_fengsu = lv_label_create(ui_WeatherToday_Info);
    lv_obj_align(label_fengsu, LV_ALIGN_BOTTOM_LEFT, 40, -8);
    lv_obj_set_size(label_fengsu, 48, 16);
    lv_label_set_text(label_fengsu, "");
    lv_obj_set_style_text_font(label_fengsu, &lv_font_montserrat_16, 0);
    lv_obj_set_style_text_color(label_fengsu, lv_palette_main(LV_PALETTE_BLUE), 0);

    label_shidu = lv_label_create(ui_WeatherToday_Info);
    lv_obj_align(label_shidu, LV_ALIGN_BOTTOM_RIGHT, 4, -8);
    lv_obj_set_size(label_shidu, 48, 16);
    lv_label_set_text(label_shidu, "");
    lv_obj_set_style_text_font(label_shidu, &lv_font_montserrat_16, 0);
    lv_obj_set_style_text_color(label_shidu, lv_palette_main(LV_PALETTE_BLUE), 0);
}

static void Gui_App_Weather_Set(struct WeaInfo weainfo)
{
    char str[120];
    
    sprintf(str, "%s   %s", weainfo.data, Wifi_getCity());
    lv_label_set_text(gui_WeaDate, str);
    int a = 0;
    sscanf(weainfo.codeday, "%d", &a);
    switch (a)
    {
    case 0:
    case 1:
    case 2:
    case 3:
        lv_label_set_text(gui_WeaTemp, "晴");
        lv_img_set_src(ui_WeaImage, &qing);
        break;
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
        lv_label_set_text(gui_WeaTemp, "云");
        lv_img_set_src(ui_WeaImage, &yun);
        break;
    case 9:
        lv_label_set_text(gui_WeaTemp, "阴");
        lv_img_set_src(ui_WeaImage, &yin);
        break;
    case 11:
    case 12:
        lv_label_set_text(gui_WeaTemp, "雷");
        lv_img_set_src(ui_WeaImage, &lei);
        break;
    case 10:
    case 13:
    case 14:
    case 15:
    case 16:
    case 17:
    case 18:
    case 19:
        lv_label_set_text(gui_WeaTemp, "雨");
        lv_img_set_src(ui_WeaImage, &yu);
        break;
    case 20:
    case 21:
    case 22:
    case 23:
    case 24:
    case 25:
        lv_label_set_text(gui_WeaTemp, "雪");
        lv_img_set_src(ui_WeaImage, &xue);
        break;
    case 30:
        lv_label_set_text(gui_WeaTemp, "雾");
        lv_img_set_src(ui_WeaImage, &wu);
        break;
    default:
        lv_label_set_text(gui_WeaTemp, "无");
        lv_img_set_src(ui_WeaImage, &other);
        a = 0;
        break;
    }
    char hl[10];
    sprintf(hl, "%s / %s", weainfo.high, weainfo.low);
    lv_label_set_text(gui_WeaHL, hl);
    lv_label_set_text(label_precip, weainfo.precip);
    lv_label_set_text(label_fengsu, weainfo.wind_speed);

    lv_label_set_text(label_fengxiang, ((strcmp(weainfo.wind_direction, "无持续风向") == 0) ? "不稳":weainfo.wind_direction));
    lv_label_set_text(label_jiangyu, weainfo.rainfall);
    sprintf(hl, "%s%", weainfo.humidity);
    lv_label_set_text(label_shidu, hl);
}

void Gui_App_weather_GetTemp(char high[10], char low[10]){
    if (Wifi_IsWiFiConnected())
    {
        if (!isUpdate)
        {
            Gui_App_Weather_Update();
        }
        strcpy(high, weainfo1.high);
        strcpy(low, weainfo1.low);
    }else{
        strcpy(high, "Na");
        strcpy(low, "Na");
    }
}

static void event_key_handler(lv_event_t *e)
{
    switch (e->code)
    {
    case LV_EVENT_KEY:
    {
        const uint32_t key = lv_indev_get_key(lv_indev_get_act());
        lv_obj_t *obj = lv_event_get_target(e);
        SoundRing();

        if (key == LV_KEY_ENTER)
        {
            if(Wifi_getWeatherInfo()){
                Gui_App_Weather_Set(weainfo1);
            }
        }
        else if (key == LV_KEY_BACKSPACE)
        {
            Gui_App_Show();
        }
        else if (key == LV_KEY_LEFT)
        {
            if (isUpdate)
            {
                weainfo_index--;
                if (weainfo_index > 2)
                {
                    weainfo_index = 0;
                }
                if (weainfo_index < 0)
                {
                    weainfo_index = 2;
                }
                switch (weainfo_index)
                {
                case 0:
                    Gui_App_Weather_Set(weainfo1);
                    break;
                case 1:
                    Gui_App_Weather_Set(weainfo2);
                    break;
                case 2:
                    Gui_App_Weather_Set(weainfo3);
                    break;
                default:
                    break;
                }
            }
            
            
        }
        else if (key == LV_KEY_RIGHT)
        {
            if (isUpdate)
            {
                weainfo_index++;
                if (weainfo_index > 2)
                {
                    weainfo_index = 0;
                }
                if (weainfo_index < 0)
                {
                    weainfo_index = 2;
                }
                switch (weainfo_index)
                {
                case 0:
                    Gui_App_Weather_Set(weainfo1);
                    break;
                case 1:
                    Gui_App_Weather_Set(weainfo2);
                    break;
                case 2:
                    Gui_App_Weather_Set(weainfo3);
                    break;
                default:
                    break;
                }
            }
            
            
        }
    }
    break;
    }
}

void Gui_App_Weather_Init()
{
    gui_App_screen[WEATHER] = lv_obj_create(NULL);
    lv_group_add_obj(group, gui_App_screen[WEATHER]);
    lv_obj_add_event_cb(gui_App_screen[WEATHER], event_key_handler, LV_EVENT_KEY, NULL);
    lv_obj_clear_flag(gui_App_screen[WEATHER], LV_OBJ_FLAG_SCROLLABLE); /// Flags
    lv_obj_set_style_pad_all(gui_App_screen[WEATHER], 0, 0);

    Gui_App_Weather_Title();
    Gui_App_Weather_Temp();
    Gui_App_Weather_Info();
}

void Gui_App_Weather_Update()
{
    if (Wifi_IsWiFiConnected())
    {
        if (!isUpdate)
        {
            gettimeofday(&tv_now, NULL);
            lastupdate = tv_now.tv_sec;
            if(Wifi_getWeatherInfo()){
                Gui_App_Weather_Set(weainfo1);
                isUpdate = true;
            }else{
                lv_label_set_text(gui_WeaDate, "连接服务器失败");
            }
        }
    } else{
        lv_label_set_text(gui_WeaDate, "无网络连接");
    }
}

time_t Gui_App_Weather_GetLastupdate(){
    return lastupdate;
}

void Gui_App_Weather_CleanUpdate(){
    isUpdate = false;
}

bool Gui_App_Weather_GetUpdateStatus(){
    return isUpdate;
}
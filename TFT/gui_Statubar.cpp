/*
 * @Author: lunuj 68381451+lunuj@users.noreply.github.com
 * @Date: 2024-03-30 17:16:02
 * @LastEditors: lunuj 68381451+lunuj@users.noreply.github.com
 * @LastEditTime: 2024-03-31 21:53:04
 * @FilePath: /TFT/gui_Statubar.cpp
 * @Description: 
 * 
 * Copyright (c) 2024 by ${lunuj}, All Rights Reserved. 
 */
#include "gui_Main.h"
#include "gui_Statubar.h"

lv_obj_t *bar;
lv_obj_t *label_time;
lv_obj_t *bat_bar;
lv_obj_t *label_alarm;
lv_obj_t *label_sound;
lv_obj_t *label_title;

void Gui_Statubar_Init(){
    // 状态栏
    bar = lv_obj_create(lv_scr_act());
    lv_obj_set_size(bar, 158, 20);
    lv_obj_set_style_border_width(bar, 1, 0);
    lv_obj_set_style_pad_all(bar, 0, 0);
    lv_obj_set_style_opa(bar, LV_OPA_COVER, 0);
    lv_obj_set_style_border_side(bar, LV_BORDER_SIDE_BOTTOM | LV_BORDER_SIDE_LEFT | LV_BORDER_SIDE_RIGHT, 0);
    lv_obj_align(bar, LV_ALIGN_TOP_MID, 0, 0);
    lv_obj_clear_flag(bar, LV_OBJ_FLAG_SCROLLABLE); // 取消滚动

    // 时间
    label_time = lv_label_create(bar);
    lv_label_set_text(label_time, "LunuJ");
    lv_obj_set_size(label_time, LV_SIZE_CONTENT, 16);
    lv_obj_set_style_text_font(label_time, &lv_font_montserrat_14, 0);
    lv_obj_set_style_text_color(label_time, lv_palette_main(LV_PALETTE_BLUE), 0);
    lv_obj_align(label_time, LV_ALIGN_LEFT_MID, 5, 0);

    // 电池电量
    bat_bar = lv_bar_create(bar);
    lv_obj_set_style_border_color(bat_bar, lv_palette_main(LV_PALETTE_BLUE), LV_PART_MAIN);
    lv_obj_set_style_border_width(bat_bar, 2, LV_PART_MAIN);
    lv_obj_set_style_pad_all(bat_bar, 3, LV_PART_MAIN);
    lv_obj_set_style_radius(bat_bar, 7, LV_PART_MAIN);
    lv_obj_set_style_anim_time(bat_bar, 200, LV_PART_MAIN);

    lv_obj_set_style_radius(bat_bar, 0, LV_PART_INDICATOR);

    lv_obj_set_style_bg_opa(bat_bar, LV_OPA_COVER, LV_PART_INDICATOR);
    lv_obj_set_style_bg_color(bat_bar, lv_palette_main(LV_PALETTE_RED), LV_PART_INDICATOR);
    lv_obj_set_style_bg_grad_color(bat_bar, lv_palette_main(LV_PALETTE_GREEN), LV_PART_INDICATOR);
    lv_obj_set_style_bg_grad_dir(bat_bar, LV_GRAD_DIR_HOR, LV_PART_INDICATOR);

    lv_obj_set_size(bat_bar, 21, 14);
    lv_bar_set_range(bat_bar, 0, 100);
    lv_obj_align(bat_bar, LV_ALIGN_RIGHT_MID, -5, 0);
    lv_bar_set_value(bat_bar, 100, LV_ANIM_OFF);

    // 声音
    label_sound = lv_label_create(bar);
    lv_obj_set_size(label_sound, 14, 20);
    lv_label_set_text(label_sound, LV_SYMBOL_VOLUME_MID);
    lv_obj_set_style_text_font(label_sound, &lv_font_montserrat_14, 0);
    lv_obj_set_style_text_color(label_sound, lv_palette_main(LV_PALETTE_BLUE), 0);
    lv_obj_align_to(label_sound, bat_bar, LV_ALIGN_OUT_LEFT_MID, -4, 2);

    // 闹钟
    label_alarm = lv_label_create(bar);
    lv_obj_set_size(label_alarm, 14, 20);
    lv_label_set_text(label_alarm, LV_SYMBOL_BELL);
    lv_obj_set_style_text_font(label_alarm, &lv_font_montserrat_14, 0);
    lv_obj_set_style_text_color(label_alarm, lv_palette_main(LV_PALETTE_BLUE), 0);
    lv_obj_align_to(label_alarm, label_sound, LV_ALIGN_OUT_LEFT_MID, 0, 0);
}

void Gui_StatusBar_Set(bool isAPP, uint16_t hour, uint16_t min, uint16_t bat_value, bool alarm, int sond_value)
{
    if (isAPP)
    {
        char str[50];
        sprintf(str, "%02d : %02d", hour, min);
        lv_label_set_text(label_time, str);
    }else{
        lv_label_set_text(label_time, "LUNUJ");
    }
    
    lv_bar_set_value(bat_bar, bat_value % 101, LV_ANIM_ON);
    if (alarm)
    {
        lv_label_set_text(label_alarm, LV_SYMBOL_BELL);
    }
    else
    {
        lv_label_set_text(label_alarm, "");
    }

    if (GetMute())
    {
        lv_label_set_text(label_sound, LV_SYMBOL_MUTE);
    }else if(soundval == 0){
        lv_label_set_text(label_sound, LV_SYMBOL_VOLUME_MID);
    }else{
        lv_label_set_text(label_sound, LV_SYMBOL_VOLUME_MAX);
    }
}

void Gui_Statu_Setparent(lv_obj_t * parent){
	lv_obj_set_parent(bar, parent);
}
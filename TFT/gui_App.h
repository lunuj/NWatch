/*
 * @Author: lunuj 68381451+lunuj@users.noreply.github.com
 * @Date: 2024-01-08 16:41:03
 * @LastEditors: lunuj 68381451+lunuj@users.noreply.github.com
 * @LastEditTime: 2024-03-31 23:27:46
 * @FilePath: /TFT/gui_App.h
 * @Description: 
 * 
 * Copyright (c) 2024 by ${lunuj}, All Rights Reserved. 
 */
#ifndef GUI_APP_H
#define GUI_APP_H

#include <lvgl.h>
#include <img_def.h>
#include <icon_font.h>
#include "gui.h"
#include "gui_Main.h"
#include "gui_App_weather.h"
#include "gui_App_alarm.h"
#include "gui_App_setting.h"
#include "gui_App_battery.h"


#define APP_LIST_LEN 4

#define LV_IMG_CREATE(img, lv_img, w, h, x, y, zoom, align, pos_x, pos_y)   \
    lv_img_set_src(lv_img, &img);                                           \
    lv_obj_set_width(lv_img, w);                                            \
    lv_obj_set_height(lv_img, h);                                           \
    lv_obj_set_x(lv_img, x);                                                \
    lv_obj_set_y(lv_img, y);                                                \
    lv_obj_add_flag(lv_img, LV_OBJ_FLAG_ADV_HITTEST);                       \
    lv_obj_clear_flag(lv_img, LV_OBJ_FLAG_SCROLLABLE);                      \
    lv_img_set_zoom(lv_img, 200);                                           \
    lv_obj_align(lv_img, align, pos_x, pos_y);

#define ANIM_LINE_ADD(a, exec_cb, path_cb, ready_cb, time, back_time, delay, var, begin, end, repeatcnt) \
    do                                                                                                   \
    {                                                                                                    \
        lv_anim_init(a);                                                                                 \
        lv_anim_set_exec_cb(a, exec_cb);                                                                 \
        if (path_cb != NULL)                                                                             \
            lv_anim_set_path_cb(a, path_cb);                                                             \
        if (ready_cb != NULL)                                                                            \
            lv_anim_set_ready_cb(a, ready_cb);                                                           \
        lv_anim_set_time(a, time);                                                                       \
        lv_anim_set_playback_time(a, back_time);                                                         \
        lv_anim_set_delay(a, delay);                                                                     \
        lv_anim_set_var(a, var);                                                                         \
        lv_anim_set_values(a, begin, end);                                                               \
        lv_anim_set_repeat_count(a, repeatcnt);                                                          \
    } while (0);

enum APP_LIST{WEATHER, ALARM, BATTER, SETTING};
extern lv_group_t *group;
extern lv_obj_t *gui_App_screen[6];

void Gui_App_Init();

void Gui_App_Show();

#endif // GUI_APP_H


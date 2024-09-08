/*
 * @Author: lunuj 68381451+lunuj@users.noreply.github.com
 * @Date: 2024-01-10 23:37:39
 * @LastEditors: lunuj 68381451+lunuj@users.noreply.github.com
 * @LastEditTime: 2024-03-29 17:54:09
 * @FilePath: /TFT/gui_App_about.cpp
 * @Description:
 *
 * Copyright (c) 2024 by ${lunuj}, All Rights Reserved.
 */
#include "gui_App_about.h"

static void event_key_handler(lv_event_t *e)
{
    switch (e->code)
    {
    case LV_EVENT_KEY:
    {
        const uint32_t key = lv_indev_get_key(lv_indev_get_act());
        lv_obj_t *obj = lv_event_get_target(e);
        SoundRing();

        if (key == LV_KEY_BACKSPACE)
        {
            Gui_App_Show();
        }
    }
    break;
    }
}

void Gui_App_About_Init()
{
    gui_App_screen[ABOUT] = lv_obj_create(NULL);
    lv_group_add_obj(group, gui_App_screen[ABOUT]);
    lv_obj_add_event_cb(gui_App_screen[ABOUT], event_key_handler, LV_EVENT_KEY, NULL);

    lv_obj_t *ui_picture = lv_img_create(gui_App_screen[ABOUT]);
    LV_IMG_CREATE(face_img, ui_picture, 50, 50, 0, 0, 128, LV_ALIGN_TOP_MID, 0, 0);
    lv_obj_set_style_radius(ui_picture, 25, 0);

    lv_obj_t * gui_About_info = lv_label_create(gui_App_screen[BATTER]);
    lv_label_set_text(gui_About_info, "mail: hhmf6580873g@163.com");
    lv_obj_align(gui_About_info, LV_ALIGN_LEFT_MID, 10, -30);
    lv_obj_set_size(gui_About_info, 160, 30);
    lv_obj_set_style_radius(gui_About_info, 5, 0);
    lv_obj_set_style_text_font(gui_About_info, &lv_font_montserrat_24, 0);
    lv_obj_set_style_text_color(gui_About_info, lv_palette_main(LV_PALETTE_BLUE), 0);
    lv_obj_set_style_text_align(gui_About_info, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_flex_flow(gui_About_info, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(gui_About_info, LV_FLEX_ALIGN_SPACE_AROUND, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    lv_obj_set_style_pad_left(gui_About_info, 7, 0);
    lv_obj_set_style_pad_top(gui_About_info, 7, 0);
    lv_obj_set_style_pad_right(gui_About_info, 0, 0);
    lv_obj_set_style_border_width(gui_About_info, 0, 0);
    lv_obj_set_style_shadow_width(gui_About_info, 20, 0);
    lv_obj_set_style_shadow_color(gui_About_info, lv_palette_main(LV_PALETTE_BLUE), 0);
    lv_obj_set_scrollbar_mode(gui_About_info, LV_SCROLLBAR_MODE_OFF);

}
#line 1 "/Users/lunuj/Documents/project/esp32/TFT/gui_App_setting.cpp"
/*
 * @Author: lunuj 68381451+lunuj@users.noreply.github.com
 * @Date: 2024-01-11 17:11:29
 * @LastEditors: lunuj 68381451+lunuj@users.noreply.github.com
 * @LastEditTime: 2024-04-04 10:31:03
 * @FilePath: /TFT/gui_App_setting.cpp
 * @Description:
 *
 * Copyright (c) 2024 by ${lunuj}, All Rights Reserved.
 */
#include "gui_App_setting.h"

#define SETTING_PAGE_NUM_MAX 5
#define SUB_PAGE_NUM_MAX 9

lv_obj_t *root_page;
lv_obj_t *sub_wifi_page;
lv_obj_t *sub_data_page;
lv_obj_t *sub_display_page;
lv_obj_t *sub_sound_page;
lv_obj_t *sub_about_page;
lv_obj_t *sub_other_page;

lv_obj_t *sub_page_list[SETTING_PAGE_NUM_MAX] = {};

const int sub_page_num[SETTING_PAGE_NUM_MAX] = {3, 7, 5, 2, 1};
struct tm time_set;
static int code = 0;
static int dep = 0;
static int select_set = 0;

const int root_page_table[SETTING_PAGE_NUM_MAX][SUB_PAGE_NUM_MAX] = {
	{0, 1, },
	{0, 1, 2, 3, 4, 5, 6, 7, 8},
	{0, 2, 3, 4, 5, 0, 0, 0, 0},
	{0, 1, 2, 0, 0, 0, 0, 0, 0},
	{0, 1, 0, 0, 0, 0, 0, 0, 0}};

const int root_page_type_table[SETTING_PAGE_NUM_MAX][SUB_PAGE_NUM_MAX] = {
	{2, 2, 0, },
	{3, 3, 3, 3, 3, 3, 0},
	{1, 2, 2, 2, 3, },
	{2, 3,},
	{3, }
};

static void setting_wifi_update(){
	if (Wifi_IsWiFiOpen())
	{
		lv_obj_add_state(lv_obj_get_child(lv_obj_get_child(lv_obj_get_child(sub_page_list[code], 1), 0), 2), LV_STATE_CHECKED);
	}else{
		lv_obj_clear_state(lv_obj_get_child(lv_obj_get_child(lv_obj_get_child(sub_page_list[code], 1), 0), 2), LV_STATE_CHECKED);
	}
	if (WiFi_IsPortalActive())
	{
		lv_obj_add_state(lv_obj_get_child(lv_obj_get_child(lv_obj_get_child(sub_page_list[code], 1), 1), 2), LV_STATE_CHECKED);
	}else{
		lv_obj_clear_state(lv_obj_get_child(lv_obj_get_child(lv_obj_get_child(sub_page_list[code], 1), 1), 2), LV_STATE_CHECKED);
	}
	
}

static void setting_time_update(bool isUpdate){
	if (isUpdate)
	{
		gettimeofday(&tv_now, NULL);
		now = tv_now.tv_sec;
		localtime_r(&now, &time_set);
	}
	char str[10];
	strftime(str, 9, "%Y", &time_set);
	lv_roller_set_options(lv_obj_get_child(lv_obj_get_child(lv_obj_get_child(sub_page_list[code], 1), 0), 1), str,LV_ROLLER_MODE_INFINITE);
	strftime(str, 9, "%m", &time_set);
	lv_roller_set_options(lv_obj_get_child(lv_obj_get_child(lv_obj_get_child(sub_page_list[code], 1), 1), 1), str,LV_ROLLER_MODE_INFINITE);
	strftime(str, 9, "%d", &time_set);
	lv_roller_set_options(lv_obj_get_child(lv_obj_get_child(lv_obj_get_child(sub_page_list[code], 1), 2), 1), str,LV_ROLLER_MODE_INFINITE);
	strftime(str, 9, "%H", &time_set);
	lv_roller_set_options(lv_obj_get_child(lv_obj_get_child(lv_obj_get_child(sub_page_list[code], 1), 3), 1), str,LV_ROLLER_MODE_INFINITE);
	strftime(str, 9, "%M", &time_set);
	lv_roller_set_options(lv_obj_get_child(lv_obj_get_child(lv_obj_get_child(sub_page_list[code], 1), 4), 1), str,LV_ROLLER_MODE_INFINITE);

}

static void setting_time_change(int addorsub){
	int index = 0;

	if(addorsub >= 0){
		index = 1;
	}else{
		index = -1;
	}
	switch (select_set%5)
	{
	case 0:
		time_set.tm_year += index;
		break;
	case 1:
		time_set.tm_mon += index;
		break;
	case 2:
		time_set.tm_mday += index;
		break;
	case 3:
		time_set.tm_hour += index;
		break;
	case 4:
		time_set.tm_min += index;
		break;
	default:
		break;
	}
	
	now = mktime(&time_set);
	localtime_r(&now, &time_set);
	setting_time_update(false);
}

static void sub_wifi_page_fun0()
{
	if (lv_obj_get_state(lv_obj_get_child(lv_obj_get_child(lv_obj_get_child(sub_page_list[code], 1), select_set), 2)) == LV_STATE_CHECKED)
		Wifi_Open_Wifi();
	else
		Wifi_Close_Wifi();
	setting_wifi_update();
}

static void sub_wifi_page_fun1(){
	if (lv_obj_get_state(lv_obj_get_child(lv_obj_get_child(lv_obj_get_child(sub_page_list[code], 1), select_set), 2)) == LV_STATE_CHECKED)
		Wifi_Open_Portal();
	else
		WiFi_Close_Portal();
	setting_wifi_update();
}

static void sub_wifi_page_fun2(){
	Wifi_cleanall();
	setting_wifi_update();
}

static void sub_data_page_fun0(){
	now = mktime(&time_set);
	tv_now.tv_sec = now;
	tv_now.tv_usec = 0;
	settimeofday(&tv_now, NULL);
	Gui_Main_SetTimeCurrent(false);
}

static void sub_data_page_fun1(){
	Gui_Main_SetTimetoupdate(lv_roller_get_selected(lv_obj_get_child(lv_obj_get_child(lv_obj_get_child(sub_page_list[code], 1), select_set), 1)));
}

static void sub_data_page_fun2(){
	Wifi_getTime(&time_set);
	now = mktime(&time_set);
	tv_now.tv_sec = now + 60 * 60 * 8;
	tv_now.tv_usec = 0;
	settimeofday(&tv_now, NULL);
	setting_time_update(true);
	Gui_Main_SetTimeCurrent(true);

	// dep = 0;
	// lv_obj_set_style_text_color(lv_obj_get_child(lv_obj_get_child(sub_page_list[code], 1), select_set), lv_color_black(), 0);
	// select_set = 0;
	// lv_menu_clear_history(gui_App_screen[SETTING]);			
	// lv_menu_set_page(gui_App_screen[SETTING], root_page);
	// lv_event_send(lv_obj_get_child(lv_obj_get_child(root_page, 0), code), LV_EVENT_PRESSED, NULL);	
	// lv_obj_scroll_to(sub_page_list[code], 0, 24 * root_page_table[code][select_set], LV_ANIM_OFF);
	// lv_event_send(lv_obj_get_child(lv_obj_get_child(root_page, 0), code), LV_EVENT_PRESS_LOST, NULL);
	// code = 0;
	// lv_event_send(lv_obj_get_child(lv_obj_get_child(root_page, 0), code), LV_EVENT_PRESSED, NULL);
	
	// Gui_Main_Show();
}

static void sub_display_page_fun0(){
	Gui_Oled_light(lv_slider_get_value(lv_obj_get_child(lv_obj_get_child(lv_obj_get_child(sub_page_list[code], 1), select_set), 2)));
}

static void sub_display_page_fun1(){
	if (lv_obj_get_state(lv_obj_get_child(lv_obj_get_child(lv_obj_get_child(sub_page_list[code], 1), select_set), 2)) == LV_STATE_CHECKED)
	{
		SetLightTF(select_set - 1, true);
	}else{
		SetLightTF(select_set - 1, false);
	}
}

static void sub_display_page_fun2(){
	Gui_Sleeptime_Set(lv_roller_get_selected(lv_obj_get_child(lv_obj_get_child(lv_obj_get_child(sub_page_list[code], 1), select_set), 1)));
}

static void sub_sound_page_fun0(){
	Mute(lv_obj_get_state(lv_obj_get_child(lv_obj_get_child(lv_obj_get_child(sub_page_list[code], 1), select_set), 2)) == LV_STATE_CHECKED);
}

static void sub_sound_page_fun1(){
	int a = lv_roller_get_selected(lv_obj_get_child(lv_obj_get_child(lv_obj_get_child(sub_page_list[code], 1), select_set), 1));
	SoundValSet(a);
}

static void sub_other_page_fun0(){
	char buf[20];
	lv_roller_get_selected_str(lv_obj_get_child(lv_obj_get_child(lv_obj_get_child(sub_page_list[code], 1), select_set), 1), buf, 19);
	Wifi_setCity(buf);
	Gui_App_Weather_CleanUpdate();
	Gui_App_Weather_Update();
}

static void (*root_page_function_table[SETTING_PAGE_NUM_MAX][SUB_PAGE_NUM_MAX])() = {
	{sub_wifi_page_fun0, sub_wifi_page_fun1, sub_wifi_page_fun2},
	{sub_data_page_fun0, sub_data_page_fun0, sub_data_page_fun0, sub_data_page_fun0, sub_data_page_fun0,sub_data_page_fun1,sub_data_page_fun2},
	{sub_display_page_fun0, sub_display_page_fun1, sub_display_page_fun1, sub_display_page_fun1, sub_display_page_fun2},
	{sub_sound_page_fun0, sub_sound_page_fun1},
	{sub_other_page_fun0}};

static lv_obj_t *create_text(lv_obj_t *parent, const char *icon, const char *txt, u8_t builder_variant)
{
	lv_obj_t *obj = lv_menu_cont_create(parent);
	lv_obj_set_size(obj, 160, 24);
	lv_obj_t *img = NULL;
	lv_obj_t *label = NULL;

	if (icon)
	{
		img = lv_img_create(obj);
		lv_obj_set_style_text_font(img, &icon_setting_font, 0);
		lv_img_set_src(img, icon);
	}

	if (txt)
	{
		label = lv_label_create(obj);
		lv_label_set_text(label, txt);
		lv_label_set_long_mode(label, LV_LABEL_LONG_SCROLL_CIRCULAR);
		lv_obj_set_style_text_font(label, &setting_font, 0);
		lv_obj_set_flex_grow(label, 1);
		lv_obj_set_size(obj, 160, 24);
		lv_obj_set_size(label, 160, 20);
	}

	if (builder_variant == 1 && icon && txt)
	{
		lv_obj_add_flag(img, LV_OBJ_FLAG_FLEX_IN_NEW_TRACK);
		lv_obj_swap(img, label);
		lv_label_set_long_mode(label, LV_LABEL_LONG_SCROLL_CIRCULAR);
		lv_obj_set_style_pad_top(label, 2, 0);
		lv_obj_set_style_text_font(label, &setting_font, 0);
		lv_obj_set_style_text_font(img, &icon_setting_font, 0);
		lv_obj_set_size(obj, 160, 48);
		lv_obj_set_size(label, 100, 20);
	}
	if (builder_variant == 2)
	{
		lv_label_set_long_mode(label, LV_LABEL_LONG_SCROLL_CIRCULAR);
		lv_obj_set_flex_grow(label, 0);
		lv_obj_set_size(obj, 160, 24);
		lv_obj_set_size(label, 65, 20);
	}

	return obj;
}
static lv_obj_t *create_slider(lv_obj_t *parent, const char *icon, const char *txt, int32_t min, int32_t max, int32_t val)
{
	lv_obj_t *obj = create_text(parent, icon, txt, 1);
	lv_obj_t *slider = lv_slider_create(obj);
	lv_obj_set_size(slider, 90, 4);
	lv_slider_set_range(slider, min, max);
	lv_slider_set_value(slider, val, LV_ANIM_OFF);

	if (icon == NULL)
	{
		lv_obj_add_flag(slider, LV_OBJ_FLAG_FLEX_IN_NEW_TRACK);
	}

	return obj;
}
static lv_obj_t *create_switch(lv_obj_t *parent, const char *icon, const char *txt, bool chk)
{
	lv_obj_t *obj = create_text(parent, icon, txt, 2);

	lv_obj_t *sw = lv_switch_create(obj);
	lv_obj_add_state(sw, chk ? LV_STATE_CHECKED : 0);
	lv_obj_set_size(sw, 36, 20);

	return obj;
}
static lv_obj_t *create_roller(lv_obj_t *parent, const char *option, const char *txt)
{
	lv_obj_t *obj = lv_menu_cont_create(parent);
	lv_obj_set_size(obj, 140, 24);
	lv_obj_t *label = NULL;
	lv_obj_t *roller = NULL;

	if (txt)
	{
		label = lv_label_create(obj);
		lv_label_set_text(label, txt);
		// lv_label_set_long_mode(label, LV_LABEL_LONG_SCROLL_CIRCULAR);
		lv_label_set_long_mode(label, LV_LABEL_LONG_SCROLL_CIRCULAR);
		lv_obj_set_style_text_font(label, &setting_font, 0);
		lv_obj_set_size(label, 80, 20);
	}

	if (option)
	{
		roller = lv_roller_create(obj);
		lv_obj_set_size(roller, 40, 20);
		lv_obj_set_align(roller, LV_ALIGN_LEFT_MID);
		lv_obj_set_style_text_font(label, &setting_font, 0);
		lv_obj_set_style_text_font(roller, &setting_font, 0);
		lv_roller_set_options(roller, option, LV_ROLLER_MODE_INFINITE);
		lv_obj_set_style_text_color(roller, lv_color_hex(0x000000), LV_PART_SELECTED);
		lv_obj_set_style_bg_color(roller, lv_color_hex(0xffffff), LV_PART_SELECTED);
	}
	return obj;
}

static void switch_handler()
{
	if (code == 0)
	{
		lv_menu_set_page(gui_App_screen[SETTING], NULL);
		lv_menu_set_sidebar_page(gui_App_screen[SETTING], root_page);
		lv_event_send(lv_obj_get_child(lv_obj_get_child(lv_menu_get_cur_sidebar_page(gui_App_screen[SETTING]), 0), 0), LV_EVENT_CLICKED, NULL);
		code = 1;
	}
	else
	{
		lv_menu_set_sidebar_page(gui_App_screen[SETTING], NULL);
		lv_menu_clear_history(gui_App_screen[SETTING]);
		lv_menu_set_page(gui_App_screen[SETTING], root_page);
		code = 0;
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
			if (dep == 0)
			{
				lv_event_send(lv_obj_get_child(lv_obj_get_child(root_page, 0), code), LV_EVENT_PRESS_LOST, NULL);
				lv_event_send(lv_obj_get_child(lv_obj_get_child(root_page, 0), code), LV_EVENT_CLICKED, NULL);
				lv_obj_set_style_text_color(lv_obj_get_child(lv_obj_get_child(sub_page_list[code], 1), select_set), lv_palette_main(LV_PALETTE_BLUE), 0);
				if(code == 0)
					setting_wifi_update();
				if(code == 1)
					setting_time_update(true);
				
				dep = 1;
			}
			else if (dep == 1)
			{
				lv_obj_set_style_text_color(lv_obj_get_child(lv_obj_get_child(sub_page_list[code], 1), select_set), lv_palette_main(LV_PALETTE_ORANGE), 0);
				dep = 2;
			}
			else if (dep == 2)
			{
				lv_obj_set_style_text_color(lv_obj_get_child(lv_obj_get_child(sub_page_list[code], 1), select_set), lv_palette_main(LV_PALETTE_BLUE), 0);
				dep = 1;
				(root_page_function_table[code][select_set])();
			}
		}
		else if (key == LV_KEY_BACKSPACE)
		{
			if (dep == 0)
			{
				lv_event_send(lv_obj_get_child(lv_obj_get_child(root_page, 0), code), LV_EVENT_PRESS_LOST, NULL);
				code = 0;
				lv_obj_scroll_to(root_page, 0, 0, LV_ANIM_OFF);
				lv_event_send(lv_obj_get_child(lv_obj_get_child(root_page, 0), code), LV_EVENT_PRESSED, NULL);
				Gui_App_Show();
			}
			else if (dep == 1)
			{
				dep = 0;
				lv_obj_set_style_text_color(lv_obj_get_child(lv_obj_get_child(sub_page_list[code], 1), select_set), lv_color_black(), 0);
				select_set = 0;
				lv_menu_clear_history(gui_App_screen[SETTING]);	
				lv_event_send(lv_obj_get_child(lv_obj_get_child(root_page, 0), code), LV_EVENT_PRESSED, NULL);	
				lv_obj_scroll_to(sub_page_list[code], 0, 24 * root_page_table[code][select_set], LV_ANIM_OFF);
				lv_menu_set_page(gui_App_screen[SETTING], root_page);
			}
			else if (dep == 2)
			{
			}
		}
		else if (key == LV_KEY_LEFT)
		{
			if (dep == 0)
			{
				lv_event_send(lv_obj_get_child(lv_obj_get_child(root_page, 0), code), LV_EVENT_PRESS_LOST, NULL);
				code--;
				if (code < 0)
				{
					code = 0;
				}
				else if (code < 2)
				{
					lv_obj_scroll_to(root_page, 0, 0, LV_ANIM_ON);
				}
				else if (code < SETTING_PAGE_NUM_MAX - 3)
				{
					lv_obj_scroll_to(root_page, 0, 24 * (code - 3), LV_ANIM_ON);
				}
				else if (code < SETTING_PAGE_NUM_MAX)
				{
					lv_obj_scroll_to(root_page, 0, 24 * (code - 3) + 18, LV_ANIM_ON);
				}
				else if (code = SETTING_PAGE_NUM_MAX)
				{
					code = SETTING_PAGE_NUM_MAX - 1;
				}
				lv_event_send(lv_obj_get_child(lv_obj_get_child(root_page, 0), code), LV_EVENT_PRESSED, NULL);
			}
			else if (dep == 1)
			{
				lv_obj_set_style_text_color(lv_obj_get_child(lv_obj_get_child(sub_page_list[code], 1), select_set), lv_color_black(), 0);
				select_set = (select_set + sub_page_num[code] - 1) % sub_page_num[code];
				lv_obj_set_style_text_color(lv_obj_get_child(lv_obj_get_child(sub_page_list[code], 1), select_set), lv_palette_main(LV_PALETTE_BLUE), 0);
				lv_obj_scroll_to(sub_page_list[code], 0, 24 * root_page_table[code][select_set], LV_ANIM_ON);
			}
			else if (dep == 2)
			{
				lv_obj_t *lv_part;
				int32_t lv_part_val;
				switch (root_page_type_table[code][select_set])
				{
				case 1:
					lv_part = lv_obj_get_child(lv_obj_get_child(lv_obj_get_child(sub_page_list[code], 1), select_set), 2);
					lv_part_val = lv_slider_get_value(lv_part);
					lv_slider_set_value(lv_part, lv_part_val - 1, LV_ANIM_ON);
					sub_display_page_fun0();
					break;
				case 2:
					lv_part = lv_obj_get_child(lv_obj_get_child(lv_obj_get_child(sub_page_list[code], 1), select_set), 2);
					if (lv_obj_get_state(lv_part) == LV_STATE_CHECKED)
						lv_obj_clear_state(lv_part, LV_STATE_CHECKED);
					else
						lv_obj_add_state(lv_part, LV_STATE_CHECKED);
					break;
				case 3:
					lv_part = lv_obj_get_child(lv_obj_get_child(lv_obj_get_child(sub_page_list[code], 1), select_set), 1);
					if (code == 1 && select_set < 5)
					{
						setting_time_change(-1);
					}else{
						lv_part = lv_obj_get_child(lv_obj_get_child(lv_obj_get_child(sub_page_list[code], 1), select_set), 1);
						lv_part_val = lv_roller_get_selected(lv_part);
						lv_roller_set_selected(lv_part, lv_part_val-1, LV_ANIM_ON);
					}
					break;
				default:
					break;
				}
			}
		}
		else if (key == LV_KEY_RIGHT)
		{
			if (dep == 0)
			{
				lv_event_send(lv_obj_get_child(lv_obj_get_child(root_page, 0), code), LV_EVENT_PRESS_LOST, NULL);
				code++;
				if (code < 0)
				{
					code = 0;
				}
				else if (code < 2)
				{
					lv_obj_scroll_to(root_page, 0, 0, LV_ANIM_ON);
				}
				else if (code < SETTING_PAGE_NUM_MAX - 3)
				{
					lv_obj_scroll_to(root_page, 0, 24 * (code - 3), LV_ANIM_ON);
				}
				else if (code < SETTING_PAGE_NUM_MAX)
				{
					lv_obj_scroll_to(root_page, 0, 18 + 24 * (code - 3), LV_ANIM_ON);
				}
				else if (code = SETTING_PAGE_NUM_MAX)
				{
					code = SETTING_PAGE_NUM_MAX - 1;
				}
				lv_event_send(lv_obj_get_child(lv_obj_get_child(root_page, 0), code), LV_EVENT_PRESSED, NULL);
			}
			else if (dep == 1)
			{
				lv_obj_set_style_text_color(lv_obj_get_child(lv_obj_get_child(sub_page_list[code], 1), select_set), lv_color_black(), 0);
				select_set = (select_set + 1) % sub_page_num[code];
				lv_obj_set_style_text_color(lv_obj_get_child(lv_obj_get_child(sub_page_list[code], 1), select_set), lv_palette_main(LV_PALETTE_BLUE), 0);
				lv_obj_scroll_to(sub_page_list[code], 0, 24 * root_page_table[code][select_set], LV_ANIM_ON);
			}
			else if (dep == 2)
			{
				lv_obj_t *lv_part;
				int32_t lv_part_val;
				switch (root_page_type_table[code][select_set])
				{
				case 1:
					lv_part = lv_obj_get_child(lv_obj_get_child(lv_obj_get_child(sub_page_list[code], 1), select_set), 2);
					lv_part_val = lv_slider_get_value(lv_part);
					lv_slider_set_value(lv_part, lv_part_val + 1, LV_ANIM_ON);
					sub_display_page_fun0();
					break;
				case 2:
					lv_part = lv_obj_get_child(lv_obj_get_child(lv_obj_get_child(sub_page_list[code], 1), select_set), 2);
					if (lv_obj_get_state(lv_part) == LV_STATE_CHECKED)
						lv_obj_clear_state(lv_part, LV_STATE_CHECKED);
					else
						lv_obj_add_state(lv_part, LV_STATE_CHECKED);
					break;
				case 3:
					if (code == 1 && select_set < 5)
					{
						setting_time_change(1);
					}else{
						lv_part = lv_obj_get_child(lv_obj_get_child(lv_obj_get_child(sub_page_list[code], 1), select_set), 1);
						lv_part_val = lv_roller_get_selected(lv_part);
						lv_roller_set_selected(lv_part, lv_part_val+1, LV_ANIM_ON);
					}

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

static void Gui_App_Setting_Sub()
{
	int sub_num = 0;

	lv_obj_t *cont;
	lv_obj_t *section;

	sub_wifi_page = lv_menu_page_create(gui_App_screen[SETTING], "WiFi");
	lv_obj_set_style_pad_hor(sub_wifi_page, lv_obj_get_style_pad_left(lv_menu_get_main_header(gui_App_screen[SETTING]), 0), 0);
	lv_menu_separator_create(sub_wifi_page);
	section = lv_menu_section_create(sub_wifi_page);
	create_switch(section, ICON_FONT_SETTING_WIFI, "无线网络", 0);
	create_switch(section, ICON_FONT_SETTING_PORT, "移动热点", 0);
	create_text(section, ICON_FONT_SETTING_CLEAR, "清除连接", 0);
	sub_page_list[sub_num] = sub_wifi_page;
	sub_num++;

	sub_data_page = lv_menu_page_create(gui_App_screen[SETTING], "Date");
	lv_obj_set_style_pad_hor(sub_data_page, lv_obj_get_style_pad_left(lv_menu_get_main_header(gui_App_screen[SETTING]), 0), 0);
	lv_menu_separator_create(sub_data_page);
	section = lv_menu_section_create(sub_data_page);
	create_roller(section, "1", "设置年");
	create_roller(section, "2", "设置月");
	create_roller(section, "3", "设置日");
	create_roller(section, "4", "设置时");
	create_roller(section, "5", "设置分");
	create_roller(section, "off\n15m\n30m\n1h\n6h\n12h\n24h", "自动更新");
	create_text(section, ICON_FONT_SETTING_UPDATE, "立即更新", 0);
	sub_page_list[sub_num] = sub_data_page;
	sub_num++;

	sub_display_page = lv_menu_page_create(gui_App_screen[SETTING], "Display");
	lv_obj_set_style_pad_hor(sub_display_page, lv_obj_get_style_pad_left(lv_menu_get_main_header(gui_App_screen[SETTING]), 0), 0);
	lv_menu_separator_create(sub_display_page);
	section = lv_menu_section_create(sub_display_page);
	create_slider(section, ICON_FONT_SETTING_LIGHT, "亮度设置", 0, 10, 10);
	create_switch(section, ICON_FONT_SETTING_AUTOLIGHT, "自动亮度", false);
	create_switch(section, ICON_FONT_SETTING_TURN, "翻转亮屏", false);
	create_switch(section, ICON_FONT_SETTING_OBJ, "物体亮屏", false);
	create_roller(section, "off\n15s\n30s\n1m\n5m\n10m\n15m", "自动熄屏");
	sub_page_list[sub_num] = sub_display_page;
	sub_num++;

	sub_sound_page = lv_menu_page_create(gui_App_screen[SETTING], "Sound");
	lv_obj_set_style_pad_hor(sub_sound_page, lv_obj_get_style_pad_left(lv_menu_get_main_header(gui_App_screen[SETTING]), 0), 0);
	lv_menu_separator_create(sub_sound_page);
	section = lv_menu_section_create(sub_sound_page);
	create_switch(section, ICON_FONT_SETTING_MUTE, "静音模式", false);
	create_roller(section, "小\n大", "音量大小");
	sub_page_list[sub_num] = sub_sound_page;
	sub_num++;

	sub_other_page = lv_menu_page_create(gui_App_screen[SETTING], "Other");
	lv_obj_set_style_pad_hor(sub_other_page, lv_obj_get_style_pad_left(lv_menu_get_main_header(gui_App_screen[SETTING]), 0), 0);
	lv_menu_separator_create(sub_other_page);
	section = lv_menu_section_create(sub_other_page);
	// create_text(section, LV_SYMBOL_AUDIO, "其他设置", false);
	create_roller(section, "海口\n深圳\n北京\n南阳", "天气地区");
	sub_page_list[sub_num] = sub_other_page;
}

static void Gui_App_Setting_Sidebar()
{
	lv_obj_t *cont;
	lv_obj_t *section;
	root_page = lv_menu_page_create(gui_App_screen[SETTING], "Settings");

	lv_obj_set_style_pad_hor(root_page, lv_obj_get_style_pad_left(lv_menu_get_main_header(gui_App_screen[SETTING]), 0), 0);
	lv_obj_set_style_bg_opa(root_page, LV_OPA_0, LV_PART_SCROLLBAR | LV_STATE_DEFAULT);

	section = lv_menu_section_create(root_page);
	cont = create_text(section, ICON_FONT_SETTING_WIFI, "无线与网络", 0);
	lv_menu_set_load_page_event(gui_App_screen[SETTING], cont, sub_wifi_page);
	cont = create_text(section, ICON_FONT_SETTING_DATE, "日期与时间", 0);
	lv_menu_set_load_page_event(gui_App_screen[SETTING], cont, sub_data_page);
	cont = create_text(section, ICON_FONT_SETTING_DISPLAY, "显示", 0);
	lv_menu_set_load_page_event(gui_App_screen[SETTING], cont, sub_display_page);
	cont = create_text(section, ICON_FONT_SETTING_SOUND, "声音", 0);
	lv_menu_set_load_page_event(gui_App_screen[SETTING], cont, sub_sound_page);
	cont = create_text(section, ICON_FONT_SETTING_OTHER, "其他", 0);
	lv_menu_set_load_page_event(gui_App_screen[SETTING], cont, sub_other_page);
}

void Gui_App_Setting_Init()
{
	gui_App_screen[SETTING] = lv_menu_create(NULL);
	lv_group_add_obj(group, gui_App_screen[SETTING]);
	lv_obj_set_size(gui_App_screen[SETTING], 160, 128);
	lv_obj_add_event_cb(gui_App_screen[SETTING], event_key_handler, LV_EVENT_KEY, NULL);
	lv_obj_set_style_bg_color(gui_App_screen[SETTING], lv_color_darken(lv_obj_get_style_bg_color(gui_App_screen[SETTING], 0), 10), 0);
	lv_obj_center(gui_App_screen[SETTING]);

	Gui_App_Setting_Sub();
	Gui_App_Setting_Sidebar();

	lv_menu_set_mode_root_back_btn(gui_App_screen[SETTING], LV_MENU_ROOT_BACK_BTN_DISABLED);
	lv_menu_set_page(gui_App_screen[SETTING], root_page);
	lv_event_send(lv_obj_get_child(lv_obj_get_child(root_page, 0), code), LV_EVENT_PRESSED, NULL);
}
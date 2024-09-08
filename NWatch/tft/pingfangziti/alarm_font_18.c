/*******************************************************************************
 * Size: 18 px
 * Bpp: 4
 * Opts: 
 ******************************************************************************/

#ifdef LV_LVGL_H_INCLUDE_SIMPLE
#include "lvgl.h"
#else
#include "lvgl/lvgl.h"
#endif

#ifndef ALARM_FONT_18
#define ALARM_FONT_18 1
#endif

#if ALARM_FONT_18

/*-----------------
 *    BITMAPS
 *----------------*/

/*Store the image of the glyphs*/
static LV_ATTRIBUTE_LARGE_CONST const uint8_t glyph_bitmap[] = {
    /* U+4E00 "一" */
    0x3, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33,
    0x30, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xf1, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0,

    /* U+4E0A "上" */
    0x0, 0x0, 0x0, 0x7d, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x7, 0xd0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x7d, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x7, 0xd0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x7d, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x7, 0xd2, 0x22,
    0x22, 0x21, 0x0, 0x0, 0x0, 0x0, 0x7f, 0xff,
    0xff, 0xff, 0x70, 0x0, 0x0, 0x0, 0x7, 0xd1,
    0x11, 0x11, 0x10, 0x0, 0x0, 0x0, 0x0, 0x7d,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x7,
    0xd0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x7d, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x7, 0xd0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x7d, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x7, 0xd0, 0x0, 0x0, 0x0, 0x0, 0x33,
    0x33, 0x33, 0x9d, 0x33, 0x33, 0x33, 0x33, 0xf,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0,

    /* U+4E0B "下" */
    0xf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xf0, 0x44, 0x44, 0x44, 0x6f, 0x64, 0x44, 0x44,
    0x44, 0x0, 0x0, 0x0, 0x2, 0xf2, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x2f, 0x20, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x2, 0xfb, 0x30,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x2f, 0xcf,
    0xa1, 0x0, 0x0, 0x0, 0x0, 0x0, 0x2, 0xf2,
    0x4d, 0xf7, 0x0, 0x0, 0x0, 0x0, 0x0, 0x2f,
    0x20, 0x7, 0xfd, 0x30, 0x0, 0x0, 0x0, 0x2,
    0xf2, 0x0, 0x2, 0xcb, 0x0, 0x0, 0x0, 0x0,
    0x2f, 0x20, 0x0, 0x0, 0x10, 0x0, 0x0, 0x0,
    0x2, 0xf2, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x2f, 0x20, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x2, 0xf2, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x2f, 0x20, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x2, 0xf2, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x2f, 0x20, 0x0, 0x0, 0x0,

    /* U+56DE "回" */
    0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf3,
    0x3f, 0x32, 0x22, 0x22, 0x22, 0x22, 0x23, 0xf3,
    0x3f, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xf3,
    0x3f, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xf3,
    0x3f, 0x0, 0x5e, 0xee, 0xee, 0xe5, 0x0, 0xf3,
    0x3f, 0x0, 0x5f, 0x33, 0x33, 0xf5, 0x0, 0xf3,
    0x3f, 0x0, 0x5e, 0x0, 0x0, 0xe5, 0x0, 0xf3,
    0x3f, 0x0, 0x5e, 0x0, 0x0, 0xe5, 0x0, 0xf3,
    0x3f, 0x0, 0x5e, 0x0, 0x0, 0xe5, 0x0, 0xf3,
    0x3f, 0x0, 0x5f, 0x33, 0x33, 0xf5, 0x0, 0xf3,
    0x3f, 0x0, 0x5f, 0xff, 0xff, 0xf5, 0x0, 0xf3,
    0x3f, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xf3,
    0x3f, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xf3,
    0x3f, 0x43, 0x33, 0x33, 0x33, 0x33, 0x34, 0xf3,
    0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf3,
    0x3f, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xf3,

    /* U+5B9A "定" */
    0x0, 0x0, 0x0, 0x0, 0xd5, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x9c, 0x0, 0x0,
    0x0, 0x0, 0x5, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0x50, 0x5, 0xf3, 0x33, 0x33, 0x33,
    0x33, 0x33, 0x3f, 0x50, 0x5, 0xe0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0xe, 0x50, 0x5, 0xe0, 0x44,
    0x44, 0x44, 0x44, 0x44, 0x2d, 0x40, 0x0, 0x3,
    0xff, 0xff, 0xff, 0xff, 0xff, 0x70, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x5e, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x64, 0x0, 0x5e, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0xf5, 0x0, 0x5e, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x3, 0xf1, 0x0, 0x5f, 0xff,
    0xff, 0xf4, 0x0, 0x0, 0x8, 0xd0, 0x0, 0x5f,
    0x33, 0x33, 0x31, 0x0, 0x0, 0xe, 0xf5, 0x0,
    0x5e, 0x0, 0x0, 0x0, 0x0, 0x0, 0x6f, 0x8e,
    0x10, 0x5e, 0x0, 0x0, 0x0, 0x0, 0x0, 0xe8,
    0xa, 0xe6, 0x6e, 0x0, 0x0, 0x0, 0x0, 0xa,
    0xe0, 0x0, 0x7f, 0xff, 0x75, 0x43, 0x33, 0x40,
    0xe, 0x30, 0x0, 0x1, 0x59, 0xcd, 0xef, 0xff,
    0xf0, 0x1, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0,

    /* U+786E "确" */
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x4e, 0x20, 0x0,
    0x0, 0xe, 0xff, 0xff, 0xf1, 0xc, 0xe2, 0x22,
    0x20, 0x0, 0xbc, 0xf7, 0x44, 0x6, 0xff, 0xee,
    0xfd, 0x0, 0x0, 0x1f, 0x10, 0x3, 0xf9, 0x0,
    0xc, 0x40, 0x0, 0x5, 0xd0, 0x1, 0xee, 0x33,
    0x3a, 0xc3, 0x31, 0x0, 0x9a, 0x0, 0x2b, 0xef,
    0xef, 0xfe, 0xef, 0x40, 0xe, 0x93, 0x32, 0xe,
    0x40, 0x3e, 0x0, 0xe4, 0x6, 0xfe, 0xde, 0xa0,
    0xe6, 0x15, 0xe1, 0x1e, 0x40, 0xef, 0x70, 0x8a,
    0xe, 0xff, 0xff, 0xff, 0xf4, 0x4e, 0xd7, 0x8,
    0xa0, 0xe5, 0x4, 0xe0, 0xe, 0x40, 0x3b, 0x70,
    0x8a, 0xe, 0x40, 0x3e, 0x0, 0xe4, 0x0, 0xb7,
    0x8, 0xa0, 0xfe, 0xde, 0xfd, 0xdf, 0x40, 0xb,
    0x70, 0x8a, 0x1f, 0x54, 0x7f, 0x44, 0xf4, 0x0,
    0xb9, 0x3a, 0xa3, 0xf0, 0x3, 0xe0, 0xe, 0x40,
    0xb, 0xff, 0xf9, 0x8b, 0x0, 0x3e, 0x0, 0xe4,
    0x0, 0xb7, 0x0, 0xf, 0x60, 0x3, 0xe0, 0xf,
    0x40, 0x2, 0x10, 0x1, 0xd0, 0x0, 0x3e, 0x5f,
    0xe1, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x10, 0x0,

    /* U+8FD4 "返" */
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x30,
    0x4, 0xe4, 0x0, 0x1, 0x56, 0x78, 0xad, 0xff,
    0x50, 0x8, 0xf5, 0x0, 0x4f, 0xcb, 0xa9, 0x63,
    0x0, 0x0, 0x7, 0xf3, 0x4, 0xe0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x4, 0x0, 0x4e, 0x22, 0x22,
    0x22, 0x21, 0x0, 0x0, 0x0, 0x5, 0xfe, 0xee,
    0xee, 0xef, 0x50, 0x33, 0x33, 0x0, 0x5d, 0x0,
    0x0, 0x3, 0xf1, 0xd, 0xff, 0xe0, 0x7, 0xc2,
    0xb1, 0x0, 0xbb, 0x0, 0x0, 0x4e, 0x0, 0x9b,
    0x1b, 0xe3, 0x3f, 0x30, 0x0, 0x4, 0xe0, 0xc,
    0x80, 0x8, 0xfe, 0xa0, 0x0, 0x0, 0x4e, 0x0,
    0xf5, 0x0, 0xb, 0xf8, 0x0, 0x0, 0x4, 0xe0,
    0x5f, 0x10, 0xa, 0xf7, 0xf8, 0x0, 0x0, 0x4e,
    0xd, 0xb0, 0x2c, 0xe3, 0x4, 0xf7, 0x0, 0x7,
    0xf2, 0xa3, 0x2f, 0xc2, 0x0, 0x5, 0xe0, 0x6,
    0xfb, 0xc0, 0x0, 0x50, 0x0, 0x0, 0x0, 0x3,
    0xf5, 0x9, 0xd7, 0x43, 0x22, 0x22, 0x33, 0x31,
    0x9a, 0x0, 0x6, 0xbe, 0xff, 0xff, 0xff, 0xff,
    0x40, 0x10, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0,

    /* U+9875 "页" */
    0xef, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe,
    0x33, 0x33, 0x33, 0x3d, 0xa3, 0x33, 0x33, 0x33,
    0x0, 0x0, 0x0, 0xf, 0x60, 0x0, 0x0, 0x0,
    0x0, 0x9f, 0xff, 0xff, 0xff, 0xff, 0xf8, 0x0,
    0x0, 0xac, 0x44, 0x44, 0x44, 0x44, 0xd8, 0x0,
    0x0, 0xaa, 0x0, 0x6, 0x60, 0x0, 0xb8, 0x0,
    0x0, 0xaa, 0x0, 0xa, 0xa0, 0x0, 0xb8, 0x0,
    0x0, 0xaa, 0x0, 0xa, 0xa0, 0x0, 0xb8, 0x0,
    0x0, 0xaa, 0x0, 0xb, 0x90, 0x0, 0xb8, 0x0,
    0x0, 0xaa, 0x0, 0xe, 0x60, 0x0, 0xb8, 0x0,
    0x0, 0xaa, 0x0, 0x3f, 0x30, 0x0, 0xb8, 0x0,
    0x0, 0x66, 0x0, 0xcb, 0x4, 0x0, 0x65, 0x0,
    0x0, 0x0, 0x1a, 0xf2, 0x4f, 0xe7, 0x10, 0x0,
    0x0, 0x38, 0xfd, 0x30, 0x1, 0x7e, 0xf9, 0x10,
    0x5e, 0xfd, 0x60, 0x0, 0x0, 0x0, 0x6e, 0xf4,
    0x6, 0x20, 0x0, 0x0, 0x0, 0x0, 0x0, 0x70
};


/*---------------------
 *  GLYPH DESCRIPTION
 *--------------------*/

static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc[] = {
    {.bitmap_index = 0, .adv_w = 0, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0, .adv_w = 288, .box_w = 18, .box_h = 3, .ofs_x = 0, .ofs_y = 5},
    {.bitmap_index = 27, .adv_w = 288, .box_w = 17, .box_h = 17, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 172, .adv_w = 288, .box_w = 17, .box_h = 16, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 308, .adv_w = 288, .box_w = 16, .box_h = 16, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 436, .adv_w = 288, .box_w = 18, .box_h = 18, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 598, .adv_w = 288, .box_w = 17, .box_h = 19, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 760, .adv_w = 288, .box_w = 17, .box_h = 18, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 913, .adv_w = 288, .box_w = 16, .box_h = 16, .ofs_x = 1, .ofs_y = -2}
};

/*---------------------
 *  CHARACTER MAPPING
 *--------------------*/

static const uint16_t unicode_list_0[] = {
    0x0, 0xa, 0xb, 0x8de, 0xd9a, 0x2a6e, 0x41d4, 0x4a75
};

/*Collect the unicode lists and glyph_id offsets*/
static const lv_font_fmt_txt_cmap_t cmaps[] =
{
    {
        .range_start = 19968, .range_length = 19062, .glyph_id_start = 1,
        .unicode_list = unicode_list_0, .glyph_id_ofs_list = NULL, .list_length = 8, .type = LV_FONT_FMT_TXT_CMAP_SPARSE_TINY
    }
};



/*--------------------
 *  ALL CUSTOM DATA
 *--------------------*/

#if LVGL_VERSION_MAJOR == 8
/*Store all the custom data of the font*/
static  lv_font_fmt_txt_glyph_cache_t cache;
#endif

#if LVGL_VERSION_MAJOR >= 8
static const lv_font_fmt_txt_dsc_t font_dsc = {
#else
static lv_font_fmt_txt_dsc_t font_dsc = {
#endif
    .glyph_bitmap = glyph_bitmap,
    .glyph_dsc = glyph_dsc,
    .cmaps = cmaps,
    .kern_dsc = NULL,
    .kern_scale = 0,
    .cmap_num = 1,
    .bpp = 4,
    .kern_classes = 0,
    .bitmap_format = 0,
#if LVGL_VERSION_MAJOR == 8
    .cache = &cache
#endif
};


/*-----------------
 *  PUBLIC FONT
 *----------------*/

/*Initialize a public general font descriptor*/
#if LVGL_VERSION_MAJOR >= 8
const lv_font_t alarm_font_18 = {
#else
lv_font_t alarm_font_18 = {
#endif
    .get_glyph_dsc = lv_font_get_glyph_dsc_fmt_txt,    /*Function pointer to get glyph's data*/
    .get_glyph_bitmap = lv_font_get_bitmap_fmt_txt,    /*Function pointer to get glyph's bitmap*/
    .line_height = 19,          /*The maximum line height required by the font*/
    .base_line = 3,             /*Baseline measured from the bottom of the line*/
#if !(LVGL_VERSION_MAJOR == 6 && LVGL_VERSION_MINOR == 0)
    .subpx = LV_FONT_SUBPX_NONE,
#endif
#if LV_VERSION_CHECK(7, 4, 0) || LVGL_VERSION_MAJOR >= 8
    .underline_position = -2,
    .underline_thickness = 1,
#endif
    .dsc = &font_dsc,          /*The custom font data. Will be accessed by `get_glyph_bitmap/dsc` */
    .fallback = NULL,
    .user_data = NULL
};



#endif /*#if ALARM_FONT_18*/

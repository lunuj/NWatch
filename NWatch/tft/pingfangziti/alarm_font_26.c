/*******************************************************************************
 * Size: 26 px
 * Bpp: 4
 * Opts: 
 ******************************************************************************/

#ifdef LV_LVGL_H_INCLUDE_SIMPLE
#include "lvgl.h"
#else
#include "lvgl/lvgl.h"
#endif

#ifndef ALARM_FONT_26
#define ALARM_FONT_26 1
#endif

#if ALARM_FONT_26

/*-----------------
 *    BITMAPS
 *----------------*/

/*Store the image of the glyphs*/
static LV_ATTRIBUTE_LARGE_CONST const uint8_t glyph_bitmap[] = {
    /* U+5012 "倒" */
    0x0, 0x0, 0x56, 0x10, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x5, 0x70, 0x0, 0x0, 0xdf, 0x3d,
    0xdd, 0xdd, 0xdd, 0xdb, 0x0, 0x0, 0xb, 0xf1,
    0x0, 0x2, 0xfc, 0x7, 0x7b, 0xfa, 0x77, 0x76,
    0xe, 0xb0, 0xb, 0xf1, 0x0, 0x8, 0xf5, 0x0,
    0xb, 0xf1, 0x0, 0x0, 0xf, 0xc0, 0xb, 0xf1,
    0x0, 0xd, 0xe0, 0x0, 0x1f, 0xb0, 0x6a, 0x0,
    0xf, 0xc0, 0xb, 0xf1, 0x0, 0x3f, 0xb0, 0x0,
    0x6f, 0x50, 0x9f, 0x30, 0xf, 0xc0, 0xb, 0xf1,
    0x0, 0xbf, 0xb0, 0x0, 0xde, 0x0, 0x1f, 0xb0,
    0xf, 0xc0, 0xb, 0xf1, 0x5, 0xff, 0xb0, 0x4,
    0xf7, 0x0, 0x3c, 0xf2, 0xf, 0xc0, 0xb, 0xf1,
    0xd, 0xff, 0xb0, 0x3d, 0xfc, 0xdf, 0xff, 0xf9,
    0xf, 0xc0, 0xb, 0xf1, 0x7f, 0x7f, 0xb0, 0x4f,
    0xfd, 0xb8, 0x52, 0xbe, 0xf, 0xc0, 0xb, 0xf1,
    0xdc, 0x1f, 0xb0, 0x2, 0x0, 0x24, 0x10, 0x33,
    0xf, 0xc0, 0xb, 0xf1, 0x82, 0x1f, 0xb0, 0x0,
    0x0, 0x9f, 0x30, 0x0, 0xf, 0xc0, 0xb, 0xf1,
    0x0, 0x1f, 0xb0, 0x0, 0x0, 0x9f, 0x30, 0x0,
    0xf, 0xc0, 0xb, 0xf1, 0x0, 0x1f, 0xb0, 0x3,
    0x33, 0xaf, 0x63, 0x32, 0xf, 0xc0, 0xb, 0xf1,
    0x0, 0x1f, 0xb0, 0x1f, 0xff, 0xff, 0xff, 0xfa,
    0xf, 0xc0, 0xb, 0xf1, 0x0, 0x1f, 0xb0, 0x7,
    0x77, 0xcf, 0x97, 0x75, 0xf, 0xc0, 0xb, 0xf1,
    0x0, 0x1f, 0xb0, 0x0, 0x0, 0x9f, 0x30, 0x0,
    0xf, 0xc0, 0xb, 0xf1, 0x0, 0x1f, 0xb0, 0x0,
    0x0, 0x9f, 0x30, 0x0, 0xf, 0xc0, 0xb, 0xf1,
    0x0, 0x1f, 0xb0, 0x0, 0x0, 0x9f, 0x30, 0x0,
    0x2, 0x10, 0xb, 0xf1, 0x0, 0x1f, 0xb0, 0x0,
    0x0, 0x9f, 0x30, 0x38, 0x0, 0x0, 0xb, 0xf1,
    0x0, 0x1f, 0xb0, 0x0, 0x0, 0x9f, 0xbe, 0xff,
    0x0, 0x0, 0xb, 0xf1, 0x0, 0x1f, 0xb0, 0x26,
    0x9d, 0xff, 0xff, 0xe9, 0x0, 0x0, 0xd, 0xf1,
    0x0, 0x1f, 0xb0, 0x9f, 0xff, 0xea, 0x62, 0x0,
    0x3, 0xba, 0xbf, 0xf0, 0x0, 0x1f, 0xb0, 0x37,
    0x41, 0x0, 0x0, 0x0, 0x1, 0xff, 0xfe, 0x50,

    /* U+65F6 "时" */
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x1, 0x54, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x2f, 0xb0, 0x0, 0xdf,
    0xff, 0xff, 0xfb, 0x0, 0x0, 0x0, 0x0, 0x2,
    0xfb, 0x0, 0xd, 0xf6, 0x66, 0x7f, 0xb0, 0x0,
    0x0, 0x0, 0x0, 0x2f, 0xb0, 0x0, 0xdf, 0x0,
    0x1, 0xfb, 0x1a, 0xaa, 0xaa, 0xaa, 0xab, 0xfe,
    0xaa, 0x9d, 0xf0, 0x0, 0x1f, 0xb2, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xfe, 0xdf, 0x0, 0x1,
    0xfb, 0x1, 0x11, 0x11, 0x11, 0x14, 0xfc, 0x11,
    0x1d, 0xf0, 0x0, 0x1f, 0xb0, 0x0, 0x0, 0x0,
    0x0, 0x2f, 0xb0, 0x0, 0xdf, 0x0, 0x1, 0xfb,
    0x0, 0x0, 0x0, 0x0, 0x2, 0xfb, 0x0, 0xd,
    0xfb, 0xbb, 0xbf, 0xb0, 0x1, 0x40, 0x0, 0x0,
    0x2f, 0xb0, 0x0, 0xdf, 0xff, 0xff, 0xfb, 0x0,
    0xef, 0x10, 0x0, 0x2, 0xfb, 0x0, 0xd, 0xf0,
    0x0, 0x1f, 0xb0, 0x7, 0xfb, 0x0, 0x0, 0x2f,
    0xb0, 0x0, 0xdf, 0x0, 0x1, 0xfb, 0x0, 0xd,
    0xf5, 0x0, 0x2, 0xfb, 0x0, 0xd, 0xf0, 0x0,
    0x1f, 0xb0, 0x0, 0x3f, 0xd0, 0x0, 0x2f, 0xb0,
    0x0, 0xdf, 0x0, 0x1, 0xfb, 0x0, 0x0, 0xbf,
    0x60, 0x2, 0xfb, 0x0, 0xd, 0xf0, 0x0, 0x1f,
    0xb0, 0x0, 0x2, 0xfe, 0x0, 0x2f, 0xb0, 0x0,
    0xdf, 0x0, 0x1, 0xfb, 0x0, 0x0, 0x8, 0x30,
    0x2, 0xfb, 0x0, 0xd, 0xfa, 0xaa, 0xbf, 0xb0,
    0x0, 0x0, 0x0, 0x0, 0x2f, 0xb0, 0x0, 0xdf,
    0xff, 0xff, 0xfb, 0x0, 0x0, 0x0, 0x0, 0x2,
    0xfb, 0x0, 0xd, 0xf0, 0x0, 0x1f, 0xb0, 0x0,
    0x0, 0x0, 0x0, 0x2f, 0xb0, 0x0, 0xdf, 0x0,
    0x1, 0xda, 0x0, 0x0, 0x0, 0x0, 0x2, 0xfb,
    0x0, 0x6, 0x70, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x5f, 0xb0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x7c, 0xcb, 0xbf, 0xf8, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x5, 0xff,
    0xff, 0xfb, 0x10, 0x0,

    /* U+79D2 "秒" */
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x15, 0x90, 0x0, 0x0, 0xf, 0xe0, 0x0, 0x0,
    0x0, 0x0, 0x24, 0x79, 0xdf, 0xff, 0x40, 0x0,
    0x0, 0xfe, 0x0, 0x0, 0x0, 0x0, 0x8f, 0xff,
    0xff, 0xc8, 0x40, 0x0, 0x0, 0xf, 0xe0, 0x0,
    0x0, 0x0, 0x4, 0xa8, 0x6e, 0xd0, 0x0, 0x0,
    0x10, 0x0, 0xfe, 0x5, 0xb1, 0x0, 0x0, 0x0,
    0x0, 0xed, 0x0, 0x0, 0xa, 0xf3, 0xf, 0xe0,
    0x5f, 0xa0, 0x0, 0x0, 0x0, 0xe, 0xd0, 0x0,
    0x0, 0xef, 0x0, 0xfe, 0x0, 0xbf, 0x40, 0x0,
    0x23, 0x33, 0xee, 0x33, 0x30, 0x2f, 0xb0, 0xf,
    0xe0, 0x2, 0xfe, 0x0, 0xa, 0xff, 0xff, 0xff,
    0xff, 0x17, 0xf6, 0x0, 0xfe, 0x0, 0x8, 0xf7,
    0x0, 0x69, 0x99, 0xff, 0x99, 0x91, 0xcf, 0x20,
    0xf, 0xe0, 0x0, 0x1f, 0xe0, 0x0, 0x0, 0x6f,
    0xd0, 0x0, 0x3f, 0xd0, 0x0, 0xfe, 0x0, 0x0,
    0x9f, 0x70, 0x0, 0xc, 0xfe, 0x10, 0x9, 0xf6,
    0x0, 0xf, 0xe0, 0x0, 0x1, 0xc5, 0x0, 0x3,
    0xff, 0xfd, 0x11, 0xff, 0x0, 0x0, 0xfe, 0x0,
    0x4, 0x30, 0x0, 0x0, 0xad, 0xee, 0xcd, 0x17,
    0x80, 0x0, 0xf, 0xe0, 0x0, 0xef, 0x10, 0x0,
    0x4f, 0x6e, 0xd1, 0xed, 0x10, 0x0, 0x0, 0xfe,
    0x0, 0x6f, 0xa0, 0x0, 0x1e, 0xe0, 0xed, 0x4,
    0xfb, 0x0, 0x0, 0xa, 0x90, 0xe, 0xf2, 0x0,
    0xa, 0xf6, 0xe, 0xd0, 0x9, 0x60, 0x0, 0x0,
    0x0, 0x9, 0xf9, 0x0, 0x2, 0xfc, 0x0, 0xed,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x8, 0xfe, 0x10,
    0x0, 0xe, 0x30, 0xe, 0xd0, 0x0, 0x0, 0x0,
    0x0, 0x6, 0xff, 0x30, 0x0, 0x0, 0x20, 0x0,
    0xed, 0x0, 0x0, 0x0, 0x0, 0x7, 0xff, 0x40,
    0x0, 0x0, 0x0, 0x0, 0xe, 0xd0, 0x0, 0x0,
    0x0, 0x2c, 0xff, 0x60, 0x0, 0x0, 0x0, 0x0,
    0x0, 0xed, 0x0, 0x0, 0x1, 0x8f, 0xfd, 0x30,
    0x0, 0x0, 0x0, 0x0, 0x0, 0xe, 0xd0, 0x0,
    0x5b, 0xff, 0xf8, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0xed, 0x1, 0xef, 0xff, 0x93, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xe, 0xd0,
    0x8, 0xb5, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0,

    /* U+8868 "表" */
    0x0, 0x0, 0x0, 0x0, 0x0, 0x2, 0x20, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0xf, 0xf0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0xf, 0xf0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x4, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x40,
    0x3, 0xbb, 0xbb, 0xbb, 0xbb, 0xbf, 0xfb, 0xbb,
    0xbb, 0xbb, 0xbb, 0x30, 0x0, 0x0, 0x0, 0x0,
    0x0, 0xf, 0xf0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0xf, 0xf0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x9, 0xcc, 0xcc,
    0xcc, 0xcf, 0xfc, 0xcc, 0xcc, 0xcc, 0x90, 0x0,
    0x0, 0xb, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xb0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0xf, 0xf0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0xf, 0xf0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x2a, 0xaa, 0xaa, 0xaa,
    0xaa, 0xaf, 0xfa, 0xaa, 0xaa, 0xaa, 0xaa, 0xa2,
    0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xf3, 0x0, 0x0, 0x0, 0x0,
    0x6f, 0xb0, 0xce, 0x10, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x5, 0xfd, 0x0, 0x4f, 0x70,
    0x0, 0x0, 0x60, 0x0, 0x0, 0x0, 0x0, 0x9f,
    0xc1, 0x0, 0xc, 0xe1, 0x0, 0xb, 0xf8, 0x0,
    0x0, 0x0, 0x5e, 0xfc, 0x0, 0x0, 0x4, 0xfa,
    0x3, 0xdf, 0xb0, 0x0, 0x0, 0x5d, 0xff, 0xf9,
    0x0, 0x0, 0x0, 0xaf, 0xbf, 0xf7, 0x0, 0x0,
    0x8e, 0xff, 0x95, 0xf9, 0x0, 0x0, 0x0, 0xd,
    0xfb, 0x10, 0x0, 0x0, 0x6f, 0x92, 0x3, 0xf9,
    0x0, 0x0, 0x0, 0x3, 0xff, 0x50, 0x0, 0x0,
    0x1, 0x0, 0x3, 0xf9, 0x0, 0x3, 0x86, 0x0,
    0x4f, 0xf8, 0x0, 0x0, 0x0, 0x0, 0x3, 0xf9,
    0x27, 0xdf, 0xfa, 0x0, 0x3, 0xef, 0xc3, 0x0,
    0x0, 0x0, 0x9, 0xff, 0xff, 0xfb, 0x50, 0x0,
    0x0, 0x1c, 0xff, 0xb2, 0x0, 0x0, 0xd, 0xff,
    0xa6, 0x10, 0x0, 0x0, 0x0, 0x0, 0x5d, 0xf2,
    0x0, 0x0, 0x4, 0x40, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x30,

    /* U+8BA1 "计" */
    0x0, 0x27, 0x0, 0x0, 0x0, 0x0, 0x0, 0x9,
    0xe4, 0x0, 0x0, 0x0, 0x0, 0xcf, 0xb1, 0x0,
    0x0, 0x0, 0x0, 0xa, 0xf4, 0x0, 0x0, 0x0,
    0x0, 0x1b, 0xfd, 0x20, 0x0, 0x0, 0x0, 0xa,
    0xf4, 0x0, 0x0, 0x0, 0x0, 0x0, 0x8f, 0xe2,
    0x0, 0x0, 0x0, 0xa, 0xf4, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x7, 0xf3, 0x0, 0x0, 0x0, 0xa,
    0xf4, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x10,
    0x0, 0x0, 0x0, 0xa, 0xf4, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xa,
    0xf4, 0x0, 0x0, 0x0, 0x67, 0x77, 0x76, 0x0,
    0x7a, 0xaa, 0xaa, 0xae, 0xfc, 0xaa, 0xaa, 0xaa,
    0xdf, 0xff, 0xfc, 0x0, 0xaf, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0x34, 0x44, 0xfc, 0x0,
    0x23, 0x33, 0x33, 0x3b, 0xf7, 0x33, 0x33, 0x33,
    0x0, 0x0, 0xfc, 0x0, 0x0, 0x0, 0x0, 0xa,
    0xf4, 0x0, 0x0, 0x0, 0x0, 0x0, 0xfc, 0x0,
    0x0, 0x0, 0x0, 0xa, 0xf4, 0x0, 0x0, 0x0,
    0x0, 0x0, 0xfc, 0x0, 0x0, 0x0, 0x0, 0xa,
    0xf4, 0x0, 0x0, 0x0, 0x0, 0x0, 0xfc, 0x0,
    0x0, 0x0, 0x0, 0xa, 0xf4, 0x0, 0x0, 0x0,
    0x0, 0x0, 0xfc, 0x0, 0x0, 0x0, 0x0, 0xa,
    0xf4, 0x0, 0x0, 0x0, 0x0, 0x0, 0xfc, 0x0,
    0x0, 0x0, 0x0, 0xa, 0xf4, 0x0, 0x0, 0x0,
    0x0, 0x0, 0xfc, 0x0, 0x10, 0x0, 0x0, 0xa,
    0xf4, 0x0, 0x0, 0x0, 0x0, 0x0, 0xfc, 0x2,
    0xe1, 0x0, 0x0, 0xa, 0xf4, 0x0, 0x0, 0x0,
    0x0, 0x0, 0xfc, 0x3e, 0xf3, 0x0, 0x0, 0xa,
    0xf4, 0x0, 0x0, 0x0, 0x0, 0x0, 0xfe, 0xff,
    0x60, 0x0, 0x0, 0xa, 0xf4, 0x0, 0x0, 0x0,
    0x0, 0x2, 0xff, 0xf5, 0x0, 0x0, 0x0, 0xa,
    0xf4, 0x0, 0x0, 0x0, 0x0, 0x7, 0xfd, 0x30,
    0x0, 0x0, 0x0, 0xa, 0xf4, 0x0, 0x0, 0x0,
    0x0, 0x1, 0xa0, 0x0, 0x0, 0x0, 0x0, 0xa,
    0xf4, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0xa, 0xf4, 0x0, 0x0, 0x0,

    /* U+949F "钟" */
    0x0, 0x6, 0xb3, 0x0, 0x0, 0x0, 0x0, 0x0,
    0xbc, 0x0, 0x0, 0x0, 0x0, 0xc, 0xf1, 0x0,
    0x0, 0x0, 0x0, 0x0, 0xef, 0x0, 0x0, 0x0,
    0x0, 0x2f, 0xd3, 0x33, 0x31, 0x0, 0x0, 0x0,
    0xef, 0x0, 0x0, 0x0, 0x0, 0x7f, 0xff, 0xff,
    0xf8, 0x0, 0x0, 0x0, 0xef, 0x0, 0x0, 0x0,
    0x0, 0xce, 0x55, 0x55, 0x52, 0xb, 0xbb, 0xbb,
    0xff, 0xbb, 0xbb, 0xb0, 0x5, 0xf8, 0x0, 0x0,
    0x0, 0xf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf1,
    0xd, 0xf1, 0x0, 0x0, 0x0, 0xf, 0xc0, 0x0,
    0xff, 0x0, 0xb, 0xf1, 0x5f, 0xa0, 0x0, 0x0,
    0x0, 0xf, 0xc0, 0x0, 0xef, 0x0, 0xb, 0xf1,
    0x8f, 0x5f, 0xff, 0xff, 0xf2, 0xf, 0xc0, 0x0,
    0xef, 0x0, 0xb, 0xf1, 0x2, 0x2a, 0xdf, 0xca,
    0xa1, 0xf, 0xc0, 0x0, 0xef, 0x0, 0xb, 0xf1,
    0x0, 0x0, 0x8f, 0x50, 0x0, 0xf, 0xc0, 0x0,
    0xef, 0x0, 0xb, 0xf1, 0x0, 0x0, 0x8f, 0x50,
    0x0, 0xf, 0xc0, 0x0, 0xef, 0x0, 0xb, 0xf1,
    0x1, 0x11, 0x9f, 0x61, 0x11, 0xf, 0xc0, 0x0,
    0xef, 0x0, 0xb, 0xf1, 0x1f, 0xff, 0xff, 0xff,
    0xfe, 0xf, 0xfc, 0xcc, 0xff, 0xcc, 0xcf, 0xf1,
    0x9, 0x99, 0xcf, 0xb9, 0x98, 0xf, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xf1, 0x0, 0x0, 0x8f, 0x50,
    0x0, 0xf, 0xc0, 0x0, 0xef, 0x0, 0xb, 0xf1,
    0x0, 0x0, 0x8f, 0x50, 0x0, 0x0, 0x0, 0x0,
    0xef, 0x0, 0x0, 0x0, 0x0, 0x0, 0x8f, 0x50,
    0x0, 0x0, 0x0, 0x0, 0xef, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x8f, 0x50, 0x0, 0x0, 0x0, 0x0,
    0xef, 0x0, 0x0, 0x0, 0x0, 0x0, 0x8f, 0x50,
    0x3a, 0x40, 0x0, 0x0, 0xef, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x8f, 0x8b, 0xff, 0x60, 0x0, 0x0,
    0xef, 0x0, 0x0, 0x0, 0x0, 0x2, 0xef, 0xff,
    0xb4, 0x0, 0x0, 0x0, 0xef, 0x0, 0x0, 0x0,
    0x0, 0x0, 0xdd, 0x83, 0x0, 0x0, 0x0, 0x0,
    0xef, 0x0, 0x0, 0x0, 0x0, 0x0, 0x10, 0x0,
    0x0, 0x0, 0x0, 0x0, 0xef, 0x0, 0x0, 0x0,

    /* U+95F9 "闹" */
    0x0, 0x2, 0x20, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x4f, 0xc0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xb,
    0xf8, 0x0, 0xd, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xf1, 0x0, 0x1, 0xef, 0x20, 0x9, 0xbb, 0xbb,
    0xbb, 0xbb, 0xbe, 0xf1, 0x0, 0x0, 0x6f, 0xa0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0xb, 0xf1, 0x58,
    0x10, 0xd, 0xe1, 0x2, 0x40, 0x0, 0x0, 0x0,
    0xb, 0xf1, 0xaf, 0x20, 0x2, 0x0, 0x1f, 0xe0,
    0x0, 0x0, 0x0, 0xb, 0xf1, 0xaf, 0x20, 0x0,
    0x0, 0x9, 0xf4, 0x0, 0x0, 0x0, 0xb, 0xf1,
    0xaf, 0x20, 0x9a, 0xaa, 0xab, 0xfd, 0xaa, 0xaa,
    0xa5, 0xb, 0xf1, 0xaf, 0x20, 0xef, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xf8, 0xb, 0xf1, 0xaf, 0x20,
    0x0, 0x0, 0x4, 0xf8, 0x0, 0x0, 0x0, 0xb,
    0xf1, 0xaf, 0x20, 0x0, 0x0, 0x4, 0xf8, 0x0,
    0x0, 0x0, 0xb, 0xf1, 0xaf, 0x20, 0x1, 0x11,
    0x15, 0xf9, 0x11, 0x11, 0x0, 0xb, 0xf1, 0xaf,
    0x20, 0xf, 0xff, 0xff, 0xff, 0xff, 0xff, 0x80,
    0xb, 0xf1, 0xaf, 0x20, 0xf, 0xd9, 0x9b, 0xfc,
    0x99, 0xaf, 0x80, 0xb, 0xf1, 0xaf, 0x20, 0xf,
    0x90, 0x4, 0xf8, 0x0, 0x2f, 0x80, 0xb, 0xf1,
    0xaf, 0x20, 0xf, 0x90, 0x4, 0xf8, 0x0, 0x2f,
    0x80, 0xb, 0xf1, 0xaf, 0x20, 0xf, 0x90, 0x4,
    0xf8, 0x0, 0x2f, 0x80, 0xb, 0xf1, 0xaf, 0x20,
    0xf, 0x90, 0x4, 0xf8, 0x0, 0x4f, 0x80, 0xb,
    0xf1, 0xaf, 0x20, 0xf, 0x90, 0x4, 0xf8, 0x7d,
    0xff, 0x50, 0xb, 0xf1, 0xaf, 0x20, 0xe, 0x80,
    0x4, 0xf8, 0x3b, 0xb7, 0x0, 0xb, 0xf1, 0xaf,
    0x20, 0x0, 0x0, 0x4, 0xf8, 0x0, 0x0, 0x0,
    0xc, 0xf1, 0xaf, 0x20, 0x0, 0x0, 0x4, 0xf8,
    0x0, 0x0, 0x0, 0xe, 0xf0, 0xaf, 0x20, 0x0,
    0x0, 0x1, 0x73, 0x0, 0x0, 0x6b, 0xdf, 0xd0,
    0xaf, 0x20, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x5f, 0xfd, 0x30
};


/*---------------------
 *  GLYPH DESCRIPTION
 *--------------------*/

static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc[] = {
    {.bitmap_index = 0, .adv_w = 0, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0, .adv_w = 416, .box_w = 24, .box_h = 24, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 288, .adv_w = 416, .box_w = 23, .box_h = 24, .ofs_x = 2, .ofs_y = -3},
    {.bitmap_index = 564, .adv_w = 416, .box_w = 25, .box_h = 26, .ofs_x = 0, .ofs_y = -4},
    {.bitmap_index = 889, .adv_w = 416, .box_w = 24, .box_h = 25, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 1189, .adv_w = 416, .box_w = 24, .box_h = 24, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 1477, .adv_w = 416, .box_w = 24, .box_h = 24, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 1765, .adv_w = 416, .box_w = 22, .box_h = 25, .ofs_x = 2, .ofs_y = -3}
};

/*---------------------
 *  CHARACTER MAPPING
 *--------------------*/

static const uint16_t unicode_list_0[] = {
    0x0, 0x15e4, 0x29c0, 0x3856, 0x3b8f, 0x448d, 0x45e7
};

/*Collect the unicode lists and glyph_id offsets*/
static const lv_font_fmt_txt_cmap_t cmaps[] =
{
    {
        .range_start = 20498, .range_length = 17896, .glyph_id_start = 1,
        .unicode_list = unicode_list_0, .glyph_id_ofs_list = NULL, .list_length = 7, .type = LV_FONT_FMT_TXT_CMAP_SPARSE_TINY
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
const lv_font_t alarm_font_26 = {
#else
lv_font_t alarm_font_26 = {
#endif
    .get_glyph_dsc = lv_font_get_glyph_dsc_fmt_txt,    /*Function pointer to get glyph's data*/
    .get_glyph_bitmap = lv_font_get_bitmap_fmt_txt,    /*Function pointer to get glyph's bitmap*/
    .line_height = 26,          /*The maximum line height required by the font*/
    .base_line = 4,             /*Baseline measured from the bottom of the line*/
#if !(LVGL_VERSION_MAJOR == 6 && LVGL_VERSION_MINOR == 0)
    .subpx = LV_FONT_SUBPX_NONE,
#endif
#if LV_VERSION_CHECK(7, 4, 0) || LVGL_VERSION_MAJOR >= 8
    .underline_position = -3,
    .underline_thickness = 2,
#endif
    .dsc = &font_dsc,          /*The custom font data. Will be accessed by `get_glyph_bitmap/dsc` */
    .fallback = NULL,
    .user_data = NULL
};



#endif /*#if ALARM_FONT_26*/


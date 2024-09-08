/*******************************************************************************
 * Size: 38 px
 * Bpp: 4
 * Opts: 
 ******************************************************************************/

#ifdef LV_LVGL_H_INCLUDE_SIMPLE
#include "lvgl.h"
#else
#include "lvgl/lvgl.h"
#endif

#ifndef WEATHER_FONT
#define WEATHER_FONT 1
#endif

#if WEATHER_FONT

/*-----------------
 *    BITMAPS
 *----------------*/

/*Store the image of the glyphs*/
static LV_ATTRIBUTE_LARGE_CONST const uint8_t glyph_bitmap[] = {
    /* U+4E91 "云" */
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x26,
    0x0, 0x0, 0x0, 0x3, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0x0, 0x0, 0x0, 0x0, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0x40, 0x0, 0x0, 0x0,
    0xcf, 0xcb, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa,
    0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0xaa, 0x40, 0x0,
    0x0, 0x0, 0x10, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x13, 0x70,
    0x6f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xf3, 0x2f, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xf7, 0xf, 0xda, 0x99, 0x99,
    0x99, 0x99, 0x9d, 0xfb, 0x99, 0x99, 0x99, 0x99,
    0x99, 0x99, 0x99, 0x99, 0x99, 0x95, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x1e, 0xff, 0x50, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x9f, 0xff,
    0x60, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x3,
    0xff, 0xf6, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0xd, 0xff, 0xa0, 0x0, 0x0, 0x0, 0x4,
    0x40, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x9f, 0xfd, 0x0, 0x0, 0x0,
    0x0, 0x8f, 0xf2, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x4, 0xff, 0xf3, 0x0,
    0x0, 0x0, 0x2, 0xff, 0xfd, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1e, 0xff,
    0x70, 0x0, 0x0, 0x0, 0x0, 0x5f, 0xff, 0xb0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0xcf, 0xfb, 0x0, 0x0, 0x0, 0x0, 0x0, 0x9,
    0xff, 0xf7, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x8, 0xff, 0xe1, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0xcf, 0xff, 0x40, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x5f, 0xff, 0x30, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x1e, 0xff, 0xf2, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x2, 0xef, 0xf7, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x3, 0xff,
    0xfd, 0x0, 0x0, 0x0, 0x0, 0x0, 0x2e, 0xff,
    0xb0, 0x0, 0x0, 0x0, 0x1, 0x22, 0x34, 0x56,
    0x77, 0xdf, 0xff, 0x90, 0x0, 0x0, 0x0, 0x6,
    0xff, 0xff, 0xba, 0xbc, 0xdd, 0xef, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xf5, 0x0, 0x0,
    0x0, 0x8, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0x20, 0x0, 0x0, 0x1, 0xff, 0xff, 0xff, 0xff,
    0xed, 0xcb, 0xa9, 0x87, 0x76, 0x54, 0x32, 0x10,
    0x4f, 0xff, 0xd0, 0x0, 0x0, 0x0, 0x8a, 0x53,
    0x10, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x8, 0xff, 0xf7, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0xdf, 0x70, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x33,
    0x0, 0x0,

    /* U+65E0 "无" */
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x77, 0x77, 0x77, 0x77,
    0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77,
    0x78, 0xad, 0x0, 0x0, 0x0, 0x0, 0xdf, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0x20, 0x0, 0x0, 0x0,
    0xaf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x60, 0x0,
    0x0, 0x0, 0x45, 0x21, 0x0, 0x0, 0x0, 0x0,
    0xff, 0xd0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0xff, 0xc0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x1, 0xff, 0xb0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x2, 0xff, 0xb0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x3,
    0xff, 0x90, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x5, 0xff, 0x70, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x7, 0xff, 0x50, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x9, 0xff, 0x30,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xc,
    0xff, 0x20, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x25, 0x70, 0xd, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xf0, 0x9, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xf3, 0x6, 0xfb,
    0xa9, 0x99, 0x99, 0x99, 0x99, 0xcf, 0xfc, 0x99,
    0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x99, 0x93,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xaf,
    0xf4, 0xa, 0x85, 0x10, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0xef, 0xf0, 0xe, 0xff, 0x10, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x4, 0xff, 0xb0, 0xe, 0xfe, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0xa, 0xff, 0x50, 0xe,
    0xfe, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1f, 0xff,
    0x0, 0xe, 0xfe, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0xaf, 0xf9, 0x0, 0xe, 0xfe, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x3, 0xff, 0xf1, 0x0, 0xe, 0xfe, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0xd, 0xff, 0x70, 0x0, 0xe,
    0xfe, 0x0, 0x0, 0x0, 0x0, 0x0, 0x4, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0xaf, 0xfd, 0x0,
    0x0, 0xe, 0xfe, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x2f, 0xa3, 0x0, 0x0, 0x0, 0x0, 0x8, 0xff,
    0xf3, 0x0, 0x0, 0xe, 0xfe, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x4f, 0xfa, 0x0, 0x0, 0x0, 0x0,
    0x9f, 0xff, 0x70, 0x0, 0x0, 0xe, 0xfe, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x7f, 0xf7, 0x0, 0x0,
    0x0, 0xa, 0xff, 0xf8, 0x0, 0x0, 0x0, 0xe,
    0xfe, 0x0, 0x0, 0x0, 0x0, 0x0, 0xaf, 0xf4,
    0x0, 0x0, 0x2, 0xdf, 0xff, 0x90, 0x0, 0x0,
    0x0, 0xe, 0xfe, 0x0, 0x0, 0x0, 0x0, 0x0,
    0xdf, 0xf1, 0x0, 0x0, 0x8f, 0xff, 0xf8, 0x0,
    0x0, 0x0, 0x0, 0xd, 0xff, 0x50, 0x0, 0x0,
    0x0, 0x18, 0xff, 0xd0, 0x0, 0x6e, 0xff, 0xff,
    0x50, 0x0, 0x0, 0x0, 0x0, 0xa, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0x70, 0x2d, 0xff,
    0xff, 0xc2, 0x0, 0x0, 0x0, 0x0, 0x0, 0x2,
    0xef, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfa, 0x0,
    0xb, 0xff, 0xf8, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x7, 0xac, 0xcc, 0xcc, 0xcc, 0xb9,
    0x40, 0x0, 0x0, 0xdb, 0x20, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0,

    /* U+6674 "晴" */
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x30, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0xef, 0xb0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xef,
    0xc0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0xef, 0xa0, 0x0, 0x0, 0x1, 0x35, 0x0,
    0xb, 0x97, 0x77, 0x77, 0x9c, 0x20, 0xf, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xfe, 0x0, 0xf, 0xff, 0xff, 0xff, 0xff, 0xf2,
    0xc, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0x10, 0xf, 0xff, 0xff, 0xff,
    0xff, 0xd0, 0x6, 0x63, 0x22, 0x22, 0x22, 0xef,
    0xb2, 0x22, 0x22, 0x22, 0x22, 0x0, 0xf, 0xf8,
    0x0, 0x0, 0xef, 0xa0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0xef, 0x90, 0x0, 0x0, 0x0, 0x0, 0x0,
    0xf, 0xf8, 0x0, 0x0, 0xef, 0x90, 0x0, 0x0,
    0x0, 0x0, 0x0, 0xef, 0xa0, 0x0, 0x0, 0x13,
    0x60, 0x0, 0xf, 0xf8, 0x0, 0x0, 0xef, 0x90,
    0x0, 0xef, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xf0, 0x0, 0xf, 0xf8, 0x0, 0x0,
    0xef, 0x90, 0x0, 0xbf, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xf3, 0x0, 0xf, 0xf8,
    0x0, 0x0, 0xef, 0x90, 0x0, 0x46, 0x32, 0x22,
    0x22, 0xef, 0xb2, 0x22, 0x22, 0x22, 0x20, 0x0,
    0xf, 0xf8, 0x0, 0x0, 0xef, 0x90, 0x0, 0x0,
    0x0, 0x0, 0x0, 0xef, 0x90, 0x0, 0x0, 0x0,
    0x0, 0x0, 0xf, 0xf8, 0x0, 0x0, 0xef, 0x90,
    0x23, 0x33, 0x33, 0x33, 0x33, 0xff, 0xb3, 0x33,
    0x33, 0x33, 0x47, 0x50, 0xf, 0xf8, 0x0, 0x0,
    0xef, 0x90, 0x9f, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xa0, 0xf, 0xf8,
    0x11, 0x11, 0xef, 0x90, 0x5f, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe0,
    0xf, 0xff, 0xff, 0xff, 0xff, 0x90, 0x14, 0x10,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0xf, 0xff, 0xff, 0xff, 0xff, 0x90,
    0x0, 0x21, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x35, 0x0, 0x0, 0xf, 0xfa, 0x44, 0x44,
    0xff, 0x90, 0x0, 0x9f, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xa0, 0x0, 0xf, 0xf8,
    0x0, 0x0, 0xef, 0x90, 0x0, 0x9f, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x0,
    0xf, 0xf8, 0x0, 0x0, 0xef, 0x90, 0x0, 0x9f,
    0xf3, 0x33, 0x33, 0x33, 0x33, 0x33, 0x34, 0xff,
    0x80, 0x0, 0xf, 0xf8, 0x0, 0x0, 0xef, 0x90,
    0x0, 0x9f, 0xe0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x1, 0xff, 0x70, 0x0, 0xf, 0xf8, 0x0, 0x0,
    0xef, 0x90, 0x0, 0x9f, 0xe0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x1, 0xff, 0x70, 0x0, 0xf, 0xf8,
    0x0, 0x0, 0xef, 0x90, 0x0, 0x9f, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x70, 0x0,
    0xf, 0xf8, 0x0, 0x0, 0xef, 0x90, 0x0, 0x9f,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0x70, 0x0, 0xf, 0xf8, 0x0, 0x0, 0xef, 0x90,
    0x0, 0x9f, 0xe1, 0x11, 0x11, 0x11, 0x11, 0x11,
    0x12, 0xff, 0x70, 0x0, 0xf, 0xf8, 0x0, 0x0,
    0xef, 0x90, 0x0, 0x9f, 0xe0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x1, 0xff, 0x70, 0x0, 0xf, 0xfd,
    0xbb, 0xbb, 0xff, 0x90, 0x0, 0x9f, 0xe1, 0x11,
    0x11, 0x11, 0x11, 0x11, 0x12, 0xff, 0x70, 0x0,
    0xf, 0xff, 0xff, 0xff, 0xff, 0x90, 0x0, 0x9f,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0x70, 0x0, 0xf, 0xfe, 0xcc, 0xcc, 0xff, 0x90,
    0x0, 0x9f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0x70, 0x0, 0xf, 0xf8, 0x0, 0x0,
    0xef, 0x90, 0x0, 0x9f, 0xe0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x1, 0xff, 0x70, 0x0, 0xf, 0xf8,
    0x0, 0x0, 0x34, 0x20, 0x0, 0x9f, 0xe0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x1, 0xff, 0x70, 0x0,
    0x8, 0x84, 0x0, 0x0, 0x0, 0x0, 0x0, 0x9f,
    0xe0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x4, 0xff,
    0x60, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x9f, 0xe0, 0x0, 0x0, 0xc, 0xda, 0x97,
    0x8e, 0xff, 0x40, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x9f, 0xe0, 0x0, 0x0, 0x8,
    0xff, 0xff, 0xff, 0xfd, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x9f, 0xe0, 0x0,
    0x0, 0x5, 0xff, 0xff, 0xfd, 0x91, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0,

    /* U+9634 "阴" */
    0x44, 0x20, 0x0, 0x0, 0x5, 0x70, 0x0, 0x21,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x7, 0x10,
    0xbf, 0xff, 0xff, 0xff, 0xff, 0xfa, 0x0, 0xaf,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe4,
    0xbf, 0xff, 0xff, 0xff, 0xff, 0xff, 0x30, 0xaf,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf7,
    0xbf, 0xf3, 0x33, 0x33, 0xef, 0xf7, 0x0, 0xaf,
    0xf7, 0x66, 0x66, 0x66, 0x66, 0x66, 0xcf, 0xf2,
    0xbf, 0xf0, 0x0, 0x2, 0xff, 0xe0, 0x0, 0xaf,
    0xf0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x9f, 0xf1,
    0xbf, 0xf0, 0x0, 0x7, 0xff, 0x90, 0x0, 0xaf,
    0xf0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x9f, 0xf1,
    0xbf, 0xf0, 0x0, 0xb, 0xff, 0x30, 0x0, 0xaf,
    0xf0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x9f, 0xf1,
    0xbf, 0xf0, 0x0, 0x1f, 0xfe, 0x0, 0x0, 0xaf,
    0xf0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x9f, 0xf1,
    0xbf, 0xf0, 0x0, 0x5f, 0xf9, 0x0, 0x0, 0xaf,
    0xf0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x9f, 0xf1,
    0xbf, 0xf0, 0x0, 0xaf, 0xf3, 0x0, 0x0, 0xaf,
    0xf0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x9f, 0xf1,
    0xbf, 0xf0, 0x0, 0xef, 0xe0, 0x0, 0x0, 0xaf,
    0xf7, 0x66, 0x66, 0x66, 0x66, 0x66, 0xcf, 0xf1,
    0xbf, 0xf0, 0x4, 0xff, 0x80, 0x0, 0x0, 0xaf,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf1,
    0xbf, 0xf0, 0x8, 0xff, 0x30, 0x0, 0x0, 0xaf,
    0xfe, 0xee, 0xee, 0xee, 0xee, 0xee, 0xff, 0xf1,
    0xbf, 0xf0, 0xd, 0xff, 0x0, 0x0, 0x0, 0xaf,
    0xf0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x9f, 0xf1,
    0xbf, 0xf0, 0x7, 0xff, 0x80, 0x0, 0x0, 0xaf,
    0xf0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x9f, 0xf1,
    0xbf, 0xf0, 0x0, 0xcf, 0xf3, 0x0, 0x0, 0xaf,
    0xf0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x9f, 0xf1,
    0xbf, 0xf0, 0x0, 0x3f, 0xfb, 0x0, 0x0, 0xaf,
    0xf0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x9f, 0xf1,
    0xbf, 0xf0, 0x0, 0xa, 0xff, 0x30, 0x0, 0xaf,
    0xf0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x9f, 0xf1,
    0xbf, 0xf0, 0x0, 0x3, 0xff, 0xa0, 0x0, 0xbf,
    0xf0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x9f, 0xf1,
    0xbf, 0xf0, 0x0, 0x0, 0xdf, 0xf0, 0x0, 0xcf,
    0xf6, 0x66, 0x66, 0x66, 0x66, 0x66, 0xcf, 0xf1,
    0xbf, 0xf0, 0x0, 0x0, 0x9f, 0xf3, 0x0, 0xdf,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf1,
    0xbf, 0xf0, 0x0, 0x0, 0x7f, 0xf5, 0x0, 0xef,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf1,
    0xbf, 0xf0, 0x0, 0x0, 0x6f, 0xf6, 0x0, 0xff,
    0xa0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x9f, 0xf1,
    0xbf, 0xf0, 0x0, 0x0, 0x7f, 0xf5, 0x3, 0xff,
    0x70, 0x0, 0x0, 0x0, 0x0, 0x0, 0x9f, 0xf1,
    0xbf, 0xf1, 0x21, 0x14, 0xef, 0xf2, 0x7, 0xff,
    0x40, 0x0, 0x0, 0x0, 0x0, 0x0, 0x9f, 0xf1,
    0xbf, 0xf4, 0xff, 0xff, 0xff, 0xd0, 0xc, 0xff,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x9f, 0xf1,
    0xbf, 0xf0, 0xff, 0xff, 0xff, 0x30, 0x2f, 0xfb,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x9f, 0xf1,
    0xbf, 0xf0, 0xce, 0xec, 0x92, 0x0, 0x8f, 0xf5,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x9f, 0xf1,
    0xbf, 0xf0, 0x0, 0x0, 0x0, 0x1, 0xff, 0xf0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x9f, 0xf1,
    0xbf, 0xf0, 0x0, 0x0, 0x0, 0x9, 0xff, 0x70,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x9f, 0xf1,
    0xbf, 0xf0, 0x0, 0x0, 0x0, 0x5f, 0xfe, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xcf, 0xf0,
    0xbf, 0xf0, 0x0, 0x0, 0x2, 0xff, 0xf5, 0x0,
    0x0, 0x0, 0x4, 0xed, 0xcc, 0xce, 0xff, 0xd0,
    0xbf, 0xf0, 0x0, 0x0, 0xa, 0xff, 0x90, 0x0,
    0x0, 0x0, 0x0, 0xef, 0xff, 0xff, 0xff, 0x50,
    0xbf, 0xf0, 0x0, 0x0, 0x0, 0x9c, 0x0, 0x0,
    0x0, 0x0, 0x0, 0xae, 0xfe, 0xdc, 0x93, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,

    /* U+96E8 "雨" */
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x2, 0x50, 0x2f, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xf0, 0xf, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xf3, 0xb, 0xda,
    0x98, 0x88, 0x88, 0x88, 0x88, 0x88, 0xaf, 0xfd,
    0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x83,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x2f, 0xfb, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x2f, 0xfb, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x2f, 0xfb, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x2f, 0xfb,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x3, 0x0, 0x0,
    0x0, 0xa, 0xb9, 0x98, 0x88, 0x88, 0x88, 0x88,
    0xaf, 0xfd, 0x88, 0x88, 0x88, 0x88, 0x88, 0x9f,
    0xb0, 0x0, 0x0, 0xc, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xfb, 0x0, 0x0, 0xc, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xf5, 0x0, 0x0, 0xc,
    0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x2f, 0xfb,
    0x0, 0x0, 0x0, 0x0, 0x0, 0xcf, 0xf2, 0x0,
    0x0, 0xc, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x2f, 0xfb, 0x0, 0x0, 0x0, 0x0, 0x0, 0xcf,
    0xf1, 0x0, 0x0, 0xc, 0xff, 0x0, 0x1, 0x0,
    0x0, 0x0, 0x2f, 0xfb, 0x0, 0x1, 0x0, 0x0,
    0x0, 0xcf, 0xf1, 0x0, 0x0, 0xc, 0xff, 0x0,
    0x5f, 0x70, 0x0, 0x0, 0x2f, 0xfb, 0x0, 0x8f,
    0x50, 0x0, 0x0, 0xcf, 0xf1, 0x0, 0x0, 0xc,
    0xff, 0x1, 0xff, 0xfc, 0x20, 0x0, 0x2f, 0xfb,
    0x3, 0xff, 0xfa, 0x0, 0x0, 0xcf, 0xf1, 0x0,
    0x0, 0xc, 0xff, 0x0, 0x4e, 0xff, 0xf5, 0x0,
    0x2f, 0xfb, 0x0, 0x4e, 0xff, 0xe3, 0x0, 0xcf,
    0xf1, 0x0, 0x0, 0xc, 0xff, 0x0, 0x1, 0xcf,
    0xff, 0x80, 0x2f, 0xfb, 0x0, 0x1, 0xbf, 0xff,
    0x80, 0xcf, 0xf1, 0x0, 0x0, 0xc, 0xff, 0x0,
    0x0, 0x9, 0xff, 0xd1, 0x2f, 0xfb, 0x0, 0x0,
    0x7, 0xff, 0xe1, 0xcf, 0xf1, 0x0, 0x0, 0xc,
    0xff, 0x0, 0x0, 0x0, 0x5e, 0x20, 0x2f, 0xfb,
    0x0, 0x0, 0x0, 0x4e, 0x20, 0xcf, 0xf1, 0x0,
    0x0, 0xc, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x2f, 0xfb, 0x0, 0x0, 0x0, 0x0, 0x0, 0xcf,
    0xf1, 0x0, 0x0, 0xc, 0xff, 0x0, 0x10, 0x0,
    0x0, 0x0, 0x2f, 0xfb, 0x0, 0x20, 0x0, 0x0,
    0x0, 0xcf, 0xf1, 0x0, 0x0, 0xc, 0xff, 0x1,
    0xdd, 0x20, 0x0, 0x0, 0x2f, 0xfb, 0x2, 0xec,
    0x20, 0x0, 0x0, 0xcf, 0xf1, 0x0, 0x0, 0xc,
    0xff, 0x8, 0xff, 0xf6, 0x0, 0x0, 0x2f, 0xfb,
    0xa, 0xff, 0xf6, 0x0, 0x0, 0xcf, 0xf1, 0x0,
    0x0, 0xc, 0xff, 0x0, 0x7f, 0xff, 0xb1, 0x0,
    0x2f, 0xfb, 0x0, 0x9f, 0xff, 0xa1, 0x0, 0xcf,
    0xf1, 0x0, 0x0, 0xc, 0xff, 0x0, 0x3, 0xef,
    0xfe, 0x40, 0x2f, 0xfb, 0x0, 0x5, 0xff, 0xfe,
    0x30, 0xcf, 0xf1, 0x0, 0x0, 0xc, 0xff, 0x0,
    0x0, 0x1c, 0xff, 0xb0, 0x2f, 0xfb, 0x0, 0x0,
    0x2d, 0xff, 0x80, 0xcf, 0xf1, 0x0, 0x0, 0xc,
    0xff, 0x0, 0x0, 0x0, 0x9d, 0x0, 0x2f, 0xfb,
    0x0, 0x0, 0x0, 0xab, 0x0, 0xcf, 0xf1, 0x0,
    0x0, 0xc, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x2f, 0xfb, 0x0, 0x0, 0x0, 0x0, 0x0, 0xcf,
    0xf1, 0x0, 0x0, 0xc, 0xff, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x2f, 0xfb, 0x0, 0x0, 0x0, 0x0,
    0x0, 0xcf, 0xf1, 0x0, 0x0, 0xc, 0xff, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x2f, 0xfb, 0x0, 0x0,
    0x0, 0x0, 0x2, 0xff, 0xf0, 0x0, 0x0, 0xc,
    0xff, 0x0, 0x0, 0x0, 0x0, 0x0, 0x2f, 0xfb,
    0x0, 0x3, 0xff, 0xed, 0xdf, 0xff, 0xc0, 0x0,
    0x0, 0xc, 0xff, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x19, 0x96, 0x0, 0x0, 0xef, 0xff, 0xff, 0xff,
    0x40, 0x0, 0x0, 0xc, 0xff, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xae, 0xdd,
    0xcc, 0xa3, 0x0, 0x0,

    /* U+96EA "雪" */
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x13, 0x50,
    0x0, 0x0, 0x2, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0x0, 0x0, 0x0, 0xf, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xf3, 0x0, 0x0, 0x0, 0x75, 0x32,
    0x22, 0x22, 0x22, 0x22, 0x3f, 0xf8, 0x22, 0x22,
    0x22, 0x22, 0x22, 0x22, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x1, 0xff, 0x70,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0xa6, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x6f,
    0xfa, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0xab,
    0x10, 0xf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xfd, 0x0, 0xff, 0xfe, 0xee, 0xee, 0xee,
    0xee, 0xee, 0xef, 0xff, 0xee, 0xee, 0xee, 0xee,
    0xee, 0xee, 0xff, 0x90, 0xf, 0xf8, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x1, 0xff, 0x70, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x2f, 0xf6, 0x0, 0xff, 0x80,
    0x0, 0x0, 0x0, 0x2, 0x20, 0x1f, 0xf7, 0x0,
    0x0, 0x0, 0x0, 0x21, 0x2, 0xff, 0x50, 0xf,
    0xf8, 0x3, 0xff, 0xff, 0xff, 0xf9, 0x1, 0xff,
    0x70, 0x7f, 0xff, 0xff, 0xff, 0x50, 0x2f, 0xf5,
    0x0, 0xff, 0x80, 0xf, 0xff, 0xff, 0xff, 0xc0,
    0x1f, 0xf7, 0x4, 0xff, 0xff, 0xff, 0xf9, 0x2,
    0xff, 0x50, 0xf, 0xf8, 0x0, 0x74, 0x21, 0x11,
    0x11, 0x1, 0xff, 0x70, 0x18, 0x32, 0x11, 0x11,
    0x10, 0x2f, 0xf5, 0x0, 0x99, 0x40, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x1f, 0xf7, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x1, 0x99, 0x30, 0x0, 0x0, 0x3,
    0xcc, 0xcc, 0xcd, 0xf8, 0x1, 0xff, 0x70, 0x6c,
    0xcc, 0xcc, 0xef, 0x40, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x1f, 0xff, 0xff, 0xff, 0xc0, 0x1f, 0xf7,
    0x4, 0xff, 0xff, 0xff, 0xf8, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0xa7, 0x43, 0x33, 0x33, 0x1,
    0xee, 0x60, 0x1b, 0x64, 0x33, 0x33, 0x20, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x49, 0x0, 0x0, 0x0, 0x0, 0xef, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xfd, 0x30, 0x0, 0x0, 0xa,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xf2, 0x0, 0x0,
    0x0, 0x69, 0x65, 0x55, 0x55, 0x55, 0x55, 0x55,
    0x55, 0x55, 0x55, 0x55, 0x55, 0x5f, 0xfd, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xef,
    0xc0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0xe, 0xfb, 0x0, 0x0, 0x0, 0x0, 0x46, 0x66,
    0x66, 0x66, 0x66, 0x66, 0x66, 0x66, 0x66, 0x66,
    0x66, 0x66, 0xff, 0xb0, 0x0, 0x0, 0x0, 0x9,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xfb, 0x0, 0x0, 0x0,
    0x0, 0x5f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xb0, 0x0,
    0x0, 0x0, 0x1, 0x51, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xe, 0xfb,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0xef, 0xb0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0xe, 0xfb, 0x0, 0x0, 0x0, 0x5f, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xb0, 0x0, 0x0, 0x2,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xfb, 0x0, 0x0,
    0x0, 0xb, 0x97, 0x66, 0x66, 0x66, 0x66, 0x66,
    0x66, 0x66, 0x66, 0x66, 0x66, 0x66, 0xff, 0xb0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xe,
    0xfb, 0x0, 0x0,

    /* U+96F7 "雷" */
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x13, 0x60,
    0x0, 0x0, 0x2, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0x10, 0x0, 0x0, 0xf, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xf5, 0x0, 0x0, 0x0, 0x75, 0x32,
    0x22, 0x22, 0x22, 0x22, 0x3f, 0xf8, 0x22, 0x22,
    0x22, 0x22, 0x22, 0x22, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x1, 0xff, 0x70,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0xa6, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x6f,
    0xfa, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x9c,
    0x10, 0xf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xfe, 0x10, 0xff, 0xfe, 0xee, 0xee, 0xee,
    0xee, 0xee, 0xef, 0xff, 0xee, 0xee, 0xee, 0xee,
    0xee, 0xee, 0xff, 0xb0, 0xf, 0xf8, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x1, 0xff, 0x70, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x1f, 0xf7, 0x0, 0xff, 0x80,
    0x2, 0x22, 0x22, 0x35, 0x30, 0x1f, 0xf7, 0x1,
    0x22, 0x22, 0x23, 0x52, 0x1, 0xff, 0x70, 0xf,
    0xf8, 0x3, 0xff, 0xff, 0xff, 0xfa, 0x1, 0xff,
    0x70, 0x6f, 0xff, 0xff, 0xff, 0x70, 0x1f, 0xf7,
    0x0, 0xff, 0x80, 0xf, 0xff, 0xee, 0xee, 0xc0,
    0x1f, 0xf7, 0x3, 0xff, 0xee, 0xee, 0xea, 0x1,
    0xff, 0x70, 0xf, 0xf8, 0x0, 0x41, 0x0, 0x0,
    0x0, 0x1, 0xff, 0x70, 0x4, 0x0, 0x0, 0x0,
    0x0, 0x1f, 0xf7, 0x0, 0x99, 0x40, 0x0, 0x0,
    0x0, 0x13, 0x10, 0x1f, 0xf7, 0x0, 0x0, 0x0,
    0x1, 0x31, 0x0, 0x99, 0x40, 0x0, 0x0, 0x3,
    0xff, 0xff, 0xff, 0xf9, 0x1, 0xff, 0x70, 0x6f,
    0xff, 0xff, 0xff, 0x70, 0x0, 0x0, 0x0, 0x0,
    0x0, 0xf, 0xff, 0xff, 0xff, 0xc0, 0x1f, 0xf7,
    0x3, 0xff, 0xff, 0xff, 0xfa, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x42, 0x10, 0x0, 0x0, 0x0,
    0x11, 0x0, 0x5, 0x21, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x11, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x2,
    0x40, 0x0, 0x0, 0x0, 0x7, 0xff, 0xee, 0xee,
    0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee,
    0xee, 0xff, 0x90, 0x0, 0x0, 0x0, 0x7f, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xfd, 0x0, 0x0, 0x0, 0x7,
    0xff, 0x76, 0x66, 0x66, 0x66, 0x68, 0xff, 0x86,
    0x66, 0x66, 0x66, 0x67, 0xff, 0x90, 0x0, 0x0,
    0x0, 0x7f, 0xf1, 0x0, 0x0, 0x0, 0x0, 0x4f,
    0xf4, 0x0, 0x0, 0x0, 0x0, 0x1f, 0xf8, 0x0,
    0x0, 0x0, 0x7, 0xff, 0x10, 0x0, 0x0, 0x0,
    0x4, 0xff, 0x40, 0x0, 0x0, 0x0, 0x1, 0xff,
    0x80, 0x0, 0x0, 0x0, 0x7f, 0xf1, 0x0, 0x0,
    0x0, 0x0, 0x4f, 0xf4, 0x0, 0x0, 0x0, 0x0,
    0x1f, 0xf8, 0x0, 0x0, 0x0, 0x7, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0x80, 0x0, 0x0, 0x0, 0x7f,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xf8, 0x0, 0x0, 0x0,
    0x7, 0xff, 0x65, 0x55, 0x55, 0x55, 0x58, 0xff,
    0x85, 0x55, 0x55, 0x55, 0x56, 0xff, 0x80, 0x0,
    0x0, 0x0, 0x7f, 0xf1, 0x0, 0x0, 0x0, 0x0,
    0x4f, 0xf4, 0x0, 0x0, 0x0, 0x0, 0x1f, 0xf8,
    0x0, 0x0, 0x0, 0x7, 0xff, 0x10, 0x0, 0x0,
    0x0, 0x4, 0xff, 0x40, 0x0, 0x0, 0x0, 0x1,
    0xff, 0x80, 0x0, 0x0, 0x0, 0x7f, 0xf1, 0x0,
    0x0, 0x0, 0x0, 0x4f, 0xf4, 0x0, 0x0, 0x0,
    0x0, 0x1f, 0xf8, 0x0, 0x0, 0x0, 0x7, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0x80, 0x0, 0x0, 0x0,
    0x7f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xf8, 0x0, 0x0,
    0x0, 0x7, 0xff, 0x65, 0x55, 0x55, 0x55, 0x55,
    0x55, 0x55, 0x55, 0x55, 0x55, 0x56, 0xff, 0x80,
    0x0, 0x0, 0x0, 0x7f, 0xf1, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1f,
    0xf8, 0x0, 0x0,

    /* U+96FE "雾" */
    0x0, 0x0, 0x12, 0x22, 0x22, 0x22, 0x22, 0x22,
    0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x23, 0x54,
    0x0, 0x0, 0x0, 0x0, 0x4, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xb0, 0x0, 0x0, 0x0, 0x0, 0x1f,
    0xfe, 0xee, 0xee, 0xee, 0xee, 0xef, 0xff, 0xee,
    0xee, 0xee, 0xee, 0xee, 0xec, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x30, 0x0, 0x0, 0x0, 0x0, 0x1,
    0xff, 0x70, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x64, 0x22, 0x22, 0x22, 0x22,
    0x22, 0x22, 0x3f, 0xf8, 0x22, 0x22, 0x22, 0x22,
    0x22, 0x22, 0x57, 0x0, 0x0, 0xf, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x0, 0x0,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xb0, 0x0, 0xf, 0xf8, 0x0, 0x0, 0x0, 0x0,
    0x1, 0x1, 0xff, 0x70, 0x0, 0x0, 0x0, 0x0,
    0x10, 0x1f, 0xf7, 0x0, 0x0, 0xff, 0x80, 0x9d,
    0xdd, 0xdd, 0xef, 0xe0, 0x1f, 0xf7, 0xa, 0xdd,
    0xdd, 0xde, 0xfe, 0x1, 0xff, 0x70, 0x0, 0xf,
    0xf8, 0x8, 0xff, 0xff, 0xff, 0xff, 0x21, 0xff,
    0x70, 0x8f, 0xff, 0xff, 0xff, 0xf2, 0x1f, 0xf7,
    0x0, 0x0, 0xff, 0x80, 0x24, 0x10, 0x0, 0x0,
    0x0, 0x1f, 0xf7, 0x2, 0x41, 0x0, 0x0, 0x0,
    0x1, 0xff, 0x70, 0x0, 0x8, 0x84, 0x1, 0x11,
    0x11, 0x11, 0x48, 0x1, 0xff, 0x70, 0x11, 0x11,
    0x11, 0x14, 0x70, 0x8, 0x83, 0x0, 0x0, 0x0,
    0x0, 0xaf, 0xff, 0xff, 0xff, 0xf0, 0x1f, 0xf7,
    0xa, 0xff, 0xff, 0xff, 0xff, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x7, 0xfd, 0xcc, 0xdc, 0xcc,
    0x21, 0xff, 0x70, 0x7f, 0xdc, 0xcc, 0xcc, 0xc2,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x6f, 0xd7, 0x0, 0x9, 0x94, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x1, 0xaf, 0xfd, 0x50, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x17, 0x60, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x6, 0xef, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xa0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x5d, 0xff, 0xff,
    0xed, 0xdd, 0xdd, 0xdd, 0xdd, 0xdd, 0xdd, 0xff,
    0xff, 0xe8, 0x10, 0x0, 0x0, 0x0, 0x6, 0xdf,
    0xfe, 0x8e, 0xff, 0xa3, 0x0, 0x0, 0x0, 0x0,
    0x4, 0xbf, 0xfe, 0x70, 0x0, 0x0, 0x0, 0x0,
    0xe, 0xff, 0xe6, 0x0, 0x6, 0xef, 0xfc, 0x72,
    0x0, 0x3, 0x8d, 0xff, 0xe7, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x4e, 0x70, 0x0, 0x0, 0x0,
    0x4a, 0xff, 0xfe, 0xbe, 0xff, 0xfa, 0x40, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x1, 0x47, 0x9d, 0xff, 0xff, 0xff, 0xfe,
    0xca, 0x97, 0x53, 0x21, 0x0, 0x0, 0x0, 0x0,
    0x12, 0x46, 0x79, 0xce, 0xff, 0xff, 0xfe, 0xa6,
    0x47, 0xbe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xea, 0x3, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xb8,
    0x42, 0x74, 0x10, 0x0, 0x2, 0x47, 0xac, 0xef,
    0xff, 0xff, 0xff, 0x40, 0xb, 0xff, 0xda, 0x85,
    0x30, 0x0, 0x0, 0x3f, 0xf9, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x1, 0x34, 0x67, 0x80, 0x0, 0x12,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x5, 0xff, 0x60,
    0x0, 0x0, 0x0, 0x0, 0x1, 0x80, 0x0, 0x0,
    0x0, 0x0, 0x0, 0xe, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xd2, 0x0, 0x0, 0x0, 0x0, 0x0, 0xaf, 0xed,
    0xdd, 0xdd, 0xdf, 0xff, 0xdd, 0xdd, 0xdd, 0xdd,
    0xdd, 0xdf, 0xfe, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x1, 0x0, 0x0, 0x0, 0x8, 0xff, 0x40, 0x0,
    0x0, 0x0, 0x0, 0x0, 0xff, 0x90, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x19, 0xff,
    0xa0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xf, 0xf7,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x3,
    0x8f, 0xff, 0xa0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x4, 0xff, 0x50, 0x0, 0x0, 0x0, 0x0, 0x1,
    0x46, 0xae, 0xff, 0xff, 0x60, 0x0, 0x6, 0x65,
    0x44, 0x45, 0x57, 0xef, 0xf1, 0x0, 0x0, 0x0,
    0x0, 0xbe, 0xff, 0xff, 0xff, 0xd7, 0x0, 0x0,
    0x0, 0x9f, 0xff, 0xff, 0xff, 0xff, 0xfa, 0x0,
    0x0, 0x0, 0x0, 0x7, 0xff, 0xff, 0xb8, 0x30,
    0x0, 0x0, 0x0, 0x5, 0xff, 0xff, 0xff, 0xed,
    0xc7, 0x0, 0x0, 0x0, 0x0, 0x0, 0xa, 0x63,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x2, 0x11,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0
};


/*---------------------
 *  GLYPH DESCRIPTION
 *--------------------*/

static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc[] = {
    {.bitmap_index = 0, .adv_w = 0, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0, .adv_w = 608, .box_w = 36, .box_h = 33, .ofs_x = 1, .ofs_y = -4},
    {.bitmap_index = 594, .adv_w = 608, .box_w = 36, .box_h = 35, .ofs_x = 1, .ofs_y = -5},
    {.bitmap_index = 1224, .adv_w = 608, .box_w = 36, .box_h = 37, .ofs_x = 2, .ofs_y = -5},
    {.bitmap_index = 1890, .adv_w = 608, .box_w = 32, .box_h = 35, .ofs_x = 3, .ofs_y = -5},
    {.bitmap_index = 2450, .adv_w = 608, .box_w = 36, .box_h = 34, .ofs_x = 1, .ofs_y = -4},
    {.bitmap_index = 3062, .adv_w = 608, .box_w = 35, .box_h = 34, .ofs_x = 2, .ofs_y = -4},
    {.bitmap_index = 3657, .adv_w = 608, .box_w = 35, .box_h = 34, .ofs_x = 2, .ofs_y = -4},
    {.bitmap_index = 4252, .adv_w = 608, .box_w = 37, .box_h = 35, .ofs_x = 1, .ofs_y = -5}
};

/*---------------------
 *  CHARACTER MAPPING
 *--------------------*/

static const uint16_t unicode_list_0[] = {
    0x0, 0x174f, 0x17e3, 0x47a3, 0x4857, 0x4859, 0x4866, 0x486d
};

/*Collect the unicode lists and glyph_id offsets*/
static const lv_font_fmt_txt_cmap_t cmaps[] =
{
    {
        .range_start = 20113, .range_length = 18542, .glyph_id_start = 1,
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
const lv_font_t weather_font = {
#else
lv_font_t weather_font = {
#endif
    .get_glyph_dsc = lv_font_get_glyph_dsc_fmt_txt,    /*Function pointer to get glyph's data*/
    .get_glyph_bitmap = lv_font_get_bitmap_fmt_txt,    /*Function pointer to get glyph's bitmap*/
    .line_height = 37,          /*The maximum line height required by the font*/
    .base_line = 5,             /*Baseline measured from the bottom of the line*/
#if !(LVGL_VERSION_MAJOR == 6 && LVGL_VERSION_MINOR == 0)
    .subpx = LV_FONT_SUBPX_NONE,
#endif
#if LV_VERSION_CHECK(7, 4, 0) || LVGL_VERSION_MAJOR >= 8
    .underline_position = -10,
    .underline_thickness = 2,
#endif
    .dsc = &font_dsc,          /*The custom font data. Will be accessed by `get_glyph_bitmap/dsc` */
    .fallback = NULL,
    .user_data = NULL
};



#endif /*#if WEATHER_FONT*/


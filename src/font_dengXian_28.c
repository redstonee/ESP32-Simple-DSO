/*******************************************************************************
 * Size: 28 px
 * Bpp: 2
 * Opts: 
 ******************************************************************************/

#ifdef LV_LVGL_H_INCLUDE_SIMPLE
#include "lvgl.h"
#else
#include "lvgl/lvgl.h"
#endif

#ifndef DENGXIAN
#define DENGXIAN 1
#endif

#if DENGXIAN

/*-----------------
 *    BITMAPS
 *----------------*/

/*Store the image of the glyphs*/
static LV_ATTRIBUTE_LARGE_CONST const uint8_t glyph_bitmap[] = {
    /* U+3002 "。" */
    0x6, 0x90, 0x28, 0x28, 0x30, 0xc, 0x50, 0x5,
    0x20, 0x8, 0x24, 0x1c, 0xb, 0xe0,

    /* U+4ED6 "他" */
    0x0, 0x2, 0x80, 0x0, 0x38, 0x0, 0x0, 0x0,
    0x3, 0xe0, 0x0, 0x38, 0x0, 0x0, 0x0, 0x7,
    0xc1, 0x40, 0x38, 0x0, 0x0, 0x0, 0xb, 0x42,
    0xc0, 0x38, 0x0, 0x0, 0x0, 0xf, 0x2, 0xc0,
    0x38, 0x0, 0x0, 0x0, 0x1d, 0x2, 0xc0, 0x38,
    0x0, 0x0, 0x0, 0x3c, 0x2, 0xc0, 0x38, 0x0,
    0x0, 0x0, 0x78, 0x2, 0xc0, 0x38, 0x1b, 0xc0,
    0x0, 0xf8, 0x2, 0xc0, 0x3f, 0xff, 0x80, 0x2,
    0xf8, 0x2, 0xdb, 0xfe, 0x43, 0x80, 0xb, 0xb8,
    0x6b, 0xfe, 0x78, 0x3, 0x80, 0x1f, 0x3a, 0xff,
    0xc0, 0x38, 0x3, 0x80, 0x2d, 0x38, 0x42, 0xc0,
    0x38, 0x3, 0x80, 0x0, 0x38, 0x2, 0xc0, 0x38,
    0x3, 0x80, 0x0, 0x38, 0x2, 0xc0, 0x38, 0x3,
    0x80, 0x0, 0x38, 0x2, 0xc0, 0x38, 0x3, 0x80,
    0x0, 0x38, 0x2, 0xc0, 0x38, 0x5b, 0x80, 0x0,
    0x38, 0x2, 0xc0, 0x38, 0xbf, 0x0, 0x0, 0x38,
    0x2, 0xc0, 0x38, 0x79, 0x0, 0x0, 0x38, 0x2,
    0xc0, 0x38, 0x0, 0x0, 0x0, 0x38, 0x2, 0xc0,
    0x38, 0x0, 0x20, 0x0, 0x38, 0x2, 0xc0, 0x0,
    0x0, 0x3c, 0x0, 0x38, 0x2, 0xc0, 0x0, 0x0,
    0xb8, 0x0, 0x38, 0x1, 0xfa, 0xaa, 0xab, 0xf0,
    0x0, 0x38, 0x0, 0xbf, 0xff, 0xff, 0x80, 0x0,
    0x38, 0x0, 0x0, 0x0, 0x0, 0x0,

    /* U+4F60 "你" */
    0x0, 0x1, 0x0, 0x1e, 0x0, 0x0, 0x0, 0x0,
    0x2f, 0x0, 0xbc, 0x0, 0x0, 0x0, 0x0, 0xf4,
    0x3, 0xd0, 0x0, 0x0, 0x0, 0x3, 0xc0, 0xf,
    0x0, 0x0, 0x0, 0x0, 0x2d, 0x0, 0x78, 0x0,
    0x0, 0x0, 0x0, 0xf0, 0x3, 0xe5, 0x55, 0x56,
    0x40, 0x7, 0x80, 0xf, 0xff, 0xff, 0xfe, 0x0,
    0x3e, 0x0, 0xf0, 0x0, 0x0, 0xb0, 0x2, 0xf8,
    0x7, 0x80, 0x0, 0x3, 0xc0, 0xf, 0xe0, 0x3c,
    0x0, 0xa0, 0x2e, 0x0, 0xf7, 0x83, 0xd0, 0x3,
    0xc0, 0xf0, 0xf, 0xce, 0x1f, 0x0, 0xe, 0x0,
    0x0, 0x8, 0x38, 0x0, 0x0, 0x38, 0x0, 0x0,
    0x0, 0xe0, 0x0, 0x0, 0xe0, 0x0, 0x0, 0x3,
    0x80, 0x7, 0x83, 0x83, 0x40, 0x0, 0xe, 0x0,
    0x2e, 0xe, 0x1f, 0x0, 0x0, 0x38, 0x0, 0xf0,
    0x38, 0x2f, 0x0, 0x0, 0xe0, 0xb, 0x40, 0xe0,
    0x3e, 0x0, 0x3, 0x80, 0x3c, 0x3, 0x80, 0x3c,
    0x0, 0xe, 0x3, 0xd0, 0xe, 0x0, 0xbc, 0x0,
    0x38, 0x2e, 0x0, 0x38, 0x0, 0xf8, 0x0, 0xe2,
    0xf0, 0x0, 0xe0, 0x0, 0xc0, 0x3, 0x82, 0x40,
    0x3, 0x80, 0x0, 0x0, 0xe, 0x0, 0x0, 0xe,
    0x0, 0x0, 0x0, 0x38, 0x0, 0x1f, 0xf4, 0x0,
    0x0, 0x0, 0xf0, 0x0, 0x3f, 0x80, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,

    /* U+50BB "傻" */
    0x0, 0x1, 0x0, 0x2, 0x40, 0x0, 0x0, 0x0,
    0x3, 0xd0, 0x3, 0xd0, 0x0, 0x0, 0x0, 0x7,
    0xc0, 0x7, 0x40, 0x0, 0x0, 0x0, 0xf, 0x45,
    0x5f, 0x55, 0x55, 0x40, 0x0, 0x1e, 0xb, 0xff,
    0xff, 0xff, 0x80, 0x0, 0x3c, 0xb, 0x8, 0x3,
    0xd3, 0x40, 0x0, 0x7c, 0xb, 0xf, 0x8f, 0x43,
    0x40, 0x0, 0xfc, 0xb, 0x1, 0xfc, 0x3, 0x40,
    0x2, 0xfc, 0xb, 0x1, 0xff, 0x3, 0x40, 0xb,
    0xec, 0xb, 0x1f, 0x87, 0xc3, 0x40, 0x2f, 0x2c,
    0xb, 0x8, 0x0, 0x43, 0x40, 0x1d, 0x2c, 0xb,
    0xff, 0xff, 0xff, 0x80, 0x0, 0x2c, 0x5, 0xb5,
    0x56, 0xf5, 0x40, 0x0, 0x2c, 0x0, 0xf1, 0x81,
    0xfd, 0x0, 0x0, 0x2c, 0x7, 0xd3, 0xe0, 0x1f,
    0xc0, 0x0, 0x2c, 0x7f, 0xb, 0xd5, 0x5a, 0xf0,
    0x0, 0x2c, 0xf4, 0x1f, 0xff, 0xf8, 0x10, 0x0,
    0x2c, 0x0, 0x7c, 0x0, 0xb0, 0x0, 0x0, 0x2c,
    0x1, 0xf1, 0x41, 0xd0, 0x0, 0x0, 0x2c, 0xb,
    0xc3, 0xc3, 0xc0, 0x0, 0x0, 0x2c, 0x3e, 0x0,
    0xff, 0x0, 0x0, 0x0, 0x2c, 0x18, 0x0, 0x7e,
    0x0, 0x0, 0x0, 0x2c, 0x0, 0x2, 0xfb, 0xe0,
    0x0, 0x0, 0x2c, 0x0, 0x6f, 0x40, 0xbf, 0xe8,
    0x0, 0x2c, 0x3f, 0xf4, 0x0, 0x7, 0xf8, 0x0,
    0x3c, 0x1e, 0x0, 0x0, 0x0, 0x10,

    /* U+5988 "妈" */
    0x0, 0x4, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x3d, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0xe0,
    0xb, 0xff, 0xff, 0xf0, 0x0, 0x7, 0x40, 0x15,
    0x55, 0x57, 0xc0, 0x0, 0x1c, 0x0, 0x0, 0x0,
    0xe, 0x0, 0x0, 0xb0, 0x0, 0x1e, 0x0, 0x38,
    0x1, 0x57, 0xea, 0xa0, 0x74, 0x0, 0xe0, 0xf,
    0xff, 0xff, 0x81, 0xd0, 0x3, 0x40, 0x0, 0x74,
    0xe, 0x7, 0x0, 0xd, 0x0, 0x1, 0xc0, 0x34,
    0x1c, 0x0, 0x34, 0x0, 0xb, 0x1, 0xc0, 0xb0,
    0x0, 0xd0, 0x0, 0x38, 0xb, 0x2, 0xc0, 0x7,
    0x40, 0x0, 0xd0, 0x3c, 0xb, 0x0, 0x1d, 0x0,
    0x7, 0x0, 0xe0, 0x3f, 0xff, 0xff, 0xc0, 0x2c,
    0x7, 0x40, 0x95, 0x55, 0x5f, 0x0, 0xe0, 0x2c,
    0x0, 0x0, 0x0, 0x3c, 0x3, 0xe0, 0xe0, 0x0,
    0x0, 0x0, 0xf0, 0x2, 0xfb, 0x41, 0x0, 0x0,
    0x43, 0xc0, 0x1, 0xfc, 0x1f, 0xff, 0xff, 0xe,
    0x0, 0x3, 0xf4, 0x10, 0x0, 0x4, 0x38, 0x0,
    0x3d, 0xf8, 0x0, 0x0, 0x0, 0xe0, 0x7, 0xd0,
    0xbc, 0x0, 0x0, 0x3, 0x80, 0xbd, 0x0, 0x90,
    0x0, 0x0, 0x2d, 0xb, 0xc0, 0x0, 0x0, 0x0,
    0x3f, 0xf0, 0x4, 0x0, 0x0, 0x0, 0x0, 0xfe,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,

    /* U+5C44 "屄" */
    0x0, 0x15, 0x55, 0x55, 0x55, 0x55, 0x0, 0x3,
    0xff, 0xff, 0xff, 0xff, 0xf0, 0x0, 0x38, 0x0,
    0x0, 0x0, 0xb, 0x0, 0x3, 0x80, 0x0, 0x0,
    0x0, 0xb0, 0x0, 0x38, 0x0, 0x0, 0x0, 0xb,
    0x0, 0x3, 0x80, 0x0, 0x0, 0x0, 0xb0, 0x0,
    0x3f, 0xff, 0xff, 0xff, 0xff, 0x0, 0x3, 0x95,
    0x55, 0x95, 0x55, 0x60, 0x0, 0x38, 0x0, 0xf,
    0x0, 0x0, 0x0, 0x3, 0x80, 0x0, 0x3c, 0x0,
    0x0, 0x0, 0x38, 0x0, 0x0, 0xc0, 0x0, 0x0,
    0x3, 0x4f, 0xff, 0xff, 0xff, 0xf4, 0x0, 0x34,
    0xb5, 0x55, 0x55, 0x57, 0x40, 0x3, 0x4b, 0x0,
    0x0, 0x0, 0x34, 0x0, 0x74, 0xf0, 0x24, 0x1c,
    0x3, 0x40, 0x7, 0x0, 0x7, 0x42, 0xc0, 0x0,
    0x0, 0xb0, 0x0, 0xb0, 0x1d, 0x0, 0x0, 0xf,
    0x0, 0xe, 0x0, 0xe0, 0x0, 0x0, 0xe0, 0x1,
    0xd0, 0xb, 0x0, 0x0, 0x1d, 0x0, 0x3c, 0x0,
    0x38, 0x0, 0x3, 0xc0, 0x7, 0x40, 0x2, 0xd0,
    0x0, 0x78, 0x1, 0xe0, 0x0, 0xf, 0x0, 0xf,
    0x0, 0x7c, 0x0, 0x0, 0x3d, 0x2, 0xe0, 0x2f,
    0x0, 0x0, 0x0, 0xf8, 0x4, 0x7, 0x80, 0x0,
    0x0, 0x3, 0xd0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0,

    /* U+6211 "我" */
    0x0, 0x0, 0x0, 0xa, 0x40, 0x0, 0x0, 0x0,
    0x0, 0x10, 0xb8, 0x0, 0x0, 0x0, 0x0, 0x6f,
    0x4b, 0x4e, 0x0, 0x0, 0xff, 0xff, 0x94, 0xb0,
    0xbc, 0x0, 0xb, 0xeb, 0x80, 0x7, 0x41, 0xf0,
    0x0, 0x0, 0x38, 0x0, 0x74, 0x7, 0xc0, 0x0,
    0x3, 0x80, 0x7, 0x40, 0x18, 0x0, 0x0, 0x38,
    0x0, 0x74, 0x0, 0x0, 0x65, 0x57, 0xd5, 0x5b,
    0x95, 0x55, 0x8b, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xfc, 0x0, 0x3, 0x80, 0x3, 0x80, 0x0, 0x0,
    0x0, 0x38, 0x0, 0x38, 0x6, 0x0, 0x0, 0x3,
    0x80, 0x3, 0xc0, 0xbc, 0x0, 0x0, 0x38, 0x8,
    0x2c, 0xf, 0x0, 0x0, 0x3, 0x9b, 0xc1, 0xc1,
    0xd0, 0x0, 0x0, 0x3f, 0xe0, 0xd, 0x3c, 0x0,
    0x0, 0x7f, 0xd0, 0x0, 0xe7, 0x40, 0x2, 0xff,
    0x78, 0x0, 0xb, 0xe0, 0x0, 0x3e, 0x3, 0x80,
    0x0, 0x7c, 0x0, 0x0, 0x0, 0x38, 0x0, 0xb,
    0xc0, 0x0, 0x0, 0x3, 0x80, 0x2, 0xfd, 0x0,
    0x0, 0x0, 0x38, 0x0, 0xb8, 0xf0, 0x8, 0x0,
    0x3, 0x80, 0x3d, 0x7, 0x80, 0xe0, 0x0, 0x38,
    0x2f, 0x40, 0x2e, 0x2d, 0x1, 0xff, 0x4b, 0xc0,
    0x0, 0xbf, 0xc0, 0x1f, 0xd0, 0x10, 0x0, 0x1,
    0xf0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,

    /* U+662F "是" */
    0x0, 0x15, 0x55, 0x55, 0x55, 0x40, 0x0, 0x2,
    0xff, 0xff, 0xff, 0xf8, 0x0, 0x0, 0x2c, 0x0,
    0x0, 0x3, 0x80, 0x0, 0x2, 0xc0, 0x0, 0x0,
    0x38, 0x0, 0x0, 0x2d, 0x55, 0x55, 0x57, 0x80,
    0x0, 0x2, 0xff, 0xff, 0xff, 0xf8, 0x0, 0x0,
    0x2c, 0x0, 0x0, 0x3, 0x80, 0x0, 0x2, 0xc0,
    0x0, 0x0, 0x38, 0x0, 0x0, 0x2d, 0x55, 0x55,
    0x57, 0x80, 0x0, 0x3, 0xff, 0xff, 0xff, 0xfc,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x7f, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xd6, 0x55, 0x55, 0x5f,
    0x55, 0x55, 0x58, 0x0, 0x0, 0x0, 0xb0, 0x0,
    0x0, 0x0, 0x0, 0x80, 0xb, 0x0, 0x0, 0x0,
    0x0, 0x2e, 0x0, 0xb0, 0x0, 0x10, 0x0, 0x3,
    0xc0, 0xb, 0xff, 0xff, 0x0, 0x0, 0x7c, 0x0,
    0xb0, 0x0, 0x50, 0x0, 0xf, 0xf0, 0xb, 0x0,
    0x0, 0x0, 0x1, 0xe3, 0xd0, 0xb0, 0x0, 0x0,
    0x0, 0x3c, 0xf, 0xdb, 0x0, 0x0, 0x0, 0xf,
    0x40, 0x1f, 0xff, 0xaa, 0xff, 0xe3, 0xe0, 0x0,
    0x1b, 0xff, 0xff, 0xfc, 0x1c, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0,

    /* U+7684 "的" */
    0x0, 0x64, 0x0, 0x2, 0x80, 0x0, 0x0, 0xb8,
    0x0, 0x3, 0xc0, 0x0, 0x0, 0xf0, 0x0, 0x7,
    0x40, 0x0, 0x0, 0xe0, 0x0, 0xb, 0x0, 0x0,
    0x1, 0xd0, 0x0, 0xe, 0x0, 0x0, 0x2, 0xc0,
    0x0, 0x1d, 0x0, 0x0, 0x3f, 0xff, 0xf0, 0x3f,
    0xff, 0xfc, 0x3e, 0xaa, 0xf0, 0xb9, 0x55, 0x7c,
    0x38, 0x0, 0x70, 0xf0, 0x0, 0x2c, 0x38, 0x0,
    0x73, 0xd0, 0x0, 0x2c, 0x38, 0x0, 0x72, 0xc0,
    0x0, 0x2c, 0x38, 0x0, 0x70, 0x0, 0x0, 0x2c,
    0x38, 0x0, 0x70, 0x9, 0x0, 0x2c, 0x38, 0x0,
    0x70, 0xf, 0x0, 0x2c, 0x3f, 0xff, 0xf0, 0x7,
    0xc0, 0x2c, 0x39, 0x55, 0xb0, 0x1, 0xf0, 0x2c,
    0x38, 0x0, 0x70, 0x0, 0xb8, 0x2c, 0x38, 0x0,
    0x70, 0x0, 0x3c, 0x2c, 0x38, 0x0, 0x70, 0x0,
    0x0, 0x2c, 0x38, 0x0, 0x70, 0x0, 0x0, 0x2c,
    0x38, 0x0, 0x70, 0x0, 0x0, 0x3c, 0x39, 0x55,
    0xb0, 0x0, 0x0, 0x3c, 0x3f, 0xff, 0xf0, 0x0,
    0x0, 0x3c, 0x38, 0x0, 0xb0, 0x0, 0x0, 0x74,
    0x38, 0x0, 0x60, 0x0, 0x7f, 0xe0, 0x0, 0x0,
    0x0, 0x0, 0x29, 0x0,

    /* U+808F "肏" */
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x3, 0x40, 0x0, 0x0, 0x0, 0x0, 0x0, 0x7f,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x7c, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x2, 0xf0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x3f, 0xd0, 0x0, 0x0, 0x0,
    0x0, 0x1f, 0xf, 0x80, 0x0, 0x0, 0x0, 0xb,
    0xc0, 0x2f, 0x80, 0x0, 0x0, 0x1b, 0xe0, 0x0,
    0x2f, 0xe4, 0x1, 0xbf, 0xe0, 0xf, 0x40, 0x2f,
    0xfc, 0x3f, 0x90, 0x0, 0xf0, 0x0, 0x1b, 0x41,
    0x40, 0x0, 0xe, 0x0, 0x0, 0x0, 0x2, 0xff,
    0xff, 0xff, 0xff, 0xfc, 0x0, 0x2d, 0x55, 0x7f,
    0x55, 0x56, 0xc0, 0x2, 0xc0, 0x3, 0xfd, 0x0,
    0x2c, 0x0, 0x2c, 0x0, 0xf0, 0xbd, 0x2, 0xc0,
    0x2, 0xc0, 0xbc, 0x0, 0xf8, 0x2c, 0x0, 0x2c,
    0x2f, 0xb, 0x42, 0x82, 0xc0, 0x2, 0xc0, 0x40,
    0xf0, 0x0, 0x2c, 0x0, 0x2c, 0x0, 0x3f, 0x40,
    0x2, 0xc0, 0x2, 0xc0, 0xf, 0x7f, 0x40, 0x2c,
    0x0, 0x2c, 0x7, 0xc0, 0x7f, 0x42, 0xc0, 0x2,
    0xc1, 0xf0, 0x0, 0x70, 0x2c, 0x0, 0x2c, 0x0,
    0x0, 0x0, 0x2, 0xc0, 0x2, 0xc0, 0x0, 0x0,
    0xf, 0xfc, 0x0, 0x2c, 0x0, 0x0, 0x0, 0xfe,
    0x40, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,

    /* U+FF01 "！" */
    0x0, 0x38, 0x38, 0x38, 0x38, 0x38, 0x38, 0x38,
    0x38, 0x38, 0x38, 0x38, 0x34, 0x34, 0x34, 0x34,
    0x0, 0x0, 0x0, 0x0, 0x7c, 0x7c, 0x10,

    /* U+FF0C "，" */
    0x10, 0xf3, 0xc6, 0x28, 0xc0,

    /* U+FF1F "？" */
    0x1, 0x64, 0x0, 0xbf, 0xfe, 0xb, 0x40, 0x2e,
    0x10, 0x0, 0x3c, 0x0, 0x0, 0x74, 0x0, 0x1,
    0xd0, 0x0, 0x7, 0x0, 0x0, 0x38, 0x0, 0x2,
    0xc0, 0x0, 0x2c, 0x0, 0x2, 0xc0, 0x0, 0x1c,
    0x0, 0x0, 0xd0, 0x0, 0x3, 0x0, 0x0, 0xc,
    0x0, 0x0, 0x34, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1,
    0xf0, 0x0, 0x7, 0xc0, 0x0, 0x4, 0x0, 0x0
};


/*---------------------
 *  GLYPH DESCRIPTION
 *--------------------*/

static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc[] = {
    {.bitmap_index = 0, .adv_w = 0, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0, .adv_w = 448, .box_w = 8, .box_h = 7, .ofs_x = 3, .ofs_y = -3},
    {.bitmap_index = 14, .adv_w = 448, .box_w = 28, .box_h = 26, .ofs_x = 0, .ofs_y = -4},
    {.bitmap_index = 196, .adv_w = 448, .box_w = 27, .box_h = 27, .ofs_x = 0, .ofs_y = -5},
    {.bitmap_index = 379, .adv_w = 448, .box_w = 28, .box_h = 26, .ofs_x = 0, .ofs_y = -4},
    {.bitmap_index = 561, .adv_w = 448, .box_w = 27, .box_h = 26, .ofs_x = 0, .ofs_y = -4},
    {.bitmap_index = 737, .adv_w = 448, .box_w = 26, .box_h = 26, .ofs_x = 0, .ofs_y = -5},
    {.bitmap_index = 906, .adv_w = 448, .box_w = 26, .box_h = 27, .ofs_x = 1, .ofs_y = -5},
    {.bitmap_index = 1082, .adv_w = 448, .box_w = 26, .box_h = 26, .ofs_x = 1, .ofs_y = -5},
    {.bitmap_index = 1251, .adv_w = 448, .box_w = 24, .box_h = 26, .ofs_x = 2, .ofs_y = -4},
    {.bitmap_index = 1407, .adv_w = 448, .box_w = 26, .box_h = 27, .ofs_x = 1, .ofs_y = -4},
    {.bitmap_index = 1583, .adv_w = 448, .box_w = 4, .box_h = 23, .ofs_x = 4, .ofs_y = -1},
    {.bitmap_index = 1606, .adv_w = 448, .box_w = 3, .box_h = 6, .ofs_x = 3, .ofs_y = -4},
    {.bitmap_index = 1611, .adv_w = 448, .box_w = 11, .box_h = 23, .ofs_x = 2, .ofs_y = -1}
};

/*---------------------
 *  CHARACTER MAPPING
 *--------------------*/

static const uint16_t unicode_list_0[] = {
    0x0, 0x1ed4, 0x1f5e, 0x20b9, 0x2986, 0x2c42, 0x320f, 0x362d,
    0x4682, 0x508d, 0xceff, 0xcf0a, 0xcf1d
};

/*Collect the unicode lists and glyph_id offsets*/
static const lv_font_fmt_txt_cmap_t cmaps[] =
{
    {
        .range_start = 12290, .range_length = 53022, .glyph_id_start = 1,
        .unicode_list = unicode_list_0, .glyph_id_ofs_list = NULL, .list_length = 13, .type = LV_FONT_FMT_TXT_CMAP_SPARSE_TINY
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
    .bpp = 2,
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
const lv_font_t font_dengXian_28 = {
#else
lv_font_t font_dengXian_28 = {
#endif
    .get_glyph_dsc = lv_font_get_glyph_dsc_fmt_txt,    /*Function pointer to get glyph's data*/
    .get_glyph_bitmap = lv_font_get_bitmap_fmt_txt,    /*Function pointer to get glyph's bitmap*/
    .line_height = 28,          /*The maximum line height required by the font*/
    .base_line = 5,             /*Baseline measured from the bottom of the line*/
#if !(LVGL_VERSION_MAJOR == 6 && LVGL_VERSION_MINOR == 0)
    .subpx = LV_FONT_SUBPX_NONE,
#endif
#if LV_VERSION_CHECK(7, 4, 0) || LVGL_VERSION_MAJOR >= 8
    .underline_position = -5,
    .underline_thickness = 1,
#endif
    .dsc = &font_dsc,          /*The custom font data. Will be accessed by `get_glyph_bitmap/dsc` */
    .fallback = NULL,
    .user_data = NULL,
};



#endif /*#if DENGXIAN*/


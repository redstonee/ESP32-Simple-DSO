#pragma once

#include <lvgl.h>
namespace lvgl
{

    class Style
    {
    private:
        lv_style_t _style;

    public:
        Style()
        {
            lv_style_init(&_style);
        }

        ~Style()
        {
            lv_style_reset(&_style);
        }

        lv_style_t *get()
        {
            return &_style;
        }

        Style &setBorderWidth(uint16_t width)
        {
            lv_style_set_border_width(&_style, width);
            return *this;
        }

        Style &setBorderColor(lv_color_t color)
        {
            lv_style_set_border_color(&_style, color);
            return *this;
        }

        Style &setBorderColor(uint8_t r, uint8_t g, uint8_t b)
        {
            return setBorderColor(lv_color_make(r, g, b));
        }

        Style &setBgColor(lv_color_t color)
        {
            lv_style_set_bg_color(&_style, color);
            return *this;
        }

        Style &setBgColor(uint8_t r, uint8_t g, uint8_t b)
        {
            return setBgColor(lv_color_make(r, g, b));
        }

        Style &setBgOpacity(uint8_t opa)
        {
            lv_style_set_bg_opa(&_style, opa);
            return *this;
        }

        Style &setTextColor(lv_color_t color)
        {
            lv_style_set_text_color(&_style, color);
            return *this;
        }

        Style &setTextColor(uint8_t r, uint8_t g, uint8_t b)
        {
            return setTextColor(lv_color_make(r, g, b));
        }

        Style &setTextFont(const lv_font_t *font)
        {
            lv_style_set_text_font(&_style, font);
            return *this;
        }

        Style &setHeight(uint16_t height)
        {
            lv_style_set_height(&_style, height);
            return *this;
        }

        Style &setWidth(uint16_t width)
        {
            lv_style_set_width(&_style, width);
            return *this;
        }

        Style &setSize(uint16_t w, uint16_t h)
        {
            return setHeight(h).setWidth(w);
        }

        Style &setPadTop(uint16_t pad)
        {
            lv_style_set_pad_top(&_style, pad);
            return *this;
        }

        Style &setPadBottom(uint16_t pad)
        {
            lv_style_set_pad_bottom(&_style, pad);
            return *this;
        }

        Style &setPadLeft(uint16_t pad)
        {
            lv_style_set_pad_left(&_style, pad);
            return *this;
        }

        Style &setPadRight(uint16_t pad)
        {
            lv_style_set_pad_right(&_style, pad);
            return *this;
        }

        Style &setPadAll(uint16_t pad)
        {
            lv_style_set_pad_all(&_style, pad);
            return *this;
        }

        Style &setRadius(uint16_t radius)
        {
            lv_style_set_radius(&_style, radius);
            return *this;
        }
    };
}
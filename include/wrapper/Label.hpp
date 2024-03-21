#pragma once

#include "Widget.hpp"

namespace lvgl
{
    class Label : public Widget
    {
    public:
        Label(const char *txt = "", lv_obj_t *parent = lv_scr_act())
        {
            _obj = lv_label_create(parent);
            lv_label_set_text(_obj, txt);
        }

        Label &setText(const char *txt)
        {
            lv_label_set_text(_obj, txt);
            return *this;
        }

        Label &setTextFmt(const char *fmt, ...)
        {
            va_list args;
            va_start(args, fmt);
            lv_label_set_text_fmt(_obj, fmt);
            va_end(args);
            return *this;
        }

        char *getText()
        {
            return lv_label_get_text(_obj);
        }

        Label &setLongMode(lv_label_long_mode_t mode)
        {
            lv_label_set_long_mode(_obj, mode);
            return *this;
        }

        lv_label_long_mode_t getLongMode()
        {
            return lv_label_get_long_mode(_obj);
        }

        Label &setRecolor(bool en)
        {
            lv_label_set_recolor(_obj, en);
            return *this;
        }

        bool getRecolor()
        {
            return lv_label_get_recolor(_obj);
        }

        Widget &setFont(const lv_font_t *font)
        {
            lv_obj_set_style_text_font(_obj, font, LV_PART_MAIN);
            return *this;
        }
    };
}
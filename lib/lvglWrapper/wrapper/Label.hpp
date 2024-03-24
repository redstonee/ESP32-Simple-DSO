#pragma once

#include "Widget.hpp"

namespace lvgl
{
    class Label : public Widget<Label>
    {
    public:
        Label(const char *txt, lv_obj_t *parent = lv_scr_act())
        {
            _obj = lv_label_create(parent);
            lv_label_set_text(_obj, txt);
        }

        Label(const char *txt, Widget *parent)
        {
            Label(txt, parent->get());
        }

        inline Label &setText(const char *txt)
        {
            lv_label_set_text(_obj, txt);
            return *this;
        }

        Label &setTextFmt(const char *fmt, ...)
        {
            va_list args;
            va_start(args, fmt);
            char buf[1024];
            vsprintf(buf, fmt, args);
            lv_label_set_text(_obj, buf);
            va_end(args);
            return *this;
        }

        inline char *getText()
        {
            return lv_label_get_text(_obj);
        }

        inline Label &setLongMode(lv_label_long_mode_t mode)
        {
            lv_label_set_long_mode(_obj, mode);
            return *this;
        }

        inline lv_label_long_mode_t getLongMode()
        {
            return lv_label_get_long_mode(_obj);
        }

        inline Label &setRecolor(bool en)
        {
            lv_label_set_recolor(_obj, en);
            return *this;
        }

        inline bool getRecolor()
        {
            return lv_label_get_recolor(_obj);
        }

        inline Label &setFont(const lv_font_t *font)
        {
            lv_obj_set_style_text_font(_obj, font, LV_PART_MAIN);
            return *this;
        }

        inline Label &setColor(lv_color_t color)
        {
            lv_obj_set_style_text_color(_obj, color, LV_PART_MAIN);
            return *this;
        }
    };
}
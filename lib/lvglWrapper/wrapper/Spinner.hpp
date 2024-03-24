#pragma once

#include "Widget.hpp"

namespace lvgl
{
    class Spinner : public Widget<Spinner>
    {
    public:
        Spinner(uint32_t time, uint32_t arc_len, lv_obj_t *parent)
        {
            _obj = lv_spinner_create(parent, time, arc_len);
        }

        Spinner(uint32_t time, uint32_t arc_len)
        {
            Spinner(time, arc_len, lv_scr_act());
        }

        Spinner(uint32_t time, uint32_t arc_len, Widget *parent)
        {
            Spinner(time, arc_len, parent->get());
        }
    };
}
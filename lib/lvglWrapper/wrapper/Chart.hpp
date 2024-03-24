#pragma once

#include "Widget.hpp"

namespace lvgl
{
    class Chart : public Widget<Chart>
    {
    private:
    public:
        Chart(lv_chart_type_t type, lv_obj_t *parent = lv_scr_act())
        {
            _obj = lv_chart_create(parent);
            lv_chart_set_type(_obj, type);
        }

        Chart(lv_chart_type_t type, Widget *parent)
        {
            Chart(type, parent->get());
        }

        inline Chart &setType(lv_chart_type_t type)
        {
            lv_chart_set_type(_obj, type);
            return *this;
        }

        inline Chart &setPointCount(uint16_t count)
        {
            lv_chart_set_point_count(_obj, count);
            return *this;
        }

        inline uint16_t getPointCount()
        {
            return lv_chart_get_point_count(_obj);
        }

        inline Chart &setRange(lv_chart_axis_t axis, uint16_t min, uint16_t max)
        {
            lv_chart_set_range(_obj, axis, min, max);
            return *this;
        }

        inline Chart &setDivLineCount(uint8_t count_h, uint8_t count_v)
        {
            lv_chart_set_div_line_count(_obj, count_h, count_v);
            return *this;
        }

        inline Chart &setUpdateMode(lv_chart_update_mode_t mode)
        {
            lv_chart_set_update_mode(_obj, mode);
            return *this;
        }

        inline Chart &setPointSize(uint8_t size)
        {
            lv_obj_set_style_size(_obj, 0, LV_PART_INDICATOR);
            return *this;
        }

        inline void refresh()
        {
            lv_chart_refresh(_obj);
        }
    };
}
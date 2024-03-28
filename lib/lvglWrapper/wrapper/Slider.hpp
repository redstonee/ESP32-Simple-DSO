#pragma once

#include "Widget.hpp"

namespace lvgl {

class Slider : public Widget<Slider> {
  Slider(lv_obj_t *parent = lv_scr_act()) { lv_slider_create(parent); }

  Slider(Widget *parent) { Slider(parent->get()); }

  inline Slider &setMode(lv_slider_mode_t mode) {
    lv_slider_set_mode(_obj, mode);
    return *this;
  }

  inline lv_slider_mode_t getMode() { return lv_slider_get_mode(_obj); }

  inline Slider &setValue(int32_t value,
                          lv_anim_enable_t anim_en = LV_ANIM_OFF) {
    lv_slider_set_value(_obj, value, anim_en);
    return *this;
  }

  inline Slider &setValue(int32_t value, bool anim_en) {
    return setValue(value, anim_en ? LV_ANIM_ON : LV_ANIM_OFF);
  }

  inline int32_t getValue() { return lv_slider_get_value(_obj); }

  inline Slider &setRange(int32_t min, int32_t max) {
    lv_slider_set_range(_obj, min, max);
    return *this;
  }

  inline Slider &setLeftValue(int32_t value,
                              lv_anim_enable_t anim_en = LV_ANIM_OFF) {
    lv_slider_set_left_value(_obj, value, anim_en);
    return *this;
  }

  inline Slider &setLeftValue(int32_t value, bool anim_en) {
    return setLeftValue(value, anim_en ? LV_ANIM_ON : LV_ANIM_OFF);
  }

  inline int32_t getLeftValue() { return lv_slider_get_left_value(_obj); }
};
} // namespace lvgl
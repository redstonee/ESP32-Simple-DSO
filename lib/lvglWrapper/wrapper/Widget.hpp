#pragma once

#include "Style.hpp"
#include <lvgl.h>

namespace lvgl {
template <class That> class Widget {
protected:
  lv_obj_t *_obj;
  inline void addEvent(lv_event_cb_t event_cb,
                       lv_event_code_t event_type = LV_EVENT_ALL) {
    lv_obj_add_event_cb(_obj, event_cb, event_type, nullptr);
  }

public:
  ~Widget() { lv_obj_del(_obj); }
  inline That &align(lv_align_t align, lv_coord_t x_mod, lv_coord_t y_mod) {
    lv_obj_align(_obj, align, x_mod, y_mod);
    return static_cast<That &>(*this);
  }

  inline That &setSize(lv_coord_t width, lv_coord_t height) {
    lv_obj_set_size(_obj, width, height);
    return static_cast<That &>(*this);
  }

  inline That &setPos(lv_coord_t x, lv_coord_t y) {
    lv_obj_set_pos(_obj, x, y);
    return static_cast<That &>(*this);
  }

  inline That &setParent(lv_obj_t *parent) {
    lv_obj_set_parent(_obj, parent);
    return static_cast<That &>(*this);
  }

  inline That &setParent(Widget *parent) {
    return lv_obj_set_parent(_obj, parent->get());
  }

  inline That &addStyle(lv_style_t *style,
                        lv_style_selector_t selector = LV_PART_MAIN) {
    lv_obj_add_style(_obj, style, selector);
    return static_cast<That &>(*this);
  }

  inline That &addStyle(Style *style,
                        lv_style_selector_t selector = LV_PART_MAIN) {
    return lv_obj_add_style(_obj, style->get(), selector);
  }

  inline That &removeStyle(lv_style_selector_t selector) {
    lv_obj_remove_style(_obj, NULL, selector);
    return static_cast<That &>(*this);
  }
  inline lv_obj_t *get() { return _obj; }

  inline That &setAngle(uint16_t angle) {
    lv_obj_set_style_transform_angle(_obj, angle * 10, LV_PART_MAIN);
    return static_cast<That &>(*this);
  }
};

} // namespace lvgl
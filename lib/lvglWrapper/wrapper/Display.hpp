#pragma once

#include <lvgl.h>
#include <vector>

namespace lvgl {
namespace DisplayDriver {
static lv_disp_drv_t disp_drv;
static lv_disp_draw_buf_t draw_buf;
static std::vector<lv_color_t> buf;

void init(uint16_t width, uint16_t height, uint32_t bufferSize,
          void (*flush_cb)(struct _lv_disp_drv_t *disp_drv,
                           const lv_area_t *area, lv_color_t *color_p)) {
  buf = std::vector<lv_color_t>(bufferSize);
  lv_disp_draw_buf_init(&draw_buf, buf.data(), NULL, bufferSize);

  lv_disp_drv_init(&disp_drv);
  disp_drv.draw_buf = &draw_buf;
  disp_drv.flush_cb = flush_cb;
  disp_drv.hor_res = width;
  disp_drv.ver_res = height;
  lv_disp_drv_register(&disp_drv);
}

} // namespace DisplayDriver
} // namespace lvgl
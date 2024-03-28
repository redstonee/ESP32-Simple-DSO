#pragma once

#include <Arduino.h>
#include <TFT_eSPI.h>
#include <examples/lv_examples.h>
#include <lvgl.h>
// #include <random>

#include "AnalogConfig.hpp"
#include "config.h"
#include "lvglWrapper.h"

extern "C" {
LV_FONT_DECLARE(font_dengXian_14)
LV_FONT_DECLARE(font_dengXian_28)
}

extern SemaphoreHandle_t lvglMutex;

namespace GFXDriver {
static TFT_eSPI tft;

void display_flush(lv_disp_drv_t *disp_drv, const lv_area_t *area,
                   lv_color_t *color_map) {
  uint32_t w = (area->x2 - area->x1 + 1);
  uint32_t h = (area->y2 - area->y1 + 1);

  tft.startWrite();
  tft.setAddrWindow(area->x1, area->y1, w, h);
  // tft.pushColors(&color_map->full, w * h, true);
  tft.pushPixelsDMA(&color_map->full, w * h);
  tft.endWrite();

  lv_disp_flush_ready(disp_drv);
}

void touch_read(lv_indev_drv_t *indev, lv_indev_data_t *data) {
  uint16_t touchX, touchY;

  bool touched = tft.getTouch(&touchX, &touchY, 600);

  if (!touched) {
    data->state = LV_INDEV_STATE_REL;
  } else {
    data->state = LV_INDEV_STATE_PR;

    /*Set the coordinates*/
    data->point.x = touchX;
    data->point.y = touchY;
  }
}

#if LV_USE_LOG != 0
/* Serial debugging */
void log_print(const char *buf) {
  Serial.printf(buf);
  Serial.flush();
}
#endif

void lvglTickTask(void *pvParameters) {
  while (true) {
    delay(1);
    lv_tick_inc(1);
  }
}

void init() {
  tft.begin();
  tft.setRotation(1);
  tft.setSwapBytes(true);
  tft.initDMA();
  uint16_t calData[5] = {383, 3506, 311, 3408, 3};
  tft.setTouch(calData);
  lvgl::init();
  lvgl::DisplayDriver::init(LCD_WIDTH, LCD_HEIGHT, LCD_WIDTH * LCD_HEIGHT,
                            display_flush);
  lvgl::Indev::init(touch_read);
#if LV_USE_LOG != 0
  lv_log_register_print_cb(log_print);
#endif

  xTaskCreate(lvglTickTask, "lvglTickTask", 4096, NULL, 3, NULL);
}



} // namespace GFXDriver

namespace Graphics {
using namespace lvgl;

uint8_t selectedChannel = 0xff; // 0xff means no channel selected

static bool running = true;

inline void setSelectedChannel(uint8_t ch) {
  if (ch > 1 and ch != 0xff) {
    log_printf("Invalid channel number: %d\n", ch);
    return;
  }

  selectedChannel = ch;
}

inline uint8_t getSelectedChannel() { return selectedChannel; }

inline void toggleRunning() { running = !running; }

void drawTestThings() {
  static auto txt = Label("你他妈的是傻屄？");
  txt.setFont(&font_dengXian_28).align(LV_ALIGN_CENTER, 0, 0);

  static uint16_t count = 0;

  static auto cnt_txt = Label("0");
  cnt_txt.align(LV_ALIGN_CENTER, 0, -30);

  static class BtnOnClick : public OnClickListener {
  public:
    void onClick() {
      count++;
      cnt_txt.setTextFmt("%d", count);
    }
  } btnOnClick;

  static auto btn = TextButton("肏你");
  btn.setFont(&font_dengXian_28)
      .setOnClickListener(&btnOnClick)
      .align(LV_ALIGN_CENTER, 0, 60)
      .setSize(100, 30);
}

void refreshStatusTask(void *pvParameters) {
  auto txt_running = ((Label **)pvParameters)[0];
  auto txt_ch0 = ((Label **)pvParameters)[1];
  auto txt_ch1 = ((Label **)pvParameters)[2];

  while (true) {
    if (xSemaphoreTake(lvglMutex, 10 / portTICK_RATE_MS)) {
      txt_running->setText(running ? "Running" : "Stopped")
          .setColor(running ? lv_palette_main(LV_PALETTE_GREEN)
                            : lv_palette_main(LV_PALETTE_RED));
      txt_ch0->setColor(AnalogConfig::getChannelEnabled(0)
                            ? lv_palette_main(LV_PALETTE_TEAL)
                            : lv_palette_main(LV_PALETTE_GREY));
      txt_ch1->setColor(AnalogConfig::getChannelEnabled(1)
                            ? lv_palette_main(LV_PALETTE_DEEP_ORANGE)
                            : lv_palette_main(LV_PALETTE_GREY));
      xSemaphoreGive(lvglMutex);
      vTaskDelay(300 / portTICK_PERIOD_MS);
    }
  }
}

void testDataTask(void *pvParameters) {
  std::vector<lv_coord_t> chartData(200, 0);
  auto chart = (Chart *)pvParameters;
  auto s = lv_chart_add_series(chart->get(), lv_palette_main(LV_PALETTE_TEAL),
                               LV_CHART_AXIS_PRIMARY_Y);
  lv_chart_set_ext_y_array(chart->get(), s, chartData.data());

  while (true) {
    if (running) {
      // lv_chart_set_next_value(chart->get(), s, random(-30, 30));
      for (auto &v : chartData)
        v = random(-30, 30);

      if (xSemaphoreTake(lvglMutex, 10 / portTICK_RATE_MS)) {
        chart->refresh();
        xSemaphoreGive(lvglMutex);
      }
    }
    vTaskDelay(100 / portTICK_PERIOD_MS);
  }
}

void drawMainScreen() {

  static auto title = Label("垃圾示波器");
  title.setFont(&font_dengXian_14).align(LV_ALIGN_TOP_MID, 0, 0);

  static auto txt_running = Label("Running");
  txt_running.align(LV_ALIGN_BOTTOM_LEFT, 32, -4)
      .setFont(&lv_font_montserrat_14)
      .setColor(lv_palette_main(LV_PALETTE_GREEN));

  static auto waveChart = Chart(LV_CHART_TYPE_LINE);
  waveChart.setRange(LV_CHART_AXIS_PRIMARY_Y, 0, 4096)
      .setDivLineCount(4, 6)
      .setPointSize(0)
      .align(LV_ALIGN_CENTER, 0, 0)
      .setSize(260, 200)
      .setPointCount(200)
      .setRange(LV_CHART_AXIS_PRIMARY_Y, -30, 30)
      .setUpdateMode(LV_CHART_UPDATE_MODE_SHIFT)
      .setParent(lv_scr_act())
      .setAxisTick(LV_CHART_AXIS_PRIMARY_Y, 10, 5, 5, 3, true, 30);

  static auto txt_ch0 = Label("CH1");
  txt_ch0.align(LV_ALIGN_BOTTOM_MID, -20, -4)
      .setFont(&lv_font_montserrat_14)
      .setColor(lv_palette_main(LV_PALETTE_TEAL));

  static auto txt_ch1 = Label("CH2");
  txt_ch1.align(LV_ALIGN_BOTTOM_MID, 20, -4)
      .setFont(&lv_font_montserrat_14)
      .setColor(lv_palette_main(LV_PALETTE_DEEP_ORANGE));

  static auto btn_menu = TextButton("Menu");
  btn_menu.setFont(&lv_font_montserrat_16)
      .setSize(80, 25)
      .setAngle(-90)
      .setPos(295, 160);

  xTaskCreate(testDataTask, "testDataTask", 4096, &waveChart, 1, NULL);

  static const Label *statusLabels[] = {&txt_running, &txt_ch0, &txt_ch1};
  xTaskCreate(refreshStatusTask, "refreshStatusTask", 4096,
              (void *)statusLabels, 1, NULL);
}
} // namespace Graphics
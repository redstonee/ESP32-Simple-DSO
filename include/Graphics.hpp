#pragma once

#include <Arduino.h>
#include <lvgl.h>
#include <examples/lv_examples.h>
#include <TFT_eSPI.h>

#include "config.h"
#include "lvglWrapper.h"

extern "C"
{
    LV_FONT_DECLARE(dengXian)
}

namespace GFXDriver
{
    static TFT_eSPI tft;

    void display_flush(lv_disp_drv_t *disp_drv, const lv_area_t *area, lv_color_t *color_map)
    {
        uint32_t w = (area->x2 - area->x1 + 1);
        uint32_t h = (area->y2 - area->y1 + 1);

        tft.startWrite();
        tft.setAddrWindow(area->x1, area->y1, w, h);
        tft.pushColors(&color_map->full, w * h, true);
        tft.endWrite();

        lv_disp_flush_ready(disp_drv);
    }

    void touch_read(lv_indev_drv_t *indev, lv_indev_data_t *data)
    {
        uint16_t touchX, touchY;

        bool touched = tft.getTouch(&touchX, &touchY, 600);

        if (!touched)
        {
            data->state = LV_INDEV_STATE_REL;
        }
        else
        {
            data->state = LV_INDEV_STATE_PR;

            /*Set the coordinates*/
            data->point.x = touchX;
            data->point.y = touchY;
        }
    }

#if LV_USE_LOG != 0
    /* Serial debugging */
    void log_print(const char *buf)
    {
        Serial.printf(buf);
        Serial.flush();
    }
#endif

    void init()
    {
        tft.begin();
        tft.setRotation(1);
        uint16_t calData[5] = {383, 3506, 311, 3408, 3};
        tft.setTouch(calData);
        lvgl::init();
        lvgl::DisplayDriver::init(LCD_WIDTH, LCD_HEIGHT, LCD_WIDTH * LCD_HEIGHT / 10, display_flush);
        lvgl::Indev::init(touch_read);
#if LV_USE_LOG != 0
        lv_log_register_print_cb(log_print);
#endif
    }

} // namespace GFXDriver

namespace Graphics
{
    using namespace lvgl;

    static bool ch0_selected = false;
    static bool ch1_selected = false;
    static bool running = true;

    inline void setChannelSelected(uint8_t ch, bool selected)
    {
        switch (ch)
        {
        case 0:
            ch0_selected = selected;
            break;

        case 1:
            ch1_selected = selected;
            break;
        default:
            log_printf("Invalid channel number: %d\n", ch);
        }
    }

    inline bool getChannelSelected(uint8_t ch)
    {
        switch (ch)
        {
        case 0:
            return ch0_selected;
        case 1:
            return ch1_selected;
        default:
            log_printf("Invalid channel number: %d\n", ch);
            return false;
        }
    }

    inline void toggleRunning()
    {
        running = !running;
    }

    void drawTestThings()
    {
        static auto txt = Label("你他妈的是傻屄？");
        txt.setFont(&dengXian).align(LV_ALIGN_CENTER, 0, 0);

        static uint16_t count = 0;

        static auto cnt_txt = Label("0");
        cnt_txt.align(LV_ALIGN_CENTER, 0, -30);

        static class BtnOnClick : public OnClickListener
        {
        public:
            void onClick()
            {
                count++;
                cnt_txt.setTextFmt("%d", count);
            }
        } btnOnClick;

        static auto btn = TextButton("肏你");
        btn.setFont(&dengXian).setOnClickListener(&btnOnClick).align(LV_ALIGN_CENTER, 0, 60).setSize(100, 30);
    }

    void drawMainScreen()
    {

        static auto title = Label("垃圾示波器");
        title.setFont(&dengXian).align(LV_ALIGN_TOP_MID, 0, 0).setSize(LCD_WIDTH, 30);

        static auto txt_running = Label("Running");
        txt_running.align(LV_ALIGN_BOTTOM_LEFT, 0, 0).setFont(&lv_font_montserrat_16);

    }
}
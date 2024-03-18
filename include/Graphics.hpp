#pragma once

#include <Arduino.h>
#include <lvgl.h>
#include <TFT_eSPI.h>

#include "config.h"

// extern Adafruit_SH1106G display;

namespace Graphics
{

    static TFT_eSPI tft; /* TFT instance */

#if LV_USE_LOG != 0
    /* Serial debugging */
    void my_log_print(const char *buf)
    {
        Serial.printf(buf);
        Serial.flush();
    }
#endif

    /* Display flushing */
    void my_disp_flush(lv_disp_drv_t *disp, const lv_area_t *area, lv_color_t *color_p)
    {
        uint32_t w = (area->x2 - area->x1 + 1);
        uint32_t h = (area->y2 - area->y1 + 1);

        tft.startWrite();
        tft.setAddrWindow(area->x1, area->y1, w, h);
        tft.pushColors(&color_p->full, w * h, true);
        tft.endWrite();

        lv_disp_flush_ready(disp);
    }

        void my_touchpad_read(lv_indev_drv_t *indev_drv, lv_indev_data_t *data)
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

            Serial.print("Data x ");
            Serial.println(touchX);

            Serial.print("Data y ");
            Serial.println(touchY);
        }
    }

    void init()
    {
        static lv_disp_draw_buf_t disp_draw_buf;
        static lv_color_t buf[LCD_HEIGHT * LCD_WIDTH / 10];
        lv_disp_draw_buf_init(&disp_draw_buf, buf, NULL, LCD_HEIGHT * LCD_WIDTH / 10);

        lv_init();
#if LV_USE_LOG != 0
        lv_log_register_print_cb(my_log_print);
#endif
        static lv_disp_drv_t disp_drv;
        lv_disp_drv_init(&disp_drv);
        disp_drv.flush_cb = my_disp_flush;
        disp_drv.draw_buf = &disp_draw_buf;
        disp_drv.hor_res = LCD_WIDTH;
        disp_drv.ver_res = LCD_HEIGHT;
        lv_disp_drv_register(&disp_drv);

        static lv_indev_drv_t indev_drv;
        lv_indev_drv_init(&indev_drv);
        indev_drv.type = LV_INDEV_TYPE_POINTER;
        indev_drv.read_cb = my_touchpad_read;
        lv_indev_drv_register(&indev_drv);
    }
}
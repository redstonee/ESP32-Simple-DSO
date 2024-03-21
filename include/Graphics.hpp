#pragma once

#include <Arduino.h>
#include <lvgl.h>
#include <examples/lv_examples.h>
#include <TFT_eSPI.h>

#include "config.h"

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

            Serial.print("Data x ");
            Serial.println(touchX);

            Serial.print("Data y ");
            Serial.println(touchY);
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
        static lv_disp_draw_buf_t draw_buf;
        static lv_color_t buf[LCD_WIDTH * LCD_HEIGHT / 10];

        tft.begin();
        tft.setRotation(1);
        uint16_t calData[5] = {383, 3506, 311, 3408, 3};
        tft.setTouch(calData);

        lv_init();

#if LV_USE_LOG != 0
        lv_log_register_print_cb(log_print);
#endif

        lv_disp_draw_buf_init(&draw_buf, buf, NULL, LCD_WIDTH * LCD_HEIGHT / 10);

        static lv_disp_drv_t disp_drv;
        lv_disp_drv_init(&disp_drv);
        disp_drv.draw_buf = &draw_buf;
        disp_drv.flush_cb = display_flush;
        disp_drv.hor_res = LCD_WIDTH;
        disp_drv.ver_res = LCD_HEIGHT;
        lv_disp_drv_register(&disp_drv);

        static lv_indev_drv_t indev_drv;
        lv_indev_drv_init(&indev_drv);
        indev_drv.type = LV_INDEV_TYPE_POINTER;
        indev_drv.read_cb = touch_read;
        lv_indev_drv_register(&indev_drv);
    }

} // namespace GFXDriver

namespace Graphics
{

    void init()
    {
        GFXDriver::init();

        static auto txt = lv_label_create(lv_scr_act());
        lv_obj_set_style_text_font(txt, &dengXian, LV_PART_MAIN);
        lv_label_set_text(txt, "你他妈的是傻屄？");
        lv_obj_align(txt, LV_ALIGN_CENTER, 0, 0);

        static uint16_t count = 0;
        static auto cnt_txt = lv_label_create(lv_scr_act());
        lv_label_set_text_fmt(cnt_txt, "%d", count);
        lv_obj_align(cnt_txt, LV_ALIGN_CENTER, 0, -30);

        auto btnOnClick = [](lv_event_t * event)
        {
            if (lv_event_get_code(event) == LV_EVENT_CLICKED)
            {
                count++;
                lv_label_set_text_fmt(cnt_txt, "%d", count);
            }
        };

        static auto btn = lv_btn_create(lv_scr_act());
        lv_obj_set_size(btn, 100, 30);
        lv_obj_align(btn, LV_ALIGN_CENTER, 0, 60);
        lv_obj_add_event_cb(btn, btnOnClick, LV_EVENT_CLICKED, NULL);

        static auto btn_txt = lv_label_create(btn);
        lv_obj_set_style_text_font(btn_txt, &dengXian, LV_PART_MAIN);
        lv_label_set_text(btn_txt, "我肏");
        lv_obj_center(btn_txt);
    }
}
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

    void drawTestThings()
    {
        // static auto txt = lvgl::Label("你他妈的是傻屄？").setFont(&dengXian).align(LV_ALIGN_CENTER, 0, 0);
        // static auto txt = lv_label_create(lv_scr_act());
        // lv_obj_set_style_text_font(txt, &dengXian, LV_PART_MAIN);
        // lv_label_set_text(txt, "你他妈的是傻屄？");
        // lv_obj_align(txt, LV_ALIGN_CENTER, 0, 0);

        static uint16_t count = 0;

        static auto cnt_txt = lvgl::Label("0");
        static auto ww=cnt_txt.align(LV_ALIGN_CENTER, 0, -30);
        // static auto cnt_txt = lv_label_create(lv_scr_act());
        // lv_label_set_text_fmt(cnt_txt, "%d", count);
        // lv_obj_align(cnt_txt, LV_ALIGN_CENTER, 0, -30);

        static class BtnOnClick : public lvgl::OnClickListener
        {
        public:
            void onClick()
            {
                count++;
                cnt_txt.setTextFmt("%d", count);
            }
        } btnOnClick;

        // static auto btn = lvgl::TextButton("我肏").setOnClickListener(&btnOnClick).align(LV_ALIGN_CENTER, 0, 60).setSize(100, 30);

        //     static auto btn = lv_btn_create(lv_scr_act());
        //     lv_obj_set_size(btn, 100, 30);
        //     lv_obj_align(btn, LV_ALIGN_CENTER, 0, 60);
        //     lv_obj_add_event_cb(btn, btnOnClick, LV_EVENT_CLICKED, NULL);

        //     static auto btn_txt = lv_label_create(btn);
        //     lv_obj_set_style_text_font(btn_txt, &dengXian, LV_PART_MAIN);
        //     lv_label_set_text(btn_txt, "我肏");
        //     lv_obj_center(btn_txt);
        // }
    }
}
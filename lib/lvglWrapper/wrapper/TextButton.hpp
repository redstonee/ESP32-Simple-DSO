#pragma once

#include "Widget.hpp"
#include "Label.hpp"
#include "EventListener.hpp"

namespace lvgl
{
    class TextButton : public Widget<TextButton>
    {
    private:
        Label *_label;

    public:
        TextButton(const char *txt, lv_obj_t *parent = lv_scr_act())
        {
            _obj = lv_btn_create(parent);
            _label = new Label(txt, _obj);
            _label->align(LV_ALIGN_CENTER, 0, 0);
        }

        TextButton &setFont(const lv_font_t *font)
        {
            _label->setFont(font);
            return *this;
        }
        
        TextButton &setText(char *txt)
        {
            _label->setText(txt);
            return *this;
        }

        TextButton &setTextFmt(const char *fmt, ...)
        {
            va_list args;
            va_start(args, fmt);
            char buf[1024];
            vsprintf(buf, fmt, args);
            _label->setText(buf);
            va_end(args);
            return *this;
        }

        char *getText()
        {
            return _label->getText();
        }

        TextButton &setOnClickListener(OnClickListener *listener)
        {
            static auto _listener = listener;
            addEvent([](lv_event_t *e)
                     { _listener->onClick(); },
                     LV_EVENT_CLICKED);
            return *this;
        }

        TextButton &setOnLongPressListener(OnLongPressListener *listener)
        {
            static auto _listener = listener;
            addEvent([](lv_event_t *e)
                     { _listener->onLongPress(); },
                     LV_EVENT_LONG_PRESSED);
            return *this;
        }
    };
}
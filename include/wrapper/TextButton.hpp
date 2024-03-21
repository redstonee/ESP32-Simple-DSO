#pragma once

#include "Widget.hpp"
#include "Label.hpp"
#include "EventListener.hpp"

namespace lvgl
{
    class TextButton : public Widget
    {
    private:
        Label _label;

    public:
        TextButton(char *txt, lv_obj_t *parent = lv_scr_act())
        {
            _obj = lv_btn_create(parent);
            _label = Label(txt, _obj);
        }

        TextButton &setText(char *txt)
        {
            _label.setText(txt);
            return *this;
        }

        char *getText()
        {
            return _label.getText();
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
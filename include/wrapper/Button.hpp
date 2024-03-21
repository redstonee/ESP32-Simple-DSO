#include "Widget.hpp"
#include "Label.hpp"

class Button : public Widget
{
private:
    Label _label;

public:
    Button(char *txt, lv_obj_t *parent = lv_scr_act())
    {
        _obj = lv_btn_create(parent);
        _label = Label(_obj, txt);
    }

    inline Button &setText(char *txt)
    {
        _label.setText(txt);
        return *this;
    }

    inline char *getText()
    {
        return _label.getText();
    }

    inline Button &setOnClickListener(void (*onClick)())
    {
        addEvent([&onClick](lv_event_t *e)
                 { onClick(); },
                 LV_EVENT_CLICKED);
        return *this;
    }
};

#include "Widget.hpp"

class Label : public Widget
{
public:
    Label(lv_obj_t *parent = lv_scr_act(), const char *txt = "")
    {
        _obj = lv_label_create(parent);
        lv_label_set_text(_obj, txt);
    }

    inline Label &setText(const char *txt)
    {
        lv_label_set_text(_obj, txt);
        return *this;
    }

    inline char *getText()
    {
        return lv_label_get_text(_obj);
    }

    inline Label &setLongMode(lv_label_long_mode_t mode)
    {
        lv_label_set_long_mode(_obj, mode);
        return *this;
    }

    inline lv_label_long_mode_t getLongMode()
    {
        return lv_label_get_long_mode(_obj);
    }

    inline Label &setRecolor(bool en)
    {
        lv_label_set_recolor(_obj, en);
        return *this;
    }

    inline bool getRecolor()
    {
        return lv_label_get_recolor(_obj);
    }
};

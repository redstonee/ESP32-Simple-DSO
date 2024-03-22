#include <lvgl.h>

namespace lvgl
{
    namespace Indev
    {
        static lv_indev_drv_t indev_drv;
        void init(void (*read_cb)(struct _lv_indev_drv_t *indev_drv, lv_indev_data_t *data))
        {
            lv_indev_drv_init(&indev_drv);
            indev_drv.type = LV_INDEV_TYPE_POINTER;
            indev_drv.read_cb = read_cb;
            lv_indev_drv_register(&indev_drv);
        }
    }
}
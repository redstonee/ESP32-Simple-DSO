#pragma once

#include "wrapper/TextButton.hpp"
#include "wrapper/Display.hpp"
#include "wrapper/EventListener.hpp"
#include "wrapper/Indev.hpp"
#include "wrapper/Label.hpp"
#include "wrapper/Style.hpp"
#include "wrapper/Widget.hpp"

namespace lvgl
{
    inline void init()
    {
        lv_init();
    }
}
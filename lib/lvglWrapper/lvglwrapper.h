#pragma once

#include "wrapper/TextButton.hpp"
#include "wrapper/Display.hpp"
#include "wrapper/EventListener.hpp"
#include "wrapper/Indev.hpp"
#include "wrapper/Label.hpp"
#include "wrapper/Style.hpp"
#include "wrapper/Widget.hpp"
#include "wrapper/Slider.hpp"
#include "wrapper/Spinner.hpp"
#include "wrapper/Chart.hpp"

namespace lvgl
{
    inline void init()
    {
        lv_init();
    }
}
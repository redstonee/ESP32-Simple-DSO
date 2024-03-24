#pragma once

#include <Arduino.h>

#include "config.h"
#include "Graphics.hpp"
#include "AnalogConfig.hpp"

namespace ButtonHandler
{

    void handleChannelButton(uint8_t channel)
    {
        if (AnalogConfig::getChannelEnabled(channel))
        {
            if (Graphics::getChannelSelected(channel))
                AnalogConfig::setChannelEnabled(channel, false);
            else
                Graphics::setChannelSelected(channel, true);
        }
        else
        {
            AnalogConfig::setChannelEnabled(channel, true);
            Graphics::setChannelSelected(channel, true);
        }
    }

    void handleRunStopButton()
    {
        Graphics::toggleRunning();
    }

    void task(void *pvParameters)
    {
        while (1)
        {
            if (digitalRead(BTN_CH1) == LOW)
            {
                handleChannelButton(0);
                while (!digitalRead(BTN_CH1))
                    ;

                delay(100);
            }
            if (digitalRead(BTN_CH2) == LOW)
            {
                handleChannelButton(1);
                while (!digitalRead(BTN_CH2))
                    ;
                delay(100);
            }
            if (digitalRead(BTN_RUN_ST) == LOW)
            {
                Graphics::toggleRunning();
                while (!digitalRead(BTN_RUN_ST))
                    ;
                delay(100);
            }
            delay(10);
        }
    }

    inline void init()
    {
        pinMode(BTN_CH1, INPUT_PULLUP);
        pinMode(BTN_CH2, INPUT_PULLUP);
        pinMode(BTN_RUN_ST, INPUT_PULLUP);
        xTaskCreate(task, "ButtonHandler", 2048, NULL, 1, NULL);
    }

}
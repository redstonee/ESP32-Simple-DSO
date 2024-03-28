#pragma once

#include <Arduino.h>

#include "AnalogConfig.hpp"
#include "Graphics.hpp"
#include "config.h"

namespace ButtonHandler {

void handleChannelButton(uint8_t channel) {
  if (AnalogConfig::getChannelEnabled(channel)) {
    if (Graphics::getSelectedChannel() == channel)
      AnalogConfig::setChannelEnabled(channel, false);
    else
      Graphics::setSelectedChannel(channel);
  } else {
    AnalogConfig::setChannelEnabled(channel, true);
    Graphics::setSelectedChannel(channel);
  }
}

void handleRunStopButton() { Graphics::toggleRunning(); }

void task(void *pvParameters) {
  while (1) {
    if (digitalRead(BTN_CH1) == LOW) {
      handleChannelButton(0);
      while (!digitalRead(BTN_CH1))
        ;

      delay(100);
    }
    if (digitalRead(BTN_CH2) == LOW) {
      handleChannelButton(1);
      while (!digitalRead(BTN_CH2))
        ;
      delay(100);
    }
    if (digitalRead(BTN_RUN_ST) == LOW) {
      Graphics::toggleRunning();
      while (!digitalRead(BTN_RUN_ST))
        ;
      delay(100);
    }
    delay(10);
  }
}

inline void init() {
  pinMode(BTN_CH1, INPUT_PULLUP);
  pinMode(BTN_CH2, INPUT_PULLUP);
  pinMode(BTN_RUN_ST, INPUT_PULLUP);
  xTaskCreate(task, "ButtonHandler", 2048, NULL, 1, NULL);
}

} // namespace ButtonHandler
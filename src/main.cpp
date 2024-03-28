#include <Arduino.h>
#include <TFT_eSPI.h>
#include <lvgl.h>

#include "AnalogConfig.hpp"
#include "Buttonhandler.hpp"
#include "Graphics.hpp"
#include "config.h"

SemaphoreHandle_t lvglMutex;

void setup() {
  // put your setup code here, to run once:

  lvglMutex = xSemaphoreCreateMutex();
  Serial.begin(115200);
  GFXDriver::init();
  // Graphics::drawTestThings();
  Graphics::drawMainScreen();
  AnalogConfig::init();
  ButtonHandler::init();
}

void loop() {
  // put your main code here, to run repeatedly:
  if (xSemaphoreTake(lvglMutex, 10 / portTICK_RATE_MS)) {
      lv_task_handler();
      xSemaphoreGive(lvglMutex);
    }
  delay(5);
}
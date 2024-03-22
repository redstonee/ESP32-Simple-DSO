#include <Arduino.h>
#include <lvgl.h>
#include <TFT_eSPI.h>

#include "config.h"
#include "Graphics.hpp"
#include "AnalogConfig.hpp"
#include "Buttonhandler.hpp"

void setup()
{
  // put your setup code here, to run once:

  Serial.begin(115200);
  GFXDriver::init();
  Graphics::drawTestThings();
  AnalogConfig::init();
  ButtonHandler::init();
}

void loop()
{
  // put your main code here, to run repeatedly:
  lv_tick_inc(5);
  lv_task_handler();
  delay(5);
}
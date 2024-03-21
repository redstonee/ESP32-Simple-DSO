#pragma once

#include <Arduino.h>

// Pin definitions except for the display
constexpr uint8_t CHARGE_STAT = 48;
constexpr uint8_t CHARGE_DET = 47;

constexpr uint8_t BTN_CH1 = 5;
constexpr uint8_t BTN_CH2 = 6;
constexpr uint8_t BTN_RUN_ST = 38;

constexpr uint8_t ATT_GAIN_A0 = 15;
constexpr uint8_t ATT_GAIN_A1 = 16;
constexpr uint8_t COUPLING1 = 17;
constexpr uint8_t COUPLING2 = 18;

// Display size
constexpr uint16_t LCD_WIDTH = 320;
constexpr uint16_t LCD_HEIGHT = 240;
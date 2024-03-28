#pragma once

#include "Preferences.h"
#include "config.h"
#include <Arduino.h>

namespace AnalogConfig {
static bool ch0_enabled, ch1_enabled;
static Preferences pref;

constexpr auto CH0_EN_KEY = "ch0_en";
constexpr auto CH1_EN_KEY = "ch1_en";
constexpr auto ATT_GAIN_KEY = "att_gain";
constexpr auto COUPLING_CH0_KEY = "coupling_ch0";
constexpr auto COUPLING_CH1_KEY = "coupling_ch1";

enum class Att_Gain {
  Att_30,
  Att_6,
  Gain_0_6,
  Gain_3,
};

enum class Coupling {
  DC,
  AC,
};

void setAttGain(Att_Gain att_gain) {
  switch (att_gain) {
  case Att_Gain::Att_30:
    digitalWrite(ATT_GAIN_A0, 0);
    digitalWrite(ATT_GAIN_A1, 0);
    break;

  case Att_Gain::Att_6:
    digitalWrite(ATT_GAIN_A0, 1);
    digitalWrite(ATT_GAIN_A1, 0);
    break;

  case Att_Gain::Gain_0_6:
    digitalWrite(ATT_GAIN_A0, 0);
    digitalWrite(ATT_GAIN_A1, 1);
    break;

  case Att_Gain::Gain_3:
    digitalWrite(ATT_GAIN_A0, 1);
    digitalWrite(ATT_GAIN_A1, 1);
    break;
  default:
    break;
  }
  pref.putUChar(ATT_GAIN_KEY, static_cast<uint8_t>(att_gain));
}

void setChannelCoupling(uint8_t channel, Coupling coupling) {
  uint8_t pin;
  switch (channel) {
  case 0:
    pin = COUPLING1;
    pref.putUChar(COUPLING_CH0_KEY, static_cast<uint8_t>(coupling));
    break;
  case 1:
    pin = COUPLING2;
    pref.putUChar(COUPLING_CH1_KEY, static_cast<uint8_t>(coupling));
    break;
  default:
    log_printf("Invalid channel number: %d\n", channel);
    return;
  }

  digitalWrite(pin, coupling == Coupling::AC ? 0 : 1);
}

void setChannelEnabled(uint8_t channel, bool enabled) {
  assert(channel < 2);
  switch (channel) {
  case 0:
    ch0_enabled = enabled;
    break;
  case 1:
    ch1_enabled = enabled;
    break;
  default:
    log_printf("Invalid channel number: %d\n", channel);
    return;
  }
  pref.putBool(channel == 0 ? CH0_EN_KEY : CH1_EN_KEY, enabled);
}

inline bool getChannelEnabled(uint8_t channel) {
  switch (channel) {
  case 0:
    return ch0_enabled;
  case 1:
    return ch1_enabled;
  default:
    log_printf("Invalid channel number: %d\n", channel);
    return false;
  }
}

inline void toggleChannelEnabled(uint8_t channel) {
  setChannelEnabled(channel, !getChannelEnabled(channel));
}

void init() {
  pinMode(ATT_GAIN_A0, OUTPUT);
  pinMode(ATT_GAIN_A1, OUTPUT);
  pinMode(COUPLING1, OUTPUT);
  pinMode(COUPLING2, OUTPUT);

  pref.begin("analog");
  ch0_enabled = pref.getBool(CH0_EN_KEY, true);
  ch1_enabled = pref.getBool(CH1_EN_KEY, false);
  uint8_t att_gain = pref.getUChar(ATT_GAIN_KEY, 0);
  uint8_t coupling_ch0 = pref.getUChar(COUPLING_CH0_KEY, 0);
  uint8_t coupling_ch1 = pref.getUChar(COUPLING_CH1_KEY, 0);
  setAttGain(static_cast<Att_Gain>(att_gain));
  setChannelCoupling(0, static_cast<Coupling>(coupling_ch0));
  setChannelCoupling(1, static_cast<Coupling>(coupling_ch1));
}

} // namespace AnalogConfig
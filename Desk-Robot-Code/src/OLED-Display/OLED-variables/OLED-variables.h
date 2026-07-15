#pragma once
#include <Arduino.h>
#include <U8g2lib.h>

#ifndef CLIONPROJECTS_OLED_VARIABLES_H
#define CLIONPROJECTS_OLED_VARIABLES_H

extern U8G2_SH1107_PIMORONI_128X128_F_HW_I2C u8g2;

extern const unsigned long BLINK_INTERVAL;
extern const unsigned long WATCH_LEFT_INTERVAL;
extern const unsigned long WATCH_RIGHT_INTERVAL;
extern const unsigned long OBSERVE_INTERVAL;
extern const unsigned long SLEEP_INTERVAL;
extern const unsigned long SLEEP_DURATION;

extern unsigned long lastBlink;
extern unsigned long lastWatchLeft;
extern unsigned long lastWatchRight;
extern unsigned long lastObserve;
extern unsigned long lastSleep;
extern unsigned long sleepStartedAt;

extern bool asleep;

#endif //CLIONPROJECTS_OLED_VARIABLES_H

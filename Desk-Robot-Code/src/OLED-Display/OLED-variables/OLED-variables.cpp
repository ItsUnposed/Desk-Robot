#include "OLED-variables.h"

U8G2_SH1107_PIMORONI_128X128_F_HW_I2C u8g2(U8G2_R0, U8X8_PIN_NONE);

const unsigned long BLINK_INTERVAL       = 30UL * 1000UL;         // ca. 30 Sekunden
const unsigned long WATCH_LEFT_INTERVAL  = 10UL * 60UL * 500UL;  // 5 Minuten
const unsigned long WATCH_RIGHT_INTERVAL = 10UL * 60UL * 500UL;  // 5 Minuten
const unsigned long OBSERVE_INTERVAL     = 10UL * 60UL * 500UL;  // 5 Minuten

unsigned long lastBlink;
unsigned long lastWatchLeft;
unsigned long lastWatchRight;
unsigned long lastObserve;

bool asleep = false;


#include <U8g2lib.h>
#include <Wire.h>

U8G2_SH1107_PIMORONI_128X128_F_HW_I2C u8g2(U8G2_R0, U8X8_PIN_NONE);

const unsigned long BLINK_INTERVAL       = 30UL * 1000UL;         // ca. 30 Sekunden
const unsigned long WATCH_LEFT_INTERVAL  = 10UL * 60UL * 1000UL;  // 10 Minuten
const unsigned long WATCH_RIGHT_INTERVAL = 10UL * 60UL * 1000UL;  // 10 Minuten
const unsigned long OBSERVE_INTERVAL     = 10UL * 60UL * 1000UL;  // 10 Minuten
const unsigned long SLEEP_INTERVAL       = 60UL * 60UL * 1000UL;  // genau 1 Stunde
const unsigned long SLEEP_DURATION       = 10UL * 1000UL;         // Annahme: 10 Sekunden geschlossene Augen, siehe Hinweis oben

unsigned long lastBlink;
unsigned long lastWatchLeft;
unsigned long lastWatchRight;
unsigned long lastObserve;
unsigned long lastSleep;
unsigned long sleepStartedAt;

bool asleep = false;

void setup() {
  Serial.begin(115200);
  delay(1000);
  if (!u8g2.begin()) {
    Serial.println("Display Error!");
    while (1);
  }

  u8g2.setDisplayRotation(U8G2_R0);
  u8g2.setFont(u8g2_font_ncenB08_tr);
  u8g2.setDrawColor(1);

  unsigned long now = millis();
  lastBlink      = now;
  lastWatchLeft  = now;
  lastWatchRight = now - 3UL * 60UL * 1000UL; // 3 Minuten Versatz
  lastObserve    = now - 6UL * 60UL * 1000UL; // 6 Minuten Versatz
  lastSleep      = now;

  normal(); 
}

void loop() {
  unsigned long now = millis();

  // Solange die Augen geschlossen sind, keine anderen Animationen starten
  if (asleep) {
    if (now - sleepStartedAt >= SLEEP_DURATION) {
      wakeUp();
      asleep = false;
    }
    return;
  }

  // Schlafen hat Vorrang vor allen anderen Animationen
  if (now - lastSleep >= SLEEP_INTERVAL) {
    sleep();
    lastSleep = now;
    sleepStartedAt = now;
    asleep = true;
    return;
  }

  if (now - lastBlink >= BLINK_INTERVAL) {
    blink();
    lastBlink = now;
  }

  if (now - lastWatchLeft >= WATCH_LEFT_INTERVAL) {
    watchLeft();
    lastWatchLeft = now;
  }

  if (now - lastWatchRight >= WATCH_RIGHT_INTERVAL) {
    watchRight();
    lastWatchRight = now;
  }

  if (now - lastObserve >= OBSERVE_INTERVAL) {
    observe();
    lastObserve = now;
  }
}

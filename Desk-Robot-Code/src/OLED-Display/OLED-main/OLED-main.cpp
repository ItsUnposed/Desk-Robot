#include "OLED-main.h"

void chooseFace()
{
    unsigned long now = millis();

    // Solange die Augen geschlossen sind, keine anderen Animationen starten
    if (toggleTime) {
        if (asleep) {
            if (giveRes() > 200) {
                wakeUp();
                asleep = false;
            }
            return;
        }

        // Schlafen hat Vorrang vor allen anderen Animationen
        if (giveRes() < 200) {
            sleep();
            asleep = true;
            return;
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

        if (now - lastBlink >= BLINK_INTERVAL) {
            blink();
            lastBlink = now;
        }
    }
}

void OLEDsetup()
{
    while (!u8g2.begin());

    u8g2.setDisplayRotation(U8G2_R0);
    u8g2.setFont(u8g2_font_ncenB08_tr);
    u8g2.setDrawColor(1);

    unsigned long now = millis();
    lastBlink      = now;
    lastWatchLeft  = now;
    lastWatchRight = now - 2UL * 60UL * 1000UL; // 2 Minuten Versatz
    lastObserve    = now - 4UL * 60UL * 1000UL; // 4 Minuten Versatz
    normal();
}
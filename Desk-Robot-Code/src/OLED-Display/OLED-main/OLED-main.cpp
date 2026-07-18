#include "OLED-main.h"
#include "Sensors/Photoresistor/photoresistor.h"

void chooseFace()
{
    unsigned long now = millis();

    // Solange die Augen geschlossen sind, keine anderen Animationen starten
    while (asleep) {
        if (giveRes() > 1500) {
            wakeUp();
            asleep = false;
        }
    }

    // Schlafen hat Vorrang vor allen anderen Animationen
    if (giveRes() < 500) {
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

void OLEDsetup()
{
    while (!u8g2.begin());

    u8g2.setDisplayRotation(U8G2_R0);
    u8g2.setFont(u8g2_font_ncenB08_tr);
    u8g2.setDrawColor(1);

    unsigned long now = millis();
    lastBlink      = now;
    lastWatchLeft  = now;
    lastWatchRight = now - 3UL * 60UL * 1000UL; // 3 Minuten Versatz
    lastObserve    = now - 6UL * 60UL * 1000UL; // 6 Minuten Versatz
    normal();
}
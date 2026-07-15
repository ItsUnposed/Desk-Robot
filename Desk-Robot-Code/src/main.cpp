#include <Arduino.h>
#include "OLED-Display/OLED-main/OLED-main.h"

void setup() {
    Serial.begin(115200);
    delay(1000);
    OLEDsetup();
}

void loop() {
    chooseFace();
}
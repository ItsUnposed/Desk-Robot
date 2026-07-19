#include <Arduino.h>
#include "OLED-Display/OLED-main/OLED-main.h"
#include "Sensors/Photoresistor/photoresistor.h"
#include "Connection/connection.h"

void setup() {
    Serial.begin(115200);
    delay(1000);
    OLEDsetup();
    connectionSetup();
    Serial.println(WiFi.macAddress());
}

void loop() {
    chooseFace();
    // printRes();
}
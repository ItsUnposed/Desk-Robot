#include "photoresistor.h"

void printRes() {
    int resistance = analogRead(32);
    Serial.println(resistance);
}

int giveRes() {
    int resistance = analogRead(32);
    return resistance;
}
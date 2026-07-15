#include <U8g2lib.h>
#include <Wire.h>

void setup() {
  Serial.begin(115200);
  delay(1000);
  OLEDsetup();
}

void loop() {
  chooseFace();
}

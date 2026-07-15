#include <U8g2lib.h>
#include <Wire.h>

U8G2_SH1107_PIMORONI_128X128_F_HW_I2C u8g2(U8G2_R0, U8X8_PIN_NONE);

void setup() {
  Serial.begin(115200);
  delay(1000);
  if (!u8g2.begin()) {
    Serial.println("Display Error!");
    while (1);
  }

  u8g2.setDisplayRotation(U8G2_R1);
  u8g2.setFont(u8g2_font_ncenB08_tr);
  u8g2.setDrawColor(1);
}

void loop()
{
  normal();
  observe();
  delay(1000);
}


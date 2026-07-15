
void normal()
{
  u8g2.clearBuffer();
  u8g2.drawRBox(17, 40, 38, 38, 3);
  u8g2.drawRBox(74, 40, 38, 38, 3);
  u8g2.sendBuffer();
}

void blink()
{
  blinkClose();
  delay(1000);
  blinkOpen();
}

void sleep()
{
  blinkClose();
  for (int i = 0 ; i < 3; i++)
  {
    u8g2.drawStr(90 + 10 * i, 44 - 10 * i, "Z");
    u8g2.sendBuffer();
    delay(500);
  }
}

void wakeUp()
{
  u8g2.setDrawColor(2);
  for (int i = 0 ; i < 3; i++)
  {
    u8g2.drawStr(110 - 10 * i, 24 + 10 * i, "Z");
    u8g2.sendBuffer();
    delay(500);
  }
  u8g2.setDrawColor(1);
  blinkOpen();
}

void watchLeft()
{
  for (int i = 0; i < 15; i++)
  {
    u8g2.clearBuffer();
    u8g2.drawRBox(17 - i, 40, 38, 38, 3);
    u8g2.drawRBox(74 - 1.5* i, 40, 38, 38, 3);
    delay(2);
    u8g2.sendBuffer();
  }
  delay(1000);
  for (int i = 0; i < 15; i++)
  {
    u8g2.clearBuffer();
    u8g2.drawRBox(3 + i, 40, 38, 38, 3);
    u8g2.drawRBox(53 + 1.5* i, 40, 38, 38, 3);
    delay(2);
    u8g2.sendBuffer();
  }
}

void watchRight()
{
  for (int i = 0; i < 15; i++)
  {
    u8g2.clearBuffer();
    u8g2.drawRBox(17 + 1.5 * i, 40, 38, 38, 3);
    u8g2.drawRBox(74 + i, 40, 38, 38, 3);
    delay(2);
    u8g2.sendBuffer();
  }
  delay(1000);
  for (int i = 0; i < 15; i++)
  {
    u8g2.clearBuffer();
    u8g2.drawRBox(38 - 1.5*i, 40, 38, 38, 3);
    u8g2.drawRBox(88 - i, 40, 38, 38, 3);
    delay(2);
    u8g2.sendBuffer();
  }
}

void observe()
{
  for (int i = 0; i < 15; i++)
  {
    u8g2.clearBuffer();
    u8g2.drawRBox(17 - i, 40 + 2*i, 38, 38, 3);
    u8g2.drawRBox(74 - 1.5* i, 40 + 2*i, 38, 38, 3);
    delay(2);
    u8g2.sendBuffer();
  }

  delay(1000);

  for (int i = 0; i < 15; i++)
  {
    u8g2.clearBuffer();
    u8g2.drawRBox(3 + 2*i, 68, 38, 38, 3);
    u8g2.drawRBox(53 + 2*i, 68, 38, 38, 3);
    delay(2);
    u8g2.sendBuffer();
  }

  delay(1000);

  for (int i = 0; i < 15; i++)
  {
    u8g2.clearBuffer();
    u8g2.drawRBox(31 - i, 68 - 2*i, 38, 38, 3);
    u8g2.drawRBox(81 - 0.5*i, 68 - 2*i, 38, 38, 3);
    delay(2);
    u8g2.sendBuffer();
  }

}

void blinkClose()
{
  for (int i = 0; i < 15; i++)
  {
    u8g2.clearBuffer();
    u8g2.drawRBox(17, 40 + i, 38, 38 - 2*i, 3);
    u8g2.drawRBox(74, 40 + i, 38, 38 - 2*i, 3);
    delay(2);
    u8g2.sendBuffer();
  }
}

void blinkOpen()
{
  for (int i = 0; i < 15; i++)
  {
    u8g2.clearBuffer();
    u8g2.drawRBox(17, 54 - i, 38, 10 + 2*i, 3);
    u8g2.drawRBox(74, 54 - i, 38, 10 + 2*i, 3);
    delay(1);
    u8g2.sendBuffer();
  }
}


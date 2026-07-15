#pragma once
#include <Arduino.h>
#include <U8g2lib.h>
#include "../OLED-variables/OLED-variables.h"

#ifndef CLIONPROJECTS_FACES_H
#define CLIONPROJECTS_FACES_H

void normal();
void blink();
void sleep();
void wakeUp();
void watchLeft();
void watchRight();
void observe();
void blinkClose();
void blinkOpen();

#endif //CLIONPROJECTS_FACES_H

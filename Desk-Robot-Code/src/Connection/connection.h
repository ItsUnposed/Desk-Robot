#pragma once
#include "Arduino.h"
#include "OLED-Display/OLED-faces/faces.h"
#include <esp_now.h>
#include <WiFi.h>

#ifndef DESK_ROBOT_CODE_CONNECTION_H
#define DESK_ROBOT_CODE_CONNECTION_H

struct Payload {
    int state_button1;
    int state_button2;
    int state_button3;
    int state_button4;
    int state_button5;
    int state_button6;
    int state_button7;
    int state_button8;
    int state_button9;

    int state_button10;
    uint8_t status;
};

extern int prev_button1, prev_button2, prev_button3, prev_button4, prev_button5,
prev_button6, prev_button7, prev_button8 , prev_button9, prev_button10;
extern bool toggleDeck;

extern Payload data;

void OnDataRecv(const uint8_t * mac, const uint8_t *incomingData, int len);
void connectionSetup();

#endif //DESK_ROBOT_CODE_CONNECTION_H

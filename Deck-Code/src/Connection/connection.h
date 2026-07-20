#pragma once
#include "Arduino.h"
#include "Variables/variables.h"
#include <esp_now.h>
#include <WiFi.h>

#ifndef DECK_CODE_CONNECTION_H
#define DECK_CODE_CONNECTION_H

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

extern uint8_t broadcastAddress[6];
extern Payload data;
extern esp_now_peer_info_t peerInfo;

void OnDataSent(const uint8_t *mac_addr, esp_now_send_status_t status);
void connectionSetup();
void connectionLoop();

#endif //DECK_CODE_CONNECTION_H

#include "connection.h"
#include "Variables/variables.h"

uint8_t broadcastAddress[] = {0xD4, 0xE9, 0xF4, 0x77, 0xFE, 0x60};
Payload data;
esp_now_peer_info_t peerInfo;

void OnDataSent(const uint8_t *mac_addr, esp_now_send_status_t status) {
    Serial.println(status == ESP_NOW_SEND_SUCCESS ? "Gesendet!" : "Fehler");
}
void connectionSetup() {
    Serial.begin(115200);
    pinMode(button1, INPUT);
    pinMode(button2, INPUT);
    pinMode(button3, INPUT);
    pinMode(button4, INPUT);
    pinMode(button5, INPUT);
    pinMode(button6, INPUT);
    pinMode(button7, INPUT);
    pinMode(button8, INPUT);
    pinMode(button9, INPUT);

    pinMode(button10, INPUT);
    WiFi.mode(WIFI_STA);
    if (esp_now_init() != ESP_OK) {
        Serial.println("ESP-NOW Fehler");
        return;
    }
    esp_now_register_send_cb(OnDataSent);
    memcpy(peerInfo.peer_addr, broadcastAddress, 6);
    peerInfo.channel = 0;
    peerInfo.encrypt = false;
    esp_now_add_peer(&peerInfo);
}
void connectionLoop() {
    data.state_button1 = digitalRead(button1);
    data.state_button2 = digitalRead(button2);
    data.state_button3 = digitalRead(button3);
    data.state_button4 = digitalRead(button4);
    data.state_button5 = digitalRead(button5);
    data.state_button6 = digitalRead(button6);
    data.state_button7 = digitalRead(button7);
    data.state_button8 = digitalRead(button8);
    data.state_button9 = digitalRead(button9);
    data.state_button10 = digitalRead(button10);
    esp_now_send(broadcastAddress, (uint8_t *) &data, sizeof(data));
    delay(20); // 50 Hz
}
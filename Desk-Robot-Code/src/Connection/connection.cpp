#include "connection.h"

Payload data;
int prev_button1, prev_button2, prev_button3, prev_button4, prev_button5 = 0;

void OnDataRecv(const uint8_t * mac, const uint8_t *incomingData, int len) {
    memcpy(&data, incomingData, sizeof(data));
    Serial.print("Bytes empfangen: "); Serial.println(len);
    Serial.print("Button1 "); Serial.print(data.state_button1);
    Serial.print(" | Button2 "); Serial.print(data.state_button2);
    Serial.print(" | Button3 "); Serial.print(data.state_button3);
    Serial.print(" | Button4 "); Serial.print(data.state_button4);
    Serial.print(" | Button5 "); Serial.println(data.state_button5);
    if (data.state_button1 && prev_button1 != data.state_button1) {
        prev_button1 = data.state_button1;
        blink();
    }
    else if (data.state_button2 && prev_button2 != data.state_button2) {
        prev_button2 = data.state_button2;
        watchLeft();
    }
    else if (data.state_button3 && prev_button3 != data.state_button3) {
        prev_button3 = data.state_button3;
        watchRight();
    }
    else if (data.state_button4 && prev_button4 != data.state_button4) {
        prev_button4 = data.state_button4;
        observe();
    }
    else if (data.state_button5 && prev_button5 != data.state_button5) {
        prev_button5 = data.state_button5;
        sleep();
        delay(10000);
        wakeUp();
    }

    prev_button1 = data.state_button1;
    prev_button2 = data.state_button2;
    prev_button3 = data.state_button3;
    prev_button4 = data.state_button4;
    prev_button5 = data.state_button5;
}
void connectionSetup() {
    Serial.begin(115200);
    WiFi.mode(WIFI_STA); // WLAN im Stations-Modus starten
    if (esp_now_init() != ESP_OK) {
        Serial.println("Fehler beim Starten von ESP-NOW");
        return;
    }
    esp_now_register_recv_cb(OnDataRecv);
}

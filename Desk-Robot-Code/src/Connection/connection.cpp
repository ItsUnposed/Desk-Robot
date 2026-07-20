#include "connection.h"

Payload data;
int prev_button1, prev_button2, prev_button3, prev_button4, prev_button5,
prev_button6, prev_button7, prev_button8, prev_button9, prev_button10= 0;
bool toggleDeck = false;

void OnDataRecv(const uint8_t * mac, const uint8_t *incomingData, int len) {
    memcpy(&data, incomingData, sizeof(data));
    Serial.print("Bytes empfangen: "); Serial.println(len);
    Serial.print("Button1 "); Serial.print(data.state_button1);
    Serial.print(" | Button2 "); Serial.print(data.state_button2);
    Serial.print(" | Button3 "); Serial.print(data.state_button3);
    Serial.print(" | Button4 "); Serial.print(data.state_button4);
    Serial.print(" | Button5 "); Serial.print(data.state_button5);
    Serial.println();
    Serial.print("Button6 "); Serial.print(data.state_button6);
    Serial.print(" | Button7 "); Serial.print(data.state_button7);
    Serial.print(" | Button8 "); Serial.print(data.state_button8);
    Serial.print(" | Button9 "); Serial.print(data.state_button9);
    Serial.print(" | Button10 "); Serial.print(data.state_button10);
    Serial.println();

    if (toggleDeck) {
        if (data.state_button1 && prev_button1 != data.state_button1 ) {
            prev_button1 = data.state_button1;
            normal();
        }
        else if (data.state_button2 && prev_button2 != data.state_button2) {
            prev_button2 = data.state_button2;
            blink();
        }
        else if (data.state_button3 && prev_button3 != data.state_button3 ) {
            prev_button3 = data.state_button3;
            watchLeft();
        }
        else if (data.state_button4 && prev_button4 != data.state_button4) {
            prev_button4 = data.state_button4;
            watchRight();
        }
        else if (data.state_button5 && prev_button5 != data.state_button5) {
            prev_button5 = data.state_button5;
            observe();
        }
        else if (data.state_button6 && prev_button6 != data.state_button6) {
            prev_button6 = data.state_button6;
            sleep();
        }
        else if (data.state_button7 && prev_button7 != data.state_button7) {
            prev_button7 = data.state_button7;
            if (asleep) {
                wakeUp();
            }
        }
        else if (data.state_button8 && prev_button8 != data.state_button8) {
            prev_button8 = data.state_button8;
        }
        else if (data.state_button9 && prev_button9 != data.state_button9) {
            prev_button9 = data.state_button9;
        }
    }
    else if (data.state_button10 && prev_button10 != data.state_button10) {
        prev_button10 = data.state_button10;
        toggleDeck = !toggleDeck;
        toggleTime = !toggleTime;
    }

    prev_button1 = data.state_button1;
    prev_button2 = data.state_button2;
    prev_button3 = data.state_button3;
    prev_button4 = data.state_button4;
    prev_button5 = data.state_button5;
    prev_button6 = data.state_button6;
    prev_button7 = data.state_button7;
    prev_button8 = data.state_button8;
    prev_button9 = data.state_button9;
    prev_button10 = data.state_button10;
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

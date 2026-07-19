#include "Arduino.h"
#include "Connection/connection.h"
#include "Variables/variables.h"


void setup() {
    connectionSetup();
}

void loop() {
    connectionLoop();
}
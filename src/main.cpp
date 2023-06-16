#include <Arduino.h>

#define LED_RGB_RED 11
#define LED_RGB_GREEN 10
#define LED_RGB_BLUE 9

#define BUTTON_RGB_RED 7
#define BUTTON_RGB_GREEN 6
#define BUTTON_RGB_BLUE 5

void setup() {

    pinMode(LED_RGB_RED, OUTPUT);
    pinMode(LED_RGB_GREEN, OUTPUT);
    pinMode(LED_RGB_BLUE, OUTPUT);

    pinMode(BUTTON_RGB_RED, INPUT_PULLUP);
    pinMode(BUTTON_RGB_GREEN, INPUT_PULLUP);
    pinMode(BUTTON_RGB_BLUE, INPUT_PULLUP);

}

const long buttonStrokeDelayMs = 400;
unsigned long buttonRedLastMillis = 0;
unsigned long buttonGreenLastMillis = 0;
unsigned long buttonBlueLastMillis = 0;

void loop() {

    unsigned long currentMillis = millis();

    if (digitalRead(BUTTON_RGB_RED) == LOW) {
        if (currentMillis - buttonRedLastMillis >= buttonStrokeDelayMs) {
            digitalWrite(LED_RGB_RED, !digitalRead(LED_RGB_RED));
            buttonRedLastMillis = currentMillis;
        }
    }

    if (digitalRead(BUTTON_RGB_GREEN) == LOW) {
        if (currentMillis - buttonGreenLastMillis >= buttonStrokeDelayMs) {
            digitalWrite(LED_RGB_GREEN, !digitalRead(LED_RGB_GREEN));
            buttonGreenLastMillis = currentMillis;
        }
    }

    if (digitalRead(BUTTON_RGB_BLUE) == LOW) {
        if (currentMillis - buttonBlueLastMillis >= buttonStrokeDelayMs) {
            digitalWrite(LED_RGB_BLUE, !digitalRead(LED_RGB_BLUE));
            buttonBlueLastMillis = currentMillis;
        }
    }

}
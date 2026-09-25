// Exercise 4: Light sensor -> LED band (exactly one LED ON)

#include "Arduino.h"

#define RED_LED_PIN    26
#define GREEN_LED_PIN  27
#define BLUE_LED_PIN   14
#define YELLOW_LED_PIN 12
#define LIGHT_PIN      33

#define READ_INTERVAL_MS 500

const int ledPins[4]    = { BLUE_LED_PIN, GREEN_LED_PIN, YELLOW_LED_PIN, RED_LED_PIN };
const char *bandNames[4] = { "BLUE", "GREEN", "YELLOW", "RED" };

unsigned long lastReadTime = 0;

/****************************************************/
void setup(void)
{
    Serial.begin(115200);
    analogReadResolution(12);   // 0..4095

    for (int i = 0; i < 4; i++) {
        pinMode(ledPins[i], OUTPUT);
        digitalWrite(ledPins[i], LOW);
    }
}

/****************************************************/
void loop(void)
{
    if (millis() - lastReadTime >= READ_INTERVAL_MS) {
        lastReadTime = millis();

        int raw = analogRead(LIGHT_PIN);
        int band = raw / 1024;          // 0-1023 -> 0, ..., 3072-4095 -> 3
        if (band > 3) band = 3;

        for (int i = 0; i < 4; i++) {
            digitalWrite(ledPins[i], i == band ? HIGH : LOW);
        }

        Serial.print("band=");
        Serial.println(bandNames[band]);
    }
}

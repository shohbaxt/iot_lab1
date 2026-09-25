// Exercise 3: Read light sensor every 500 ms

#include "Arduino.h"

#define LIGHT_PIN 33

#define READ_INTERVAL_MS 500

unsigned long lastReadTime = 0;

/****************************************************/
void setup(void)
{
    Serial.begin(115200);
    analogReadResolution(12);   // 0..4095
}

/****************************************************/
void loop(void)
{
    if (millis() - lastReadTime >= READ_INTERVAL_MS) {
        lastReadTime = millis();

        int raw = analogRead(LIGHT_PIN);
        Serial.print("raw=");
        Serial.println(raw);
    }
}

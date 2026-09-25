// Exercise 5: Snapshot light sensor on button press

#include "Arduino.h"

#define YELLOW_LED_PIN 12
#define BUTTON_PIN     25   // active high (external pull-down)
#define LIGHT_PIN      33

#define DEBOUNCE_MS 50
#define FLASH_MS    100

int lastReading = LOW;
int stableState = LOW;
unsigned long lastChangeTime = 0;

/****************************************************/
void setup(void)
{
    Serial.begin(115200);
    analogReadResolution(12);   // 0..4095
    pinMode(YELLOW_LED_PIN, OUTPUT);
    pinMode(BUTTON_PIN, INPUT);
    digitalWrite(YELLOW_LED_PIN, LOW);
}

/****************************************************/
void loop(void)
{
    int reading = digitalRead(BUTTON_PIN);

    if (reading != lastReading) {
        lastChangeTime = millis();
        lastReading = reading;
    }

    if ((millis() - lastChangeTime) > DEBOUNCE_MS && reading != stableState) {
        stableState = reading;

        // Take snapshot on press (rising edge)
        if (stableState == HIGH) {
            int raw = analogRead(LIGHT_PIN);
            Serial.print("snapshot=");
            Serial.println(raw);

            digitalWrite(YELLOW_LED_PIN, HIGH);
            delay(FLASH_MS);
            digitalWrite(YELLOW_LED_PIN, LOW);
        }
    }
}

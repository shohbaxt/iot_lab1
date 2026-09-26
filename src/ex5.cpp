#include "Arduino.h"

#define YELLOW_LED_PIN 12
#define BUTTON_PIN     25
#define LIGHT_PIN      33

int lastButton = LOW;

void setup(void)
{
    Serial.begin(115200);
    pinMode(YELLOW_LED_PIN, OUTPUT);
    pinMode(BUTTON_PIN, INPUT);
}

void loop(void)
{
    int button = digitalRead(BUTTON_PIN);

    if (button == HIGH && lastButton == LOW) {
        int raw = analogRead(LIGHT_PIN);
        Serial.print("snapshot=");
        Serial.println(raw);

        digitalWrite(YELLOW_LED_PIN, HIGH);
        delay(100);
        digitalWrite(YELLOW_LED_PIN, LOW);
    }

    lastButton = button;
    delay(50);
}

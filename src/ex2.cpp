#include "Arduino.h"

#define GREEN_LED_PIN 27
#define BUTTON_PIN    25

int lastButton = LOW;
int greenOn = 0;

void setup(void)
{
    Serial.begin(115200);
    pinMode(GREEN_LED_PIN, OUTPUT);
    pinMode(BUTTON_PIN, INPUT);
}

void loop(void)
{
    int button = digitalRead(BUTTON_PIN);

    if (button == HIGH && lastButton == LOW) {
        if (greenOn == 0) {
            greenOn = 1;
            digitalWrite(GREEN_LED_PIN, HIGH);
            Serial.println("GREEN=1");
        } else {
            greenOn = 0;
            digitalWrite(GREEN_LED_PIN, LOW);
            Serial.println("GREEN=0");
        }
    }

    lastButton = button;
    delay(50);
}

// Exercise 1: Blink RED LED (500 ms ON / 500 ms OFF)

#include "Arduino.h"

#define RED_LED_PIN 26

/****************************************************/
void setup(void)
{
    Serial.begin(115200);
    pinMode(RED_LED_PIN, OUTPUT);
}

/****************************************************/
void loop(void)
{
    digitalWrite(RED_LED_PIN, HIGH);
    Serial.println("RED ON");
    delay(500);

    digitalWrite(RED_LED_PIN, LOW);
    Serial.println("RED OFF");
    delay(500);
}

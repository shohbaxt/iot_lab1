#include "Arduino.h"

#define LIGHT_PIN 33

void setup(void)
{
    Serial.begin(115200);
}

void loop(void)
{
    int raw = analogRead(LIGHT_PIN);

    Serial.print("raw=");
    Serial.println(raw);

    delay(500);
}

#include <Arduino.h>
#include "Flasher.h"

Flasher::Flasher(int ledPin, int onTime, int offTime) {
    _ledPin = ledPin;
    _onTime = onTime;
    _offTime = offTime;
    
    int ledState;
    unsigned long prevMillis;
}

void Flasher::begin() {
    pinMode(_ledPin, OUTPUT);
    ledState = LOW;
    prevMillis = 0;
}

void Flasher::run() {
    unsigned long currMillis = millis();

    if (ledState == HIGH && currMillis - prevMillis >= _onTime)
    {
        ledState = LOW;
        prevMillis = currMillis;
        digitalWrite(_ledPin, ledState);
    }
    else if (ledState == LOW && currMillis - prevMillis >= _offTime)
    {
        ledState = HIGH;
        prevMillis = currMillis;
        digitalWrite(_ledPin, ledState);
    }
}
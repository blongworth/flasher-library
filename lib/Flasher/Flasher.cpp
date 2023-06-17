/*!
 * @file Flasher.cpp
 *
 * @mainpage LED flasher Library
 *
 * @section intro_sec Introduction
 *
 * This is a library for flashing LEDs without blocking with a
 * variable duty cycle
 *
 * @section author Author
 *
 * Written by Brett Longworth
 *
 * @section license License
 *
 * BSD license, all text above must be included in any redistribution
 */

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

void Flasher::update(int onTime, int offTime) {
    _onTime = onTime;
    _offTime = offTime;
}
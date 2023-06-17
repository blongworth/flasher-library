/*!
 * @file Flasher.h
 *
 * This is a library for flashing LEDs without blocking with a
 * variable duty cycle
 *
 * Written by Brett Longworth
 *
 * BSD license, all text above must be included in any redistribution
 */
#ifndef Flasher_h
#define Flasher_h

#include <Arduino.h>

class Flasher
{
private:
    int _ledPin;
    int _onTime;
    int _offTime;
    int ledState;
    unsigned long prevMillis;
public:
    Flasher(int ledPin, int onTime, int offTime);
    void begin();
    void run();
    void update(int onTime, int offTime);
};

#endif
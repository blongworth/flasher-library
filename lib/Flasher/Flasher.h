
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
};

#endif
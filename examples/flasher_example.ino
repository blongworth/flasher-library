/*!
 * @file Flasher_example.cpp
 *
 * Use example for Flasher library. Set up a flasher, run it, and 
 * update it's period based on a timer
 *
 * Written by Brett Longworth
 *
 * BSD license, all text above must be included in any redistribution
 */

#include <Arduino.h>
#include "Flasher.h"

int onTime = 100;
int offTime = 900;
elapsedMillis updateTimer; // elapsed millis is part of teensyduino framework

// create a Flasher object
Flasher flasher(LED_BUILTIN, onTime, offTime);

void setup() {
  // start flasher object
  flasher.begin();
  updateTimer = 0;
}

void loop() {
  // updates led status if needed
  flasher.run();
  
  // demonstrate changing pattern of a running flasher
  if (updateTimer > 5000) {
    onTime = offTime;
    offTime = 1000 - onTime;
    flasher.update(onTime, offTime); // flashers can be updated
    updateTimer = 0;
  }
}

#include <Arduino.h>
#include "Flasher.h"

Flasher flasher(LED_BUILTIN, 100, 900);
elapsedMillis updateTimer;

void setup() {
  flasher.begin();
  updateTimer = 0;
}

void loop() {
  flasher.run();
  if (updateTimer > 5000) {
    flasher.update(900, 100);
    updateTimer = 0;
  }
}

#include <Arduino.h>
#include "Flasher.h"

Flasher flasher(LED_BUILTIN, 100, 900);

void setup() {
  flasher.begin();
}

void loop() {
  flasher.run();
}

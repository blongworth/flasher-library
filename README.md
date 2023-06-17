# Flasher Library

This is a library to flash LEDs in a non-blocking way.

The library allows creation of Flasher objects, which take a pin
to flash, and a duty cycle, in the form of on-time and off-time.

The run function checks whether it's time to do something with the
LED, and should be run once per loop. These calls are non-blocking.
The update function may be used to change the blink rate of a running
Flasher object.

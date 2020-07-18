#include "Arduino.h"

// Teensy 2.0 has the LED on pin 11
// Teensy++ 2.0 has the LED on pin 6
// Teensy 3.x / Teensy LC have the LED on pin 13
#ifndef LED_BUILTIN
#define LED_BUILTIN 13
#endif


const int ledPin = LED_BUILTIN;
const int steps = 4;
const int blipDuration = 20;
const int delayFactor = 5;
const int delayDuration = delayFactor * steps * blipDuration;


// the setup() method runs once, when the sketch starts

void blip() {
  digitalWrite(ledPin, HIGH);   // set the LED on
  delay(blipDuration);          // wait for a second
  digitalWrite(ledPin, LOW);    // set the LED off
}

void ratchet(int dur, int n) {
  int inter = (dur - n * blipDuration) / n;
  for (int i=0; i<n; i++) {
    blip();
    delay(inter);
  }
}

void setup() {
  pinMode(ledPin, OUTPUT);
}


void loop() {
  for(int i=1; i<=steps; i++) {
    ratchet(delayDuration, i);
    delay(delayDuration);
  }
}

#ifndef LED_FUNCTIONS_H
#define LED_FUNCTIONS_H

#include <Arduino.h>

// LED Pins (as required)
const int RED_PIN   = 7;
const int GREEN_PIN = 6;
const int BLUE_PIN  = 5;

// Initialize LED pins
void initLEDPins() {
  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);

  digitalWrite(RED_PIN, LOW);
  digitalWrite(GREEN_PIN, LOW);
  digitalWrite(BLUE_PIN, LOW);
}

// Toggle a specific LED
void toggleLED(int pin) {
  digitalWrite(pin, !digitalRead(pin));
}

#endif
#ifndef LED_FUNCTIONS_H
#define LED_FUNCTIONS_H

#include <Arduino.h>

const int RED_PIN = 8;
const int GREEN_PIN = 9;
const int BLUE_PIN = 10;

// Function to initialize pins
void initLEDPins() {
  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);
  
  // Start with all OFF
  digitalWrite(RED_PIN, LOW);
  digitalWrite(GREEN_PIN, LOW);
  digitalWrite(BLUE_PIN, LOW);
}

// Function to toggle a specific pin
void toggleLED(int pin) {
  int state = digitalRead(pin); // Read current state
  digitalWrite(pin, !state);    // Write the opposite state
}

// Function to turn ALL LEDs ON
void turnAllOn() {
  digitalWrite(RED_PIN, HIGH);
  digitalWrite(GREEN_PIN, HIGH);
  digitalWrite(BLUE_PIN, HIGH);
}

// Function to turn ALL LEDs OFF
void turnAllOff() {
  digitalWrite(RED_PIN, LOW);
  digitalWrite(GREEN_PIN, LOW);
  digitalWrite(BLUE_PIN, LOW);
}

#endif
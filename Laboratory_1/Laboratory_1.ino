// Running Light using pins 8–12
// Sequence: 12 → 11 → 10 → 9 → 8 (ON one by one), then OFF one by one

int leds[] = {12, 11, 10, 9, 8}; // LED pins
int numLeds = 5;

void setup() {
  // Set pins as output
  for (int i = 0; i < numLeds; i++) {
    pinMode(leds[i], OUTPUT);
  }
}

void loop() {
  // Turn ON LEDs one by one (12 → 8)
  for (int i = 0; i < numLeds; i++) {
    digitalWrite(leds[i], HIGH);
    delay(1000); // 1 second
  }

  // Turn OFF LEDs one by one (12 → 8)
  for (int i = 0; i < numLeds; i++) {
    digitalWrite(leds[i], LOW);
    delay(1000); // 1 second
  }
}
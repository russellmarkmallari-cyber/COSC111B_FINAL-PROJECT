#include "ledheader.h"

// Button pins (as required)
const int BTN_RED   = 12;
const int BTN_GREEN = 11;
const int BTN_BLUE  = 10;

// Previous button states (for edge detection)
bool prevRedBtn   = HIGH;
bool prevGreenBtn = HIGH;
bool prevBlueBtn  = HIGH;

void setup() {
  Serial.begin(9600);

  initLEDPins();

  pinMode(BTN_RED, INPUT_PULLUP);
  pinMode(BTN_GREEN, INPUT_PULLUP);
  pinMode(BTN_BLUE, INPUT_PULLUP);

  Serial.println("Arduino Ready (Bi-directional Serial)");
}

void loop() {

  /* ===============================
     OUTBOUND: Arduino → Python
     =============================== */
  bool currRedBtn   = digitalRead(BTN_RED);
  bool currGreenBtn = digitalRead(BTN_GREEN);
  bool currBlueBtn  = digitalRead(BTN_BLUE);

  // Button 1 → 'R'
  if (prevRedBtn == HIGH && currRedBtn == LOW) {
    Serial.println("R");
  }

  // Button 2 → 'G'
  if (prevGreenBtn == HIGH && currGreenBtn == LOW) {
    Serial.println("G");
  }

  // Button 3 → 'B'
  if (prevBlueBtn == HIGH && currBlueBtn == LOW) {
    Serial.println("B");
  }

  prevRedBtn   = currRedBtn;
  prevGreenBtn = currGreenBtn;
  prevBlueBtn  = currBlueBtn;

  /* ===============================
     INBOUND: Python → Arduino
     =============================== */
  if (Serial.available() > 0) {
    char cmd = Serial.read();
    cmd = toupper(cmd); // Case-insensitive

    switch (cmd) {
      case '1':
        toggleLED(RED_PIN);
        break;

      case '2':
        toggleLED(GREEN_PIN);
        break;

      case '3':
        toggleLED(BLUE_PIN);
        break;
    }
  }
}
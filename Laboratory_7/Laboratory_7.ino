#include "ledheader.h"

const int btn1 = 12;
const int btn2 = 11;
const int btn3 = 10;

void setup() {
  Serial.begin(9600);
  initLEDPins();
  pinMode(btn1, INPUT_PULLUP);
  pinMode(btn2, INPUT_PULLUP);
  pinMode(btn3, INPUT_PULLUP);
  Serial.println("Arduino Ready");
}

void loop() {
  if (Serial.available() > 0) {
    String cmd = Serial.readString();
    cmd.trim();
    cmd.toLowerCase();

    if (cmd == "1") {
      toggleLED(RED_PIN);
      Serial.println("Red LED Toggled");
    } else if (cmd == "2") {
      toggleLED(GREEN_PIN);
      Serial.println("GREEN LED Toggled");
    } else if (cmd == "3") {
      toggleLED(BLUE_PIN);
      Serial.println("BLUE LED Toggled");
    } else if (cmd == "on") {
      setOnLED();
      Serial.println("All LED On");
    } else if (cmd == "off") {
      setOffLED();
      Serial.println("All LED Off");
    }
    else {
      Serial.println("Invalid Command");
    }
  }

  if (digitalRead(btn1) == LOW) {
    Serial.println("Button 1 Pressed");
    delay(250); // debounce
  }

  if (digitalRead(btn2) == LOW) {
    toggleLED(GREEN_PIN);
    Serial.println("Button 2 Pressed");
    delay(250);
  }

  if (digitalRead(btn3) == LOW) {
    toggleLED(BLUE_PIN);
    Serial.println("Button 3 Pressed");
    delay(250);
  }
}
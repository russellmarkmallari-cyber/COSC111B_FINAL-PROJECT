#include "ledheader.h"

void setup() {
  Serial.begin(9600);
  initLEDPins();

  Serial.println("System Ready.");
  Serial.println("Enter Command (R, G, B, A, O):");
}

void loop() {

  // Buffer Checker
  if (Serial.available() > 0) {

    delay(5);  // Ensures all characters from input are complete

    String input = Serial.readString();  
    input.trim();                       

    // Removes extra characters
    if (input.length() != 1) {
      Serial.println("Error: Only ONE character allowed (R,G,B,A,O).");
      return;
    }

    // Input Verifier
    char choice = input.charAt(0);
    choice = toupper(choice); // Case-insensitive handling

    // Determines accepted input
    if (choice != 'R' && choice != 'G' && choice != 'B' && choice != 'A' && choice != 'O' && choice != 'V') {
      Serial.print("Error: Invalid Command '");
      Serial.print(choice);
      Serial.println("'");
      return;
    }


    switch (choice) {
      case 'R':
        toggleLED(RED_PIN);
        Serial.println("Red LED Toggled");
        break;

      case 'G':
        toggleLED(GREEN_PIN);
        Serial.println("Green LED Toggled");
        break;

      case 'B':
        toggleLED(BLUE_PIN);
        Serial.println("Blue LED Toggled");
        break;

      case 'A':
        turnAllOn();
        Serial.println("All LEDs ON");
        break;

      case 'O':
        turnAllOff();
        Serial.println("All LEDs OFF");
        break;
      
      case 'V':
        toggleLED(BLUE_PIN);
        toggleLED(RED_PIN);
        Serial.println("Blue and Red LED Turned ON");
        break;
    }
  }
}

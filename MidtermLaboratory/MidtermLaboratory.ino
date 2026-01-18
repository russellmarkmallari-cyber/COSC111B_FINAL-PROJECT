#define LDR_PIN A0
#define GREEN_LED 11
#define YELLOW_LED 12
#define RED_LED 13

int lowThreshold = 40;     
int highThreshold = 70;    
int lightPercent = 0;      
String mode = "Manual";   
String environment = "Normal"; 
String activeLED = "None";


void setup() {
  Serial.begin(9600);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(YELLOW_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);


  digitalWrite(GREEN_LED, LOW);
  digitalWrite(YELLOW_LED, LOW);
  digitalWrite(RED_LED, LOW);

  Serial.println("Smart Lighting System Initialized");
  Serial.println("System Ready. Defaulting to Manual Mode.");
  Serial.print("Initial Light Level: ");
  Serial.println(lightPercent);
  Serial.println();
}

void loop() {

  if (Serial.available()) {
    String command = Serial.readStringUntil('\n');
    command.trim();
    processCommand(command);
  }

  // --- 2. Update Logic Based on Mode ---
  if (mode == "Automatic") {
    int sensorValue = analogRead(LDR_PIN);
    lightPercent = map(sensorValue, 0, 1023, 0, 100);
    updateAutomaticLED(lightPercent);
  } else {
    updateManualLED(lightPercent);
}

  // --- 3. Display Data on Serial Monitor ---
  Serial.print("Light Intensity: ");
  Serial.print(lightPercent);
  Serial.print("% | Current Mode: ");
  Serial.print(mode);
  Serial.print(" | Active LED: ");
  Serial.print(activeLED);

  if (mode == "Automatic") {
    Serial.print(" | Environment: ");
    Serial.print(environment);
  }
  Serial.println();

  delay(1000);
}

void updateAutomaticLED(int lightVal) {
  if (lightVal <= 40) {
    environment = "Cloudy";
    digitalWrite(GREEN_LED, HIGH);
    digitalWrite(YELLOW_LED, LOW);
    digitalWrite(RED_LED, LOW);
    activeLED = "Green";
  } 
  else if (lightVal <= 70) {
    environment = "Normal";
    digitalWrite(GREEN_LED, LOW);
    digitalWrite(YELLOW_LED, HIGH);
    digitalWrite(RED_LED, LOW);
    activeLED = "Yellow";
  } 
  else {
    environment = "Clear";
    digitalWrite(GREEN_LED, LOW);
    digitalWrite(YELLOW_LED, LOW);
    digitalWrite(RED_LED, HIGH);
    activeLED = "Red";
  }
}

void updateManualLED(int lightVal) {
  if (lightVal <= lowThreshold) {
    digitalWrite(GREEN_LED, HIGH);
    digitalWrite(YELLOW_LED, LOW);
    digitalWrite(RED_LED, LOW);
    activeLED = "Green";
  } 
  else if (lightVal > lowThreshold && lightVal < highThreshold) {
    digitalWrite(GREEN_LED, LOW);
    digitalWrite(YELLOW_LED, HIGH);
    digitalWrite(RED_LED, LOW);
    activeLED = "Yellow";
  } 
  else {
    digitalWrite(GREEN_LED, LOW);
    digitalWrite(YELLOW_LED, LOW);
    digitalWrite(RED_LED, HIGH);
    activeLED = "Red";
  }
}

void processCommand(String cmd) {
  cmd.trim();
  cmd.toUpperCase();

  // --- Mode switching ---
  if (cmd == "MODE AUTO") {
    mode = "Automatic";
    Serial.println("\n> Switched to Automatic Mode");
  } 
  else if (cmd == "MODE MANUAL") {
    mode = "Manual";
    Serial.println("\n> Switched to Manual Mode");
  } 

  else if (cmd.startsWith("SET LIGHT ")) {
    if (mode == "Manual") {
      int newLight = cmd.substring(10).toInt();
      if (newLight >= 0 && newLight <= 100) {
        lightPercent = newLight;
        Serial.print("\n> Light intensity manually set to ");
        Serial.print(lightPercent);
        Serial.println("%");
        updateManualLED(lightPercent);  // Update LED immediately
        Serial.print("> Active LED: ");
        Serial.println(activeLED);
      } else {
        Serial.println("\n> Error: Light level must be 0–100");
      }
    } else {
      Serial.println("\n> Error: Can only set light level in Manual Mode");
    }
  }

  else if (cmd.startsWith("SET LOW ")) {
    int newLow = cmd.substring(.toInt();
    if (newLow >= 0 && newLow <= 100) {
      lowThreshold = newLow;
      Serial.print("\n> Low threshold updated to ");
      Serial.println(lowThreshold);

  
    if (mode == "Manual") {
      updateManualLED(lightPercent);
      Serial.print("> Current Light: ");
      Serial.print(lightPercent);
      Serial.print("% | Active LED: ");
      Serial.println(activeLED);
      }
    } else {
      Serial.println("\n> Error: Low threshold must be 0–100");
    }
  }

  else if (cmd.startsWith("SET HIGH ")) {
    int newHigh = cmd.substring(9).toInt();
    if (newHigh >= 0 && newHigh <= 100) {
      highThreshold = newHigh;
      Serial.print("\n> High threshold updated to ");
      Serial.println(highThreshold);

    if (mode == "Manual") {
      updateManualLED(lightPercent);
      Serial.print("> Current Light: ");
      Serial.print(lightPercent);
      Serial.print("% | Active LED: ");
      Serial.println(activeLED);
      }
    } else {
      Serial.println("\n> Error: High threshold must be 0–100");
    }
  }
}
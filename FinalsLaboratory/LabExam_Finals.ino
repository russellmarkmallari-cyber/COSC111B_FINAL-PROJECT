const int btn1 = 12;

int lastButtonState = HIGH;
int currentButtonState = HIGH;

void setup() {
  Serial.begin(9600);
  pinMode(btn1, INPUT_PULLUP);

  // Optional startup message (safe for Python if handled)
  Serial.println("Arduino Ready");
}

void loop() {
  currentButtonState = digitalRead(btn1);

  // Detect button press (HIGH → LOW)
  if (lastButtonState == HIGH && currentButtonState == LOW) {
    Serial.println("Button 1 Pressed");
    delay(200);  // debounce delay
  }

  lastButtonState = currentButtonState;
}
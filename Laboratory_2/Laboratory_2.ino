int leds[] = {12, 11, 10, 9, 8};
int numLeds = 5;

void setup() {
  int i = 0;
  while (i < numLeds) {
    pinMode(leds[i], OUTPUT);
    i++;
  }
}

void loop() {
  int i = 0;

  while (i < numLeds) {
    int brightness = 0;
    while (brightness <= 255) {
      analogWrite(leds[i], brightness);
      delay(10);
      brightness++;
    }
    delay(1000);
    i++;
  }

  i = 0;

  while (i < numLeds) {
    int brightness = 255;
    while (brightness >= 0) {
      analogWrite(leds[i], brightness);
      delay(10);
      brightness--;
    }
    delay(1000);
    i++;
  }
}
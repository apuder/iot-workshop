
const int PIN_LED = 6;
const int PIN_POTENTIOMETER = A0;

void setup() {
  pinMode(PIN_LED, OUTPUT);
}

void loop() {
  // val will be between 0 and 1023
  int val = analogRead(PIN_POTENTIOMETER);
  // (val / 4) will be between 0 and 255
  analogWrite(PIN_LED, val / 4);
}


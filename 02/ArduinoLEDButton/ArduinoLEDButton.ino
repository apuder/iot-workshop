
const int PIN_LED = 6;
const int PIN_BUTTON = 2;

void setup() {
  pinMode(PIN_LED, OUTPUT);
  pinMode(PIN_BUTTON, INPUT_PULLUP);
}

void loop() {
  bool pressed = digitalRead(PIN_BUTTON) == LOW;
  digitalWrite(PIN_LED, pressed ? HIGH : LOW);
}


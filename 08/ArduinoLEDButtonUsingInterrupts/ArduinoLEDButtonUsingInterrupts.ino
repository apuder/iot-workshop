
const int PIN_LED = 6;
const int PIN_BUTTON = 2;

void isr_button() {
  bool pressed = digitalRead(PIN_BUTTON) == LOW;
  digitalWrite(PIN_LED, pressed ? HIGH : LOW);
}

void setup() {
  pinMode(PIN_LED, OUTPUT);
  pinMode(PIN_BUTTON, INPUT_PULLUP);
  int irq = digitalPinToInterrupt(PIN_BUTTON);
  attachInterrupt(irq, isr_button, CHANGE);
}

void loop() { /* Do nothing */ }


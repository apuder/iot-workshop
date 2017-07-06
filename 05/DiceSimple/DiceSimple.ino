
#define PIN_SEGMENT_A 3
#define PIN_SEGMENT_B 2
#define PIN_SEGMENT_C 8
#define PIN_SEGMENT_D 7
#define PIN_SEGMENT_E 6
#define PIN_SEGMENT_F 5
#define PIN_SEGMENT_G 4

#define PIN_BUTTON 9

void show_1() {
  digitalWrite(PIN_SEGMENT_A, LOW);
  digitalWrite(PIN_SEGMENT_B, HIGH);
  digitalWrite(PIN_SEGMENT_C, HIGH);
  digitalWrite(PIN_SEGMENT_D, LOW);
  digitalWrite(PIN_SEGMENT_E, LOW);
  digitalWrite(PIN_SEGMENT_F, LOW);
  digitalWrite(PIN_SEGMENT_G, LOW);
}

void show_2() {
  digitalWrite(PIN_SEGMENT_A, HIGH);
  digitalWrite(PIN_SEGMENT_B, HIGH);
  digitalWrite(PIN_SEGMENT_C, LOW);
  digitalWrite(PIN_SEGMENT_D, HIGH);
  digitalWrite(PIN_SEGMENT_E, HIGH);
  digitalWrite(PIN_SEGMENT_F, LOW);
  digitalWrite(PIN_SEGMENT_G, HIGH);
}

void show_3() {
  digitalWrite(PIN_SEGMENT_A, HIGH);
  digitalWrite(PIN_SEGMENT_B, HIGH);
  digitalWrite(PIN_SEGMENT_C, HIGH);
  digitalWrite(PIN_SEGMENT_D, HIGH);
  digitalWrite(PIN_SEGMENT_E, LOW);
  digitalWrite(PIN_SEGMENT_F, LOW);
  digitalWrite(PIN_SEGMENT_G, HIGH);
}

void show_4() {
  digitalWrite(PIN_SEGMENT_A, LOW);
  digitalWrite(PIN_SEGMENT_B, HIGH);
  digitalWrite(PIN_SEGMENT_C, HIGH);
  digitalWrite(PIN_SEGMENT_D, LOW);
  digitalWrite(PIN_SEGMENT_E, LOW);
  digitalWrite(PIN_SEGMENT_F, HIGH);
  digitalWrite(PIN_SEGMENT_G, HIGH);
}

void show_5() {
  digitalWrite(PIN_SEGMENT_A, HIGH);
  digitalWrite(PIN_SEGMENT_B, LOW);
  digitalWrite(PIN_SEGMENT_C, HIGH);
  digitalWrite(PIN_SEGMENT_D, HIGH);
  digitalWrite(PIN_SEGMENT_E, LOW);
  digitalWrite(PIN_SEGMENT_F, HIGH);
  digitalWrite(PIN_SEGMENT_G, HIGH);
}

void show_6() {
  digitalWrite(PIN_SEGMENT_A, HIGH);
  digitalWrite(PIN_SEGMENT_B, LOW);
  digitalWrite(PIN_SEGMENT_C, HIGH);
  digitalWrite(PIN_SEGMENT_D, HIGH);
  digitalWrite(PIN_SEGMENT_E, HIGH);
  digitalWrite(PIN_SEGMENT_F, HIGH);
  digitalWrite(PIN_SEGMENT_G, HIGH);
}

void setup() {
  pinMode(PIN_SEGMENT_A, OUTPUT);
  pinMode(PIN_SEGMENT_B, OUTPUT);
  pinMode(PIN_SEGMENT_C, OUTPUT);
  pinMode(PIN_SEGMENT_D, OUTPUT);
  pinMode(PIN_SEGMENT_E, OUTPUT);
  pinMode(PIN_SEGMENT_F, OUTPUT);
  pinMode(PIN_SEGMENT_G, OUTPUT);
  pinMode(PIN_BUTTON, INPUT_PULLUP);
  show_1();
}

bool isButtonPressed() {
  return digitalRead(PIN_BUTTON) == LOW;
}

void loop() {
  if (!isButtonPressed()) {
    return;
  }
  show_1();
  if (!isButtonPressed()) {
    return;
  }
  show_2();
  if (!isButtonPressed()) {
    return;
  }
  show_3();
  if (!isButtonPressed()) {
    return;
  }
  show_4();
  if (!isButtonPressed()) {
    return;
  }
  show_5();
  if (!isButtonPressed()) {
    return;
  }
  show_6();
}

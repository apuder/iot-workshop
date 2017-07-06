
#define PIN_SEGMENT_A 3
#define PIN_SEGMENT_B 2
#define PIN_SEGMENT_C 8
#define PIN_SEGMENT_D 7
#define PIN_SEGMENT_E 6
#define PIN_SEGMENT_F 5
#define PIN_SEGMENT_G 4

#define PIN_BUTTON 9

#define SEGMENT_A (1 << 0)
#define SEGMENT_B (1 << 1)
#define SEGMENT_C (1 << 2)
#define SEGMENT_D (1 << 3)
#define SEGMENT_E (1 << 4)
#define SEGMENT_F (1 << 5)
#define SEGMENT_G (1 << 6)


const int segments[] = {
  SEGMENT_A | SEGMENT_B | SEGMENT_C | SEGMENT_D | SEGMENT_E | SEGMENT_F,
  SEGMENT_B | SEGMENT_C,
  SEGMENT_A | SEGMENT_B | SEGMENT_D | SEGMENT_E | SEGMENT_G,
  SEGMENT_A | SEGMENT_B | SEGMENT_C | SEGMENT_D | SEGMENT_G,
  SEGMENT_B | SEGMENT_C | SEGMENT_F | SEGMENT_G,
  SEGMENT_A | SEGMENT_C | SEGMENT_D | SEGMENT_F | SEGMENT_G,
  SEGMENT_A | SEGMENT_C | SEGMENT_D | SEGMENT_E | SEGMENT_F | SEGMENT_G,
  SEGMENT_A | SEGMENT_B | SEGMENT_C,
  SEGMENT_A | SEGMENT_B | SEGMENT_C | SEGMENT_D | SEGMENT_E | SEGMENT_F | SEGMENT_G,
  SEGMENT_A | SEGMENT_B | SEGMENT_C | SEGMENT_D | SEGMENT_F | SEGMENT_G
};

const int outerCircle[] = {
  SEGMENT_A,
  SEGMENT_B,
  SEGMENT_C,
  SEGMENT_D,
  SEGMENT_E,
  SEGMENT_F
};

const int segmentPins[] = {
  PIN_SEGMENT_A,
  PIN_SEGMENT_B,
  PIN_SEGMENT_C,
  PIN_SEGMENT_D,
  PIN_SEGMENT_E,
  PIN_SEGMENT_F,
  PIN_SEGMENT_G
};

void render(int seg) {
  for (int i = 0; i < 7; i++) {
    digitalWrite(segmentPins[i], (seg & 1) ? HIGH : LOW);
    seg >>= 1;
  }
}

void doAnimation() {
  int i = 0;
  int len = sizeof(outerCircle) / sizeof(int);
  for (int k = 0; k < 30; k++) {
    int seg = outerCircle[i];
    i = (i + 1) % len;
    seg |= outerCircle[i];
    render(seg);
    delay(50);
  }
}

void showNumber(int n) {
  int seg = segments[n];
  render(seg);
}

void setup() {
  for (int i = 0; i < 7; i++) {
    pinMode(segmentPins[i], OUTPUT); 
  }
  pinMode(PIN_BUTTON, INPUT_PULLUP);
  doAnimation();
  render(0);
}

bool isButtonPressed() {
  return digitalRead(PIN_BUTTON) == LOW;
}

void loop() {
  if (!isButtonPressed()) {
    return;
  }
  doAnimation();
  int d = 90;
  int v = 0;
  for (int i = 0; i < 15; i++) {
    int new_v = 0;
    do {
      new_v = random(1, 7);
    } while (v == new_v);
    v = new_v;
    showNumber(v);
    delay(d);
    if (i > 9) {
      d += 100;
    }
  }
  for (int i = 0; i < 5; i++) {
    render(0);
    delay(300);
    showNumber(v);
    delay(300);
  }
}

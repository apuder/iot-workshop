
#include <IRremote.h>

const int PIN_BUTTON = 7;

// 38 kHz carrier frequency
const int frequency = 38;

IRsend ir_sender;

const unsigned int rawData[] = {1000, 1000, 1000, 500, 1000, 500, 1000, 500, 1500, 1000, 500, 500, 1500, 1000};

void setup() {
  pinMode(PIN_BUTTON, INPUT_PULLUP);
}

void loop() {
  bool pressed = digitalRead(PIN_BUTTON) == LOW;
  if (pressed) {
    ir_sender.sendRaw(rawData, sizeof(rawData) / sizeof(rawData[0]), frequency);
    delay(1000);
  }
}

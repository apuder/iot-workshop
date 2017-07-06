
#include <IRremote.h>

// 38 kHz carrier frequency
const int frequency = 38;

IRsend ir_sender;

const unsigned int rawData[] = {9100, 4450, 550, 550, 600, 1650, 600, 1650, 550, 550, 600, 550, 550, 550, 600, 550, 600, 1650, 600, 1600, 600, 1650, 600, 550, 550, 1650, 600, 550, 550, 1650, 600, 1650, 600, 550, 550, 550, 600, 1650, 600, 550, 550, 550, 600, 1650, 600, 500, 600, 550, 600, 550, 550, 1650, 650, 500, 600, 1600, 600, 1650, 600, 550, 550, 1650, 600, 1650, 600, 1650, 550};

void setup() {
}

void loop() {
  ir_sender.sendRaw(rawData, sizeof(rawData) / sizeof(rawData[0]), frequency);

  delay(5000);
}

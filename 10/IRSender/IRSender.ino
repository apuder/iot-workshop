
#include <IRremote.h>

// 38 kHz carrier frequency
const int frequency = 38;

IRsend ir_sender;

unsigned int rawData[] = {4500, 4450, 600, 1600, 600, 1600, 600, 1650, 600, 500, 600, 500, 600, 500, 600, 500, 650, 500, 600, 1600, 600, 1600, 600, 1650, 600, 500, 600, 500, 600, 500, 600, 550, 600, 500, 600, 500, 600, 1600, 600, 500, 600, 550, 600, 500, 600, 500, 600, 500, 600, 500, 600, 1650, 600, 500, 600, 1600, 600, 1650, 600, 1600, 600, 1600, 600, 1650, 600, 1600, 600};

void setup() {
}

void loop() {
  ir_sender.sendRaw(rawData, sizeof(rawData) / sizeof(rawData[0]), frequency);

  delay(5000);
}

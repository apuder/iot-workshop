
#include <IRremote.h>

const int PIN_IR_RECEIVER = 11; 
const int PIN_LED = 2;

const int sensitivity = 150;

const unsigned int rawData[] = {1000, 1000, 1000, 500, 1000, 500, 1000, 500, 1500, 1000, 500, 500, 1500, 1000};

IRrecv ir_receiver(PIN_IR_RECEIVER);

decode_results results;

void setup() {
  pinMode(PIN_LED, OUTPUT);
  ir_receiver.enableIRIn();
}

void alarmRaised() {
  digitalWrite(PIN_LED, HIGH);
  delay(2000);
  digitalWrite(PIN_LED, LOW);
}

void analyze(decode_results* results) {
  int len = sizeof(rawData) / sizeof(rawData[0]);
  if (len != results->rawlen) {
    return;
  }
  for (int i = 1; i < len; i++) {
    unsigned int v = results->rawbuf[i] * USECPERTICK;
    unsigned int ref = rawData[i - 1];
    if (v < ref - sensitivity) {
      return;
    }
    if (v > ref + sensitivity) {
      return;
    }
  }
  alarmRaised();
}

void loop() {
  if (ir_receiver.decode(&results)) {
    analyze(&results);
    ir_receiver.resume();
  }
}

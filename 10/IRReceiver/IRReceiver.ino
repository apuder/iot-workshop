
#include <IRremote.h>

const int PIN_IR_RECEIVER = 11; 

IRrecv ir_receiver(PIN_IR_RECEIVER);

decode_results results;

void setup() {
  Serial.begin(9600);
  ir_receiver.enableIRIn();
}


void dump(decode_results* results) {
  Serial.print("unsigned int rawData[] = {");

  for (int i = 1;  i < results->rawlen;  i++) {
    if (i != 1) {
      Serial.print(", ");
    }
    Serial.print(results->rawbuf[i] * USECPERTICK, DEC);
  }
  Serial.println("};");
}

void loop() {
  if (ir_receiver.decode(&results)) {
    dump(&results);
    ir_receiver.resume();
  }
}

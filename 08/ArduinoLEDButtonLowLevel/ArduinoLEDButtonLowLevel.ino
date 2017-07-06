
/*
 * The following four #define's could be safely deleted because
 * PORTD, DDRD, PIND and 'bit' are defined in the Arduino
 * header files. They are shown here to highlight the fact that
 * input/output pins on the Arduino can be accessed via memory-
 * mapped I/O by using C-pointers. Note that the memory addresses
 * are hard-coded for the Arduino Uno. The section numbers are
 * references to the ATmega328 manual where the respective registers
 * are explained.
 */

// PORTD (Section 18.4.8)
volatile uint8_t* PORT_D_DATA_REGISTER = (uint8_t*) 0x2B;
#define PORTD (*PORT_D_DATA_REGISTER)

// DDRD (Section 18.4.9)
volatile uint8_t* PORT_D_DATA_DIRECTION = (uint8_t*) 0x2a;
#define DDRD (*PORT_D_DATA_DIRECTION)

// PIND (Section 18.4.10)
volatile uint8_t* PORT_D_INPUT = (uint8_t*) 0x29;
#define PIND (*PORT_D_INPUT)

#define bit(b) (1 << (b))


const unsigned char PIN_2 = bit(2);
const unsigned char PIN_6 = bit(6);

void my_setup() {
  // Configure PIN_6 as output
  DDRD |= PIN_6;
  // Configure PIN_2 as input
  DDRD &= ~PIN_2;
  // Configure pullup for PIN_2
  PORTD |= PIN_2;
}

bool isButtonPressed() {
  return PIND & PIN_2;
}

void my_loop() {
  if (isButtonPressed()) {
    // LED off
    PORTD &= ~PIN_6;
  } else {
    // LED on
    PORTD |= PIN_6;
  }
}

int main() {
  my_setup();
  while (true) {
    my_loop();
  }
  return 0;
}



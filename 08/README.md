# Low-Level Access

This tutorial demonstrates some low-level access of the Arduino. Functionally the two sketches discussed below
are equivalent to the <a href="../03/">Arduino controlling LED &amp; Button</a> example. In particular, the wiring
is identical to the earlier example.

### Memory Mapped I/O

The Arduino Uno used for this tutorial uses the
<a href="http://www.atmel.com/Images/Atmel-42735-8-bit-AVR-Microcontroller-ATmega328-328P_Datasheet.pdf">ATmega328P</a>
microcontroller. Functions such as
<a href="https://www.arduino.cc/en/Reference/DigitalRead">`digitalRead()`</a> are convenience functions that
use _Memory Mapped I/O_ (MMIO) to manipulate the GPIO pins. In MMIO, C-pointers are used to access specific
memory locations to control GPIO pins. E.g., by inspecting bit 2 of memory address 0x29 (decimal 41) it can be
determined if a HIGH or LOW signal is present at GPIO pin 2 of the Arduino. This can be accomplished by the
following C-code:

```c
volatile uint8_t* PORT_D_INPUT = (uint8_t*) 0x29;
if (*PORT_D_INPUT & (1 << 2)) {
  // Pin 2 is HIGH
} else {
  // Pin 2 is LOW
}
```

Functionally the preceding code excerpt is equivalent to calling `digitalRead(2)`.
Note the use of modifier `volatile` which is necessary in order to avoid compiler optimizations (the C-compiler
does not know about MMIO and therefore might optimize-away the code above). The fact that memory address 0x29
can be used to control pin 2 is documented in Section 18.4.10 of the
<a href="http://www.atmel.com/Images/Atmel-42735-8-bit-AVR-Microcontroller-ATmega328-328P_Datasheet.pdf">ATmega328P
datasheet</a>. Sketch
<a href="https://github.com/apuder/iot-workshop/blob/master/08/ArduinoLEDButtonLowLevel/ArduinoLEDButtonLowLevel.ino">ArduinoLEDButtonLowLevel</a>
also highlights the usual function `main()` entry point of a C program. Functions `setup()` and `loop()` are
just convenience functions introduced by the Arduino.

### Interrupts

An Arduino sketch usually performs its work in the `loop()` function. The LED/button example constantly checks the
state of the button (pressed or not pressed) and updates the LED accordingly. This is sometimes referred to
_busy waiting_. It is possible to register a so-called _Interrupt Service Routine_ (ISR) which is a regular
C function with no input parameters and no return type that will be called whenever a particular event occurs.
Sketch
<a href="https://github.com/apuder/iot-workshop/blob/master/08/ArduinoLEDButtonUsingInterrupts/ArduinoLEDButtonUsingInterrupts.ino">ArduinoLEDButtonUsingInterrupts</a>
is functionally equivalent to the
<a href="../03/">Arduino controlling LED &amp; Button</a> example, however, function
<a href="https://www.arduino.cc/en/Reference/AttachInterrupt">`attachInterrupt()`</a> is used to register
function `isr_button()` as an ISR. The ISR will be called whenever there is a state change on the GPIO pin
to which the button is connected. There are several things to consider:

* Not all GPIO pins support interrupts. On the Arduino Uno only GPIO pins 2 and 3 support interrupts.
* ISRs need to be careful on modifying global variables in order to avoid race conditions.
* Interrupts are disabled while inside the ISR. One consequence is that time-based functions such
  as `delay()` will not work while inside the ISR. For that reason ISRs should also not take much time to execute.

One reason to use interrupts is that they help to avoid busy-waiting. In this particular example, the
`loop()` function contains no code and it would be possible to put the CPU in a low-power state (not
shown in this example). This is particularly important for battery-powered Arduinos.
More details on interrupts and ISRs are available on this <a href="http://gammon.com.au/interrupts">blog post</a>.


# Serial Demo

The Arduino IDE does not offer any debugging capabilities. A common issue for any microcontroller is
how to find programming errors in the absense of a debugger. The Arduino offers a way to print debug messages
to what is called the _Serial Monitor_. C++ class
<a href="https://www.arduino.cc/en/Reference/Serial">`Serial`</a> has methods to interact with the serial
interface of an Arduino. In order to use the the serial interface, it must first be initialized via
<a href="https://www.arduino.cc/en/Serial/Begin">`Serial.begin()`</a>. This typically happens in the
`setup()` function. The parameter to method `Serial.begin()`
indicates the transmission speed (in the example below it is 9600 bits per second). Once the serial
interface has been initialized, method
<a href="https://www.arduino.cc/en/Serial/Println">`Serial.println()`</a> can be used to print log
messages. This example does not require any wiring as it does not use GPIO pins. The sketch below will
print log messages to the serial monitor. Before compiling and running the sketch, the serial monitor
must be opened from the Arduino IDE via the menu option _Tools > Serial Monitor_. Note that the transmission
speed of the serial monitor needs to match the speed configured in the sketch.

```c
void setup() {
  Serial.begin(9600);
  Serial.println("Inside setup()");
}

void loop() {
  Serial.println("Inside loop()");
  delay(1000);
}
```

# Infrared Receiver

An _Infrared Receiver_ (IR receiver for short) detects  infrared light modulated at a certain frequency,
commonly 38 kHz. Whenever this frequency of the IR spectrum is detected, the output pin of the IR receiver
is asserted to low (leftmost pin of the IR receiver in the diagram below).
When a regular TV remote is pointed to the IR receiver below, the red LED will light
up. One of the reasons the IR signal is modulated at 38 kHz is so that the IR receiver can distinguish it from
naturally occuring infrared light (e.g., the sun). Each button of a TV remote sends an unique on/off pattern that
identifies the particular button. An oscilloscope or a logic analyzer are needed to visualize this pattern.
The Arduino is once more only used as a power supply in this example and no sketch needs to be uploaded.

A good explanation on the functioning of an IR receiver is contained
at this <a href="https://learn.adafruit.com/ir-sensor/overview">Adafruit tutorial</a>. This
<a href="http://irq5.io/2012/07/27/infrared-remote-control-protocols-part-1/">web page</a> provides
a good explanation of the various encodings used for IR signals.

<img src="IRReceiverLED_bb.png" width="50%"/>


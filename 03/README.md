# Serial Demo

The Arduino IDE does not offer any debugging capabilities. A common issue for any microcontroller is
how to find programming errors in the absense of a debugger. The Arduino offers a way to print debug messages
to what is called the _Serial Monitor_. C++ class
<a href="https://www.arduino.cc/en/Reference/Serial">`Serial`</a> has methods (i.e., functions of a C++ class)
to interact with the serial
interface of an Arduino. In order to use the the serial interface, it must first be initialized via
<a href="https://www.arduino.cc/en/Serial/Begin">`Serial.begin()`</a>. This typically happens in the
`setup()` function. The parameter to method `Serial.begin()`
indicates the transmission speed (in the example below it is 9600 bits per second, or 9600 baud). Once the serial
interface has been initialized, method
<a href="https://www.arduino.cc/en/Serial/Println">`Serial.println()`</a> can be used to print log
messages. This example does not require any wiring. The sketch below will
print log messages to the serial monitor. Before compiling and running the sketch, the serial monitor
must be opened from the Arduino IDE via the menu option _Tools > Serial Monitor_. Note that the transmission
speed of the serial monitor needs to match the speed configured in the sketch. The sketch below will
print "_Inside loop()_" every 1000 milli seconds (i.e., every 1 second).

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


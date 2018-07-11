# Arduino controlling LED &amp; Button

This example is functionally equivalent to the <a href="../01/">LED &amp; Button</a> example, however,
the Arduino controls the behavior of the LED. This is the first time in this tutorial that a program
(usually referred to as a _sketch_) is uploaded to the Arduino. This requires a so-called _Integrated
Development Environment_, or IDE for short. While there are a variety of IDEs available to develop for
the Arduino, the sketches part of this tutorial assume the standard
<a href="https://www.arduino.cc/en/Main/Software">Arduino IDE</a>.

The button is connected to pin 2 and the LED is connected to
pin 6 of the Arduino. The following sketch will light up the LED when the button is pressed:

```c
const int PIN_LED = 6;
const int PIN_BUTTON = 2;

void setup() {
  pinMode(PIN_LED, OUTPUT);
  pinMode(PIN_BUTTON, INPUT_PULLUP);
}

void loop() {
  bool pressed = digitalRead(PIN_BUTTON) == LOW;
  digitalWrite(PIN_LED, pressed ? HIGH : LOW);
}
```

Function `setup()` defines pin 2 as input and pin 6 as output via function
<a href="https://www.arduino.cc/en/Reference/PinMode">`pinMode()`</a>. The constant `INPUT_PULLUP`
will activate an internal pull-up resistor which is why the wiring below does not need a dedicated
resistor connected to the button. Function `loop()` then uses functions
<a href="https://www.arduino.cc/en/Reference/DigitalRead">`digitalRead()`</a> to determine if the button
is pressed or not and
<a href="https://www.arduino.cc/en/Reference/DigitalWrite">`digitalWrite()`</a> to turn the LED off or on.

<img src="doc/ArduinoLEDButton_bb.png" width="50%"/>

Tutorial

[![Tutorial](https://img.youtube.com/vi/qr91fY0JsOU/hqdefault.jpg)](https://youtu.be/qr91fY0JsOU) 

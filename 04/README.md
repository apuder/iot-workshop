# One Blinking LED

The Arduino offers function <a href="https://www.arduino.cc/en/Reference/Delay">`delay()`</a>
to delay execution for a specific number of milli-seconds. The following sketch will turn the LED on
for 500 milli-seconds (half a second) and then turn it off for 250 milli-seconds:

```c
const int PIN_LED = 6;

void setup() {
  pinMode(PIN_LED, OUTPUT);
}

void loop() {
  digitalWrite(PIN_LED, HIGH);
  delay(500);
  digitalWrite(PIN_LED, LOW);
  delay(250);
}
```

One issue with <a href="https://www.arduino.cc/en/Reference/Delay">`delay()`</a> is that blocks the
CPU and it is not possible to do anything else during the delay because the Arduino has only one
thread of execution. In other words, the Arduino does not support concurrent programming via the
common technique of multi-threading. The following sketch makes use of function
<a href="https://www.arduino.cc/en/Reference/Millis">`millis()`</a> to make the LED blink in the
same pattern as with the sketch above:

```c
const int PIN_LED = 6;

const int LED_ON_TIME = 500;
const int LED_OFF_TIME = 250;

int ledState = LOW;
unsigned long tsLastStateChange = 0;

void setup() {
  pinMode(PIN_LED, OUTPUT);
}

void loop() {
  unsigned long delta = millis() - tsLastStateChange;
  switch(ledState) {
  case LOW:
    if (delta > LED_OFF_TIME) {
      ledState = HIGH;
      tsLastStateChange = millis();
    }
    break;
  case HIGH:
    if (delta > LED_ON_TIME) {
      ledState = LOW;
      tsLastStateChange = millis();
    }
    break;
  }
  digitalWrite(PIN_LED, ledState);
}
```

<a href="https://www.arduino.cc/en/Reference/Millis">`millis()`</a> returns the number of milli-seconds since
the Arduino began running and the above sketch uses this to determine whether the LED should be turned off or
on. Note that the `loop()` function of the earlier sketch takes about 750 milli-seconds for one iteration
(due to the 500 + 250 milli-seconds delay). The `loop()` function of the second sketch in contrast does not call
<a href="https://www.arduino.cc/en/Reference/Delay">`delay()`</a> and will therefore only take a fraction
of a second for one iteration.



<img src="doc/OneBlinkingLED_bb.png" width="50%"/>


class BlinkingLED {
private:
  const int LED_PIN;
  const int LED_ON_TIME;
  const int LED_OFF_TIME;
  int ledState = LOW;
  unsigned long tsLastStateChange = 0;
public:
  BlinkingLED(int pin, int onTime, int offTime) :
    LED_PIN(pin),
    LED_ON_TIME(onTime),
    LED_OFF_TIME(offTime) {
      pinMode(LED_PIN, OUTPUT);
  }
  void update() {
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
    digitalWrite(LED_PIN, ledState);
  }
};

BlinkingLED ledRed(6, 50, 25);
BlinkingLED ledGreen(7, 100, 100);

void setup() {}

void loop()
{
  ledRed.update();
  ledGreen.update();
}


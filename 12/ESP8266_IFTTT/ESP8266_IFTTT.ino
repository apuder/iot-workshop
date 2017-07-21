
#include <ESP8266WiFi.h>
#include <WiFiClientSecure.h>

// The following three parameters need to be changed
const char* ssid = "IoT Workshop";
const char* password = "B9LZd73yWx33";
const char* iftttApiKey = "API_KEY";

const char* host = "maker.ifttt.com";
const int httpsPort = 443;

const int PIN_BUTTON = 0;

void setup() {
  Serial.begin(115200);

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
  }
  Serial.print("WiFi connected with IP address: ");
  Serial.println(WiFi.localIP());

  pinMode(PIN_BUTTON, INPUT_PULLUP);
}

void doPOST() {
  WiFiClientSecure client;
  Serial.println("Connecting to IFTTT server");
  if (!client.connect(host, httpsPort)) {
    Serial.println("Connection failed");
    return;
  }

  String url = "/trigger/esp8266_triggered/with/key/";
  client.print(String("POST ") + url + iftttApiKey + " HTTP/1.1\r\n" +
               "Host: " + host + "\r\n" +
               "User-Agent: ESP8266\r\n" +
               "Connection: close\r\n\r\n");

  while (client.connected()) {
    // Read response from IFTTT but ignore it
    String line = client.readStringUntil('\n');
    Serial.println(line);
  }
}

bool isButtonPressed() {
  return digitalRead(PIN_BUTTON) == LOW;
}

void loop() {
  if (isButtonPressed()) {
    doPOST();
    while (isButtonPressed()) ;
  }
}

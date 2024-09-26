#include <Arduino.h>
#include <WiFi.h>
#include <WebServer.h>

const char* ssid = "";
const char* password = "";

WebServer server(80);

int led_1 = 4;
int led_2 = 5;
int led_3 = 18;
int led_4 = 10;
int led_5 = 3;
int led_6 = 8;
int led_7 = 0;
int led_8 = 7;

void handleLEDOn() {
  digitalWrite(led_1, HIGH);
  digitalWrite(led_2, HIGH);
  digitalWrite(led_3, HIGH);
  digitalWrite(led_4, HIGH);
  digitalWrite(led_5, HIGH);
  digitalWrite(led_6, HIGH);
  digitalWrite(led_7, HIGH);
  digitalWrite(led_8, HIGH);
  server.send(200, "text/html", "All LEDs are ON");
}

void handleLEDOff() {
  digitalWrite(led_1, LOW);
  digitalWrite(led_2, LOW);
  digitalWrite(led_3, LOW);
  digitalWrite(led_4, LOW);
  digitalWrite(led_5, LOW);
  digitalWrite(led_6, LOW);
  digitalWrite(led_7, LOW);
  digitalWrite(led_8, LOW);
  server.send(200, "text/html", "All LEDs are OFF");
}

void handleBlinkingON(){
  int speed = 100;
  for (int i = 0; i < 5; i++)
  {
    digitalWrite(led_1, HIGH);
    delay(speed);
    digitalWrite(led_1, LOW);

    digitalWrite(led_2, HIGH);
    digitalWrite(led_3, HIGH);
    delay(speed);
    digitalWrite(led_2, LOW);
    digitalWrite(led_3, LOW);

    digitalWrite(led_4, HIGH);
    digitalWrite(led_5, HIGH);
    delay(speed);
    digitalWrite(led_4, LOW);
    digitalWrite(led_5, LOW);

    digitalWrite(led_6, HIGH);
    digitalWrite(led_7, HIGH);
    delay(speed);
    digitalWrite(led_6, LOW);
    digitalWrite(led_7, LOW);

    digitalWrite(led_8, HIGH);
    delay(speed);
    digitalWrite(led_8, LOW);
  //--------------------------

    digitalWrite(led_8, HIGH);
    delay(speed);
    digitalWrite(led_8, LOW);

  digitalWrite(led_6, HIGH);
    digitalWrite(led_7, HIGH);
    delay(speed);
    digitalWrite(led_6, LOW);
    digitalWrite(led_7, LOW);
    digitalWrite(led_4, HIGH);
    digitalWrite(led_5, HIGH);
    delay(speed);
    digitalWrite(led_4, LOW);
    digitalWrite(led_5, LOW);
    digitalWrite(led_2, HIGH);
    digitalWrite(led_3, HIGH);
    delay(speed);
    digitalWrite(led_2, LOW);
    digitalWrite(led_3, LOW);
    digitalWrite(led_1, HIGH);
    delay(speed);
    digitalWrite(led_1, LOW);
  }
  for (int i = 0; i < 10; i++)
  {
    digitalWrite(led_1, HIGH);
    digitalWrite(led_2, HIGH);
    digitalWrite(led_3, HIGH);
    digitalWrite(led_4, HIGH);
    digitalWrite(led_5, HIGH);
    digitalWrite(led_6, HIGH);
    digitalWrite(led_7, HIGH);
    digitalWrite(led_8, HIGH);
    delay(speed);
    digitalWrite(led_1, LOW);
    digitalWrite(led_2, LOW);
    digitalWrite(led_3, LOW);
    digitalWrite(led_4, LOW);
    digitalWrite(led_5, LOW);
    digitalWrite(led_6, LOW);
    digitalWrite(led_7, LOW);
    digitalWrite(led_8, LOW);
    delay(speed * 2);
    digitalWrite(led_1, HIGH);
    digitalWrite(led_2, HIGH);
    digitalWrite(led_3, HIGH);
    digitalWrite(led_4, HIGH);
    digitalWrite(led_5, HIGH);
    digitalWrite(led_6, HIGH);
    digitalWrite(led_7, HIGH);
    digitalWrite(led_8, HIGH);
    delay(speed);
    digitalWrite(led_1, LOW);
    digitalWrite(led_2, LOW);
    digitalWrite(led_3, LOW);
    digitalWrite(led_4, LOW);
    digitalWrite(led_5, LOW);
    digitalWrite(led_6, LOW);
    digitalWrite(led_7, LOW);
    digitalWrite(led_8, LOW);
    delay(speed * 2);
  }



  server.send(200, "text/html", "Leds blinking");
}

void setup() {
  Serial.begin(115200);
  
  pinMode(led_1, OUTPUT);
  pinMode(led_2, OUTPUT);
  pinMode(led_3, OUTPUT);
  pinMode(led_4, OUTPUT);
  pinMode(led_5, OUTPUT);
  pinMode(led_6, OUTPUT);
  pinMode(led_7, OUTPUT);
  pinMode(led_8, OUTPUT);

  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }

  Serial.println("Connected to WiFi");
  Serial.println(WiFi.localIP());

  server.on("/led/on", handleLEDOn);
  server.on("/led/off", handleLEDOff);
  server.on("/led/blinking", handleBlinkingON);
  

  server.begin();
}

void loop() {
  server.handleClient();
}

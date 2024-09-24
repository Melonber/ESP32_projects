#include <Arduino.h>

void setup() {
  Serial.begin(115200);
  pinMode(0, OUTPUT);
  Serial.println("Hello from setup");
}

void loop() {
  digitalWrite(0, HIGH);
  delay(200);
  digitalWrite(0, LOW);
  delay(200);
  Serial.println("Hi from loop!");
}

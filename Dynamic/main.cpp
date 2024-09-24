#include <WiFi.h>
#include <Arduino.h>

int speaker = 0;
int led = 1;

void setup()
{
  Serial.begin(115200);
  pinMode(speaker, OUTPUT);
  pinMode(led, OUTPUT);
  digitalWrite(speaker, HIGH);
  digitalWrite(led, HIGH);
  delay(500);
  digitalWrite(speaker, LOW);
  digitalWrite(led, LOW);
  delay(500);
  digitalWrite(speaker, HIGH);
  digitalWrite(led, HIGH);
  delay(500);
  digitalWrite(speaker, LOW);
  digitalWrite(led, HIGH);
  delay(500);
  digitalWrite(speaker, HIGH);
  digitalWrite(led, HIGH);
  delay(500);
  digitalWrite(speaker, LOW);
  digitalWrite(led, LOW);
  delay(500);

  digitalWrite(speaker, HIGH);
  digitalWrite(led, HIGH);

  delay(250);
  digitalWrite(speaker, LOW);
  digitalWrite(led, LOW);
  delay(250);

  digitalWrite(speaker, HIGH);
  digitalWrite(led, HIGH);
  delay(250);
  digitalWrite(speaker, LOW);
  digitalWrite(led, LOW);
  delay(250);


  digitalWrite(speaker, HIGH);
  digitalWrite(led, HIGH);
  delay(250);
  digitalWrite(speaker, LOW);
  digitalWrite(led, LOW);
  delay(250);

  digitalWrite(speaker, HIGH);
  digitalWrite(led, HIGH);
  delay(100);
  digitalWrite(speaker, LOW);
  digitalWrite(led, LOW);
  delay(100);

  digitalWrite(speaker, HIGH);
  delay(100);
  digitalWrite(speaker, LOW);
  delay(100);

  digitalWrite(speaker, HIGH);
  delay(100);
  digitalWrite(speaker, LOW);
  delay(100);

  digitalWrite(speaker, HIGH);
  delay(100);
  digitalWrite(speaker, LOW);
  delay(100);

  digitalWrite(speaker, HIGH);
  delay(100);
  digitalWrite(speaker, LOW);
  delay(100);

  digitalWrite(speaker, HIGH);
  delay(100);
  digitalWrite(speaker, LOW);
  delay(100);

  digitalWrite(speaker, HIGH);
  delay(100);
  digitalWrite(speaker, LOW);
  delay(100);

  digitalWrite(speaker, HIGH);
  delay(100);
  digitalWrite(speaker, LOW);
  delay(100);

  digitalWrite(speaker, HIGH);
  delay(100);
  digitalWrite(speaker, LOW);
  delay(100);

  digitalWrite(speaker, HIGH);
  delay(100);
  digitalWrite(speaker, LOW);
  delay(100);

  digitalWrite(speaker, HIGH);
  delay(100);
  digitalWrite(speaker, LOW);
  delay(100);
}

void loop(){
  


}

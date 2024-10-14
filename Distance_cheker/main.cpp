#include <Arduino.h>

const int red_pin = 0;
const int yellow_pin = 1;
const int green_pin = 2;
const int buzzer_pin = 3;
const int trigger_pin = 5;
const int echo_pin = 18;
const int button_pin = 6;
bool pressed = false;
bool lastButtonState = HIGH;
bool buzzer_active = false;

void green_on()
{
  digitalWrite(green_pin, HIGH);
}

void green_off(){
  digitalWrite(green_pin, LOW);
}

void yellow_on(){
  digitalWrite(yellow_pin, HIGH);
}

void yellow_off(){
  digitalWrite(yellow_pin, LOW);
}

void red_on(){
  digitalWrite(red_pin, HIGH);
}

void red_off(){
  digitalWrite(red_pin, LOW);
}

void buzzer_once(){
  digitalWrite(buzzer_pin, HIGH);
  delay(700);
  digitalWrite(buzzer_pin, LOW);
}

void buzzer_far(){
  digitalWrite(buzzer_pin, HIGH);
  delay(1000);
  digitalWrite(buzzer_pin, LOW);
  delay(1000);
}

void buzzer_middle(){
  digitalWrite(buzzer_pin, HIGH);
  delay(500);
  digitalWrite(buzzer_pin, LOW);
  delay(500);
}

void buzzer_near(){
  digitalWrite(buzzer_pin, HIGH);
  delay(50);
  digitalWrite(buzzer_pin, LOW);
  delay(50);
}

void setup(){
  Serial.begin(115200);
  pinMode(buzzer_pin, OUTPUT);
  pinMode(red_pin, OUTPUT);
  pinMode(yellow_pin, OUTPUT);
  pinMode(green_pin, OUTPUT);
  pinMode(trigger_pin, OUTPUT);
  pinMode(echo_pin, INPUT);
  pinMode(button_pin, INPUT_PULLUP);
}

void loop(){


  bool currentButtonState = digitalRead(button_pin);

  if(lastButtonState == HIGH && currentButtonState == LOW){
    pressed = !pressed;
    delay(100);
    Serial.print(pressed ? "On" : "OFF");
  }

  if (pressed == 1){
    if(!buzzer_active){
      buzzer_once();
      buzzer_active = true;
    }
      long duration, distance;
      digitalWrite(trigger_pin, LOW);
      delayMicroseconds(2);
      digitalWrite(trigger_pin, HIGH);
      delayMicroseconds(10);
      digitalWrite(trigger_pin, LOW);

      duration = pulseIn(echo_pin, HIGH);
      distance = duration * 0.034 / 2;

      Serial.print("Distance: ");
      Serial.print(distance);
      Serial.println(" cm");
      if(distance >= 25)
    {
      green_on();
      red_off();
      yellow_off();
    }
    else if (distance < 25 && distance >= 10)
    {
      green_off();
      red_off();
      yellow_on();
      buzzer_middle();

    }
    else if (distance < 10)
    {
      green_off();
      yellow_off();
      red_on();

      buzzer_near();

    }

    delay(100);
    }

  else{
    Serial.println("Parking mode OFF");
    green_off();
    yellow_off();
    red_off();
    buzzer_active = false; 
    delay(200);
    }
}

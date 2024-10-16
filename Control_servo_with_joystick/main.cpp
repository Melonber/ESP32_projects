#include <Arduino.h>
#include <ESP32Servo.h>

const int pinX = 1;      // Пин для X оси джойстика
const int pinY = 2;      // Пин для Y оси джойстика
const int pinButton = 3; // Пин для кнопки на джойстике
const int pinServo = 10; // Пин для сервопривода

Servo myServo;

void setup() {
  myServo.attach(10);
}

void loop() {
  // Считывание значений с джойстика
  int XValue = analogRead(pinX); // Считываем значение X
  int YValue = analogRead(pinY); // Считываем значение Y
  int buttonState = digitalRead(pinButton); // Проверяем состояние кнопки

  // Проверка, нужно ли поворачивать сервопривод на 180 градусов
  if (XValue > 3373) {
    myServo.write(180);

  } 
  else if(XValue < 1000){
    myServo.write(-180);
  }
  else {
    myServo.write(90); // Останавливаем сервопривод, если джойстик не отклонен
  }

  // Вывод данных в консоль
  Serial.print("X: ");
  Serial.print(XValue);
  Serial.print("\tY: ");
  Serial.print(YValue);

  // Проверяем, нажата ли кнопка
  if (buttonState == LOW) {
    Serial.print("\tButton pressed");
  }

  Serial.println(); // Переход на новую строку для удобного отображения

  delay(100); // Задержка перед следующим чтением
}

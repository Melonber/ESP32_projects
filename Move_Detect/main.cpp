#include <WiFi.h>
#include <Arduino.h>

int sensorPin = 2;      // Пин сенсора
int ledPin = 1;         // Пин светодиода
int buzzerPin = 18;     // Пин зуммера
int sensorValue = 0;    // Значение, считываемое с сенсора
bool motionDetected = false; // Флаг для отслеживания состояния движения
unsigned long motionStartTime = 0; // Время начала обнаружения движения
unsigned long buzzerDuration = 1000; // Длительность работы зуммера (1 секунда)

void setup() {
  pinMode(ledPin, OUTPUT);      // Устанавливаем пин светодиода как выход
  pinMode(sensorPin, INPUT);    // Устанавливаем пин сенсора как вход
  pinMode(buzzerPin, OUTPUT);   // Устанавливаем пин зуммера как выход
  Serial.begin(115200);         // Инициализируем сериал для вывода данных
}

void loop() {
  sensorValue = digitalRead(sensorPin); // Считываем данные с PIR сенсора

  // Если движение обнаружено и флаг motionDetected == false
  if (sensorValue == HIGH && !motionDetected) {
    motionDetected = true;                  // Устанавливаем флаг движения
    motionStartTime = millis();             // Запоминаем время начала движения
    digitalWrite(ledPin, HIGH);             // Включаем светодиод
    digitalWrite(buzzerPin, HIGH);          // Включаем зуммер
    Serial.println("Motion detected!");
  }

  // Если прошло более 1 секунды с начала обнаружения движения
  if (motionDetected && millis() - motionStartTime >= buzzerDuration) {
    digitalWrite(buzzerPin, LOW);           // Выключаем зуммер через 1 секунду
  }

  // Если движение прекратилось (сенсор вернулся в LOW)
  if (sensorValue == LOW && motionDetected) {
    digitalWrite(ledPin, LOW);              // Выключаем светодиод
    motionDetected = false;                 // Сбрасываем флаг движения
    Serial.println("No motion.");
  }

  delay(500);  // Задержка для предотвращения слишком частого считывания
}

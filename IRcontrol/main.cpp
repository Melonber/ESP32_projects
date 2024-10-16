#include <Arduino.h>
#include <IRrecv.h>
#include <IRutils.h>

const int ledPin = 1; // Пин для светодиода
const int recv_pin = 4; // Пин для ИК-приемника

IRrecv irrecv(recv_pin);
decode_results results;

void setup() {
  Serial.begin(115200);
  pinMode(ledPin, OUTPUT);
  irrecv.enableIRIn(); // Запускаем ИК-приемник
}

void loop() {
  if (irrecv.decode(&results)) {
    Serial.println(resultToHumanReadableBasic(&results)); // Выводим информацию о нажатой кнопке
    Serial.println(results.value, HEX);
    if (results.value == 0x80BF49B6) { //  код кнопки
      digitalWrite(ledPin, HIGH); // Включаем светодиод
    } else {
      digitalWrite(ledPin, LOW); // Выключаем светодиод
    }
    irrecv.resume(); // Считываем следующий сигнал
  }
}

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <WiFi.h>
#include <HTTPClient.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1  // Без пина сброса
#define SCREEN_ADDRESS 0x3C  // Адрес I2C для OLED
#define DOWN_BUTTON 1  // Пин для кнопки вниз
#define UP_BUTTON 2    // Пин для кнопки вверх
#define MIDDLE_BUTTON 0 // Пин для кнопки выбора

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// Переменные для меню
int currentSelection = 0; // Текущая выбранная строка меню
const int menuItems = 3;  // Количество пунктов меню

// Wi-Fi данные
const char* ssid = "Summator WiFi"; // Замените на имя вашей сети
const char* password = "YaseminBerkman"; // Замените на пароль вашей сети

// URL вашего API
const char* apiUrl = "http://10.0.0.34:8000/check"; // Замените на ваш URL API

void setup() {
  // Инициализация I2C на ESP32
  Wire.begin(8, 9); // SDA = GPIO 8, SCK = GPIO 9
  Wire.setClock(100000); // Установим частоту I2C на 100kHz

  // Инициализация дисплея
  if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;); // Остановить выполнение если дисплей не инициализирован
  } else {
    Serial.println(F("OLED initialized"));
  }

  // Очистка экрана
  display.clearDisplay();

  // Настройка пинов кнопок
  pinMode(DOWN_BUTTON, INPUT_PULLUP);
  pinMode(UP_BUTTON, INPUT_PULLUP);
  pinMode(MIDDLE_BUTTON, INPUT_PULLUP);

  // Подключение к Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");

  // Отображаем начальное меню
  displayMenu();
}

void loop() {
  // Проверка нажатия кнопки вниз
  if (digitalRead(DOWN_BUTTON) == LOW) {
    currentSelection = (currentSelection + 1) % menuItems; // Цикл по меню
    displayMenu();
    delay(200); // Задержка для предотвращения дребезга кнопок
  }

  // Проверка нажатия кнопки вверх
  if (digitalRead(UP_BUTTON) == LOW) {
    currentSelection = (currentSelection - 1 + menuItems) % menuItems; // Цикл по меню
    displayMenu();
    delay(200); // Задержка для предотвращения дребезга кнопок
  }

  // Проверка нажатия кнопки выбора (MIDDLE_BUTTON)
  if (digitalRead(MIDDLE_BUTTON) == LOW) {
    handleSelection(); // Обрабатываем выбор
    delay(200); // Задержка для предотвращения дребезга кнопок
  }
}

// Функция для отображения меню
void displayMenu() {
  display.clearDisplay(); // Очистка экрана

  // Вывод пунктов меню
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);

  display.setCursor(0, 0);
  if (currentSelection == 0) {
    display.print(F("1)Send hello in tg<")); // Пункт выбран
  } else {
    display.print(F("1)Send tg message"));
  }

  display.setCursor(0, 16);
  if (currentSelection == 1) {
    display.print(F("2)Send gif<")); // Пункт выбран
  } else {
    display.print(F("2)Send kitty in tg"));
  }
  
  display.setCursor(0, 32);
  if (currentSelection == 2) {
    display.print(F("3)Exit<")); // Пункт выбран
  } else {
    display.print(F("3)Exit"));
  }
  
  display.display(); // Обновляем экран
}

// Функция для обработки выбора пункта меню
void handleSelection() {
  display.clearDisplay(); // Очистка экрана

  display.setCursor(0, 0); // Устанавливаем курсор в начало

  if (currentSelection == 0) {
    // Отправка текстового сообщения в Telegram
    sendCommandToTelegram("Send_message");
  } else if (currentSelection == 1) {
    // Отправка GIF в Telegram
    sendCommandToTelegram("Send_Gif");
  }

  display.display(); // Обновляем экран
}

void sendCommandToTelegram(String command) {
  if (WiFi.status() == WL_CONNECTED) { // Проверяем подключение к WiFi
    HTTPClient http;
    
    // Отправляем POST-запрос
    http.begin(apiUrl);
    http.addHeader("Content-Type", "application/json");

    // Подготавливаем тело запроса
    String requestBody = "{\"command\": \"" + command + "\"}"; // Отправляем команду
    int httpResponseCode = http.POST(requestBody);

    // Проверяем код ответа
    if (httpResponseCode > 0) {
      String response = http.getString(); // Получаем ответ от API
      Serial.println(httpResponseCode); // Печатаем код ответа
      Serial.println(response); // Печатаем ответ

      // Обрабатываем ответ
      if (response.indexOf("yes") != -1) {
        display.setCursor(0, 0);
        display.print(F("Command sent!")); // Успешное сообщение
      } else {
        display.setCursor(0, 0);
        display.print(F("Command sent!")); // Не отправлено
      }
    } else {
      Serial.print("Error on sending POST: ");
      Serial.println(httpResponseCode);
      display.setCursor(0, 0);
      display.print(F("Error sending")); // Ошибка отправки
    }

    http.end(); // Завершаем запрос
  } else {
    Serial.println("WiFi Disconnected");
  }
}

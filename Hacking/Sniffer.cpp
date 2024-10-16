#include <Arduino.h>
#include "esp_wifi.h"
#include <WiFi.h>

// Callback для обработки перехваченных пакетов
void wifi_sniffer_packet_handler(void *buff, wifi_promiscuous_pkt_type_t type) {
  wifi_promiscuous_pkt_t *pkt = (wifi_promiscuous_pkt_t *)buff;
  
  // Длина пакета
  uint16_t len = pkt->rx_ctrl.sig_len;
  Serial.print("Packet length: ");
  Serial.println(len);

  // Данные пакета
  const uint8_t *payload = pkt->payload;

  // Выводим полезную нагрузку пакета в шестнадцатеричном формате
  Serial.print("Packet data: ");
  for (int i = 0; i < len; i++) {
    Serial.printf("%02X ", payload[i]);
  }
  Serial.println();
}

void setup() {
  Serial.begin(115200);

  // Инициализация Wi-Fi в режиме promiscuous
  WiFi.mode(WIFI_MODE_STA);
  esp_wifi_set_promiscuous(true);
  esp_wifi_set_promiscuous_rx_cb(&wifi_sniffer_packet_handler);
}

void loop() {
  // В цикле ничего не делаем, так как обработка идет в коллбеке
}

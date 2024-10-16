;Platformio.ini:

[env:esp32-c3-devkitc-02]
platform = espressif32
board = esp32-c3-devkitc-02
upload_port = /dev/cu.SLAB_USBtoUART
framework = arduino
monitor_speed = 115200
lib_deps = madhephaestus/ESP32Servo@^3.0.5

;lib_deps = madhephaestus/ESP32Servo@^3.0.5 - ONLY THIS WORKS WITH ESP32 !

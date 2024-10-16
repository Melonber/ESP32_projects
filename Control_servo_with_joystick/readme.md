;Platformio.ini:<br>

[env:esp32-c3-devkitc-02]<br>
platform = espressif32<br>
board = esp32-c3-devkitc-02<br>
upload_port = /dev/cu.SLAB_USBtoUART<br>
framework = arduino<br>
monitor_speed = 115200<br>
lib_deps = madhephaestus/ESP32Servo@^3.0.5<br>
<br>
;lib_deps = madhephaestus/ESP32Servo@^3.0.5 - ONLY THIS WORKS WITH ESP32 !<br>

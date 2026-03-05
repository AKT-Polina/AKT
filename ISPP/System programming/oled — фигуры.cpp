#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

Adafruit_SSD1306 display(128, 64, &Wire, -1);

void setup() {
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C); // Инициализация
  display.clearDisplay(); // Очистка буфера

  // 1. Рисуем рамку
  display.drawRect(0, 0, 128, 64, WHITE);

  // 2. Рисуем закрашенный круг в центре
  display.fillCircle(64, 32, 15, WHITE);

  // 3. Отправляем на экран
  display.display(); 
}

void loop() {}

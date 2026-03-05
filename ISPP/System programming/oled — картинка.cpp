#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// массив из конвертера (пример иконки 16x16)
const unsigned char myBitmap [] PROGMEM = {
  0x00, 0x00, 0x01, 0x80, 0x03, 0xc0, 0x07, 0xe0, 0x07, 0xe0, 0x0f, 0xf0, 0x1f, 0xf8, 0x1f, 0xf8,
  0x1f, 0xf8, 0x1f, 0xf8, 0x0f, 0xf0, 0x07, 0xe0, 0x07, 0xe0, 0x03, 0xc0, 0x01, 0x80, 0x00, 0x00
};

Adafruit_SSD1306 display(128, 64, &Wire, -1);

void setup() {
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();

  // Вывод битмапа:
  // drawBitmap(x, y, имя_массива, ширина, высота, цвет)
  display.drawBitmap(32, 16, myBitmap, 16, 16, WHITE);

  display.display();
}

void loop() {}

// библиотеки для работы с OLED экраном Arduino IDE
#include "Wire.h"
#include "Adafruit_GFX.h"
#include "Adafruit_SSD1306.h"

Adafruit_SSD1306 display(128, 64, &Wire, 4); // указываем размер экрана в пикселях

void setup() {
   display.begin(SSD1306_SWITCHCAPVCC, 0x3C); // указываем адрес устройства на шине
   display.clearDisplay();
   display.setTextSize(1, 2); // указываем размер шрифта
   display.setTextColor(SSD1306_WHITE); // указываем цвет надписи

   display.setCursor(30, 10);
   display.println("ARDUINO");
   display.display();
   delay(3000);
   display.clearDisplay(); // очищаем экран
}

void loop() {
   display.setTextSize(3); // указываем размер шрифта
   display.setTextColor(SSD1306_WHITE); // указываем цвет надписи

   for (int i = 0; i <= 100; i++) {
      display.setCursor(20, 10);
      display.println(i);
      display.display();
      delay(100);
      display.clearDisplay(); // очищаем экран
   }

}
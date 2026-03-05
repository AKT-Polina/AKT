#include "OLED_I2C.h" // библиотека для oled экрана
OLED  myOLED(SDA, SCL, 8); // создаем объект myOLED

extern uint8_t RusFont[]; // подключаем русский шрифт

void setup() {
   // инициализируем экран с русским шрифтом
   myOLED.begin();
   myOLED.setFont(RusFont);
}

void loop() {

   // бегущая строка на oled с русскими буквами
   for (int i = 128; i >= -40; i--) {
      myOLED.print("GHBDTN!", i, 32);
      myOLED.update();
      delay(5);
      myOLED.clrScr(); // очищаем экран OLED
   }

   // выплывающая строка на oled с русскими буквами
   for (int i = -10; i <= 80; i++) {
      myOLED.print("GHBDTN!", CENTER, i);
      myOLED.update();
      delay(5);
      myOLED.clrScr(); // очищаем экран OLED
   }

}
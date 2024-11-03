#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  Serial.begin(9600);
  lcd.begin(16,2);
  lcd.backlight();
  lcd.setCursor(1, 0);
  lcd.print("hello");
  lcd.setCursor(6, 9);
  lcd.print("2020");
}

void loop() {
}

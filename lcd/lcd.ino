#include <LiquidCrystal.h>

LiquidCrystal lcd(3,5,8,9,10,11);

void setup()
{
  lcd.begin(16,2);
lcd.print("Bac 2k24 ");
  lcd.setCursor(1, 1);
  lcd.print("admis Inshallah");
  lcd.setCursor(1, 1);
}
void loop()
{

}
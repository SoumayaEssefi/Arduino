#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>

#define DHTPIN 6        
#define DHTTYPE DHT11   

DHT dht(DHTPIN, DHTTYPE);

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  Serial.begin(9600);
  
  dht.begin();
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
}

void loop() {
  int humidity = dht.readHumidity();
  int temperature = dht.readTemperature();
  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.print(" %\t");
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println("C");

  lcd.setCursor(0, 1);
  lcd.print("Temp:");
  lcd.print(temperature );
  lcd.setCursor(9, 1);
  lcd.print("Hum:");
  lcd.print(humidity);

  delay(2000);
}

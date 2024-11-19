#define ldrPin  A0  
#define ledPin  9     

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(ldrPin, INPUT_PULLUP);

}

void loop() {
 
  int lumiere = analogRead(ldrPin);
  int a = map(lumiere, 0, 1023, 0, 255); 
  analogWrite(ledPin, a);
  delay(20);  
}

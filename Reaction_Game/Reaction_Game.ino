#define led 2
#define button 12
#define buzzer 13
float game ;
unsigned long starttime ;
unsigned long Clicktime ;

void setup() {
  // put your setup code here, to run once:
  pinMode( led , OUTPUT);
  pinMode( buzzer , OUTPUT);
  pinMode(button, INPUT_PULLUP);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  int intervale = random(0,6000);
  digitalWrite(buzzer, HIGH);
  delay(100);
   digitalWrite(buzzer, LOW);
  delay(intervale);
  digitalWrite(led,HIGH);
  starttime = millis();
  game = true;
while (game ){
  if (digitalRead(button) == LOW){
    Clicktime = millis();
    digitalWrite(led,LOW);

  unsigned long time = Clicktime - starttime ;
  Serial.print("letemps est :");
  Serial.print(time);
  Serial.println("letemps est :");

  game = false;
  delay (1000);


  }
}
}


#define led 2
#define button 12
void setup() {
  // put your setup code here, to run once:
pinMode( led , OUTPUT);
pinMode(button, INPUT_PULLUP);

}

void loop() {
  // put your main code here, to run repeatedly:
if (digitalRead(button) == HIGH){
  digitalWrite(led,LOW);}
else{
  digitalWrite(led,HIGH);
}
}

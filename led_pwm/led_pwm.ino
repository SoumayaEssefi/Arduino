#define led 10
int i;
void setup() {
  // put your setup code here, to run once:
pinMode( led , OUTPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  for ( i = 10; i<=255; i++){
  analogWrite(led, i);
  Serial.println(i);
  delay(10);

  }

}

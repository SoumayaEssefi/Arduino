#define trigPin  11
#define echoPin  10
#define Buzzer  7

void setup() {
 
  Serial.begin(9600);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(Buzzer, OUTPUT);

}

void loop() {


  digitalWrite(trigPin, LOW);
  delay(200);
  digitalWrite(trigPin, HIGH);
  delay(200);
  digitalWrite(trigPin, LOW);

  long temps = pulseIn(echoPin, HIGH);
  long distance = temps * 0.034 / 2; 

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  int timer = distance * 10;
  
  if (distance <60) {
    digitalWrite(Buzzer, HIGH);
    delay(timer);
    digitalWrite(Buzzer, LOW);
    delay(timer);

  } else {

    digitalWrite(Buzzer, LOW);
 
  }


}

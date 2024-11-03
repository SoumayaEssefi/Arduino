#include <Servo.h>;
#define trigPin  9
#define echoPin  8
#define servoPin  10

Servo doorServo;

void setup() {
 
  Serial.begin(9600);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  doorServo.attach(servoPin);

  doorServo.write(0);
}

void loop() {

  long temps;
  long distance;

  digitalWrite(trigPin, LOW);
  delay(200);
  digitalWrite(trigPin, HIGH);
  delay(200);
  digitalWrite(trigPin, LOW);

  temps = pulseIn(echoPin, HIGH);
  distance = temps * 0.034 / 2; 

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  
  if (distance <30) {
    
    doorServo.write(90);
    Serial.println("open");
  } else {
    
    doorServo.write(0);
    Serial.println("close");
  }

  delay(500);
}

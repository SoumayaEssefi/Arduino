#define capteur A0
#define pumpPin 8            

int seuil = 400;  

void setup() {
  pinMode(pumpPin, OUTPUT);
  pinMode(capteur, INPUT);   
  Serial.begin(9600);        
}

void loop() {
  int a = analogRead(capteur); 
  Serial.print("Niveau d'humidité du sol : ");
  Serial.println(a);                     

  if (a < seuil) {
    digitalWrite(pumpPin, HIGH); 
  } else {
    digitalWrite(pumpPin, LOW);   
  }

  delay(2000); }

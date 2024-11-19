#define gasPin A0       
#define flamePin 2      
#define alertPin 8      

int gas_seuil = 200;    
int flameThreshold = HIGH; 

void setup() {
  pinMode(gasPin, INPUT);     
  pinMode(flamePin, INPUT);    
  pinMode(alertPin, OUTPUT);   
  Serial.begin(9600);          
}

void loop() {
  int gasLevel = analogRead(gasPin);             
  int flameStatus = digitalRead(flamePin);        

  Serial.print("Niveau de gaz : ");
  Serial.println(gasLevel);                       
  Serial.print("Flamme détectée : ");
  Serial.println(flameStatus);                     

  if (gasLevel > gas_seuil || flameStatus == LOW) {
    digitalWrite(alertPin, HIGH);  
  } else {
    digitalWrite(alertPin, LOW);   
  }

  delay(1000);
}

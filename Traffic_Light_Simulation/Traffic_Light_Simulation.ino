#define LED_ROUGE 2
#define LED_ORANGE 3
#define LED_VERT 4
#define BUTTON 12

int etat = 0; 
void setup() {
  pinMode(LED_ROUGE, OUTPUT);
  pinMode(LED_ORANGE, OUTPUT);
  pinMode(LED_VERT, OUTPUT);
  pinMode(BUTTON, INPUT_PULLUP); 
  Serial.begin(9600);
}

void loop() {
  if (digitalRead(BUTTON) == LOW) {
    delay(50);
    etat = (etat+1)%4; 
    Serial.println(etat);

  switch (etat) {
    case 0: 
      digitalWrite(LED_ROUGE, HIGH);
      digitalWrite(LED_ORANGE, LOW);
      digitalWrite(LED_VERT, LOW);
      break;

    case 1: 
      digitalWrite(LED_ROUGE, HIGH);
      digitalWrite(LED_ORANGE, HIGH);
      digitalWrite(LED_VERT, LOW);
      break;

    case 2: 
      digitalWrite(LED_ROUGE, LOW);
      digitalWrite(LED_ORANGE, LOW);
      digitalWrite(LED_VERT, HIGH);
      break;

    case 3: 
      digitalWrite(LED_ROUGE, LOW);
      digitalWrite(LED_ORANGE, HIGH);
      digitalWrite(LED_VERT, LOW);
      break;
  }
  delay(200); 
}}

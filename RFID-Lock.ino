#include <SPI.h>
#include <MFRC522.h>
#include <WiFi.h>
#include <FirebaseESP32.h>
#include <NTPClient.h>
#include <WiFiUdp.h>
const char *ssid = "soumaya"; 
const char *password = "******";
const char *firebaseHost = "https://******.firebaseio.com/";  
const char *databaseSecret = "************";  
FirebaseData firebaseData;

#define SS_PIN 2
#define RST_PIN 5
MFRC522 rfid(SS_PIN, RST_PIN);

#define lock 17 // Pin pour contrôler le verrou

WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "pool.ntp.org", 3600); 

String uidString = ""; 

void setup() {
  Serial.begin(9600);
  SPI.begin();
  pinMode(lock, OUTPUT);
  rfid.PCD_Init();
  Serial.println("Initialisation en cours...");

  connectWiFi();

  Firebase.begin(firebaseHost, databaseSecret);
  Firebase.reconnectWiFi(true);

  timeClient.begin();
  Serial.println("Approchez une carte RFID...");
}

void loop() {
  if (!timeClient.update()) {
    timeClient.forceUpdate();
  }

  if (!rfid.PICC_IsNewCardPresent() || !rfid.PICC_ReadCardSerial())
    return;

  uidString = "";
  for (byte i = 0; i < rfid.uid.size; i++) {
    uidString += (rfid.uid.uidByte[i] < 0x10 ? "0" : "") + String(rfid.uid.uidByte[i], HEX);
  }

  Serial.print("UID détecté : ");
  Serial.println(uidString);

  if (checkUIDInFirebase(uidString)) {
    unlock(); 
    logAccess(uidString, "Accès autorisé");
  } else {
    lockDoor();
    logAccess(uidString, "Accès refusé");
  }

  rfid.PICC_HaltA();
}

void connectWiFi() {
  Serial.println("Connexion au WiFi...");
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }
  Serial.println("\nConnecté au WiFi !");
}

bool checkUIDInFirebase(String uid) {
  String path = "/uids/" + uid;  
  if (Firebase.getBool(firebaseData, path)) {
    return firebaseData.boolData();
  }
  return false;  
}

void logAccess(String uid, String status) {
  String path = "/logs/" + String(millis()); 
  String time = timeClient.getFormattedTime();
  String date = getFormattedDate();         
  Firebase.setString(firebaseData, path + "/uid", uid);
  Firebase.setString(firebaseData, path + "/status", status);
  Firebase.setString(firebaseData, path + "/time", time);
  Firebase.setString(firebaseData, path + "/date", date);

  Serial.println("Enregistrement dans Firebase :");
  Serial.println("UID : " + uid);
  Serial.println("Status : " + status);
  Serial.println("Heure : " + time);
  Serial.println("Date : " + date);
}

void unlock() {
  digitalWrite(lock, HIGH);  
  Serial.println("Verrou ouvert !");
  delay(3000);              
  digitalWrite(lock, LOW);   

void lockDoor() {
  Serial.println("Accès refusé. Verrou fermé.");
  digitalWrite(lock, LOW); 
  delay(1000);
}

String getFormattedDate() {
  time_t rawtime = timeClient.getEpochTime();  
  struct tm *timeinfo = gmtime(&rawtime);
  char buffer[11];
  sprintf(buffer, "%04d-%02d-%02d", timeinfo->tm_year + 1900, timeinfo->tm_mon + 1, timeinfo->tm_mday);
  return String(buffer);  
}
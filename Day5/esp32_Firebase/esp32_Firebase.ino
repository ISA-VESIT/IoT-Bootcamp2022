#include <Arduino.h>
#include <WiFi.h>
#include <FirebaseESP32.h>

//Helper Token
#include "addons/TokenHelper.h"
//RTDB payload printing info and other helper functions.
#include "addons/RTDBHelper.h"

// Wifi Creds
#define WIFI_SSID "---------"
#define WIFI_PASSWORD "********"

// Firebase API Key
#define API_KEY "**********"

// Firebase Database URL
#define DATABASE_URL "https://******.firebaseio.com/" 

//Define Firebase Data object
FirebaseData fbdo;

FirebaseAuth auth;
FirebaseConfig config;

unsigned long sendDataPrevMillis = 0;
int ledValue;
int ledAVal;
int ledBrightnessValue;
bool signupOK = false;

int led = 2 ;
int led2 = 16;

void setup() {
  Serial.begin(115200);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Connecting to Wi-Fi");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(300);
  }
  Serial.println();
  Serial.print("Connected with IP: ");
  Serial.println(WiFi.localIP());
  Serial.println();

//  API Key setup
  config.api_key = API_KEY;

//  Database URL setup
  config.database_url = DATABASE_URL;

//SignUP
  if (Firebase.signUp(&config, &auth, "", "")) {
    Serial.println("ok");
    signupOK = true;
  }
  else {
    Serial.printf("%s\n", config.signer.signupError.message.c_str());
  }

//callback function for the long running token generation task
  config.token_status_callback = tokenStatusCallback; //see addons/TokenHelper.h

  Firebase.begin(&config, &auth);
  Firebase.reconnectWiFi(true);

  pinMode(led,OUTPUT);
  pinMode(led2 , OUTPUT);

  ledcAttachPin(led2, 1);
  ledcSetup(1, 12000, 8);
}

void loop() {
  if (Firebase.ready() && signupOK && (millis() - sendDataPrevMillis > 15000 || sendDataPrevMillis == 0)) {
    sendDataPrevMillis = millis();
    if (Firebase.RTDB.getInt(&fbdo, "/led/ON_OFF")) {
      if (fbdo.dataType() == "int") {
        ledValue = fbdo.intData();
        Serial.println(ledValue);
        if(ledValue == 1){
          digitalWrite(led,HIGH);
        }else{
          digitalWrite(led,LOW);
        }
      }
    }
    else {
      Serial.println(fbdo.errorReason());
    }
    
    if (Firebase.RTDB.getInt(&fbdo, "/led/Brightness")) {
      if (fbdo.dataType() == "int") {
        ledBrightnessValue = fbdo.intData();
        if(0 <= ledBrightnessValue <= 4095){
          ledAVal = map(ledBrightnessValue, 0, 4095, 255, 0);
          ledcWrite(1,ledAVal);
        }
      }
    }
    else {
      Serial.println(fbdo.errorReason());
    }
  }
}

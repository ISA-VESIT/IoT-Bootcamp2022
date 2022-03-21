#include "BluetoothSerial.h"
BluetoothSerial SerialBT;

char receivedChar;// received value will be stored as CHAR in this variable

const char turnON ='Buzzer on';
const char turnOFF ='Buzzer off';
const int LEDpin = 16;

void setup() {
  Serial.begin(115200);
  SerialBT.begin("ESP32_test"); //Bluetooth device name
  pinMode(LEDpin, OUTPUT);
 
}

void loop() {
    receivedChar =(char)SerialBT.read();

  if (Serial.available()) {
    SerialBT.write(Serial.read());
  
  }
  if (SerialBT.available()) {
    
    
    if(receivedChar == turnON)
    {
    
     Serial.println("LED ON:");//write on serial monitor
     digitalWrite(LEDpin, HIGH);// turn the LED ON
       
    }
    if(receivedChar == turnOFF)
    {
     
     Serial.println("LED OFF:");//write on serial monitor
      digitalWrite(LEDpin, LOW);// turn the LED off 
    }    
     
  

  }
  delay(20);
}

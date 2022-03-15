//-----Esp32 Led Blink-----

int led = 2; //Pre-defined Led pin in esp32

void setup() {
  
pinMode(led,OUTPUT); //To configure if the pin as an Output pin.

}

void loop() {
  
  digitalWrite(led,HIGH); //Set the led pin to high i.e. turn the led on
  delay(1000); //Wait for 1 sec
  digitalWrite(led,LOW); //Set the led pin to low i.e. turn the led off
  delay(1000); //Wait for 1 sec

}

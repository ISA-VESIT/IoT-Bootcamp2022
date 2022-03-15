//----Blink LED 5 times using for loop

int led =2;
int i = 0; //Initalising i
void setup() {
  
  pinMode(led,OUTPUT);
  Serial.begin(115200); //Starting Serial communication

}

void loop() {

  for(i ; i<5 ; i++){
    digitalWrite(led,HIGH);
    Serial.println(i);
    delay(1000);
    digitalWrite(led,LOW);
    delay(1000);
  }
  
}

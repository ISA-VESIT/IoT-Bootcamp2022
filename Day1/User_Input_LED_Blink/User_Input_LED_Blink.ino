//Taking input from serial moniter

int led = 2; 
void setup() {
  
  pinMode(led,OUTPUT);
  Serial.begin(115200); //To start serial communication at a baud rate of 115200 

}

void loop() {

  Serial.println("Enter blink times :"); //Asking user to enter value
  while(Serial.available() == 0){} // Waiting for user to enter value
  int num = Serial.parseInt(); // Reading value entered by user
  
  int i = 1;                //initialising i    
  while(i <= num){
    digitalWrite(led,HIGH); //Led on
    Serial.println(i);     //Couting the number of blinks 
    delay(1000);           //1 sec delay
    digitalWrite(led,LOW); //Led off
    delay(1000);           //1 sec delay
    i++;                   //incrementing i
  }

}

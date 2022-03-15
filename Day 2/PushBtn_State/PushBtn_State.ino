int led = 16;
int pushBtn = 15;
int buttonOld = 0;
int buttonNew = 1;
int ledState = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(led,OUTPUT);
  pinMode(pushBtn,INPUT);
  Serial.begin(115200);
  
}

void loop() {
  // put your main code here, to run repeatedly:

  buttonNew = digitalRead(pushBtn);
  if(buttonNew == 1 && buttonOld ==0){
    if(ledState == 0){
      digitalWrite(led,HIGH);
      ledState = 1;
    }else{
      digitalWrite(led,LOW);
      ledState = 0;
    }
  }

  buttonOld = buttonNew;
  
  delay(100);
}

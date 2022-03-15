int led = 16;
int pushBtn = 15;
bool pushBtnState = 0;
void setup() {
  // put your setup code here, to run once:
  pinMode(pushBtn,INPUT);
  pinMode(led,OUTPUT);
  Serial.begin(115200);
  
}

void loop() {
  // put your main code here, to run repeatedly:
 pushBtnState = digitalRead(pushBtn);
 Serial.println(pushBtnState);
 if(pushBtnState == 0){
  digitalWrite(led,LOW); 
 }else{
  digitalWrite(led,HIGH);
 }

}

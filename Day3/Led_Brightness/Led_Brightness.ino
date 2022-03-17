int potpin = 33;
int led = 16;
int potVal;
byte ledVal;

void setup() {
  // put your setup code here, to run once:
  pinMode(potpin,INPUT);
  pinMode(led,OUTPUT);
  Serial.begin(115200);
  ledcAttachPin(led, 1);
ledcSetup(1, 12000, 8);

}

void loop() {
  // put your main code here, to run repeatedly:
  potVal = analogRead(potpin);
  ledVal = map(potVal, 0, 4095, 255, 0);
  ledcWrite(1,ledVal);
  Serial.println(ledVal);

}

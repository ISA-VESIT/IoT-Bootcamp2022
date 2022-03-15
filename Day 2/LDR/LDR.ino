#define ldrpin 32
#define ledpin 25

int value = 0;

void setup() {
  Serial.begin(115200);
  pinMode(ledpin, OUTPUT);
  pinMode(ldrpin, INPUT);
}

void loop() {
  value = analogRead(ldrpin);
  Serial.println("LDR value is: ");
  Serial.println(value);
  if (value >=2000)                    //Define a threshold value 
  {
    digitalWrite(ledpin, LOW);      //If less than threshold turn led on 
  }
  else
  {
    digitalWrite(ledpin,HIGH);       // If more than threshold, turn it off
  }
  delay(100);
}

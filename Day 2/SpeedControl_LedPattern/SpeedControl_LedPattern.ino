int potpin = 33 ;
int timer;

int ledPins[] = {
  16,17,25,26,27,5,18,19,15};       // an array of pin numbers to which LEDs are attached
int pinCount = 9;                   // the number of pins (i.e. the length of the array)

int pot;
void setup() 
{

  Serial.begin(115200); //Start serial communication 
  for (int thisPin = 0; thisPin < pinCount; thisPin++) {
    pinMode(ledPins[thisPin], OUTPUT);
  }  
}

void loop() 
{
 
  for (int thisPin = 0; thisPin < pinCount; thisPin++)                // loop from the lowest pin to the highest:
  {
    digitalWrite(ledPins[thisPin], LOW);                              // turn the pin on:
    delay(timer);
    digitalWrite(ledPins[thisPin], HIGH);                              // turn the pin off:

  }

 
  for (int thisPin = pinCount - 1; thisPin >= 0; thisPin--)            // loop from the highest pin to the lowest:
  {
    digitalWrite(ledPins[thisPin], LOW);                               // turn the pin on:
    delay(timer); 
    digitalWrite(ledPins[thisPin], HIGH);                              // turn the pin off:
  }
  
  timer=analogRead(potpin);
  Serial.println(timer);

}

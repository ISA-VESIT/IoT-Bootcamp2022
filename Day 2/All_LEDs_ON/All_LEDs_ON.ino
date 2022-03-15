int ledPins[] = {
  16,17,25,26,27,5,18,19};        // an array of pin numbers to which LEDs are attached
int pinCount = 8;                    // the number of pins (i.e. the length of the array)


void setup() 
{

  for (int thisPin = 0; thisPin < pinCount; thisPin++) {
    pinMode(ledPins[thisPin], OUTPUT);
  }


}

void loop() 
{
 
  for (int thisPin = 0; thisPin < pinCount; thisPin++)              // loop 
  {
       digitalWrite(ledPins[thisPin], LOW);                           // turn the pin on:
  }


}

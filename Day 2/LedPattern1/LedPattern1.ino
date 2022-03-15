int ledPins[] = {
  16,17,25,26,27,5,18,19};        // an array of pin numbers to which LEDs are attached
int pinCount = 8;                    // the number of pins (i.e. the length of the array)
int timer = 200;                     // The higher the number, the slower the timing.

void setup() 
{

  for (int thisPin = 0; thisPin < pinCount; thisPin++) {
    pinMode(ledPins[thisPin], OUTPUT);
  }


}

void loop() 
{
 
  for (int thisPin = 0; thisPin < pinCount; thisPin++)              // loop from the lowest pin to the highest:
  {
    digitalWrite(ledPins[thisPin], LOW);                            // turn the pin off:
    delay(timer);
    digitalWrite(ledPins[thisPin], HIGH);                           // turn the pin on:

  }


  for (int thisPin = pinCount - 1; thisPin >= 0; thisPin--)         // loop from the highest pin to the lowest:
  {
    digitalWrite(ledPins[thisPin], LOW);                            // turn the pin off:
    delay(timer);
    digitalWrite(ledPins[thisPin], HIGH);                           // turn the pin on:
  }




}

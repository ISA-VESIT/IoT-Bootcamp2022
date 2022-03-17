#include <Wire.h>
#include <TM1650.h>

TM1650 d;

void setup() 
{
  Wire.begin();
  d.init();

  d.displayOff();
  d.displayString("__");
  d.setBrightness(TM1650_MIN_BRIGHT);
  d.displayOn();
  delay(100);
  char line[]="ISA";
 d.displayString(line);
 d.setBrightnessGradually(TM1650_MAX_BRIGHT);
  
   
}

void loop() 
{
  
}

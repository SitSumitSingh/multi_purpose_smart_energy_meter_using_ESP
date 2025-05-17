#include "EmonLib.h"                   // Include Emon Library
EnergyMonitor emon1;                   // Create an instance
void setup()
{  
  Serial.begin(9600);
  
  emon1.current(35, 111);             // Current: input pin, calibration.
}

void loop()
{
  float Irms = emon1.calcIrms(1480);  // Calculate Irms only


  float raw = analogRead(35);
  Serial.println(raw);
  delay(500);


  
  Serial.println(Irms,3);		       // Irms
}
#include <EmonLib.h>  // Include EmonLib

EnergyMonitor emon1;  // Create an instance

void setup()
{
  Serial.begin(9600);
  emon1.voltage(35, 120.0, 1); 
  // Arguments: (analogPin, calibration constant, phase shift)
  // Adjust the calibration constant based on your ZMPT101B
}

void loop()
{
  emon1.calcVI(20, 2000);  // Calculate voltage (20 half-cycles, timeout 2000 ms)
  float voltage = emon1.Vrms;

 // Serial.print("Voltage: ");
  Serial.println(voltage);
  //Serial.println(" V");

  delay(1000);
}

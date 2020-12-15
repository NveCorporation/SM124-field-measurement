/*********************************************************************************  
Reads magnetic field from an SM124 smart sensor with an Arduino. 
Connect sensor power to Arduino 3.3 V and connect I²C SDA and SCL.
Demo at: https://youtu.be/PDNVEmkQcs0
www.nve.com * www.YouTube.com/NveCorporation * sensor-apps@nve.com * Rev. 12/10/20
*********************************************************************************/
#include <Wire.h> //I²C  Library
void setup() {
  Serial.begin(57600); //Initialize serial port
  Wire.begin(); //Join I²C bus as master
}
void loop() {
  Wire.requestFrom(36,1); //Request one byte from the SM124 (I²C address 72/2=36)
  Serial.print(float(Wire.read())/100); //Read, scale, and print sensor output
  Serial.print(" mT \r" );
  delay(100); //10 samples/second
}

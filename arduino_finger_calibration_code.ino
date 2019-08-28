#include <i2c_t3.h>

//Arduino finger calibration code



#include <SparkFun_ADS1015_Arduino_Library.h>


ADS1015 left_pinkyring;
ADS1015 left_indexmiddle;
ADS1015 right_pinkyring;
ADS1015 right_indexmiddle;






void setup() {
  Wire.begin();
  Serial.begin(115200);


  if (left_pinkyring.begin(Wire, 100000, ADS1015_ADDRESS_SCL) == false)
  {
    Serial.println(" check left ring and pinky. they are missing/missconnected.");
    while(1);
  }
   if (left_indexmiddle.begin(Wire, 100000, ADS1015_ADDRESS_VDD) == false)
  {
    Serial.println(" check left index and middle. they are missing/missconnected.");
    while(1);
  }
  if (right_pinkyring.begin(Wire, 100000, ADS1015_ADDRESS_SDA) == false)
  {
    Serial.println(" check left ring and pinky. they are missing/missconnected.");
    while(1);
  }
   if (right_indexmiddle.begin(Wire, 100000, ADS1015_ADDRESS_GND) == false)
  {
    Serial.println(" check right index and middle. they are missing/missconnected.");
    while(1);
  }

  Serial.println("Calibrating, flex all sensors through full range of motion multiple times, send 'a' when finished");


}

void loop() {
  uint8_t fingercalib;
  do
  {
      //fingerset = left_pinkyring.calibrate();
      //fingerset = left_indexmiddle.calibrate();
      //fingerset = right_indexmiddle.calibrate();
      //fingerset = right_pinkyring.calibrate();
  }while (fingercalib != 'a');
  Serial.println("calibration finished");
  for(int finger; finger < 2; finger++)
  {
      Serial.print("finger");
      Serial.print(finger);
      Serial.print(":");
      for (int variance =0; variance< 2; variance++)
      {
          switch(variance)
          {
        case 0:
        Serial.print("Low: ");
        Serial.print(left_pinkyring.getCalibration(finger, variance));
        break;
        case 1:
        Serial.print(" High: ");
        Serial.print(left_pinkyring.getCalibration(finger, variance));
        break;
      }
    }
    Serial.println();
  }
}

 

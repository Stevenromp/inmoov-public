#include <SPI.h>
#include<Servo.h>
#include<Wire.h>
#include <SparkFun_ADS1015_Arduino_Library.h>

Servo pinkyLeft;
Servo indexLeft;
Servo middleLeft;
Servo wristLeft;
Servo thumbLeft;
Servo ringLeft;


Servo pinkyRight;
Servo ringRight;
Servo middleRight;
Servo indexRight;
Servo thumbRight;
Servo wristRight;

Servo lshoulder_x;
Servo lshoulder_y;
Servo lshoulder_z;
Servo l_bicep;
Servo rshoulder_x;
Servo rshoulder_y;
Servo rshoulder_z;
Servo r_bicep;

ADS1015 left_pinkyring;
ADS1015 left_indexmiddle;
ADS1015 right_pinkyring;
ADS1015 right_indexmiddle;

//thumb flex code define
int flexLthumb = A0;
int flexRthumb = A1;

int flexLthumb_val;
int flexRthumb_val;

//bicep myoware code define
int myoLbicep = A3;
int myoRbicep = A4;

int myoLbicep_val;
int myoRbicep_val;


float r_hands[4] = {0, 0, 0, 0};
float l_hands[4] = {0, 0, 0, 0};
uint16_t handCalibrationL[4][2] =
{ //hi, low values
  {916, 820}, //index
  {890, 1090}, //middle
  {840, 1090}, //ring
  {670, 873} //pinky
};
uint16_t handCalibrationR[4][2] =
{ //hi, low values
  {730, 1090}, //index
  {790, 899}, //middle
  {720, 906}, //ring
  {730, 900} //pinky
};

uint32_t i2cSpeed = 100000;




int test = 0;

void setup() {
  Wire.begin();
  Serial.begin(115200);

  {
    if (left_pinkyring.begin(Wire, i2cSpeed, ADS1015_ADDRESS_SCL)  ==  false)
    {
      Serial.println(" check left ring and pinky. they are missing/missconnected.");
      while (1);
    }
    if (left_indexmiddle.begin(Wire, i2cSpeed, ADS1015_ADDRESS_VDD)  ==  false)
    {
      Serial.println(" check left index and middle. they are missing/missconnected.");
      while (1);
    }
    if (right_pinkyring.begin(Wire, i2cSpeed, ADS1015_ADDRESS_SDA)  ==  false)
    {
      Serial.println(" check left ring and pinky. they are missing/missconnected.");
      while (1);
    }
    if (right_indexmiddle.begin(Wire, i2cSpeed, ADS1015_ADDRESS_GND)  ==  false)
    {
      Serial.println(" check right index and middle. they are missing/missconnected.");
      while (1);
    }
  }

  //left hand calibration
  for (int finger; finger < 2; finger++)
  {
    for (int hiLo = 0; hiLo < 2; hiLo++)
    {
      left_pinkyring.setCalibration(finger, hiLo, handCalibrationL[finger][hiLo]);
      left_indexmiddle.setCalibration(finger, hiLo, handCalibrationL[finger + 2][hiLo]);
    }
  }
  //right hand calibration
  for (int finger; finger < 2; finger++)
  {
    for (int hiLo = 0; hiLo < 2; hiLo++)
    {
      right_pinkyring.setCalibration(finger, hiLo, handCalibrationL[finger][hiLo]);
      right_indexmiddle.setCalibration(finger, hiLo, handCalibrationL[finger + 2][hiLo]);
    }
  }
  pinMode(flexLthumb, INPUT);
  pinMode(flexRthumb, INPUT);

  pinkyRight.attach(2);
  ringRight.attach(3);
  middleRight.attach(4);
  indexRight.attach(5);
  thumbRight.attach(6);
  wristRight.attach(7);

  pinkyLeft.attach(29);
  ringLeft.attach(30);
  middleLeft.attach(23);
  indexLeft.attach(22);
  thumbLeft.attach(21);
  wristLeft.attach(20);


  //    lshoulder_x.attach();
  //lshoulder_y.attach(29);
  //    lshoulder_z.attach();
  l_bicep.attach(29);
  //    rshoulder_x.attach();
  //  rshoulder_y.attach(30);
  //    rshoulder_z.attach();
  r_bicep.attach(30);
  pinMode(13, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(13, HIGH);


  uint16_t  data;
  for (int finger = 0; finger <=  1; finger++)
  {
    r_hands[finger] = right_indexmiddle.getScaledAnalogData(finger);
    r_hands[finger + 2] = right_pinkyring.getScaledAnalogData(finger);
    l_hands[finger] = left_indexmiddle.getScaledAnalogData(finger);
    l_hands[finger + 2] = left_pinkyring.getScaledAnalogData(finger);
  }

  //Thumb Flex code

  flexLthumb_val = analogRead(flexLthumb);
  flexLthumb_val = map(flexLthumb_val, -17, 40, 10, 170);
  flexRthumb_val = analogRead(flexRthumb);
  flexRthumb_val = map(flexRthumb_val, -21, 45, 10, 170);

  //myoware code
  myoLbicep_val = analogRead(myoLbicep);
  myoLbicep_val = map(myoLbicep_val, 80 , 984 , 65 , 135);
  myoRbicep_val = analogRead(myoRbicep);
  myoRbicep_val = map(myoRbicep_val, 90 , 982 , 45, 100);
  delay(300);



  pinkyRight.write(r_hands[0]);
  ringRight.write(r_hands[1]);
  middleRight.write(r_hands[2]);
  indexRight.write(r_hands[3]);
  thumbRight.write(flexRthumb_val);
  //wristRight.write()

  pinkyLeft.write(r_hands[0]);
  ringLeft.write(r_hands[1]);
  middleLeft.write(r_hands[2]);
  indexLeft.write(r_hands[3]);
  thumbLeft.write(flexRthumb_val);
  //wristLeft.write();

  r_bicep.write(myoRbicep_val);
  l_bicep.write(myoLbicep_val);




  digitalWrite(13, LOW);
  delay(500);
}

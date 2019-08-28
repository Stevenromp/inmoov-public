#include <SparkFun_ADS1015_Arduino_Library.h>

#include<Servo.h>
int servoOne = 2;
int servoTwo = 3;
int servoThree = 4;
int servoFour = 5;
int servoFive = 6;
int servoSix = 7;
int servoSeven = 8;
int servoEight = 9;
int servoNine = 10;
int servoTen = 29;
int servoElbowPit= 38;

Servo servoTestOne;
Servo servoTestTwo;
Servo servoTestThree;
Servo servoTestFour;
Servo servoTestFive;
Servo servoTestSix;
Servo servoTestSeven;
Servo servoTestEight;
Servo servoTestNine;
Servo servoTestTen;
Servo servoTestElbowPit;

int test = 0;

void setup() {
  // put your setup code here, to run once:
    servoTestOne.attach(servoOne);
    servoTestTwo.attach(servoTwo);
    servoTestThree.attach(servoThree);
    servoTestFour.attach(servoFour);
    servoTestFive.attach(servoFive);
    servoTestSix.attach(servoSix);
    servoTestSeven.attach(servoSeven);
    servoTestEight.attach(servoEight);
    servoTestNine.attach(servoNine);
    servoTestTen.attach(servoTen);
    servoTestElbowPit.attach(servoElbowPit);

    Serial.begin(38400);
    pinMode(13, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(13, HIGH);

 // test += 2;
 // if (test > 170)
 //   test = 0;
 // Serial.println(test);
  
  //delay(25);
  test =0;
  Serial.println("Closed");
  servoTestOne.write(test);
  servoTestTwo.write(test);
  servoTestThree.write(test);
  servoTestFour.write(test);
  servoTestFive.write(test);
  servoTestSix.write(test);
  servoTestSeven.write(test);
  servoTestEight.write(test);
  servoTestNine.write(test);
  servoTestTen.write(test);
  ControlElbow(test);
  
  resetHand();

  delay(2000);
  resetHand();

  test = 170;
  Serial.println("Finger");
  servoTestThree.write(test);
  servoTestSeven.write(test);
  ControlElbow(test);


  delay(2000);
  resetHand();

  test = 170;
  Serial.println("Sign");
  servoTestTwo.write(test);
  servoTestFour.write(test);
  servoTestSix.write(test);
  ControlElbow(test);


  delay(2000);
  resetHand();

  test = 170;
  Serial.println("Peace");
  servoTestFour.write(test);
  servoTestSix.write(30);
  servoTestSeven.write(test);
  ControlElbow(255);

  
  delay(2000);
  resetHand();
  Serial.println("Dog Walk");
  for (int ind = 0; ind < 20; ind++)
  {
    if (ind %2 == 0)
    {
      test = 170;
    }
    else 
    {
      test = 120;
    }
  servoTestFour.write(test);
  servoTestSix.write(30);
  delay(15);
  servoTestSeven.write(test);
  ControlElbow(test);
  delay (100);
  }


  //delay(2000);
  resetHand();
  test = 170;
  Serial.println("Open");
  servoTestOne.write(test);
  servoTestTwo.write(test);
  servoTestThree.write(test);
  servoTestFour.write(test);
  servoTestFive.write(test);
  servoTestSix.write(test);
  servoTestSeven.write(test);
  servoTestEight.write(test);
  servoTestNine.write(test);
  servoTestTen.write(test);
  ControlElbow(255);


  delay(2000);
  resetHand();
}

void ControlElbow(int input)
{
  
  input = map(input, 0, 255, 45, 100);
  servoTestElbowPit.write(input);
  Serial.println(input);
}

void resetHand()
{
  test = 0;
  servoTestOne.write(test);
  servoTestTwo.write(test);
  servoTestThree.write(test);
  servoTestFour.write(test);
  servoTestFive.write(test);
  servoTestSix.write(test);
  servoTestSeven.write(test);
  servoTestEight.write(test);
  servoTestNine.write(test);
  servoTestTen.write(test);
}

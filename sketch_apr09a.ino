#include<Servo.h>

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

int test = 0;

void setup() {

  
    pinkyLeft.attach(2);
    ringLeft.attach(3);
    middleLeft.attach(4);
    indexLeft.attach(5);
    thumbLeft.attach(6);
    wristLeft.attach(7);

    pinkyRight.attach(29);
    ringRight.attach(30);
    middleRight.attach(23);
    indexRight.attach(22);
    thumbRight.attach(21);
    wristRight.attach(20);


//    lshoulder_x.attach();
    lshoulder_y.attach(29);
//    lshoulder_z.attach();
//    l_bicep.attach();
//    rshoulder_x.attach();
    rshoulder_y.attach(30);
//    rshoulder_z.attach();
//    r_bicep.attach();


    Serial.begin(38400);
    pinMode(13, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(13, HIGH);
  wristLeft.write(0);
     delay(2000);

 digitalWrite(13, LOW);
   //rshoulder_y.write(45);
   //delay(2000);

   resetHand();
  
// 
//  test =0;
//  Serial.println("0, closed");
//  pinkyLeft.write(test); 
//  indexLeft.write(test);
//  middleLeft.write(test);
//  wristLeft.write(test);
//  thumbLeft.write(test);
//  ringLeft.write(test);
//  delay(2000);
 

//  test =170;
//  Serial.println("170, flipped off");
//  //pinkyLeft.write(test); 
//  //indexLeft.write(test);
//  middleLeft.write(test);
//  //wristLeft.write(test);
//  //thumbLeft.write(test);
//  //ringLeft.write(test);
//  delay(2000);
//  resetHand();
//
//
//
//  test =170;
//  Serial.println("170, peace");
//  //pinkyLeft.write(test); 
//  indexLeft.write(test);
//  middleLeft.write(test);
//  //wristLeft.write(test);
//  //thumbLeft.write(test);
//  //ringLeft.write(test);
//  delay(2000);
//  resetHand();
//
//    test =170;
//  Serial.println("170, opened hand");
//  pinkyLeft.write(test); 
//  indexLeft.write(test);
//  middleLeft.write(test);
//  wristLeft.write(test);
//  thumbLeft.write(test);
//  ringLeft.write(test);
//  delay(2000);
//  resetHand();
//
//  test =170;
//  Serial.println("170, hang loose");
//  pinkyLeft.write(test); 
//  thumbLeft.write(50);
//  delay(40);
//  indexLeft.write(test);
//  //middleLeft.write(test);
//  //wristLeft.write(test);
//  delay(50);
//  thumbLeft.write(0);
//  //ringLeft.write(test);
//  delay(2000);
//  resetHand();
//
//    test =170;
//  Serial.println("170, peace");
//  //pinkyLeft.write(test); 
//  //indexLeft.write(test);
//  //middleLeft.write(test);
//  //wristLeft.write(test);
//  //thumbLeft.write(test);
//  //ringLeft.write(test);
//  delay(2000);
//  resetHand();
   
//
//  test =70;
//  Serial.println("70");
//  //pinkyLeft.write(test); 
//  //indexLeft.write(test);
//  //middleLeft.write(test);
//  //wristLeft.write(test);
//  //thumbLeft.write(test);
//  //ringLeft.write(test);
//  delay(2000);
//  //resetHand();
//
//  test =90;
//  Serial.println("90");
//  //pinkyLeft.write(test); 
//  //indexLeft.write(test);
//  //middleLeft.write(test);
//  //wristLeft.write(test);
//  //thumbLeft.write(test);
//  //ringLeft.write(test);
//  //delay(2000);
//  //resetHand();
//
//  test =100;
//  Serial.println("100");
//  //pinkyLeft.write(test); 
//  //indexLeft.write(test);
//  //middleLeft.write(test);
//  //wristLeft.write(test);
//  //thumbLeft.write(test);
//  //ringLeft.write(test);
//  delay(2000);
//  //resetHand();
//
//  test =120;
//  Serial.println("120");
//  //pinkyLeft.write(test); 
//  //indexLeft.write(test);
//  //middleLeft.write(test);
//  //wristLeft.write(test);
//  //thumbLeft.write(test);
//  //ringLeft.write(test);
//  delay(2000);
//  //resetHand();
//  test =140;
//  Serial.println("140");
//  //pinkyLeft.write(test); 
//  //indexLeft.write(test);
//  //middleLeft.write(test);
//  //wristLeft.write(test);
//  //thumbLeft.write(test);
//  //ringLeft.write(test);
//  delay(2000);
//  //resetHand();

}

void resetHand()
{
  test = 90;
   Serial.println("closed");
  pinkyLeft.write(test); 
  indexLeft.write(test);
  middleLeft.write(test);
  //wristLeft.write(test);
  delay(40);
  thumbLeft.write(test);
  ringLeft.write(test);
}

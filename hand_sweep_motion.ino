/* Sweep
 by BARRAGAN <http://barraganstudio.com>
 This example code is in the public domain.

 modified 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Sweep
*/

#include <Servo.h>

Servo thumb;  // create servo object to control a servo
Servo pointerFinger;
Servo middleFinger;
Servo ringFinger;
Servo pinkieFinger;
Servo wrist;

// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position

void setup() {
  thumb.attach(7);  // attaches the servo on pin 9 to the servo object
  pointerFinger.attach(8);
  middleFinger.attach(9);
  ringFinger.attach(10);
  pinkieFinger.attach(11);
  wrist.attach(12);
}

void loop() {
  // pointerFinger.write(0);              // tell servo to go to position in variable 'pos'
  //  middleFinger.write(0);
    //ringFinger.write(0);
    pinkieFinger.write(0);
  for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    //pointerFinger.write(pos);              // tell servo to go to position in variable 'pos'
    //middleFinger.write(pos);
    //ringFinger.write(pos);
    //pinkieFinger.write(pos);
    delay(10);                       // waits 10ms for the servo to reach the position
  }
  for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    //pointerFinger.write(pos);              // tell servo to go to position in variable 'pos'
    //middleFinger.write(pos);
    //ringFinger.write(pos);
    //pinkieFinger.write(pos);
    delay(10);                       // waits 10ms for the servo to reach the position
  }
}


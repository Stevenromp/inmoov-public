#include <Servo.h>

Servo myservo [6];
byte base_state = 0; 
void setup() {
  // put your setup code here, to run once:
    myservo[0].attach(2);thumb
    myservo[1].attach(3);pointer
    myservo[2].attach(4);middle
    myservo[3].attach(5);ring
    myservo[4].attach(6);pinkie
    myservo[5].attach(7);wrist
}

void loop() {
  // put your main code here, to run repeatedly:
  if(base_state==0)
  {
    myservo[0].write(45);thumb
    myservo[1].write(60);pointer
    myservo[2].write(75);middle
    myservo[3].write(90);ring
    myservo[4].write(105);pinkie
    myservo[5].write(120);wrist
    base_state=random(0,2);
  }
  if(base_state == 1)
  {
    myservo[0].write(0);thumb
    myservo[1].write(0);pointer
    myservo[2].write(0);middle
    myservo[3].write(0);ring
    myservo[4].write(0);pinkie
    myservo[5].write(0);wrist
    base_state= random(0,2)
  }


}

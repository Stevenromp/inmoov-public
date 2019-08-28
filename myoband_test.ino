#include <Servo.h>
Servo myservo;
const int ThreshValue = 250;

void setup() {
  // put your setup code here, to run once:
myservo.attach(9);
}

void loop() {
  // put your main code here, to run repeatedly:
int value = analogRead(A3);

if(value<ThreshValue)
{
  myservo.writeMicroseconds(800);
}
else
{
  myservo.writeMicroseconds(2250);
  
}
}

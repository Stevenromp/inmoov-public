#include <Servo.h>

//defined variables

#define LEFT_PINKY_ARRAY 
#define LEFT_PINKY_SERVO 

#define LEFT_RING_ARRAY 
#define LEFT_RING_SERVO 

#define LEFT_MIDDLE_ARRAY 
#define LEFT_MIDDLE_SERVO 

#define LEFT_INDEX_ARRAY 
#define LEFT_INDEX_SERVO 

#define LEFT_THUMB_ARRAY 
#define LEFT_THUMB_SERVO 

#define RIGHT_THUMB_ARRAY 
#define RIGHT_THUMB_SERVO 
// thumbs will operate differently than fingers, 
//as the shape is slightly cumbersome for 
//qwicc flex sensors. Will constantly scan voltage parameters,
// and check that the voltage is between .5-1.5 volts.
// if a jump is made that is greater than 3 volts, will move to 
//second position.

#define RIGHT_INDEX_ARRAY 
#define RIGHT_INDEX_SERVO 

#define RIGHT_MIDDLE_ARRAY 
#define RIGHT_MIDDLE_SERVO 

#define RIGHT_RING_ARRAY 
#define RIGHT_RING_SERVO

#define RIGHT_PINKY_ARRAY 
#define RIGHT_PINKY_SERVO 

#define LEFT_WRIST_ARRAY 
#define LEFT_WRIST_SERVO 

#define RIGHT_WRIST_ARRAY
#define RIGHT_WRIST_SERVO 

#define LEFT_BICEP_ARRAY
#define LEFT_BICEP_SERVO 
//minimum servo value = 11
//max servo value = 180
#define LEFT_SHOULDER_X_ARRAY
#define LEFT_SHOULDER_X_SERVO 

#define LEFT_SHOULDER_Y_ARRAY
#define LEFT_SHOULDER_Y_SERVO 

#define LEFT_SHOULDER_Z_ARRAY
#define LEFT_SHOULDER_Z_SERVO 

#define RIGHT_BICEP_ARRAY
#define RIGHT_BICEP_SERVO 
//minimum servo value = 10
//max servo value = 180
#define RIGHT_SHOULDER_X_ARRAY
#define RIGHT_SHOULDER_X_SERVO 

#define RIGHT_SHOULDER_Y_ARRAY
#define RIGHT_SHOULDER_Y_SERVO 

#define RIGHT_SHOULDER_Z_ARRAY
#define RIGHT_SHOULDER_Z_SERVO 

#define PRESSURE_MIN 0
#define PRESSURE_MAX 900

#define PRESSURE_RANGE PRESSURE_MAX - PRESSURE_MIN

#define MUSCLE_MIN -250
#define MUSCLE_MAX -35
#define MUSCLE_RANGE MUSCLE_MAX - MUSCLE_MIN

#define DEGREE_MIN 0
#define DEGREE_MAX 120
#define DEGREE_RANGE DEGREE_MAX - DEGREE_MIN

#define HISTORY_LENGTH 10
Servo fingers[10];
Servo wrist[2];
Servo bicep[2];
Servo shoulder_X[2];
Servo shoulder_Y[2];
Servo shoulder_Z[2];



int position;
int pressureHistory[HISTORY_LENGTH];
int muscleHistory[HISTORY_LENGTH];
int pressureInsertionIndex;
int muscleInsertionIndex;
boolean muscle_mode = false;
int degreeFromPressure(int pressure) {
  return ((float)(pressure - PRESSURE_MIN) / (PRESSURE_RANGE)) * DEGREE_RANGE + DEGREE_MIN; 
}
int degreeFromMuscle(int muscle) {
   return ((float)(muscle - MUSCLE_MIN) / (MUSCLE_RANGE)) * DEGREE_RANGE + DEGREE_MIN; 
}


void updateFinger(int fingerIndex, int grip) {

  Servo finger = fingers[fingerIndex];
  int degree = 90;
  finger.write(grip);
}

void updateFingerBoth(int fingerIndex, int pressure, int muscle) {
    Servo finger = fingers[fingerIndex];
  int degree =  degreeFromMuscle(muscle) *.5 +  degreeFromPressure(pressure) *.5;
  Serial.println(degree);
  finger.write(degree);
}

void updateThumb(int grip,int value){
    if(value == 1)
    {
    updateFinger(LEFT_THUMB_ARRAY, grip);
    }
    updateFinger(RIGHT_THUMB_ARRAY, grip);
}

int movingPressureAverage() {
  long sum = 0;
  for (int i = 0; i < HISTORY_LENGTH; i++) {
     sum += pressureHistory[i];
  }
  return sum/HISTORY_LENGTH;
}
int movingMuscleAverage() {
  long sum = 0;
  for (int i = 0; i < HISTORY_LENGTH; i++) {
     sum += muscleHistory[i];
  }
  return sum/HISTORY_LENGTH;
}
void insertIntoPressureHistory(int sensorReading) {
  
  pressureHistory[pressureInsertionIndex] = sensorReading;
  pressureInsertionIndex = (pressureInsertionIndex + 1) % (HISTORY_LENGTH + 1);
}

void insertIntoMuscleHistory(int sensorReading) {
  muscleHistory[muscleInsertionIndex] = sensorReading;
  muscleInsertionIndex = (pressureInsertionIndex + 1) % (HISTORY_LENGTH + 1);
}


void updateIndexFinger(int grip,int value){
    if(value == 1)
    {
    updateFinger(LEFT_INDEX_ARRAY, grip);
    }
    updateFinger(RIGHT_INDEX_ARRAY, grip);
}
void updateMiddleFinger(int grip,int value){
    if(value == 1)
    {
    updateFinger(LEFT_MIDDLE_ARRAY, grip);
    }
    updateFinger(RIGHT_MIDDLE_ARRAY, grip);
}

void updateRingFinger(int grip,int value){
    if(value == 1)
    {
    updateFinger(LEFT_RING_ARRAY, grip);
    }
    updateFinger(RIGHT_RING_ARRAY, grip);
}

void updatePinkyFinger(int grip,int value){
    if(value == 1)
    {
    updateFinger(LEFT_PINKY_ARRAY, grip);
    }
    updateFinger(RIGHT_PINKY_ARRAY, grip);
}

void updateBicep(int grip,int value){
    if(value == 1)
    {
    updateFinger(LEFT_BICEP_ARRAY, grip);
    }
    updateFinger(RIGHT_BICEP_ARRAY, grip); 
}

void updateshoulderX(int grip,int value){
    if(value == 1)
    {
    updateFinger(LEFT_SHOULDER_X_ARRAY, grip);
    }
    updateFinger(RIGHT_SHOULDER_X_ARRAY, grip); 
}

void updateshoulderY(int grip,int value){
    if(value == 1)
    {
    updateFinger(LEFT_SHOULDER_Y_ARRAY, grip);
    }
    updateFinger(RIGHT_SHOULDER_Y_ARRAY, grip); 
}

void updateshoulderZ(int grip,int value){
    if(value == 1)
    {
    updateFinger(LEFT_SHOULDER_Z_ARRAY, grip);
    }
    updateFinger(RIGHT_SHOULDER_Z_ARRAY, grip); 
}

void updateWrist(int grip,int value)
{
    if(value == 1)
    {
    updateFinger(LEFT_WRIST_ARRAY, grip);
    }
    updateFinger(RIGHT_WRIST_ARRAY, grip);
}

void resetFingers()
{
    for (int i = 0; i < 10; i++) 
    {
        updateFinger(i,0);
    }
}

void updateAllFingers(int grip) {
    updateLeftThumb(grip,1);
    updateIndexFinger(grip,1);
    updateRingFinger(grip,1);
    updatePinkyFinger(grip,1);
    updateMiddleFinger(grip,1);

    updateLeftThumb(grip,2);
    updateIndexFinger(grip,2);
    updateRingFinger(grip,2);
    updatePinkyFinger(grip,2);
    updateMiddleFinger(grip,2);
}

void updateAllFingersBoth(int pressure, int muscle){
    for (int i = 0; i < 5; i++) {
    updateFingerBoth(i,pressure, muscle);
  }
}








void setup() 
{
  
  fingers[LEFT_THUMB_ARRAY].attach(LEFT_THUMB_SERVO);
  fingers[LEFT_INDEX_ARRAY].attach(LEFT_INDEX_SERVO);
  fingers[LEFT_MIDDLE_ARRAY].attach(LEFT_MIDDLE_SERVO);
  fingers[LEFT_RING_ARRAY].attach(LEFT_RING_SERVO);
  fingers[LEFT_PINKY_ARRAY].attach(LEFT_PINKY_SERVO);
  fingers[RIGHT_THUMB_ARRAY].attach(RIGHT_THUMB_SERVO);
  fingers[RIGHT_INDEX_ARRAY].attach(RIGHT_INDEX_SERVO);
  fingers[RIGHT_MIDDLE_ARRAY].attach(RIGHT_MIDDLE_SERVO);
  fingers[RIGHT_RING_ARRAY].attach(RIGHT_RING_SERVO);
  fingers[RIGHT_PINKY_ARRAY].attach(RIGHT_PINKY_SERVO);


  wrist[LEFT_WRIST_ARRAY].attach(LEFT_WRIST_SERVO);
  wrist[RIGHT_WRIST_ARRAY].attach(RIGHT_WRIST_SERVO);

  bicep[LEFT_BICEP_ARRAY].attach(LEFT_BICEP_SERVO)
  bicep[RIGHT_BICEP_ARRAY].attach(RIGHT_BICEP_SERVO)

  shoulder_X[LEFT_SHOULDER_X_ARRAY].attach(LEFT_SHOULDER_X_SERVO)
  shoulder_X[RIGHT_SHOULDER_X_ARRAY].attach(RIGHT_SHOULDER_X_SERVO)

  shoulder_Y[LEFT_SHOULDER_X_ARRAY].attach(LEFT_SHOULDER_Y_SERVO)
  shoulder_Y[RIGHT_SHOULDER_Y_ARRAY].attach(RIGHT_SHOULDER_Y_SERVO)
  
  shoulder_Z[LEFT_SHOULDER_Z_ARRAY].attach(LEFT_SHOULDER_Z_SERVO)
  shoulder_Z[RIGHT_SHOULDER_Z_ARRAY].attach(RIGHT_SHOULDER_Z_SERVO)
  
  position = 60;
  muscleInsertionIndex = 0;
  pressureInsertionIndex = 0;
  resetFingers();
  pinMode(A2, INPUT);
  Serial.begin (9600);
} 



void fingertest()
{

    // Loop through motion tests for the fingers
    updateThumb(0,1);
    delay(1000);
    updateThumb(0,2);
    delay(1000);

    updateThumb(90,1);
    delay(1000);
    updateThumb(90,2);
    delay(1000);

    updateIndexFinger(0,1);
    delay(1000);
    updateIndexFinger(0,2);
    delay(1000);

    updateIndexFinger(90,1);
    delay(1000);
    updateIndexFinger(90,2);
    delay(1000);

    updateMiddleFinger(0,1);
    delay(1000);
    updateMiddleFinger(0,2);
    delay(1000);

    updateMiddleFinger(90,1);
    delay(1000);
    updateMiddleFinger(90,2);
    delay(1000);

    updateRingFinger(0,1);
    delay(1000);
    updateRingFinger(0,2);
    delay(1000);

    updateRingFinger(90,1);
    delay(1000);
    updateRingFinger(90,2);
    delay(1000);

    updatePinkyFinger(0,1);
    delay(1000);
    updatePinkyFinger(0,2);
    delay(1000);

    updatePinkyFinger(90,1);
    delay(1000);
    updatePinkyFinger(90,2);
    delay(1000);
}

void upperarmtest()
{
    updateBicep(15,1);
    delay(1000);
    updateBicep(15,2);
    delay(1000);

    updateBicep(180,1);
    delay(1000);
    updateBicep(180,2);
    delay(1000);

    updateshoulderX(0,1);
    delay(1000);
    updateshoulderX(0,2);
    delay(1000);

    updateshoulderX(90,1);
    delay(1000);
    updateshoulderX(90,2);
    delay(1000);

    updateshoulderY(0,1);
    delay(1000);
    updateshoulderY(0,2);
    delay(1000);

    updateshoulderY(90,1);
    delay(1000);
    updateshoulderY(90,2);
    delay(1000);

    updateshoulderZ(0,1);
    delay(1000);
    updateshoulderZ(0,2);
    delay(1000);

    updateshoulderZ(90,1);
    delay(1000);
    updateshoulderZ(90,2);
    delay(1000);
}

wristtest()
{
    updateWrist(15,1);
    delay(1000);
    updateWrist(15,2);
    delay(1000);updateBicep(90,1);
    delay(1000);
    updateBicep(90,2);
}


void loop() {           

//fingertest();
//wristtest();
//upperarmtest();

  //alltovirtual();        // Example: alltovirtual
  //delay(10);           // Wait 4000 milliseconds (4 seconds)
  //alltorest();           // Uncomment to use this
  //delay(4000);           // Uncomment to use this
  //alltomax();            // Uncomment to use this
  //delay(2000);
  // Uncomment to use this
    //updateThumb(100);  
    //updateThumb(0);
    
    int potential = analogRead(A2);
    
    if (potential >= 0 && potential <= 333) {
    muscle_mode = false;
    int sensorValue = analogRead(A0);
    insertIntoPressureHistory(sensorValue);
    int average = movingPressureAverage();
    updateAllFingers(average);
    //Serial.println(average);
    }
    else if (potential >= 334 && potential <= 666) {
      muscle_mode = false;
      switch(position) {
        case 0:
          resetFingers();
          break;
        case 1:
          updateMiddleFinger(PRESSURE_MAX);
          updateIndexFinger(PRESSURE_MAX);
          break;
        case 2:
          resetFingers();
          break;
        case 3:
          updatePinkyFinger(PRESSURE_MAX);
          updateIndexFinger(PRESSURE_MAX);
          updateThumb(PRESSURE_MAX);
          break;
        case 4:
          resetFingers();
          break;
        case 5:
          
          break;
      }
      delay(2000);
    }
    else {
    muscle_mode = true;
    int pressureValue = analogRead(A0);
    insertIntoPressureHistory(pressureValue);
    int pressure_average = movingPressureAverage();
    int muscleValue = analogRead(A1)*-1;
    insertIntoMuscleHistory(muscleValue);
    int muscle_average = movingMuscleAverage();
    updateAllFingersBoth(pressure_average, muscle_average);
    }
  position = (position + 1) % 6;

  
}

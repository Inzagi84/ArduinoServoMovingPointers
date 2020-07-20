/*
Filip Crljenić 2.7.2020.
Project for learning Arduino.
Push button and Servo Rotation when its on 180 move back on push
*/
#include <Servo.h>

//Program
short tmpDegree=0;
const short delayServoTime = 50;
const short movingStep = 5;

// Servo1 
Servo myServo1;  // create servo object to control a servo
const short pinServo1 = 9;
short degreeServo1 = 0;
const short maxDegreeServo1 = 180;
const short minDegreeServo1 = 90;

void setup() {
  myServo1.attach(pinServo1);  // attaches the servo on pin 9 to the servo object
  // initialize serial communication at 9600 bits per second:
  resetServo(&myServo1,minDegreeServo1);
}



void loop() {
  long currentMills = millis();

  moveServo(&myServo1,&degreeServo1, movingStep, maxDegreeServo1,minDegreeServo1);
  
}

// Moving servo to max degree with steps if get to max then get back to minDegree
void moveServo(Servo *_servo, short *degree, short _step, short maxDegree, short minDegree)
{
  *degree=_servo->read();
   
  if (*degree >= maxDegree)
  {    
    resetServo(_servo, minDegree);  
    *degree=0; 
  }
  else
  {
   _servo->write(*degree+_step);
}
   delay(delayServoTime);
  }

void moveServoToDegree(Servo *_servo, int _moveToDegree)
{
  
  tmpDegree = _servo->read();
  while(_moveToDegree>tmpDegree)
  {    
     _servo->write(tmpDegree+movingStep);
     delay(delayServoTime);
     tmpDegree += movingStep;
  }
}
void resetServo(Servo *_servo, int _minDegree)
{
  
  tmpDegree=_servo->read();
  
  while(tmpDegree>_minDegree)
  {
    _servo->write(tmpDegree-movingStep);
    delay(delayServoTime);
    tmpDegree-=movingStep;
  }
  
}

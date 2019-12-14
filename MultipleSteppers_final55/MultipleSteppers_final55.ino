// MultiStepper.pde
// -*- mode: C++ -*-
//
// Shows how to multiple simultaneous steppers
// Runs one stepper forwards and backwards, accelerating and decelerating
// at the limits. Runs other steppers at the same time
//
// Copyright (C) 2009 Mike McCauley
// $Id: MultiStepper.pde,v 1.1 2011/01/05 01:51:01 mikem Exp mikem $

#include <NewPing.h>
#include <AccelStepper.h>

#define TRIGGER_PIN  12  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN     11  // Arduino pin tied to echo pin on the ultrasonic sensor.
#define MAX_DISTANCE 200 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.

//const int stepsPerRevolution = 2048;  // change this to fit the number of steps per revolution
// for your motor
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance.

// Define some steppers and the pins the will use
AccelStepper stepper1(AccelStepper::FULL4WIRE, 7, 8, 9, 10);
AccelStepper stepper2(AccelStepper::FULL4WIRE, 3, 4, 5, 6);
////tepper stepper3(AccelStepper::FULL2WIRE, 10, 11);
bool stepperRun = false;
void setup()
{
  Serial.begin(115200); // Open serial monitor at 115200 baud to see ping results.

  //    stepper1.setMaxSpeed(200.0);
  //    stepper1.setAcceleration(100.0);
  //stepper1.moveTo(24);

  //    stepper2.setMaxSpeed(300.0);
  //    stepper2.setAcceleration(100.0);
  //stepper2.moveTo(1000000);

  //    stepper3.setMaxSpeed(300.0);
  //    stepper3.setAcceleration(100.0);
  //    stepper3.moveTo(1000000);

  stepper1.setMaxSpeed(1000);
  stepper1.setSpeed(1000);

  stepper2.setMaxSpeed(1000);
  stepper2.setSpeed(1000);
}

void loop()
{
  // delay(50);                     // Wait 50ms between pings (about 20 pings/sec). 29ms should be the shortest delay between pings.
  Serial.print("Ping: ");
  Serial.print(sonar.ping_cm()); // Send ping, get distance in cm and print result (0 = outside set distance range)

  Serial.println("cm");
  
  int cm = sonar.ping_cm();
    stepper1.runSpeed();
  if (cm > 16 && cm < 65) {
    
    stepper2.runSpeed();

  } else {
    stepperRun = false;
  }

  if (stepperRun == true) {
  
  }


  // Change direction at the limits
  //    if (stepper1.distanceToGo() == 0)
  //	stepper1.moveTo(-stepper1.currentPosition());
  //    stepper1.run();
  //    stepper2.run();
  // stepper3.run();

  //if(cm < 30){
  //    stepper1.run();
  //     stepper2.counterStep();
  // }

  //if(cm < 30){
  //    stepper1.moveTo(-stepper1.currentPosition());
  //     stepper2.run();
  //}

}

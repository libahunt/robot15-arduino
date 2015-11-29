/*******************************************************************************
Code for a micromouse (https://en.wikipedia.org/wiki/Micromouse) competition robot.
Works in cooperation with RasperryPi.

by Anna Jõgi a.k.a Libahunt

*******************************************************************************/
#include <NewPing.h>
#include <AccelStepper.h>

#define DEBUG /*comment this line out in production then all DP Serial instructsions are ignored*/
#include "DebugUtils.h"/*leave this in, otherwise you get errors*/

#include "Layout.h" //Pin connections
#include "Settings.h" //Variables that might need tweaking
#include "Vars.h"

AccelStepper motorRight(8, motorR[0], motorR[2], motorR[1], motorR[3]);//8 is type
AccelStepper motorLeft(8, motorL[0], motorL[2], motorL[1], motorL[3]);//order of pins 1,3,2,4

NewPing sonar[sonarsNum] = {
  NewPing(sensorRight, sensorRight, pingMaxDist),
  NewPing(sensorFront, sensorFront, pingMaxDist),
  NewPing(sensorLeft, sensorLeft, pingMaxDist)
};



void setup() {
    
  Serial.begin(9600);//for communication with RasPi
  
  //Stepper motors setup for exploration mode
  motorRight.setAcceleration(motorAccelerationExplore);
  motorRight.setMaxSpeed(motorSpeedExplore);
  motorLeft.setAcceleration(motorAccelerationExplore);
  motorLeft.setMaxSpeed(motorSpeedExplore);
  
  state = WAIT_COMMAND;
  commands = 0;
  
  Serial.println('d');
  
}

void loop() {
  
  if (state == WAIT_COMMAND) {
     	
    commands = takeOrders();
    if (commands > 0) {//serial command received
      currentCommand = 0;
      state = DRIVE_BY_COMMAND;
    }
    
  }
  
  else if (state == DRIVE_BY_COMMAND) {
    
    //check if motor stepping is due
    runningRight = motorRight.run();//runs if still distance to go, saves state in var, false if moving done  
    runningLeft = motorLeft.run();
    
    //single run command has finished executing
    if (!runningRight && !runningLeft) {
      if (currentCommand < commands) {
        execCommand( incomingCommand[currentCommand] );
        currentCommand++; 
      }
      else {
        //all commands executed, report back and change state
        stopMovement();
        Serial.println('d');
        commands = 0;
        currentCommand = 0;
        state = WAIT_COMMAND;
      }
    }
     
    //check if sensor read is due 
    pingAll();
    
  }
  
  else if (state == EXPLORE) {
    
    //check if motor stepping is due
    runningRight = motorRight.run();//runs if still distance to go, saves state in var, false if moving done
    runningLeft = motorLeft.run();
    
    //check if sensor read is due 
    pingAll();
    
    //check if in the middle of a square
    if (motorLeft.currentPosition() == nextSquareCentre) {
      mapSquareWalls();
    }
    
    //has finished executing
    if (!runningRight && !runningLeft) {
      reportBack();
      state = WAIT_COMMAND;
    }
    
  }

}



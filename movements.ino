/*right motor: forward is negative
left motor: forward is positive*/

void moveForward(float cm) {
  long steps = long(cm*cmSteps);
  motorRight.enableOutputs();
  motorLeft.enableOutputs();
  sensorsStart();
  motorLeft.move(steps);
  motorRight.move(-1*steps);
}

void turnLeft() {
  motorRight.enableOutputs();
  motorLeft.enableOutputs();
  motorRight.move(-1*turnSteps);
  motorLeft.move(-1*turnSteps);
}

void turnRight() {
  motorRight.enableOutputs();
  motorLeft.enableOutputs();
  motorRight.move(turnSteps);
  motorLeft.move(turnSteps);
}

void stopMovement() {
  motorRight.stop();
  motorLeft.stop();
  motorRight.disableOutputs();
  motorLeft.disableOutputs();
}

/*void correctToRight() {
  targetLeft = motorLeft.targetPosition();
  targetRight = motorRight.targetPosition(); 	
  motorLeft.stop();
  motorRight.stop();
  motorLeft.move(-1*correctionStepsTurn);
  while (motorLeft.distanceToGo() > 0) {
    motorLeft.run();
  }
  motorRight.move(correctionStepsStraight);
  motorLeft.move(-1*correctionStepsStraight);
  while (motorLeft.distanceToGo() > 0) {
    motorLeft.run();
  }
  motorRight.moveTo(targetRight);
  motorLeft.moveTo(targetLeft);
}

void correctToLeft() {
  targetLeft = motorLeft.targetPosition();
  targetRight = motorRight.targetPosition(); 	
  motorLeft.stop();
  motorRight.stop();
  motorRight.move(correctionStepsTurn);
  while (motorRight.distanceToGo() > 0) {
    motorRight.run();
  }
  motorRight.move(correctionStepsStraight);
  motorLeft.move(-1*correctionStepsStraight);
  while (motorLeft.distanceToGo() > 0) {
    motorLeft.run();
  }
  motorRight.moveTo(targetRight);
  motorLeft.moveTo(targetLeft);
}*/

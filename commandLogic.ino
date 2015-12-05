/*Data structure:
pi->ardu
[number]: move forward the specified number of squares (9 is max, 91 results in 10 squares)
l: turn left
r: turn right
e: explore mode drive forward*/

void execCommand(char commandChar) {
  if(commandChar =='r') {
    DPL("B: turning right");
    turnRight();
  } 
  else if(commandChar =='l') {
    DPL("B: turning left");
    turnLeft();
  }
  else if (commandChar-'0' <=9 && commandChar-'0' >0) {
    DP("B: moving ");
    DP(commandChar - '0');
    DPL(" squares");
    moveForward((commandChar-'0')*squareSize);
  }
  
  else if(commandChar == 'e') {
    DPL("B: exploring");
    cleanExploreResults();
    currentExploreAddress = 0;
    nextSquareCentre = motorLeft.currentPosition() + (squareSize*cmSteps);
    moveForward(mazeSize);//maximum length, will be stopped by measurement of wall
    stopCorrection = true;
    state = EXPLORE; //change state
  }
  
  else {
    Serial.print("E: unknown command '");
    Serial.print(commandChar);
    Serial.println("'");
    commands = 0;
    currentCommand = 0;
    state = WAIT_COMMAND;
  }
}

void mapSquareWalls() {
  //record if walls are open, sensors say 0 if reading out of range, so exclude too small also
  if(sonarReadings[0] < isWallMin || sonarReadings[0] > isWallMax) {//right open
    exploreResults[currentExploreAddress] += 4;
  } 
  if(sonarReadings[3] < isWallMin || sonarReadings[3] > isWallMax) {//left open
    exploreResults[currentExploreAddress] += 1;
  }
  if(sonarReadings[1] < isWallMin || sonarReadings[1] > squareSize) {//front open
    exploreResults[currentExploreAddress] += 2;
  }
  //set new checkpoint
  nextSquareCentre = motorLeft.currentPosition() + (squareSize*cmSteps);
  currentExploreAddress++;
}

void cleanExploreResults() {
  for (int i; i<mazeSize; i++) {
    exploreResults[i] = 0;
  }
}

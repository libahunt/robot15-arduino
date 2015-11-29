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
  //record if walls are open
  if(sonarReadings[0] < 6) {//right open
    exploreResults[currentExploreAddress] += 4;
  } 
  if(sonarReadings[3] < 6) {//left open
    exploreResults[currentExploreAddress] += 1;
  }
  if(sonarReadings[1] < 10) {//front open
    exploreResults[currentExploreAddress] += 2;
  }
  else {//front not open
    //at the end of the straight drive, report back
    //reportBack();
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

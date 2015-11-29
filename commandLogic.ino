/*Data structure:
pi->ardu
[number]: move forward the specified number of squares (9 is max, 91 results in 10 squares)
l: turn left
r: turn right
e: explore mode drive forward*/

void execCommand(char commandChar) {
  if(commandChar =='r') {
    turnRight();
  } 
  else if(commandChar =='l') {
    turnLeft();
  }
  else if (commandChar-'0' <=9 && commandChar-'0' >=0) {
    moveForward((commandChar-'0')*squareSize);
  }
  
  else if(commandChar == 'e') {
    //TODO insert drive command
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


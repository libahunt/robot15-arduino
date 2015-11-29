/*Data structure:
pi->ardu
[number]: move forward the specified number of squares (9 is max, 91 results in 10 squares)
l: turn left
r: turn right
e: explore mode drive forward

ardu-> pi
d: done fulfilling drive commands
[number]: explored square properties in binary, 
    DEC 1-open to left, 2 open to front, 4 open to right, 
    example 6 means open forward and right, 5 means open left and right, 4 means open right,
    3 means open front and left, 2 means open to front, 1 means open to left,
    0 means dead end all sides closed 
    
B: line starting with B indicates debug printout
*/

byte takeOrders() {
//returns the number of command charaters stored
  if (Serial.available() > 0) {
    commandIndex = 0;
    while (Serial.available() > 0) {
      if(commandIndex < commandLength) {
        incomingByte = Serial.read();
        incomingCommand[commandIndex] = incomingByte;
        commandIndex++;
      }
    }
    return commandIndex;
  }
  else return 0;
}

void reportBack() {
  for (int i=0; i<=currentExploreAddress; i++) {
    Serial.print(exploreResults[i]);
  }
  Serial.println("d");
  state = WAIT_COMMAND;
}


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
    example 6 means open forward and right, 0 means dead end all sides closed 
    
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
  
}


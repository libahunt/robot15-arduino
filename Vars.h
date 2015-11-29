#define WAIT_COMMAND 0
#define DRIVE_BY_COMMAND 1
#define EXPLORE 2

byte state;

/*ping sensors related*/
const byte sonarsNum = 3;
unsigned long pingTimer[sonarsNum];
unsigned int sonarReadings[sonarsNum];
uint8_t currentSensor = 0;

/*Serial communication related*/
byte incomingCommand[commandLength];
byte incomingByte;//helper during receiving
byte commandIndex;//helper during receiving
byte commands;//holds the number of commands that was received into incomingCommand
byte currentCommand;//counter for keeping track of drive command that is executed right now

boolean runningRight = false;
boolean runningLeft = false;

/*
#define TWO_WALLS 0
#define RIGHT_WALL 1
#define LEFT_WALL 2
#define NO_WALL 3
byte driveMode;
*/

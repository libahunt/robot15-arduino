#define WAIT_COMMAND 0
#define DRIVE_BY_COMMAND 1
#define EXPLORE 2

byte state;

/*ping sensors related*/
const byte sonarsNum = 3;
unsigned long pingTimer[sonarsNum];
unsigned long sonarReadings[sonarsNum];
uint8_t currentSensor = 0;

/*Serial communication related*/
byte incomingCommand[commandLength];
byte incomingByte;//helper during receiving
byte commandIndex;//helper during receiving
byte commands;//holds the number of commands that was received into incomingCommand
byte currentCommand;//counter for keeping track of drive command that is executed right now

byte currentExploreAddress = 0;//index of square currently explored
byte exploreResults[mazeSize];//binary mappings of squares that will be sent to RasPi
long nextSquareCentre;//holds left motor step number that occurs in the middle of next square


/*Maneuvers related*/
boolean runningRight = false;
boolean runningLeft = false;
long rightPos;//to save AccelStepper currentPosition() for later use 	
long leftPos;
long targetLeft; //to save AccelStepper targetPosition() for later use
long targetRight; 

boolean stopCorrection = true;	

/*
#define TWO_WALLS 0
#define RIGHT_WALL 1
#define LEFT_WALL 2
#define NO_WALL 3
byte driveMode;
*/

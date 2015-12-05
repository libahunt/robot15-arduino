/*Ping sensor related*/
const int pingMaxDist = 50; // Maximum distance (in cm) to ping.
const unsigned long pingInterval = 33;

/*Stepper motors related*/
const float motorAccelerationExplore = 750;
const float motorAccelerationRun = 750;
const float motorSpeedExplore = 1500;
const float motorSpeedRun = 1500;

/*Wall detection related*/
const unsigned long isFrontWallMax = 60;
const unsigned long isFrontWallMin = 10;
const unsigned long isWallMax = 50;
const unsigned long isWallMin = 5;

/*Maneuvers related*/
const long cmSteps = 272;//number of motor steps that yield 1 cm move forward
const long turnSteps = 6.28*cmSteps;//number of motor steps that yield 90 degree turn

const long correction1StepsTurn = 100;
const long correctionStepsStraight = cmSteps;
const long correction2StepsTurn = correction1StepsTurn * 0.66;

const float squareSize = 18.0;//square length in cm
const byte mazeSize = 16;//number of squares in a row
const float frontWallDist = 2.5;//measured distance to front wall when robot is centered in the square

const byte commandLength = 100;//max length of command taken from raspi, long needed for full runs



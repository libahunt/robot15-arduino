/*Ping sensor related*/
const int pingMaxDist = 50; // Maximum distance (in cm) to ping.
const unsigned long pingInterval = 33;

/*Stepper motors related*/
const float motorAccelerationExplore = 750;
const float motorAccelerationRun = 750;
const float motorSpeedExplore = 1200;
const float motorSpeedRun = 1200;

const long cmSteps = 272;//number of motor steps that yield 1 cm move forward
const long turnSteps = 6.28*cmSteps;//number of motor steps that yield 90 degree turn
const long correctionStepsTurn = cmSteps * 1.25;
const long correctionStepsStraight = cmSteps / 1.25;

const float squareSize = 18.0;

const byte commandLength = 20;//max length of command taken from raspi

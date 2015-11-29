const byte motorR[4] = {4, 5, 6, 7};
const byte motorL[4] = {8, 9, 10, 11};

const byte sensorRight = 15;
const byte sensorFront = 14;
const byte sensorLeft = 16;

/*Layout:
0 - (USB)
1 - (USB)
2
3
4 - Stepper right 1 
5 - Stepper right 2
6 - Stepper right 3
7 - Stepper right 4 
8 - Stepper left 1 
9 - Stepper left 2
10 - Stepper left 3
11 - Stepper left 4
12
13

A0 - Ping sensor front
A1 - Ping sensor right
A2  - Ping sensor left
A3 -
A4 - I2C compass
A5 - I2C compass
A6
A7

*/

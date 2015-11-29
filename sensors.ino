void sensorsStart() {
  //Sensors setup
  pingTimer[0] = millis() + 75;
  for (uint8_t i = 1; i < sonarsNum; i++) {
    pingTimer[i] = pingTimer[i - 1] + pingInterval;
  }
}

void pingAll() {
  for (uint8_t i = 0; i < sonarsNum; i++) { // Loop through all the sensors.
    if (millis() >= pingTimer[i]) {         // Is it this sensor's time to ping?
      pingTimer[i] += pingInterval * sonarsNum;  // Set next time this sensor will be pinged.
      if (i == 0 && currentSensor == sonarsNum - 1) {  
        oneSensorCycle(); // Sensor ping cycle complete, do something with the results.
      }
      sonar[currentSensor].timer_stop();          // Make sure previous timer is canceled before starting a new ping (insurance).
      currentSensor = i;                          // Sensor being accessed.
      sonarReadings[currentSensor] = 0;                      // Make distance zero in case there's no ping echo for this sensor.
      sonar[currentSensor].ping_timer(echoCheck); // Do the ping (processing continues, interrupt will call echoCheck to look for echo).
    }
  }
}


void echoCheck() {
  if (sonar[currentSensor].check_timer())
    sonarReadings[currentSensor] = sonar[currentSensor].ping_result / US_ROUNDTRIP_CM;
}

void oneSensorCycle() { // Sensor ping cycle complete, analyze results
/*
  #ifdef DEBUG
    for (uint8_t i = 0; i < sonarsNum; i++) {
      DP("B: ");
      DP(i);
      DP("=");
      DP(sonarReadings[i]);
      DP("cm ");
    }
    DPL();
  #endif
*/  
  //check if front wall too close
  /*if (sonarReadings[1] < 3) {
    long rightPos = motorRight.targetPosition() - motorRight.distanceToGo();
    long leftPos = motorLeft.targetPosition() - motorLeft.distanceToGo();
    motorRight.moveTo(rightPos + );
    motorLeft.move(-1*turnSteps);
  }
  
  else if (sonarReadings[0] < sonarReadings[3]*1.3) {
    correctToLeft();
  }
  else if (sonarReadings[3] < sonarReadings[0]*1.3) {
    correctToRight();
  }*/
  
  //register change in wall status ... 
  
}



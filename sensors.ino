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
        sensorAnalyze(); // Sensor ping cycle complete, do something with the results.
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
    sonarReadings[currentSensor] = sonar[currentSensor].ping_result * 0.34;
}

void sensorAnalyze() { // Sensor ping cycle complete, analyze results

  //check if front wall too close
  if (sonarReadings[1] <= isFrontWallMax && sonarReadings[1] > isFrontWallMin && state == EXPLORE) {//TODO: this condition is problematic!
    DP("B: front wall closing ");
    DPL(sonarReadings[1]);
    rightPos = motorRight.currentPosition();
    leftPos = motorLeft.currentPosition();
    motorRight.moveTo( rightPos - (sonarReadings[1]/10 * cmSteps) );
    motorLeft.moveTo( leftPos + (sonarReadings[1]/10 * cmSteps) );
  }
  
  else if (sonarReadings[0] < sonarReadings[3]*1.3) {
    correctToLeft();
  }
  else if (sonarReadings[3] < sonarReadings[0]*1.3) {
    correctToRight();
  }
  
}


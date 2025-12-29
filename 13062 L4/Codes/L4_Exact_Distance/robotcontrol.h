#ifndef ROBOTCONTROL_H
#define ROBOTCONTROL_H

class robotcontrol {
private:
  mpu* imu;
  PID* pid;
  MotorControl* motor;
  Debugger* dbg;
  int LS, RS;
  int basespeed = 200;
  int turnspeed = 150;

  const int wheelDiameter = 67;                             // mm
  const float wheelCircumference = 3.1416 * wheelDiameter;  // mm
  int estimatedRPM = 114;
public:
  robotcontrol(mpu* imu,
               PID* pid,
               MotorControl* motor,
               Debugger* dbg)
    : imu(imu), pid(pid), motor(motor), dbg(dbg) {}

  void moverobot(char dir, long time) {
    motor->move(dir);
    unsigned long start = millis();
    while (millis() - start < time) {
      imu->update();
      float yawrate = imu->getz();
      float correction = pid->compute(yawrate, 0);

      if (dir == 'f') {
        LS = constrain(basespeed + correction, 0, 255);
        RS = constrain(basespeed - correction, 0, 255);
      } else {
        LS = constrain(basespeed - correction, 0, 255);
        RS = constrain(basespeed + correction, 0, 255);
      }
      motor->setPWM(LS, RS);
    }
    motor->move('s');
  }

  void turn(float targetangle) {
    int yawangle = 0;
    unsigned long previous = millis();
    while (abs(targetangle - yawangle) > 1) {
      unsigned long now = millis();
      float dt = (now - previous) / 1000.0;
      previous = now;
      imu->update();
      float yawrate = imu->getz();
      yawangle -= yawrate * dt;

      motor->setPWM(turnspeed, turnspeed);
      if (yawangle < targetangle) motor->move('l');
      else motor->move('r');

      delay(10);
    }
    motor->move('s');
  }

  void start_calibration() {
    moverobot('f', 1000);
  }

  void calibrateRPM(float distanceCM) {
    float distanceMM = distanceCM * 10;
    estimatedRPM = (distanceMM / wheelCircumference) / (1000 / 60000.0);

    Serial.print("Updated Estimated RPM: ");
    Serial.println(estimatedRPM);
  }

  void moveED(float distanceCM) {
    float distanceMM = distanceCM * 10;
    float numRevolutions = distanceMM / wheelCircumference;
    float timePerRev = 60.0 / estimatedRPM;
    float totalTimeSec = numRevolutions * timePerRev;
    unsigned long totalTimeMS = totalTimeSec * 1000;

    moverobot('f',totalTimeMS);
  }

};


#endif
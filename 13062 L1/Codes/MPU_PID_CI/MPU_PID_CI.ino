#include "MPU.h"
#include <Wire.h>
#include "PID.h"

PID p(1.0, 1.0, 1.0);
mpu m;

void setup() {
  Serial.begin(9600);
  Wire.begin();
  if (m.begin()) {
    Serial.println("MPU CONNECTED");
    m.calibrate();
  } else {
    Serial.println("MPU NOT CONNECTED");
  }
}

void loop() {
  if (m.check()) {
    m.update();
  } else {
    Serial.println("MPU Failed to Update");
  }
  if (m.check()) {
    Serial.println(p.compute(m.getz()));
  } else {
    Serial.println("MPU Failed to get Value");
  }
  // put your main code here, to run repeatedly:
}

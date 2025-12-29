//Main Course File (Do not make changes withour recording, Make a copy)

#include "MPU.h"
#include <Wire.h>
#include "PID.h"

#include "motorcontrol.h"
#include <WebServer.h>
#include <WebSocketsServer.h>
#include <WiFi.h>
#include "debugger.h"
#include "webhandler.h"
#include "robotcontrol.h"


PID p(1.0, 0.1, 0.1);
mpu m;

// Motor pins (example pins, change as needed)
const int M1A = 32;
const int M1B = 33;
const int M2A = 18;
const int M2B = 19;
const int PWMA = 5;
const int PWMB = 15;

const char* ssid = "LIFE_M1";
const char* password = "12345678";


MotorControl motor(M1A, M1B, M2A, M2B, PWMA, PWMB);
WebSocketsServer socket = WebSocketsServer(81);
Debugger debugger(&socket);
robotcontrol robot(&m,&p,&motor,&debugger);
WebHandler web(&motor, &socket, &debugger, &robot);



void setup() {
  Serial.begin(9600);
  Wire.begin();

  // Start WiFi in AP mode

  WiFi.mode(WIFI_AP);
  WiFi.softAP(ssid, password);
  Serial.print("WiFi AP started. SSID: ");
  Serial.println(WiFi.softAPIP());

  if (m.begin()) {
    Serial.println("MPU CONNECTED");
    m.calibrate();
  } else {
    Serial.println("MPU NOT CONNECTED");
  }
  motor.begin();
  // motor.test(); // Optionally comment out after testing
  web.begin();
}


void loop() {
  // if (m.check()) {
  //   m.update();
  // } else {
  //   Serial.println("MPU Failed to Update");
  // }
  // if (m.check()) {
  //   Serial.println(p.compute(m.getz()));
  // } else {
  //   Serial.println("MPU Failed to get Value");
  // }
  web.update();
}

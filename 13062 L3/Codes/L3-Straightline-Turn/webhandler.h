// webhandler.h
// Handles WebServer, WebSocketsServer, and command parsing for ESP32 car

#ifndef WEBHANDLER_H
#define WEBHANDLER_H

#include <WebServer.h>
#include <WebSocketsServer.h>
#include <ArduinoJson.h>
#include "motorcontrol.h"
#include "debugger.h"
#include "Interface.h"
#include "robotcontrol.h"


class WebHandler {
public:
  WebHandler(MotorControl* motor, WebSocketsServer* socket, Debugger* debugger, robotcontrol* robot)
    : _motor(motor), _socket(socket), _debugger(debugger), robot(robot){}

  void begin() {

    server.on("/", [this]() {
      server.send(200, "text/html", MAIN_page);
    });
    server.begin();
    server.begin();

    _socket->begin();
    _socket->onEvent([this](uint8_t num, WStype_t type, uint8_t* payload, size_t length) {
      this->onWebSocketEvent(num, type, payload, length);
    });
  }

  void update() {
    server.handleClient();
    _socket->loop();
  }

  void onWebSocketEvent(uint8_t num, WStype_t type, uint8_t* payload, size_t length) {
    if (type == WStype_TEXT) {
      DynamicJsonDocument doc(256);
      DeserializationError err = deserializeJson(doc, payload, length);

      if (!err) {
        String key = doc["key"] | "";
        String value = doc["value"] | "";
        Serial.println(key);
        Serial.println(value);
        if (key == "move" && _motor) {
          _motor->move(value[0]);
          _debugger->sendDebug("Move: " + value);
        }else if(key == "fs" || key == "bs"){
          float val = doc["value"].as<float>();
          robot->moverobot(key[0], val);
        }else if (key == "turn"){
          float val = doc["value"].as<float>();
          robot->turn(val);
        }
      }
    }
  }

private:
  MotorControl* _motor;
  WebSocketsServer* _socket;
  Debugger* _debugger;
  WebServer server{ 80 };
  robotcontrol* robot;
};

#endif  // WEBHANDLER_H

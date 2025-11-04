# LIFE Robotics Course (Project-LIFE-13062)

Welcome to the LIFE Robotics Course repository. This project contains the code, diagrams, and resources for the LIFE robotics series where we build and program an ESP32-based robot that learns to drive straight, turn precisely using an IMU, and eventually perform mapping and autonomous behaviors.

## Course Overview

LIFE is a free, hands-on robotics course that walks you through building a robot platform, programming low-level motor and sensor control, and applying control theory (PID) and IMU sensing (MPU6050) for precise navigation. The series mixes hardware tutorials, Arduino/C++ code, and web-control interfaces using the ESP32.

What you will get from this repository:
- Source code for each lecture/module (see `13062 L1/`, `13062 L2/`, `13062 L3/` folders)
- Circuit diagrams and 3D-print guidance
- Custom PID and motor control libraries used in the course
- Links to lecture videos and external resources

## Lecture / Module Index

Intro — Course Trailer
- Video: https://youtu.be/KHHjebn6sVA
- Summary: Kickoff video showcasing core LIFE features (navigation, path memory, mapping, autonomous decision making).

What's inside the course
- Video: https://youtu.be/j3v7BzDmeeI
- Summary: Full course outline — building the robot, coding (C++, JS, HTML), navigation, mapping, path memory, and web-control.

Module L1 — Foundations: MPU6050 & PID
- Video: https://youtu.be/AyyBTrm51oY
- Summary: Learn to interface the MPU6050 IMU with the ESP32 and implement a custom PID library in Arduino to correct drift and stabilize motion.
- What you’ll learn:
	- How to use MPU6050 with ESP32
	- Why robots drift & how PID control fixes it
	- Writing a simple PID library in Arduino/C++
	- NASA-inspired programming discipline for robotics

Module L2 — Wi‑Fi & Web Control (ESP32)
- Video: https://youtu.be/Of0DStubWUc
- Summary: Build a Wi‑Fi controlled robot with a web interface. This module also demonstrates using VSCode Copilot and prompt-engineering to accelerate code writing.
- What you’ll learn:
	- ESP32 Wi‑Fi setup and WebSocket control
	- PWM motor control and web interface basics
	- AI-assisted coding workflows with VSCode Copilot

Module L3 — PID Straight-Line & Precise Turns (IMU)
- Video: https://youtu.be/1F6HHr7PidI
- Summary: Implement PID control for straight-line motion and use MPU6050 yaw (heading) to perform accurate degree-based turns. Learn calibration and real-time drift correction.
- What you’ll learn:
	- Implementing PID for straight-line motion
	- Using MPU6050 yaw for precise angular turns
	- Calibrating and tuning Kp, Ki, Kd
	- Reusable movement primitives for autonomous navigation

## Resources & Code

All course files, downloads and documentation are available from the course site:
https://neweraexploration.com/courses

Repository structure (high level):
- `13062 L1/` — L1 code, circuit diagrams, resources
- `13062 L2/` — L2 webserver and Wi‑Fi control code
- `13062 L3/` — L3 straight-line & turn code

Look inside each `Codes/` subfolder for the Arduino (.ino) sketches and supporting headers (`MPU.h`, `PID.h`, `motorcontrol.h`, etc.).

## Tools & Technologies

- ESP32 microcontroller
- MPU6050 IMU (gyro + accelerometer)
- Arduino IDE or Visual Studio Code (PlatformIO recommended)
- Web technologies (HTML/JS) for browser-based controls
- Custom PID and motor-control libraries included in the repo

## Support the Free Course

This course is 100% free. If you’d like to support ongoing development and tutorials, please consider contributing:
https://neweraexploration.com/courses/#support

## Stay Connected

- Instagram: https://www.instagram.com/nexbot_oo
- Website: https://neweraexploration.com
- Discord community: https://discord.gg/mb7AT6GVEQH

If you post videos or projects using these materials, tag them with:
#robotics #arduino #esp32 #roboticscourse #stem #swarm #computervision #3dprinting

Suggested repo tags / SEO keywords:
ESP32 PID robot, MPU6050 ESP32, Arduino PID control, precise turn robot, autonomous robot ESP32, straight line robot movement, robot control algorithm, LIFE 13062, New Era Exploration robotics

## How to Use This Repo

1. Open the relevant lecture folder (e.g., `13062 L3/Codes/`) in Arduino IDE or PlatformIO.
2. Connect your ESP32 board, select the correct board/port, and upload the sketch (example: `WEBSERVER-ESPROBOT.ino` or `L3-Straightline-Turn.ino`).
3. For web-control modules, connect the ESP32 to your Wi‑Fi network and open the served web UI in a browser.
4. Tune PID constants in the `PID.h`/`PID` files as described in each module video.

## Contributing

Contributions, bug reports, and improvements are welcome. Please open issues or pull requests on the GitHub repository and reference the relevant module.

---
_This README was generated to organize the LIFE course materials contained in this repository. For the official course site, videos, and support options, visit https://neweraexploration.com/courses._

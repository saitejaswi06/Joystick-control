# 🎮 Joystick-Based Differential Drive Control | ESP8266 + Pygame
A real-time robot control system using a USB joystick and ESP8266, where joystick movements are translated into PWM signals for differential drive control via serial communication.

## 🎯 Objective
To control a differential drive robot using a game controller connected to a PC, with the PC sending real-time motor PWM values to the robot’s ESP8266 microcontroller over UART.

## ⚙️ Technologies Used
| Domain | Tools / Libraries |
|--------------------|------------------------------------------|
| Game Controller | Pygame Joystick API |
| Serial Communication | PySerial (Python), UART on ESP8266 |
| Motor Control | ESP8266, L293D Motor Driver |
| Platform | PC (Windows/Linux), ESP8266 NodeMCU |
| Programming | Python 3.x (Pygame, PySerial) |

## 🛠️ System Overview
The Python script reads joystick X and Y axes using Pygame's Joystick module, computes left and right wheel PWM values using a differential drive algorithm (left_pwm = scale(y + x), right_pwm = scale(y - x)), and sends them over serial in the format `<left_pwm>,<right_pwm>\n`. The ESP8266 reads these values and drives the left and right DC motors via an L293D motor driver.

## 🔩 Hardware Setup
| Component | Purpose |
|-------------------|--------------------------------------|
| ESP8266 NodeMCU | Wi-Fi-enabled microcontroller |
| L293D Motor Driver | Controls left & right DC motors |
| Differential Drive | Robot chassis |
| PC | Runs the joystick reading Python script |
| Game Controller | Xbox / Logitech / PS gamepad |

## 🎮 Joystick Mapping
| Axis | Control |
|-----|---------|
| X-axis (axis 0) | Angular velocity (left/right turn) |
| Y-axis (axis 1) | Linear velocity (forward/backward) |
Both axes are combined to form left and right wheel PWM values scaled between -255 and 255.

## 💻 Example Data Sent over Serial
`120,100\n` for forward with slight right turn, `-200,-200\n` for full reverse, `0,0\n` for stop.

## ✅ Key Features
Smooth differential drive control with joystick axes mapped to left/right wheel speeds. Scaled PWM output for proportional motor speed control. Simple and efficient serial communication protocol. Keyboard interrupt handling for safe stop on exit.

## 🔧 Future Improvements
Add Wi-Fi-based control using UDP/TCP instead of serial. Integrate PID control on ESP8266 for smoother wheel speed transitions. Add joystick button mapping for mode switching (e.g., slow/fast mode).

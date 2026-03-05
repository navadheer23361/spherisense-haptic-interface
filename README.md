# SpheriSense – Spherical Multimodal Haptic Interface

SpheriSense is a spherical multimodal haptic interface designed for intuitive human–computer interaction (HCI).  
The system integrates ESP32-based sensing, IMU motion tracking, wireless communication, and tactile feedback to enable immersive control and interaction in robotics, virtual reality, and teleoperation applications.

---

## Project Overview

Traditional human–computer interfaces often rely on keyboards, mice, or touchscreens, which limit natural interaction.  
SpheriSense explores a more intuitive interaction model by using a **spherical handheld device** capable of sensing motion, force, and grip patterns while providing tactile feedback to the user.

The system combines:

- Motion sensing using IMU
- Finger force sensing
- Wireless communication
- Haptic feedback motors
- Real-time control interfaces

This enables a natural and immersive interaction between humans and digital or robotic systems.

---

## System Architecture

The system consists of three main modules:

### 1. Input & Sensing
- Finger force sensors (analog inputs)
- MPU6050 IMU for motion tracking
- Joystick for directional control

### 2. Processing Units
- **ESP32** – main controller handling sensing and communication
- **Arduino Nano** – dedicated finger sensor interface
- **ESP8266** – motor receiver and control interface

### 3. Output & Feedback
- Haptic motors for tactile feedback
- Motor driver (L298N) for actuator control
- Real-time dashboard for visualization

---

## Hardware Components

| Component | Purpose |
|--------|--------|
| ESP32 | Main processing and wireless communication |
| ESP8266 | Motor receiver and actuator control |
| Arduino Nano | Finger sensor interface |
| MPU6050 IMU | Motion and orientation tracking |
| L298N Motor Driver | Motor control |
| Analog Potentiometers / Force Sensors | Finger force detection |
| Haptic Motors | Tactile feedback |

---

## Communication Architecture

Two wireless communication modes are used:

### Mode 1 – Motor Control
Protocol: **ESP-NOW / UDP Broadcast**

Used for:
- Real-time motor control
- Low latency communication between controllers

### Mode 2 – Air Mouse Interface
Protocol: **Bluetooth Low Energy (BLE)**

Used for:
- PC interaction
- Motion-based cursor control


---

## Features

- Multimodal haptic interaction
- Motion sensing using IMU
- Gives kinesthetic feedback
- Wireless communication between modules
- Real-time dashboard monitoring
- Hardware prototype with integrated electronics
- Modular architecture for future expansion

---

## Applications

Possible use cases include:

- Robotics teleoperation
- Virtual reality interaction
- Human–computer interfaces
- Training simulators
- Assistive technologies
- Space HCI systems

---

## Future Improvements

- Replace potentiometers with **force-sensitive resistors (FSRs)**
- Implement **closed-loop BLDC force feedback**
- Add additional haptic feedback channels
- Design an ergonomic **3D-printed enclosure**
- Integrate advanced gesture recognition

---

## Demo

A working demonstration video is included in the repository.


---

## Contributors

- **Navadheer Kumar** – System schematics and CAD modelling
- **Neeraj Chandra** – System architecture and sensor integration
- **Akshay** – Prototype fabrication

---

## License

This project is developed for academic and research purposes.

# Self-Balancing Robot Using Arduino and MPU6050

## Overview

This project implements a **two-wheel self-balancing robot** using an **Arduino**, an **MPU6050** IMU, and a **PID (Proportional-Integral-Derivative)** controller. The robot continuously measures its tilt angle using the MPU6050's Digital Motion Processor (DMP) and adjusts the speed and direction of two DC motors to maintain balance.

The project is designed as a simple and efficient implementation of a balancing robot using the MPU6050 DMP library and an L298N (or compatible) motor driver.

---

## Features

* MPU6050 DMP-based angle estimation
* PID controller for balance stabilization
* Automatic motor direction and speed control
* FIFO overflow protection
* Fall detection with automatic motor shutdown
* Compatible with Arduino Uno and similar boards

---

## Hardware Requirements

* Arduino Uno (or compatible)
* MPU6050 IMU Sensor
* L298N Motor Driver
* 2 DC Geared Motors
* Robot Chassis
* 2 Wheels
* Battery Pack (7.4V–12V recommended)
* Jumper Wires

---

## Pin Connections

### MPU6050

| MPU6050 | Arduino |
| ------- | ------- |
| VCC     | 5V      |
| GND     | GND     |
| SDA     | A4      |
| SCL     | A5      |
| INT     | D2      |

### Motor Driver

| L298N | Arduino |
| ----- | ------- |
| ENA   | D5      |
| IN1   | D6      |
| IN2   | D7      |
| IN3   | D8      |
| IN4   | D9      |
| ENB   | D10     |

---

## Software Requirements

* Arduino IDE
* I2Cdev Library
* MPU6050 Library (MotionApps 2.0)

---

## PID Parameters

The default PID values used are:

```cpp
Kp = 21.0
Ki = 140.0
Kd = 0.8
```

These values are intended as a starting point and should be tuned according to the robot's weight, motor characteristics, wheel size, battery voltage, and center of gravity.

---

## Working Principle

1. The MPU6050 measures the robot's orientation.
2. The DMP calculates the pitch angle.
3. The pitch angle is compared with the desired balance angle (180°).
4. The PID controller computes the correction required.
5. Motor speed and direction are adjusted to restore balance.
6. If the robot tilts beyond the safe range, the motors are automatically disabled to protect the hardware.

---

## Safety Features

* FIFO overflow handling
* Motor shutdown when the robot falls
* Output limiting
* Integral windup protection
* PWM output constrained to valid range

---

## Project Structure

```
Self-Balancing-Robot/
│
├── SelfBalancingRobot.ino
├── README.md
└── images/
    ├── robot.jpg
    └── wiring.png
```

---

## Installation

1. Clone the repository.

```
git clone https://github.com/your-username/self-balancing-robot.git
```

2. Install the required Arduino libraries.
3. Open the `.ino` file in Arduino IDE.
4. Connect the Arduino.
5. Upload the sketch.
6. Power the robot and begin PID tuning if necessary.

---

## Future Improvements

* Auto PID tuning
* Bluetooth control
* OLED display for debugging
* Wireless telemetry
* Battery voltage monitoring
* Encoder-based speed feedback
* Kalman filter implementation

---

## License

This project is released under the MIT License. You are free to use, modify, and distribute it with proper attribution.

---

## Acknowledgments

* Jeff Rowberg for the I2Cdev and MPU6050 libraries.
* Arduino community for documentation and open-source resources.

---

## Author

**Batool Shahid**

If you found this project helpful, consider giving the repository a ⭐ on GitHub.

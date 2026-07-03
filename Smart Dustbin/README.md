# Smart Lid Automation using Arduino and Ultrasonic Sensor

This repository contains the Arduino-based source code for an automated smart lid system (like a Smart Dustbin or automatic container). The system uses an ultrasonic sensor to detect objects within a specific range and automatically triggers a servo motor to open and close the lid.

---

## 🛠️ Components Required

* **Microcontroller:** Arduino Uno (or any compatible Arduino board)
* **Sensor:** HC-SR04 Ultrasonic Sensor
* **Actuator:** SG90 Servo Motor (or equivalent)
* **Jumper Wires** & **Breadboard**

---

## 📌 Pin Configurations

Connect the components to your Arduino board according to the following pin map:

| Component | Component Pin | Arduino Pin |
| :--- | :--- | :--- |
| **Ultrasonic Sensor** | VCC | 5V |
| | Trigger | Pin 9 |
| | Echo | Pin 10 |
| | GND | GND |
| **Servo Motor** | Signal (Orange/Yellow) | Pin 11 |
| | Power (Red) | 5V |
| | Ground (Brown/Black) | GND |

---

## ⚙️ How It Works

1. The **Ultrasonic Sensor** continuously broadcasts ultrasonic waves to measure the distance of any object in front of it.
2. If an object or hand comes within the **20 cm** threshold (`MAX_DISTANCE`), the **Servo Motor** rotates to **90 degrees** to open the lid.
3. The lid stays open as long as the object is detected. Once the object moves away, the servo returns to **0 degrees**, closing the lid securely.
4. Real-time distance data is also printed to the **Serial Monitor** at a baud rate of `9600`.

---

## 🚀 Getting Started

### Prerequisites
* Download and install the [Arduino IDE](https://www.arduino.cc/en/software).
* The code utilizes the built-in `Servo.h` library, so no external library installations are required.

### Installation & Flashing
1. Clone this repository to your local machine:
   ```bash
   git clone [https://github.com/YOUR_USERNAME/YOUR_REPOSITORY_NAME.git](https://github.com/YOUR_USERNAME/YOUR_REPOSITORY_NAME.git)

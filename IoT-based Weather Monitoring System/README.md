# IoT-Based Weather Monitoring System

## Overview

This project is an Arduino-based Weather Monitoring System that measures real-time temperature and humidity using a DHT11 sensor and displays the readings on a 16×2 I2C LCD. Sensor data is also sent to the Serial Monitor for debugging and monitoring.

The system uses a non-blocking timer based on the `millis()` function, allowing continuous operation without relying on long delays.

---

## Features

- Real-time temperature monitoring
- Real-time humidity monitoring
- 16×2 I2C LCD display
- Serial Monitor output
- Non-blocking sensor updates using `millis()`
- Sensor error detection
- Lightweight and beginner-friendly implementation

---

## Technologies Used

- Arduino IDE
- C++
- DHT11 Sensor
- 16×2 I2C LCD
- Wire Library
- LiquidCrystal_I2C Library
- DHT Sensor Library

---

## Hardware Requirements

- Arduino Uno
- DHT11 Temperature & Humidity Sensor
- 16×2 I2C LCD Display
- Breadboard
- Jumper Wires
- USB Cable

---

## Circuit Connections

### DHT11

| DHT11 Pin | Arduino Uno |
|-----------|-------------|
| VCC | 5V |
| GND | GND |
| DATA | Digital Pin 2 |

### I2C LCD

| LCD Pin | Arduino Uno |
|----------|-------------|
| VCC | 5V |
| GND | GND |
| SDA | A4 |
| SCL | A5 |

---

## Required Libraries

Install the following libraries from the Arduino Library Manager:

- DHT sensor library by Adafruit
- Adafruit Unified Sensor
- LiquidCrystal_I2C
- Wire (Built-in)

---

## Project Structure

```
IoT-Weather-Monitoring-System/
│
├── WeatherMonitoringSystem.ino
├── README.md
└── images/
    ├── circuit_diagram.png
    ├── lcd_output.jpg
    └── hardware_setup.jpg
```

---

## Installation

Clone the repository:

```bash
git clone https://github.com/your-username/iot-weather-monitoring-system.git
```

Open the project in the Arduino IDE.

Install the required libraries.

Connect the hardware according to the circuit diagram.

Select your Arduino board and COM port.

Upload the code.

Open the Serial Monitor at **9600 baud**.

---

## Working Principle

1. The Arduino initializes the DHT11 sensor and the I2C LCD.
2. Every 2 seconds, the DHT11 measures temperature and humidity.
3. The readings are displayed on the LCD.
4. The same readings are printed on the Serial Monitor.
5. If the sensor fails to respond, an error message is displayed on both the LCD and Serial Monitor.

---

## Sample Serial Monitor Output

```
Temperature: 28.4 C
Humidity: 61.2 %

Temperature: 28.5 C
Humidity: 61.0 %

Temperature: 28.6 C
Humidity: 60.9 %
```

---

## LCD Output

```
Temp: 28.4°C
Hum: 61.2%
```

---

## Applications

- Weather Monitoring
- Smart Home Systems
- Greenhouse Monitoring
- Environmental Monitoring
- IoT Projects
- Educational Projects
- Agriculture Automation

---

## Future Improvements

- Wi-Fi connectivity using ESP8266 or ESP32
- Cloud data logging with ThingSpeak
- Mobile application integration
- OLED display support
- Weather forecasting
- Email and SMS alerts
- SD card data logging
- MQTT integration

---

## License

This project is licensed under the MIT License.

---

## Acknowledgments

- Arduino Community
- Adafruit for the DHT Library
- LiquidCrystal_I2C Library Developers

---

## Author

**Batool Shahid**

If you found this project helpful, consider giving the repository a ⭐ on GitHub.

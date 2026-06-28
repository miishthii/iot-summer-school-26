# Wi-Fi Temperature Monitor (ESP32)

## Project Description

This project implements a Wi-Fi-enabled temperature monitoring system using an ESP32 and a DHT sensor. The ESP32 hosts a web server that displays live temperature, humidity, device uptime, and provides a button to control an onboard LED. The webpage automatically refreshes every 10 seconds to display updated sensor readings.

---

## Hardware Required

* ESP32 Development Board
* DHT11 Sensor *(DHT22 used for Wokwi simulation)*
* Red LED
* 220 Ω Resistor
* Breadboard
* Jumper Wires

---

## Circuit Connections

### DHT Sensor

| DHT Pin | ESP32 Pin |
| ------- | --------- |
| VCC     | 3.3V      |
| GND     | GND       |
| DATA    | GPIO 4    |

### LED

| LED Pin     | ESP32 Pin                    |
| ----------- | ---------------------------- |
| Anode (+)   | GPIO 2                       |
| Cathode (-) | GND (through 220 Ω resistor) |

---

## Features

* Displays Temperature (°C)
* Displays Humidity (%)
* Displays Device Uptime
* LED ON/OFF Control using a Web Button
* Automatic Page Refresh every 10 Seconds
* Web Server Accessible over Wi-Fi

---

## Software Requirements

* Arduino IDE
* ESP32 Board Package
* WiFi Library
* WebServer Library
* DHT Sensor Library by Adafruit

---

## How to Run

1. Open the project in Arduino IDE.
2. Install the required libraries.
3. Enter your Wi-Fi SSID and Password in the code.
4. Upload the sketch to the ESP32.
5. Open the Serial Monitor (115200 baud).
6. Note the IP address displayed after the ESP32 connects to Wi-Fi.
7. Enter the IP address into a web browser.
8. View the live dashboard and use the **Toggle LED** button to control the LED.

---

## Expected Output

The web page displays:

* Current Temperature
* Current Humidity
* Device Uptime
* ESP32 IP Address
* Toggle LED Button
* Automatic Refresh every 10 seconds

---

## Folder Structure

```text
week4/
└── wifi_webserver/
    ├── wifi_webserver.ino
    ├── README.md
    └── screenshots/
        └── webpage.png
```

---

## Libraries Used

* WiFi
* WebServer
* DHT Sensor Library by Adafruit

---

## Simulation Note

This project was developed using **Wokwi** with an **ESP32** and a **DHT22** sensor, as DHT11 is not available in the simulator. The DHT22 is fully compatible for demonstrating the required functionality. The web interface was designed to represent the expected output of the ESP32 web server.

---

## Author

**Name:** Mishthi Chopra

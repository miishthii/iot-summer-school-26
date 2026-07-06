# 🚨 PIR-Based Security Camera Trigger

## 📌 Problem Statement

A small shop in Rohtak, Haryana requires a low-cost security monitoring system that detects motion after shop hours and immediately alerts the owner. This project uses a PIR sensor to detect movement, provides a three-stage alarm using LEDs and a buzzer, logs events to the Serial Monitor, and supports optional Telegram notifications for a physical ESP32 deployment.

---

# 💡 Solution Approach

An ESP32 continuously monitors a PIR motion sensor for movement. Motion alerts are only processed during user-defined monitoring hours, which can be configured through the Serial Monitor using the `SET_HOURS` command.

A potentiometer is used to simulate adjustable sensor sensitivity. Depending on the potentiometer value, the system selects one of three alarm levels:

- **Warning**
- **Alarm**
- **Urgent**

Each level activates a different buzzer frequency and LED flashing pattern to simulate increasing alert severity.

Whenever motion is detected during the active monitoring period, the ESP32 records the event with a timestamp in the Serial Monitor.

For physical ESP32 deployment, Telegram notification support is provided in a separate integration file.

---

# 🛠 Hardware Components

| Component | Quantity |
|-----------|:--------:|
| ESP32 Dev Module | 1 |
| PIR Motion Sensor | 1 |
| Potentiometer | 1 |
| Active Buzzer | 1 |
| Green LED | 1 |
| Yellow LED | 1 |
| Red LED | 1 |
| 220Ω Resistors | 3 |
| Jumper Wires | As required |

---

# 🔌 Pin Connections

| Component | ESP32 Pin |
|-----------|-----------|
| PIR OUT | GPIO27 |
| Potentiometer | GPIO34 |
| Active Buzzer | GPIO25 |
| Green LED | GPIO18 |
| Yellow LED | GPIO19 |
| Red LED | GPIO21 |

---

# ⚙ Features

- PIR motion detection
- Adjustable sensitivity using potentiometer
- Three-stage alarm escalation
- Sequential LED alert simulation
- Active buzzer warning
- Configurable monitoring hours
- Timestamped Serial logging
- Telegram integration for physical ESP32 deployment

---

# 🚨 Alarm Levels

| Level | LEDs | Buzzer |
|-------|------|--------|
| Warning | Green | Low frequency |
| Alarm | Green + Yellow | Medium frequency |
| Urgent | Green + Yellow + Red | High frequency with rapid flashing |

---

# ⏰ Monitoring Hours

Monitoring hours can be configured through the Serial Monitor.

Example:

```text
SET_HOURS 22 06
```

This enables motion monitoring from **10:00 PM until 6:00 AM**.

---

# 🖥 Sample Serial Output

```text
==================================
PIR Security Camera Trigger
==================================

Monitoring Hours : 22 -> 6

--------------------------------
Timestamp : 18 sec
Motion Detected
Sensitivity Value : 3450
Alert Level : URGENT
[18 sec] URGENT
Motion Event Logged
--------------------------------
```

---

# 📱 Telegram Integration

A separate file named **`TelegramIntegration.ino`** is included in the repository. It contains the Wi-Fi connection and Telegram Bot API implementation required to send motion alerts to a Telegram chat on a physical ESP32.

**Simulation Note:** The primary Wokwi project demonstrates the PIR sensor, alarm escalation, LED indications, and Serial logging. Telegram functionality is provided separately for deployment on actual hardware.

---


# 📚 Libraries Used

- WiFi.h
- HTTPClient.h *(Telegram integration)*
- ArduinoJson *(Optional for future enhancements)*

---

# 👩‍💻 Author

**Mishthi Chopra**

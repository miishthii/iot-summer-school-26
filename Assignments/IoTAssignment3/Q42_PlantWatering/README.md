# 🌱 Automated Plant Watering System
**video demo**: https://www.loom.com/share/de1deaf41923426fbde2ba8e11cd67a0

## 📌 Problem Statement
 
A horticulture farmer in Jammu & Kashmir wants to automate irrigation for a small saffron farm plot. The system should monitor soil moisture and water the plants only when the soil is dry. Since saffron is highly sensitive to overwatering, the system must avoid watering during rainy or overcast conditions. The farmer should also be able to manually activate irrigation whenever required.

---

# 💡 Solution Approach

This project uses an **ESP32** to monitor soil moisture, ambient light, and weather conditions to determine whether irrigation is required.

For simulation in Wokwi, a **potentiometer** is used to emulate a soil moisture sensor because Wokwi does not currently provide a soil moisture sensor component. An **LDR** acts as a local rain proxy by detecting low ambient light (overcast conditions), while the **OpenWeatherMap REST API** is used to check whether rain is currently reported for the selected location.

The irrigation pump is simulated using an **LED** connected to the ESP32. The pump is activated only when:

- Soil moisture is classified as **DRY**
- The LDR indicates **no overcast conditions**
- The weather API reports **no rain**

A push button provides manual irrigation override. After manual activation, a **5-minute lockout period** prevents repeated watering to avoid over-irrigation.

A **16×2 I2C LCD** continuously displays soil moisture percentage, current operating mode, and the elapsed time since the last watering event.

All readings are logged to **Google Sheets** using Google Apps Script over Wi-Fi.

---

# 🛠 Hardware Components

| Component | Quantity |
|-----------|:--------:|
| ESP32 Dev Module | 1 |
| Potentiometer *(Soil Moisture Simulation)* | 1 |
| LDR | 1 |
| Push Button | 1 |
| Green LED *(Pump Simulation)* | 1 |
| 220Ω Resistor | 1 |
| 16×2 LCD (I2C) | 1 |
| Jumper Wires | As required |

---

# 🔌 Pin Connections

| Component | ESP32 Pin |
|-----------|-----------|
| Potentiometer | GPIO34 |
| LDR | GPIO35 |
| Push Button | GPIO18 |
| Pump LED | GPIO19 |
| LCD SDA | GPIO21 |
| LCD SCL | GPIO22 |

---

# 🌦 Irrigation Logic

The irrigation decision follows the logic below:

```text
Read Soil Moisture
        │
        ▼
Is Soil DRY?
        │
       Yes
        │
        ▼
Check LDR + Weather API
        │
   ┌────┴────┐
   │         │
Rain?      No Rain
   │         │
   ▼         ▼
Skip      Water Plant
```

---

# 📊 Soil Moisture Zones

| Moisture (%) | Status |
|--------------|--------|
| 0 – 29% | 🌵 DRY |
| 30 – 69% | ✅ OPTIMAL |
| 70 – 100% | 💧 WET |

---

# 🌧 Rain Detection

The system uses **two independent methods** to determine rainfall conditions:

- **LDR** detects overcast or low-light conditions.
- **OpenWeatherMap REST API** checks current weather information.

Watering is skipped whenever **either method** indicates rain.

---

# 📺 LCD Display

Example:

```text
M:45% DRY
Last:120s
```

---

# ☁ Google Sheets Logging

Sensor readings are uploaded using:

- Wi-Fi
- HTTP GET Requests
- Google Apps Script
- Google Sheets

Each log entry contains:

- Timestamp
- Moisture Percentage
- Moisture Status
- Rain Status
- Last Watered Time

---

# 🚀 Features

- Automatic irrigation
- Soil moisture monitoring
- LDR-based rain detection
- Weather API integration
- Manual watering override
- 5-minute safety lockout
- LCD status display
- Google Sheets cloud logging
- Offline decision making using LDR when internet is unavailable

---

# ⚠ Simulation Notes

This project was developed using **Wokwi**.

To accommodate simulator limitations:

- A **potentiometer** is used to simulate the soil moisture sensor.
- A **green LED** simulates the relay-controlled water pump.
- **ESP32** is used instead of ESP8266 because the project requires **two analog inputs** (soil moisture and LDR), while the ESP8266 provides only one ADC pin.

These substitutions preserve the intended system functionality while enabling complete simulation.

---


# 📚 Libraries Used

- WiFi.h
- HTTPClient.h
- ArduinoJson
- Wire.h
- LiquidCrystal_I2C

---

# 👩‍💻 Author

**Mishthi Chopra**

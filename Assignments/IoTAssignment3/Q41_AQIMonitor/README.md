# 🏠 Smart Home Air Quality Monitor

## 📌 Problem Statement

A family in Milan, Europe, is concerned about indoor air quality during winter when wood is burned for heating. This project designs an IoT-based Smart Home Air Quality Monitoring System using an ESP32 that continuously monitors smoke/gas concentration, temperature, and humidity. The system provides local visual and audible alerts based on air quality levels and continues to function even without an internet connection.

---

# 💡 Solution Approach

The system uses an **MQ-2 gas sensor** to detect smoke and gas concentration and a **DHT22 (used in Wokwi; replace with DHT11 for physical hardware)** to measure temperature and humidity.

At startup, the MQ-2 sensor is calibrated by recording a baseline gas value. During operation, the current gas reading is compared with the baseline to classify air quality into three severity levels:

- **SAFE** – Normal indoor air quality
- **MODERATE** – Elevated smoke levels
- **DANGER** – Unsafe smoke concentration

Depending on the detected severity:

- 🟢 Green LED indicates safe conditions.
- 🟡 Yellow LED indicates moderate smoke levels.
- 🔴 Red LED indicates dangerous air quality.
- A buzzer sounds different tones for moderate and danger conditions.

Sensor readings are logged to the Serial Monitor in CSV format, making them easy to export or analyze. For a physical ESP32, Bluetooth notifications can also be sent to a connected smartphone using the ESP32's built-in BluetoothSerial library. Since Wokwi does not support Bluetooth communication, a simulated mobile interface is included as an illustration of the expected alerts.

---

# 🔧 Hardware Components

| Component | Quantity |
|-----------|:--------:|
| ESP32 Dev Module | 1 |
| MQ-2 Gas Sensor | 1 |
| DHT22 Sensor *(DHT11 for actual hardware)* | 1 |
| RGB LED (Common Cathode) | 1 |
| Active Buzzer | 1 |
| Breadboard | 1 |
| Jumper Wires | As required |

---

# ⚙️ Features

- Real-time smoke/gas monitoring
- Temperature and humidity monitoring
- Automatic MQ-2 sensor calibration
- Three-level air quality classification
- RGB LED visual indication
- Three-stage buzzer alarm
- CSV logging through Serial Monitor
- Bluetooth alert support for real ESP32
- Offline operation (no internet required)

---

# 📊 Air Quality Thresholds

| Gas Difference from Baseline | Status |
|-----------------------------:|--------|
| Less than 80 | 🟢 SAFE |
| 80 – 249 | 🟡 MODERATE |
| 250 and above | 🔴 DANGER |

---

# 📈 Sample Serial Output

```text
Timestamp, MQ-2 Value, DHT11 Temp, DHT11 Humidity, Severity Level
00:01,220,23.4,49,SAFE
00:02,280,23.5,50,SAFE
00:03,420,23.6,49,MODERATE
00:04,710,23.8,48,DANGER
```

---

# 📱 Sample Bluetooth Alert

```text
SAFE

Gas:210
Temp:22.8°C
Humidity:51%
```

```text
WARNING

Moderate Smoke Detected

Gas=430

Check Fireplace
```

```text
DANGER!!

Smoke Level Critical

Gas=765

Open Windows
Leave Room if Necessary
```

---


# 👩‍💻 Author

**Mishthi Chopra**

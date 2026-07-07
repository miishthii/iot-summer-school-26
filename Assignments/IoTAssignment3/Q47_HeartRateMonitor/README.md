# ❤️ Heart Rate & SpO₂ Monitor (Simulation)

## 📌 Problem Statement

This project simulates a heart rate and blood oxygen (SpO₂) monitoring system using an ESP32. Since the MAX30102 pulse oximeter is unavailable in Wokwi, an LDR is used as a proxy sensor to simulate varying pulse and oxygen saturation values. The system continuously monitors simulated health parameters, smooths sensor readings using a rolling average, displays the values on the Serial Monitor, and activates an alert LED whenever abnormal readings are detected.

**Note:** This project is intended for learning sensor interfacing concepts and is **not a medical device**.
**Video demo:** https://www.loom.com/share/96358ea41e4d4aa1ae6f9188194ef12a

---

# 💡 Solution Approach

An **ESP32** reads analog values from an **LDR**, which acts as a simulated pulse oximeter. A **5-reading rolling average** is calculated to reduce sensor noise and provide stable measurements.

The averaged sensor value is mapped to simulated:

- Heart Rate (40–140 bpm)
- Blood Oxygen Saturation (88–100%)

The system evaluates the readings against predefined safety thresholds:

- Heart Rate < **50 bpm**
- Heart Rate > **120 bpm**
- SpO₂ < **94%**

If any of these conditions occur, a **red LED** turns ON to indicate an abnormal reading.

Sensor readings are displayed on the **Serial Monitor** every two seconds, and a sample CSV log format is included in the project for documentation.

---

# 🛠 Hardware Components

| Component | Quantity |
|-----------|:--------:|
| ESP32 Dev Module | 1 |
| LDR | 1 |
| 10kΩ Resistor | 1 |
| Red LED | 1 |
| 220Ω Resistor | 1 |
| Jumper Wires | As required |

---

# 🔌 Pin Connections

| Component | ESP32 Pin |
|-----------|-----------|
| LDR | GPIO34 |
| Red LED | GPIO14 |

---

# ❤️ Simulated Health Parameters

| Parameter | Simulated Range |
|-----------|-----------------|
| Heart Rate | 40–140 bpm |
| SpO₂ | 88–100% |

---

# ⚠ Alert Conditions

The red LED turns ON whenever:

- Heart Rate < **50 bpm**
- Heart Rate > **120 bpm**
- SpO₂ < **94%**

Otherwise, the LED remains OFF.

---

# ⚙ Features

- Simulated heart rate monitoring
- Simulated SpO₂ monitoring
- LDR-based analog sensor simulation
- 5-reading rolling average smoothing
- Automatic abnormal reading detection
- LED alert indication
- Serial Monitor output every 2 seconds
- Sample CSV health log

---

# 📄 Sample Serial Output

```text
--------------------------
Heart Rate : 82 bpm
SpO₂ : 98 %
Alert : NO
--------------------------

--------------------------
Heart Rate : 128 bpm
SpO₂ : 92 %
Alert : YES
--------------------------
```

---

# 📁 Health Log

A sample CSV file is included in:

```text
/data/health_log.csv
```

Example:

```csv
Timestamp,HeartRate,SpO2,Alert
0,78,98,NO
2,81,99,NO
4,122,93,YES
6,75,98,NO
8,46,92,YES
```
---

# 📚 Libraries Used

- Arduino.h

---

# ⚠ Simulation Notes

This project was developed using **Wokwi**.

Since the **MAX30102 pulse oximeter** is not available in the simulator, an **LDR** is used as a proxy sensor. Analog readings from the LDR are mapped to simulated heart rate and SpO₂ values, allowing the signal processing and alert logic to be demonstrated while preserving the intended functionality of the assignment.

---

# 👩‍💻 Author

**Mishthi Chopra**

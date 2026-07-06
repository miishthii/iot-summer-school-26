# 🔐 Smart Door Lock with OTP
**Video demo:** https://www.loom.com/share/d9fdf44abeca4de6b5fbf55a15d38995

## 📌 Problem Statement
 
A university hostel wants to replace traditional physical keys with a secure PIN-based access system. This project implements an IoT-enabled Smart Door Lock that allows a student to enter a 4-digit ID, generates a unique 6-digit One-Time Password (OTP), and unlocks the door only after the correct OTP is entered within 30 seconds. The system logs all access attempts and provides visual feedback using an LCD display.

---

# 💡 Solution Approach

The system is built around an **ESP32** that interfaces with a **4×4 keypad**, **16×2 I2C LCD**, and **SG90 servo motor**.

A student first enters their **4-digit ID** through the keypad. Once a valid ID is received, the ESP32 generates a **random 6-digit OTP** and displays a notification indicating that the OTP has been sent. In a physical implementation, the OTP can be transmitted to the user's smartphone using the ESP32's built-in Bluetooth (BluetoothSerial) or an HC-05 Bluetooth module. Since Wokwi does not support Bluetooth communication, the OTP is displayed on the Serial Monitor for demonstration purposes.

The user must enter the generated OTP within **30 seconds**. A non-blocking timer using `millis()` tracks the validity period. If the entered OTP matches the generated OTP before the timer expires, the servo rotates **90°** to simulate unlocking the door before returning to the locked position. If the OTP is incorrect or expires, access is denied and the system resets.

All successful and failed login attempts are recorded in the Serial Monitor.

---

# 🛠 Hardware Components

| Component | Quantity |
|-----------|:--------:|
| ESP32 Dev Module | 1 |
| 4×4 Matrix Keypad | 1 |
| 16×2 I2C LCD | 1 |
| SG90 Servo Motor | 1 |
| Jumper Wires | As required |

---

# 🔌 Pin Connections

| Component | ESP32 Pin |
|-----------|-----------|
| Keypad R1 | GPIO13 |
| Keypad R2 | GPIO12 |
| Keypad R3 | GPIO14 |
| Keypad R4 | GPIO27 |
| Keypad C1 | GPIO26 |
| Keypad C2 | GPIO25 |
| Keypad C3 | GPIO33 |
| Keypad C4 | GPIO32 |
| LCD SDA | GPIO21 |
| LCD SCL | GPIO22 |
| Servo Signal | GPIO18 |

---

# 🔄 System Workflow

```text
Power On
   │
   ▼
Enter 4-digit ID
   │
   ▼
Generate 6-digit OTP
   │
   ▼
OTP Sent
(Bluetooth / Serial Monitor)
   │
   ▼
Enter OTP
   │
 ┌─┴───────────┐
 │             │
Correct      Incorrect / Timeout
 │             │
 ▼             ▼
Unlock      Access Denied
Door         Reset System
```

---

# 🚀 Features

- 4-digit student ID authentication
- Random 6-digit OTP generation
- 30-second OTP expiry timer using `millis()`
- Servo motor door lock simulation
- LCD prompts and masked keypad input
- Serial logging of access attempts
- Bluetooth-ready implementation for physical ESP32
- Automatic system reset after each attempt

---

# 📺 LCD Screens

### Startup

```text
Smart Door Lock
System Start
```

### ID Entry

```text
Enter ID
****
```

### OTP Entry

```text
Enter OTP
******
```

### Success

```text
ACCESS
GRANTED
```

### Failure

```text
ACCESS
DENIED
```

### Timeout

```text
OTP
EXPIRED
```

---

# 📄 Sample Serial Output

```text
System Ready

ID Entered: 1234

OTP Generated: 548271

OTP Entered: 548271

ACCESS GRANTED

Door Unlocked

----------------------

LOG: SUCCESS ENTRY
```

Failed attempt:

```text
System Ready

ID Entered: 1234

OTP Entered: 123456

ACCESS DENIED

----------------------

LOG: FAILED ENTRY
```

---

# 📱 Bluetooth Support

For a physical ESP32, the generated OTP can be transmitted to a connected smartphone using the **BluetoothSerial** library or an **HC-05 Bluetooth module**.

**Simulation Note:** Wokwi does not currently support Bluetooth communication. Therefore, the OTP is displayed through the Serial Monitor, and a sample mobile notification is provided as an illustration.

---

# 📚 Libraries Used

- Wire.h
- LiquidCrystal_I2C.h
- Keypad.h
- ESP32Servo.h

---

# 👩‍💻 Author

**Mishthi Chopra**

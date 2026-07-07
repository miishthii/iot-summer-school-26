# 🌆 Smart City Proposal – IoT Solutions for Jammu

## Introduction

As part of the Jammu Smart City initiative, Internet of Things (IoT) technology can improve public infrastructure by enabling real-time monitoring, automation, and data-driven decision making. This proposal presents three IoT-based solutions designed to improve energy efficiency, environmental monitoring, and waste management. The proposed systems are low-cost, scalable, and suitable for deployment throughout Jammu city.

---

# 1. Smart Street Lighting

https://www.loom.com/share/21b751d46f1e4e28a70f3bf6fcc95b24
https://wokwi.com/projects/468906013313278977

## Objective

Reduce electricity consumption by automatically switching street lights ON only during nighttime when pedestrians or vehicles are detected.

### Sensors Required

- LDR (Light Dependent Resistor)
- PIR Motion Sensor

### Microcontroller & Connectivity

- ESP32
- Wi-Fi (MQTT)

### Data Flow

```text
LDR + PIR
      │
      ▼
ESP32 Controller
      │
   MQTT Protocol
      │
      ▼
Cloud MQTT Broker
      │
      ▼
Smart City Dashboard
```

### Estimated Cost per Node

| Component | Cost (INR) |
|-----------|-----------:|
| ESP32 | ₹550 |
| PIR Sensor | ₹120 |
| LDR | ₹20 |
| LED/Relay | ₹80 |
| Miscellaneous | ₹100 |
| **Total** | **≈ ₹870** |

### Benefits

- Reduces electricity consumption
- Improves public safety
- Low maintenance
- Automatic operation

---

# 2. Smart Air Quality Monitoring

https://www.loom.com/share/2c990c8136db4413a660aaac324263e7
https://wokwi.com/projects/468907101773073409

## Objective

Continuously monitor environmental conditions and air pollution across different parts of Jammu city.

### Sensors Required

- MQ-2 Gas Sensor
- DHT11 Temperature & Humidity Sensor

### Microcontroller & Connectivity

- ESP32
- Wi-Fi (MQTT)

### Data Flow

```text
MQ-2 + DHT11
       │
       ▼
ESP32 Controller
       │
   MQTT Protocol
       │
       ▼
Cloud Database
       │
       ▼
Environmental Dashboard
```

### Estimated Cost per Node

| Component | Cost (INR) |
|-----------|-----------:|
| ESP32 | ₹550 |
| MQ-2 | ₹180 |
| DHT11 | ₹120 |
| LEDs & Miscellaneous | ₹100 |
| **Total** | **≈ ₹950** |

### Benefits

- Continuous air quality monitoring
- Early pollution detection
- Better public health awareness
- Historical environmental analysis

---

# 3. Smart Waste Bin Monitoring

https://www.loom.com/share/5a1c7d995d6f4fe99641c0e3c9d6fad9
https://wokwi.com/projects/468907991287560193

## Objective

Monitor municipal waste bins in real time and optimize garbage collection schedules.

### Sensors Required

- HC-SR04 Ultrasonic Sensor

### Microcontroller & Connectivity

- ESP32
- Wi-Fi (HTTP)

### Data Flow

```text
HC-SR04
    │
    ▼
ESP32 Controller
    │
HTTP Protocol
    │
    ▼
Cloud Server
    │
    ▼
Municipal Dashboard
```

### Estimated Cost per Node

| Component | Cost (INR) |
|-----------|-----------:|
| ESP32 | ₹550 |
| HC-SR04 | ₹150 |
| LEDs | ₹50 |
| Miscellaneous | ₹100 |
| **Total** | **≈ ₹850** |

### Benefits

- Prevents overflowing waste bins
- Optimizes garbage collection routes
- Reduces fuel consumption
- Improves city cleanliness

---

# Overall Advantages

The proposed Smart City system provides several benefits:

- Reduced energy consumption through intelligent street lighting
- Continuous environmental monitoring for healthier urban living
- Efficient waste collection with reduced operational costs
- Real-time monitoring through cloud dashboards
- Easy scalability for deployment across multiple city zones
- Low-cost implementation using ESP32-based sensor nodes

---

# Conclusion

The proposed IoT-based Smart City solution combines Smart Street Lighting, Air Quality Monitoring, and Smart Waste Bin Monitoring to improve urban infrastructure in Jammu. Each system uses low-cost sensors connected to an ESP32 microcontroller with wireless communication for cloud-based monitoring. Together, these solutions improve public safety, reduce operational costs, support environmental sustainability, and enable data-driven city management. Due to their modular design and affordable hardware, these systems can be gradually deployed across the city and expanded in the future as Smart City initiatives continue to grow.

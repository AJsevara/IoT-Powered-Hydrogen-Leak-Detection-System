# 🚨 IoT-Powered Hydrogen Leak Detection System

## 📌 Introduction

Hydrogen is a key element in the **Green Hydrogen Era**, powering **clean energy** solutions. However, its **flammable and invisible nature** makes leak detection **critical** for **safety**.

This project provides a **smart hydrogen leak detection system** using **ESP8266, an MQ-x sensor, and Blynk** to ensure **real-time monitoring** and **instant alerts** in industrial environments.

---

## 🔥 Features

✔ **Real-time hydrogen gas detection**\
✔ **I2C LCD display for local monitoring**\
✔ **Remote notifications via Blynk app**\
✔ **Buzzer & LED alerts for immediate response**\
✔ **Adjustable threshold control via Blynk slider**\
✔ **Low-cost, scalable, and IoT-enabled solution**

---

## 🏭 Applications

🚀 **Green Hydrogen Production Plants** – Ensuring leak-free hydrogen processing\
🚗 **Fuel Cell Vehicles (FCVs)** – Detecting leaks in storage tanks & pipelines\
⛽ **Hydrogen Refueling Stations** – Preventing explosion risks\
🏭 **Industrial Hydrogen Storage** – Monitoring hydrogen handling in industries\
🔬 **Aerospace & Research Labs** – Safe hydrogen usage in experimental setups

---

## 🖥️ Hardware Requirements

| Component             | Quantity | Description                        |
| --------------------- | -------- | ---------------------------------- |
| **ESP8266 (NodeMCU)** | 1        | Wi-Fi-enabled microcontroller      |
| **MQ-x Gas Sensor**   | 1        | Detects hydrogen gas concentration |
| **I2C LCD (16x2)**    | 1        | Displays real-time gas levels      |
| **Buzzer**            | 1        | Alerts when gas crosses threshold  |
| **Green LED**         | 1        | Indicates safe condition           |
| **Red LED**           | 1        | Indicates gas leakage              |
| **5V Power Supply**   | 1        | Powers the system                  |

---

## 📜 Circuit Diagram

📌 **[View the circuit diagram here](hardware/circuit_diagram.png)**

---

## 🚀 Getting Started

### 1️⃣ Setup Blynk

1. **Download and install Blynk App** (iOS/Android).
2. **Create a new project** and select **ESP8266** as the device.
3. **Add a slider widget** linked to **V1 (Threshold Control)**.
4. **Copy the Blynk Authentication Token** for the Arduino code.

---

### 2️⃣ Install Required Libraries

Install the following libraries in **Arduino IDE**:

```cpp
BlynkSimpleEsp8266.h
Wire.h
LiquidCrystal_PCF8574.h
```

---

### 3️⃣ Upload Code

1. Connect **ESP8266** to your computer.
2. Open **Arduino IDE** and upload `src/main.ino`.
3. Monitor sensor readings in the **Serial Monitor**.

---

## 📜 Code Overview

This project uses **MQ-x sensor readings** to detect hydrogen gas levels. If the gas **exceeds the threshold**, the **buzzer & LED alerts** activate, and a **notification is sent via Blynk**.

---

## 📢 Future Improvements

✅ Integration with **AI-based gas leak prediction**\
✅ **Battery-powered version** for portability\
✅ **Cloud-based monitoring** for industrial use


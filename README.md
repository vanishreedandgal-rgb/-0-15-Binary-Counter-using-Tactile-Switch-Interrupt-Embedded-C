# 0-15-Binary-Counter-using-Tactile-Switch-Interrupt-Embedded-C
# 0–15 Binary Counter using Tactile Switch (Interrupt) — Embedded C

---

## Project Overview

This project implements a **4-bit Binary Counter (0–15)** using a **tactile push button** and **interrupt programming** on an AVR microcontroller.

Each press of the tactile switch triggers an **interrupt**, incrementing the binary count displayed using LEDs.

This experiment demonstrates **interrupt handling**, **GPIO interfacing**, and **real-time embedded system control**.

---

## Hardware Requirements

* AVR Microcontroller (ATmega328P / ATmega16 / ATmega32)
* 4 LEDs
* Tactile Push Button Switch
* 220Ω Current Limiting Resistors
* Breadboard
* Connecting Wires
* Power Supply / USB Programmer

---

## Software Requirements

* Microchip Studio / Atmel Studio
* AVR-GCC Compiler
* Proteus Simulator (Optional)

---

## Circuit Connections

| Component      | Microcontroller Pin |
| -------------- | ------------------- |
| LED 1          | PD2                 |
| LED 2          | PD3                 |
| LED 3          | PD4                 |
| LED 4          | PD5                 |
| Tactile Switch | PD6                 |

### Connection Method

* LED **Anode (+)** → PD2–PD5
* LED **Cathode (−)** → 220Ω Resistor → GND
* Switch one side → PD6
* Switch other side → GND

(Internal Pull-Up resistor enabled)

---

## Working Principle

1. LEDs act as a **4-bit binary display**.
2. Push button generates a **Pin Change Interrupt**.
3. Every button press:

   * Counter increments.
   * Value ranges from **0 to 15**.
4. Binary value is shown on LEDs.
5. Counter resets automatically after 15.

---

## Project Structure

```
binary-counter-interrupt-avr/
│
├── main.c        # Embedded C source code
├── README.md     # Project documentation
```

---

## Expected Output

| Button Press | LED Output    |
| ------------ | ------------- |
| 1            | 0001          |
| 2            | 0010          |
| 3            | 0011          |
| ...          | ...           |
| 15           | 1111          |
| Next         | Reset to 0000 |

---

## Learning Outcomes

* Interrupt Programming in AVR
* Pin Change Interrupt (PCINT)
* Binary Counting Logic
* Button Debouncing Technique
* Embedded System Event Handling

---

##

---

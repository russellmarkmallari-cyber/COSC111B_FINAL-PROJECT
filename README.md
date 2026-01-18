# COSC111B Final Project – Arduino Laboratory Portfolio

This repository contains a structured collection of Arduino-based laboratory activities and examinations developed for the **COSC111B** course. The project demonstrates fundamental and advanced concepts in embedded systems, including hardware interfacing, sensor integration, serial communication, and web-based control using Python and FastAPI.

---

## Project Overview

All laboratory activities and major assessments for COSC111B are consolidated in this repository. Each activity is designed to progressively build technical competence, starting from basic Arduino programming and advancing toward bi-directional communication and API-driven control systems.

### Core Topics Covered
- Arduino programming (C/C++)
- Analog and digital sensor integration
- Serial communication between Arduino and Python
- Web API interaction using FastAPI
- Embedded systems design principles

---

## Hardware Requirements

- Arduino Uno, Nano, or compatible board  
- LEDs (Red, Green, Blue)  
- Resistors (220Ω for LEDs, 10kΩ for sensors)  
- NTC Thermistor  
- Photoresistor (LDR)  
- Push buttons  
- Breadboard and jumper wires  
- USB cable for Arduino  

---

## Laboratory Activities

### Laboratory 1 – Sequential LED Control
**Folder:** `Laboratory_1/`

**Description:**  
Introduces basic Arduino programming through sequential LED control using arrays and loops.

**Concepts Covered:**
- Array-based pin management  
- `pinMode()` and `digitalWrite()`  
- Loop-driven execution  
- Delay-based timing  

**Files:**
- `Laboratory_1.ino`  
- `Laboratory#1.png`

---

### Laboratory 2 – PWM Brightness Control
**Folder:** `Laboratory_2/`

**Description:**  
Implements Pulse Width Modulation (PWM) for smooth LED brightness transitions on supported pins.

**Concepts Covered:**
- PWM using `analogWrite()`  
- Conditional logic for PWM pins  
- Brightness fading effects  

**Files:**
- `Laboratory_2.ino`  
- `Laboratory#2.png`

---

### Laboratory 3 – Fire Detection System
**Folder:** `Laboratory_3/`

**Description:**  
A dual-sensor fire detection system using temperature and light intensity measurements.

**Concepts Covered:**
- Analog sensor reading  
- Steinhart–Hart temperature calculation  
- Multi-condition logic  
- Modular programming  

**Files:**
- `Laboratory_4.ino`  
- `Laboratory#3.png`

---

### Laboratory 4 – Light Threshold Alert System
**Folder:** `Laboratory_4/`

**Description:**  
A light-triggered alert system with Serial command control.

**Concepts Covered:**
- Serial communication  
- Command parsing  
- Boolean state control  

**Files:**
- `Laboratory_4.ino`  
- `Laboratory_4.png`

---

### Laboratory 5 – Serial LED Controller
**Folder:** `Laboratory_5/`

**Description:**  
Interactive LED control via Arduino Serial Monitor and a Python terminal interface.

**Concepts Covered:**
- Header file creation  
- Serial command parsing  
- Python–Arduino communication using `pyserial`  

**Files:**
- `Laboratory_5.ino`  
- `Laboratory_5.py`  
- `ledheader.h`  
- `Laboratory_5.png`

---

### Laboratory 6 – Bi-Directional Serial Communication
**Folder:** `Laboratory_6/`

**Description:**  
Demonstrates full-duplex communication where Arduino buttons and Python commands control LEDs.

**Concepts Covered:**
- Two-way Serial communication  
- Button input handling  
- Python Serial listeners  

**Files:**
- `Laboratory_6.ino`  
- `Laboratory_6.py`  
- `ledheader.h`  
- `Laboratory_6.png`

---

### Laboratory 7 – FastAPI Web-Controlled LEDs
**Folder:** `Laboratory_7/`

**Description:**  
Web-based LED control using FastAPI and Serial communication with Arduino.

**Concepts Covered:**
- RESTful API design  
- HTTP GET endpoints  
- Arduino integration with web services  

**Files:**
- `Laboratory_7.ino`  
- `Laboratory_7.py`  
- `ledheader.h`  
- `Laboratory_7.png`

---

## Laboratory Examinations

### Midterm Examination – Adaptive Light Sensor System
**Folder:** `LabExam_Midterms/`

**Description:**  
An advanced light-monitoring system with automatic and manual modes and adjustable thresholds.

**Files:**
- `LabExam_Midterms.ino`

---

### Final Examination – API Button Integration
**Folder:** `LabExam_Finals/`

**Description:**  
Integrates physical Arduino buttons with external API endpoints for remote LED control.

**Files:**
- `LabExam_Finals.ino`  
- `LabExam_Finals.py`

---

## Notes

- Update the COM port in Python scripts to match your system configuration.
- Ensure all required Python libraries (e.g., `pyserial`, `fastapi`) are installed before running scripts.
  
SERIAL_PORT = "COM5"              # Your Arduino COM port

API_BASE_URL = "BASE_API"         # Your API server URL

GROUP_NUMBER = "1"                # Button-to-group mapping



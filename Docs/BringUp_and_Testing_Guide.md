# Bring-Up and Testing Guide

## Overview

This document defines the recommended validation procedure for the first assembled SolarCore-4S MPPT Power Management System PCB.

The objective is to verify hardware functionality safely while minimizing the risk of component damage during initial power-up.

---

## Required Equipment

### Essential

* Digital Multimeter
* Adjustable Bench Power Supply
* ST-Link Programmer
* USB Type-C Cable

### Recommended

* Oscilloscope
* Electronic Load
* Logic Analyzer
* Thermal Camera

---

## Stage 1 – Visual Inspection

Verify:

* Component placement
* Component orientation
* Solder joints
* Connector orientation
* Missing components
* Solder bridges

### Pass Criteria

* No visible assembly defects
* No damaged components
* No solder bridges

---

## Stage 2 – Continuity Testing

Check for shorts between:

* B+ and B-
* PV+ and PV-
* V12_SYS and GND
* V5_SYS and GND
* 3V3_SYS and GND

### Pass Criteria

* No short circuits detected

---

## Stage 3 – Power Rail Verification

Apply power using a current-limited bench supply.

### Verify Rails

| Rail    | Expected Value |
| ------- | -------------- |
| V12_SYS | ~12V           |
| V5_SYS  | ~5V            |
| 3V3_SYS | ~3.3V          |

### Pass Criteria

* All rails present
* No excessive current draw
* No overheating

---

## Stage 4 – STM32 Bring-Up

Verify:

* ST-Link connection
* MCU detection
* Firmware programming
* Stable operation

### Pins

| Signal | STM32 Pin |
| ------ | --------- |
| SWDIO  | PA13      |
| SWCLK  | PA14      |

### Pass Criteria

* STM32 detected successfully
* Firmware upload successful

---

## Stage 5 – USB-C Debug Interface

Verify:

* CP2102N detection
* UART communication
* Serial terminal operation

### Pins

| Signal   | STM32 Pin |
| -------- | --------- |
| UART1_TX | PA9       |
| UART1_RX | PA10      |

### Pass Criteria

* Reliable serial communication

---

## Stage 6 – User Interface Verification

### LEDs

Verify operation of:

* BAT_LEVEL1
* BAT_LEVEL2
* BAT_LEVEL3
* BAT_LEVEL4
* BAT_LEVEL5

### Buzzer

Verify:

* Startup indication
* Test tone generation

### Pass Criteria

* All indicators functional

---

## Stage 7 – BQ76920 Verification

Verify:

* Device power
* Communication
* ALERT functionality

### Signal

| Signal    | STM32 Pin |
| --------- | --------- |
| BMS_ALERT | PA0       |

### Pass Criteria

* BQ76920 responds correctly
* ALERT line functional

---

## Stage 8 – Analog Measurement Verification

### Voltage Measurement

Verify:

| Signal  | STM32 Pin |
| ------- | --------- |
| FB_NODE | PA4       |

Compare ADC readings against a multimeter.

### Current Measurement

Verify:

| Signal            | STM32 Pin |
| ----------------- | --------- |
| CURRENT_SENSE_OUT | PA5       |

Compare ADC readings against measured current.

### Pass Criteria

* Measurements within expected tolerance

---

## Stage 9 – Expansion Interface Verification

### I²C Header

| Signal | STM32 Pin |
| ------ | --------- |
| SDA    | PB6       |
| SCL    | PB5       |

### UART3 Header

| Signal   | STM32 Pin |
| -------- | --------- |
| UART3_TX | PB10      |
| UART3_RX | PB11      |

### Pass Criteria

* Communication interfaces functional

---

## Stage 10 – Protection Verification

Verify:

* Battery disconnect detection
* Undervoltage response
* Overvoltage response
* Overcurrent response

### Pass Criteria

* Protection mechanisms operate correctly

---

## Future Validation

### MPPT System

Reserved Resource:

| Signal           | STM32 Pin |
| ---------------- | --------- |
| PV Voltage Sense | PA3       |

Future testing will include:

* PV voltage acquisition
* MPPT control validation
* Power tracking verification

---

## Final Acceptance Checklist

### Hardware

* [ ] Visual inspection passed
* [ ] No shorts detected
* [ ] Power rails verified
* [ ] STM32 operational
* [ ] BQ76920 operational

### Interfaces

* [ ] USB-C verified
* [ ] UART1 verified
* [ ] UART3 verified
* [ ] I²C verified

### User Interface

* [ ] LEDs verified
* [ ] Buzzer verified

### Measurements

* [ ] Voltage sensing verified
* [ ] Current sensing verified

### Protection

* [ ] Undervoltage protection verified
* [ ] Overvoltage protection verified
* [ ] Overcurrent protection verified

---

## Revision Information

Document Version: 1.0

Board Revision: Rev A

Project: SolarCore-4S MPPT Power Management System

Author: Yukesh S

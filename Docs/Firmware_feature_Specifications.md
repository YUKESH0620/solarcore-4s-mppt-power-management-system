# Firmware Feature Specification

## Overview

This document defines the firmware architecture, software modules, operating modes, and future capabilities of the SolarCore-4S MPPT Power Management System.

The firmware is intended to run on the STM32F103C8T6 microcontroller and provide:

- Battery monitoring
- BMS supervision
- Fault management
- User interface control
- Communication services
- Future MPPT implementation
- Expansion module support

---

# MCU Information

| Parameter | Value |
|------------|------------|
| MCU | STM32F103C8T6 |
| Core | ARM Cortex-M3 |
| Clock | 72 MHz |
| IDE | STM32CubeIDE |
| Language | C |
| HAL | STM32 HAL Drivers |

---

# Firmware Architecture

The firmware shall be organized into independent modules.

```text
Application Layer
│
├── System Manager
├── Battery Manager
├── MPPT Controller
├── Fault Manager
├── User Interface Manager
├── Communication Manager
├── Output Manager
└── Data Logger
│
Hardware Abstraction Layer
│
STM32 Peripherals
```

---

# System Manager

## Purpose

Central firmware coordinator.

### Responsibilities

- System initialization
- State management
- Scheduler execution
- Module coordination
- Startup sequence
- Shutdown sequence

### Startup Tasks

1. Configure clocks
2. Initialize GPIO
3. Initialize ADC
4. Initialize UART
5. Initialize I²C
6. Initialize timers
7. Initialize indicators
8. Verify BMS communication
9. Enter operational state

---

# Battery Manager

## Purpose

Monitor battery condition.

### Inputs

| Signal | STM32 Pin |
|----------|----------|
| BMS_ALERT | PA0 |
| FB_NODE | PA4 |
| CURRENT_SENSE | PA5 |

### Responsibilities

- Battery voltage estimation
- State of charge estimation
- Charge state determination
- Discharge monitoring
- Protection coordination

### Future Features

- Coulomb counting
- Battery health estimation
- Cycle counting
- Runtime prediction

---

# MPPT Controller

## Status

Planned

---

## Purpose

Maximize solar energy extraction.

### PWM Output

| Signal | STM32 Pin |
|----------|----------|
| PWM_OUT | PA8 |

### Future Inputs

| Signal | STM32 Pin |
|----------|----------|
| PV Voltage Sense | PA3 |
| Current Sense | PA5 |

### Planned Algorithm

Perturb and Observe (P&O)

---

## Workflow

```text
Measure Voltage
Measure Current
Calculate Power
Adjust Duty Cycle
Measure Again
Repeat
```

---

## Future Enhancements

- Incremental Conductance
- Adaptive Step Size
- Temperature Compensation
- Hybrid MPPT Algorithms

---

# Fault Manager

## Purpose

Detect and respond to abnormal conditions.

### Monitored Sources

- BQ76920
- Current Sensor
- Voltage Measurements
- Communication Interfaces
- Watchdog

### Fault Categories

| Category | Description |
|-----------|-----------|
| Battery | Cell faults |
| Current | Overcurrent |
| Voltage | Overvoltage |
| Communication | Interface faults |
| Firmware | Internal faults |

---

## Fault Responses

| Severity | Action |
|-----------|-----------|
| INFO | Log Event |
| WARNING | User Notification |
| MAJOR | Disable Function |
| CRITICAL | Emergency Shutdown |

---

# User Interface Manager

## Purpose

Manage LEDs and buzzer.

---

## Battery LEDs

| Pin | Function |
|---------|---------|
| PB0 | BAT_LEVEL1 |
| PB1 | BAT_LEVEL2 |
| PB2 | BAT_LEVEL3 |
| PB3 | BAT_LEVEL4 |
| PB4 | BAT_LEVEL5 |

Functions:

- Battery level display
- Charging animation
- Fault indication
- Startup diagnostics

---

## Buzzer

| Pin | Function |
|---------|---------|
| PB7 | BUZ_CTRL |

Functions:

- Startup beep
- Fault alerts
- Low battery warnings
- Charge completion indication

---

## User Button

| Pin | Function |
|---------|---------|
| PA1 | USER_BUTTON |

Potential Actions:

- Wake system
- Show battery level
- Toggle display pages
- Enter diagnostics mode

---

# OLED Display Manager

## Status

Future Expansion

### Interface

| Signal | STM32 Pin |
|---------|---------|
| SDA | PB6 |
| SCL | PB5 |

---

## Planned Display Pages

### Page 1

Battery Information

```text
Voltage
Percentage
Status
```

### Page 2

Solar Information

```text
PV Voltage
PV Current
PV Power
```

### Page 3

System Status

```text
Faults
Outputs
Communication
```

---

# Communication Manager

## UART1

### Purpose

Debug Interface

| Signal | Pin |
|----------|----------|
| TX | PA9 |
| RX | PA10 |

Applications:

- Debug logging
- Diagnostics
- Firmware development

---

## UART3

### Purpose

Expansion Interface

| Signal | Pin |
|----------|----------|
| TX | PB10 |
| RX | PB11 |

Applications:

- ESP32
- Bluetooth
- LoRa
- GSM
- Telemetry

---

# ESP32 Telemetry Manager

## Status

Future Expansion

Potential Features:

- Web Dashboard
- MQTT
- WiFi Monitoring
- OTA Updates
- Mobile App Support
- Cloud Integration

---

# CAN Communication

## Status

Reserved

| Signal | Pin |
|----------|----------|
| CAN_TX | PA11 |
| CAN_RX | PA12 |

Potential Applications:

- Industrial Systems
- Vehicle Networks
- Distributed Power Systems

---

# Output Manager

## Purpose

Manage system outputs.

Responsibilities:

- Output enable
- Output disable
- Load monitoring
- Protection coordination

Future Features:

- Smart load control
- Priority load management
- Emergency shutdown

---

# Data Logger

## Status

Future Expansion

Potential Logged Parameters:

- Battery voltage
- Current measurements
- Fault events
- Charge cycles
- Runtime statistics

Storage Options:

- Internal Flash
- External EEPROM
- SD Card

---

# Watchdog Manager

## Purpose

Recover from firmware failures.

Functions:

- Detect lockups
- Force restart
- Maintain system reliability

---

# Operating States

## Startup

```text
Power Applied
Initialize Hardware
Run Diagnostics
Enter Ready State
```

---

## Idle

```text
Monitoring Active
Charging Disabled
```

---

## Charging

```text
Battery Charging Active
Monitoring Active
```

---

## Fault

```text
Protection Triggered
User Alerted
Recovery Required
```

---

## Shutdown

```text
Outputs Disabled
Low Power State
```

---

# Future Firmware Roadmap

## Revision B

- PV Voltage Measurement
- Basic MPPT

## Revision C

- OLED Dashboard
- ESP32 Telemetry

## Revision D

- Data Logging
- CAN Support

## Revision E

- Advanced MPPT
- Cloud Monitoring

---

# Firmware Development Priority

| Priority | Feature |
|-----------|-----------|
| 1 | Hardware Bring-Up |
| 2 | ADC Acquisition |
| 3 | BMS Monitoring |
| 4 | LED Indicators |
| 5 | Buzzer Control |
| 6 | Fault Handling |
| 7 | UART Debug |
| 8 | MPPT Implementation |
| 9 | OLED Support |
| 10 | ESP32 Telemetry |

---

# Revision Information

Document Version: 1.0

Applicable Hardware Revision: Rev A

Board:

SolarCore-4S MPPT Power Management System

Author:

Yukesh S
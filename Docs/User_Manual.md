# User Manual

## SolarCore-4S MPPT Power Management System

Version: Rev A

---

## 1. Introduction

The SolarCore-4S MPPT Power Management System is an embedded energy harvesting and battery management platform designed around the STM32F103C8T6 microcontroller and BQ76920 battery monitoring IC.

The platform combines:

- Solar energy harvesting
- Future MPPT control capability
- 4S LiFePO4 battery management
- Charge and discharge protection
- Power distribution
- USB-C debugging
- OLED expansion support
- ESP32 expansion support

This document describes hardware operation, connectors, indicators, and system usage.

---

## 2. Safety Information

Before using the board:

- Verify battery polarity.
- Verify solar panel polarity.
- Never short battery terminals.
- Never exceed battery voltage limits.
- Verify all wiring before applying power.
- Use appropriate fuses where required.
- Disconnect power before modifying connections.

---

## 3. Supported Battery Configuration

| Parameter | Value |
|------------|------------|
| Battery Type | LiFePO4 |
| Configuration | 4S |
| Nominal Voltage | 12.8V |
| Maximum Voltage | 14.6V |
| Monitoring IC | BQ76920 |

---

## 4. System Overview

The board contains the following major subsystems:

1. STM32 Control System
2. Battery Management System
3. Charge Protection
4. Discharge Protection
5. Power Distribution
6. USB-C Programming Interface
7. User Interface Indicators
8. Expansion Interfaces

---

## 5. Power-Up Sequence

Recommended startup sequence:

1. Connect battery pack.
2. Verify battery LEDs illuminate.
3. Verify power LED operation.
4. Connect solar panel input.
5. Verify charging indication.
6. Connect external loads if required.

---

## 6. Battery Connection

### Battery Connector

Connect:

```text
B+
B1
B2
B3
B-
```

according to the battery pack cell order.

Incorrect balance wiring may trigger BMS protection or damage monitoring circuitry.

Before connection:

- Measure cell voltages.
- Verify wiring sequence.
- Verify connector orientation.

---

## 7. Solar Input Connection

Connect photovoltaic input to:

```text
PV+
PV-
```

Recommended checks:

- Verify polarity.
- Verify open-circuit voltage.
- Verify connector integrity.

Current hardware revision does not directly measure PV voltage.

Future revisions may use the reserved PV sensing input on PA3 together with an external voltage divider interface.

---

## 8. Output Connections

The board provides regulated system power rails.

### Available Rails

| Rail | Purpose |
|--------|--------|
| SYS_VBAT | Battery Output |
| V12_SYS | 12V Distribution |
| V5_SYS | 5V Distribution |
| 3V3_SYS | Logic Supply |
| VBOOST_OUT | Boost Converter Output |

These rails may be used to power external electronics and future expansion modules.

---

## 9. USB-C Programming Interface

The board includes a USB Type-C interface connected to a CP2102N USB-UART bridge.

Functions:

- Firmware upload
- Serial debugging
- Diagnostic logging
- Development support

### UART Mapping

| Signal | STM32 Pin |
|----------|----------|
| UART1_TX | PA9 |
| UART1_RX | PA10 |

---

## 10. OLED Expansion Header

An I²C expansion header is available for OLED displays and other peripherals.

### STM32 Connections

| Signal | Pin |
|----------|----------|
| SDA | PB6 |
| SCL | PB5 |

### Supported Future Features

- Battery voltage display
- Battery percentage
- Fault codes
- Charging status
- Output status
- System diagnostics

Recommended Display:

SSD1306 OLED

---

## 11. ESP32 Expansion Header

UART3 is reserved for wireless expansion.

### STM32 Connections

| Signal | Pin |
|----------|----------|
| UART3_TX | PB10 |
| UART3_RX | PB11 |

Potential applications:

- WiFi monitoring
- MQTT
- Cloud connectivity
- Mobile applications
- Remote telemetry
- Home Assistant integration

---

## 12. User Button

### STM32 Pin

```text
PA1
```

Potential firmware functions:

- Wake-up
- Menu navigation
- Status display
- Diagnostics mode
- Factory reset

Actual behavior depends on firmware implementation.

---

## 13. Battery Level LEDs

### STM32 Pins

| LED | Pin |
|--------|--------|
| BAT_LEVEL1 | PB0 |
| BAT_LEVEL2 | PB1 |
| BAT_LEVEL3 | PB2 |
| BAT_LEVEL4 | PB3 |
| BAT_LEVEL5 | PB4 |

Normal operation:

| Battery Level | LEDs |
|---------------|------|
| 0–20% | LED1 |
| 20–40% | LED1–LED2 |
| 40–60% | LED1–LED3 |
| 60–80% | LED1–LED4 |
| 80–100% | LED1–LED5 |

---

## 14. Buzzer

### STM32 Pin

```text
PB7
```

The buzzer is fully firmware-controlled.

Recommended indications:

| Event | Pattern |
|---------|---------|
| Startup | Single Beep |
| Charging Started | Double Beep |
| Charge Complete | Triple Beep |
| Low Battery | Periodic Beep |
| BMS Fault | Long Tone |

The buzzer frequency and patterns may be modified through firmware.

---

## 15. BMS Monitoring

The BQ76920 monitors:

- Cell Voltage
- Overvoltage
- Undervoltage
- Charge Overcurrent
- Discharge Overcurrent

### Alert Line

| Signal | STM32 Pin |
|----------|----------|
| BMS_ALERT | PA0 |

The MCU uses this signal to detect protection events.

---

## 16. Future Expansion Features

Reserved MCU resources enable future capabilities:

- CAN Communication
- RS485
- Temperature Monitoring
- Fan Control
- Data Logging
- Smart Load Control
- Wireless Connectivity
- Advanced MPPT Algorithms

---

## 17. Known Revision-A Limitation

### PV Voltage Measurement

Revision A does not directly acquire photovoltaic panel voltage.

Reserved resource:

| STM32 Pin |
|----------|
| PA3 |

Future revisions may use:

- External resistor divider
- Dedicated sensing connector
- True MPPT voltage tracking

This limitation does not affect battery management operation.

---

## 18. Troubleshooting

| Symptom | Possible Cause |
|------------|------------|
| No LEDs | No battery connection |
| BMS Fault LED Active | Battery protection event |
| No Charging | Solar input unavailable |
| No UART Communication | USB driver issue |
| Battery Not Detected | Wiring issue |
| Continuous Buzzer | Fault condition |

Refer to:

```text
Fault_Analysis_Guide.md
```

for detailed diagnostics.

---

## 19. Related Documentation

- STM32_Pin_Assignment.md
- LED_and_Buzzer_Behavior.md
- Fault_Analysis_Guide.md
- Hardware_Features.md
- Firmware_Feature_Specification.md
- Future_Expansion_Guide.md

---

## Revision Information

Document Version: 1.0

Board Revision: Rev A

Project:

SolarCore-4S MPPT Power Management System

Author:

Yukesh S
# STM32F103C8T6 Pin Assignment

## Overview

The SolarCore-4S MPPT Power Management System uses an STM32F103C8T6 microcontroller as the central system controller. The MCU is responsible for battery monitoring, fault handling, future MPPT control implementation, user interface management, communication interfaces, and system supervision.

This document defines the official pin assignment for Hardware Revision A.

---

# MCU Information

| Parameter | Value |
|------------|------------|
| MCU | STM32F103C8T6 |
| Architecture | ARM Cortex-M3 |
| Flash Memory | 64 KB |
| SRAM | 20 KB |
| Operating Voltage | 3.3V |
| Debug Interface | SWD |
| Firmware Toolchain | STM32CubeIDE |

---

# Pin Assignment Table

| Pin | Function | Module |
|------|------|------|
| PA0 | BMS_ALERT | BQ76920 |
| PA1 | USER_BUTTON | User Input |
| PA2 | Reserved | Future Expansion |
| PA3 | Reserved (Future PV Voltage Sense) | MPPT Rev-B |
| PA4 | FB_NODE Voltage Sense | ADC1_IN4 |
| PA5 | Current Sense (INA180 Output) | ADC1_IN5 |
| PA6 | Reserved | Future Expansion |
| PA7 | Reserved | Future Expansion |
| PA8 | PWM_OUT | TIM1_CH1 → IR2104 |
| PA9 | UART1_TX | CP2102N |
| PA10 | UART1_RX | CP2102N |
| PA11 | CAN_TX (Unused) | Future |
| PA12 | CAN_RX (Unused) | Future |
| PA13 | SWDIO | Programming |
| PA14 | SWCLK | Programming |
| PA15 | Unused | Reserved |
| PB0 | BAT_LEVEL1 | Battery LED 1 |
| PB1 | BAT_LEVEL2 | Battery LED 2 |
| PB2 | BAT_LEVEL3 | Battery LED 3 |
| PB3 | BAT_LEVEL4 | Battery LED 4 |
| PB4 | BAT_LEVEL5 | Battery LED 5 |
| PB5 | I2C_SCL | OLED / Expansion |
| PB6 | I2C_SDA | OLED / Expansion |
| PB7 | BUZ_CTRL | Buzzer Output |
| PB8 | Reserved | Future Expansion |
| PB9 | Reserved | Future Expansion |
| PB10 | UART3_TX | ESP32 Expansion |
| PB11 | UART3_RX | ESP32 Expansion |
| PB12 | Reserved | Future Expansion |
| PB13 | Reserved | Future Expansion |
| PB14 | Reserved | Future Expansion |
| PB15 | Reserved | Future Expansion |

---

# Functional Grouping

## Analog Inputs

### PA4 — FB_NODE Voltage Sense

Purpose:

- Battery charge node monitoring
- Voltage feedback acquisition
- MPPT feedback path
- ADC measurements

Peripheral:

ADC1_IN4

---

### PA5 — Current Sense Input

Purpose:

- INA180 current monitor output
- Charging current measurement
- Power estimation
- Future MPPT calculations

Peripheral:

ADC1_IN5

---

### PA3 — Reserved PV Voltage Input

Purpose:

Future photovoltaic voltage sensing.

Revision A PCB does not directly monitor PV panel voltage.

A dedicated external sensing interface is planned for future hardware revisions.

Planned Applications:

- True MPPT implementation
- Solar panel power calculation
- Panel operating point tracking
- Advanced energy harvesting algorithms

Peripheral:

ADC1_IN3

Status:

Reserved

---

# PWM Outputs

## PA8 — MPPT PWM Control

Signal:

PWM_OUT

Peripheral:

TIM1_CH1

Connected Device:

IR2104 Gate Driver

Purpose:

- Buck converter control
- MPPT duty cycle control
- Power regulation
- Future closed-loop energy harvesting

Status:

Reserved for future firmware implementation.

---

# Communication Interfaces

## UART1

Used for debugging and firmware development.

| Pin | Function |
|------|------|
| PA9 | UART1_TX |
| PA10 | UART1_RX |

Connected Device:

CP2102N USB-UART Bridge

Applications:

- Serial terminal
- Debug messages
- Firmware diagnostics
- Development support

---

## UART3

Reserved for future wireless and communication expansion.

| Pin | Function |
|------|------|
| PB10 | UART3_TX |
| PB11 | UART3_RX |

Applications:

- ESP32 Integration
- ESP32-S3 Integration
- Bluetooth Modules
- LoRa Communication
- GSM Modems
- Telemetry Systems
- IoT Gateways

---

## I²C Interface

Dedicated expansion bus.

| Pin | Function |
|------|------|
| PB5 | I2C_SCL |
| PB6 | I2C_SDA |

Applications:

- OLED Displays
- Environmental Sensors
- RTC Modules
- External EEPROM
- ADC Expansion
- Digital Sensors

---

# User Interface Resources

## Battery Level Indicators

Five independent battery level LEDs are provided.

| Pin | LED |
|------|------|
| PB0 | BAT_LEVEL1 |
| PB1 | BAT_LEVEL2 |
| PB2 | BAT_LEVEL3 |
| PB3 | BAT_LEVEL4 |
| PB4 | BAT_LEVEL5 |

Potential Functions:

- Battery percentage display
- Charging animation
- Diagnostic display
- Fault indication
- Startup sequence

---

## User Button

Pin:

PA1

Purpose:

General-purpose user interaction.

Possible Functions:

- Wake-up
- Status display request
- Mode selection
- Factory reset
- Firmware menu navigation

---

## Buzzer

Pin:

PB7

Signal:

BUZ_CTRL

Purpose:

Audible user feedback.

Possible Firmware Functions:

- Startup notification
- Low battery warning
- Charging complete indication
- Fault alerts
- Diagnostic feedback

Since the buzzer is GPIO-controlled, firmware can generate custom frequencies and notification patterns.

---

# Debug Interface

## SWD Programming

| Pin | Function |
|------|------|
| PA13 | SWDIO |
| PA14 | SWCLK |

Applications:

- Firmware upload
- Breakpoint debugging
- Flash programming
- System diagnostics

Supported Tools:

- ST-Link V2
- ST-Link V3
- STM32CubeIDE

---

# Future Expansion Resources

The following pins are intentionally reserved for future platform growth:

| Pin |
|------|
| PA2 |
| PA6 |
| PA7 |
| PA11 |
| PA12 |
| PA15 |
| PB8 |
| PB9 |
| PB12 |
| PB13 |
| PB14 |
| PB15 |

Potential Future Features:

- CAN Bus
- RS485
- Fan Control
- Temperature Sensors
- Relay Outputs
- Data Logging
- Smart Load Control
- Industrial Communication
- Wireless Connectivity

---

# GPIO Resource Summary

| Category | Count |
|-----------|--------|
| Analog Inputs | 3 |
| PWM Outputs | 1 |
| UART Interfaces | 2 |
| I²C Interfaces | 1 |
| User Buttons | 1 |
| LED Outputs | 5 |
| Buzzer Outputs | 1 |
| SWD Debug Interface | 1 |
| Reserved Expansion Pins | 12 |

---

# Revision Information

Document Version: 1.0

Applicable Hardware Revision: Rev A

Board:

SolarCore-4S MPPT Power Management System

Author:

Yukesh S
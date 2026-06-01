# Hardware Architecture

## Overview

The SolarCore-4S MPPT Power Management System is a modular embedded energy harvesting and battery management platform designed around an STM32F103C8T6 microcontroller and a BQ76920 battery monitoring system.

The architecture combines:

- Solar Energy Harvesting
- Battery Charging
- Battery Protection
- Embedded Monitoring
- Power Distribution
- Expansion Interfaces
- Future MPPT Capability

The platform is organized into multiple independent hardware subsystems to improve maintainability, scalability, and future development.

---

# System Block Diagram

```text
                    ┌─────────────────┐
                    │   Solar Input   │
                    └────────┬────────┘
                             │
                             ▼
                  ┌────────────────────┐
                  │ Input Protection   │
                  └────────┬───────────┘
                           │
                           ▼
               ┌─────────────────────────┐
               │ Charging Power Stage    │
               └──────────┬──────────────┘
                          │
                          ▼
               ┌─────────────────────────┐
               │ 4S LiFePO4 Battery Pack │
               └──────────┬──────────────┘
                          │
          ┌───────────────┼───────────────┐
          │                               │
          ▼                               ▼
 ┌─────────────────┐          ┌─────────────────┐
 │ BQ76920 BMS     │          │ Protection Stage│
 └────────┬────────┘          └────────┬────────┘
          │                             │
          ▼                             ▼
 ┌────────────────────────────────────────────┐
 │ Power Distribution and Output Management   │
 └───────────────────┬────────────────────────┘
                     │
                     ▼
         ┌──────────────────────────┐
         │ Regulated Power Outputs  │
         └──────────────────────────┘

                     ▲
                     │
          ┌──────────┴──────────┐
          │ STM32F103C8T6 MCU   │
          └─────────────────────┘
```

---

# Hardware Subsystems

The design is divided into seven major hardware subsystems.

| Sheet | Subsystem |
|---------|---------|
| Sheet 1 | System Architecture |
| Sheet 2 | STM32 Controller and Monitoring |
| Sheet 3 | Battery Management System |
| Sheet 4 | Charge and Discharge Protection |
| Sheet 5 | Output Connectors and Protection |
| Sheet 6 | Power Distribution |
| Sheet 7 | USB-C Debug Interface |

---

# 1. System Architecture

## Purpose

Acts as the top-level integration sheet and defines how all hardware blocks interact.

### Responsibilities

- System connectivity
- Power flow definition
- Signal flow organization
- Hierarchical schematic management

### Major Interfaces

- Solar Input
- Battery Pack
- BMS
- STM32 Controller
- Power Distribution
- Debug Interface

### Design Objective

Provide a clean separation between:

- Power Electronics
- Battery Management
- Embedded Control
- User Interfaces

---

# 2. STM32 Controller and Monitoring System

## Purpose

The STM32F103C8T6 serves as the central controller for the entire platform.

### Responsibilities

- Battery monitoring
- Fault management
- ADC acquisition
- User interface control
- Communication handling
- Future MPPT control

---

## Analog Monitoring

### Battery Voltage

Pin:

```text
PA4
```

Signal:

```text
FB_NODE
```

Purpose:

- Battery voltage measurement
- Charge monitoring
- System diagnostics

---

### Current Measurement

Pin:

```text
PA5
```

Signal:

```text
CURRENT_SENSE_OUT
```

Purpose:

- Charge current monitoring
- Future MPPT calculations
- Power estimation

---

## BMS Alert Monitoring

Pin:

```text
PA0
```

Signal:

```text
BMS_ALERT
```

Purpose:

Immediate notification of battery protection events.

---

## User Interface

Connected Devices:

- Battery LEDs
- Status LEDs
- Buzzer
- User Button

---

## Communication Interfaces

### UART1

Connected to:

```text
CP2102N
```

Purpose:

- Debugging
- Firmware upload
- Serial diagnostics

---

### UART3

Reserved for:

- ESP32
- Telemetry
- Future wireless communication

---

### I²C

Reserved for:

- OLED display
- External sensors
- Expansion peripherals

---

# 3. Battery Management System

## Purpose

Provide hardware-level battery monitoring and protection.

---

## Main Component

```text
BQ76920
```

---

## Functions

- Cell monitoring
- Overvoltage protection
- Undervoltage protection
- Charge overcurrent protection
- Discharge overcurrent protection

---

## Battery Configuration

| Parameter | Value |
|------------|------------|
| Chemistry | LiFePO4 |
| Configuration | 4S |
| Nominal Voltage | 12.8V |
| Maximum Voltage | 14.6V |

---

## BMS Communication

The BQ76920 reports fault conditions through:

```text
BMS_ALERT
```

connected to:

```text
PA0
```

---

# 4. Charge and Discharge Protection Stage

## Purpose

Provide safe control of battery charging and battery discharge.

---

## Main Components

```text
AO4407A MOSFETs
```

---

## Functions

- Charge path control
- Discharge path control
- Reverse current protection
- Battery isolation

---

## Protection Events

The subsystem responds to:

- Overvoltage
- Undervoltage
- Overcurrent
- Short circuit conditions

---

# 5. Output Connectors and Protection

## Purpose

Provide protected access to system power rails.

---

## Features

- Output connectors
- Reverse protection
- Load connection interface
- Expansion support

---

## Design Goals

- Safe load connection
- Simplified external integration
- Future expansion capability

---

# 6. Power Distribution System

## Purpose

Generate and distribute power throughout the platform.

---

## Available Rails

| Rail | Purpose |
|--------|--------|
| SYS_VBAT | Battery Rail |
| V12_SYS | System Power |
| V5_SYS | Logic and Expansion |
| 3V3_SYS | MCU Supply |
| VBOOST_OUT | Boost Output |

---

## Design Objectives

- Stable voltage distribution
- Low impedance power delivery
- Future peripheral support

---

## Power Consumers

- STM32
- BQ76920
- CP2102N
- Expansion Interfaces
- External Peripherals

---

# 7. USB-C Debug and Programming Interface

## Purpose

Provide firmware development and debugging access.

---

## Main Components

```text
USB Type-C Connector
CP2102N
```

---

## Features

- Serial communication
- Firmware development
- Debug logging
- Programming support

---

## MCU Connection

| Signal | STM32 Pin |
|----------|----------|
| UART_TX | PA9 |
| UART_RX | PA10 |

---

# User Interface Architecture

## Battery LEDs

| Pin | Function |
|------|------|
| PB0 | BAT_LEVEL1 |
| PB1 | BAT_LEVEL2 |
| PB2 | BAT_LEVEL3 |
| PB3 | BAT_LEVEL4 |
| PB4 | BAT_LEVEL5 |

Purpose:

Battery capacity indication.

---

## Buzzer

Pin:

```text
PB7
```

Purpose:

Audible user notifications.

---

## User Button

Pin:

```text
PA1
```

Purpose:

Future user interaction.

---

# Expansion Architecture

The design intentionally reserves resources for future functionality.

---

## OLED Interface

| Signal | STM32 Pin |
|----------|----------|
| SDA | PB6 |
| SCL | PB5 |

Potential Features:

- Battery Dashboard
- Charging Status
- Fault Information

---

## ESP32 Interface

| Signal | STM32 Pin |
|----------|----------|
| TX | PB10 |
| RX | PB11 |

Potential Features:

- WiFi
- MQTT
- Remote Monitoring

---

## CAN Interface

Reserved Pins:

| Signal | STM32 Pin |
|----------|----------|
| CAN_TX | PA11 |
| CAN_RX | PA12 |

Future Applications:

- Industrial Networks
- Distributed Power Systems
- Vehicle Integration

---

# Future MPPT Architecture

## Reserved Resource

Pin:

```text
PA3
```

Purpose:

Future photovoltaic voltage sensing.

---

## Planned Measurements

- PV Voltage
- PV Current
- PV Power

---

## Planned Algorithms

- Perturb and Observe
- Incremental Conductance

---

# Design Philosophy

The SolarCore-4S MPPT Power Management System was designed as a modular embedded energy platform rather than a single-purpose charger.

The architecture prioritizes:

- Safety
- Expandability
- Maintainability
- Firmware Flexibility
- Professional PCB Design Practices

The hardware foundation supports future development in:

- MPPT Control
- Wireless Monitoring
- Data Logging
- Industrial Communication
- Advanced Battery Analytics

---

## Revision Information

Document Version: 1.0

Board Revision: Rev A

Project:

SolarCore-4S MPPT Power Management System

Author:

Yukesh S
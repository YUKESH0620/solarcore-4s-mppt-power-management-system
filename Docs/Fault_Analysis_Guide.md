# Fault Analysis Guide

## Overview

This document describes the potential fault conditions that may occur within the SolarCore-4S MPPT Power Management System and provides guidance for detection, diagnosis, user notification, and corrective actions.

The fault management architecture combines:

- BQ76920 Battery Protection
- STM32 Monitoring Firmware
- Current Sensing
- Voltage Monitoring
- LED Indicators
- Audible Alerts

---

# Fault Classification

Faults are categorized into four groups:

| Category | Description |
|------------|------------|
| Battery Faults | Cell voltage and battery protection events |
| Charging Faults | Charge path abnormalities |
| System Faults | Internal hardware or firmware issues |
| Communication Faults | Interface and peripheral failures |

---

# Fault Detection Sources

| Source | Monitored Parameters |
|------------|------------|
| BQ76920 | Cell Voltages, OVP, UVP, OCP |
| INA180 | Charge Current |
| ADC Measurements | System Voltage |
| STM32 Firmware | Communication, Logic Checks |
| Future PV Sense Circuit | Solar Panel Voltage |

---

# Battery Protection Faults

## Cell Overvoltage

### Detection Source

BQ76920

### Cause

- Excessive charging voltage
- Charger malfunction
- Incorrect battery configuration

### System Response

- Disable charging MOSFET
- Assert BMS_ALERT
- Trigger fault indication

### User Indication

LED Pattern:

```text
All LEDs Blink Fast
```

Buzzer:

```text
Long Continuous Tone
```

### Corrective Action

- Disconnect charger
- Verify battery pack voltage
- Inspect charging circuitry

---

## Cell Undervoltage

### Detection Source

BQ76920

### Cause

- Deep battery discharge
- Excessive load
- Battery aging

### System Response

- Disable discharge MOSFET
- Prevent further battery drain

### User Indication

LED Pattern:

```text
LED1 Fast Blink
```

Buzzer:

```text
Short Beep Every 2 Seconds
```

### Corrective Action

- Recharge battery immediately
- Check connected loads

---

## Charge Overcurrent

### Detection Source

BQ76920

### Cause

- Excessive charging current
- Charger malfunction
- Shorted battery cell

### System Response

- Disable charging path

### User Indication

Charging LED:

```text
Fast Blink
```

Buzzer:

```text
Double Long Beep
```

### Corrective Action

- Verify charging source
- Inspect battery condition

---

## Discharge Overcurrent

### Detection Source

BQ76920

### Cause

- Load overload
- Output short circuit

### System Response

- Disable discharge path
- Protect battery

### User Indication

LED Pattern:

```text
Alternating LED Flash
```

### Corrective Action

- Remove load
- Inspect output connectors

---

# Battery Connection Faults

## Battery Missing

### Detection Source

Firmware

### Cause

- Battery disconnected
- Loose terminal connection

### System Response

- Disable charging
- Disable discharge

### User Indication

LED Pattern:

```text
LED1 and LED5 Blink
```

### Corrective Action

- Verify battery wiring
- Check connector integrity

---

## Cell Tap Wiring Fault

### Detection Source

BQ76920 Cell Voltage Monitoring

### Cause

- Incorrect battery harness wiring
- Open cell tap connection

### System Response

- Enter protection mode

### User Indication

LED Pattern:

```text
Sequential Flash Pattern
```

### Corrective Action

- Verify B1–B4 connections
- Check battery harness

---

# Charging System Faults

## Solar Input Missing

### Detection Source

Firmware Voltage Measurement

### Cause

- No solar input
- PV connector disconnected

### System Response

- Disable charging state

### User Indication

Charging LED OFF

### Corrective Action

- Verify solar panel connection
- Measure PV voltage

---

## PV Voltage Sense Not Available

### Detection Source

Firmware

### Cause

Current Revision A limitation.

### Description

The current PCB revision reserves PA3 for future photovoltaic voltage measurement but does not directly acquire PV panel voltage.

### System Impact

- Basic charging operation unaffected
- Advanced MPPT optimization unavailable

### Future Solution

Use external voltage divider connected to reserved PV sensing interface.

---

# Current Measurement Faults

## Current Sensor Failure

### Detection Source

ADC Monitoring

### Signal

PA5

### Cause

- INA180 failure
- Open sense path
- PCB damage

### System Response

- Disable MPPT algorithm
- Raise warning flag

### User Indication

LED2 + LED4 Blink

### Corrective Action

- Inspect INA180
- Verify shunt resistor

---

## Invalid Current Reading

### Detection Source

Firmware Validation

### Cause

- ADC corruption
- Sensor saturation
- Noise

### System Response

- Ignore measurement
- Raise warning

---

# Voltage Measurement Faults

## Feedback Voltage Out of Range

### Detection Source

PA4 ADC

### Cause

- Divider resistor failure
- Wiring issue
- Unexpected battery voltage

### System Response

- Disable MPPT control

### User Indication

LED1 + LED3 + LED5 Blink

---

# Communication Faults

## BQ76920 Communication Failure

### Detection Source

I²C Timeout

### Interface

PB5 (SCL)
PB6 (SDA)

### Cause

- I²C bus failure
- BQ76920 fault
- Pull-up resistor issue

### System Response

- Disable charging
- Disable discharge
- Raise critical fault

### User Indication

LED Pattern:

```text
LED1 + LED3 + LED5 Blink
```

Buzzer:

```text
Three Short Pulses
```

### Corrective Action

- Verify SDA/SCL lines
- Check BQ76920 power supply

---

## UART Communication Failure

### Detection Source

Firmware

### Interfaces

UART1
UART3

### Cause

- Disconnected peripheral
- ESP32 not responding
- USB connection lost

### System Response

- Log warning
- Continue operation

### Severity

Low

---

# MCU Faults

## Watchdog Reset

### Detection Source

Firmware

### Cause

- Software lockup
- Unexpected execution state

### System Response

- Automatic restart

### User Indication

Startup sequence repeats

### Corrective Action

- Review firmware logs

---

## Brownout Event

### Detection Source

STM32 Reset Flags

### Cause

- Supply voltage collapse
- Excessive load

### System Response

- Safe restart

### User Indication

Double startup beep

---

# Future Thermal Faults

## Overtemperature

### Status

Not Implemented in Revision A

### Reserved Expansion

PA6
PA7

### Potential Sensors

- NTC Thermistor
- Digital Temperature Sensor

### Planned Response

- Reduce charging current
- Disable outputs
- Alert user

---

# Fault Severity Levels

| Level | Description | Action |
|---------|---------|---------|
| INFO | Informational Event | Log Only |
| WARNING | Minor Issue | User Notification |
| MAJOR | System Degradation | Protective Action |
| CRITICAL | Safety Risk | Immediate Shutdown |

---

# Recommended Fault Codes

| Code | Description |
|---------|---------|
| F001 | Cell Overvoltage |
| F002 | Cell Undervoltage |
| F003 | Charge Overcurrent |
| F004 | Discharge Overcurrent |
| F005 | Battery Missing |
| F006 | Cell Tap Fault |
| F007 | Current Sensor Failure |
| F008 | Feedback Voltage Error |
| F009 | BQ76920 Communication Failure |
| F010 | Brownout Reset |
| F011 | Watchdog Reset |
| F012 | Thermal Fault (Future) |

---

# Revision Information

Document Version: 1.0

Applicable Hardware Revision: Rev A

Board:

SolarCore-4S MPPT Power Management System

Author:

Yukesh S
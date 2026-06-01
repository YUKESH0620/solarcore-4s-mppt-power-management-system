# Engineering Decisions

## Overview

This document explains the major engineering decisions made during the design of the SolarCore-4S MPPT Power Management System.

The objective was not simply to build a battery charger, but to develop a modular embedded power management platform capable of supporting future expansion, firmware development, and advanced energy harvesting algorithms.

The design philosophy focused on:

- Modularity
- Scalability
- Maintainability
- Firmware Flexibility
- Professional PCB Design Practices
- Future Expandability

---

# Why STM32F103C8T6?

## Decision

STM32F103C8T6 was selected as the primary system controller.

---

## Requirements

The controller needed to provide:

- Multiple ADC channels
- PWM generation
- UART communication
- I²C communication
- Sufficient GPIO resources
- Development tool support
- Low cost
- Strong ecosystem

---

## Advantages

### ADC Resources

The design requires monitoring:

- Battery voltage
- Current sensor output
- Future PV voltage sensing

STM32 provides sufficient ADC resources for current and future requirements.

---

### Timer Resources

The MPPT architecture requires PWM generation.

STM32 timers support:

- High-resolution PWM
- Future complementary outputs
- Duty cycle control
- Frequency control

---

### Development Ecosystem

STM32 offers:

- STM32CubeIDE
- STM32 HAL
- Extensive documentation
- Community support
- Professional industry adoption

---

### Expansion Capability

Unused GPIO resources remain available for:

- CAN
- OLED
- Wireless modules
- Temperature monitoring
- Future peripherals

---

## Conclusion

STM32F103C8T6 provides an excellent balance between cost, capability, ecosystem support, and future scalability.

---

# Why BQ76920?

## Decision

The BQ76920 was selected as the battery monitoring and protection IC.

---

## Requirements

The system required:

- Cell monitoring
- Overvoltage protection
- Undervoltage protection
- Charge overcurrent protection
- Discharge overcurrent protection
- Hardware-level safety

---

## Advantages

### Dedicated Battery Protection

Battery safety should not depend solely on firmware.

The BQ76920 provides independent hardware protection.

---

### Individual Cell Monitoring

The IC enables:

- Cell voltage monitoring
- Cell imbalance detection
- Future balancing strategies

---

### Alert Interface

The BMS_ALERT signal allows the STM32 to react quickly to battery events.

---

## Conclusion

The BQ76920 provides a reliable and industry-proven battery management solution for multi-cell lithium battery systems.

---

# Why IR2104?

## Decision

The IR2104 was selected as the gate driver for the future MPPT power stage.

---

## Requirements

The MPPT architecture requires:

- High-side MOSFET control
- Low-side MOSFET control
- Bootstrap operation
- Fast switching capability

---

## Advantages

### High-Side Drive Capability

The IR2104 simplifies high-side N-channel MOSFET control.

---

### Industry Adoption

The device is widely used in:

- Buck converters
- Motor drives
- Power supplies
- Power electronics development

---

### Simplicity

The device provides a straightforward implementation path for future MPPT firmware development.

---

## Conclusion

The IR2104 offers a practical and proven solution for driving the MPPT switching stage.

---

# Why LM3478?

## Decision

The LM3478 was selected for the power conversion and distribution subsystem.

---

## Requirements

The design required:

- Flexible power conversion
- Expansion capability
- Efficient power distribution

---

## Advantages

### Wide Application Range

The LM3478 supports:

- Boost converters
- SEPIC converters
- Flyback converters

---

### Design Flexibility

The controller enables future power architecture experimentation and optimization.

---

## Conclusion

The LM3478 provides flexibility and supports future design evolution.

---

# Why a 4-Layer PCB?

## Decision

A 4-layer PCB stackup was selected.

---

## Requirements

The project combines:

- Power electronics
- Battery management
- Embedded control
- Communication interfaces

These functions benefit significantly from a dedicated plane structure.

---

## Selected Stackup

### Layer 1

Top Signal

### Layer 2

Ground Plane

### Layer 3

Power Plane

### Layer 4

Bottom Signal

---

## Advantages

### Improved Ground Integrity

A continuous ground plane reduces:

- Noise
- Ground bounce
- Return path impedance

---

### Improved Power Distribution

Dedicated power routing improves:

- Voltage stability
- Current handling
- Routing simplicity

---

### Better EMI Performance

The stackup helps control:

- Switching noise
- Signal integrity
- Radiated emissions

---

### Easier Routing

The architecture contains:

- Battery management circuitry
- Multiple interfaces
- Power conversion stages

A 4-layer board significantly simplifies routing.

---

## Conclusion

The 4-layer architecture improves electrical performance and reflects professional PCB design practice.

---

# Why USB Type-C?

## Decision

USB Type-C was selected for the programming and debug interface.

---

## Requirements

The board required:

- Firmware upload capability
- Serial debugging
- Reliable connectivity

---

## Advantages

### Modern Interface

USB Type-C is widely available and eliminates cable orientation concerns.

---

### Development Convenience

Developers can:

- Program firmware
- Monitor debug messages
- Access diagnostics

using a single connection.

---

## Conclusion

USB Type-C improves usability and provides a modern development experience.

---

# Why UART3 Expansion?

## Decision

UART3 was reserved for future expansion.

---

## Requirements

Future communication capabilities were considered during the initial design phase.

---

## Potential Applications

### ESP32 Integration

Possible features:

- WiFi
- MQTT
- OTA updates
- Remote monitoring

---

### Wireless Modules

Possible integrations:

- Bluetooth
- LoRa
- GSM

---

## Conclusion

Reserving UART3 enables future communication upgrades without hardware redesign.

---

# Why OLED Support?

## Decision

An I²C expansion header was included.

---

## Motivation

Providing user feedback directly on the board improves usability.

---

## Possible Future Features

- Battery percentage
- Cell voltages
- Charging status
- Fault messages
- Solar statistics
- System diagnostics

---

## Conclusion

The I²C interface enables future user-interface enhancements with minimal hardware changes.

---

# Why Reserve CAN Resources?

## Decision

CAN resources were reserved on PA11 and PA12.

---

## Motivation

Industrial and automotive systems frequently use CAN communication.

Providing future support increases platform flexibility.

---

## Potential Applications

- Industrial battery systems
- Distributed power systems
- Energy management networks
- Vehicle integration

---

## Conclusion

Although unused in Revision A, CAN support was considered during architecture planning.

---

# Why Reserve PA3 for PV Voltage Measurement?

## Decision

PA3 was intentionally reserved for future photovoltaic voltage sensing.

---

## Design Observation

During development, battery monitoring and system architecture were prioritized.

A direct PV voltage measurement path was not implemented in Revision A.

---

## Future Improvement

An external voltage sensing circuit can be connected to the reserved interface.

This enables:

- PV voltage monitoring
- True MPPT implementation
- Power calculations
- Solar operating point tracking

---

## Engineering Benefit

Reserving the resource prevents future firmware limitations and allows the platform to evolve without major MCU changes.

---

# Why Multiple Reserved GPIOs?

## Decision

Several GPIOs were intentionally left unused.

---

## Motivation

Future requirements are difficult to predict during early hardware development.

Reserved resources allow:

- Additional sensors
- Relays
- Fan control
- Communication interfaces
- Data logging
- User interface improvements

---

## Conclusion

Strategic GPIO reservation improves long-term maintainability and scalability.

---

# Design Philosophy

The SolarCore-4S MPPT Power Management System was designed as a learning platform, development platform, and future expansion platform.

The design prioritizes:

- Safe battery operation
- Modular architecture
- Embedded system development
- Professional PCB design
- Expandability
- Maintainability

Rather than optimizing for a single application, the platform was intentionally designed to support future experimentation, firmware development, and advanced power management features.

---

## Revision Information

Document Version: 1.0

Board Revision: Rev A

Project:

SolarCore-4S MPPT Power Management System

Author:

Yukesh S
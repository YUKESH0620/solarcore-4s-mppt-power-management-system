# PCB Design Guide

## Overview

This document describes the PCB design methodology, layout strategy, stackup selection, grounding architecture, routing decisions, thermal considerations, and manufacturing preparation for the SolarCore-4S MPPT Power Management System.

The PCB was developed using Altium Designer and follows professional PCB design practices for mixed-signal embedded power electronics systems.

The board integrates:

- Battery Management
- Embedded Control
- Power Distribution
- Communication Interfaces
- Future MPPT Capability
- Expansion Interfaces

---

# Design Objectives

The PCB was designed with the following goals:

- Reliable power distribution
- Low-noise analog measurements
- Future firmware expansion
- Modular subsystem organization
- Manufacturing readiness
- Professional documentation generation

---

# PCB Information

| Parameter | Value |
|------------|------------|
| Design Tool | Altium Designer |
| Layer Count | 4 |
| PCB Type | Mixed Signal |
| MCU | STM32F103C8T6 |
| BMS IC | BQ76920 |
| USB Interface | CP2102N |
| Power Architecture | Battery Management and Power Distribution |
| Documentation | Draftsman |

---

# PCB Images

## Top View
![alt text](<Screenshot 2026-05-30 160011.png>)
Description:

Top layer contains the majority of active components including:

- STM32 Controller
- BQ76920
- Power Conversion Components
- Protection Circuitry
- USB-C Interface
- Expansion Headers

---

## Bottom View
![alt text](<Screenshot 2026-05-30 160140.png>)
Description:

Bottom layer primarily supports:

- Signal Routing
- Plane Connections
- Thermal Via Connections
- Power Distribution Support

---

## Perspective View
![alt text](<Screenshot 2026-05-31 214424.png>)
Description:

The 3D view demonstrates final component placement, connector accessibility, and overall mechanical organization.

---

# Layer Stackup

## Layer 1

### Top Signal Layer

Contains:

- Component placement
- Critical signal routing
- Power routing
- High-density interconnects

---

## Layer 2

### Ground Plane

Dedicated ground plane.

Purpose:

- Low impedance return path
- Noise reduction
- Improved signal integrity
- EMI reduction

---

## Layer 3

### Power Plane

Used for:

- Battery power distribution
- Regulated voltage rails
- Internal power routing

Benefits:

- Reduced voltage drop
- Simplified routing
- Improved current handling

---

## Layer 4

### Bottom Signal Layer

Used for:

- Secondary routing
- Interface signals
- Expansion routing
- Support traces

---

# Placement Strategy

The PCB follows a functional block placement methodology.

Subsystems are grouped according to function.

---

# STM32 Control Section

The STM32 subsystem is located in a dedicated control area.

Components:

- STM32F103C8T6
- Decoupling capacitors
- Crystal oscillator
- Reset circuitry
- Programming interface

Design Goals:

- Minimize digital noise
- Short decoupling paths
- Clean routing environment

---

# Battery Management Section

The BQ76920 subsystem is placed close to battery monitoring circuitry.

Design Goals:

- Accurate cell measurements
- Reduced noise pickup
- Short sensing paths

Benefits:

- Improved voltage monitoring
- Reliable fault detection

---

# Charge and Discharge Protection

Protection MOSFETs are grouped together.

Purpose:

- Simplified current flow
- Thermal management
- Easier troubleshooting

---

# USB-C Interface Placement

The USB-C connector is placed near the PCB edge.

Benefits:

- Easy accessibility
- Convenient firmware development
- Improved mechanical usability

---

# Expansion Interface Placement

Expansion headers are positioned at the board perimeter.

Interfaces:

- I²C Header
- UART3 Header
- Debug Connections

Benefits:

- Easy access
- Future module integration
- Reduced wiring complexity

---

# Routing Strategy

Routing was performed according to signal function.

---

# Power Routing

Power traces are prioritized.

Goals:

- Low voltage drop
- Low impedance
- Reliable current delivery

Methods:

- Wide traces
- Power pours
- Plane utilization

---

# Signal Routing

Signal traces were routed with emphasis on:

- Short path lengths
- Noise avoidance
- Reduced crossing

Sensitive signals include:

- BMS_ALERT
- Current Sense
- Voltage Sense
- UART Interfaces
- I²C Interfaces

---

# Analog Signal Routing

Special consideration was given to analog measurement signals.

Signals:

- FB_NODE
- CURRENT_SENSE_OUT

Objectives:

- Reduce noise
- Improve measurement accuracy
- Maintain ADC integrity

---

# Grounding Strategy

A dedicated ground plane is used.

Benefits:

- Reduced noise
- Improved return current paths
- Enhanced signal integrity

---

# Grounding Philosophy

The design separates noisy and sensitive circuitry through placement and routing practices while maintaining a unified ground reference.

Objectives:

- Minimize ground loops
- Reduce switching noise coupling
- Improve ADC measurements

---

# Power Distribution Architecture

The PCB distributes power through dedicated rails.

## SYS_VBAT

Primary battery rail.

Purpose:

- Battery distribution
- Protection stage supply

---

## V12_SYS

12V system rail.

Purpose:

- External loads
- Future peripherals

---

## V5_SYS

5V system rail.

Purpose:

- Logic support
- Expansion modules

---

## 3V3_SYS

3.3V rail.

Purpose:

- STM32
- BQ76920 interfaces
- Logic circuitry

---

# Thermal Design

Thermal management was considered throughout the layout process.

Methods:

- Copper spreading
- Power plane utilization
- Strategic component placement

---

# Thermal Considerations

Highest thermal contributors:

- Power MOSFETs
- Power conversion circuitry
- Voltage regulators

Design Objectives:

- Heat spreading
- Reduced hotspots
- Reliable operation

---

# Decoupling Strategy

Every major IC includes local decoupling capacitors.

Objectives:

- Stable operation
- Reduced transient noise
- Improved supply integrity

---

# EMI Considerations

The layout incorporates basic EMI-conscious practices.

Methods:

- Ground plane usage
- Controlled return paths
- Short critical traces
- Functional partitioning

---

# Design Rule Check (DRC)

Before manufacturing, the PCB should pass:

- Clearance checks
- Short circuit checks
- Unconnected net checks
- Silk screen checks
- Hole validation
- Polygon validation

---

# Manufacturing Readiness

The PCB design package includes:

- PCB Layout
- Schematics
- Draftsman Documentation
- Gerber Files
- NC Drill Files
- BOM

---

# Draftsman Documentation

Generated documentation includes:

## Assembly Drawing

Provides:

- Component placement
- Reference designators
- Assembly guidance

---

## Layer Documentation

Provides:

- Layer information
- Routing visibility
- PCB structure reference

---

## Manufacturing Documentation

Provides:

- Fabrication information
- Board specifications
- Production references

---

# Design Review Checklist

Before fabrication verify:

- All connectors labeled
- Polarized components verified
- BQ76920 pin mapping checked
- STM32 pin mapping checked
- Decoupling capacitors present
- DRC clean
- Silkscreen verified
- Drill files generated
- Gerbers generated
- BOM generated

---

# Known Revision-A Notes

## PV Voltage Measurement

Revision A reserves PA3 for future photovoltaic voltage measurement but does not directly acquire PV voltage.

Future revisions may add:

- External voltage divider
- Dedicated sensing interface
- Advanced MPPT functionality

---

# PCB Design Philosophy

The PCB was designed to serve as a modular development platform rather than a fixed-function charger.

The architecture emphasizes:

- Scalability
- Expandability
- Maintainability
- Embedded Development
- Power Electronics Learning
- Professional PCB Design Practices

The design supports future growth into:

- MPPT Systems
- Wireless Monitoring
- Industrial Communication
- Data Logging
- Advanced Battery Analytics

---

## Revision Information

Document Version: 1.0

Board Revision: Rev A

Project:

SolarCore-4S MPPT Power Management System

Author:

Yukesh S
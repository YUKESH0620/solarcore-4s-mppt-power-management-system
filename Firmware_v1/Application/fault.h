/*
Project     : MPPT Solar Power Supply
File        : fault.h

Description :
Fault management definitions.

Developer Notes :

* Centralized fault handling.
* Stores active system fault.
* Used by all application modules.
  */

#ifndef FAULT_H
#define FAULT_H

#include <stdint.h>

// System Fault Types

typedef enum
{
FAULT_NONE = 0,

FAULT_BMS_COMMUNICATION,

FAULT_BATTERY_OVERVOLTAGE,

FAULT_BATTERY_UNDERVOLTAGE,

FAULT_OVERCURRENT,

FAULT_SENSOR_FAILURE,

FAULT_MPPT_FAILURE
} fault_t;

// Public APIs

// Initialize fault manager
void Fault_Init(void);

// Set active fault
void Fault_Set(fault_t fault);

// Clear active fault
void Fault_Clear(void);

// Get active fault
fault_t Fault_Get(void);

#endif

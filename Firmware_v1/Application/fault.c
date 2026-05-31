/*
Project     : MPPT Solar Power Supply
File        : fault.c

Description :
Fault management implementation.

Developer Notes :

* Stores active system fault.
* Only one fault is tracked at a time.
  */

#include "fault.h"

// Current active fault
static fault_t g_ActiveFault;

// Initialize fault manager
void Fault_Init(void)
{
g_ActiveFault = FAULT_NONE;
}

// Set active fault
void Fault_Set(fault_t fault)
{
g_ActiveFault = fault;
}

// Clear active fault
void Fault_Clear(void)
{
g_ActiveFault = FAULT_NONE;
}

// Get active fault
fault_t Fault_Get(void)
{
return g_ActiveFault;
}

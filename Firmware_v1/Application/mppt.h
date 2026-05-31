/*
Project     : MPPT Solar Power Supply
File        : mppt.h

Description :
MPPT controller definitions.

Developer Notes :

* Handles solar charging control.
* Handles MPPT state.
* Uses battery and current sensing modules.
* Actual MPPT algorithm will be added later.
  */

#ifndef MPPT_H
#define MPPT_H

#include <stdint.h>

// MPPT Status

typedef enum
{
MPPT_STOPPED = 0,
MPPT_RUNNING

} mppt_state_t;

// Public APIs

// Initialize MPPT module
void MPPT_Init(void);

// Execute MPPT control loop
void MPPT_Update(void);

// Start MPPT operation
void MPPT_Start(void);

// Stop MPPT operation
void MPPT_Stop(void);

// Get MPPT state
mppt_state_t MPPT_GetState(void);

#endif

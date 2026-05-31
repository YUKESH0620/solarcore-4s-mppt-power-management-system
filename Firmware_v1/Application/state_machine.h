/*
Project     : MPPT Solar Power Supply
File        : state_machine.h

Description :
System state machine definitions.

Developer Notes :
* State transitions only.
* No hardware access.
* No peripheral control.
* No MPPT algorithm code.
  */

// Header Guard
#ifndef STATE_MACHINE_H
#define STATE_MACHINE_H

// Type Definitions

typedef enum
{
STATE_INIT = 0,
STATE_BATTERY_CHECK,
STATE_IDLE,
STATE_CHARGING,
STATE_DISCHARGING,
STATE_FAULT

} system_state_t;

// Public APIs

// Initialize state machine
void StateMachine_Init(void);

// Execute current active state
void StateMachine_Run(void);

// Change system state
void StateMachine_SetState(system_state_t state);

// Get current system state
system_state_t StateMachine_GetState(void);

#endif

/*
Project     : MPPT Solar Power Supply
File        : state_machine.c

Description :
State machine implementation.

Developer Notes :

* Executes system states.
* Controls state transitions.
* No direct hardware control.
* Peripheral actions must be handled through drivers.
  */

#include "state_machine.h"

// Current active system state
static system_state_t g_CurrentState;

// Private Function Prototypes

static void State_Init(void);
static void State_BatteryCheck(void);
static void State_Idle(void);
static void State_Charging(void);
static void State_Discharging(void);
static void State_Fault(void);

// Initialize state machine
void StateMachine_Init(void)
{
g_CurrentState = STATE_INIT;
}

// Execute current active state
void StateMachine_Run(void)
{
// Route execution to active state handler
switch(g_CurrentState)
{
case STATE_INIT:
State_Init();
break;

```
    case STATE_BATTERY_CHECK:
        State_BatteryCheck();
        break;

    case STATE_IDLE:
        State_Idle();
        break;

    case STATE_CHARGING:
        State_Charging();
        break;

    case STATE_DISCHARGING:
        State_Discharging();
        break;

    case STATE_FAULT:
        State_Fault();
        break;

    default:
        g_CurrentState = STATE_FAULT;
        break;
}
```

}

// Change system state
void StateMachine_SetState(system_state_t state)
{
g_CurrentState = state;
}

// Get current system state
system_state_t StateMachine_GetState(void)
{
return g_CurrentState;
}

// INIT state handler
static void State_Init(void)
{
// TODO:
// Initialize application modules


StateMachine_SetState(STATE_BATTERY_CHECK);

}

// BATTERY_CHECK state handler
static void State_BatteryCheck(void)
{
// TODO:
// Verify BQ76920 communication
// Verify battery presence
// Verify cell voltages

StateMachine_SetState(STATE_IDLE);

}

// IDLE state handler
static void State_Idle(void)
{
// TODO:
// Wait for charging or discharging request
}

// CHARGING state handler
static void State_Charging(void)
{
// TODO:
// Execute charging control
// Execute MPPT algorithm
}

// DISCHARGING state handler
static void State_Discharging(void)
{
// TODO:
// Monitor battery status
// Monitor load conditions
}

// FAULT state handler
static void State_Fault(void)
{
// TODO:
// Handle fault condition
// Wait for recovery
}

/*
Project     : MPPT Solar Power Supply
File        : mppt.c

Description :
MPPT controller implementation.

Developer Notes :

* Controls charging process.
* Uses battery information.
* Uses current measurements.
* Future location of MPPT algorithm.
  */

#include "mppt.h"

#include "battery.h"
#include "../drivers/ina180.h"

// Current MPPT state
static mppt_state_t g_MPPTState;

// Initialize MPPT module
void MPPT_Init(void)
{
g_MPPTState = MPPT_STOPPED;
}

// Execute MPPT control loop
void MPPT_Update(void)
{
if(g_MPPTState != MPPT_RUNNING)
{
return;
}

/*
 TODO

 1. Read solar current

 2. Read battery voltage

 3. Read charge voltage

 4. Execute MPPT algorithm

 5. Adjust PWM duty cycle
*/


}

// Start MPPT operation
void MPPT_Start(void)
{
g_MPPTState = MPPT_RUNNING;
}

// Stop MPPT operation
void MPPT_Stop(void)
{
g_MPPTState = MPPT_STOPPED;
}

// Get MPPT state
mppt_state_t MPPT_GetState(void)
{
return g_MPPTState;
}

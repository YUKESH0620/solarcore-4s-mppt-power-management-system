/*
Project     : MPPT Solar Power Supply
File        : main.c

Description :
Main firmware entry point.

Developer Notes :

* Initializes the firmware.
* Executes scheduler tasks.
* Executes state machine.
* Avoid placing application logic directly here.
* Keep main loop clean.
  */

#include "system/system.h"

#include "application/scheduler.h"
#include "application/state_machine.h"

int main(void)
{
scheduler_flags_t *pScheduler;

```
// Initialize complete firmware
System_Init();

// Get scheduler flags structure
pScheduler = Scheduler_GetFlags();

while(1)
{
    // Execute state machine every loop
    StateMachine_Run();

    // 1ms Tasks
    if(pScheduler->Task_1ms)
    {
        pScheduler->Task_1ms = 0;

        // Future 1ms tasks
    }

    // 10ms Tasks
    if(pScheduler->Task_10ms)
    {
        pScheduler->Task_10ms = 0;

        // Button handling
        // Buzzer handling
    }

    // 100ms Tasks
    if(pScheduler->Task_100ms)
    {
        pScheduler->Task_100ms = 0;

        // Battery monitoring
        // Sensor updates
    }

    // 500ms Tasks
    if(pScheduler->Task_500ms)
    {
        pScheduler->Task_500ms = 0;

        // OLED update
    }

    // 1000ms Tasks
    if(pScheduler->Task_1000ms)
    {
        pScheduler->Task_1000ms = 0;

        // Debug messages
    }
}
```

}

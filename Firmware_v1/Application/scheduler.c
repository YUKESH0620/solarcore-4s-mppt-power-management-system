/*
Project     : MPPT Solar Power Supply
File        : scheduler.c

Description :
Firmware task scheduler implementation.

Developer Notes :

* Generates periodic task flags.
* Uses 1ms system tick.
* No application logic shall be placed here.
  */

#include "scheduler.h"

// Scheduler task flags
static scheduler_flags_t g_SchedulerFlags;

// Time counters
static uint16_t Counter_10ms;
static uint16_t Counter_100ms;
static uint16_t Counter_500ms;
static uint16_t Counter_1000ms;

// Initialize scheduler
void Scheduler_Init(void)
{
Counter_10ms   = 0;
Counter_100ms  = 0;
Counter_500ms  = 0;
Counter_1000ms = 0;

```
g_SchedulerFlags.Task_1ms    = 0;
g_SchedulerFlags.Task_10ms   = 0;
g_SchedulerFlags.Task_100ms  = 0;
g_SchedulerFlags.Task_500ms  = 0;
g_SchedulerFlags.Task_1000ms = 0;
```

}

// Called every 1ms
void Scheduler_Update(void)
{
// 1ms task
g_SchedulerFlags.Task_1ms = 1;

```
Counter_10ms++;
Counter_100ms++;
Counter_500ms++;
Counter_1000ms++;

// 10ms task
if(Counter_10ms >= 10)
{
    Counter_10ms = 0;
    g_SchedulerFlags.Task_10ms = 1;
}

// 100ms task
if(Counter_100ms >= 100)
{
    Counter_100ms = 0;
    g_SchedulerFlags.Task_100ms = 1;
}

// 500ms task
if(Counter_500ms >= 500)
{
    Counter_500ms = 0;
    g_SchedulerFlags.Task_500ms = 1;
}

// 1000ms task
if(Counter_1000ms >= 1000)
{
    Counter_1000ms = 0;
    g_SchedulerFlags.Task_1000ms = 1;
}
```

}

// Return scheduler flags structure
scheduler_flags_t* Scheduler_GetFlags(void)
{
return &g_SchedulerFlags;
}

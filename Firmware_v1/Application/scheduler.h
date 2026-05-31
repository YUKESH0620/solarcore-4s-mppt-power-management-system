/*
Project     : MPPT Solar Power Supply
File        : scheduler.h

Description :
Firmware task scheduler definitions.

Developer Notes :

* Provides periodic task timing.
* All application modules shall use scheduler timing.
* Prevents blocking delays.
* Based on 1ms system tick.

Task Intervals :

1ms    -> System Tasks

10ms   -> Button, Buzzer

100ms  -> Battery Monitoring

500ms  -> OLED Update

1000ms -> Debug Messages
*/

#ifndef SCHEDULER_H
#define SCHEDULER_H

#include <stdint.h>

// Scheduler Task Flags
typedef struct
{
uint8_t Task_1ms;
uint8_t Task_10ms;
uint8_t Task_100ms;
uint8_t Task_500ms;
uint8_t Task_1000ms;

} scheduler_flags_t;

// Public APIs

// Initialize scheduler
void Scheduler_Init(void);

// Update scheduler timing
void Scheduler_Update(void);

// Get scheduler task flags
scheduler_flags_t* Scheduler_GetFlags(void);

#endif

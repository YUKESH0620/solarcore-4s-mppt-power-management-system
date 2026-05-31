/*
Project     : MPPT Solar Power Supply
File        : buzzer.h

Description :
Buzzer control definitions.

Developer Notes :

* Provides buzzer patterns.
* Uses GPIO driver internally.
* Application modules should use this interface.
  */

#ifndef BUZZER_H
#define BUZZER_H

#include <stdint.h>

// Buzzer patterns

typedef enum
{
BUZZER_NONE = 0,
BUZZER_SINGLE_BEEP,
BUZZER_DOUBLE_BEEP,
BUZZER_ERROR_BEEP

} buzzer_pattern_t;

// Public APIs

// Initialize buzzer module
void Buzzer_Init(void);

// Execute buzzer state machine
void Buzzer_Update(void);

// Start buzzer pattern
void Buzzer_Start(buzzer_pattern_t pattern);

#endif

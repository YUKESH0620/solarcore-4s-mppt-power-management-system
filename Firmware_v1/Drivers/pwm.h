/*
Project     : MPPT Solar Power Supply
File        : pwm.h

Description :
PWM driver definitions.

Developer Notes :

* Controls buck converter duty cycle.
* Uses TIM1 Channel 1.
* Output pin is PA8.
* Used by MPPT module.
  */

#ifndef PWM_H
#define PWM_H

#include <stdint.h>

// Public APIs

// Initialize PWM driver
void PWM_Init(void);

// Start PWM output
void PWM_Start(void);

// Stop PWM output
void PWM_Stop(void);

// Set PWM duty cycle (0-100%)
void PWM_SetDutyCycle(float dutyCycle);

// Get current duty cycle
float PWM_GetDutyCycle(void);

#endif

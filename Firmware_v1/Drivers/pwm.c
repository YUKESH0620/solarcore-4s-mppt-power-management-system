/*
Project     : MPPT Solar Power Supply
File        : pwm.c

Description :
PWM driver implementation.

Developer Notes :

* Uses TIM1 Channel 1.
* Controls buck converter duty cycle.
* Used by MPPT module.
  */

#include "pwm.h"
#include "main.h"

extern TIM_HandleTypeDef htim1;

// Current PWM duty cycle
static float g_DutyCycle;

// Initialize PWM driver
void PWM_Init(void)
{
g_DutyCycle = 0.0f;
}

// Start PWM output
void PWM_Start(void)
{
HAL_TIM_PWM_Start(&htim1, TIM_CHANNEL_1);
}

// Stop PWM output
void PWM_Stop(void)
{
HAL_TIM_PWM_Stop(&htim1, TIM_CHANNEL_1);
}

// Set PWM duty cycle (0-100%)
void PWM_SetDutyCycle(float dutyCycle)
{
uint32_t compareValue;
uint32_t period;

```
// Limit duty cycle range
if(dutyCycle > 100.0f)
{
    dutyCycle = 100.0f;
}

if(dutyCycle < 0.0f)
{
    dutyCycle = 0.0f;
}

g_DutyCycle = dutyCycle;

// Get timer period
period = __HAL_TIM_GET_AUTORELOAD(&htim1);

// Convert percentage to compare value
compareValue = (uint32_t)((dutyCycle / 100.0f) * period);

// Update PWM duty cycle
__HAL_TIM_SET_COMPARE(&htim1,
                      TIM_CHANNEL_1,
                      compareValue);
```

}

// Get current duty cycle
float PWM_GetDutyCycle(void)
{
return g_DutyCycle;
}

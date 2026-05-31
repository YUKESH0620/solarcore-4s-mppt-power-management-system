/*
Project     : MPPT Solar Power Supply
File        : system.c

Description :
System initialization implementation.

Developer Notes :

* Initializes all firmware modules.
* Called once during startup.
* Keep startup sequence centralized.
  */

#include "system.h"

// Drivers

#include "../drivers/gpio.h"
#include "../drivers/uart.h"
#include "../drivers/adc.h"
#include "../drivers/ina180.h"
#include "../drivers/pwm.h"

// Application

#include "../application/scheduler.h"
#include "../application/state_machine.h"
#include "../application/fault.h"
#include "../application/battery.h"
#include "../application/buzzer.h"
#include "../application/mppt.h"
#include "../application/display.h"

// Initialize complete firmware system
void System_Init(void)
{
// Drivers

    GPIO_Init();
    UART_Init();
    ADC_Driver_Init();
    INA180_Init();
    PWM_Init();

    // Application Modules

    Scheduler_Init();

    Fault_Init();

    Battery_Init();

    Buzzer_Init();

    MPPT_Init();

    Display_Init();

    StateMachine_Init();

}

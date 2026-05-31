/*
Project     : MPPT Solar Power Supply
File        : gpio.h

Description :
GPIO driver definitions.

Developer Notes :

* Handles LEDs, Button and Buzzer.
* Centralized GPIO access.
* Application code should not access GPIO registers directly.

Hardware Mapping :

PA1  -> USER_BUTTON

PB0  -> BAT_LEVEL1
PB1  -> BAT_LEVEL2
PB2  -> BAT_LEVEL3
PB3  -> BAT_LEVEL4
PB4  -> BAT_LEVEL5

PB9  -> BUZZER_CTRL
*/

#ifndef GPIO_H
#define GPIO_H

#include <stdint.h>

// Battery Level LEDs

typedef enum
{
LED_BAT_1 = 0,
LED_BAT_2,
LED_BAT_3,
LED_BAT_4,
LED_BAT_5

} led_t;

// Public APIs

// Initialize GPIO driver
void GPIO_Init(void);

// Turn ON selected LED
void GPIO_LED_On(led_t led);

// Turn OFF selected LED
void GPIO_LED_Off(led_t led);

// Toggle selected LED
void GPIO_LED_Toggle(led_t led);

// Read user button state
uint8_t GPIO_Button_Read(void);

// Turn buzzer ON
void GPIO_Buzzer_On(void);

// Turn buzzer OFF
void GPIO_Buzzer_Off(void);

#endif

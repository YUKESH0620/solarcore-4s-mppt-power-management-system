/*
Project     : MPPT Solar Power Supply
File        : gpio.c

Description :
GPIO driver implementation.

Developer Notes :

* Controls Battery LEDs.
* Controls Buzzer.
* Reads User Button.
* Hardware-specific GPIO operations are centralized here.
  */

#include "gpio.h"
#include "main.h"

// Initialize GPIO driver
void GPIO_Init(void)
{
// GPIO initialization handled by CubeMX/HAL
}

// Turn ON selected LED
void GPIO_LED_On(led_t led)
{
switch(led)
{
case LED_BAT_1:
HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, GPIO_PIN_SET);
break;

```
    case LED_BAT_2:
        HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, GPIO_PIN_SET);
        break;

    case LED_BAT_3:
        HAL_GPIO_WritePin(GPIOB, GPIO_PIN_2, GPIO_PIN_SET);
        break;

    case LED_BAT_4:
        HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, GPIO_PIN_SET);
        break;

    case LED_BAT_5:
        HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, GPIO_PIN_SET);
        break;

    default:
        break;
}
```

}

// Turn OFF selected LED
void GPIO_LED_Off(led_t led)
{
switch(led)
{
case LED_BAT_1:
HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, GPIO_PIN_RESET);
break;

```
    case LED_BAT_2:
        HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, GPIO_PIN_RESET);
        break;

    case LED_BAT_3:
        HAL_GPIO_WritePin(GPIOB, GPIO_PIN_2, GPIO_PIN_RESET);
        break;

    case LED_BAT_4:
        HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, GPIO_PIN_RESET);
        break;

    case LED_BAT_5:
        HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, GPIO_PIN_RESET);
        break;

    default:
        break;
}
```

}

// Toggle selected LED
void GPIO_LED_Toggle(led_t led)
{
switch(led)
{
case LED_BAT_1:
HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_0);
break;

```
    case LED_BAT_2:
        HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_1);
        break;

    case LED_BAT_3:
        HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_2);
        break;

    case LED_BAT_4:
        HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_3);
        break;

    case LED_BAT_5:
        HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_4);
        break;

    default:
        break;
}
```

}

// Read user button state
uint8_t GPIO_Button_Read(void)
{
return (uint8_t)HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_1);
}

// Turn buzzer ON
void GPIO_Buzzer_On(void)
{
HAL_GPIO_WritePin(GPIOB, GPIO_PIN_9, GPIO_PIN_SET);
}

// Turn buzzer OFF
void GPIO_Buzzer_Off(void)
{
HAL_GPIO_WritePin(GPIOB, GPIO_PIN_9, GPIO_PIN_RESET);
}


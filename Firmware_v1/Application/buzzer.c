/*
Project     : MPPT Solar Power Supply
File        : buzzer.c

Description :
Buzzer control implementation.

Developer Notes :

* Uses GPIO buzzer driver.
* Generates buzzer patterns.
  */

#include "buzzer.h"
#include "../drivers/gpio.h"

// Current active buzzer pattern
static buzzer_pattern_t g_BuzzerPattern;

// Initialize buzzer module
void Buzzer_Init(void)
{
g_BuzzerPattern = BUZZER_NONE;
}

// Execute buzzer state machine
void Buzzer_Update(void)
{
switch(g_BuzzerPattern)
{
case BUZZER_NONE:
break;

```
    case BUZZER_SINGLE_BEEP:
        /*
         TODO

         Generate single beep
        */
        break;

    case BUZZER_DOUBLE_BEEP:
        /*
         TODO

         Generate double beep
        */
        break;

    case BUZZER_ERROR_BEEP:
        /*
         TODO

         Generate error pattern
        */
        break;

    default:
        break;
}
```

}

// Start buzzer pattern
void Buzzer_Start(buzzer_pattern_t pattern)
{
g_BuzzerPattern = pattern;
}

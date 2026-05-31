/*
Project     : MPPT Solar Power Supply
File        : display.c

Description :
Display management implementation.

Developer Notes :

* Shows battery information.
* Shows charging status.
* Shows fault information.
* Uses OLED driver for rendering.
  */

#include "display.h"

#include "battery.h"
#include "fault.h"
#include "mppt.h"

#include "../drivers/oled.h"

// Initialize display module
void Display_Init(void)
{
OLED_Init();
}

// Update display contents
void Display_Update(void)
{
battery_data_t *pBattery;

```
pBattery = Battery_GetData();

OLED_Clear();

/*
 TODO

 Line 1:
 Battery Percentage

 Line 2:
 Pack Voltage

 Line 3:
 Solar Current

 Line 4:
 System State

 Line 5:
 Fault Status
*/

OLED_Update();
```

}

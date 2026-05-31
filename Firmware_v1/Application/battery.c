/*
Project     : MPPT Solar Power Supply
File        : battery.c

Description :
Battery management implementation.

Developer Notes :

* Uses BQ76920 driver.
* Converts raw battery data.
* Calculates pack voltage.
* Calculates battery percentage.
  */

#include "battery.h"
#include "../drivers/bq76920.h"

// Battery information structure
static battery_data_t g_BatteryData;

// Initialize battery module
void Battery_Init(void)
{
g_BatteryData.Cell1Voltage = 0;
g_BatteryData.Cell2Voltage = 0;
g_BatteryData.Cell3Voltage = 0;
g_BatteryData.Cell4Voltage = 0;

```
g_BatteryData.PackVoltage = 0;
g_BatteryData.Percentage  = 0;
```

}

// Update battery measurements
void Battery_Update(void)
{
/*
TODO:

```
 1. Read cell voltage registers
 2. Convert raw ADC values
 3. Calculate cell voltages
 4. Calculate pack voltage
 5. Calculate battery percentage
*/
```

}

// Get battery information
battery_data_t* Battery_GetData(void)
{
return &g_BatteryData;
}

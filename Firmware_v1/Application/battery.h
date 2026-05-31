/*
Project     : MPPT Solar Power Supply
File        : battery.h

Description :
Battery management definitions.

Developer Notes :

* Handles battery monitoring.
* Handles voltage calculations.
* Handles battery percentage calculations.
* Handles battery fault detection.
* Uses BQ76920 driver for raw data acquisition.
  */

#ifndef BATTERY_H
#define BATTERY_H

#include <stdint.h>

// Battery Information Structure

typedef struct
{
uint16_t Cell1Voltage;
uint16_t Cell2Voltage;
uint16_t Cell3Voltage;
uint16_t Cell4Voltage;

```
uint16_t PackVoltage;

uint8_t Percentage;
```

} battery_data_t;

// Public APIs

// Initialize battery module
void Battery_Init(void);

// Update battery measurements
void Battery_Update(void);

// Get battery information
battery_data_t* Battery_GetData(void);

#endif

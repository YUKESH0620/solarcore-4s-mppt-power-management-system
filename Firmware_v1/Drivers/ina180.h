/*
Project     : MPPT Solar Power Supply
File        : ina180.h

Description :
INA180 current sense driver definitions.

Developer Notes :

* Reads current sense voltage from ADC.
* Converts ADC value to current.
* Used for solar current monitoring.
* Used by MPPT module.

Hardware Mapping :

PA5 -> CURRENT_SENSE
INA180A1 Gain = 20 V/V
Shunt = 10mΩ
*/

#ifndef INA180_H
#define INA180_H

#include <stdint.h>

// Current Information Structure

typedef struct
{
uint16_t AdcValue;
float SenseVoltage;
float Current;

} ina180_data_t;

// Public APIs

// Initialize INA180 module
void INA180_Init(void);

// Update current measurement
void INA180_Update(void);

// Get current measurement data
ina180_data_t* INA180_GetData(void);

#endif

/*
Project     : MPPT Solar Power Supply
File        : adc.h

Description :
ADC driver definitions.

Developer Notes :

* Centralized ADC access.
* Used by INA180 driver.
* Used by MPPT module.
* Future support for PV voltage sensing.
  */

#ifndef ADC_H
#define ADC_H

#include <stdint.h>

// ADC Channels Used

#define ADC_FB_NODE_CHANNEL         ADC_CHANNEL_4
#define ADC_CURRENT_SENSE_CHANNEL   ADC_CHANNEL_5

// Public APIs

// Initialize ADC driver
void ADC_Driver_Init(void);

// Read ADC channel
uint16_t ADC_ReadChannel(uint32_t channel);

#endif

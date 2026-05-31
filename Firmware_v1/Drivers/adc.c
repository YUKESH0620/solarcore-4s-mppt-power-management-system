/*
Project     : MPPT Solar Power Supply
File        : adc.c

Description :
ADC driver implementation.

Developer Notes :

* Provides generic ADC access.
* Other modules should use this driver instead of HAL ADC directly.
  */

#include "adc.h"
#include "main.h"

extern ADC_HandleTypeDef hadc1;

// Initialize ADC driver
void ADC_Driver_Init(void)
{
// ADC initialization handled by CubeMX/HAL
}

// Read ADC channel
uint16_t ADC_ReadChannel(uint32_t channel)
{
ADC_ChannelConfTypeDef sConfig = {0};

sConfig.Channel = channel;
sConfig.Rank = ADC_REGULAR_RANK_1;
sConfig.SamplingTime = ADC_SAMPLETIME_239CYCLES_5;

HAL_ADC_ConfigChannel(&hadc1, &sConfig);

HAL_ADC_Start(&hadc1);

HAL_ADC_PollForConversion(&hadc1, HAL_MAX_DELAY);

return HAL_ADC_GetValue(&hadc1);


}

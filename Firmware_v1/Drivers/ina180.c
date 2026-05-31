/*
Project     : MPPT Solar Power Supply
File        : ina180.c

Description :
INA180 current sense driver implementation.

Developer Notes :

* Reads PA5 ADC value.
* Converts ADC reading to current.
* Provides solar current information.
  */

#include "ina180.h"

// Current measurement data
static ina180_data_t g_CurrentData;

// Initialize INA180 module
void INA180_Init(void)
{
g_CurrentData.AdcValue = 0;
g_CurrentData.SenseVoltage = 0.0f;
g_CurrentData.Current = 0.0f;
}

// Update current measurement
void INA180_Update(void)
{
/*
TODO

```
 1. Read ADC channel connected to PA5

 2. Convert ADC count to voltage

 3. Calculate INA180 output voltage

 4. Calculate current using:

    Current = Vout / (Gain × Rshunt)

 5. Store results
*/
```

}

// Get current measurement data
ina180_data_t* INA180_GetData(void)
{
return &g_CurrentData;
}

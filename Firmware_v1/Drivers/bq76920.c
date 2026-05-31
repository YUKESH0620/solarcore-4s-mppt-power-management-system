/*
Project     : MPPT Solar Power Supply
File        : bq76920.c

Description :
BQ76920 driver implementation.

Developer Notes :

* Raw device driver.
* Handles I2C communication only.
* No battery calculations.
* No charging decisions.
  */

#include "bq76920.h"
#include "main.h"

extern I2C_HandleTypeDef hi2c1;

// Initialize BQ76920 driver
uint8_t BQ76920_Init(void)
{
uint8_t sysStat;

```
// Verify communication by reading SYS_STAT
sysStat = BQ76920_ReadRegister(BQ76920_SYS_STAT);

return sysStat;
```

}

// Read single register
uint8_t BQ76920_ReadRegister(uint8_t regAddress)
{
uint8_t data = 0;

```
HAL_I2C_Mem_Read(&hi2c1,
                 (BQ76920_I2C_ADDRESS << 1),
                 regAddress,
                 I2C_MEMADD_SIZE_8BIT,
                 &data,
                 1,
                 HAL_MAX_DELAY);

return data;
```

}

// Write single register
void BQ76920_WriteRegister(uint8_t regAddress,
uint8_t data)
{
HAL_I2C_Mem_Write(&hi2c1,
(BQ76920_I2C_ADDRESS << 1),
regAddress,
I2C_MEMADD_SIZE_8BIT,
&data,
1,
HAL_MAX_DELAY);
}

// Read multiple registers
void BQ76920_ReadRegisters(uint8_t regAddress,
uint8_t *buffer,
uint8_t length)
{
HAL_I2C_Mem_Read(&hi2c1,
(BQ76920_I2C_ADDRESS << 1),
regAddress,
I2C_MEMADD_SIZE_8BIT,
buffer,
length,
HAL_MAX_DELAY);
}

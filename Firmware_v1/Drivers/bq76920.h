/*
Project     : MPPT Solar Power Supply
File        : bq76920.h

Description :
BQ76920 battery monitor driver definitions.

Developer Notes :

* Raw device driver only.
* Handles I2C communication.
* Handles register access.
* No battery calculations.
* No SOC calculations.
* No charging decisions.

Hardware Mapping :

PB6 -> I2C1_SCL
PB7 -> I2C1_SDA

PA0 -> BMS_ALERT
*/

#ifndef BQ76920_H
#define BQ76920_H

#include <stdint.h>

// BQ76920 I2C Address

#define BQ76920_I2C_ADDRESS       0x08

// Important Registers

#define BQ76920_SYS_STAT          0x00
#define BQ76920_CELLBAL1          0x01

#define BQ76920_SYS_CTRL1         0x04
#define BQ76920_SYS_CTRL2         0x05

#define BQ76920_VC1_HI_BYTE       0x0C
#define BQ76920_VC1_LO_BYTE       0x0D

#define BQ76920_VC2_HI_BYTE       0x0E
#define BQ76920_VC2_LO_BYTE       0x0F

#define BQ76920_VC3_HI_BYTE       0x10
#define BQ76920_VC3_LO_BYTE       0x11

#define BQ76920_VC4_HI_BYTE       0x12
#define BQ76920_VC4_LO_BYTE       0x13

#define BQ76920_BAT_HI_BYTE       0x2A
#define BQ76920_BAT_LO_BYTE       0x2B

// Public APIs

// Initialize BQ76920 driver
uint8_t BQ76920_Init(void);

// Read single register
uint8_t BQ76920_ReadRegister(uint8_t regAddress);

// Write single register
void BQ76920_WriteRegister(uint8_t regAddress,
uint8_t data);

// Read multiple registers
void BQ76920_ReadRegisters(uint8_t regAddress,
uint8_t *buffer,
uint8_t length);

#endif

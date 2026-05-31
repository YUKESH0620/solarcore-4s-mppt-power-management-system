/*
Project     : MPPT Solar Power Supply
File        : oled.h

Description :
SSD1306 OLED driver definitions.

Developer Notes :

* SSD1306 128x64 I2C display.
* Graphics driver only.
* No battery logic.
* No MPPT logic.
* No fault logic.

Hardware Mapping :

PB6 -> I2C1_SCL
PB7 -> I2C1_SDA
*/

#ifndef OLED_H
#define OLED_H

#include <stdint.h>

// Display dimensions

#define OLED_WIDTH     128
#define OLED_HEIGHT    64

// Public APIs

// Initialize OLED
void OLED_Init(void);

// Clear display buffer
void OLED_Clear(void);

// Update display
void OLED_Update(void);

// Set cursor position
void OLED_SetCursor(uint8_t x,
uint8_t y);

// Write string
void OLED_WriteString(char *str);

#endif



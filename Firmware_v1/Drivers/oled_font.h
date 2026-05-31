/*
Project     : MPPT Solar Power Supply
File        : oled_font.h

Description :
SSD1306 font definitions.

Developer Notes :

* Stores character bitmaps.
* Used by OLED driver.
* Keep font data separate from OLED logic.
  */

#ifndef OLED_FONT_H
#define OLED_FONT_H

#include <stdint.h>

// Font Information

#define FONT_WIDTH     5
#define FONT_HEIGHT    7

// ASCII 32-127

extern const uint8_t Font5x7[][5];

#endif

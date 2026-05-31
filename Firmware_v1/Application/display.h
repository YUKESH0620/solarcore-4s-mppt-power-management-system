/*
Project     : MPPT Solar Power Supply
File        : display.h

Description :
Display management definitions.

Developer Notes :

* Controls OLED screen content.
* Collects information from application modules.
* Uses OLED driver for rendering.
* Keeps project logic separate from OLED driver.
  */

#ifndef DISPLAY_H
#define DISPLAY_H

// Public APIs

// Initialize display module
void Display_Init(void);

// Update display contents
void Display_Update(void);

#endif

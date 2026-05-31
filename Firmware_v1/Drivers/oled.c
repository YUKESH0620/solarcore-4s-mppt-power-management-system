/*
Project     : MPPT Solar Power Supply
File        : oled.c

Description :
SSD1306 OLED driver implementation.

Developer Notes :

* Uses I2C1.
* SSD1306 controller.
* Graphics driver only.
  */

#include "oled.h"
#include "main.h"

extern I2C_HandleTypeDef hi2c1;

// Display buffer
static uint8_t OLED_Buffer[1024];

// Current cursor position
static uint8_t CursorX;
static uint8_t CursorY;

// Initialize OLED
void OLED_Init(void)
{
/*
TODO

```
 SSD1306 initialization sequence
*/
```

}

// Clear display buffer
void OLED_Clear(void)
{
uint16_t i;

```
for(i = 0; i < sizeof(OLED_Buffer); i++)
{
    OLED_Buffer[i] = 0x00;
}
```

}

// Update display
void OLED_Update(void)
{
/*
TODO

```
 Transfer display buffer
 to SSD1306 over I2C
*/
```

}

// Set cursor position
void OLED_SetCursor(uint8_t x,
uint8_t y)
{
CursorX = x;
CursorY = y;
}

// Write string
void OLED_WriteString(char *str)
{
/*
TODO

```
 Character rendering
 Font table lookup
 Buffer update
*/
```

}

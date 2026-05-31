/*
Project     : MPPT Solar Power Supply
File        : uart.c

Description :
UART communication implementation.

Developer Notes :

* Uses USART1 for debugging.
* Connected to CP2102N USB-UART bridge.
* Blocking transmit implementation.
* Can be upgraded to interrupt/DMA later.
  */

#include "uart.h"
#include "main.h"

extern UART_HandleTypeDef huart1;

// Initialize UART module
void UART_Init(void)
{
// UART initialization handled by CubeMX/HAL
}

// Send single character
void UART_SendChar(char ch)
{
HAL_UART_Transmit(&huart1,
(uint8_t *)&ch,
1,
HAL_MAX_DELAY);
}

// Send string
void UART_SendString(const char *str)
{
while(*str != '\0')
{
UART_SendChar(*str);
str++;
}
}

// Send string followed by CRLF
void UART_SendLine(const char *str)
{
UART_SendString(str);

```
UART_SendChar('\r');
UART_SendChar('\n');
```

}

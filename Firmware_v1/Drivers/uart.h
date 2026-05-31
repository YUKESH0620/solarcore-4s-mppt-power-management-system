/*
Project     : MPPT Solar Power Supply
File        : uart.h

Description :
UART communication interface.

Developer Notes :

* Primarily used for debugging.
* Uses USART1 connected to CP2102N.
* All debug messages should pass through this module.
* Application code should not directly use HAL UART functions.

Hardware Mapping :

PA9  -> USART1_TX
PA10 -> USART1_RX
*/

#ifndef UART_H
#define UART_H

#include <stdint.h>

// Initialize UART module
void UART_Init(void);

// Send single character
void UART_SendChar(char ch);

// Send string
void UART_SendString(const char *str);

// Send line with CRLF
void UART_SendLine(const char *str);

#endif

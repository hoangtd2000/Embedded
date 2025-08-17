/*
 *  Created on: Apr 21, 2025
 *      Author: Hoangtd2000
 */
#ifndef _UART_H_
#define _UART_H_
#include <compiler_defs.h>
#include <C8051F580_defs.h> // SFR declarations
void UART1_Init(U32 sysclk, U32 baudrate);
#endif
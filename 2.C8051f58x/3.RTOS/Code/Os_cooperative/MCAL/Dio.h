/*
 *  Created on: Apr 21, 2025
 *      Author: Hoangtd2000
 */
#ifndef _DIO_H_
#define _DIO_H_
#include <compiler_defs.h>
#include <C8051F580_defs.h> // SFR declarations

#define SET 1U
#define RESET 0U

#define PRESS 0U
#define RELEASE 1U

SBIT(LED_G, SFR_P2, 1);
SBIT(LED_Y, SFR_P2, 0);
SBIT(SW2, SFR_P1, 2);
typedef enum
{
    LED_GREEN,
    LED_YELLOW
} Led_e;

void PORT_Init(void);
void Tonggle(Led_e led);
U8 Get_Button_state(void);
void External_Interrupt_Init(void);
void Ext0_Set_Callback_Ptr(void (*funct)(void));
#endif
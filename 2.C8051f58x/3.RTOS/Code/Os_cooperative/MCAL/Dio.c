#include "Dio.h"

//-----------------------------------------------------------------------------
// P1.2   digital   open-drain    SW2
// P1.5   digital   push-pull    UART1 TX
// P1.6   digital   open-drain   UART1 RX
// P2.0   digital   push-pull    LED YELLOW
// P2.1   digital   push-pull    LED GREEN
//-----------------------------------------------------------------------------
void (*Ext0_call_back_ptr)(void) = 0;
void PORT_Init(void)
{
    U8 SFRPAGE_save = SFRPAGE;
    SFRPAGE = CONFIG_PAGE;
    P2MDOUT = 0x03;
    P1MDOUT |= 0x20; // TX1 (P1.5) push-pull
    P1MDIN &= ~0x20; // RX1 (P1.6) input
    P0SKIP = 0xFF;
    P1SKIP = 0x1F;
	P1MDIN &= ~0x02;
    XBR2 = 0x42; // Enable UART1 on P2.0(TX) and P2.1(RX)
                 // // Enable crossbar and weak pull-ups
    SFRPAGE = SFRPAGE_save;
}
void Tonggle(Led_e led)
{
    switch (led)
    {
    case LED_GREEN:
        LED_G = ~LED_G;
        break;
    case LED_YELLOW:
        LED_Y = ~LED_Y;
        break;
    }
}
U8 Get_Button_state(void){
    return SW2;
}
void External_Interrupt_Init(void)
{
       U8 SFRPAGE_save = SFRPAGE;
    SFRPAGE = CONFIG_PAGE;

    TCON |= 0x01;      // IT0 = 1 ? edge-triggered
    IT01CF = 0x02;     // /INT0 on P1.2, active-low (bit 7 = 0)
    EX0 = 1;           // Enable /INT0
    EA = 1;            // Global interrupt enable

    SFRPAGE = SFRPAGE_save;
}
void Ext0_Set_Callback_Ptr(void (*funct)(void))
{
    Ext0_call_back_ptr = funct;
}
INTERRUPT(INT0_ISR, INTERRUPT_INT0)
{
	if(Ext0_call_back_ptr != 0){
		Ext0_call_back_ptr();
	}
}
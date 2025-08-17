#include "Timer.h"
SEG_XDATA U32 G_systick = 0;
void (*Timer2_Call_Back_Ptr)(void) = 0;
void TIMER2_Init(U16 counts)
{
    U8 SFRPAGE_save = SFRPAGE;
    SFRPAGE = ACTIVE_PAGE;

    TMR2CN = 0x00;  // Stop Timer2; Clear TF2;
                    // use SYSCLK/12 as timebase
    CKCON &= ~0x60; // Timer2 clocked based on T2XCLK;

    TMR2RL = -counts; // Init reload values
    TMR2 = 0xFFFF;    // Set to reload immediately
    ET2 = 1;          // Enable Timer2 interrupts
    TR2 = 1;          // Start Timer2
    SFRPAGE = SFRPAGE_save;
}
void Clear_Timer2_ISR_Flag(void)
{
    TF2H = 0; // Clear Timer2 interrupt flag
}
void Timer2_Set_Callback_Ptr(void (*funct)(void))
{
    Timer2_Call_Back_Ptr = funct;
}
void Increase_G_systick(void)
{
    G_systick++;
}
U32 Get_G_systick(void)
{
    return G_systick;
}
INTERRUPT(Timer2_ISR, INTERRUPT_TIMER2)
{
    if (Timer2_Call_Back_Ptr != 0)
    {
        Timer2_Call_Back_Ptr();
    }
}
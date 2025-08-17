#include "GPT.h"
void SYSCLK_Init(void)
{
    U8 SFRPAGE_save = SFRPAGE;
    SFRPAGE = CONFIG_PAGE;

    OSCICN |= 0x87; // Configure internal oscillator for
                    // its maximum frequency
    RSTSRC = 0x04;  // Enable missing clock detector

    SFRPAGE = SFRPAGE_save;
}
#include "Uart.h"

void UART1_Init(U32 sysclk, U32 baudrate)
{
    U8 SFRPAGE_save = SFRPAGE;
    SFRPAGE = ACTIVE2_PAGE;

    SCON1 = 0x10; // SCON1: 8-bit variable bit rate
                  //        level of STOP bit is ignored
                  //        RX enabled
                  //        ninth bits are zeros
                  //        clear RI0 and TI0 bits
    if (sysclk / baudrate / 2 / 256 < 1)
    {
        TH1 = -(sysclk / baudrate / 2);
        CKCON &= ~0x0B; // T1M = 1; SCA1:0 = xx
        CKCON |= 0x08;
    }
    else if (sysclk / baudrate / 2 / 256 < 4)
    {
        TH1 = -(sysclk / baudrate / 2 / 4);
        CKCON &= ~0x0B; // T1M = 0; SCA1:0 = 01
        CKCON |= 0x01;
    }
    else if (sysclk / baudrate / 2 / 256 < 12)
    {
        TH1 = -(sysclk / baudrate / 2 / 12);
        CKCON &= ~0x0B; // T1M = 0; SCA1:0 = 00
    }
    else
    {
        TH1 = -(sysclk / baudrate / 2 / 48);
        CKCON &= ~0x0B; // T1M = 0; SCA1:0 = 10
        CKCON |= 0x02;
    }

    TL1 = TH1;     // Init Timer1
    TMOD &= ~0xF0; // TMOD: timer 1 in 8-bit autoreload
    TMOD |= 0x20;
    TR1 = 1; // START Timer1

    TI1 = 1; // Indicate TX0 ready (SCON1)

    SFRPAGE = SFRPAGE_save;
}
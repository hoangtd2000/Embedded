#pragma iv(0x0000)

#include <compiler_defs.h>
#include <C8051F580_defs.h>            // SFR declarations
#include <stdio.h>
#include "Test_flash.h"

//-----------------------------------------------------------------------------
// Global CONSTANTS
//-----------------------------------------------------------------------------
SBIT(LED_G, SFR_P2, 1);
SBIT(LED_Y, SFR_P2, 0);
SBIT(SW2, SFR_P1, 2);
#define SYSCLK      24000000           // SYSCLK frequency in Hz
#define BAUDRATE      115200           // Baud rate of UART in bps
//-----------------------------------------------------------------------------
// Function PROTOTYPES
//-----------------------------------------------------------------------------

void SYSCLK_Init (void);
void UART1_Init (void);
void PORT_Init (void);
void delayms(int time); 
void task1_handler(void);
void task2_handler(void);
void TIMER2_Init (U16 counts);
void EXTERNAL_INTERRUPT_Init(void);
SEG_XDATA U32 G_systick = 0;

SEG_XDATA U32 test = 1;

//-----------------------------------------------------------------------------
// MAIN Routine
//-----------------------------------------------------------------------------

void main (void)
{

    U8 SFRPAGE_save = SFRPAGE;

	SFRPAGE = ACTIVE_PAGE;
   PCA0MD &= ~0x40;                    // Disable watchdog timer
       write_bank1();
    write_bank2();
    write_bank3();
   
   PORT_Init();                        // Initialize Port I/O
   SYSCLK_Init ();                     // Initialize Oscillator
   UART1_Init();
   TIMER2_Init(SYSCLK / 12 / 1000); // Init Timer2
   EXTERNAL_INTERRUPT_Init();
	EA = 1;               // Enable global interrupts	
	SFRPAGE = ACTIVE2_PAGE;  

   while (1)
   {
    //   LED_G = ~LED_G;   // Toggle green LED
       LED_Y = ~LED_Y;   // Toggle yellow LED
      printf ("hello \n");
      delayms(1000);     // Delay 100 ms
   }
}

//-----------------------------------------------------------------------------
// P1.5   digital   push-pull    UART1 TX
// P1.6   digital   open-drain   UART1 RX
//-----------------------------------------------------------------------------
void PORT_Init (void)
 {
   U8 SFRPAGE_save = SFRPAGE;
   SFRPAGE = CONFIG_PAGE;
   P2MDOUT   = 0x03;
   P1MDOUT |= 0x20; // TX1 (P1.5) push-pull
   P1MDIN &= ~0x20; // RX1 (P1.6) input
   P0SKIP    = 0xFF;
   P1SKIP    = 0x1F;

   XBR2    = 0x42;                     // Enable UART1 on P2.0(TX) and P2.1(RX)
                                    // // Enable crossbar and weak pull-ups
   SFRPAGE = SFRPAGE_save;
 }

//-----------------------------------------------------------------------------
// SYSCLK_Init
//-----------------------------------------------------------------------------
//
// Return Value : None
// Parameters   : None

void SYSCLK_Init (void)
{
   U8 SFRPAGE_save = SFRPAGE;
   SFRPAGE = CONFIG_PAGE;

   OSCICN |= 0x87;                     // Configure internal oscillator for
                                       // its maximum frequency
   RSTSRC  = 0x04;                     // Enable missing clock detector

   SFRPAGE = SFRPAGE_save;
}

//-----------------------------------------------------------------------------
// UART1_Init
//-----------------------------------------------------------------------------

void UART1_Init (void)
{
   U8 SFRPAGE_save = SFRPAGE;
   SFRPAGE = ACTIVE2_PAGE;

   SCON1 = 0x10;                       // SCON1: 8-bit variable bit rate
                                       //        level of STOP bit is ignored
                                       //        RX enabled
                                       //        ninth bits are zeros
                                       //        clear RI0 and TI0 bits
   if (SYSCLK / BAUDRATE / 2 / 256 < 1) 
   {
      TH1 = -(SYSCLK / BAUDRATE / 2);
      CKCON &= ~0x0B;                  // T1M = 1; SCA1:0 = xx
      CKCON |=  0x08;
   } 
   else if (SYSCLK / BAUDRATE / 2 / 256 < 4) 
   {
      TH1 = -(SYSCLK / BAUDRATE / 2 / 4);
      CKCON &= ~0x0B;                  // T1M = 0; SCA1:0 = 01
      CKCON |=  0x01;
   } 
   else if (SYSCLK / BAUDRATE / 2 / 256 < 12) 
   {
      TH1 = -(SYSCLK / BAUDRATE / 2 / 12);
      CKCON &= ~0x0B;                  // T1M = 0; SCA1:0 = 00
   } 
   else 
   {
      TH1 = -(SYSCLK / BAUDRATE / 2 / 48);
      CKCON &= ~0x0B;                  // T1M = 0; SCA1:0 = 10
      CKCON |=  0x02;
   }

   TL1 = TH1;                          // Init Timer1
   TMOD &= ~0xF0;                      // TMOD: timer 1 in 8-bit autoreload
   TMOD |=  0x20;
   TR1 = 1;                            // START Timer1

   TI1 = 1;                            // Indicate TX0 ready (SCON1)

   SFRPAGE = SFRPAGE_save;
}




void delayms(int time)
{
	G_systick = 0;
	while(G_systick < time);
}



void TIMER2_Init (U16 counts)
{
    U8 SFRPAGE_save = SFRPAGE;
   SFRPAGE = ACTIVE_PAGE;

   TMR2CN  = 0x00;                     // Stop Timer2; Clear TF2;
                                       // use SYSCLK/12 as timebase
                                       CKCON  &= ~0x60;                    // Timer2 clocked based on T2XCLK;
                                       
                                       TMR2RL  = -counts;                  // Init reload values
                                       TMR2    = 0xFFFF;                   // Set to reload immediately
   ET2     = 1;                        // Enable Timer2 interrupts
   TR2     = 1;                        // Start Timer2
   SFRPAGE = SFRPAGE_save;
}
/*
INTERRUPT(Timer2_ISR, INTERRUPT_TIMER2)
{
	TF2H = 0 ;
	G_systick++;
}
*/
void isr_timer(void)interrupt INTERRUPT_TIMER2{
		TF2H = 0 ;
	G_systick++;
}

void EXTERNAL_INTERRUPT_Init (void)
{
       U8 sfr_backup = SFRPAGE;
    SFRPAGE = CONFIG_PAGE;

    TCON |= 0x01;      // IT0 = 1 ? edge-triggered
    IT01CF = 0x02;     // /INT0 on P1.2, active-low (bit 7 = 0)
    EX0 = 1;           // Enable /INT0
    EA = 1;            // Global interrupt enable

    SFRPAGE = sfr_backup;
}

//INTERRUPT(INT0_ISR, INTERRUPT_INT0)
void hoang(void) interrupt INTERRUPT_INT0
{
   //test = 0 ;
	if(!SW2){
   LED_G = ~LED_G;
   }
}


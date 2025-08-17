#include <compiler_defs.h>
#include <C8051F580_defs.h> // SFR declarations
#include "Test_flash.h"
extern U8 test;
void write_bank1(void)
{
    SEG_XDATA U8 a_bank1 = 10;
    a_bank1++;
	test++;
    if (a_bank1 == 10)
    {
        return;
    }
    return;
}
void write_bank2(void)
{
    SEG_XDATA U8 a_bank1 = 10;
    a_bank1++;
    test++;
	if (a_bank1 == 10)
    {
        return;
    }
    return;
}
void write_bank3(void)
{
    SEG_XDATA U8 a_bank1 = 10;
    a_bank1++;
    test++;
	if (a_bank1 == 10)
    {
        return;
    }
    return;
}

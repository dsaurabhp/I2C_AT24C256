#include "delay.h"
#include "types.h"
void delay_ms(u32 DlyMs)
{
	DlyMs*=12000;
	while(DlyMs--);
}
void delay_us(u32 DlyUs)
{
	DlyUs*=12;
	while(DlyUs--);
}

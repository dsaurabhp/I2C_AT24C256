#include "lcd.h"
#include "lcd_defines.h"
#include <lpc21xx.h>
#include "defines.h"
#include "delay.h"
void CmdLCD(u8 ch)
{
	IOCLR0|=1<<RS;
	WRITEBYTE(IOPIN0,LCD_D,ch);
	IOSET0|=1<<EN;
	delay_us(1);
	IOCLR0|=1<<EN;
	delay_ms(2);
}
void Char_LCD(u8 ch)
{
	IOSET0|=1<<RS;
	WRITEBYTE(IOPIN0,LCD_D,ch);
	IOSET0|=1<<EN;
	delay_us(1);
	IOCLR0|=1<<EN;
	delay_ms(2);
}
void U32LCD(u32 n)
{
	u8 a[10];
	s32 i=0;
	if(n==0)
	{
		Char_LCD('0');
	}
	else
	{
		while(n)
		{
			a[i]=(n%10)+48;
			i++;
			n/=10;
		}
		for(--i;i>=0;i--)
		  Char_LCD(a[i]);
	}
}
void Str_lcd(u8 *p)
{
	while(*p)
		Char_LCD(*p++);
}
void Init_LCD(void)
{
	IODIR0|=0xFF<<LCD_D;
	IODIR0|=1<<RS;
	IODIR0|=1<<EN;
	IODIR0|=1<<18;
	//IOCLR0|=1<<18;
	delay_ms(15);
	CmdLCD(0x30);
	delay_ms(5);
	CmdLCD(0x30);
	delay_us(160);
	CmdLCD(0x30);
	delay_us(160);
	CmdLCD(0x38);
	CmdLCD(0x01);
	CmdLCD(0x06);
	CmdLCD(0x0f);
}

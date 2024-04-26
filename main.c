#include <lpc21xx.h>
#include "lcd.h"
#include "i2c_define.h"
#include "delay.h"
#define SLAVEADDR 0x50
#define EEPROMADDR 0xB0
#define EEPROMADDR1 0xA0
#define LINE2_POS0 0xc0
u8 rdat[6];
u8 var;
int main()
{
	Init_LCD();
	i2c_eeprom_bytewrite(SLAVEADDR,EEPROMADDR,'N');
	var=i2c_eeprom_randomread(SLAVEADDR,EEPROMADDR);
	Char_LCD(var);
	CmdLCD(LINE2_POS0);	
	i2c_eeprom_pagewrite(SLAVEADDR,EEPROMADDR1,(s8*)"Hello",5);
	i2c_eeprom_seqread(SLAVEADDR,EEPROMADDR1,(u8*)rdat,5);
	Str_lcd(rdat);
	while(1);
}

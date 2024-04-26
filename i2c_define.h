#ifndef _I2C_H_
#define _I2C_H_
#include "types.h"
#define SCL 2 //p0.2
#define SDA 3 //p0.3
#define I2C_EEPROM_SA 0x50

void i2cStart(void);
void i2cWrite(u8 );
void i2cAck(void);
void i2cStop(void);
void i2cReStart(void);
void i2cNAck(void);
u8 i2cRead(void);
void i2cMAck(void);
void i2c_eeprom_bytewrite(u8 ,u16 ,u8 );
u8 i2c_eeprom_randomread(u8 ,u8 );
void i2c_eeprom_pagewrite(u8 ,u16 ,s8 *,u8 );
void i2c_eeprom_seqread(u8 ,u16 ,u8 *,u8 );
#endif

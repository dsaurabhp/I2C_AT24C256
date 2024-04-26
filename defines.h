#ifndef _DEFINE_H_
#define _DEFINE_H_
//defines.h
#include "types.h"

#define READWRITEBIT(WORD,DBIT,SBIT) \
        WORD=((WORD&~(1<<DBIT))| \
				     (((WORD>>SBIT)&1)<<DBIT))

#define READWRITEBIT2(DWORD,DBIT,SWORD,SBIT) \
        DWORD=((DWORD&~(1<<DBIT))| \
				      (((SWORD>>SBIT)&1)<<DBIT))

#define SETBIT(WORD,BIT) (WORD|=1<<BIT)
#define SSETBIT(WORD,BIT) (WORD=1<<BIT)
#define SCLRBIT SSETBIT

#define CLRBIT(WORD,BIT) (WORD&=~(1<<BIT))
#define CPLBIT(WORD,BIT) (WORD^=1<<BIT)
#define READBIT(WORD,BIT) ((WORD>>BIT)&1)
#define WRITEBIT(WORD,BITPOS,BIT) \
        WORD=((WORD&=(~(1<<BITPOS)))| \
				     (BIT<<BITPOS))

#define WRITEBYTE(WORD,STARTBITPOS,BYTE) \
        WORD=((WORD&=(~(0xFF<<STARTBITPOS)))| \
				     (BYTE<<STARTBITPOS))

#define WRITENIBBLE(WORD,STARTBITPOS,NIBBLE) \
        WORD=((WORD&=(~(15<<STARTBITPOS)))| \
				     (NIBBLE<<STARTBITPOS))

#define READNIBBLE(WORD,STARTBITPOS) \
        ((WORD>>STARTBITPOS)&15)
#endif

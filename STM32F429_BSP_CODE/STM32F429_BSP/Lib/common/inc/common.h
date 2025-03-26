#ifndef __COMMON_H
#define __COMMON_H
#include "includes.h"



#define REV8(x)         ((((x)>>7)&1)+((((x)>>6)&1)<<1)+((((x)>>5)&1)<<2)+((((x)>>4)&1)<<3)+((((x)>>3)&1)<<4)+((((x)>>2)&1)<<5)+((((x)>>1)&1)<<6)+(((x)&1)<<7))   
#define REV16(x)        (rev8 (x)+(rev8 (x>> 8)<< 8))   
#define REV32(x)        (rev16(x)+(rev16(x>>16)<<16))   



#define BIT(x)  			(1<<x)
#define STE_BIT(x,b)  do{x |=  BIT(b);}while(0)
#define CLR_BIT(x,b)  do{x &= ~BIT(b);}while(0)
#define REV_BIT(x,b)  do{x ^=  BIT(b);}while(0)
#define GET_BIT(x,b)  ((x>>b)&0x1)


#define N_BIT1(x)			(BIT(x)-1)
#define BITS_SET(x,s,n,v)	do{x= (x&(~(N_BIT1(n)<<s)))|(v<<s);}while(0)



int odd_check(u8 *buf, u8 len);
int even_check(u8 *buf, u8 len);
int my_memset(u8 *buf, u8 dat,u32 len);
void my_memcpy(u8 *tar, const u8 *src, u32 len);
int my_memcmp(const u8 *tar, const u8 *src,u32 len);



u32 bytes_to_dat32(u8* src, u8 len);
u64 bytes_to_dat64(u8* src, u8 len);



u8 calCRC_16(u16 initval, u8 *data, u8 len, u16 *crc, u8 *crc_buf);



#endif








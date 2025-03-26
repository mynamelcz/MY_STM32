#include "common.h"


#define true	1
#define false 0






// 8bit odd check
u8 odd_parity(u8 bt)
{
  // cf http://graphics.stanford.edu/~seander/bithacks.html#ParityParallel
  return (0x9669 >> ((bt ^(bt >> 4)) & 0xF)) & 1;
}



const u8 CHECK_BITS_TAB[16] = { 0, 1, 1, 2, 1, 2, 2, 3, 
								1, 2, 2, 3, 2, 3, 3, 4};
int odd_check(u8 *buf, u8 len)
{
    u8 i,bit1_num = 0;
    for(i = 0; i<len; i++){
        bit1_num += CHECK_BITS_TAB[buf[i] >>4];
        bit1_num += CHECK_BITS_TAB[buf[i]&0xf];
    }
    if(bit1_num & 0x1)
        return true;
    return false;
}
int even_check(u8 *buf, u8 len)
{
    u8 i,bit1_num = 0;
    for(i = 0; i<len; i++){
        bit1_num += CHECK_BITS_TAB[buf[i] >>4];
        bit1_num += CHECK_BITS_TAB[buf[i]&0xf];
    }
    if(bit1_num & 0x1)
        return false;
    return true;
}
int my_memset(u8 *buf, u8 dat,u32 len)
{
	u32 L = 0;
	if((len == 0)||(buf == NULL))
		return 0;
	do{
		*buf++ = dat;
	}while((buf!=NULL) && (len != (++L)));
	return L;
}
void my_memcpy(u8 *tar, const u8 *src, u32 len)
{
	ASSERT(tar);
	ASSERT(src);
	while(len--)
		*tar++ = *src++;
}

int my_memcmp(const u8 *tar, const u8 *src,u32 len)
{
	ASSERT(tar);
	ASSERT(src);
	while(len--)
	{
		if(*tar++ != *src++)
		{
			return 0;
		}
	}
	return 1;
}

u32 bytes_to_dat32(u8* src, u8 len)
{
	u32 num = 0;
	while ((len--) && src)
	{
		num = (num << 8) | (*src);
		src++;
	}
	return num;
}


u64 bytes_to_dat64(u8* src, u8 len)
{
	u64 num = 0;
	while ((len--) && src)
	{
		num = (num << 8) | (*src);
		src++;
	}
	return num;
}




u8 calCRC_16(u16 initval, u8 *data, u8 len, u16 *crc, u8 *crc_buf)
{
    u8  bt;
    u32 wCrc = initval;//0x6363;
    u8 crc_h,crc_l = 0;
    do {
	bt = *data++;
	bt = (bt ^ (u8)(wCrc & 0x00FF));
	bt = (bt ^ (bt << 4));
	wCrc = (wCrc >> 8) ^ ((u32) bt << 8) ^ ((u32) bt << 3) ^ ((u32) bt >> 4);
    } while (--len);

	crc_l = (u8)(wCrc & 0xFF);
	crc_h = (u8)((wCrc >> 8) & 0xFF);
	if(crc){
		*crc  = (u16)crc_h<<8;
		*crc += crc_l;
	}
	if(crc_buf){
		crc_buf[0] = (u8)(wCrc & 0xFF);
		crc_buf[1] = (u8)((wCrc >> 8) & 0xFF);
	}
	return 0;
}
















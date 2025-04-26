#include "soft_iic_drv.h"
#include "eeprom.h"
#define IIC_ADDR    0xA0



#define IIC_PORT_HD     &iic_h45_port_hd


void eep_write_byte(u16 addr, u8 data)
{
    SF_IIC_Drv.w_reg_a8(IIC_PORT_HD,IIC_ADDR,addr,data);
    TimeDelay.delay_ms(8);
}

u8 eep_read_byte(u16 addr)
{
    u8 data = 0;
    SF_IIC_Drv.r_reg_a8(IIC_PORT_HD,IIC_ADDR,addr,&data);
    return data;
}







void eep_write(u16 addr, u8 *buf, u8 len)
{
    
    while (len--)
    {
        eep_write_byte(addr,*buf);
        addr++;
        buf++;
    }
}

void eep_read(u16 addr, u8 *buf, u8 len)
{
    while (len--)
    {
        *buf++ = eep_read_byte(addr++);
    }
}






void eep_test(void)
{
    u8 rbuf[32];
    u8 wbuf[32];
    
    eep_read(0,rbuf,32);
    LOG_HEX("R:",rbuf,32);
    for(int i = 0; i < 32; i++)
    {
        rbuf[i] = 0;
        wbuf[i] = i;
    }
    eep_write(0,wbuf,32);
    eep_read(0,rbuf,32);

    LOG_HEX("R:",rbuf,32);
}













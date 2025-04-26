#include "soft_iic_drv.h"

static u32 iic_delayus_g = 10;






static void iic_start(soft_iic_port_hd_t *hd)
{
	hd->SDA_OUT();
	hd->SDA_WRITE(1);
	hd->delay_us(iic_delayus_g);
	hd->CLK(1);
	hd->delay_us(iic_delayus_g);
	hd->SDA_WRITE(0);
	hd->delay_us(iic_delayus_g);
	hd->CLK(0);
}

static void iic_stop(soft_iic_port_hd_t *hd)
{
	hd->SDA_OUT();
	hd->CLK(0);
	hd->SDA_WRITE(0);
	hd->CLK(1);
	hd->delay_us(iic_delayus_g);
	hd->SDA_WRITE(1);
	hd->delay_us(iic_delayus_g);
}



static u8 iic_wait_ack(soft_iic_port_hd_t *hd)
{
	u8 time_cnt = 0;
	hd->SDA_IN();
	hd->delay_us(iic_delayus_g);
    hd->CLK(1);
	while(hd->SDA_READ()){
		if(time_cnt++ > 5){
			hd->CLK(0);
			iic_stop(hd);
			return IIC_NARCK;
		}
		hd->delay_us(iic_delayus_g/2);
	}
	hd->delay_us(iic_delayus_g);
	hd->CLK(0);
	return IIC_ARCK;
}


static u8 iic_write_byte(soft_iic_port_hd_t *hd, u8 dat)
{
	signed char i;
	hd->SDA_OUT();
	
    for (i = 7; i >= 0; i--)
    {
        hd->CLK(0);
		hd->SDA_WRITE((dat>>i)&0x1);
        hd->delay_us(iic_delayus_g);
		hd->CLK(1);
        hd->delay_us(iic_delayus_g);
    }
	hd->CLK(0);
	return iic_wait_ack(hd);
}


static u8 iic_read_byte(soft_iic_port_hd_t *hd, u8 ack)
{
	u8 i,rdat = 0;
	hd->SDA_IN();
    for (i = 0; i < 8; i++)
    {
		rdat <<= 1;
        hd->CLK(0);
        hd->delay_us(iic_delayus_g);
		hd->CLK(1);
		if(hd->SDA_READ())
			rdat |= 1;
        hd->delay_us(iic_delayus_g);
    }	
	if(ack){
		hd->CLK(0);
		hd->delay_us(iic_delayus_g);
		hd->SDA_OUT();
		hd->SDA_WRITE(0);
		hd->delay_us(iic_delayus_g);		
		hd->CLK(1);
		hd->delay_us(iic_delayus_g);
		hd->CLK(0);
	}else{
		hd->CLK(0);
		hd->delay_us(iic_delayus_g);
		hd->SDA_OUT();
		hd->SDA_WRITE(1);
		hd->delay_us(iic_delayus_g);		
		hd->CLK(1);
		hd->delay_us(iic_delayus_g);
		hd->CLK(0);
	}
	
	
	return rdat;
};



static u8 iic_write_reg(soft_iic_port_hd_t *hd, u8 addr, u8 reg, u8 dat)
{
	iic_start(hd);
	
	if(iic_write_byte(hd, addr&0xfe) == IIC_NARCK)
		return IIC_ARCK_ERR;
	if(iic_write_byte(hd, reg) == IIC_NARCK)
		return IIC_ARCK_ERR;
	if(iic_write_byte(hd, dat) == IIC_NARCK)
		return IIC_ARCK_ERR;
	
	iic_stop(hd);
	return IIC_NO_ERR;
}

static u8 iic_read_reg(soft_iic_port_hd_t *hd, u8 addr, u8 reg, u8 *rdat)
{

	iic_start(hd);
	
	if(iic_write_byte(hd, addr&0xfe) == IIC_NARCK)
		return IIC_ARCK_ERR;
	if(iic_write_byte(hd, reg) == IIC_NARCK)
		return IIC_ARCK_ERR;
//	iic_stop(hd);
	
	iic_start(hd);
	if(iic_write_byte(hd, addr|0x1) == IIC_NARCK)
		return IIC_ARCK_ERR;	
	*rdat = iic_read_byte(hd, 0);
	iic_stop(hd);
	return IIC_NO_ERR;
}


static u8 iic_write_reg_a16(soft_iic_port_hd_t *hd, u8 addr, u16 reg, u8 dat)
{
	iic_start(hd);
	
	if(iic_write_byte(hd, addr&0xfe) == IIC_NARCK)
		return IIC_ARCK_ERR;
	if(iic_write_byte(hd, (reg>>8)&0xff) == IIC_NARCK)
		return IIC_ARCK_ERR;
    if(iic_write_byte(hd, (reg>>0)&0xff) == IIC_NARCK)
		return IIC_ARCK_ERR;
	if(iic_write_byte(hd, dat) == IIC_NARCK)
		return IIC_ARCK_ERR;
	
	iic_stop(hd);
	return IIC_NO_ERR;
}

static u8 iic_read_reg_a16(soft_iic_port_hd_t *hd, u8 addr, u16 reg, u8 *rdat)
{

	iic_start(hd);
	
	if(iic_write_byte(hd, addr&0xfe) == IIC_NARCK)
		return IIC_ARCK_ERR;
	if(iic_write_byte(hd, (reg>>8)&0xff) == IIC_NARCK)
		return IIC_ARCK_ERR;
    if(iic_write_byte(hd, (reg>>0)&0xff) == IIC_NARCK)
		return IIC_ARCK_ERR;
//	iic_stop(hd);
	
	iic_start(hd);
	if(iic_write_byte(hd, addr|0x1) == IIC_NARCK)
		return IIC_ARCK_ERR;	
	*rdat = iic_read_byte(hd, 0);
	iic_stop(hd);
	return IIC_NO_ERR;
}

static u8 iic_write_buf(soft_iic_port_hd_t *hd, u8 addr, u8 addr_start, u8 *buf, u16 len)
{
//	u32 i = 0;
//	iic_start(hd);
//	if(iic_write_byte(hd, addr&0xfe) == IIC_NARCK)
//		return IIC_ARCK_ERR;
//	if(iic_write_byte(hd, addr_start) == IIC_NARCK)
//		return IIC_ARCK_ERR;
//	
//	for(i = 0; i < len; i++){
//		if(iic_write_byte(hd, buf[i]) == IIC_NARCK)
//			return IIC_ARCK_ERR;
//	}
//	iic_stop(hd);
//	return IIC_NO_ERR;
}

static u8 iic_read_buf(soft_iic_port_hd_t *hd, u8 addr, u8 addr_start, u8 *buf, u16 len)
{
//	u32 i = 0;
//	iic_start(hd);
//	
//	if(iic_write_byte(hd, addr&0xfe) == IIC_NARCK)
//		return IIC_ARCK_ERR;
//	if(iic_write_byte(hd, addr_start) == IIC_NARCK)
//		return IIC_ARCK_ERR;
//	
//	for(i = 0; i < len-1; i++){
//		buf[i] = iic_read_byte(hd, 1);
//	}
//	buf[len-1] = iic_read_byte(hd, 0);
//	iic_stop(hd);
//	return IIC_NO_ERR;
}

static u8 iic_write_buf_a16(soft_iic_port_hd_t *hd, u8 w_addr, u16 addr_start, u8 *buf, u16 len)
{
//	u32 i = 0;
//	iic_start(hd);
//	if(iic_write_byte(hd, w_addr) == IIC_NARCK)
//		return IIC_ARCK_ERR;
//	if(iic_write_byte(hd, (addr_start>>8)&0xff) == IIC_NARCK)
//		return IIC_ARCK_ERR;
//    if(iic_write_byte(hd, (addr_start>>0)&0xff) == IIC_NARCK)
//		return IIC_ARCK_ERR;
//	for(i = 0; i < len; i++){
//		if(iic_write_byte(hd, buf[i]) == IIC_NARCK)
//			return IIC_ARCK_ERR;
//	}
//	iic_stop(hd);
//	return IIC_NO_ERR;
}

static u8 iic_read_buf_a16(soft_iic_port_hd_t *hd, u8 r_addr, u16 addr_start, u8 *buf, u16 len)
{
//	u32 i = 0;
//	iic_start(hd);
//	
//	if(iic_write_byte(hd, r_addr) == IIC_NARCK)
//		return IIC_ARCK_ERR;
//	if(iic_write_byte(hd, (addr_start>>8)&0xff) == IIC_NARCK)
//		return IIC_ARCK_ERR;
//    if(iic_write_byte(hd, (addr_start>>0)&0xff) == IIC_NARCK)
//		return IIC_ARCK_ERR;
//	
//	for(i = 0; i < len-1; i++){
//		buf[i] = iic_read_byte(hd, 1);
//	}
//	buf[len-1] = iic_read_byte(hd, 0);
//	iic_stop(hd);
//	return IIC_NO_ERR;
}

static void set_clk_delay(uint32_t cnt_us)
{
    iic_delayus_g = cnt_us;
}





const soft_iic_drv_t SF_IIC_Drv = {
	.w_reg_a8	=   iic_write_reg,
	.r_reg_a8 	=  	iic_read_reg,
    .w_reg_a16	=   iic_write_reg_a16,
	.r_reg_a16 	=  	iic_read_reg_a16,
	.write_a8	=	iic_write_buf,
	.read_a8	=	iic_read_buf,
	.write_a16	=	iic_write_buf_a16,
	.read_a16	=	iic_read_buf_a16,
	.set_clk_delay =   set_clk_delay,
};










void iic_h45_sda_in(void)
{
    IIC_SDA_IN_MODE();
}
void iic_h45_sda_out(void)
{
    IIC_SDA_OUT_MODE();
}

void iic_h45_sda_write(u8 en)
{
    IIC_SDA(en);
}

u8 iic_h45_sda_read(void)
{
    if(IIC_SDA_R())
    {
        return 1;
    }
    return 0;
}

void iic_h45_clk(u8 en)
{
    IIC_SCL(en);
}

void iic_delay_us(u32 cnt)
{
    TimeDelay.delay_us(cnt);
}

soft_iic_port_hd_t iic_h45_port_hd = 
{
    .SDA_IN = iic_h45_sda_in,
    .SDA_OUT = iic_h45_sda_out,
    .SDA_WRITE = iic_h45_sda_write,
    .SDA_READ = iic_h45_sda_read,
    .CLK = iic_h45_clk,
    .delay_us = iic_delay_us,
};




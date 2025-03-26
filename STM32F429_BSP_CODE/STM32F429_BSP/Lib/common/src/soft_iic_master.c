#include "soft_iic_master.h"

static u32 iic_delayus_g = 1;






static void iic_start(Soft_IIC_hd *hd)
{
	hd->SDA_Dir(IIC_SDA_OUT);
	
	hd->SDA_Out(1);
	hd->delay_us(iic_delayus_g);
	hd->CLK(1);
	hd->delay_us(iic_delayus_g);
	hd->SDA_Out(0);
	hd->delay_us(iic_delayus_g);
	hd->CLK(0);
}

static void iic_stop(Soft_IIC_hd *hd)
{
	hd->SDA_Dir(IIC_SDA_OUT);
	hd->CLK(0);
	hd->SDA_Out(0);
	
	hd->CLK(1);
	hd->delay_us(iic_delayus_g);
	hd->SDA_Out(1);
	hd->delay_us(iic_delayus_g);
}



static u8 iic_wait_ack(Soft_IIC_hd *hd)
{
	u8 time_cnt = 0;
	hd->SDA_Dir(IIC_SDA_IN);
	hd->delay_us(iic_delayus_g);
    hd->CLK(1);
	while(hd->SDA_In()){
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


static u8 iic_write_byte(Soft_IIC_hd *hd, u8 dat)
{
	signed char i;
	hd->SDA_Dir(IIC_SDA_OUT);
	
    for (i = 7; i >= 0; i--)
    {
        hd->CLK(0);
		hd->SDA_Out((dat>>i)&0x1);
        hd->delay_us(iic_delayus_g);
		hd->CLK(1);
        hd->delay_us(iic_delayus_g);
    }
	hd->CLK(0);
	return iic_wait_ack(hd);
}


static u8 iic_read_byte(Soft_IIC_hd *hd, u8 ack)
{
	u8 i,rdat = 0;
	hd->SDA_Dir(IIC_SDA_IN);
    for (i = 0; i < 8; i++)
    {
		rdat <<= 1;
        hd->CLK(0);
        hd->delay_us(iic_delayus_g);
		hd->CLK(1);
		if(hd->SDA_In())
			rdat |= 1;
        hd->delay_us(iic_delayus_g);
    }	
	if(ack){
		hd->CLK(0);
		hd->delay_us(iic_delayus_g);
		hd->SDA_Dir(IIC_SDA_OUT);
		hd->SDA_Out(0);
		hd->delay_us(iic_delayus_g);		
		hd->CLK(1);
		hd->delay_us(iic_delayus_g);
		hd->CLK(0);
	}else{
		hd->CLK(0);
		hd->delay_us(iic_delayus_g);
		hd->SDA_Dir(IIC_SDA_OUT);
		hd->SDA_Out(1);
		hd->delay_us(iic_delayus_g);		
		hd->CLK(1);
		hd->delay_us(iic_delayus_g);
		hd->CLK(0);
	}
	
	
	return rdat;
};



static u8 iic_write_reg(Soft_IIC_hd *hd, u8 addr, u8 reg, u8 dat)
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

static u8 iic_read_reg(Soft_IIC_hd *hd, u8 addr, u8 reg, u8 *rdat)
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

static u8 iic_write_buf(Soft_IIC_hd *hd, u8 w_addr, u8 addr_start, u8 *buf, u16 len)
{
	u32 i = 0;
	iic_start(hd);
	if(iic_write_byte(hd, w_addr) == IIC_NARCK)
		return IIC_ARCK_ERR;
	if(iic_write_byte(hd, addr_start) == IIC_NARCK)
		return IIC_ARCK_ERR;
	
	for(i = 0; i < len; i++){
		if(iic_write_byte(hd, buf[i]) == IIC_NARCK)
			return IIC_ARCK_ERR;
	}
	
	
	iic_stop(hd);
	return IIC_NO_ERR;
}

static u8 iic_read_buf(Soft_IIC_hd *hd, u8 r_addr, u8 addr_start, u8 *buf, u16 len)
{
	u32 i = 0;
	iic_start(hd);
	
	if(iic_write_byte(hd, r_addr) == IIC_NARCK)
		return IIC_ARCK_ERR;
	if(iic_write_byte(hd, addr_start) == IIC_NARCK)
		return IIC_ARCK_ERR;
	
	for(i = 0; i < len-1; i++){
		buf[i] = iic_read_byte(hd, 1);
	}
	buf[len-1] = iic_read_byte(hd, 0);
	iic_stop(hd);
	return IIC_NO_ERR;
}



static u8 iic_ioctr(Soft_IIC_hd *hd, u8 cmd, void *buf)
{
	u8 res = 0;
	
	switch(cmd){
		case IIC_CMD_SPEED_LOW:
			iic_delayus_g = 1000;
			break;
		case IIC_CMD_SPEED_HIGH:
			iic_delayus_g = 5;
			break;
		default:
			res = 1;
			break;
	}
	return res;
}





const Soft_IIC_io_t SF_IIC_Drv = {
	.w_reg	=   iic_write_reg,
	.r_reg 	=  	iic_read_reg,
	.write	=	iic_write_buf,
	.read	=	iic_read_buf,
	.ioctrl =   iic_ioctr,
};

















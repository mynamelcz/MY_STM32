#ifndef __SOFT_IIC_MASTER_H
#define __SOFT_IIC_MASTER_H

#include "includes.h"


#define IIC_SDA_IN		1
#define IIC_SDA_OUT		0

#define IIC_ARCK	0
#define IIC_NARCK	1

enum IIC_STATE{
	IIC_NO_ERR,
	IIC_ARCK_ERR,
	
};
enum SOFT_IIC_IO_CMD{
	IIC_CMD_SPEED_LOW,
	IIC_CMD_SPEED_HIGH,
	
};
typedef struct __Soft_IIC_hd {
	void (*init)(void);
	void (*SDA_Dir)(u8 dir);
	void (*SDA_Out)(u8 en);
	u8  (*SDA_In)(void);
	void (*CLK)(u8 en);	
	void (*delay_us)(u32 us);
}const Soft_IIC_hd;


typedef struct __Soft_IIC_IO_Type{
	u8 (*w_reg)(Soft_IIC_hd *hd, u8 iic_w_addr, u8 reg, u8 dat);
	u8 (*r_reg)(Soft_IIC_hd *hd, u8 r_addr, u8 reg, u8 *rdat);
	u8 (*write)(Soft_IIC_hd *hd, u8 w_addr, u8 addr_start, u8 *buf, u16 len);
	u8 (*read)(Soft_IIC_hd *hd, u8 r_addr, u8 addr_start, u8 *buf, u16 len);
	u8 (*ioctrl)(Soft_IIC_hd *hd, u8 cmd, void *buf);
} const Soft_IIC_io_t;






extern const Soft_IIC_io_t SF_IIC_Drv;


#endif







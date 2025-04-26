#ifndef __SOFT_IIC_MASTER_H
#define __SOFT_IIC_MASTER_H

#include "includes.h"
#include "stm32f4xx.h"
#include "bsp_gpio.h"
#include "bsp_uart.h"
#include "bsp_sys.h"
#include "bsp_nvic.h"

#include "time_delay.h"



#define IIC_ARCK	    0
#define IIC_NARCK	    1

enum IIC_STATE{
	IIC_NO_ERR,
	IIC_ARCK_ERR,
};
enum SOFT_IIC_IO_CMD{
	IIC_CMD_SPEED_LOW,
	IIC_CMD_SPEED_HIGH,
	
};
typedef struct __Soft_IIC_hd {
	void (*SDA_IN)(void);
	void (*SDA_OUT)(void);
	void (*SDA_WRITE)(u8 en);
	u8  (*SDA_READ)(void);
	void (*CLK)(u8 en);	
	void (*delay_us)(u32 us);
}const soft_iic_port_hd_t;


typedef struct __Soft_IIC_IO_Type{
	u8 (*w_reg_a8)(soft_iic_port_hd_t *hd, u8 w_addr, u8 reg, u8 dat);
	u8 (*r_reg_a8)(soft_iic_port_hd_t *hd, u8 r_addr, u8 reg, u8 *rdat);
	u8 (*w_reg_a16)(soft_iic_port_hd_t *hd, u8 w_addr, u16 reg, u8 dat);
	u8 (*r_reg_a16)(soft_iic_port_hd_t *hd, u8 r_addr, u16 reg, u8 *rdat);
	u8 (*write_a8)(soft_iic_port_hd_t *hd, u8 w_addr, u8 addr_start, u8 *buf, u16 len);
	u8 (*read_a8)(soft_iic_port_hd_t *hd, u8 r_addr, u8 addr_start, u8 *buf, u16 len);
	u8 (*write_a16)(soft_iic_port_hd_t *hd, u8 w_addr, u16 addr_start, u8 *buf, u16 len);
	u8 (*read_a16)(soft_iic_port_hd_t *hd, u8 r_addr, u16 addr_start, u8 *buf, u16 len);
	void (*set_clk_delay)(uint32_t cnt);
} const soft_iic_drv_t;





extern soft_iic_port_hd_t iic_h45_port_hd;
extern const soft_iic_drv_t SF_IIC_Drv;


#endif







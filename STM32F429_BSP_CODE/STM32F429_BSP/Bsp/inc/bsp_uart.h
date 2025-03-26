#ifndef __BSP_UART_H
#define __BSP_UART_H

#include "stdio.h"
#include "includes.h"
#include "stm32f4xx.h"
#include "bsp_uart_cfg.h"
#include "stm32f4xx_ll_usart.h"

#ifdef __USING_BSP_UART_DRV



/* stm32 config class */
struct stm32_uart_config
{
    USART_TypeDef 			    *Instance;
	LL_USART_InitTypeDef   	    config;
	LL_USART_ClockInitTypeDef   clk_cfg;
};








enum
{
#ifdef BSP_USING_UART1
    UART1_INDEX,
#endif
#ifdef BSP_USING_UART2
    UART2_INDEX,
#endif
#ifdef BSP_USING_UART3
    UART3_INDEX,
#endif
#ifdef BSP_USING_UART4
    UART4_INDEX,
#endif
#ifdef BSP_USING_UART5
    UART5_INDEX,
#endif
#ifdef BSP_USING_UART6
    UART6_INDEX,
#endif
	UART_INDEX_MAX,
};



struct __bsp_uart_drv{
	int (*init)(u8 index);
	int (*cfg_clk)(u8 index);
	int (*deinit)(u8 index);
	int (*open)(u8 index);
	int (*close)(u8 index);
	int (*enable_it)(u8 index, u16 source);
	int (*diable_it)(u8 index, u16 source);	
	int (*enable_dma)(u8 index, u16 dma_req);
	int (*disable_dma)(u8 index, u16 dma_req);		
	int (*read)(u8 index, u8 *buf, u32 len);
	int (*write)(u8 index,  u8 *buf, u32 len);
	int (*w_byte)(u8 index, u8 dat);	
	int (*r_byte)(u8 index);	
};

extern const struct __bsp_uart_drv BSP_UART_DRV;



#endif


#endif





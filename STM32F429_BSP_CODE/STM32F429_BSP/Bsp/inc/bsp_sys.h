#ifndef __BSP_SYS_H__
#define __BSP_SYS_H__

#include "includes.h"




typedef enum {
	MCO1_OUT_HSI = 0x00,
	MCO1_OUT_LSE = 0x01,
	MCO1_OUT_HSE = 0x02,
	MCO1_OUT_PLL = 0x03,
}MCO1_t;
typedef enum {
	MCO2_OUT_SYS = 0x00,
	MCO2_OUT_PLLI2S = 0x01,
	MCO2_OUT_HSE = 0x02,
	MCO2_OUT_PLL = 0x03,
}MCO2_t;

typedef enum {
	MCOx_PRE0 = 0,
	MCOx_PRE2 = 4,
	MCOx_PRE3 = 5,
	MCOx_PRE4 = 6,
	MCOx_PRE5 = 7,
}MCOxDev_t;

struct __bsp_sys{
	void (*init)(void);
	u32 (*get_randnum)(void);
	void (*start_iwdt)(void);
	void (*clear_iwdt)(void);
};

extern const struct __bsp_sys	BSP_Sys;

void cfg_mco1_mco2(MCO1_t mco1, MCOxDev_t pre1, MCO2_t mco2, MCOxDev_t pre2);

#endif






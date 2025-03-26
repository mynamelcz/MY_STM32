#ifndef __BSP_NVIC_H__
#define __BSP_NVIC_H__
#include "includes.h"







typedef void (*irq_fun_t)(void);

typedef struct __bsp_nvic{
	void (*init)(void);
	void (*enable_irq)(u8 IRQChannel, u8 PreemptionPriority, u8 SubPriority);
	void (*disable_irq)(u8 IRQChannel);
	void (*attach_fun)(u8 IRQChannel, irq_fun_t fun);
	void (*detach_fun)(u8 IRQChannel);		
}bsp_nvic_t;
extern const bsp_nvic_t BSP_NVIC_DRV;






#endif

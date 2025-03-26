#ifndef __BSP_NVIC_H__
#define __BSP_NVIC_H__
#include "includes.h"
#include "stm32f4xx.h"







typedef void (*irq_fun_t)(void);

typedef struct __bsp_nvic{
	void (*init)(void);
	void (*enable_irq)(IRQn_Type IRQn, uint32_t PreemptionPriority, uint32_t SubPriority);
	void (*disable_irq)(IRQn_Type IRQn);
	void (*attach_fun)(IRQn_Type IRQn, irq_fun_t fun);
	void (*detach_fun)(IRQn_Type IRQn);		
}bsp_nvic_t;
extern const bsp_nvic_t BSP_NVIC_DRV;






#endif

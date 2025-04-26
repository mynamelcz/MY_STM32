#ifndef __BSP_LTDC_H
#define __BSP_LTDC_H





struct __bsp_ltdc_drv{
	void(*ltdc_init)(void);

};

extern const struct __bsp_ltdc_drv	BSP_LTDC_DRV;

#endif



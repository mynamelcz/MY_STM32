#ifndef __BSP_FMC_H
#define __BSP_FMC_H



void fmc_lcd_init(void);


struct __bsp_fmc_drv{
	void(*lcd_init)(void);
	void(*sdram_init)(void);

};

extern const struct __bsp_fmc_drv	BSP_FMC_DRV;

#endif



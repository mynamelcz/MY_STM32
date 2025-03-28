#ifndef	__BSP_GPIO_H
#define	__BSP_GPIO_H
#include "includes.h"
#include "stm32f4xx.h"
#include "stm32f4xx_ll_gpio.h"


#define PIN_LOW                 0x00
#define PIN_HIGH                0x01



#define __STM32_PORT(port)  GPIO##port

#define GET_PIN(PORTx,PIN_NUM) __STM32_PORT(PORTx),PIN_NUM



enum __pin_bitband_addr_e{
	PIN_BitBand_ODR_Addr,
	PIN_BitBand_IDR_Addr,
	PIN_BitBand_MODER_Addr,
};



typedef enum {
	PIN_Mode_AIN = GPIO_MODE_ANALOG,
	PIN_Mode_IN = GPIO_MODE_INPUT,
	PIN_Mode_Out_OD = GPIO_MODE_OUTPUT_OD,
	PIN_Mode_Out_PP = GPIO_MODE_OUTPUT_PP,
	PIN_Mode_AF_OD = GPIO_MODE_AF_OD,
	PIN_Mode_AF_PP = GPIO_MODE_AF_PP,
    
    PIN_Mode_IT_RISING = GPIO_MODE_IT_RISING,
    PIN_Mode_IT_FALLING = GPIO_MODE_IT_FALLING,
    PIN_Mode_IT_RISING_FALLING = GPIO_MODE_IT_RISING_FALLING,
    PIN_Mode_EVT_RISING = GPIO_MODE_EVT_RISING,
    PIN_Mode_EVT_FALLING = GPIO_MODE_EVT_FALLING,
    PIN_Mode_EVT_RISING_FALLING = GPIO_MODE_EVT_RISING_FALLING,
}PinMode_E;

typedef enum {
	PIN_NoPull = GPIO_NOPULL,
	PIN_PullUp = GPIO_PULLUP,
	PIN_PullDown = GPIO_PULLDOWN,
}PinPUPD_E;




/* STM32 GPIO driver */
struct pin_index
{
    u16 pin_num;
	u16 pin;
    GPIO_TypeDef *gpio;
    
};

/*
**位带地址转为地址别名
*/
#define BITBAND_ADDR(addr, bitnum) 	(((addr) & 0xF0000000) + 0x2000000 +(((addr) & 0xFFFFF)<<5) + ((bitnum)<<2))
#define MEM_ADDR(addr)	*(volatile unsigned long *)(addr)



struct pin_band{
	volatile u32 ODR;
	volatile u32 IDR;
	volatile u32 MODER;
};

#define PinWrite(band, x)		do{MEM_ADDR(band.ODR) = (u32)(x);}while(0)
#define PinRead(band)			MEM_ADDR(band.IDR)
#define PinInMode(band)			do{MEM_ADDR(band.MODER) = 0; MEM_ADDR(band.MODER + 4) = 0;}while(0)
#define PinOutMode(band)		do{MEM_ADDR(band.MODER) = 1; MEM_ADDR(band.MODER + 4) = 0;}while(0)

typedef void (*irq_fun_t)(void);



struct __bsp_gpio_drv{
	void(*hw_init)(void);
	void(*pin_mode)(GPIO_TypeDef *gpio,u8 pin_num, PinMode_E mode, PinPUPD_E pupd,uint32_t AF);
	void(*pin_cfgAF)(GPIO_TypeDef *gpio,u8 pin_num, u8 GPIO_AF);
	int (*pin_read)(GPIO_TypeDef *gpio,u8 pin_num);
	void(*pin_write)(GPIO_TypeDef *gpio,u8 pin_num, u8 value);
	void(*pin_tol)(GPIO_TypeDef *gpio,u8 pin_num);
	int (*pin_get_bitband)(GPIO_TypeDef *gpio,u8 pin_num, struct pin_band *band);
    
    
    void (*pin_irq_enable)(GPIO_TypeDef *gpio,u8 pin_num, void (*hdr)(void));
    void (*pin_irq_disable)(GPIO_TypeDef *gpio,u8 pin_num);
};

extern const struct __bsp_gpio_drv	BSP_GPIO_DRV;




#endif







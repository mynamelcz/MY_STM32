#ifndef __BOARD_H
#define __BOARD_H

#include "PER_PIN_MAP.h"

#define __UNUSE_PIN	0xFFFFFFFF



/* UART	*/
#define DBUG_UART					USART1


#define BSP_USING_UART1	
#define BSP_USING_UART2
#define BSP_USING_UART3	
#define BSP_USING_UART4	
#define BSP_USING_UART5	
#define BSP_USING_UART6	


#define BSP_USING_TIME1
#define BSP_USING_TIME2
#define BSP_USING_TIME3
#define BSP_USING_TIME4
#define BSP_USING_TIME5
#define BSP_USING_TIME6
#define BSP_USING_TIME7
#define BSP_USING_TIME8
#define BSP_USING_TIME9
#define BSP_USING_TIME10
#define BSP_USING_TIME11
#define BSP_USING_TIME12
#define BSP_USING_TIME13
#define BSP_USING_TIME14




#define LOOP_FUN_TIMER_INDEX    TIME7_INDEX

#ifdef BSP_USING_TIME2
#define DELAY_TIMER_INDEX		TIME2_INDEX
#define DELAY_TIMER				TIM2
#endif


//#define BSP_USING_SPI1	
#define BSP_USING_SPI2	
//#define BSP_USING_SPI3


//#define BSP_USING_DMA1_CH0
//#define BSP_USING_DMA1_CH1
//#define BSP_USING_DMA1_CH2
//#define BSP_USING_DMA1_CH3
//#define BSP_USING_DMA1_CH4
//#define BSP_USING_DMA1_CH5
//#define BSP_USING_DMA1_CH6
//#define BSP_USING_DMA1_CH7

//#define BSP_USING_DMA2_CH0
//#define BSP_USING_DMA2_CH1
//#define BSP_USING_DMA2_CH2
//#define BSP_USING_DMA2_CH3
//#define BSP_USING_DMA2_CH4
//#define BSP_USING_DMA2_CH5
//#define BSP_USING_DMA2_CH6
//#define BSP_USING_DMA2_CH7




#define BSP_USING_DAC1
#define BSP_USING_DAC2




#define __H_SPEED_SOFT_IIC
#define HS_IIC_SDA_PIN		GET_PIN(D,5)
#define HS_IIC_SCK_PIN		GET_PIN(D,7)


/*==========================================================*/
/*						Device								*/
/*==========================================================*/






extern struct pin_band TRIG1_BAND;
#define TRIG1_PIN	GET_PIN(B,1)
#define TRIG1(x)	PinWrite(TRIG1_BAND,x);


/*********************  LED **************************/
#define LED0_PIN	GET_PIN(B,1)
#define LED1_PIN	GET_PIN(B,0)
#define LED0(x)		BSP_GPIO_DRV.pin_write(LED0_PIN,!x)
#define LED1(x)		BSP_GPIO_DRV.pin_write(LED1_PIN,!x)
#define LED0_TOG()	BSP_GPIO_DRV.pin_tol(LED0_PIN)
#define LED1_TOG()	BSP_GPIO_DRV.pin_tol(LED1_PIN)

/*********************  KEY **************************/
#define KEYUP_PIN	GET_PIN(A,0)
#define KEY0_PIN	GET_PIN(H,3)
#define KEY1_PIN	GET_PIN(H,2)
#define KEY2_PIN	GET_PIN(C,13)
#define KEYUP_R()   BSP_GPIO_DRV.pin_read(KEYUP_PIN)
#define KEY0_R()   	BSP_GPIO_DRV.pin_read(KEY0_PIN)
#define KEY1_R()   	BSP_GPIO_DRV.pin_read(KEY1_PIN)
#define KEY2_R()   	BSP_GPIO_DRV.pin_read(KEY2_PIN)


extern struct pin_band TOUCHKEY_BAND;
#define TOUCH_KEY_PIN           GET_PIN(A,5)
#define TOUCH_KEY_IN_MODE()     PinInMode(TOUCHKEY_BAND)
#define TOUCH_KEY_OUT_MODE()    PinOutMode(TOUCHKEY_BAND)
#define TOUCH_KEY_R()           PinRead(TOUCHKEY_BAND)
#define TOUCH_KEY(x)            PinWrite(TOUCHKEY_BAND,x)

/*********************  IIC BUS **************************/
#define IIC_SCL_PIN     GET_PIN(H,4)
#define IIC_SDA_PIN     GET_PIN(H,5)

#define IIC_SCL(x)		    BSP_GPIO_DRV.pin_write(IIC_SCL_PIN,x)
#define IIC_SDA(x)		    BSP_GPIO_DRV.pin_write(IIC_SDA_PIN,x)
#define IIC_SDA_R()         BSP_GPIO_DRV.pin_read(IIC_SDA_PIN)
#define IIC_SDA_OUT_MODE()	BSP_GPIO_DRV.pin_mode(IIC_SDA_PIN, PIN_Mode_Out_PP, PIN_NoPull, 0)
#define IIC_SDA_IN_MODE()	BSP_GPIO_DRV.pin_mode(IIC_SDA_PIN, PIN_Mode_IN, PIN_PullUp, 0)





#endif




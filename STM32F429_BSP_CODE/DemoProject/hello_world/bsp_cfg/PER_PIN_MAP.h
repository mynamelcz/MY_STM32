#ifndef	__PER_PIN_MAP_H__ 
#define __PER_PIN_MAP_H__


/*============	TIM1 	=============
1	TIM1_ETR	PA12	PE7				
2	TIM1_BKIN	PB12	PE15	PA6			
3	TIM1_CH1N	PA7		PB13	PE8			
4	TIM1_CH2N	PB0		PB14	PE10			
5	TIM1_CH3N	PB1		PB15	PE12			
6	TIM1_CH1	PA8		PE9				
7	TIM1_CH2	PA9		PE11				
8	TIM1_CH3	PA10	PE13				
9	TIM1_CH4	PA11	PE14
 ====================================
*/
#define	TIM1_ETR_PIN	 	GET_PIN(A,12)
#define TIM1_BKIN_PIN	 	GET_PIN(B,12)
#define TIM1_CH1N_PIN	 	GET_PIN(E,8)	
#define TIM1_CH2N_PIN	 	GET_PIN(E,10)		
#define TIM1_CH3N_PIN	 	GET_PIN(E,12)			
#define TIM1_CH1_PIN	 	GET_PIN(E,9)	
#define TIM1_CH2_PIN	 	GET_PIN(E,11)		
#define TIM1_CH3_PIN	 	GET_PIN(E,13)		
#define TIM1_CH4_PIN		GET_PIN(E,14)	

/*============	TIM2 	=============
1	TIM2_ETR/CH1	PA0	PA5	PA15
2	TIM2_CH2		PA1	PB3	
3	TIM2_CH3		PA2	PB10	
4	TIM2_CH4		PA3	PB11	
 ====================================
*/
#define TIM2_CH1_ETR_PIN	GET_PIN(A,0)		
#define TIM2_CH2_PIN	 	GET_PIN(A,1)		
#define TIM2_CH3_PIN	 	GET_PIN(A,2)		
#define TIM2_CH4_PIN		GET_PIN(A,3)




/*============	TIM3 	=============
1	TIM3_CH1	PA6	PB4	PC6	
2	TIM3_CH2	PA7	PB5	PC7	
3	TIM3_CH3	PB0	PC8		
4	TIM3_CH4	PB1	PC9		
5	TIM3_ETR	PD2			
 ====================================
*/
#define	TIM3_ETR_PIN	 	GET_PIN(D,2)		
#define TIM3_CH1_PIN	 	GET_PIN(C,6)	
#define TIM3_CH2_PIN	 	GET_PIN(C,7)		
#define TIM3_CH3_PIN	 	GET_PIN(C,8)		
#define TIM3_CH4_PIN		GET_PIN(C,9)	


/*============	TIM4 	=============
1	TIM4_CH1	PB6	PD12	
2	TIM4_CH2	PB7	PD13	
3	TIM4_CH3	PB8	PD14	
4	TIM4_CH4	PB9	PD15	
5	TIM4_ETR	PE0				
 ====================================
*/
#define	TIM4_ETR_PIN	 	GET_PIN(E,0)		
#define TIM4_CH1_PIN	 	GET_PIN(B,6)	
#define TIM4_CH2_PIN	 	GET_PIN(B,7)		
#define TIM4_CH3_PIN	 	GET_PIN(B,8)		
#define TIM4_CH4_PIN		GET_PIN(B,9)	



/*============	TIM5 	=============
1	TIM5_CH1	PA0	PH10	
2	TIM5_CH2	PA1	PH11	
3	TIM5_CH3	PA2	PH12	
4	TIM5_CH4	PA3	PI0				
 ====================================
*/
#define TIM5_CH1_PIN	 	GET_PIN(A,0)	
#define TIM5_CH2_PIN	 	GET_PIN(A,1)		
#define TIM5_CH3_PIN	 	GET_PIN(A,2)		
#define TIM5_CH4_PIN		GET_PIN(A,3)	


/*============	TIM8 	=============
1	TIM8_ETR	PA0	PI3	
2	TIM8_BKIN	PA6	PI4	
3	TIM8_CH1N	PA5	PA7		PH13
4	TIM8_CH2N	PB0	PB14	PH14
5	TIM8_CH3N	PB1	PB15	PH15
6	TIM8_CH1	PC6	PI5	
7	TIM8_CH2	PC7	PI6	
8	TIM8_CH3	PC8	PI7	
9	TIM8_CH4	PC9	PI2	
 ====================================
*/
#define	TIM8_ETR_PIN	 	GET_PIN(A,0)
#define TIM8_BKIN_PIN	 	GET_PIN(A,6)
#define TIM8_CH1N_PIN	 	GET_PIN(A,5)	
#define TIM8_CH2N_PIN	 	GET_PIN(B,0)		
#define TIM8_CH3N_PIN	 	GET_PIN(B,1)			
#define TIM8_CH1_PIN	 	GET_PIN(C,6)	
#define TIM8_CH2_PIN	 	GET_PIN(C,7)		
#define TIM8_CH3_PIN	 	GET_PIN(C,8)		
#define TIM8_CH4_PIN		GET_PIN(C,9)	


/*============	TIM9 	=============
1	TIM9_CH1	PA2	PE5
2	TIM9_CH2	PA3	PE6			
 ====================================
*/
#define TIM9_CH1_PIN	 	GET_PIN(E,5)	
#define TIM9_CH2_PIN	 	GET_PIN(E,6)		
	

/*============	TIM10 	=============
1	TIM10_CH1	PB8	PF6		
 ====================================
*/
#define TIM10_CH1_PIN	 	GET_PIN(B,8)	


/*============	TIM11 	=============
1	TIM11_CH1	PB9	PF7		
 ====================================
*/
#define TIM11_CH1_PIN	 	GET_PIN(B,9)	


/*============	TIM12 	=============
1	TIM12_CH1	PB14	PH6
2	TIM12_CH2	PB15	PH9	
 ====================================
*/
#define TIM12_CH1_PIN	 	GET_PIN(B,14)	
#define TIM12_CH2_PIN	 	GET_PIN(B,15)	


/*============	TIM13 	=============
1	TIM13_CH1	PA6	PF8		
 ====================================
*/
#define TIM13_CH1_PIN	 	GET_PIN(A,6)	

/*============	TIM14 	=============
1	TIM14_CH1	PA7	PF9	
 ====================================
*/
#define TIM14_CH1_PIN	 	GET_PIN(A,7)	



/*============	UART1 	=============
1	USART1_CTS	PA11	
2	USART1_RTS	PA12	
3	USART1_TX	PA9		PB6
4	USART1_RX	PA10	PB7
5	USART1_CK	PA8	
 ====================================
*/
#define UART1_CTS_PIN	GET_PIN(A,11)
#define UART1_RTS_PIN	GET_PIN(A,12)
#define UART1_TX_PIN	GET_PIN(A,9)
#define UART1_RX_PIN	GET_PIN(A,10)
#define UART1_CK_PIN	GET_PIN(A,8)



/*============	UART2 	=============
1	USART2_CTS	PA0	PD3	
2	USART2_RTS	PA1	PD4	
3	USART2_TX	PA2	PD5	
4	USART2_RX	PA3	PD6	
5	USART2_CK	PA4	PD7	
 ====================================
*/
#define UART2_CTS_PIN	GET_PIN(A,0)
#define UART2_RTS_PIN	GET_PIN(A,1)
#define UART2_TX_PIN	GET_PIN(A,2)
#define UART2_RX_PIN	GET_PIN(A,3)
#define UART2_CK_PIN	GET_PIN(A,4)


/*============	UART3 	=============
1	USART3_CTS	PB13			PD11
2	USART3_RTS	PB14			PD12
3	USART3_TX	PB10	PC10	PD8
4	USART3_RX	PB11	PC11	PD9
5	USART3_CK	PB12	PC12	PD10
 ====================================
*/
#define UART3_CTS_PIN	GET_PIN(D,11)
#define UART3_RTS_PIN	GET_PIN(D,12)
#define UART3_TX_PIN	GET_PIN(D,8)
#define UART3_RX_PIN	GET_PIN(D,9)
#define UART3_CK_PIN	GET_PIN(D,10)


/*============	UART4 	=============
1	UART4_TX	PA0	PC10
2	UART4_RX	PA1	PC11
 ====================================
*/
#define UART4_TX_PIN	GET_PIN(C,10)
#define UART4_RX_PIN	GET_PIN(C,11)

/*============	UART5 	=============
1	UART5_TX	PC12
2	UART5_RX	PD2
 ====================================
*/
#define UART5_TX_PIN	GET_PIN(C,12)
#define UART5_RX_PIN	GET_PIN(D,2)


/*============	UART6 	=============
1	USART6_CTS	PG13	PG15
2	USART6_RTS	PG12	PG8
3	USART6_TX	PC6		PG14
4	USART6_RX	PC7		PG9
5	USART6_CK	PC8		PG7
 ====================================
*/
#define UART6_CTS_PIN	GET_PIN(G,13)
#define UART6_RTS_PIN	GET_PIN(G,12)
#define UART6_TX_PIN	GET_PIN(C,6)
#define UART6_RX_PIN	GET_PIN(C,7)
#define UART6_CK_PIN	GET_PIN(C,8)



/*============	CAN1 	=============
1	CAN1_RX		PA11 PB8 PD0 PI9
2	CAN1_TX		PA12 PB9 PD1 PH13
 ====================================
*/
#define CAN1_RX_PIN		GET_PIN(B,8)
#define CAN1_TX_PIN		GET_PIN(B,9)


/*============	CAN2 	=============
1	CAN2_RX		PB5	PB12
2	CAN2_TX		PB6	PB13
 ====================================
*/
#define CAN2_RX_PIN		GET_PIN(B,5)
#define CAN2_TX_PIN		GET_PIN(B,6)





/*============	SPI1 	=============
1	SPI1_NSS	PA4	PA15
2	SPI1_SCLK	PA5	PB3
3	SPI1_MISO	PA6	PB4
4	SPI1_MOSI	PA7	PB5
 ====================================
*/
#define SPI1_NSS_PIN		GET_PIN(A,4)
#define SPI1_SCLK_PIN		GET_PIN(A,5)
#define SPI1_MISO_PIN		GET_PIN(A,6)
#define SPI1_MOSI_PIN		GET_PIN(A,7)


/*============	SPI2 	=============
1	SPI2_NSS	PB9		PB12	PI0
2	SPI2_SCLK	PB10	PB13	PI1
3	SPI2_MISO	PB14	PC2		PI2
4	SPI2_MOSI	PB15	PC3		PI3
 ====================================
*/
#define SPI2_NSS_PIN		GET_PIN(B,9)
#define SPI2_SCLK_PIN		GET_PIN(B,10)
#define SPI2_MISO_PIN		GET_PIN(B,14)
#define SPI2_MOSI_PIN		GET_PIN(B,15)

/*============	SPI3 	=============
1	SPI3_NSS	PA4		PA15
2	SPI3_SCLK	PB3		PC10
3	SPI3_MISO	PB4		PC11
4	SPI3_MOSI	PB5		PC12
 ====================================
*/
#define SPI3_NSS_PIN		GET_PIN(A,4)
#define SPI3_SCLK_PIN		GET_PIN(B,3)
#define SPI3_MISO_PIN		GET_PIN(B,4)
#define SPI3_MOSI_PIN		GET_PIN(B,5)





/*============	IIC1 	=============
1	I2C1_SMBA	PB5				PH9
2	I2C1_SCL	PB6		PB8		PH7
3	I2C1_SDA	PB7		PB9		PH8
 ====================================
*/
#define I2C1_SMBA_PIN		GET_PIN(B,5)
#define I2C1_SCL_PIN		GET_PIN(B,6)
#define I2C1_SDA_PIN		GET_PIN(B,7)

/*============	IIC2 	=============
1	I2C2_SMBA	PB12	PF2		PH6
2	I2C2_SCL	PB10	PF1		PH4
3	I2C2_SDA	PB11	PF0		PH5
 ====================================
*/
#define I2C2_SMBA_PIN		GET_PIN(B,12)
#define I2C2_SCL_PIN		GET_PIN(B,10)
#define I2C2_SDA_PIN		GET_PIN(B,11)



/*============	IIC3 	=============
1	I2C3_SMBA	PB12		
2	I2C3_SCL	PB10	PA8
3	I2C3_SDA	PC9		PA9
 ====================================
*/
#define I2C3_SMBA_PIN		GET_PIN(B,12)
#define I2C3_SCL_PIN		GET_PIN(B,10)
#define I2C3_SDA_PIN		GET_PIN(C,9)
#endif






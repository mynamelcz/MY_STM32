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



/*============	FMC 	=============
FMC_A0            PF0
FMC_A1            PF1
FMC_A2            PF2
FMC_A3            PF3
FMC_A4            PF4
FMC_A5            PF5
FMC_A6            PF12
FMC_A7            PF13
FMC_A8            PF14
FMC_A9            PF15
FMC_A10           PG0
FMC_A11           PG1
FMC_A12           PG2
FMC_A13           PG3
FMC_A14           PG4
FMC_BA0           PG4
FMC_A15           PG5
FMC_BA1           PG5
FMC_A16           PD11
FMC_A17           PD12
FMC_A18           PD13
FMC_A19           PE3
FMC_A20           PE4
FMC_A21           PE5
FMC_A22           PE6
FMC_A23           PE2
FMC_A24           PG13
FMC_A25           PG14

FMC_D0            PD14
FMC_D1            PD15
FMC_D2            PD0
FMC_D3            PD1
FMC_D4            PE7
FMC_D5            PE8
FMC_D6            PE9
FMC_D7            PE10
FMC_D8            PE11
FMC_D9            PE12
FMC_D10           PE13
FMC_D11           PE14
FMC_D12           PE15
FMC_D13           PD8
FMC_D14           PD9
FMC_D15           PD10
FMC_D16           PH8
FMC_D17           PH9
FMC_D18           PH10
FMC_D19           PH11
FMC_D20           PH12
FMC_D21           PH13
FMC_D22           PH14
FMC_D23           PH15
FMC_D24           PI0
FMC_D25           PI1
FMC_D26           PI2
FMC_D27           PI3
FMC_D28           PI6
FMC_D29           PI7
FMC_D30           PI9
FMC_D31           PI10

FMC_NBL0          PE0
FMC_NBL1          PE1
FMC_NBL2          PI4
FMC_NBL3          PI5

FMC_CLK           PD3
FMC_SDCLK         PG8
FMC_SDCKE0        PC3   PH2  PH7
FMC_SDCKE1        PB5

FMC_NE1           PD7
FMC_NCE2          PD7
FMC_NE2           PG9
FMC_NCE3          PG9
FMC_NCE4_1        PG10
FMC_NE3           PG10
FMC_NCE4_2        PG11
FMC_NE4           PG12
FMC_SDNE0         PC2   PH3
FMC_SDNE1         PB6   PH6

FMC_NOE           PD4
FMC_NWE           PD5
FMC_NWAIT         PD6
FMC_NL            PB7
FMC_SDNWE         PC0   PH5
FMC_SDNRAS        PF11
FMC_SDNCAS        PG15
FMC_NIORD         PF6
FMC_NREG          PF7
FMC_NIOWR         PF8
FMC_CD            PF9
FMC_INTR          PF10
FMC_INT2          PG6
FMC_INT3          PG7
====================================
*/
#define FMC_A0_PIN        GET_PIN(F, 0)  
#define FMC_A1_PIN        GET_PIN(F, 1)  
#define FMC_A2_PIN        GET_PIN(F, 2)  
#define FMC_A3_PIN        GET_PIN(F, 3)  
#define FMC_A4_PIN        GET_PIN(F, 4)  
#define FMC_A5_PIN        GET_PIN(F, 5)  
#define FMC_A6_PIN        GET_PIN(F, 12) 
#define FMC_A7_PIN        GET_PIN(F, 13) 
#define FMC_A8_PIN        GET_PIN(F, 14) 
#define FMC_A9_PIN        GET_PIN(F, 15) 
#define FMC_A10_PIN       GET_PIN(G, 0)  
#define FMC_A11_PIN       GET_PIN(G, 1)  
#define FMC_A12_PIN       GET_PIN(G, 2)  
#define FMC_A13_PIN       GET_PIN(G, 3)  
#define FMC_A14_PIN       GET_PIN(G, 4)  
#define FMC_BA0_PIN       GET_PIN(G, 4)  
#define FMC_A15_PIN       GET_PIN(G, 5)  
#define FMC_BA1_PIN       GET_PIN(G, 5)  
#define FMC_A16_PIN       GET_PIN(D, 11) 
#define FMC_A17_PIN       GET_PIN(D, 12) 
#define FMC_A18_PIN       GET_PIN(D, 13) 
#define FMC_A19_PIN       GET_PIN(E, 3)  
#define FMC_A20_PIN       GET_PIN(E, 4)  
#define FMC_A21_PIN       GET_PIN(E, 5)  
#define FMC_A22_PIN       GET_PIN(E, 6)  
#define FMC_A23_PIN       GET_PIN(E, 2)  
#define FMC_A24_PIN       GET_PIN(G, 13) 
#define FMC_A25_PIN       GET_PIN(G, 14) 

#define FMC_D0_PIN        GET_PIN(D, 14) 
#define FMC_D1_PIN        GET_PIN(D, 15) 
#define FMC_D2_PIN        GET_PIN(D, 0)  
#define FMC_D3_PIN        GET_PIN(D, 1)  
#define FMC_D4_PIN        GET_PIN(E, 7)  
#define FMC_D5_PIN        GET_PIN(E, 8)  
#define FMC_D6_PIN        GET_PIN(E, 9)  
#define FMC_D7_PIN        GET_PIN(E, 10) 
#define FMC_D8_PIN        GET_PIN(E, 11) 
#define FMC_D9_PIN        GET_PIN(E, 12) 
#define FMC_D10_PIN       GET_PIN(E, 13) 
#define FMC_D11_PIN       GET_PIN(E, 14) 
#define FMC_D12_PIN       GET_PIN(E, 15) 
#define FMC_D13_PIN       GET_PIN(D, 8)  
#define FMC_D14_PIN       GET_PIN(D, 9)  
#define FMC_D15_PIN       GET_PIN(D, 10) 
#define FMC_D16_PIN       GET_PIN(H, 8)  
#define FMC_D17_PIN       GET_PIN(H, 9)  
#define FMC_D18_PIN       GET_PIN(H, 10) 
#define FMC_D19_PIN       GET_PIN(H, 11) 
#define FMC_D20_PIN       GET_PIN(H, 12) 
#define FMC_D21_PIN       GET_PIN(H, 13) 
#define FMC_D22_PIN       GET_PIN(H, 14) 
#define FMC_D23_PIN       GET_PIN(H, 15) 
#define FMC_D24_PIN       GET_PIN(I, 0)  
#define FMC_D25_PIN       GET_PIN(I, 1)  
#define FMC_D26_PIN       GET_PIN(I, 2)  
#define FMC_D27_PIN       GET_PIN(I, 3)  
#define FMC_D28_PIN       GET_PIN(I, 6)  
#define FMC_D29_PIN       GET_PIN(I, 7)  
#define FMC_D30_PIN       GET_PIN(I, 9)  
#define FMC_D31_PIN       GET_PIN(I, 10) 

#define FMC_NBL0_PIN      GET_PIN(E, 0)  
#define FMC_NBL1_PIN      GET_PIN(E, 1)  
#define FMC_NBL2_PIN      GET_PIN(I, 4)  
#define FMC_NBL3_PIN      GET_PIN(I, 5)  

#define FMC_CLK_PIN       GET_PIN(D, 3)  
#define FMC_SDCLK_PIN     GET_PIN(G, 8)  
#define FMC_SDCKE0_PIN    GET_PIN(C, 3)  
#define FMC_SDCKE1_PIN    GET_PIN(B, 5)  

#define FMC_NE1_PIN       GET_PIN(D, 7)  
#define FMC_NCE2_PIN      GET_PIN(D, 7)  
#define FMC_NE2_PIN       GET_PIN(G, 9)  
#define FMC_NCE3_PIN      GET_PIN(G, 9)  
#define FMC_NCE4_1_PIN    GET_PIN(G, 10) 
#define FMC_NE3_PIN       GET_PIN(G, 10) 
#define FMC_NCE4_2_PIN    GET_PIN(G, 11) 
#define FMC_NE4_PIN       GET_PIN(G, 12) 
#define FMC_SDNE0_PIN     GET_PIN(C, 2)  
#define FMC_SDNE1_PIN     GET_PIN(B, 6)  

#define FMC_NOE_PIN       GET_PIN(D, 4)  
#define FMC_NWE_PIN       GET_PIN(D, 5)  
#define FMC_NWAIT_PIN     GET_PIN(D, 6)  
#define FMC_NL_PIN        GET_PIN(B, 7)  
#define FMC_SDNWE_PIN     GET_PIN(C, 0)  
#define FMC_SDNRAS_PIN    GET_PIN(F, 11) 
#define FMC_SDNCAS_PIN    GET_PIN(G, 15) 
#define FMC_NIORD_PIN     GET_PIN(F, 6)  
#define FMC_NREG_PIN      GET_PIN(F, 7)  
#define FMC_NIOWR_PIN     GET_PIN(F, 8)  
#define FMC_CD_PIN        GET_PIN(F, 9)  
#define FMC_INTR_PIN      GET_PIN(F, 10) 
#define FMC_INT2_PIN      GET_PIN(G, 6)  
#define FMC_INT3_PIN      GET_PIN(G, 7)  



/*============	LTDC 	=============
1	LTDC_HSYNC	    PC6     PI10    PI12
2	LTDC_VSYNC      PA4	    PI9     PI13
3	LTDC_CLK	    PE14    PG7     PI14
4	LTDC_DE         PE13    PF10    PK7
5	LTDC_R0		    PH2     PI15
6	LTDC_R1		    PH3     PJ0
7	LTDC_R2		    PC10    PH8     PJ1
8	LTDC_R3		    PH9     PJ2
9	LTDC_R4		    PA11    PH10    PJ3
10	LTDC_R5         PA12	PH11    PJ4
11	LTDC_R6         PA8		PH12    PJ5
12	LTDC_R7		    PE15    PG6     PJ6
13	LTDC_G0         PE5     PJ7
14	LTDC_G1         PE6     PJ8
15	LTDC_G2         PA6     PJ9     PH13
16	LTDC_G3         PE11    PH14    PJ10
17	LTDC_G4         PB10    PH15    PJ11
18	LTDC_G5         PB11    PI0     PK0
19	LTDC_G6         PC7     PI1     PK1
20	LTDC_G7         PD3     PI2     PK2 
21	LTDC_B0         PE4     PJ12
22	LTDC_B1         PG12    PJ13
23	LTDC_B2         PD6     PG10    PJ14
24	LTDC_B3         PD10    PG11    PJ15
25	LTDC_B4         PE12    PI4     PK3 
26	LTDC_B5         PA3	    PI5     PK4
27	LTDC_B6         PB8     PI6     PK5
28	LTDC_B7         PB9     PI7     PK6 
 ====================================
*/
#define LTDC_HSYNC_PIN	GET_PIN(I,10)
#define LTDC_VSYNC_PIN	GET_PIN(I,9)
#define LTDC_CLK_PIN	GET_PIN(G,7)
#define LTDC_DE_PIN		GET_PIN(F,10)
#define LTDC_R0_PIN		GET_PIN(H,2)
#define LTDC_R1_PIN		GET_PIN(H,3)
#define LTDC_R2_PIN		GET_PIN(H,8)
#define LTDC_R3_PIN		GET_PIN(H,9)
#define LTDC_R4_PIN		GET_PIN(H,10)
#define LTDC_R5_PIN		GET_PIN(H,11)
#define LTDC_R6_PIN		GET_PIN(H,12)
#define LTDC_R7_PIN		GET_PIN(G,6)
#define LTDC_G0_PIN		GET_PIN(J,7)
#define LTDC_G1_PIN		GET_PIN(J,8)
#define LTDC_G2_PIN		GET_PIN(H,13)
#define LTDC_G3_PIN		GET_PIN(H,14)
#define LTDC_G4_PIN		GET_PIN(H,15)
#define LTDC_G5_PIN		GET_PIN(I,0)
#define LTDC_G6_PIN		GET_PIN(I,1)
#define LTDC_G7_PIN		GET_PIN(I,2)
#define LTDC_B0_PIN		GET_PIN(J,12)
#define LTDC_B1_PIN		GET_PIN(J,13)
#define LTDC_B2_PIN		GET_PIN(J,14)
#define LTDC_B3_PIN		GET_PIN(G,11)
#define LTDC_B4_PIN		GET_PIN(I,4)
#define LTDC_B5_PIN		GET_PIN(I,5)
#define LTDC_B6_PIN		GET_PIN(I,6)
#define LTDC_B7_PIN		GET_PIN(I,7)


#endif






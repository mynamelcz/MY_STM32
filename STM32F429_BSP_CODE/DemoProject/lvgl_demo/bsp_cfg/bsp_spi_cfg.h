#ifndef __BSP_SPI_CFG_H
#define __BSP_SPI_CFG_H

#include "board.h"

#if defined(BSP_USING_SPI1) || defined(BSP_USING_SPI2) || defined(BSP_USING_SPI3) 

#define __USING_BSP_SPI_DRV




#if defined(BSP_USING_SPI1)

#ifndef SPI1_CONFIG
#define SPI1_CONFIG                             					\
    {                                               				\
        .Instance = SPI1,                           				\
		.config = {													\
			.SPI_Direction = SPI_Direction_2Lines_FullDuplex, 		\
			.SPI_Mode = SPI_Mode_Master,	                   		\
			.SPI_DataSize = SPI_DataSize_8b,		   			 	\
			.SPI_CPOL = SPI_CPOL_High,	                    		\
			.SPI_CPHA = SPI_CPHA_2Edge,                     		\
			.SPI_NSS = SPI_NSS_Soft,		            			\
			.SPI_BaudRatePrescaler = SPI_BaudRatePrescaler_32,		\
			.SPI_FirstBit = SPI_FirstBit_MSB,               		\
			.SPI_CRCPolynomial = 7,									\
			},														\
    }
#endif /* SPI1_BUS_CONFIG */
#endif /* BSP_USING_SPI1 */
    
#if defined(BSP_USING_SPI2)

#ifndef SPI2_CONFIG
#define SPI2_CONFIG                             					\
    {                                               				\
        .Instance = SPI2,                           				\
		.config = {													\
			.SPI_Direction = SPI_Direction_2Lines_FullDuplex, 		\
			.SPI_Mode = SPI_Mode_Master,	                   		\
			.SPI_DataSize = SPI_DataSize_16b,		   			 	\
			.SPI_CPOL = SPI_CPOL_High,	                    		\
			.SPI_CPHA = SPI_CPHA_2Edge,                     		\
			.SPI_NSS = SPI_NSS_Soft,		            			\
			.SPI_BaudRatePrescaler = SPI_BaudRatePrescaler_256,		\
			.SPI_FirstBit = SPI_FirstBit_MSB,               		\
			.SPI_CRCPolynomial = 7,									\
			},														\
    }
#endif /* SPI2_BUS_CONFIG */
#endif /* BSP_USING_SPI2 */
	
#if defined(BSP_USING_SPI3)

#ifndef SPI3_CONFIG
#define SPI3_CONFIG                             					\
    {                                               				\
        .Instance = SPI3,                           				\
		.config = {													\
			.SPI_Direction = SPI_Direction_2Lines_FullDuplex, 		\
			.SPI_Mode = SPI_Mode_Master,	                   		\
			.SPI_DataSize = SPI_DataSize_8b,		   			 	\
			.SPI_CPOL = SPI_CPOL_High,	                    		\
			.SPI_CPHA = SPI_CPHA_2Edge,                     		\
			.SPI_NSS = SPI_NSS_Soft,		            			\
			.SPI_BaudRatePrescaler = SPI_BaudRatePrescaler_256,		\
			.SPI_FirstBit = SPI_FirstBit_MSB,               		\
			.SPI_CRCPolynomial = 7,									\
			},														\
    }
#endif /* SPI3_BUS_CONFIG */
#endif /* BSP_USING_SPI3 */
	
	

#endif

	
#endif










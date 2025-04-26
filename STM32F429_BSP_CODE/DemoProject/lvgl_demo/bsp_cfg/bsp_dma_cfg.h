#ifndef BSP_DMA_CFG_H
#define BSP_DMA_CFG_H

#include "board.h"





#if defined(BSP_USING_DMA1_STREAM0) || defined(BSP_USING_DMA1_STREAM1) || defined(BSP_USING_DMA1_STREAM3) || defined(BSP_USING_DMA1_STREAM4)
#define __USING_BSP_DMA_DRV



#if defined(BSP_USING_DMA1_STREAM0)
#ifndef DMA1_ST0_CONFIG
#define DMA1_ST0_CONFIG      	\
    {                        	\
		.StreamX = DMA1_Stream0,\
		.config = {				\
			.DMA_Channel 			= DMA_Channel_0,	\
			.DMA_PeripheralBaseAddr = 0,	\
			.DMA_Memory0BaseAddr 	= 0,	\
			.DMA_BufferSize 		= 0,	\
			.DMA_DIR 				= DMA_DIR_PeripheralToMemory,	\
			.DMA_PeripheralInc 		= DMA_PeripheralInc_Disable,	\
			.DMA_MemoryInc 			= DMA_MemoryInc_Enable,			\
			.DMA_PeripheralDataSize = DMA_PeripheralDataSize_Byte,	\
			.DMA_MemoryDataSize 	= DMA_MemoryDataSize_Byte,		\
			.DMA_Mode     			= DMA_Mode_Normal,				\
			.DMA_Priority 			= DMA_Priority_VeryHigh,		\
			.DMA_FIFOMode 			= DMA_FIFOMode_Disable,         \
			.DMA_FIFOThreshold 		= DMA_FIFOThreshold_Full,		\
			.DMA_MemoryBurst 		= DMA_MemoryBurst_Single,		\
			.DMA_PeripheralBurst 	= DMA_PeripheralBurst_Single,	\
		},															\
    }
#endif /* DMA1_ST1_CONFIG */
#endif /* DMA1_ST1_CONFIG */


#if defined(BSP_USING_DMA1_STREAM1)

#ifndef DMA1_ST1_CONFIG
#define DMA1_ST1_CONFIG      	\
    {                        	\
		.StreamX = DMA1_Stream3,\
		.config = {				\
			.DMA_Channel 			= DMA_Channel_3,	\
			.DMA_PeripheralBaseAddr = 0,	\
			.DMA_Memory0BaseAddr 	= 0,	\
			.DMA_BufferSize 		= 0,	\
			.DMA_DIR 				= DMA_DIR_PeripheralToMemory,	\
			.DMA_PeripheralInc 		= DMA_PeripheralInc_Disable,	\
			.DMA_MemoryInc 			= DMA_MemoryInc_Enable,			\
			.DMA_PeripheralDataSize = DMA_PeripheralDataSize_Byte,	\
			.DMA_MemoryDataSize 	= DMA_MemoryDataSize_Byte,		\
			.DMA_Mode     			= DMA_Mode_Normal,				\
			.DMA_Priority 			= DMA_Priority_VeryHigh,		\
			.DMA_FIFOMode 			= DMA_FIFOMode_Disable,         \
			.DMA_FIFOThreshold 		= DMA_FIFOThreshold_Full,		\
			.DMA_MemoryBurst 		= DMA_MemoryBurst_Single,		\
			.DMA_PeripheralBurst 	= DMA_PeripheralBurst_Single,	\
		},															\
    }
#endif /* DMA1_ST1_CONFIG */
#endif /* DMA1_ST1_CONFIG */


#if defined(BSP_USING_DMA1_STREAM4)
#ifndef DMA1_ST4_CONFIG
#define DMA1_ST4_CONFIG      	\
    {                        	\
		.StreamX = DMA1_Stream4,\
		.config = {				\
			.DMA_Channel 			= DMA_Channel_0,	\
			.DMA_PeripheralBaseAddr = 0,	\
			.DMA_Memory0BaseAddr 	= 0,	\
			.DMA_BufferSize 		= 0,	\
			.DMA_DIR 				= DMA_DIR_MemoryToPeripheral,	\
			.DMA_PeripheralInc 		= DMA_PeripheralInc_Disable,	\
			.DMA_MemoryInc 			= DMA_MemoryInc_Enable,			\
			.DMA_PeripheralDataSize = DMA_PeripheralDataSize_HalfWord,	\
			.DMA_MemoryDataSize 	= DMA_MemoryDataSize_HalfWord,		\
			.DMA_Mode     			= DMA_Mode_Circular,				\
			.DMA_Priority 			= DMA_Priority_VeryHigh,		\
			.DMA_FIFOMode 			= DMA_FIFOMode_Disable,         \
			.DMA_FIFOThreshold 		= DMA_FIFOThreshold_Full,		\
			.DMA_MemoryBurst 		= DMA_MemoryBurst_Single,		\
			.DMA_PeripheralBurst 	= DMA_PeripheralBurst_Single,	\
		},															\
    }
#endif /* DMA1_ST4_CONFIG */
#endif /* DMA1_ST4_CONFIG */


#endif


#endif











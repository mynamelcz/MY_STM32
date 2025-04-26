#ifndef __BSP_SDIO_CFG_H
#define __BSP_SDIO_CFG_H





#define SDIO_DMA                DMA2
#define SDIO_DMA_CLK            RCC_AHB1Periph_DMA2
#define SDIO_DMA_STREAM_NUM		3
#define SDIO_DMA_CHANNEL        DMA_Channel_4

#if (SDIO_DMA_STREAM_NUM == 3)
#define SDIO_DMA_STREAM       	   DMA2_Stream3

#define SDIO_DMA_FLAG_FEIF         DMA_FLAG_FEIF3
#define SDIO_DMA_FLAG_DMEIF        DMA_FLAG_DMEIF3
#define SDIO_DMA_FLAG_TEIF         DMA_FLAG_TEIF3
#define SDIO_DMA_FLAG_HTIF         DMA_FLAG_HTIF3
#define SDIO_DMA_FLAG_TCIF         DMA_FLAG_TCIF3 

#define SDIO_DMA_IRQn              DMA2_Stream3_IRQn
#define SDIO_DMA_IRQHANDLER        DMA2_Stream3_IRQHandler 

#elif(SDIO_DMA_STREAM_NUM == 6)
#define SDIO_DMA_STREAM        	   DMA2_Stream6

#define SDIO_DMA_FLAG_FEIF         DMA_FLAG_FEIF6
#define SDIO_DMA_FLAG_DMEIF        DMA_FLAG_DMEIF6
#define SDIO_DMA_FLAG_TEIF         DMA_FLAG_TEIF6
#define SDIO_DMA_FLAG_HTIF         DMA_FLAG_HTIF6
#define SDIO_DMA_FLAG_TCIF         DMA_FLAG_TCIF6 

#define SDIO_DMA_IRQn              DMA2_Stream6_IRQn
#define SDIO_DMA_IRQHANDLER        DMA2_Stream6_IRQHandler 
#else

#endif
















#endif




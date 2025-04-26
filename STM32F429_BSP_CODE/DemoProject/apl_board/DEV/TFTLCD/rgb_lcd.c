#include "rgb_lcd.h"
#include "stm32f429xx.h"
#include "bsp_gpio.h"
#include "includes.h"
#include "stm32f4xx_ll_rcc.h"

#define LTDC_FRAME_BUF_ADDR             0XC0000000
#define LCD_BL_PIN      GET_PIN(B,5)
#define LCD_BL(x)	    BSP_GPIO_DRV.pin_write(LCD_BL_PIN,x)

LTDC_HandleTypeDef  g_ltdc_handle;       /* LTDC句柄 */
DMA2D_HandleTypeDef g_dma2d_handle;      /* DMA2D句柄 */
uint16_t ltdc_lcd_framebuf[1280][800] __attribute__((at(LTDC_FRAME_BUF_ADDR)));   /* 定义最大屏分辨率时,LTDC所需的帧缓存数组大小 */


#define LCD_WIDTH           1024                    /* 面板宽度,        单位:像素 */
#define LCD_HEIGHT          600                     /* 面板高度,        单位:像素 */
#define LCD_PIXEL_FORMA     LTDC_PIXEL_FORMAT_RGB565
#define LDC_PIX_SIZE        2                       /* 每个像素占2个字节 */

/*
    lcdltdc.LCD_WIDTH = 1024;                  面板宽度,单位:像素
    lcdltdc.LCD_HEIGHT = 600;                  面板高度,单位:像素
    lcdltdc.hsw = 20;                       水平同步宽度
    lcdltdc.vsw = 3;                        垂直同步宽度
    lcdltdc.hbp = 140;                      水平后廊
    lcdltdc.vbp = 20;                       垂直后廊
    lcdltdc.hfp = 160;                      水平前廊
    lcdltdc.vfp = 12;                       垂直前廊

*/


void ltdc_fill(uint16_t sx, uint16_t sy, uint16_t ex, uint16_t ey, uint32_t color)
{
    uint32_t psx, psy, pex, pey;   /* 以LCD面板为基准的坐标系,不随横竖屏变化而变化 */
    uint32_t timeout = 0;
    uint16_t offline;
    uint32_t addr;


    psx = sx;
    psy = sy;
    pex = ex;
    pey = ey;


    offline = LCD_WIDTH - (pex - psx + 1);
    addr = ((uint32_t)ltdc_lcd_framebuf + LDC_PIX_SIZE * (LCD_WIDTH* psy + psx));

    __HAL_RCC_DMA2D_CLK_ENABLE();                              /* 使能DM2D时钟 */
    DMA2D->CR &= ~(DMA2D_CR_START);                            /* 先停止DMA2D */
    DMA2D->CR = DMA2D_R2M;                                     /* 寄存器到存储器模式 */
    DMA2D->OPFCCR = LCD_PIXEL_FORMA;                            /* 设置颜色格式 */
    DMA2D->OOR = offline;                                      /* 设置行偏移  */
    DMA2D->OMAR = addr;                                        /* 输出存储器地址 */
    DMA2D->NLR = (pey - psy + 1) | ((pex - psx + 1) << 16);    /* 设定行数寄存器 */
    DMA2D->OCOLR = color;                                      /* 设定输出颜色寄存器 */
    DMA2D->CR |= DMA2D_CR_START;                               /* 启动DMA2D */

    while((DMA2D->ISR & (DMA2D_FLAG_TC)) == 0)                 /* 等待传输完成 */
    {
        timeout++;
        if(timeout > 0X1FFFFF)break;                           /* 超时退出 */
    }
    DMA2D->IFCR |= DMA2D_FLAG_TC;                              /* 清除传输完成标志 */
}
void ltdc_clear(uint32_t color)
{
    ltdc_fill(0, 0, LCD_WIDTH - 1, LCD_HEIGHT - 1, color);
}

void rgb_lcd_test(void)
{
    uint32_t hsw = 20;                      /* 水平同步信号宽度 单位:时钟个数*/
    uint32_t hbp = 160;                     /* 水平后廊, 水平同步信号开始到有效数据开始的时钟个数 */
    uint32_t hfp = 160;                     /* 水平前廊, 有效数据结束到像一个水平同步信号开始的时钟个数 */
    uint32_t vsw = 3;                       /* 垂直同步信号宽度 单位:单位位行  */
    uint32_t vbp = 23;                      /* 垂直后廊, 一帧信号开始时,无效的行数 */
    uint32_t vfp = 12;                      /* 垂直前廊, 一帧信号结束后,无效的行数 */
    uint32_t layerx = 0;

    BSP_GPIO_DRV.pin_mode(LCD_BL_PIN, PIN_Mode_Out_PP, PIN_NoPull, 0);
   
    BSP_GPIO_DRV.pin_mode(LTDC_HSYNC_PIN, PIN_Mode_AF_PP, PIN_PullUp, GPIO_AF14_LTDC); 
    BSP_GPIO_DRV.pin_mode(LTDC_VSYNC_PIN, PIN_Mode_AF_PP, PIN_PullUp, GPIO_AF14_LTDC); 
    BSP_GPIO_DRV.pin_mode(LTDC_CLK_PIN, PIN_Mode_AF_PP, PIN_PullUp, GPIO_AF14_LTDC); 
    BSP_GPIO_DRV.pin_mode(LTDC_DE_PIN, PIN_Mode_AF_PP, PIN_PullUp, GPIO_AF14_LTDC); 
    
    BSP_GPIO_DRV.pin_mode(LTDC_R0_PIN, PIN_Mode_AF_PP, PIN_PullUp, GPIO_AF14_LTDC); 
    BSP_GPIO_DRV.pin_mode(LTDC_R1_PIN, PIN_Mode_AF_PP, PIN_PullUp, GPIO_AF14_LTDC); 
    BSP_GPIO_DRV.pin_mode(LTDC_R2_PIN, PIN_Mode_AF_PP, PIN_PullUp, GPIO_AF14_LTDC); 
    BSP_GPIO_DRV.pin_mode(LTDC_R3_PIN, PIN_Mode_AF_PP, PIN_PullUp, GPIO_AF14_LTDC); 
    BSP_GPIO_DRV.pin_mode(LTDC_R4_PIN, PIN_Mode_AF_PP, PIN_PullUp, GPIO_AF14_LTDC); 
    
    BSP_GPIO_DRV.pin_mode(LTDC_G0_PIN, PIN_Mode_AF_PP, PIN_PullUp, GPIO_AF14_LTDC); 
    BSP_GPIO_DRV.pin_mode(LTDC_G1_PIN, PIN_Mode_AF_PP, PIN_PullUp, GPIO_AF14_LTDC); 
    BSP_GPIO_DRV.pin_mode(LTDC_G2_PIN, PIN_Mode_AF_PP, PIN_PullUp, GPIO_AF14_LTDC); 
    BSP_GPIO_DRV.pin_mode(LTDC_G3_PIN, PIN_Mode_AF_PP, PIN_PullUp, GPIO_AF14_LTDC); 
    BSP_GPIO_DRV.pin_mode(LTDC_G4_PIN, PIN_Mode_AF_PP, PIN_PullUp, GPIO_AF14_LTDC); 
    BSP_GPIO_DRV.pin_mode(LTDC_G5_PIN, PIN_Mode_AF_PP, PIN_PullUp, GPIO_AF14_LTDC); 

    BSP_GPIO_DRV.pin_mode(LTDC_B0_PIN, PIN_Mode_AF_PP, PIN_PullUp, GPIO_AF14_LTDC); 
    BSP_GPIO_DRV.pin_mode(LTDC_B1_PIN, PIN_Mode_AF_PP, PIN_PullUp, GPIO_AF14_LTDC); 
    BSP_GPIO_DRV.pin_mode(LTDC_B2_PIN, PIN_Mode_AF_PP, PIN_PullUp, GPIO_AF14_LTDC); 
    BSP_GPIO_DRV.pin_mode(LTDC_B3_PIN, PIN_Mode_AF_PP, PIN_PullUp, GPIO_AF14_LTDC); 
    BSP_GPIO_DRV.pin_mode(LTDC_B4_PIN, PIN_Mode_AF_PP, PIN_PullUp, GPIO_AF14_LTDC);    
    
    
    
    
    
    RCC_PeriphCLKInitTypeDef PeriphClkInitStruct;
    LTDC_LayerCfgTypeDef playercfg;
    __HAL_RCC_LTDC_CLK_ENABLE();                      /* 使能LTDC时钟 */

    /* LTDC输出像素时钟，需要根据自己所使用的LCD数据手册来配置！ */
    PeriphClkInitStruct.PeriphClockSelection = RCC_PERIPHCLK_LTDC;
    PeriphClkInitStruct.PLLSAI.PLLSAIN = 360;
    PeriphClkInitStruct.PLLSAI.PLLSAIR = 2;
    PeriphClkInitStruct.PLLSAIDivR = RCC_PLLSAIDIVR_4;
    HAL_RCCEx_PeriphCLKConfig(&PeriphClkInitStruct);

    //LOG_D("FREQ: %d\n",LL_RCC_GetLTDCClockFreq(LL_RCC_LTDC_CLKSOURCE));
    g_ltdc_handle.Instance = LTDC;
    g_ltdc_handle.Init.HSPolarity = LTDC_HSPOLARITY_AL;         /* 水平同步极性 */
    g_ltdc_handle.Init.VSPolarity = LTDC_VSPOLARITY_AL;         /* 垂直同步极性 */
    g_ltdc_handle.Init.DEPolarity = LTDC_DEPOLARITY_AL;         /* 数据使能极性 */
    g_ltdc_handle.State = HAL_LTDC_STATE_RESET;
    g_ltdc_handle.Init.PCPolarity = LTDC_PCPOLARITY_IPC;        /* 像素时钟极性 */
    g_ltdc_handle.Init.HorizontalSync = hsw - 1;
    g_ltdc_handle.Init.VerticalSync = vsw - 1;
    g_ltdc_handle.Init.AccumulatedHBP = hsw + hbp - 1;
    g_ltdc_handle.Init.AccumulatedVBP = vsw + vbp - 1;
    g_ltdc_handle.Init.AccumulatedActiveW = hsw + hbp + LCD_WIDTH - 1;
    g_ltdc_handle.Init.AccumulatedActiveH = vsw + vbp + LCD_HEIGHT - 1;
    g_ltdc_handle.Init.TotalWidth = hsw + hbp + LCD_WIDTH + hfp - 1;
    g_ltdc_handle.Init.TotalHeigh = vsw + vbp + LCD_HEIGHT + vfp - 1;
    g_ltdc_handle.Init.Backcolor.Red = 0;                                                           /* 屏幕背景层红色部分 */
    g_ltdc_handle.Init.Backcolor.Green = 0;                                                         /* 屏幕背景层绿色部分 */
    g_ltdc_handle.Init.Backcolor.Blue = 0;                                                          /* 屏幕背景色蓝色部分 */
    HAL_LTDC_Init(&g_ltdc_handle);

    playercfg.WindowX0 = 0;                                             /* 窗口起始X坐标 */
    playercfg.WindowY0 = 0;                                             /* 窗口起始Y坐标 */
    playercfg.WindowX1 = LCD_WIDTH;                                        /* 窗口终止X坐标 */
    playercfg.WindowY1 = LCD_HEIGHT;                                        /* 窗口终止Y坐标 */
    playercfg.PixelFormat = LCD_PIXEL_FORMA;                                /* 像素格式 */
    playercfg.Alpha = 255;                                              /* Alpha值设置，0~255,255为完全不透明 */
    playercfg.Alpha0 = 0;                                               /* 默认Alpha值 */
    playercfg.BlendingFactor1 = LTDC_BLENDING_FACTOR1_PAxCA;                  /* 设置层混合系数 */
    playercfg.BlendingFactor2 = LTDC_BLENDING_FACTOR2_PAxCA;                       /* 设置层混合系数 */
    playercfg.FBStartAdress = (uint32_t)ltdc_lcd_framebuf;                                 /* 设置层颜色帧缓存起始地址 */
    playercfg.ImageWidth = LCD_WIDTH;                                       /* 设置颜色帧缓冲区的宽度 */
    playercfg.ImageHeight = LCD_HEIGHT;                                    /* 设置颜色帧缓冲区的高度 */
    playercfg.Backcolor.Red = (uint8_t)(0X000000 & 0X00FF0000) >> 16;   /* 背景颜色红色部分 */
    playercfg.Backcolor.Green = (uint8_t)(0X000000 & 0X0000FF00) >> 8;  /* 背景颜色绿色部分 */
    playercfg.Backcolor.Blue = (uint8_t)0X000000 & 0X000000FF;          /* 背景颜色蓝色部分 */
    HAL_LTDC_ConfigLayer(&g_ltdc_handle, &playercfg, layerx);               /* 设置所选中的层 */

    HAL_LTDC_SetWindowPosition(&g_ltdc_handle, 0, 0, layerx);   /* 设置窗口的位置 */
    HAL_LTDC_SetWindowSize(&g_ltdc_handle, LCD_WIDTH, LCD_HEIGHT, layerx);/* 设置窗口大小 */
    LCD_BL(1);                           /* 点亮背光 */
    ltdc_clear(0X0);               /* 清屏 */

}
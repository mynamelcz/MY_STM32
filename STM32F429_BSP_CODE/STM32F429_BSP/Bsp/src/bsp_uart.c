#include "bsp_uart.h"

#ifdef __USING_BSP_UART_DRV

const static struct stm32_uart_config Uart_Cfg_Tab[] =
{
#ifdef BSP_USING_UART1
    UART1_CONFIG,
#endif
#ifdef BSP_USING_UART2
    UART2_CONFIG,
#endif
#ifdef BSP_USING_UART3
    UART3_CONFIG,
#endif
#ifdef BSP_USING_UART4
    UART4_CONFIG,
#endif
#ifdef BSP_USING_UART5
    UART5_CONFIG,
#endif
#ifdef BSP_USING_UART6
    UART6_CONFIG,
#endif

};

int bsp_uart_init(u8 uart_index)
{
#ifdef BSP_USING_UART1
    if(uart_index == UART1_INDEX)
    {
        __HAL_RCC_USART1_CLK_ENABLE();
    }
#endif
#ifdef BSP_USING_UART2
    if(uart_index == UART2_INDEX)
    {
        __HAL_RCC_USART2_CLK_ENABLE();
    }
#endif
#ifdef BSP_USING_UART3
    if(uart_index == UART3_INDEX)
    {
        __HAL_RCC_USART3_CLK_ENABLE();
    }
#endif
#ifdef BSP_USING_UART4
    if(uart_index == UART4_INDEX)
    {
        __HAL_RCC_UART4_CLK_ENABLE();
    }
#endif
#ifdef BSP_USING_UART5
    if(uart_index == UART5_INDEX)
    {
        __HAL_RCC_UART5_CLK_ENABLE();
    }
#endif
#ifdef BSP_USING_UART6
    if(uart_index == UART6_INDEX)
    {
        __HAL_RCC_USART6_CLK_ENABLE();
    }
#endif
    LL_USART_InitTypeDef *InitStruct_p = (LL_USART_InitTypeDef*)&Uart_Cfg_Tab[uart_index].config;
    USART_TypeDef *USARTx = Uart_Cfg_Tab[uart_index].Instance;
    LL_USART_Init(USARTx, InitStruct_p);
    LL_USART_Enable(USARTx);
    return 0;
}

int bsp_uart_init_clk(u8 uart_index)
{
    LL_USART_ClockInitTypeDef *InitStruct_p = (LL_USART_ClockInitTypeDef*)&Uart_Cfg_Tab[uart_index].clk_cfg;
    USART_TypeDef *USARTx = Uart_Cfg_Tab[uart_index].Instance;
    LL_USART_ClockInit(USARTx, InitStruct_p);
    return 0;
}

int bsp_uart_enable_it(u8 index, u16 source)
{
    __HAL_UART_ENABLE_IT(&Uart_Cfg_Tab[index], source);
    return 0;
}
int bsp_uart_diable_it(u8 index, u16 source)
{
    __HAL_UART_DISABLE_IT(&Uart_Cfg_Tab[index], source);
    return 0;
}

int uart_enable_dma(u8 index, u16 dma_req)
{
    USART_TypeDef *USARTx = Uart_Cfg_Tab[index].Instance;
    USARTx->CR3 |= dma_req;
    return 0;
}
int uart_disable_dma(u8 index, u16 dma_req)
{
    USART_TypeDef *USARTx = Uart_Cfg_Tab[index].Instance;
    USARTx->CR3 &= (uint16_t)~dma_req;
    return 0;
}

int bsp_uart_send_char(u8 uart_index, u8 ch)
{
    USART_TypeDef *USARTx = Uart_Cfg_Tab[uart_index].Instance;
    while((USARTx->SR & USART_FLAG_TXE) == 0); //循环发送,直到发送完毕
    USARTx->DR = (u8) ch;
    return 0;
}

int bsp_uart_send_buf(u8 uart_index, u8 *buf, u32 len)
{
    for(int i = 0; i < len; i++)
    {
        USART_TypeDef *USARTx = Uart_Cfg_Tab[uart_index].Instance;
        while((USARTx->SR & USART_FLAG_TXE) == 0); //循环发送,直到发送完毕
        USARTx->DR = (u8) buf[i];
    }
    return 0;
}

const struct __bsp_uart_drv BSP_UART_DRV =
{
    .init = bsp_uart_init,
    .cfg_clk = bsp_uart_init_clk,
    .deinit = NULL,
    .open = NULL,
    .close = NULL,
    .enable_it = bsp_uart_enable_it,
    .diable_it = bsp_uart_diable_it,
    .enable_dma  = uart_enable_dma,
    .disable_dma = uart_disable_dma,
    .read = NULL,
    .write = bsp_uart_send_buf,
    .w_byte = bsp_uart_send_char,
    .r_byte = NULL,
};

int my_puthex8(char c_arg)
{
    char* hex = "0123456789ABCDEF";
    putchar(hex[(c_arg >> 4) & 0x0f]);
    putchar(hex[(c_arg >> 0) & 0x0f]);
    return 0;
}

//int my_printhex(const char *buf, unsigned int len)
//{
//    u8 i = 0;
//	u32 index = 0;
//	printf("\n0x%04x | ",index);
//    while(len--)
//    {
//       if(i++ == 16)
//       {
//           i = 1;
//		   printf("\n0x%04x | ",index+=16);
//       }
//       my_puthex8(*buf++);
//       putchar(' ');
//	   for(int j = 0; j< 10000; j++);
//    }
//	putchar('\n');
//	return len;
//}

int my_printhex(const char* buf, unsigned int len)
{
    u8 i = 0;
    //u32 index = 0;
    //printf("\n0x%04x | ",index);
    while(len--)
    {
        if(i++ == 16)
        {
            i = 1;
            printf("\n");
        }
       // putchar('0');
       // putchar('x');
        my_puthex8(*buf++);
        putchar(' ');
        for(int j = 0; j < 10000; j++);
    }
    putchar('\n');
    return len;
}





#if 1
#if (__ARMCC_VERSION >= 6010050)                    /* 使用AC6编译器时 */
__asm(".global __use_no_semihosting\n\t");          /* 声明不使用半主机模式 */
__asm(".global __ARM_use_no_argv \n\t");            /* AC6下需要声明main函数为无参数格式，否则部分例程可能出现半主机模式 */

#else
/* 使用AC5编译器时, 要在这里定义__FILE 和 不使用半主机模式 */
#pragma import(__use_no_semihosting)

struct __FILE
{
    int handle;
    /* Whatever you require here. If the only file you are using is */
    /* standard output using printf() for debugging, no file handling */
    /* is required. */
};

#endif

/* 不使用半主机模式，至少需要重定义_ttywrch\_sys_exit\_sys_command_string函数,以同时兼容AC6和AC5模式 */
int _ttywrch(int ch)
{
    ch = ch;
    return ch;
}

/* 定义_sys_exit()以避免使用半主机模式 */
void _sys_exit(int x)
{
    x = x;
}

char* _sys_command_string(char* cmd, int len)
{
    return NULL;
}

/* FILE 在 stdio.h里面定义. */
FILE __stdout;
int fputc(int ch, FILE *f)
{
    LL_USART_TransmitData8(DBUG_UART, (unsigned char) ch);
    while(!LL_USART_IsActiveFlag_TXE(DBUG_UART));
    return (ch);
}
#endif

#endif

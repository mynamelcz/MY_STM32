#include "includes.h"

#include "stm32f4xx.h"
#include "bsp_gpio.h"
#include "bsp_uart.h"
#include "bsp_sys.h"
#include "bsp_nvic.h"

#include "time_delay.h"

#include "key.h"
#include "lcd.h"
#include "sdram.h"
#include "stm32f4xx_ll_rcc.h"

void key_0_irq(void)
{
    LOG_D("key irq\n");
}

struct pin_band TRIG1_BAND;
struct pin_band TOUCHKEY_BAND;

void sys_periph_init(void)
{
    /*init tirg pin*/
    BSP_GPIO_DRV.pin_mode(TRIG1_PIN, PIN_Mode_Out_PP, PIN_NoPull, 0);
    BSP_GPIO_DRV.pin_get_bitband(TRIG1_PIN, &TRIG1_BAND);
    TRIG1(1);
    BSP_GPIO_DRV.pin_mode(LED0_PIN, PIN_Mode_Out_PP, PIN_NoPull, 0);
    BSP_GPIO_DRV.pin_mode(LED1_PIN, PIN_Mode_Out_PP, PIN_NoPull, 0);
    LED0(1);
    LED1(1);
    /* key */
    BSP_GPIO_DRV.pin_mode(KEY0_PIN, PIN_Mode_IN, PIN_PullUp, 0);
    BSP_GPIO_DRV.pin_mode(KEY1_PIN, PIN_Mode_IN, PIN_PullUp, 0);
    BSP_GPIO_DRV.pin_mode(KEY2_PIN, PIN_Mode_IN, PIN_PullUp, 0);
    /* touch key */
    BSP_GPIO_DRV.pin_mode(TOUCH_KEY_PIN, PIN_Mode_IN, PIN_NoPull, 0);
    BSP_GPIO_DRV.pin_get_bitband(TOUCH_KEY_PIN, &TOUCHKEY_BAND);
    TOUCH_KEY_OUT_MODE();
    TOUCH_KEY(0);
    
    BSP_GPIO_DRV.pin_mode(KEYUP_PIN, PIN_Mode_IT_RISING, PIN_PullUp, 0);
    BSP_GPIO_DRV.pin_irq_enable(KEYUP_PIN,key_0_irq);

    /* UART */
    BSP_GPIO_DRV.pin_mode(UART1_TX_PIN, PIN_Mode_AF_PP, PIN_PullUp, GPIO_AF7_USART1);
    BSP_GPIO_DRV.pin_mode(UART1_RX_PIN, PIN_Mode_AF_PP, PIN_PullUp, GPIO_AF7_USART1);
    BSP_UART_DRV.init(UART1_INDEX);

}

void getClocks(void)
{
    LL_RCC_ClocksTypeDef RCC_Clocks;
    LL_RCC_GetSystemClocksFreq(&RCC_Clocks);
    LOG_D("SYSCLK_Frequency = %dHz\n", RCC_Clocks.SYSCLK_Frequency);
    LOG_D("HCLK_Frequency   = %dHz\n", RCC_Clocks.HCLK_Frequency);
    LOG_D("PCLK1_Frequency  =  %dHz\n", RCC_Clocks.PCLK1_Frequency);
    LOG_D("PCLK2_Frequency  =  %dHz\n", RCC_Clocks.PCLK2_Frequency);

}



/**
 * @brief       SDRAM内存测试
 * @param       x,y    :起点坐标
 * @retval      无
*/
void sdram_test(uint16_t x, uint16_t y)
{  
    uint32_t i = 0;
    uint32_t temp = 0;
    uint32_t sval = 0;       /* 在地址0读到的数据 */

    /* 每隔16K字节,写入一个数据,总共写入2048个数据,刚好是32M字节 */
    for (i = 0; i < 32 * 1024 * 1024; i += 16 * 1024)
    {
        *(volatile uint32_t *)(SDRAM_ADDR + i) = temp; 
        temp++;
    }

    /* 依次读出之前写入的数据,进行校验 */
    for (i = 0; i < 32 * 1024 * 1024; i += 16 * 1024) 
    {
        temp =*(volatile uint32_t*)(SDRAM_ADDR + i);

        if (i == 0)
        {
            sval = temp;
        }
        else if (temp <= sval)
        {
            break;         /* 后面读出的数据一定要比第一次读到的数据大 */
        }

        
        lcd_printf(x,y,ST7789_FONT_24,BLACK,"%d\n",(uint16_t)(temp - sval + 1) * 16);
     //   printf("SDRAM Capacity:%dKB\r\n", (uint16_t)(temp - sval + 1) * 16);           /* 打印SDRAM容量 */
    }
}



extern void lcd_test(void);

int main(void)
{
    BSP_Sys.init();
    TimeDelay.init(180);
    BSP_GPIO_DRV.hw_init();
    BSP_NVIC_DRV.init();
    sys_periph_init();

    LOG_D(">>>>>>>>>>	Power On	<<<<<<<<<<<\n");
    timer_loop_init();
    init_key_detect();
    getClocks();
    
    lcd_init();
    sdram_init();
    
    lcd_backlight(1);
    lcd_clear(BACKGROUND_COLOR);
    sdram_test(30, 170); 
    while(1)
    {
      
        TimeDelay.delay_ms(250);
        LED1(1);LED0(0);
        TimeDelay.delay_ms(250);
        LED1(0);LED0(1);
    }
}
void my_assert_failed(uint8_t* file, uint32_t line)
{
    /* User can add his own implementation to report the file name and line number,
       ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

    /* Infinite loop */
    while(1)
    {}
}



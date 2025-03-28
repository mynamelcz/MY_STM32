#include "includes.h"

#include "stm32f4xx.h"
#include "bsp_gpio.h"
#include "bsp_uart.h"
#include "bsp_sys.h"
#include "bsp_nvic.h"

#include "time_delay.h"

#include "key.h"

#include "stm32f4xx_ll_rcc.h"

void key_0_irq(void)
{
    LOG_D("key irq\n");
}

struct pin_band TRIG1_BAND;
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

    BSP_GPIO_DRV.pin_mode(KEY0_PIN, PIN_Mode_IN, PIN_PullUp, 0);
    BSP_GPIO_DRV.pin_mode(KEY1_PIN, PIN_Mode_IN, PIN_PullUp, 0);
    BSP_GPIO_DRV.pin_mode(KEY2_PIN, PIN_Mode_IN, PIN_PullUp, 0);

    
    BSP_GPIO_DRV.pin_mode(KEYUP_PIN, PIN_Mode_IT_RISING, PIN_PullUp, 0);
    BSP_GPIO_DRV.pin_irq_enable(KEYUP_PIN,key_0_irq);

    /* UART */
    BSP_GPIO_DRV.pin_mode(UART1_TX_PIN, PIN_Mode_AF_PP, PIN_PullUp, GPIO_AF7_USART1);
    BSP_GPIO_DRV.pin_mode(UART1_RX_PIN, PIN_Mode_AF_PP, PIN_PullUp, GPIO_AF7_USART1);
    BSP_UART_DRV.init(UART1_INDEX);

}

void getClocks(void)//²âÊÔ³ÌÐò
{
    LL_RCC_ClocksTypeDef RCC_Clocks;
    LL_RCC_GetSystemClocksFreq(&RCC_Clocks);
    LOG_D("SYSCLK_Frequency = %dHz\n", RCC_Clocks.SYSCLK_Frequency);
    LOG_D("HCLK_Frequency   = %dHz\n", RCC_Clocks.HCLK_Frequency);
    LOG_D("PCLK1_Frequency  =  %dHz\n", RCC_Clocks.PCLK1_Frequency);
    LOG_D("PCLK2_Frequency  =  %dHz\n", RCC_Clocks.PCLK2_Frequency);

}







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



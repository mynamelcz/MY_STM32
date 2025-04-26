#include "includes.h"
#include "stm32f4xx_ll_rcc.h"

#include "stm32f4xx.h"
#include "bsp_gpio.h"
#include "bsp_uart.h"
#include "bsp_sys.h"
#include "bsp_nvic.h"

#include "time_delay.h"

#include "key.h"
#include "mcu_lcd.h"
#include "rgb_lcd.h"
#include "sdram.h"
#include "eeprom.h"
#include "touch_resistive.h"

#include "lvgl.h"
#include "lv_port_disp_template.h"
#include "lv_port_indev_template.h"

void key_0_irq(void)
{
    LOG_D("key irq\n");
}

struct pin_band TRIG1_BAND;
struct pin_band TRIG2_BAND;
struct pin_band TOUCHKEY_BAND;


void sys_periph_init(void)
{
    /*init tirg pin*/
    BSP_GPIO_DRV.pin_mode(TRIG1_PIN, PIN_Mode_Out_PP, PIN_NoPull, 0);
    BSP_GPIO_DRV.pin_get_bitband(TRIG1_PIN, &TRIG1_BAND);
    BSP_GPIO_DRV.pin_mode(TRIG2_PIN, PIN_Mode_Out_PP, PIN_NoPull, 0);
    BSP_GPIO_DRV.pin_get_bitband(TRIG2_PIN, &TRIG2_BAND);
    TRIG1(1);
    TRIG2(1);
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
    BSP_GPIO_DRV.pin_irq_enable(KEYUP_PIN, key_0_irq);

    /* IIC */
    BSP_GPIO_DRV.pin_mode(IIC_SCL_PIN, PIN_Mode_Out_PP, PIN_NoPull, 0);
    BSP_GPIO_DRV.pin_mode(IIC_SDA_PIN, PIN_Mode_Out_PP, PIN_NoPull, 0);

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





void lv_tick(void)
{
    TRIG1(1);
    lv_tick_inc(2);
    TRIG1(0);
}
__IRQ_HdlTypedef(lv_tick, 2);


extern void touch_test(void);


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

    //touch_test();


    register_timer_handler(T_IRQ_Hdl(lv_tick));
    lv_init();
    lv_port_disp_init();
    lv_port_indev_init();


//    lv_obj_t *switch_obj = lv_switch_create(lv_scr_act());
//    lv_obj_set_size(switch_obj, 100, 50);
//    lv_obj_align(switch_obj, LV_ALIGN_CENTER, 0, 0);



//    char* github_addr = "https://gitee.com/W23";
//    lv_obj_t * label = lv_label_create(lv_scr_act());
//    lv_label_set_recolor(label, true);
//    lv_label_set_long_mode(label, LV_LABEL_LONG_SCROLL_CIRCULAR); /*Circular scroll*/
//    lv_obj_set_width(label, 120);
//    lv_label_set_text_fmt(label, "#ff0000 Gitee: %s#", github_addr);
//    lv_obj_align(label, LV_ALIGN_TOP_LEFT, 0, 10);
//
//    lv_obj_t * label2 = lv_label_create(lv_scr_act());
//    lv_label_set_recolor(label2, true);
//    lv_label_set_long_mode(label2, LV_LABEL_LONG_SCROLL_CIRCULAR); /*Circular scroll*/
//    lv_obj_set_width(label2, 120);
//    lv_label_set_text_fmt(label2, "#ff0000 Hello# #0000ff world !123456789#");
//    lv_obj_align(label2, LV_ALIGN_CENTER, 0, -10);



    while(1)
    {
        TimeDelay.delay_ms(5);
        lv_task_handler();

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



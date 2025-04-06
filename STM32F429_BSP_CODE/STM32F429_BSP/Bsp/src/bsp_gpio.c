#include "bsp_gpio.h"
#include "includes.h"
#include "stm32f4xx.h"


static int stm32_get_pin_bitband_addr(GPIO_TypeDef* gpio, u8 pin_num, struct pin_band* band)
{
    band->IDR = BITBAND_ADDR((u32)(&(gpio->IDR)), pin_num);
    band->ODR = BITBAND_ADDR((u32)(&(gpio->ODR)), pin_num);
    band->MODER = BITBAND_ADDR((u32)(&(gpio->MODER)), (pin_num) << 1);
    return 0;
}

static void stm32_pin_write(GPIO_TypeDef* gpio, u8 pin_num, u8 value)
{
    if(value)
    {
        gpio->BSRR = 1 << pin_num;
    }
    else
    {
        gpio->BSRR = 1 << (pin_num + 16);
    }
}

static int stm32_pin_read(GPIO_TypeDef* gpio, u8 pin_num)
{
    if(gpio->IDR & (1 << pin_num))
        return 1;
    return 0;
}

static void stm32_pin_tol(GPIO_TypeDef* gpio, u8 pin_num)
{
    gpio->ODR ^= (1 << pin_num);
}

static void stm32_pin_mode(GPIO_TypeDef* gpio, u8 pin_num, PinMode_E mode, PinPUPD_E pupd, uint32_t AF)
{
    GPIO_InitTypeDef GPIO_InitStruct;
    GPIO_InitStruct.Pin = (1 << pin_num);
    GPIO_InitStruct.Pull = pupd;
    GPIO_InitStruct.Mode = mode;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
    GPIO_InitStruct.Alternate = AF;
    HAL_GPIO_Init(gpio, &GPIO_InitStruct);
}

static void stm32_pin_cfg_AF(GPIO_TypeDef* gpio, u8 pin_num, u8 GPIO_AF)
{
    if(pin_num <= 7)
    {
        LL_GPIO_SetAFPin_0_7(gpio, (1 << pin_num), GPIO_AF);
    }
    else
    {
        LL_GPIO_SetAFPin_8_15(gpio, (1 << pin_num), GPIO_AF);
    }
}



static irq_fun_t pin_irq_hdr_tab[16] =
{
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
};


static const u32 pin_irq_map[16] =
{
    /* GPIO_Pin_0 */ EXTI0_IRQn,
    /* GPIO_Pin_1 */ EXTI1_IRQn,
    /* GPIO_Pin_2 */ EXTI2_IRQn,
    /* GPIO_Pin_3 */ EXTI3_IRQn,
    /* GPIO_Pin_4 */ EXTI4_IRQn,
    /* GPIO_Pin_5 */ EXTI9_5_IRQn,
    /* GPIO_Pin_6 */ EXTI9_5_IRQn,
    /* GPIO_Pin_7 */ EXTI9_5_IRQn,
    /* GPIO_Pin_8 */ EXTI9_5_IRQn,
    /* GPIO_Pin_9 */ EXTI9_5_IRQn,
    /* GPIO_Pin_10*/ EXTI15_10_IRQn,
    /* GPIO_Pin_11*/ EXTI15_10_IRQn,
    /* GPIO_Pin_12*/ EXTI15_10_IRQn,
    /* GPIO_Pin_13*/ EXTI15_10_IRQn,
    /* GPIO_Pin_14*/ EXTI15_10_IRQn,
    /* GPIO_Pin_15*/ EXTI15_10_IRQn,

};

#include "bsp_nvic.h"
#include "stm32f4xx_ll_exti.h"

static void stm32_pin_irq_enable(GPIO_TypeDef* gpio, u8 pin_num, irq_fun_t fun)
{
    pin_irq_hdr_tab[pin_num] = fun;
    BSP_NVIC_DRV.enable_irq(pin_irq_map[pin_num], 1, 3);
}

static void stm32_pin_irq_disable(GPIO_TypeDef* gpio, u8 pin_num)
{
    u32 irqn = pin_irq_map[pin_num];
    pin_irq_hdr_tab[pin_num] = NULL;
    for(int pin = 0; pin < 16; pin++)
    {
        if((pin_irq_map[pin] == irqn) && (pin_irq_hdr_tab[pin]) != NULL)
        {
            return;
        }
    }
    BSP_NVIC_DRV.disable_irq(irqn);
}


void EXTI0_IRQHandler(void)
{
    u8 line = 0;
    if(LL_EXTI_ReadFlag_0_31(1 << line))
    {
        EXTI->IMR &= ~(1 << line);
        LL_EXTI_ClearFlag_0_31((1 << line));
        if(pin_irq_hdr_tab[line] != NULL)
            pin_irq_hdr_tab[line]();
        EXTI->IMR |= (1 << line);
    }
}
void EXTI1_IRQHandler(void)
{
    u8 line = 1;
    if(LL_EXTI_ReadFlag_0_31(1 << line))
    {
        EXTI->IMR &= ~(1 << line);
        LL_EXTI_ClearFlag_0_31((1 << line));
        if(pin_irq_hdr_tab[line] != NULL)
            pin_irq_hdr_tab[line]();
        EXTI->IMR |= (1 << line);
    }
}
void EXTI2_IRQHandler(void)
{
    u8 line = 2;
    if(LL_EXTI_ReadFlag_0_31(1 << line))
    {
        EXTI->IMR &= ~(1 << line);
        LL_EXTI_ClearFlag_0_31((1 << line));
        if(pin_irq_hdr_tab[line] != NULL)
            pin_irq_hdr_tab[line]();
        EXTI->IMR |= (1 << line);
    }
}
void EXTI3_IRQHandler(void)
{
    u8 line = 3;
    if(LL_EXTI_ReadFlag_0_31(1 << line))
    {
        EXTI->IMR &= ~(1 << line);
        LL_EXTI_ClearFlag_0_31((1 << line));
        if(pin_irq_hdr_tab[line] != NULL)
            pin_irq_hdr_tab[line]();
        EXTI->IMR |= (1 << line);
    }
}
void EXTI4_IRQHandler(void)
{
    u8 line = 4;
    if(LL_EXTI_ReadFlag_0_31(1 << line))
    {
        EXTI->IMR &= ~(1 << line);
        LL_EXTI_ClearFlag_0_31((1 << line));
        if(pin_irq_hdr_tab[line] != NULL)
            pin_irq_hdr_tab[line]();
        EXTI->IMR |= (1 << line);
    }
}
void EXTI9_5_IRQHandler(void)
{
    u8 line = 5;
    if(LL_EXTI_ReadFlag_0_31(LL_EXTI_LINE_5))
    {
        line = 5;
    }
    if(LL_EXTI_ReadFlag_0_31(LL_EXTI_LINE_6))
    {
        line = 6;
    }
    if(LL_EXTI_ReadFlag_0_31(LL_EXTI_LINE_7))
    {
        line = 7;
    }
    if(LL_EXTI_ReadFlag_0_31(LL_EXTI_LINE_8))
    {
        line = 8;
    }
    if(LL_EXTI_ReadFlag_0_31(LL_EXTI_LINE_9))
    {
        line = 9;
    }
    EXTI->IMR &= ~(1 << line);
    LL_EXTI_ClearFlag_0_31((1 << line));
    if(pin_irq_hdr_tab[line] != NULL)
        pin_irq_hdr_tab[line]();
    EXTI->IMR |= (1 << line);
}
void EXTI15_10_IRQHandler(void)
{
    u8 line = 10;
    if(LL_EXTI_ReadFlag_0_31(LL_EXTI_LINE_10))
    {
        line = 10;
    }
    if(LL_EXTI_ReadFlag_0_31(LL_EXTI_LINE_11))
    {
        line = 11;
    }
    if(LL_EXTI_ReadFlag_0_31(LL_EXTI_LINE_12))
    {
        line = 12;
    }
    if(LL_EXTI_ReadFlag_0_31(LL_EXTI_LINE_13))
    {
        line = 13;
    }
    if(LL_EXTI_ReadFlag_0_31(LL_EXTI_LINE_14))
    {
        line = 14;
    }
    if(LL_EXTI_ReadFlag_0_31(LL_EXTI_LINE_15))
    {
        line = 15;
    }
    EXTI->IMR &= ~(1 << line);
    LL_EXTI_ClearFlag_0_31((1 << line));
    if(pin_irq_hdr_tab[line] != NULL)
        pin_irq_hdr_tab[line]();
    EXTI->IMR |= (1 << line);
}




static void stm32_hw_pin_init(void)
{
    __HAL_RCC_GPIOA_CLK_ENABLE();
    __HAL_RCC_GPIOB_CLK_ENABLE();
    __HAL_RCC_GPIOC_CLK_ENABLE();
    __HAL_RCC_GPIOD_CLK_ENABLE();
    __HAL_RCC_GPIOE_CLK_ENABLE();
    __HAL_RCC_GPIOF_CLK_ENABLE();
    __HAL_RCC_GPIOG_CLK_ENABLE();
    __HAL_RCC_GPIOH_CLK_ENABLE();
    __HAL_RCC_GPIOI_CLK_ENABLE();
    __HAL_RCC_GPIOJ_CLK_ENABLE();
    __HAL_RCC_GPIOK_CLK_ENABLE();
}

const struct __bsp_gpio_drv BSP_GPIO_DRV =
{
    .hw_init = stm32_hw_pin_init,
    .pin_mode = stm32_pin_mode,
    .pin_cfgAF = stm32_pin_cfg_AF,
    .pin_read = stm32_pin_read,
    .pin_write = stm32_pin_write,
    .pin_tol = stm32_pin_tol,
    .pin_get_bitband = stm32_get_pin_bitband_addr,
    .pin_irq_enable = stm32_pin_irq_enable,
    .pin_irq_disable = stm32_pin_irq_disable,
};

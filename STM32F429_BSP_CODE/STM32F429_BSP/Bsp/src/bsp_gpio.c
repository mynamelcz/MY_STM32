#include "bsp_gpio.h"
#include "includes.h"
#include "stm32f4xx.h"


static int stm32_get_pin_bitband_addr(GPIO_TypeDef *gpio, u8 pin_num, struct pin_band *band)
{
    band->IDR = BITBAND_ADDR((u32)(&(gpio->IDR)), pin_num);
    band->ODR = BITBAND_ADDR((u32)(&(gpio->ODR)), pin_num);
    band->MODER = BITBAND_ADDR((u32)(&(gpio->MODER)), (pin_num) << 1);
    return 0;
}

static void stm32_pin_write(GPIO_TypeDef *gpio, u8 pin_num, u8 value)
{
    if (value)
    {
        gpio->BSRR = 1 << pin_num;
    }
    else
    {
        gpio->BSRR = 1 << (pin_num + 16);
    }
}

static int stm32_pin_read(GPIO_TypeDef *gpio, u8 pin_num)
{
    if (gpio->IDR & (1 << pin_num))
        return 1;
    return 0;
}

static void stm32_pin_tol(GPIO_TypeDef *gpio, u8 pin_num)
{
    gpio->ODR ^= (1 << pin_num);
}

static void stm32_pin_mode(GPIO_TypeDef *gpio, u8 pin_num, PinMode_E mode, PinPUPD_E pupd,uint32_t AF)
{
    GPIO_InitTypeDef GPIO_InitStruct;
    GPIO_InitStruct.Pin = (1 << pin_num);
    GPIO_InitStruct.Pull = pupd;
    GPIO_InitStruct.Mode = mode;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
    GPIO_InitStruct.Alternate = AF;
    HAL_GPIO_Init(gpio, &GPIO_InitStruct);
}

static void stm32_pin_cfg_AF(GPIO_TypeDef *gpio, u8 pin_num, u8 GPIO_AF)
{
    if (pin_num <= 7)
    {
        LL_GPIO_SetAFPin_0_7(gpio, (1 << pin_num), GPIO_AF);
    }
    else
    {
        LL_GPIO_SetAFPin_8_15(gpio, (1 << pin_num), GPIO_AF);
    }
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

const struct __bsp_gpio_drv BSP_GPIO_DRV = {
    .hw_init = stm32_hw_pin_init,
    .pin_mode = stm32_pin_mode,
    .pin_cfgAF = stm32_pin_cfg_AF,
    .pin_read = stm32_pin_read,
    .pin_write = stm32_pin_write,
    .pin_tol = stm32_pin_tol,
    .pin_get_bitband = stm32_get_pin_bitband_addr,
};

#include "bsp_ltdc.h"
#include "stm32f4xx.h"
#include "time_delay.h"




static void ltdc_init(void)
{
  
}




const struct __bsp_ltdc_drv BSP_LTDC_DRV =
{
    .ltdc_init = ltdc_init,
};















#include "sdram.h"
#include "bsp_fmc.h"
#include "bsp_gpio.h"











void sdram_init(void)
{


    BSP_GPIO_DRV.pin_mode(FMC_NBL0_PIN, PIN_Mode_AF_PP, PIN_PullUp, GPIO_AF12_FMC);     // FMC PE0
    BSP_GPIO_DRV.pin_mode(FMC_NBL1_PIN, PIN_Mode_AF_PP, PIN_PullUp, GPIO_AF12_FMC);     // FMC PE1
    BSP_GPIO_DRV.pin_mode(FMC_SDNRAS_PIN, PIN_Mode_AF_PP, PIN_PullUp, GPIO_AF12_FMC);   // FMC PF11

    BSP_GPIO_DRV.pin_mode(FMC_BA0_PIN, PIN_Mode_AF_PP, PIN_PullUp, GPIO_AF12_FMC);      // FMC PG4
    BSP_GPIO_DRV.pin_mode(FMC_BA1_PIN, PIN_Mode_AF_PP, PIN_PullUp, GPIO_AF12_FMC);      // FMC PG5
    
    BSP_GPIO_DRV.pin_mode(FMC_SDNWE_PIN, PIN_Mode_AF_PP, PIN_PullUp, GPIO_AF12_FMC);    // FMC PC0
    BSP_GPIO_DRV.pin_mode(FMC_SDNE0_PIN, PIN_Mode_AF_PP, PIN_PullUp, GPIO_AF12_FMC);    // FMC PC2
    BSP_GPIO_DRV.pin_mode(FMC_SDCKE0_PIN, PIN_Mode_AF_PP, PIN_PullUp, GPIO_AF12_FMC);   // FMC PC3
    BSP_GPIO_DRV.pin_mode(FMC_SDCLK_PIN, PIN_Mode_AF_PP, PIN_PullUp, GPIO_AF12_FMC);    // FMC PG8
    BSP_GPIO_DRV.pin_mode(FMC_SDNCAS_PIN, PIN_Mode_AF_PP, PIN_PullUp, GPIO_AF12_FMC);   // FMC PG15
    
    
    
    BSP_GPIO_DRV.pin_mode(FMC_D0_PIN, PIN_Mode_AF_PP, PIN_PullUp, GPIO_AF12_FMC); // FMC PD14   D0
    BSP_GPIO_DRV.pin_mode(FMC_D1_PIN, PIN_Mode_AF_PP, PIN_PullUp, GPIO_AF12_FMC); // FMC PD15   D1  
    BSP_GPIO_DRV.pin_mode(FMC_D2_PIN, PIN_Mode_AF_PP, PIN_PullUp, GPIO_AF12_FMC); // FMC PD0    D2
    BSP_GPIO_DRV.pin_mode(FMC_D3_PIN, PIN_Mode_AF_PP, PIN_PullUp, GPIO_AF12_FMC); // FMC PD1    D3
    BSP_GPIO_DRV.pin_mode(FMC_D4_PIN, PIN_Mode_AF_PP, PIN_PullUp, GPIO_AF12_FMC); // FMC PE7    D4 
    BSP_GPIO_DRV.pin_mode(FMC_D5_PIN, PIN_Mode_AF_PP, PIN_PullUp, GPIO_AF12_FMC); // FMC PE8    D5
    BSP_GPIO_DRV.pin_mode(FMC_D6_PIN, PIN_Mode_AF_PP, PIN_PullUp, GPIO_AF12_FMC); // FMC PE9    D6
    BSP_GPIO_DRV.pin_mode(FMC_D7_PIN, PIN_Mode_AF_PP, PIN_PullUp, GPIO_AF12_FMC); // FMC PE10   D7
    BSP_GPIO_DRV.pin_mode(FMC_D8_PIN, PIN_Mode_AF_PP, PIN_PullUp, GPIO_AF12_FMC); // FMC PE11   D8
    BSP_GPIO_DRV.pin_mode(FMC_D9_PIN, PIN_Mode_AF_PP, PIN_PullUp, GPIO_AF12_FMC); // FMC PE12   D9
    BSP_GPIO_DRV.pin_mode(FMC_D10_PIN, PIN_Mode_AF_PP, PIN_PullUp, GPIO_AF12_FMC); // FMC PE13  D10
    BSP_GPIO_DRV.pin_mode(FMC_D11_PIN, PIN_Mode_AF_PP, PIN_PullUp, GPIO_AF12_FMC); // FMC PE14  D11
    BSP_GPIO_DRV.pin_mode(FMC_D12_PIN, PIN_Mode_AF_PP, PIN_PullUp, GPIO_AF12_FMC); // FMC PE15  D12
    BSP_GPIO_DRV.pin_mode(FMC_D13_PIN, PIN_Mode_AF_PP, PIN_PullUp, GPIO_AF12_FMC); // FMC PD8   D13
    BSP_GPIO_DRV.pin_mode(FMC_D14_PIN, PIN_Mode_AF_PP, PIN_PullUp, GPIO_AF12_FMC); // FMC PD9   D14
    BSP_GPIO_DRV.pin_mode(FMC_D15_PIN, PIN_Mode_AF_PP, PIN_PullUp, GPIO_AF12_FMC); // FMC PD10  D15
    
    BSP_GPIO_DRV.pin_mode(FMC_A0_PIN, PIN_Mode_AF_PP, PIN_PullUp, GPIO_AF12_FMC); // FMC PF0    A0
    BSP_GPIO_DRV.pin_mode(FMC_A1_PIN, PIN_Mode_AF_PP, PIN_PullUp, GPIO_AF12_FMC); // FMC PF1    A1
    BSP_GPIO_DRV.pin_mode(FMC_A2_PIN, PIN_Mode_AF_PP, PIN_PullUp, GPIO_AF12_FMC); // FMC PF2    A2
    BSP_GPIO_DRV.pin_mode(FMC_A3_PIN, PIN_Mode_AF_PP, PIN_PullUp, GPIO_AF12_FMC); // FMC PF3    A3
    BSP_GPIO_DRV.pin_mode(FMC_A4_PIN, PIN_Mode_AF_PP, PIN_PullUp, GPIO_AF12_FMC); // FMC PF4    A4
    BSP_GPIO_DRV.pin_mode(FMC_A5_PIN, PIN_Mode_AF_PP, PIN_PullUp, GPIO_AF12_FMC); // FMC PF5    A5
    BSP_GPIO_DRV.pin_mode(FMC_A6_PIN, PIN_Mode_AF_PP, PIN_PullUp, GPIO_AF12_FMC); // FMC PF12   A6
    BSP_GPIO_DRV.pin_mode(FMC_A7_PIN, PIN_Mode_AF_PP, PIN_PullUp, GPIO_AF12_FMC); // FMC PF13   A7
    BSP_GPIO_DRV.pin_mode(FMC_A8_PIN, PIN_Mode_AF_PP, PIN_PullUp, GPIO_AF12_FMC); // FMC PF14   A8
    BSP_GPIO_DRV.pin_mode(FMC_A9_PIN, PIN_Mode_AF_PP, PIN_PullUp, GPIO_AF12_FMC); // FMC PF15   A9
    BSP_GPIO_DRV.pin_mode(FMC_A10_PIN, PIN_Mode_AF_PP, PIN_PullUp, GPIO_AF12_FMC); // FMC PG0   A10
    BSP_GPIO_DRV.pin_mode(FMC_A11_PIN, PIN_Mode_AF_PP, PIN_PullUp, GPIO_AF12_FMC); // FMC PG1   A11
    BSP_GPIO_DRV.pin_mode(FMC_A12_PIN, PIN_Mode_AF_PP, PIN_PullUp, GPIO_AF12_FMC); // FMC PG2   A12
    
    BSP_FMC_DRV.sdram_init(); 
    




}
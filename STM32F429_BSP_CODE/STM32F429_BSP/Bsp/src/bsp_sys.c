#include "stm32f4xx.h"
#include "bsp_sys.h"



/**
 * @brief       时钟设置函数
 * @param       plln: PLL1倍频系数(PLL倍频), 取值范围: 64~432.
 * @param       pllm: PLL1预分频系数(进PLL之前的分频), 取值范围: 2~63.
 * @param       pllp: PLL1的p分频系数(PLL之后的分频), 分频后作为系统时钟, 取值范围: 2,4,6,8.(仅限这4个值!)
 * @param       pllq: PLL1的q分频系数(PLL之后的分频), 取值范围: 2~15.
 * @note
 *
 *              Fvco: VCO频率
 *              Fsys: 系统时钟频率, 也是PLL1的p分频输出时钟频率
 *              Fq:   PLL1的q分频输出时钟频率
 *              Fs:   PLL输入时钟频率, 可以是HSI, HSE等.
 *              Fvco = Fs * (plln / pllm);
 *              Fsys = Fvco / pllp = Fs * (plln / (pllm * pllp));
 *              Fq   = Fvco / pllq = Fs * (plln / (pllm * pllq));
 *
 *              外部晶振为25M的时候, 推荐值: plln = 360, pllm = 25, pllp = 2, pllq = 8.
 *              得到:Fvco = 25 * (360 / 25) = 360Mhz
 *                   Fsys = pll1_p_ck = 360 / 2 = 180Mhz
 *                   Fq   = pll1_q_ck = 360 / 8 = 45(使用USB时，需设置plln=384，即可得到48Mhz频率, 此时主频为192M)
 *
 *              F429默认需要配置的频率如下:
 *              CPU频率(HCLK) = pll_p_ck = 180Mhz
 *              AHB1/2/3(rcc_hclk1/2/3) = 180Mhz
 *              APB1(rcc_pclk1) = pll_p_ck / 4 = 45Mhz
 *              APB2(rcc_pclk2) = pll_p_ck / 2 = 90Mhz
 *
 * @retval      错误代码: 0, 成功; 1, 错误;
 */
static uint8_t clock_init(uint32_t plln, uint32_t pllm, uint32_t pllp, uint32_t pllq)
{
    HAL_StatusTypeDef ret = HAL_OK;
    RCC_ClkInitTypeDef rcc_clk_init = {0};
    RCC_OscInitTypeDef rcc_osc_init = {0};
    
    __HAL_RCC_PWR_CLK_ENABLE();                                     /* 使能PWR时钟 */
    
    /* 下面这个设置用来设置调压器输出电压级别，以便在器件未以最大频率工作时使性能与功耗实现平衡 */
    __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);  /* 调压器输出电压级别选择：级别1模式 */

    /* 使能HSE，并选择HSE作为PLL时钟源，配置PLL1，开启USB时钟 */
    rcc_osc_init.OscillatorType = RCC_OSCILLATORTYPE_HSE;           /* 时钟源为HSE */
    rcc_osc_init.HSEState = RCC_HSE_ON;                             /* 打开HSE */
    rcc_osc_init.PLL.PLLState = RCC_PLL_ON;                         /* 打开PLL */
    rcc_osc_init.PLL.PLLSource = RCC_PLLSOURCE_HSE;                 /* PLL时钟源选择HSE */
    rcc_osc_init.PLL.PLLN = plln;
    rcc_osc_init.PLL.PLLM = pllm;
    rcc_osc_init.PLL.PLLP = pllp;
    rcc_osc_init.PLL.PLLQ = pllq;
    ret = HAL_RCC_OscConfig(&rcc_osc_init);                         /* 初始化RCC */
    if (ret != HAL_OK)
    {
        return 1;                                                   /* 时钟初始化失败，可以在这里加入自己的处理 */
    }
    ret = HAL_PWREx_EnableOverDrive();                              /* 开启Over-Driver功能 */
    if (ret != HAL_OK)
    {
        return 1;
    }

    /* 选中PLL作为系统时钟源并且配置HCLK,PCLK1和PCLK2*/
    rcc_clk_init.ClockType = ( RCC_CLOCKTYPE_SYSCLK \
                                    | RCC_CLOCKTYPE_HCLK \
                                    | RCC_CLOCKTYPE_PCLK1 \
                                    | RCC_CLOCKTYPE_PCLK2);

    rcc_clk_init.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;            /* 设置系统时钟时钟源为PLL */
    rcc_clk_init.AHBCLKDivider = RCC_SYSCLK_DIV1;                   /* AHB分频系数为1 */
    rcc_clk_init.APB1CLKDivider = RCC_HCLK_DIV4;                    /* APB1分频系数为4 */
    rcc_clk_init.APB2CLKDivider = RCC_HCLK_DIV2;                    /* APB2分频系数为2 */
    ret = HAL_RCC_ClockConfig(&rcc_clk_init, FLASH_LATENCY_5);      /* 同时设置FLASH延时周期为5WS，也就是6个CPU周期 */
    if (ret != HAL_OK)
    {
        return 1;                                                   /* 时钟初始化失败 */
    }
    return 0;
}




/****************	随机数	********************/
static void bsp_rng_init(void)
{
//	RCC_AHB2PeriphClockCmd(RCC_AHB2Periph_RNG,ENABLE);
//	RNG_Cmd(ENABLE);
}

static uint32_t bsp_get_randnum(void)
{
	uint32_t rand;
//	while(!RNG_GetFlagStatus(RNG_FLAG_DRDY));
//	rand = RNG_GetRandomNumber();
	return rand;
}
/****************	看门狗	********************/
static void bsp_iwdg_init(void)
{
//	IWDG_WriteAccessCmd(IWDG_WriteAccess_Enable);
//	IWDG_SetPrescaler(IWDG_Prescaler_32);	// 32K LSI 
//	IWDG_SetReload(0x0fff);
}
	
static void bsp_iwdg_start(void)
{
//	IWDG_Enable();
}
static void bsp_iwdg_clear(void)
{
//	IWDG_ReloadCounter();
}



void bsp_sys_init(void)
{
    clock_init(360, 25, 2, 8);            /* 设置时钟,180Mhz */
	bsp_rng_init();
	bsp_iwdg_init();
}








const struct __bsp_sys	BSP_Sys = {
	.init		 = bsp_sys_init,
	.get_randnum = bsp_get_randnum,
	.start_iwdt  = bsp_iwdg_start,
	.clear_iwdt  = bsp_iwdg_clear,
};



#include "bsp_timer.h"


#ifdef __USING_BSP_TIM_DRV


const struct stm32_timer_config Timer_Cfg_Tab[] =
{
#ifdef BSP_USING_TIME1
	TIMER1_CONFIG,
#endif
#ifdef BSP_USING_TIME2
	TIMER2_CONFIG,
#endif
#ifdef BSP_USING_TIME3
	TIMER3_CONFIG,
#endif
#ifdef BSP_USING_TIME4
	TIMER4_CONFIG,
#endif
#ifdef BSP_USING_TIME5
	TIMER5_CONFIG,
#endif
#ifdef BSP_USING_TIME6
	TIMER6_CONFIG,
#endif
#ifdef BSP_USING_TIME7
	TIMER7_CONFIG,
#endif
#ifdef BSP_USING_TIME8
	TIMER8_CONFIG,
#endif
#ifdef BSP_USING_TIME9
	TIMER9_CONFIG,
#endif
#ifdef BSP_USING_TIME10
	TIMER10_CONFIG,
#endif
#ifdef BSP_USING_TIME11
	TIMER11_CONFIG,
#endif
#ifdef BSP_USING_TIME12
	TIMER12_CONFIG,
#endif
#ifdef BSP_USING_TIME13
	TIMER13_CONFIG,
#endif
#ifdef BSP_USING_TIME14
	TIMER14_CONFIG,
#endif

};



static void bsp_timex_baseinit(enum TIM_INDEX timer_index)
{
	LL_TIM_InitTypeDef *InitStruct_p = (LL_TIM_InitTypeDef *)&Timer_Cfg_Tab[timer_index].BScfg;
	TIM_TypeDef *TIMx = Timer_Cfg_Tab[timer_index].Instance;
#ifdef BSP_USING_TIME1
	if(timer_index == TIME1_INDEX){
        __HAL_RCC_TIM1_CLK_ENABLE();
	}
#endif
#ifdef BSP_USING_TIME2
	if(timer_index == TIME2_INDEX){
		__HAL_RCC_TIM2_CLK_ENABLE();
	}
#endif
#ifdef BSP_USING_TIME3
	if(timer_index == TIME3_INDEX){
		__HAL_RCC_TIM3_CLK_ENABLE();
	}
#endif
#ifdef BSP_USING_TIME4
	if(timer_index == TIME4_INDEX){
		__HAL_RCC_TIM4_CLK_ENABLE();
	}
#endif
#ifdef BSP_USING_TIME5
	if(timer_index == TIME5_INDEX){
		__HAL_RCC_TIM5_CLK_ENABLE();
	}
#endif
#ifdef BSP_USING_TIME6
	if(timer_index == TIME6_INDEX){
		__HAL_RCC_TIM6_CLK_ENABLE();
	}
#endif
#ifdef BSP_USING_TIME7
	if(timer_index == TIME7_INDEX){
		__HAL_RCC_TIM7_CLK_ENABLE();
	}
#endif
#ifdef BSP_USING_TIME8
	if(timer_index == TIME8_INDEX){
		__HAL_RCC_TIM8_CLK_ENABLE();		
	}
#endif
#ifdef BSP_USING_TIME9
	if(timer_index == TIME9_INDEX){
		__HAL_RCC_TIM9_CLK_ENABLE();
	}
#endif
#ifdef BSP_USING_TIME10
	if(timer_index == TIME10_INDEX){
		__HAL_RCC_TIM10_CLK_ENABLE();		
	}
#endif
#ifdef BSP_USING_TIME11
	if(timer_index == TIME11_INDEX){
		__HAL_RCC_TIM11_CLK_ENABLE();
	}
#endif
#ifdef BSP_USING_TIME12
	if(timer_index == TIME12_INDEX){
		__HAL_RCC_TIM12_CLK_ENABLE();		
	}
#endif
#ifdef BSP_USING_TIME13
	if(timer_index == TIME13_INDEX){
		__HAL_RCC_TIM13_CLK_ENABLE();
	}
#endif
#ifdef BSP_USING_TIME14
	if(timer_index == TIME14_INDEX){
		__HAL_RCC_TIM14_CLK_ENABLE();		
	}
#endif
	LL_TIM_Init(TIMx, InitStruct_p);
}


static void bsp_timerx_OCx_init(enum TIM_INDEX timer_index, enum TIM_CHL chl)
{
	LL_TIM_OC_InitTypeDef *InitStruct_p = 0;
	TIM_TypeDef *TIMx = Timer_Cfg_Tab[timer_index].Instance;	
	
	if (chl == TIM_CH1){
		InitStruct_p = (LL_TIM_OC_InitTypeDef *)&Timer_Cfg_Tab[timer_index].OC1cfg;
	}
	if (chl == TIM_CH2){
		InitStruct_p = (LL_TIM_OC_InitTypeDef *)&Timer_Cfg_Tab[timer_index].OC2cfg;
	}
	if (chl == TIM_CH3){
		InitStruct_p = (LL_TIM_OC_InitTypeDef *)&Timer_Cfg_Tab[timer_index].OC3cfg;
	}
	if (chl == TIM_CH4){
		InitStruct_p = (LL_TIM_OC_InitTypeDef *)&Timer_Cfg_Tab[timer_index].OC4cfg;
	}
	LL_TIM_OC_Init(TIMx,chl,InitStruct_p);
}

static void bsp_timerx_ICx_init(enum TIM_INDEX timer_index, enum TIM_CHL chl)
{
	LL_TIM_IC_InitTypeDef *InitStruct_p = 0;
	TIM_TypeDef *TIMx = Timer_Cfg_Tab[timer_index].Instance;	
	
	if (chl == TIM_CH1){
		InitStruct_p = (LL_TIM_IC_InitTypeDef *)&Timer_Cfg_Tab[timer_index].IC1cfg;
	}
	if (chl == TIM_CH2){
		InitStruct_p = (LL_TIM_IC_InitTypeDef *)&Timer_Cfg_Tab[timer_index].IC2cfg;
	}
	if (chl == TIM_CH3){
		InitStruct_p = (LL_TIM_IC_InitTypeDef *)&Timer_Cfg_Tab[timer_index].IC3cfg;
	}
	if (chl == TIM_CH4){
		InitStruct_p = (LL_TIM_IC_InitTypeDef *)&Timer_Cfg_Tab[timer_index].IC4cfg;
	}
    LL_TIM_IC_Init(TIMx,chl,InitStruct_p);

}

static void bsp_timerx_BDTR_init(enum TIM_INDEX timer_index)
{
	TIM_TypeDef *TIMx = Timer_Cfg_Tab[timer_index].Instance;
	LL_TIM_BDTR_InitTypeDef *InitStruct_p = (LL_TIM_BDTR_InitTypeDef *)&Timer_Cfg_Tab[timer_index].BTTRcfg;
	LL_TIM_BDTR_Init(TIMx, InitStruct_p);
}


static void bsp_timerx_open(enum TIM_INDEX chl)
{
	TIM_TypeDef *TIMx = Timer_Cfg_Tab[chl].Instance;
    LL_TIM_EnableCounter(TIMx);
}
static void bsp_timerx_close(enum TIM_INDEX chl)
{
	TIM_TypeDef *TIMx = Timer_Cfg_Tab[chl].Instance;
	LL_TIM_DisableCounter(TIMx);

}



static void bsp_timerx_irq_open(enum TIM_INDEX index, u16 source)
{
	TIM_TypeDef *TIMx = Timer_Cfg_Tab[index].Instance;
	TIMx->DIER |= source;
}
static void bsp_timerx_irq_close(enum TIM_INDEX index, u16 source)
{
	TIM_TypeDef *TIMx = Timer_Cfg_Tab[index].Instance;
    TIMx->DIER &= (uint16_t)~source;
}

static void bsp_timerx_clear_irq_flag(enum TIM_INDEX index, u16 flag)
{
	TIM_TypeDef *TIMx = Timer_Cfg_Tab[index].Instance;
	TIMx->SR = (uint16_t)~flag;
}


int bsp_timerx_get_irq_flag(enum TIM_INDEX index, u16 flag)
{
	u16 itstatus,itenable;
	TIM_TypeDef *TIMx = Timer_Cfg_Tab[index].Instance;
	itstatus = TIMx->SR & flag;
	itenable = TIMx->DIER & flag;
	if ((itstatus != (uint16_t)RESET) && (itenable != (uint16_t)RESET))
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}




static void bsp_timerx_clear(enum TIM_INDEX index)
{
	TIM_TypeDef *TIMx = Timer_Cfg_Tab[index].Instance;
	TIMx->CNT = 0;
}
static uint16_t bsp_timerx_get_cnt(enum TIM_INDEX index)
{
	TIM_TypeDef *TIMx = Timer_Cfg_Tab[index].Instance;
	return TIMx->CNT;
}

const struct __bsp_timer_drv BSP_TIM_DRV = {
	.init 		= bsp_timex_baseinit,
	.icx_init	= bsp_timerx_ICx_init,
	.ocx_init	= bsp_timerx_OCx_init,
	.bdtr_init	= bsp_timerx_BDTR_init,
	.open 		= bsp_timerx_open,
	.close 		= bsp_timerx_close,
	.enable_it 	= bsp_timerx_irq_open,
	.diable_it 	= bsp_timerx_irq_close,
	.get_it_status = bsp_timerx_get_irq_flag,
	.clear_it_flag = bsp_timerx_clear_irq_flag,
	.clear_cnt  = bsp_timerx_clear,
	.get_cnt    = bsp_timerx_get_cnt,
};



#endif /* #ifdef __USING_BSP_TIM_DRV */































































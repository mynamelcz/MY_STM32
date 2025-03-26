#include "time_delay.h"
#include "bsp_timer.h"
#include "bsp_nvic.h"
#include "stdlib.h"

/**************************************************************
						定时循环函数
***************************************************************/

#ifdef LOOP_FUN_TIMER_INDEX




LIST_HEAD(TIM_IRQHandler_ListHead);
	
void register_timer_handler(Tirq_hd_t *hd_t)
{	
	BSP_TIM_DRV.close(LOOP_FUN_TIMER_INDEX);
	list_add_tail(&hd_t->list, &TIM_IRQHandler_ListHead);	
	BSP_TIM_DRV.open(LOOP_FUN_TIMER_INDEX);	
}	
	
void register_timer_handler_malloc(void(*fun)(void), u32 time)
{
	Tirq_hd_t *hd_t = malloc(sizeof(Tirq_hd_t));
	ASSERT(hd_t);
	hd_t->cnt = 0;
	hd_t->time = time;
	hd_t->hdl_fun = fun;
	hd_t->list.next = &(hd_t->list);
	hd_t->list.prev = &(hd_t->list);
	
	register_timer_handler(hd_t);
}	


void unregister_timer_handler(void(*fun)(void))
{
	Tirq_hd_t *pos = NULL;
	BSP_TIM_DRV.close(LOOP_FUN_TIMER_INDEX);
	list_for_each_entry(Tirq_hd_t, pos, &TIM_IRQHandler_ListHead, list)
	{
		if(pos->hdl_fun == fun){	
			list_del(&pos->list);
			break;
		}
	}
	free(pos);
	pos = NULL;
	BSP_TIM_DRV.open(LOOP_FUN_TIMER_INDEX);
}	


static void loop_timer_fun_list(struct list_head *head)
{
	
	Tirq_hd_t *pos = NULL;
	list_for_each_entry(Tirq_hd_t, pos, head, list)
	{
		if(pos->hdl_fun){
			if(++pos->cnt >= pos->time){
				pos->hdl_fun();
				pos->cnt = 0;
			}
		}else{
			DBUG_Printf("TIM_LOOP_IRQHandler err\n");
		}	
	}	  		
}






void timer_loop_callback(void)
{
    if(BSP_TIM_DRV.get_it_status(LOOP_FUN_TIMER_INDEX,TIM_IT_UPDATE))
    {
        BSP_TIM_DRV.clear_it_flag(LOOP_FUN_TIMER_INDEX,TIM_IT_UPDATE);
    	loop_timer_fun_list(&TIM_IRQHandler_ListHead);

    }
}



void timer_loop_init(void)
{
	BSP_TIM_DRV.init(LOOP_FUN_TIMER_INDEX);    
	BSP_TIM_DRV.enable_it(LOOP_FUN_TIMER_INDEX, TIM_IT_UPDATE);
    BSP_NVIC_DRV.attach_fun(TIM7_IRQn,timer_loop_callback);
    BSP_NVIC_DRV.enable_irq(TIM7_IRQn,1,3);
	BSP_TIM_DRV.open(LOOP_FUN_TIMER_INDEX);
}











#endif









/**************************************************************
						延时函数
***************************************************************/
#if 1


#ifdef EN_DELAY_TIME_INT

volatile static u32 count = 0;
void TIM6_DAC_IRQHandler(void)
{
	if (DELAY_TIMER->SR&TIM_IT_Update)
	{
		DELAY_TIMER->SR = (uint16_t)~TIM_IT_Update;
		count += 65536;
	}
}

#endif
 
static void delay_timer_init(u16 sys_clk_mhz)
{
	BSP_TIM_DRV.init(DELAY_TIMER_INDEX);
	BSP_TIM_DRV.open(DELAY_TIMER_INDEX);
	
#ifdef EN_DELAY_TIME_INT
	BSP_TimerDrv.init_irq(DELAY_TIMER_INDEX, 1,1);
//	BSP_TimerDrv.open_irq(DELAY_TIMER_INDEX, TIM_IT_Update);
#endif
}

static void time_base_delayus(u32 us)
{
	DELAY_TIMER->CNT=0;
 	while(DELAY_TIMER->CNT<=us);	
}
static void time_base_delayms(u32 ms)
{
	u32 i = 0;
	for(i = 0; i< ms; i++){
		DELAY_TIMER->CNT=0;
		while(DELAY_TIMER->CNT<=1000);	
	}
}

static u32 get_time_cnt(void)
{
#ifdef EN_DELAY_TIME_INT
	count += DELAY_TIMER->CNT;
	DELAY_TIMER->CNT = 0;
	return count;
#else
	return DELAY_TIMER->CNT;
#endif	
}

static void clear_time_cnt(void)
{
#ifdef EN_DELAY_TIME_INT
	count = 0;
#endif	
	DELAY_TIMER->CNT=0;
}


const timer_opt_t TimeDelay = {
	.init  = delay_timer_init,
	.delay_ms = time_base_delayms,
	.delay_us = time_base_delayus,
	.clear_timer = clear_time_cnt,
	.get_time_us = get_time_cnt,
	.get_sys_time_ms = NULL,
};


#else

volatile static u32 fac_us = 0;

static void delay_timer_init(u16 sys_clk_mhz)
{
	fac_us = sys_clk_mhz;
	SysTick->CTRL|=SysTick_CTRL_ENABLE_Msk ;       

}

static void time_base_delayus(u32 us)
{
	SysTick->LOAD  = fac_us*us-1;                         /* set reload register */
	SysTick->VAL   = 0UL;                               /* Load the SysTick Counter Value */
	while((SysTick->CTRL&0x10000)==0);
}
static void time_base_delayms(u32 ms)
{
	u32 i = 0;
	SysTick->LOAD  = fac_us*1000-1;                   /* set reload register */
	for(i = 0; i< ms; i++){
		SysTick->VAL   = 0UL;                         /* Load the SysTick Counter Value */
		while((SysTick->CTRL&0x10000)==0);
	}

}

static u32 get_time_cnt(void)
{
	return (0xFFFFFF-SysTick->VAL)/fac_us;
}

static void clear_time_cnt(void)
{
	SysTick->LOAD  = 0xFFFFFF;                        
	SysTick->VAL   = 0UL;  
}


const timer_opt_t TimeDelay = {
	.init  = delay_timer_init,
	.delay_ms = time_base_delayms,
	.delay_us = time_base_delayus,
	.clear_timer = clear_time_cnt,
	.get_time_us = get_time_cnt,
	.get_sys_time_ms = NULL,
};


#endif





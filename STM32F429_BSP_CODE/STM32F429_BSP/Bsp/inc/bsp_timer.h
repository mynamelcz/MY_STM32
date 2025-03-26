#ifndef __BSP_TIMER_H
#define __BSP_TIMER_H

#include "stm32f4xx.h"
#include "includes.h"
#include "bsp_timer_cfg.h"
#include "stm32f4xx_ll_tim.h"


#ifdef __USING_BSP_TIM_DRV

/* stm32 config class */
struct stm32_timer_config
{
    TIM_TypeDef*	            Instance;
    LL_TIM_InitTypeDef          BScfg;
    LL_TIM_OC_InitTypeDef 		OC1cfg;
    LL_TIM_OC_InitTypeDef 		OC2cfg;
    LL_TIM_OC_InitTypeDef 		OC3cfg;
    LL_TIM_OC_InitTypeDef 		OC4cfg;

    LL_TIM_IC_InitTypeDef 		IC1cfg;
    LL_TIM_IC_InitTypeDef 		IC2cfg;
    LL_TIM_IC_InitTypeDef 		IC3cfg;
    LL_TIM_IC_InitTypeDef 		IC4cfg;

    LL_TIM_BDTR_InitTypeDef 	BTTRcfg;
};

enum TIM_INDEX
{
#ifdef BSP_USING_TIME1
    TIME1_INDEX,
#endif
#ifdef BSP_USING_TIME2
    TIME2_INDEX,
#endif
#ifdef BSP_USING_TIME3
    TIME3_INDEX,
#endif
#ifdef BSP_USING_TIME4
    TIME4_INDEX,
#endif
#ifdef BSP_USING_TIME5
    TIME5_INDEX,
#endif
#ifdef BSP_USING_TIME6
    TIME6_INDEX,
#endif
#ifdef BSP_USING_TIME7
    TIME7_INDEX,
#endif
#ifdef BSP_USING_TIME8
    TIME8_INDEX,
#endif
#ifdef BSP_USING_TIME9
    TIME9_INDEX,
#endif
#ifdef BSP_USING_TIME10
    TIME10_INDEX,
#endif
#ifdef BSP_USING_TIME11
    TIME11_INDEX,
#endif
#ifdef BSP_USING_TIME12
    TIME12_INDEX,
#endif
#ifdef BSP_USING_TIME13
    TIME13_INDEX,
#endif
#ifdef BSP_USING_TIME14
    TIME14_INDEX,
#endif
    TIME_INDEX_MAX,
};

enum TIM_CHL
{
    TIM_CH1 = LL_TIM_CHANNEL_CH1,
    TIM_CH2 = LL_TIM_CHANNEL_CH2,
    TIM_CH3 = LL_TIM_CHANNEL_CH3,
    TIM_CH4 = LL_TIM_CHANNEL_CH4,
};

struct __bsp_timer_drv
{
    void (*init)(enum TIM_INDEX index);
    void (*icx_init)(enum TIM_INDEX index, enum TIM_CHL chl);
    void (*ocx_init)(enum TIM_INDEX index, enum TIM_CHL chl);
    void (*bdtr_init)(enum TIM_INDEX index);
    void (*open)(enum TIM_INDEX index);
    void (*close)(enum TIM_INDEX index);
    void (*enable_it)(enum TIM_INDEX index, u16 source);
    void (*diable_it)(enum TIM_INDEX index, u16 source);
    int (*get_it_status)(enum TIM_INDEX index, u16 flags);
    void (*clear_it_flag)(enum TIM_INDEX index, u16 flags);
    void (*clear_cnt)(enum TIM_INDEX index);
    uint16_t (*get_cnt)(enum TIM_INDEX index);
};

extern const struct __bsp_timer_drv BSP_TIM_DRV;

#endif /* __USING_BSP_TIM_DRV */

#endif

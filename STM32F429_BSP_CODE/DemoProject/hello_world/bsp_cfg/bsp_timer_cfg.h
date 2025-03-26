#ifndef __BSP_TIM_CONFIG_H__
#define __BSP_TIM_CONFIG_H__




#include "board.h"

#if defined(BSP_USING_TIME1) || defined(BSP_USING_TIME2) || defined(BSP_USING_TIME3) || defined(BSP_USING_TIME4) || defined(BSP_USING_TIME5) || defined(BSP_USING_TIME6) || defined(BSP_USING_TIME7) || defined(BSP_USING_TIME8) || defined(BSP_USING_TIME9) || defined(BSP_USING_TIME10) || defined(BSP_USING_TIME11) || defined(BSP_USING_TIME12) || defined(BSP_USING_TIME13) || defined(BSP_USING_TIME14)     
	
#define __USING_BSP_TIM_DRV


	
#if defined(BSP_USING_TIME1)

#ifndef TIMER1_CONFIG
#define TIMER1_CONFIG                                               \
    {                                                               \
        .Instance = TIM1,                                           \
		.BScfg = {													\
			.Prescaler = 0,							  		        \
			.CounterMode = LL_TIM_COUNTERMODE_UP,     				\
			.Autoreload = 1000-1,    	     						\
			.ClockDivision =  LL_TIM_CLOCKDIVISION_DIV1,          	\
			.RepetitionCounter = 0,								    \
		},															\
		.OC1cfg = {													\
			.OCMode =  LL_TIM_OCMODE_PWM1,   				        \
            .OCState = LL_TIM_OCSTATE_ENABLE,					    \
			.OCNState =  LL_TIM_OCSTATE_ENABLE,			            \
			.CompareValue = 100,		                            \
            .OCPolarity = LL_TIM_OCPOLARITY_HIGH,                   \
			.OCNPolarity = LL_TIM_OCPOLARITY_HIGH,		            \
			.OCIdleState = LL_TIM_OCIDLESTATE_HIGH,		            \
            .OCNIdleState = LL_TIM_OCIDLESTATE_HIGH,		        \
        },															\
		.OC2cfg = {													\
			.OCMode =  LL_TIM_OCMODE_PWM1,   				        \
            .OCState = LL_TIM_OCSTATE_ENABLE,					    \
			.OCNState =  LL_TIM_OCSTATE_ENABLE,			            \
			.CompareValue = 100,		                            \
            .OCPolarity = LL_TIM_OCPOLARITY_HIGH,                   \
			.OCNPolarity = LL_TIM_OCPOLARITY_HIGH,		            \
			.OCIdleState = LL_TIM_OCIDLESTATE_HIGH,		            \
            .OCNIdleState = LL_TIM_OCIDLESTATE_HIGH,		        \
		},															\
		.OC3cfg = {													\
			.OCMode =  LL_TIM_OCMODE_PWM1,   				        \
            .OCState = LL_TIM_OCSTATE_ENABLE,					    \
			.OCNState =  LL_TIM_OCSTATE_ENABLE,			            \
			.CompareValue = 100,		                            \
            .OCPolarity = LL_TIM_OCPOLARITY_HIGH,                   \
			.OCNPolarity = LL_TIM_OCPOLARITY_HIGH,		            \
			.OCIdleState = LL_TIM_OCIDLESTATE_HIGH,		            \
            .OCNIdleState = LL_TIM_OCIDLESTATE_HIGH,		        \
		},															\
		.OC4cfg = {													\
			.OCMode =  LL_TIM_OCMODE_PWM1,   				        \
            .OCState = LL_TIM_OCSTATE_ENABLE,					    \
			.OCNState =  LL_TIM_OCSTATE_ENABLE,			            \
			.CompareValue = 100,		                            \
            .OCPolarity = LL_TIM_OCPOLARITY_HIGH,                   \
			.OCNPolarity = LL_TIM_OCPOLARITY_HIGH,		            \
			.OCIdleState = LL_TIM_OCIDLESTATE_HIGH,		            \
            .OCNIdleState = LL_TIM_OCIDLESTATE_HIGH,		        \
		},															\
		.IC1cfg = {													\
			.ICPolarity =  LL_TIM_IC_POLARITY_RISING,				\
			.ICActiveInput = LL_TIM_ACTIVEINPUT_DIRECTTI,			\
			.ICPrescaler = LL_TIM_ICPSC_DIV1,						\
			.ICFilter =  0,										    \
		},															\
		.IC2cfg = {													\
			.ICPolarity =  LL_TIM_IC_POLARITY_RISING,				\
			.ICActiveInput = LL_TIM_ACTIVEINPUT_DIRECTTI,			\
			.ICPrescaler = LL_TIM_ICPSC_DIV1,						\
			.ICFilter =  0,										    \
		},															\
		.IC3cfg = {													\
			.ICPolarity =  LL_TIM_IC_POLARITY_RISING,				\
			.ICActiveInput = LL_TIM_ACTIVEINPUT_DIRECTTI,			\
			.ICPrescaler = LL_TIM_ICPSC_DIV1,						\
			.ICFilter =  0,										    \
		},															\
		.IC4cfg = {													\
			.ICPolarity =  LL_TIM_IC_POLARITY_RISING,				\
			.ICActiveInput = LL_TIM_ACTIVEINPUT_DIRECTTI,			\
			.ICPrescaler = LL_TIM_ICPSC_DIV1,						\
			.ICFilter =  0,										    \
		},															\
		.BTTRcfg = {												\
			.OSSRState =  LL_TIM_OSSR_ENABLE,   			        \
			.OSSIState =  LL_TIM_OSSI_ENABLE,				        \
			.LockLevel = LL_TIM_LOCKLEVEL_OFF,						\
			.DeadTime = 10,										    \
			.BreakState =  LL_TIM_BREAK_ENABLE,						\
			.BreakPolarity = LL_TIM_BREAK_POLARITY_HIGH,			\
			.AutomaticOutput = LL_TIM_AUTOMATICOUTPUT_DISABLE,		\
		},															\
    }
#endif /* TIMER1_CONFIG */
#endif /* BSP_USING_TIME1 */

#if defined(BSP_USING_TIME2)
#ifndef TIMER2_CONFIG
#define TIMER2_CONFIG                                               \
    {                                                               \
        .Instance = TIM2,                                           \
		.BScfg = {													\
			.Prescaler = 90-1,						  		        \
			.CounterMode = LL_TIM_COUNTERMODE_UP,     				\
			.Autoreload = 0xFFFFFFFF,  	     						\
			.ClockDivision =  LL_TIM_CLOCKDIVISION_DIV1,          	\
			.RepetitionCounter = 0,								    \
		},															\
		.OC1cfg = {													\
			.OCMode =  LL_TIM_OCMODE_PWM1,   				        \
            .OCState = LL_TIM_OCSTATE_ENABLE,					    \
			.OCNState =  LL_TIM_OCSTATE_ENABLE,			            \
			.CompareValue = 100,		                            \
            .OCPolarity = LL_TIM_OCPOLARITY_HIGH,                   \
			.OCNPolarity = LL_TIM_OCPOLARITY_HIGH,		            \
			.OCIdleState = LL_TIM_OCIDLESTATE_HIGH,		            \
            .OCNIdleState = LL_TIM_OCIDLESTATE_HIGH,		        \
        },															\
		.OC2cfg = {													\
			.OCMode =  LL_TIM_OCMODE_PWM1,   				        \
            .OCState = LL_TIM_OCSTATE_ENABLE,					    \
			.OCNState =  LL_TIM_OCSTATE_ENABLE,			            \
			.CompareValue = 100,		                            \
            .OCPolarity = LL_TIM_OCPOLARITY_HIGH,                   \
			.OCNPolarity = LL_TIM_OCPOLARITY_HIGH,		            \
			.OCIdleState = LL_TIM_OCIDLESTATE_HIGH,		            \
            .OCNIdleState = LL_TIM_OCIDLESTATE_HIGH,		        \
		},															\
		.OC3cfg = {													\
			.OCMode =  LL_TIM_OCMODE_PWM1,   				        \
            .OCState = LL_TIM_OCSTATE_ENABLE,					    \
			.OCNState =  LL_TIM_OCSTATE_ENABLE,			            \
			.CompareValue = 100,		                            \
            .OCPolarity = LL_TIM_OCPOLARITY_HIGH,                   \
			.OCNPolarity = LL_TIM_OCPOLARITY_HIGH,		            \
			.OCIdleState = LL_TIM_OCIDLESTATE_HIGH,		            \
            .OCNIdleState = LL_TIM_OCIDLESTATE_HIGH,		        \
		},															\
		.OC4cfg = {													\
			.OCMode =  LL_TIM_OCMODE_PWM1,   				        \
            .OCState = LL_TIM_OCSTATE_ENABLE,					    \
			.OCNState =  LL_TIM_OCSTATE_ENABLE,			            \
			.CompareValue = 100,		                            \
            .OCPolarity = LL_TIM_OCPOLARITY_HIGH,                   \
			.OCNPolarity = LL_TIM_OCPOLARITY_HIGH,		            \
			.OCIdleState = LL_TIM_OCIDLESTATE_HIGH,		            \
            .OCNIdleState = LL_TIM_OCIDLESTATE_HIGH,		        \
		},															\
		.IC1cfg = {													\
			.ICPolarity =  LL_TIM_IC_POLARITY_RISING,				\
			.ICActiveInput = LL_TIM_ACTIVEINPUT_DIRECTTI,			\
			.ICPrescaler = LL_TIM_ICPSC_DIV1,						\
			.ICFilter =  0,										    \
		},															\
		.IC2cfg = {													\
			.ICPolarity =  LL_TIM_IC_POLARITY_RISING,				\
			.ICActiveInput = LL_TIM_ACTIVEINPUT_DIRECTTI,			\
			.ICPrescaler = LL_TIM_ICPSC_DIV1,						\
			.ICFilter =  0,										    \
		},															\
		.IC3cfg = {													\
			.ICPolarity =  LL_TIM_IC_POLARITY_RISING,				\
			.ICActiveInput = LL_TIM_ACTIVEINPUT_DIRECTTI,			\
			.ICPrescaler = LL_TIM_ICPSC_DIV1,						\
			.ICFilter =  0,										    \
		},															\
		.IC4cfg = {													\
			.ICPolarity =  LL_TIM_IC_POLARITY_RISING,				\
			.ICActiveInput = LL_TIM_ACTIVEINPUT_DIRECTTI,			\
			.ICPrescaler = LL_TIM_ICPSC_DIV1,						\
			.ICFilter =  0,										    \
		},															\
		.BTTRcfg = {												\
			.OSSRState =  LL_TIM_OSSR_ENABLE,   			        \
			.OSSIState =  LL_TIM_OSSI_ENABLE,				        \
			.LockLevel = LL_TIM_LOCKLEVEL_OFF,						\
			.DeadTime = 10,										    \
			.BreakState =  LL_TIM_BREAK_ENABLE,						\
			.BreakPolarity = LL_TIM_BREAK_POLARITY_HIGH,			\
			.AutomaticOutput = LL_TIM_AUTOMATICOUTPUT_DISABLE,		\
		},															\
    }   
#endif /* TIMER2_CONFIG */
#endif /* BSP_USING_TIME2 */

#if defined(BSP_USING_TIME3)
#ifndef TIMER3_CONFIG
#define TIMER3_CONFIG                                               \
    {                                                               \
        .Instance = TIM3,                                           \
		.BScfg = {													\
			.Prescaler = 0,							  		        \
			.CounterMode = LL_TIM_COUNTERMODE_UP,     				\
			.Autoreload = 1000-1,    	     						\
			.ClockDivision =  LL_TIM_CLOCKDIVISION_DIV1,          	\
			.RepetitionCounter = 0,								    \
		},															\
		.OC1cfg = {													\
			.OCMode =  LL_TIM_OCMODE_PWM1,   				        \
            .OCState = LL_TIM_OCSTATE_ENABLE,					    \
			.OCNState =  LL_TIM_OCSTATE_ENABLE,			            \
			.CompareValue = 100,		                            \
            .OCPolarity = LL_TIM_OCPOLARITY_HIGH,                   \
			.OCNPolarity = LL_TIM_OCPOLARITY_HIGH,		            \
			.OCIdleState = LL_TIM_OCIDLESTATE_HIGH,		            \
            .OCNIdleState = LL_TIM_OCIDLESTATE_HIGH,		        \
        },															\
		.OC2cfg = {													\
			.OCMode =  LL_TIM_OCMODE_PWM1,   				        \
            .OCState = LL_TIM_OCSTATE_ENABLE,					    \
			.OCNState =  LL_TIM_OCSTATE_ENABLE,			            \
			.CompareValue = 100,		                            \
            .OCPolarity = LL_TIM_OCPOLARITY_HIGH,                   \
			.OCNPolarity = LL_TIM_OCPOLARITY_HIGH,		            \
			.OCIdleState = LL_TIM_OCIDLESTATE_HIGH,		            \
            .OCNIdleState = LL_TIM_OCIDLESTATE_HIGH,		        \
		},															\
		.OC3cfg = {													\
			.OCMode =  LL_TIM_OCMODE_PWM1,   				        \
            .OCState = LL_TIM_OCSTATE_ENABLE,					    \
			.OCNState =  LL_TIM_OCSTATE_ENABLE,			            \
			.CompareValue = 100,		                            \
            .OCPolarity = LL_TIM_OCPOLARITY_HIGH,                   \
			.OCNPolarity = LL_TIM_OCPOLARITY_HIGH,		            \
			.OCIdleState = LL_TIM_OCIDLESTATE_HIGH,		            \
            .OCNIdleState = LL_TIM_OCIDLESTATE_HIGH,		        \
		},															\
		.OC4cfg = {													\
			.OCMode =  LL_TIM_OCMODE_PWM1,   				        \
            .OCState = LL_TIM_OCSTATE_ENABLE,					    \
			.OCNState =  LL_TIM_OCSTATE_ENABLE,			            \
			.CompareValue = 100,		                            \
            .OCPolarity = LL_TIM_OCPOLARITY_HIGH,                   \
			.OCNPolarity = LL_TIM_OCPOLARITY_HIGH,		            \
			.OCIdleState = LL_TIM_OCIDLESTATE_HIGH,		            \
            .OCNIdleState = LL_TIM_OCIDLESTATE_HIGH,		        \
		},															\
		.IC1cfg = {													\
			.ICPolarity =  LL_TIM_IC_POLARITY_RISING,				\
			.ICActiveInput = LL_TIM_ACTIVEINPUT_DIRECTTI,			\
			.ICPrescaler = LL_TIM_ICPSC_DIV1,						\
			.ICFilter =  0,										    \
		},															\
		.IC2cfg = {													\
			.ICPolarity =  LL_TIM_IC_POLARITY_RISING,				\
			.ICActiveInput = LL_TIM_ACTIVEINPUT_DIRECTTI,			\
			.ICPrescaler = LL_TIM_ICPSC_DIV1,						\
			.ICFilter =  0,										    \
		},															\
		.IC3cfg = {													\
			.ICPolarity =  LL_TIM_IC_POLARITY_RISING,				\
			.ICActiveInput = LL_TIM_ACTIVEINPUT_DIRECTTI,			\
			.ICPrescaler = LL_TIM_ICPSC_DIV1,						\
			.ICFilter =  0,										    \
		},															\
		.IC4cfg = {													\
			.ICPolarity =  LL_TIM_IC_POLARITY_RISING,				\
			.ICActiveInput = LL_TIM_ACTIVEINPUT_DIRECTTI,			\
			.ICPrescaler = LL_TIM_ICPSC_DIV1,						\
			.ICFilter =  0,										    \
		},															\
		.BTTRcfg = {												\
			.OSSRState =  LL_TIM_OSSR_ENABLE,   			        \
			.OSSIState =  LL_TIM_OSSI_ENABLE,				        \
			.LockLevel = LL_TIM_LOCKLEVEL_OFF,						\
			.DeadTime = 10,										    \
			.BreakState =  LL_TIM_BREAK_ENABLE,						\
			.BreakPolarity = LL_TIM_BREAK_POLARITY_HIGH,			\
			.AutomaticOutput = LL_TIM_AUTOMATICOUTPUT_DISABLE,		\
		},															\
    }    
#endif /* TIMER3_CONFIG */
#endif /* BSP_USING_TIME3 */

#if defined(BSP_USING_TIME4)
#ifndef TIMER4_CONFIG
#define TIMER4_CONFIG                                               \
    {                                                               \
        .Instance = TIM4,                                           \
		.BScfg = {													\
			.Prescaler = 0,							  		        \
			.CounterMode = LL_TIM_COUNTERMODE_UP,     				\
			.Autoreload = 1000-1,    	     						\
			.ClockDivision =  LL_TIM_CLOCKDIVISION_DIV1,          	\
			.RepetitionCounter = 0,								    \
		},															\
		.OC1cfg = {													\
			.OCMode =  LL_TIM_OCMODE_PWM1,   				        \
            .OCState = LL_TIM_OCSTATE_ENABLE,					    \
			.OCNState =  LL_TIM_OCSTATE_ENABLE,			            \
			.CompareValue = 100,		                            \
            .OCPolarity = LL_TIM_OCPOLARITY_HIGH,                   \
			.OCNPolarity = LL_TIM_OCPOLARITY_HIGH,		            \
			.OCIdleState = LL_TIM_OCIDLESTATE_HIGH,		            \
            .OCNIdleState = LL_TIM_OCIDLESTATE_HIGH,		        \
        },															\
		.OC2cfg = {													\
			.OCMode =  LL_TIM_OCMODE_PWM1,   				        \
            .OCState = LL_TIM_OCSTATE_ENABLE,					    \
			.OCNState =  LL_TIM_OCSTATE_ENABLE,			            \
			.CompareValue = 100,		                            \
            .OCPolarity = LL_TIM_OCPOLARITY_HIGH,                   \
			.OCNPolarity = LL_TIM_OCPOLARITY_HIGH,		            \
			.OCIdleState = LL_TIM_OCIDLESTATE_HIGH,		            \
            .OCNIdleState = LL_TIM_OCIDLESTATE_HIGH,		        \
		},															\
		.OC3cfg = {													\
			.OCMode =  LL_TIM_OCMODE_PWM1,   				        \
            .OCState = LL_TIM_OCSTATE_ENABLE,					    \
			.OCNState =  LL_TIM_OCSTATE_ENABLE,			            \
			.CompareValue = 100,		                            \
            .OCPolarity = LL_TIM_OCPOLARITY_HIGH,                   \
			.OCNPolarity = LL_TIM_OCPOLARITY_HIGH,		            \
			.OCIdleState = LL_TIM_OCIDLESTATE_HIGH,		            \
            .OCNIdleState = LL_TIM_OCIDLESTATE_HIGH,		        \
		},															\
		.OC4cfg = {													\
			.OCMode =  LL_TIM_OCMODE_PWM1,   				        \
            .OCState = LL_TIM_OCSTATE_ENABLE,					    \
			.OCNState =  LL_TIM_OCSTATE_ENABLE,			            \
			.CompareValue = 100,		                            \
            .OCPolarity = LL_TIM_OCPOLARITY_HIGH,                   \
			.OCNPolarity = LL_TIM_OCPOLARITY_HIGH,		            \
			.OCIdleState = LL_TIM_OCIDLESTATE_HIGH,		            \
            .OCNIdleState = LL_TIM_OCIDLESTATE_HIGH,		        \
		},															\
		.IC1cfg = {													\
			.ICPolarity =  LL_TIM_IC_POLARITY_RISING,				\
			.ICActiveInput = LL_TIM_ACTIVEINPUT_DIRECTTI,			\
			.ICPrescaler = LL_TIM_ICPSC_DIV1,						\
			.ICFilter =  0,										    \
		},															\
		.IC2cfg = {													\
			.ICPolarity =  LL_TIM_IC_POLARITY_RISING,				\
			.ICActiveInput = LL_TIM_ACTIVEINPUT_DIRECTTI,			\
			.ICPrescaler = LL_TIM_ICPSC_DIV1,						\
			.ICFilter =  0,										    \
		},															\
		.IC3cfg = {													\
			.ICPolarity =  LL_TIM_IC_POLARITY_RISING,				\
			.ICActiveInput = LL_TIM_ACTIVEINPUT_DIRECTTI,			\
			.ICPrescaler = LL_TIM_ICPSC_DIV1,						\
			.ICFilter =  0,										    \
		},															\
		.IC4cfg = {													\
			.ICPolarity =  LL_TIM_IC_POLARITY_RISING,				\
			.ICActiveInput = LL_TIM_ACTIVEINPUT_DIRECTTI,			\
			.ICPrescaler = LL_TIM_ICPSC_DIV1,						\
			.ICFilter =  0,										    \
		},															\
		.BTTRcfg = {												\
			.OSSRState =  LL_TIM_OSSR_ENABLE,   			        \
			.OSSIState =  LL_TIM_OSSI_ENABLE,				        \
			.LockLevel = LL_TIM_LOCKLEVEL_OFF,						\
			.DeadTime = 10,										    \
			.BreakState =  LL_TIM_BREAK_ENABLE,						\
			.BreakPolarity = LL_TIM_BREAK_POLARITY_HIGH,			\
			.AutomaticOutput = LL_TIM_AUTOMATICOUTPUT_DISABLE,		\
		},															\
    }       
#endif /* TIMER4_CONFIG */
#endif /* BSP_USING_TIME4 */

#if defined(BSP_USING_TIME5)
#ifndef TIMER5_CONFIG
#define TIMER5_CONFIG                                               \
    {                                                               \
        .Instance = TIM5,                                           \
		.BScfg = {													\
			.Prescaler = 0,							  		        \
			.CounterMode = LL_TIM_COUNTERMODE_UP,     				\
			.Autoreload = 1000-1,    	     						\
			.ClockDivision =  LL_TIM_CLOCKDIVISION_DIV1,          	\
			.RepetitionCounter = 0,								    \
		},															\
		.OC1cfg = {													\
			.OCMode =  LL_TIM_OCMODE_PWM1,   				        \
            .OCState = LL_TIM_OCSTATE_ENABLE,					    \
			.OCNState =  LL_TIM_OCSTATE_ENABLE,			            \
			.CompareValue = 100,		                            \
            .OCPolarity = LL_TIM_OCPOLARITY_HIGH,                   \
			.OCNPolarity = LL_TIM_OCPOLARITY_HIGH,		            \
			.OCIdleState = LL_TIM_OCIDLESTATE_HIGH,		            \
            .OCNIdleState = LL_TIM_OCIDLESTATE_HIGH,		        \
        },															\
		.OC2cfg = {													\
			.OCMode =  LL_TIM_OCMODE_PWM1,   				        \
            .OCState = LL_TIM_OCSTATE_ENABLE,					    \
			.OCNState =  LL_TIM_OCSTATE_ENABLE,			            \
			.CompareValue = 100,		                            \
            .OCPolarity = LL_TIM_OCPOLARITY_HIGH,                   \
			.OCNPolarity = LL_TIM_OCPOLARITY_HIGH,		            \
			.OCIdleState = LL_TIM_OCIDLESTATE_HIGH,		            \
            .OCNIdleState = LL_TIM_OCIDLESTATE_HIGH,		        \
		},															\
		.OC3cfg = {													\
			.OCMode =  LL_TIM_OCMODE_PWM1,   				        \
            .OCState = LL_TIM_OCSTATE_ENABLE,					    \
			.OCNState =  LL_TIM_OCSTATE_ENABLE,			            \
			.CompareValue = 100,		                            \
            .OCPolarity = LL_TIM_OCPOLARITY_HIGH,                   \
			.OCNPolarity = LL_TIM_OCPOLARITY_HIGH,		            \
			.OCIdleState = LL_TIM_OCIDLESTATE_HIGH,		            \
            .OCNIdleState = LL_TIM_OCIDLESTATE_HIGH,		        \
		},															\
		.OC4cfg = {													\
			.OCMode =  LL_TIM_OCMODE_PWM1,   				        \
            .OCState = LL_TIM_OCSTATE_ENABLE,					    \
			.OCNState =  LL_TIM_OCSTATE_ENABLE,			            \
			.CompareValue = 100,		                            \
            .OCPolarity = LL_TIM_OCPOLARITY_HIGH,                   \
			.OCNPolarity = LL_TIM_OCPOLARITY_HIGH,		            \
			.OCIdleState = LL_TIM_OCIDLESTATE_HIGH,		            \
            .OCNIdleState = LL_TIM_OCIDLESTATE_HIGH,		        \
		},															\
		.IC1cfg = {													\
			.ICPolarity =  LL_TIM_IC_POLARITY_RISING,				\
			.ICActiveInput = LL_TIM_ACTIVEINPUT_DIRECTTI,			\
			.ICPrescaler = LL_TIM_ICPSC_DIV1,						\
			.ICFilter =  0,										    \
		},															\
		.IC2cfg = {													\
			.ICPolarity =  LL_TIM_IC_POLARITY_RISING,				\
			.ICActiveInput = LL_TIM_ACTIVEINPUT_DIRECTTI,			\
			.ICPrescaler = LL_TIM_ICPSC_DIV1,						\
			.ICFilter =  0,										    \
		},															\
		.IC3cfg = {													\
			.ICPolarity =  LL_TIM_IC_POLARITY_RISING,				\
			.ICActiveInput = LL_TIM_ACTIVEINPUT_DIRECTTI,			\
			.ICPrescaler = LL_TIM_ICPSC_DIV1,						\
			.ICFilter =  0,										    \
		},															\
		.IC4cfg = {													\
			.ICPolarity =  LL_TIM_IC_POLARITY_RISING,				\
			.ICActiveInput = LL_TIM_ACTIVEINPUT_DIRECTTI,			\
			.ICPrescaler = LL_TIM_ICPSC_DIV1,						\
			.ICFilter =  0,										    \
		},															\
		.BTTRcfg = {												\
			.OSSRState =  LL_TIM_OSSR_ENABLE,   			        \
			.OSSIState =  LL_TIM_OSSI_ENABLE,				        \
			.LockLevel = LL_TIM_LOCKLEVEL_OFF,						\
			.DeadTime = 10,										    \
			.BreakState =  LL_TIM_BREAK_ENABLE,						\
			.BreakPolarity = LL_TIM_BREAK_POLARITY_HIGH,			\
			.AutomaticOutput = LL_TIM_AUTOMATICOUTPUT_DISABLE,		\
		},															\
    }   
#endif /* TIMER5_CONFIG */
#endif /* BSP_USING_TIME5 */


#if defined(BSP_USING_TIME6)
#ifndef TIMER6_CONFIG
#define TIMER6_CONFIG                                               \
    {                                                               \
        .Instance = TIM6,                                           \
		.BScfg = {													\
			.Prescaler = 0,							  		        \
			.CounterMode = LL_TIM_COUNTERMODE_UP,     				\
			.Autoreload = 1000-1,    	     						\
			.ClockDivision =  LL_TIM_CLOCKDIVISION_DIV1,          	\
			.RepetitionCounter = 0,								    \
		},															\
		.OC1cfg = {													\
			.OCMode =  LL_TIM_OCMODE_PWM1,   				        \
            .OCState = LL_TIM_OCSTATE_ENABLE,					    \
			.OCNState =  LL_TIM_OCSTATE_ENABLE,			            \
			.CompareValue = 100,		                            \
            .OCPolarity = LL_TIM_OCPOLARITY_HIGH,                   \
			.OCNPolarity = LL_TIM_OCPOLARITY_HIGH,		            \
			.OCIdleState = LL_TIM_OCIDLESTATE_HIGH,		            \
            .OCNIdleState = LL_TIM_OCIDLESTATE_HIGH,		        \
        },															\
		.OC2cfg = {													\
			.OCMode =  LL_TIM_OCMODE_PWM1,   				        \
            .OCState = LL_TIM_OCSTATE_ENABLE,					    \
			.OCNState =  LL_TIM_OCSTATE_ENABLE,			            \
			.CompareValue = 100,		                            \
            .OCPolarity = LL_TIM_OCPOLARITY_HIGH,                   \
			.OCNPolarity = LL_TIM_OCPOLARITY_HIGH,		            \
			.OCIdleState = LL_TIM_OCIDLESTATE_HIGH,		            \
            .OCNIdleState = LL_TIM_OCIDLESTATE_HIGH,		        \
		},															\
		.OC3cfg = {													\
			.OCMode =  LL_TIM_OCMODE_PWM1,   				        \
            .OCState = LL_TIM_OCSTATE_ENABLE,					    \
			.OCNState =  LL_TIM_OCSTATE_ENABLE,			            \
			.CompareValue = 100,		                            \
            .OCPolarity = LL_TIM_OCPOLARITY_HIGH,                   \
			.OCNPolarity = LL_TIM_OCPOLARITY_HIGH,		            \
			.OCIdleState = LL_TIM_OCIDLESTATE_HIGH,		            \
            .OCNIdleState = LL_TIM_OCIDLESTATE_HIGH,		        \
		},															\
		.OC4cfg = {													\
			.OCMode =  LL_TIM_OCMODE_PWM1,   				        \
            .OCState = LL_TIM_OCSTATE_ENABLE,					    \
			.OCNState =  LL_TIM_OCSTATE_ENABLE,			            \
			.CompareValue = 100,		                            \
            .OCPolarity = LL_TIM_OCPOLARITY_HIGH,                   \
			.OCNPolarity = LL_TIM_OCPOLARITY_HIGH,		            \
			.OCIdleState = LL_TIM_OCIDLESTATE_HIGH,		            \
            .OCNIdleState = LL_TIM_OCIDLESTATE_HIGH,		        \
		},															\
		.IC1cfg = {													\
			.ICPolarity =  LL_TIM_IC_POLARITY_RISING,				\
			.ICActiveInput = LL_TIM_ACTIVEINPUT_DIRECTTI,			\
			.ICPrescaler = LL_TIM_ICPSC_DIV1,						\
			.ICFilter =  0,										    \
		},															\
		.IC2cfg = {													\
			.ICPolarity =  LL_TIM_IC_POLARITY_RISING,				\
			.ICActiveInput = LL_TIM_ACTIVEINPUT_DIRECTTI,			\
			.ICPrescaler = LL_TIM_ICPSC_DIV1,						\
			.ICFilter =  0,										    \
		},															\
		.IC3cfg = {													\
			.ICPolarity =  LL_TIM_IC_POLARITY_RISING,				\
			.ICActiveInput = LL_TIM_ACTIVEINPUT_DIRECTTI,			\
			.ICPrescaler = LL_TIM_ICPSC_DIV1,						\
			.ICFilter =  0,										    \
		},															\
		.IC4cfg = {													\
			.ICPolarity =  LL_TIM_IC_POLARITY_RISING,				\
			.ICActiveInput = LL_TIM_ACTIVEINPUT_DIRECTTI,			\
			.ICPrescaler = LL_TIM_ICPSC_DIV1,						\
			.ICFilter =  0,										    \
		},															\
		.BTTRcfg = {												\
			.OSSRState =  LL_TIM_OSSR_ENABLE,   			        \
			.OSSIState =  LL_TIM_OSSI_ENABLE,				        \
			.LockLevel = LL_TIM_LOCKLEVEL_OFF,						\
			.DeadTime = 10,										    \
			.BreakState =  LL_TIM_BREAK_ENABLE,						\
			.BreakPolarity = LL_TIM_BREAK_POLARITY_HIGH,			\
			.AutomaticOutput = LL_TIM_AUTOMATICOUTPUT_DISABLE,		\
		},															\
    }      
#endif /* TIMER6_CONFIG */
#endif /* BSP_USING_TIME6 */


#if defined(BSP_USING_TIME7)
#ifndef TIMER7_CONFIG
#define TIMER7_CONFIG                                               \
    {                                                               \
        .Instance = TIM7,                                           \
		.BScfg = {													\
			.Prescaler = 0,							  		        \
			.CounterMode = LL_TIM_COUNTERMODE_UP,     				\
			.Autoreload = 1000-1,    	     						\
			.ClockDivision =  LL_TIM_CLOCKDIVISION_DIV1,          	\
			.RepetitionCounter = 0,								    \
		},															\
		.OC1cfg = {													\
			.OCMode =  LL_TIM_OCMODE_PWM1,   				        \
            .OCState = LL_TIM_OCSTATE_ENABLE,					    \
			.OCNState =  LL_TIM_OCSTATE_ENABLE,			            \
			.CompareValue = 100,		                            \
            .OCPolarity = LL_TIM_OCPOLARITY_HIGH,                   \
			.OCNPolarity = LL_TIM_OCPOLARITY_HIGH,		            \
			.OCIdleState = LL_TIM_OCIDLESTATE_HIGH,		            \
            .OCNIdleState = LL_TIM_OCIDLESTATE_HIGH,		        \
        },															\
		.OC2cfg = {													\
			.OCMode =  LL_TIM_OCMODE_PWM1,   				        \
            .OCState = LL_TIM_OCSTATE_ENABLE,					    \
			.OCNState =  LL_TIM_OCSTATE_ENABLE,			            \
			.CompareValue = 100,		                            \
            .OCPolarity = LL_TIM_OCPOLARITY_HIGH,                   \
			.OCNPolarity = LL_TIM_OCPOLARITY_HIGH,		            \
			.OCIdleState = LL_TIM_OCIDLESTATE_HIGH,		            \
            .OCNIdleState = LL_TIM_OCIDLESTATE_HIGH,		        \
		},															\
		.OC3cfg = {													\
			.OCMode =  LL_TIM_OCMODE_PWM1,   				        \
            .OCState = LL_TIM_OCSTATE_ENABLE,					    \
			.OCNState =  LL_TIM_OCSTATE_ENABLE,			            \
			.CompareValue = 100,		                            \
            .OCPolarity = LL_TIM_OCPOLARITY_HIGH,                   \
			.OCNPolarity = LL_TIM_OCPOLARITY_HIGH,		            \
			.OCIdleState = LL_TIM_OCIDLESTATE_HIGH,		            \
            .OCNIdleState = LL_TIM_OCIDLESTATE_HIGH,		        \
		},															\
		.OC4cfg = {													\
			.OCMode =  LL_TIM_OCMODE_PWM1,   				        \
            .OCState = LL_TIM_OCSTATE_ENABLE,					    \
			.OCNState =  LL_TIM_OCSTATE_ENABLE,			            \
			.CompareValue = 100,		                            \
            .OCPolarity = LL_TIM_OCPOLARITY_HIGH,                   \
			.OCNPolarity = LL_TIM_OCPOLARITY_HIGH,		            \
			.OCIdleState = LL_TIM_OCIDLESTATE_HIGH,		            \
            .OCNIdleState = LL_TIM_OCIDLESTATE_HIGH,		        \
		},															\
		.IC1cfg = {													\
			.ICPolarity =  LL_TIM_IC_POLARITY_RISING,				\
			.ICActiveInput = LL_TIM_ACTIVEINPUT_DIRECTTI,			\
			.ICPrescaler = LL_TIM_ICPSC_DIV1,						\
			.ICFilter =  0,										    \
		},															\
		.IC2cfg = {													\
			.ICPolarity =  LL_TIM_IC_POLARITY_RISING,				\
			.ICActiveInput = LL_TIM_ACTIVEINPUT_DIRECTTI,			\
			.ICPrescaler = LL_TIM_ICPSC_DIV1,						\
			.ICFilter =  0,										    \
		},															\
		.IC3cfg = {													\
			.ICPolarity =  LL_TIM_IC_POLARITY_RISING,				\
			.ICActiveInput = LL_TIM_ACTIVEINPUT_DIRECTTI,			\
			.ICPrescaler = LL_TIM_ICPSC_DIV1,						\
			.ICFilter =  0,										    \
		},															\
		.IC4cfg = {													\
			.ICPolarity =  LL_TIM_IC_POLARITY_RISING,				\
			.ICActiveInput = LL_TIM_ACTIVEINPUT_DIRECTTI,			\
			.ICPrescaler = LL_TIM_ICPSC_DIV1,						\
			.ICFilter =  0,										    \
		},															\
		.BTTRcfg = {												\
			.OSSRState =  LL_TIM_OSSR_ENABLE,   			        \
			.OSSIState =  LL_TIM_OSSI_ENABLE,				        \
			.LockLevel = LL_TIM_LOCKLEVEL_OFF,						\
			.DeadTime = 10,										    \
			.BreakState =  LL_TIM_BREAK_ENABLE,						\
			.BreakPolarity = LL_TIM_BREAK_POLARITY_HIGH,			\
			.AutomaticOutput = LL_TIM_AUTOMATICOUTPUT_DISABLE,		\
		},															\
    }     
#endif /* TIMER7_CONFIG */
#endif /* BSP_USING_TIME7 */

#if defined(BSP_USING_TIME8)
#ifndef TIMER8_CONFIG
#define TIMER8_CONFIG                                               \
    {                                                               \
        .Instance = TIM8,                                           \
		.BScfg = {													\
			.Prescaler = 0,							  		        \
			.CounterMode = LL_TIM_COUNTERMODE_UP,     				\
			.Autoreload = 1000-1,    	     						\
			.ClockDivision =  LL_TIM_CLOCKDIVISION_DIV1,          	\
			.RepetitionCounter = 0,								    \
		},															\
		.OC1cfg = {													\
			.OCMode =  LL_TIM_OCMODE_PWM1,   				        \
            .OCState = LL_TIM_OCSTATE_ENABLE,					    \
			.OCNState =  LL_TIM_OCSTATE_ENABLE,			            \
			.CompareValue = 100,		                            \
            .OCPolarity = LL_TIM_OCPOLARITY_HIGH,                   \
			.OCNPolarity = LL_TIM_OCPOLARITY_HIGH,		            \
			.OCIdleState = LL_TIM_OCIDLESTATE_HIGH,		            \
            .OCNIdleState = LL_TIM_OCIDLESTATE_HIGH,		        \
        },															\
		.OC2cfg = {													\
			.OCMode =  LL_TIM_OCMODE_PWM1,   				        \
            .OCState = LL_TIM_OCSTATE_ENABLE,					    \
			.OCNState =  LL_TIM_OCSTATE_ENABLE,			            \
			.CompareValue = 100,		                            \
            .OCPolarity = LL_TIM_OCPOLARITY_HIGH,                   \
			.OCNPolarity = LL_TIM_OCPOLARITY_HIGH,		            \
			.OCIdleState = LL_TIM_OCIDLESTATE_HIGH,		            \
            .OCNIdleState = LL_TIM_OCIDLESTATE_HIGH,		        \
		},															\
		.OC3cfg = {													\
			.OCMode =  LL_TIM_OCMODE_PWM1,   				        \
            .OCState = LL_TIM_OCSTATE_ENABLE,					    \
			.OCNState =  LL_TIM_OCSTATE_ENABLE,			            \
			.CompareValue = 100,		                            \
            .OCPolarity = LL_TIM_OCPOLARITY_HIGH,                   \
			.OCNPolarity = LL_TIM_OCPOLARITY_HIGH,		            \
			.OCIdleState = LL_TIM_OCIDLESTATE_HIGH,		            \
            .OCNIdleState = LL_TIM_OCIDLESTATE_HIGH,		        \
		},															\
		.OC4cfg = {													\
			.OCMode =  LL_TIM_OCMODE_PWM1,   				        \
            .OCState = LL_TIM_OCSTATE_ENABLE,					    \
			.OCNState =  LL_TIM_OCSTATE_ENABLE,			            \
			.CompareValue = 100,		                            \
            .OCPolarity = LL_TIM_OCPOLARITY_HIGH,                   \
			.OCNPolarity = LL_TIM_OCPOLARITY_HIGH,		            \
			.OCIdleState = LL_TIM_OCIDLESTATE_HIGH,		            \
            .OCNIdleState = LL_TIM_OCIDLESTATE_HIGH,		        \
		},															\
		.IC1cfg = {													\
			.ICPolarity =  LL_TIM_IC_POLARITY_RISING,				\
			.ICActiveInput = LL_TIM_ACTIVEINPUT_DIRECTTI,			\
			.ICPrescaler = LL_TIM_ICPSC_DIV1,						\
			.ICFilter =  0,										    \
		},															\
		.IC2cfg = {													\
			.ICPolarity =  LL_TIM_IC_POLARITY_RISING,				\
			.ICActiveInput = LL_TIM_ACTIVEINPUT_DIRECTTI,			\
			.ICPrescaler = LL_TIM_ICPSC_DIV1,						\
			.ICFilter =  0,										    \
		},															\
		.IC3cfg = {													\
			.ICPolarity =  LL_TIM_IC_POLARITY_RISING,				\
			.ICActiveInput = LL_TIM_ACTIVEINPUT_DIRECTTI,			\
			.ICPrescaler = LL_TIM_ICPSC_DIV1,						\
			.ICFilter =  0,										    \
		},															\
		.IC4cfg = {													\
			.ICPolarity =  LL_TIM_IC_POLARITY_RISING,				\
			.ICActiveInput = LL_TIM_ACTIVEINPUT_DIRECTTI,			\
			.ICPrescaler = LL_TIM_ICPSC_DIV1,						\
			.ICFilter =  0,										    \
		},															\
		.BTTRcfg = {												\
			.OSSRState =  LL_TIM_OSSR_ENABLE,   			        \
			.OSSIState =  LL_TIM_OSSI_ENABLE,				        \
			.LockLevel = LL_TIM_LOCKLEVEL_OFF,						\
			.DeadTime = 10,										    \
			.BreakState =  LL_TIM_BREAK_ENABLE,						\
			.BreakPolarity = LL_TIM_BREAK_POLARITY_HIGH,			\
			.AutomaticOutput = LL_TIM_AUTOMATICOUTPUT_DISABLE,		\
		},															\
    }      
#endif /* TIMER8_CONFIG */
#endif /* BSP_USING_TIME8 */

#if defined(BSP_USING_TIME9)
#ifndef TIMER9_CONFIG
#define TIMER9_CONFIG                                               \
    {                                                               \
        .Instance = TIM9,                                           \
		.BScfg = {													\
			.Prescaler = 0,							  		        \
			.CounterMode = LL_TIM_COUNTERMODE_UP,     				\
			.Autoreload = 1000-1,    	     						\
			.ClockDivision =  LL_TIM_CLOCKDIVISION_DIV1,          	\
			.RepetitionCounter = 0,								    \
		},															\
		.OC1cfg = {													\
			.OCMode =  LL_TIM_OCMODE_PWM1,   				        \
            .OCState = LL_TIM_OCSTATE_ENABLE,					    \
			.OCNState =  LL_TIM_OCSTATE_ENABLE,			            \
			.CompareValue = 100,		                            \
            .OCPolarity = LL_TIM_OCPOLARITY_HIGH,                   \
			.OCNPolarity = LL_TIM_OCPOLARITY_HIGH,		            \
			.OCIdleState = LL_TIM_OCIDLESTATE_HIGH,		            \
            .OCNIdleState = LL_TIM_OCIDLESTATE_HIGH,		        \
        },															\
		.OC2cfg = {													\
			.OCMode =  LL_TIM_OCMODE_PWM1,   				        \
            .OCState = LL_TIM_OCSTATE_ENABLE,					    \
			.OCNState =  LL_TIM_OCSTATE_ENABLE,			            \
			.CompareValue = 100,		                            \
            .OCPolarity = LL_TIM_OCPOLARITY_HIGH,                   \
			.OCNPolarity = LL_TIM_OCPOLARITY_HIGH,		            \
			.OCIdleState = LL_TIM_OCIDLESTATE_HIGH,		            \
            .OCNIdleState = LL_TIM_OCIDLESTATE_HIGH,		        \
		},															\
		.OC3cfg = {													\
			.OCMode =  LL_TIM_OCMODE_PWM1,   				        \
            .OCState = LL_TIM_OCSTATE_ENABLE,					    \
			.OCNState =  LL_TIM_OCSTATE_ENABLE,			            \
			.CompareValue = 100,		                            \
            .OCPolarity = LL_TIM_OCPOLARITY_HIGH,                   \
			.OCNPolarity = LL_TIM_OCPOLARITY_HIGH,		            \
			.OCIdleState = LL_TIM_OCIDLESTATE_HIGH,		            \
            .OCNIdleState = LL_TIM_OCIDLESTATE_HIGH,		        \
		},															\
		.OC4cfg = {													\
			.OCMode =  LL_TIM_OCMODE_PWM1,   				        \
            .OCState = LL_TIM_OCSTATE_ENABLE,					    \
			.OCNState =  LL_TIM_OCSTATE_ENABLE,			            \
			.CompareValue = 100,		                            \
            .OCPolarity = LL_TIM_OCPOLARITY_HIGH,                   \
			.OCNPolarity = LL_TIM_OCPOLARITY_HIGH,		            \
			.OCIdleState = LL_TIM_OCIDLESTATE_HIGH,		            \
            .OCNIdleState = LL_TIM_OCIDLESTATE_HIGH,		        \
		},															\
		.IC1cfg = {													\
			.ICPolarity =  LL_TIM_IC_POLARITY_RISING,				\
			.ICActiveInput = LL_TIM_ACTIVEINPUT_DIRECTTI,			\
			.ICPrescaler = LL_TIM_ICPSC_DIV1,						\
			.ICFilter =  0,										    \
		},															\
		.IC2cfg = {													\
			.ICPolarity =  LL_TIM_IC_POLARITY_RISING,				\
			.ICActiveInput = LL_TIM_ACTIVEINPUT_DIRECTTI,			\
			.ICPrescaler = LL_TIM_ICPSC_DIV1,						\
			.ICFilter =  0,										    \
		},															\
		.IC3cfg = {													\
			.ICPolarity =  LL_TIM_IC_POLARITY_RISING,				\
			.ICActiveInput = LL_TIM_ACTIVEINPUT_DIRECTTI,			\
			.ICPrescaler = LL_TIM_ICPSC_DIV1,						\
			.ICFilter =  0,										    \
		},															\
		.IC4cfg = {													\
			.ICPolarity =  LL_TIM_IC_POLARITY_RISING,				\
			.ICActiveInput = LL_TIM_ACTIVEINPUT_DIRECTTI,			\
			.ICPrescaler = LL_TIM_ICPSC_DIV1,						\
			.ICFilter =  0,										    \
		},															\
		.BTTRcfg = {												\
			.OSSRState =  LL_TIM_OSSR_ENABLE,   			        \
			.OSSIState =  LL_TIM_OSSI_ENABLE,				        \
			.LockLevel = LL_TIM_LOCKLEVEL_OFF,						\
			.DeadTime = 10,										    \
			.BreakState =  LL_TIM_BREAK_ENABLE,						\
			.BreakPolarity = LL_TIM_BREAK_POLARITY_HIGH,			\
			.AutomaticOutput = LL_TIM_AUTOMATICOUTPUT_DISABLE,		\
		},															\
    }      
#endif /* TIMER9_CONFIG */
#endif /* BSP_USING_TIME9 */

#if defined(BSP_USING_TIME10)
#ifndef TIMER10_CONFIG
#define TIMER10_CONFIG                                              \
    {                                                               \
        .Instance = TIM10,                                          \
		.BScfg = {													\
			.Prescaler = 0,							  		        \
			.CounterMode = LL_TIM_COUNTERMODE_UP,     				\
			.Autoreload = 1000-1,    	     						\
			.ClockDivision =  LL_TIM_CLOCKDIVISION_DIV1,          	\
			.RepetitionCounter = 0,								    \
		},															\
		.OC1cfg = {													\
			.OCMode =  LL_TIM_OCMODE_PWM1,   				        \
            .OCState = LL_TIM_OCSTATE_ENABLE,					    \
			.OCNState =  LL_TIM_OCSTATE_ENABLE,			            \
			.CompareValue = 100,		                            \
            .OCPolarity = LL_TIM_OCPOLARITY_HIGH,                   \
			.OCNPolarity = LL_TIM_OCPOLARITY_HIGH,		            \
			.OCIdleState = LL_TIM_OCIDLESTATE_HIGH,		            \
            .OCNIdleState = LL_TIM_OCIDLESTATE_HIGH,		        \
        },															\
		.OC2cfg = {													\
			.OCMode =  LL_TIM_OCMODE_PWM1,   				        \
            .OCState = LL_TIM_OCSTATE_ENABLE,					    \
			.OCNState =  LL_TIM_OCSTATE_ENABLE,			            \
			.CompareValue = 100,		                            \
            .OCPolarity = LL_TIM_OCPOLARITY_HIGH,                   \
			.OCNPolarity = LL_TIM_OCPOLARITY_HIGH,		            \
			.OCIdleState = LL_TIM_OCIDLESTATE_HIGH,		            \
            .OCNIdleState = LL_TIM_OCIDLESTATE_HIGH,		        \
		},															\
		.OC3cfg = {													\
			.OCMode =  LL_TIM_OCMODE_PWM1,   				        \
            .OCState = LL_TIM_OCSTATE_ENABLE,					    \
			.OCNState =  LL_TIM_OCSTATE_ENABLE,			            \
			.CompareValue = 100,		                            \
            .OCPolarity = LL_TIM_OCPOLARITY_HIGH,                   \
			.OCNPolarity = LL_TIM_OCPOLARITY_HIGH,		            \
			.OCIdleState = LL_TIM_OCIDLESTATE_HIGH,		            \
            .OCNIdleState = LL_TIM_OCIDLESTATE_HIGH,		        \
		},															\
		.OC4cfg = {													\
			.OCMode =  LL_TIM_OCMODE_PWM1,   				        \
            .OCState = LL_TIM_OCSTATE_ENABLE,					    \
			.OCNState =  LL_TIM_OCSTATE_ENABLE,			            \
			.CompareValue = 100,		                            \
            .OCPolarity = LL_TIM_OCPOLARITY_HIGH,                   \
			.OCNPolarity = LL_TIM_OCPOLARITY_HIGH,		            \
			.OCIdleState = LL_TIM_OCIDLESTATE_HIGH,		            \
            .OCNIdleState = LL_TIM_OCIDLESTATE_HIGH,		        \
		},															\
		.IC1cfg = {													\
			.ICPolarity =  LL_TIM_IC_POLARITY_RISING,				\
			.ICActiveInput = LL_TIM_ACTIVEINPUT_DIRECTTI,			\
			.ICPrescaler = LL_TIM_ICPSC_DIV1,						\
			.ICFilter =  0,										    \
		},															\
		.IC2cfg = {													\
			.ICPolarity =  LL_TIM_IC_POLARITY_RISING,				\
			.ICActiveInput = LL_TIM_ACTIVEINPUT_DIRECTTI,			\
			.ICPrescaler = LL_TIM_ICPSC_DIV1,						\
			.ICFilter =  0,										    \
		},															\
		.IC3cfg = {													\
			.ICPolarity =  LL_TIM_IC_POLARITY_RISING,				\
			.ICActiveInput = LL_TIM_ACTIVEINPUT_DIRECTTI,			\
			.ICPrescaler = LL_TIM_ICPSC_DIV1,						\
			.ICFilter =  0,										    \
		},															\
		.IC4cfg = {													\
			.ICPolarity =  LL_TIM_IC_POLARITY_RISING,				\
			.ICActiveInput = LL_TIM_ACTIVEINPUT_DIRECTTI,			\
			.ICPrescaler = LL_TIM_ICPSC_DIV1,						\
			.ICFilter =  0,										    \
		},															\
		.BTTRcfg = {												\
			.OSSRState =  LL_TIM_OSSR_ENABLE,   			        \
			.OSSIState =  LL_TIM_OSSI_ENABLE,				        \
			.LockLevel = LL_TIM_LOCKLEVEL_OFF,						\
			.DeadTime = 10,										    \
			.BreakState =  LL_TIM_BREAK_ENABLE,						\
			.BreakPolarity = LL_TIM_BREAK_POLARITY_HIGH,			\
			.AutomaticOutput = LL_TIM_AUTOMATICOUTPUT_DISABLE,		\
		},															\
    }         
#endif /* TIMER10_CONFIG */
#endif /* BSP_USING_TIME10 */

#if defined(BSP_USING_TIME11)
#ifndef TIMER11_CONFIG
#define TIMER11_CONFIG                                              \
    {                                                               \
        .Instance = TIM11,                                          \
		.BScfg = {													\
			.Prescaler = 0,							  		        \
			.CounterMode = LL_TIM_COUNTERMODE_UP,     				\
			.Autoreload = 1000-1,    	     						\
			.ClockDivision =  LL_TIM_CLOCKDIVISION_DIV1,          	\
			.RepetitionCounter = 0,								    \
		},															\
		.OC1cfg = {													\
			.OCMode =  LL_TIM_OCMODE_PWM1,   				        \
            .OCState = LL_TIM_OCSTATE_ENABLE,					    \
			.OCNState =  LL_TIM_OCSTATE_ENABLE,			            \
			.CompareValue = 100,		                            \
            .OCPolarity = LL_TIM_OCPOLARITY_HIGH,                   \
			.OCNPolarity = LL_TIM_OCPOLARITY_HIGH,		            \
			.OCIdleState = LL_TIM_OCIDLESTATE_HIGH,		            \
            .OCNIdleState = LL_TIM_OCIDLESTATE_HIGH,		        \
        },															\
		.OC2cfg = {													\
			.OCMode =  LL_TIM_OCMODE_PWM1,   				        \
            .OCState = LL_TIM_OCSTATE_ENABLE,					    \
			.OCNState =  LL_TIM_OCSTATE_ENABLE,			            \
			.CompareValue = 100,		                            \
            .OCPolarity = LL_TIM_OCPOLARITY_HIGH,                   \
			.OCNPolarity = LL_TIM_OCPOLARITY_HIGH,		            \
			.OCIdleState = LL_TIM_OCIDLESTATE_HIGH,		            \
            .OCNIdleState = LL_TIM_OCIDLESTATE_HIGH,		        \
		},															\
		.OC3cfg = {													\
			.OCMode =  LL_TIM_OCMODE_PWM1,   				        \
            .OCState = LL_TIM_OCSTATE_ENABLE,					    \
			.OCNState =  LL_TIM_OCSTATE_ENABLE,			            \
			.CompareValue = 100,		                            \
            .OCPolarity = LL_TIM_OCPOLARITY_HIGH,                   \
			.OCNPolarity = LL_TIM_OCPOLARITY_HIGH,		            \
			.OCIdleState = LL_TIM_OCIDLESTATE_HIGH,		            \
            .OCNIdleState = LL_TIM_OCIDLESTATE_HIGH,		        \
		},															\
		.OC4cfg = {													\
			.OCMode =  LL_TIM_OCMODE_PWM1,   				        \
            .OCState = LL_TIM_OCSTATE_ENABLE,					    \
			.OCNState =  LL_TIM_OCSTATE_ENABLE,			            \
			.CompareValue = 100,		                            \
            .OCPolarity = LL_TIM_OCPOLARITY_HIGH,                   \
			.OCNPolarity = LL_TIM_OCPOLARITY_HIGH,		            \
			.OCIdleState = LL_TIM_OCIDLESTATE_HIGH,		            \
            .OCNIdleState = LL_TIM_OCIDLESTATE_HIGH,		        \
		},															\
		.IC1cfg = {													\
			.ICPolarity =  LL_TIM_IC_POLARITY_RISING,				\
			.ICActiveInput = LL_TIM_ACTIVEINPUT_DIRECTTI,			\
			.ICPrescaler = LL_TIM_ICPSC_DIV1,						\
			.ICFilter =  0,										    \
		},															\
		.IC2cfg = {													\
			.ICPolarity =  LL_TIM_IC_POLARITY_RISING,				\
			.ICActiveInput = LL_TIM_ACTIVEINPUT_DIRECTTI,			\
			.ICPrescaler = LL_TIM_ICPSC_DIV1,						\
			.ICFilter =  0,										    \
		},															\
		.IC3cfg = {													\
			.ICPolarity =  LL_TIM_IC_POLARITY_RISING,				\
			.ICActiveInput = LL_TIM_ACTIVEINPUT_DIRECTTI,			\
			.ICPrescaler = LL_TIM_ICPSC_DIV1,						\
			.ICFilter =  0,										    \
		},															\
		.IC4cfg = {													\
			.ICPolarity =  LL_TIM_IC_POLARITY_RISING,				\
			.ICActiveInput = LL_TIM_ACTIVEINPUT_DIRECTTI,			\
			.ICPrescaler = LL_TIM_ICPSC_DIV1,						\
			.ICFilter =  0,										    \
		},															\
		.BTTRcfg = {												\
			.OSSRState =  LL_TIM_OSSR_ENABLE,   			        \
			.OSSIState =  LL_TIM_OSSI_ENABLE,				        \
			.LockLevel = LL_TIM_LOCKLEVEL_OFF,						\
			.DeadTime = 10,										    \
			.BreakState =  LL_TIM_BREAK_ENABLE,						\
			.BreakPolarity = LL_TIM_BREAK_POLARITY_HIGH,			\
			.AutomaticOutput = LL_TIM_AUTOMATICOUTPUT_DISABLE,		\
		},															\
    }   
#endif /* TIMER11_CONFIG */
#endif /* BSP_USING_TIME11 */

#if defined(BSP_USING_TIME12)
#ifndef TIMER12_CONFIG
#define TIMER12_CONFIG                                              \
    {                                                               \
        .Instance = TIM12,                                          \
		.BScfg = {													\
			.Prescaler = 0,							  		        \
			.CounterMode = LL_TIM_COUNTERMODE_UP,     				\
			.Autoreload = 1000-1,    	     						\
			.ClockDivision =  LL_TIM_CLOCKDIVISION_DIV1,          	\
			.RepetitionCounter = 0,								    \
		},															\
		.OC1cfg = {													\
			.OCMode =  LL_TIM_OCMODE_PWM1,   				        \
            .OCState = LL_TIM_OCSTATE_ENABLE,					    \
			.OCNState =  LL_TIM_OCSTATE_ENABLE,			            \
			.CompareValue = 100,		                            \
            .OCPolarity = LL_TIM_OCPOLARITY_HIGH,                   \
			.OCNPolarity = LL_TIM_OCPOLARITY_HIGH,		            \
			.OCIdleState = LL_TIM_OCIDLESTATE_HIGH,		            \
            .OCNIdleState = LL_TIM_OCIDLESTATE_HIGH,		        \
        },															\
		.OC2cfg = {													\
			.OCMode =  LL_TIM_OCMODE_PWM1,   				        \
            .OCState = LL_TIM_OCSTATE_ENABLE,					    \
			.OCNState =  LL_TIM_OCSTATE_ENABLE,			            \
			.CompareValue = 100,		                            \
            .OCPolarity = LL_TIM_OCPOLARITY_HIGH,                   \
			.OCNPolarity = LL_TIM_OCPOLARITY_HIGH,		            \
			.OCIdleState = LL_TIM_OCIDLESTATE_HIGH,		            \
            .OCNIdleState = LL_TIM_OCIDLESTATE_HIGH,		        \
		},															\
		.OC3cfg = {													\
			.OCMode =  LL_TIM_OCMODE_PWM1,   				        \
            .OCState = LL_TIM_OCSTATE_ENABLE,					    \
			.OCNState =  LL_TIM_OCSTATE_ENABLE,			            \
			.CompareValue = 100,		                            \
            .OCPolarity = LL_TIM_OCPOLARITY_HIGH,                   \
			.OCNPolarity = LL_TIM_OCPOLARITY_HIGH,		            \
			.OCIdleState = LL_TIM_OCIDLESTATE_HIGH,		            \
            .OCNIdleState = LL_TIM_OCIDLESTATE_HIGH,		        \
		},															\
		.OC4cfg = {													\
			.OCMode =  LL_TIM_OCMODE_PWM1,   				        \
            .OCState = LL_TIM_OCSTATE_ENABLE,					    \
			.OCNState =  LL_TIM_OCSTATE_ENABLE,			            \
			.CompareValue = 100,		                            \
            .OCPolarity = LL_TIM_OCPOLARITY_HIGH,                   \
			.OCNPolarity = LL_TIM_OCPOLARITY_HIGH,		            \
			.OCIdleState = LL_TIM_OCIDLESTATE_HIGH,		            \
            .OCNIdleState = LL_TIM_OCIDLESTATE_HIGH,		        \
		},															\
		.IC1cfg = {													\
			.ICPolarity =  LL_TIM_IC_POLARITY_RISING,				\
			.ICActiveInput = LL_TIM_ACTIVEINPUT_DIRECTTI,			\
			.ICPrescaler = LL_TIM_ICPSC_DIV1,						\
			.ICFilter =  0,										    \
		},															\
		.IC2cfg = {													\
			.ICPolarity =  LL_TIM_IC_POLARITY_RISING,				\
			.ICActiveInput = LL_TIM_ACTIVEINPUT_DIRECTTI,			\
			.ICPrescaler = LL_TIM_ICPSC_DIV1,						\
			.ICFilter =  0,										    \
		},															\
		.IC3cfg = {													\
			.ICPolarity =  LL_TIM_IC_POLARITY_RISING,				\
			.ICActiveInput = LL_TIM_ACTIVEINPUT_DIRECTTI,			\
			.ICPrescaler = LL_TIM_ICPSC_DIV1,						\
			.ICFilter =  0,										    \
		},															\
		.IC4cfg = {													\
			.ICPolarity =  LL_TIM_IC_POLARITY_RISING,				\
			.ICActiveInput = LL_TIM_ACTIVEINPUT_DIRECTTI,			\
			.ICPrescaler = LL_TIM_ICPSC_DIV1,						\
			.ICFilter =  0,										    \
		},															\
		.BTTRcfg = {												\
			.OSSRState =  LL_TIM_OSSR_ENABLE,   			        \
			.OSSIState =  LL_TIM_OSSI_ENABLE,				        \
			.LockLevel = LL_TIM_LOCKLEVEL_OFF,						\
			.DeadTime = 10,										    \
			.BreakState =  LL_TIM_BREAK_ENABLE,						\
			.BreakPolarity = LL_TIM_BREAK_POLARITY_HIGH,			\
			.AutomaticOutput = LL_TIM_AUTOMATICOUTPUT_DISABLE,		\
		},															\
    }    
#endif /* TIMER12_CONFIG */
#endif /* BSP_USING_TIME12 */

#if defined(BSP_USING_TIME13)
#ifndef TIMER13_CONFIG
#define TIMER13_CONFIG                                              \
    {                                                               \
        .Instance = TIM13,                                          \
		.BScfg = {													\
			.Prescaler = 0,							  		        \
			.CounterMode = LL_TIM_COUNTERMODE_UP,     				\
			.Autoreload = 1000-1,    	     						\
			.ClockDivision =  LL_TIM_CLOCKDIVISION_DIV1,          	\
			.RepetitionCounter = 0,								    \
		},															\
		.OC1cfg = {													\
			.OCMode =  LL_TIM_OCMODE_PWM1,   				        \
            .OCState = LL_TIM_OCSTATE_ENABLE,					    \
			.OCNState =  LL_TIM_OCSTATE_ENABLE,			            \
			.CompareValue = 100,		                            \
            .OCPolarity = LL_TIM_OCPOLARITY_HIGH,                   \
			.OCNPolarity = LL_TIM_OCPOLARITY_HIGH,		            \
			.OCIdleState = LL_TIM_OCIDLESTATE_HIGH,		            \
            .OCNIdleState = LL_TIM_OCIDLESTATE_HIGH,		        \
        },															\
		.OC2cfg = {													\
			.OCMode =  LL_TIM_OCMODE_PWM1,   				        \
            .OCState = LL_TIM_OCSTATE_ENABLE,					    \
			.OCNState =  LL_TIM_OCSTATE_ENABLE,			            \
			.CompareValue = 100,		                            \
            .OCPolarity = LL_TIM_OCPOLARITY_HIGH,                   \
			.OCNPolarity = LL_TIM_OCPOLARITY_HIGH,		            \
			.OCIdleState = LL_TIM_OCIDLESTATE_HIGH,		            \
            .OCNIdleState = LL_TIM_OCIDLESTATE_HIGH,		        \
		},															\
		.OC3cfg = {													\
			.OCMode =  LL_TIM_OCMODE_PWM1,   				        \
            .OCState = LL_TIM_OCSTATE_ENABLE,					    \
			.OCNState =  LL_TIM_OCSTATE_ENABLE,			            \
			.CompareValue = 100,		                            \
            .OCPolarity = LL_TIM_OCPOLARITY_HIGH,                   \
			.OCNPolarity = LL_TIM_OCPOLARITY_HIGH,		            \
			.OCIdleState = LL_TIM_OCIDLESTATE_HIGH,		            \
            .OCNIdleState = LL_TIM_OCIDLESTATE_HIGH,		        \
		},															\
		.OC4cfg = {													\
			.OCMode =  LL_TIM_OCMODE_PWM1,   				        \
            .OCState = LL_TIM_OCSTATE_ENABLE,					    \
			.OCNState =  LL_TIM_OCSTATE_ENABLE,			            \
			.CompareValue = 100,		                            \
            .OCPolarity = LL_TIM_OCPOLARITY_HIGH,                   \
			.OCNPolarity = LL_TIM_OCPOLARITY_HIGH,		            \
			.OCIdleState = LL_TIM_OCIDLESTATE_HIGH,		            \
            .OCNIdleState = LL_TIM_OCIDLESTATE_HIGH,		        \
		},															\
		.IC1cfg = {													\
			.ICPolarity =  LL_TIM_IC_POLARITY_RISING,				\
			.ICActiveInput = LL_TIM_ACTIVEINPUT_DIRECTTI,			\
			.ICPrescaler = LL_TIM_ICPSC_DIV1,						\
			.ICFilter =  0,										    \
		},															\
		.IC2cfg = {													\
			.ICPolarity =  LL_TIM_IC_POLARITY_RISING,				\
			.ICActiveInput = LL_TIM_ACTIVEINPUT_DIRECTTI,			\
			.ICPrescaler = LL_TIM_ICPSC_DIV1,						\
			.ICFilter =  0,										    \
		},															\
		.IC3cfg = {													\
			.ICPolarity =  LL_TIM_IC_POLARITY_RISING,				\
			.ICActiveInput = LL_TIM_ACTIVEINPUT_DIRECTTI,			\
			.ICPrescaler = LL_TIM_ICPSC_DIV1,						\
			.ICFilter =  0,										    \
		},															\
		.IC4cfg = {													\
			.ICPolarity =  LL_TIM_IC_POLARITY_RISING,				\
			.ICActiveInput = LL_TIM_ACTIVEINPUT_DIRECTTI,			\
			.ICPrescaler = LL_TIM_ICPSC_DIV1,						\
			.ICFilter =  0,										    \
		},															\
		.BTTRcfg = {												\
			.OSSRState =  LL_TIM_OSSR_ENABLE,   			        \
			.OSSIState =  LL_TIM_OSSI_ENABLE,				        \
			.LockLevel = LL_TIM_LOCKLEVEL_OFF,						\
			.DeadTime = 10,										    \
			.BreakState =  LL_TIM_BREAK_ENABLE,						\
			.BreakPolarity = LL_TIM_BREAK_POLARITY_HIGH,			\
			.AutomaticOutput = LL_TIM_AUTOMATICOUTPUT_DISABLE,		\
		},															\
    }    
#endif /* TIMER13_CONFIG */
#endif /* BSP_USING_TIME13 */

#if defined(BSP_USING_TIME14)
#ifndef TIMER14_CONFIG
#define TIMER14_CONFIG                                              \
    {                                                               \
        .Instance = TIM14,                                          \
		.BScfg = {													\
			.Prescaler = 0,							  		        \
			.CounterMode = LL_TIM_COUNTERMODE_UP,     				\
			.Autoreload = 1000-1,    	     						\
			.ClockDivision =  LL_TIM_CLOCKDIVISION_DIV1,          	\
			.RepetitionCounter = 0,								    \
		},															\
		.OC1cfg = {													\
			.OCMode =  LL_TIM_OCMODE_PWM1,   				        \
            .OCState = LL_TIM_OCSTATE_ENABLE,					    \
			.OCNState =  LL_TIM_OCSTATE_ENABLE,			            \
			.CompareValue = 100,		                            \
            .OCPolarity = LL_TIM_OCPOLARITY_HIGH,                   \
			.OCNPolarity = LL_TIM_OCPOLARITY_HIGH,		            \
			.OCIdleState = LL_TIM_OCIDLESTATE_HIGH,		            \
            .OCNIdleState = LL_TIM_OCIDLESTATE_HIGH,		        \
        },															\
		.OC2cfg = {													\
			.OCMode =  LL_TIM_OCMODE_PWM1,   				        \
            .OCState = LL_TIM_OCSTATE_ENABLE,					    \
			.OCNState =  LL_TIM_OCSTATE_ENABLE,			            \
			.CompareValue = 100,		                            \
            .OCPolarity = LL_TIM_OCPOLARITY_HIGH,                   \
			.OCNPolarity = LL_TIM_OCPOLARITY_HIGH,		            \
			.OCIdleState = LL_TIM_OCIDLESTATE_HIGH,		            \
            .OCNIdleState = LL_TIM_OCIDLESTATE_HIGH,		        \
		},															\
		.OC3cfg = {													\
			.OCMode =  LL_TIM_OCMODE_PWM1,   				        \
            .OCState = LL_TIM_OCSTATE_ENABLE,					    \
			.OCNState =  LL_TIM_OCSTATE_ENABLE,			            \
			.CompareValue = 100,		                            \
            .OCPolarity = LL_TIM_OCPOLARITY_HIGH,                   \
			.OCNPolarity = LL_TIM_OCPOLARITY_HIGH,		            \
			.OCIdleState = LL_TIM_OCIDLESTATE_HIGH,		            \
            .OCNIdleState = LL_TIM_OCIDLESTATE_HIGH,		        \
		},															\
		.OC4cfg = {													\
			.OCMode =  LL_TIM_OCMODE_PWM1,   				        \
            .OCState = LL_TIM_OCSTATE_ENABLE,					    \
			.OCNState =  LL_TIM_OCSTATE_ENABLE,			            \
			.CompareValue = 100,		                            \
            .OCPolarity = LL_TIM_OCPOLARITY_HIGH,                   \
			.OCNPolarity = LL_TIM_OCPOLARITY_HIGH,		            \
			.OCIdleState = LL_TIM_OCIDLESTATE_HIGH,		            \
            .OCNIdleState = LL_TIM_OCIDLESTATE_HIGH,		        \
		},															\
		.IC1cfg = {													\
			.ICPolarity =  LL_TIM_IC_POLARITY_RISING,				\
			.ICActiveInput = LL_TIM_ACTIVEINPUT_DIRECTTI,			\
			.ICPrescaler = LL_TIM_ICPSC_DIV1,						\
			.ICFilter =  0,										    \
		},															\
		.IC2cfg = {													\
			.ICPolarity =  LL_TIM_IC_POLARITY_RISING,				\
			.ICActiveInput = LL_TIM_ACTIVEINPUT_DIRECTTI,			\
			.ICPrescaler = LL_TIM_ICPSC_DIV1,						\
			.ICFilter =  0,										    \
		},															\
		.IC3cfg = {													\
			.ICPolarity =  LL_TIM_IC_POLARITY_RISING,				\
			.ICActiveInput = LL_TIM_ACTIVEINPUT_DIRECTTI,			\
			.ICPrescaler = LL_TIM_ICPSC_DIV1,						\
			.ICFilter =  0,										    \
		},															\
		.IC4cfg = {													\
			.ICPolarity =  LL_TIM_IC_POLARITY_RISING,				\
			.ICActiveInput = LL_TIM_ACTIVEINPUT_DIRECTTI,			\
			.ICPrescaler = LL_TIM_ICPSC_DIV1,						\
			.ICFilter =  0,										    \
		},															\
		.BTTRcfg = {												\
			.OSSRState =  LL_TIM_OSSR_ENABLE,   			        \
			.OSSIState =  LL_TIM_OSSI_ENABLE,				        \
			.LockLevel = LL_TIM_LOCKLEVEL_OFF,						\
			.DeadTime = 10,										    \
			.BreakState =  LL_TIM_BREAK_ENABLE,						\
			.BreakPolarity = LL_TIM_BREAK_POLARITY_HIGH,			\
			.AutomaticOutput = LL_TIM_AUTOMATICOUTPUT_DISABLE,		\
		},															\
    }    
#endif /* TIMER14_CONFIG */
#endif /* BSP_USING_TIME14 */


#endif


#endif

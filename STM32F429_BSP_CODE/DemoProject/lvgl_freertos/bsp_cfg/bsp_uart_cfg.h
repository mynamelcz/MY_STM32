#ifndef __UART_CONFIG_H__
#define __UART_CONFIG_H__


#ifdef __cplusplus
extern "C" {
#endif

#include "board.h"

#if defined(BSP_USING_UART1) || defined(BSP_USING_UART2) || defined(BSP_USING_UART3) || defined(BSP_USING_UART4) || defined(BSP_USING_UART5) || defined(BSP_USING_UART6)

#define __USING_BSP_UART_DRV


#if defined(BSP_USING_UART1)
#ifndef UART1_CONFIG
#define UART1_CONFIG                                                		\
    {                                                               		\
        .Instance = USART1,                                         		\
		.config = {															\
			.BaudRate = 460800,										        \
			.DataWidth = LL_USART_DATAWIDTH_8B,     					    \
			.StopBits = LL_USART_STOPBITS_1,           					    \
			.Parity = LL_USART_PARITY_NONE,								    \
			.TransferDirection =  LL_USART_DIRECTION_TX_RX,          		\
			.HardwareFlowControl = LL_USART_HWCONTROL_NONE, 	            \
            .OverSampling = LL_USART_OVERSAMPLING_16, 	                    \
		},																	\
		.clk_cfg = {														\
			.ClockOutput = LL_USART_CLOCK_ENABLE,							\
			.ClockPolarity = LL_USART_POLARITY_LOW,     					\
			.ClockPhase = LL_USART_PHASE_1EDGE,           					\
			.LastBitClockPulse = LL_USART_LASTCLKPULSE_NO_OUTPUT,			\
		},																	\
    }
#endif /* UART1_CONFIG */
#endif /* BSP_USING_UART1 */


#if defined(BSP_USING_UART2)
#ifndef UART2_CONFIG
#define UART2_CONFIG                                                        \
    {                                                               		\
        .Instance = USART2,                                         		\
		.config = {															\
			.BaudRate = 460800,										        \
			.DataWidth = LL_USART_DATAWIDTH_8B,     					    \
			.StopBits = LL_USART_STOPBITS_1,           					    \
			.Parity = LL_USART_PARITY_NONE,								    \
			.TransferDirection =  LL_USART_DIRECTION_TX_RX,          		\
			.HardwareFlowControl = LL_USART_HWCONTROL_NONE, 	            \
            .OverSampling = LL_USART_OVERSAMPLING_8, 	                    \
		},																	\
		.clk_cfg = {														\
			.ClockOutput = LL_USART_CLOCK_DISABLE,							\
			.ClockPolarity = LL_USART_POLARITY_LOW,     					\
			.ClockPhase = LL_USART_PHASE_1EDGE,           					\
			.LastBitClockPulse = LL_USART_LASTCLKPULSE_NO_OUTPUT,			\
		},																	\
    }
#endif /* UART2_CONFIG */
#endif /* BSP_USING_UART2 */

#if defined(BSP_USING_UART3)
#ifndef UART3_CONFIG
#define UART3_CONFIG                                                        \
    {                                                               		\
        .Instance = USART3,                                         		\
		.config = {															\
			.BaudRate = 460800,										        \
			.DataWidth = LL_USART_DATAWIDTH_8B,     					    \
			.StopBits = LL_USART_STOPBITS_1,           					    \
			.Parity = LL_USART_PARITY_NONE,								    \
			.TransferDirection =  LL_USART_DIRECTION_TX_RX,          		\
			.HardwareFlowControl = LL_USART_HWCONTROL_NONE, 	            \
            .OverSampling = LL_USART_OVERSAMPLING_8, 	                    \
		},																	\
		.clk_cfg = {														\
			.ClockOutput = LL_USART_CLOCK_DISABLE,							\
			.ClockPolarity = LL_USART_POLARITY_LOW,     					\
			.ClockPhase = LL_USART_PHASE_1EDGE,           					\
			.LastBitClockPulse = LL_USART_LASTCLKPULSE_NO_OUTPUT,			\
		},																	\
    }
#endif /* UART3_CONFIG */
#endif /* BSP_USING_UART3 */

#if defined(BSP_USING_UART4)
#ifndef UART4_CONFIG
#define UART4_CONFIG                                                		\
    {                                                               		\
        .Instance = UART4,                                         		    \
		.config = {															\
			.BaudRate = 460800,										        \
			.DataWidth = LL_USART_DATAWIDTH_8B,     					    \
			.StopBits = LL_USART_STOPBITS_1,           					    \
			.Parity = LL_USART_PARITY_NONE,								    \
			.TransferDirection =  LL_USART_DIRECTION_TX_RX,          		\
			.HardwareFlowControl = LL_USART_HWCONTROL_NONE, 	            \
            .OverSampling = LL_USART_OVERSAMPLING_8, 	                    \
		},																	\
		.clk_cfg = {														\
			.ClockOutput = LL_USART_CLOCK_DISABLE,							\
			.ClockPolarity = LL_USART_POLARITY_LOW,     					\
			.ClockPhase = LL_USART_PHASE_1EDGE,           					\
			.LastBitClockPulse = LL_USART_LASTCLKPULSE_NO_OUTPUT,			\
		},																	\
    }
#endif /* UART4_CONFIG */
#endif /* BSP_USING_UART4 */



#if defined(BSP_USING_UART5)
#ifndef UART5_CONFIG
#define UART5_CONFIG                                                		\
    {                                                               		\
        .Instance = UART5,                                         		    \
		.config = {															\
			.BaudRate = 460800,										        \
			.DataWidth = LL_USART_DATAWIDTH_8B,     					    \
			.StopBits = LL_USART_STOPBITS_1,           					    \
			.Parity = LL_USART_PARITY_NONE,								    \
			.TransferDirection =  LL_USART_DIRECTION_TX_RX,          		\
			.HardwareFlowControl = LL_USART_HWCONTROL_NONE, 	            \
            .OverSampling = LL_USART_OVERSAMPLING_8, 	                    \
		},																	\
		.clk_cfg = {														\
			.ClockOutput = LL_USART_CLOCK_DISABLE,							\
			.ClockPolarity = LL_USART_POLARITY_LOW,     					\
			.ClockPhase = LL_USART_PHASE_1EDGE,           					\
			.LastBitClockPulse = LL_USART_LASTCLKPULSE_NO_OUTPUT,			\
		},																	\
    }
#endif /* UART5_CONFIG */
#endif /* BSP_USING_UART5 */


#if defined(BSP_USING_UART6)
#ifndef UART6_CONFIG
#define UART6_CONFIG                                                		\
    {                                                               		\
        .Instance = USART6,                                         		\
		.config = {															\
			.BaudRate = 460800,										        \
			.DataWidth = LL_USART_DATAWIDTH_8B,     					    \
			.StopBits = LL_USART_STOPBITS_1,           					    \
			.Parity = LL_USART_PARITY_NONE,								    \
			.TransferDirection =  LL_USART_DIRECTION_TX_RX,          		\
			.HardwareFlowControl = LL_USART_HWCONTROL_NONE, 	            \
            .OverSampling = LL_USART_OVERSAMPLING_8, 	                    \
		},																	\
		.clk_cfg = {														\
			.ClockOutput = LL_USART_CLOCK_DISABLE,							\
			.ClockPolarity = LL_USART_POLARITY_LOW,     					\
			.ClockPhase = LL_USART_PHASE_1EDGE,           					\
			.LastBitClockPulse = LL_USART_LASTCLKPULSE_NO_OUTPUT,			\
		},																	\
    }
#endif /* UART6_CONFIG */
#endif /* BSP_USING_UART6 */


#ifdef __cplusplus
}
#endif

#endif


#endif

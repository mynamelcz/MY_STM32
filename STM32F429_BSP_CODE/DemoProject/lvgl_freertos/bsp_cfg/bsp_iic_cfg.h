#ifndef __BSP_IIC_CFG_H
#define __BSP_IIC_CFG_H

#include "board.h"

#if defined(BSP_USING_I2C1) || defined(BSP_USING_I2C2) || defined(BSP_USING_I2C3) 

#define __USING_BSP_I2C_DRV




#if defined(BSP_USING_I2C1)
#ifndef I2C1_CONFIG
#define I2C1_CONFIG                             						\
    {                                               					\
        .Instance = I2C1,                           					\
		.config = {														\
			.I2C_ClockSpeed = 100000,									\
			.I2C_Mode = I2C_Mode_I2C,									\
			.I2C_DutyCycle = I2C_DutyCycle_2,								\
			.I2C_OwnAddress1 = 0xaa,									\
			.I2C_Ack = I2C_Ack_Enable,									\
			.I2C_AcknowledgedAddress = I2C_AcknowledgedAddress_7bit,	\
		},																\
    }
#endif /* I2C1_BUS_CONFIG */
#endif /* BSP_USING_I2C1 */
    

#if defined(BSP_USING_I2C2)
#ifndef I2C2_CONFIG
#define I2C2_CONFIG                             						\
    {                                               					\
        .Instance = I2C2,                           					\
		.config = {														\
			.I2C_ClockSpeed = 100000,									\
			.I2C_Mode = I2C_Mode_I2C,									\
			.I2C_DutyCycle = I2C_DutyCycle_2,								\
			.I2C_OwnAddress1 = 0xaa,									\
			.I2C_Ack = I2C_Ack_Enable,									\
			.I2C_AcknowledgedAddress = I2C_AcknowledgedAddress_7bit,	\
		},																\
    }
#endif /* I2C2_BUS_CONFIG */
#endif /* BSP_USING_I2C2 */

#if defined(BSP_USING_I2C3)
#ifndef I2C3_CONFIG
#define I2C3_CONFIG                             						\
    {                                               					\
        .Instance = I2C3,                           					\
		.config = {														\
			.I2C_ClockSpeed = 100000,									\
			.I2C_Mode = I2C_Mode_I2C,									\
			.I2C_DutyCycle = I2C_DutyCycle_2,								\
			.I2C_OwnAddress1 = 0xaa,									\
			.I2C_Ack = I2C_Ack_Enable,									\
			.I2C_AcknowledgedAddress = I2C_AcknowledgedAddress_7bit,	\
		},																\
    }
#endif /* I2C3_BUS_CONFIG */
#endif /* BSP_USING_I2C3 */
	

#endif /* __USING_BSP_I2C_DRV */
#endif










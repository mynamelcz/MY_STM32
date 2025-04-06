#include "bsp_fmc.h"
#include "stm32f4xx.h"
#include "time_delay.h"





static void fmc_lcd_init(void)
{
    __HAL_RCC_FMC_CLK_ENABLE();
    FMC_NORSRAM_InitTypeDef FMC_Init_t;
    FMC_Init_t.NSBank = FMC_NORSRAM_BANK1;
    FMC_Init_t.DataAddressMux = FMC_DATA_ADDRESS_MUX_DISABLE;
    FMC_Init_t.MemoryType = FMC_MEMORY_TYPE_SRAM;
    FMC_Init_t.MemoryDataWidth = FMC_NORSRAM_MEM_BUS_WIDTH_16;
    FMC_Init_t.BurstAccessMode = FMC_BURST_ACCESS_MODE_DISABLE;
    FMC_Init_t.WaitSignalPolarity = FMC_WAIT_SIGNAL_POLARITY_LOW;
    FMC_Init_t.WrapMode = FMC_WRAP_MODE_DISABLE;
    FMC_Init_t.WaitSignalActive = FMC_WAIT_TIMING_BEFORE_WS;
    FMC_Init_t.WriteOperation = FMC_WRITE_OPERATION_ENABLE;
    FMC_Init_t.WaitSignal = FMC_WAIT_SIGNAL_DISABLE;
    FMC_Init_t.ExtendedMode = FMC_EXTENDED_MODE_ENABLE;
    FMC_Init_t.AsynchronousWait = FMC_ASYNCHRONOUS_WAIT_DISABLE;
    FMC_Init_t.WriteBurst = FMC_WRITE_BURST_DISABLE;
    FMC_Init_t.ContinuousClock = FMC_CONTINUOUS_CLOCK_SYNC_ASYNC;
    FMC_Init_t.PageSize =  FMC_PAGE_SIZE_NONE;
    FMC_NORSRAM_Init(FMC_Bank1, &FMC_Init_t);

    FMC_NORSRAM_TimingTypeDef FMC_Timming_t;
    FMC_Timming_t.AddressSetupTime = 0x0F;
    FMC_Timming_t.AddressHoldTime = 0;
    FMC_Timming_t.DataSetupTime = 0x46;
    FMC_Timming_t.BusTurnAroundDuration = 0;
    FMC_Timming_t.CLKDivision = 0;
    FMC_Timming_t.DataLatency = 0;
    FMC_Timming_t.AccessMode = FMC_ACCESS_MODE_A;
    FMC_NORSRAM_Timing_Init(FMC_Bank1, &FMC_Timming_t, FMC_NORSRAM_BANK1);

    FMC_Timming_t.AddressSetupTime = 4;
    FMC_Timming_t.AddressHoldTime = 0;
    FMC_Timming_t.DataSetupTime = 4;
    FMC_Timming_t.BusTurnAroundDuration = 0;
    FMC_Timming_t.CLKDivision = 0;
    FMC_Timming_t.DataLatency = 0;
    FMC_Timming_t.AccessMode = FMC_ACCESS_MODE_A;
    FMC_NORSRAM_Extended_Timing_Init(FMC_Bank1E,
                                     &FMC_Timming_t,
                                     FMC_NORSRAM_BANK1,
                                     FMC_EXTENDED_MODE_ENABLE);
    __FMC_NORSRAM_ENABLE(FMC_Bank1, FMC_NORSRAM_BANK1);
}



static void sdram_send_cmd( uint8_t cmd, uint8_t refresh, uint16_t regval)
{
    FMC_SDRAM_CommandTypeDef command;
    command.CommandMode = cmd;                                            
    command.CommandTarget = FMC_SDRAM_CMD_TARGET_BANK1;                                   
    command.AutoRefreshNumber = refresh;                                   
    command.ModeRegisterDefinition = regval;                               
    FMC_SDRAM_SendCommand(FMC_SDRAM_DEVICE, &command, 0X1000);
}


static void fmc_sdram_init(void)
{
    FMC_SDRAM_InitTypeDef FMC_Init_t;
    FMC_Init_t.SDBank = FMC_SDRAM_BANK1;
    FMC_Init_t.ColumnBitsNumber = FMC_SDRAM_COLUMN_BITS_NUM_9;
    FMC_Init_t.RowBitsNumber = FMC_SDRAM_ROW_BITS_NUM_13;
    FMC_Init_t.MemoryDataWidth = FMC_SDRAM_MEM_BUS_WIDTH_16;
    FMC_Init_t.InternalBankNumber = FMC_SDRAM_INTERN_BANKS_NUM_4;
    FMC_Init_t.CASLatency = FMC_SDRAM_CAS_LATENCY_3;
    FMC_Init_t.WriteProtection = FMC_SDRAM_WRITE_PROTECTION_DISABLE;
    FMC_Init_t.SDClockPeriod = FMC_SDRAM_CLOCK_PERIOD_2;
    FMC_Init_t.ReadBurst = FMC_SDRAM_RBURST_ENABLE;
    FMC_Init_t.ReadPipeDelay = FMC_SDRAM_RPIPE_DELAY_1;
    FMC_SDRAM_Init(FMC_SDRAM_DEVICE, &FMC_Init_t);

    FMC_SDRAM_TimingTypeDef Timing;

    Timing.LoadToActiveDelay = 2;                                                         
    Timing.ExitSelfRefreshDelay = 7;                                                             
    Timing.SelfRefreshTime = 6;                                                                   
    Timing.RowCycleDelay = 6;                                                                                              
    Timing.WriteRecoveryTime = 2;                                       
    Timing.RPDelay = 2;                                                                      
    Timing.RCDDelay = 2;              
    FMC_SDRAM_Timing_Init(FMC_SDRAM_DEVICE,&Timing,FMC_SDRAM_BANK1);
    
    
    
    sdram_send_cmd( FMC_SDRAM_CMD_CLK_ENABLE, 1, 0);                /* 时钟配置使能 */
    TimeDelay.delay_us(500);                                                    /* 至少延时500us */
    sdram_send_cmd( FMC_SDRAM_CMD_PALL, 1, 0);                      /* 对所有存储区预充电 */
    sdram_send_cmd( FMC_SDRAM_CMD_AUTOREFRESH_MODE, 8, 0);          /* 设置自刷新次数 */


#define SDRAM_MODEREG_BURST_LENGTH_1             ((uint16_t)0x0000)
#define SDRAM_MODEREG_BURST_LENGTH_2             ((uint16_t)0x0001)
#define SDRAM_MODEREG_BURST_LENGTH_4             ((uint16_t)0x0002)
#define SDRAM_MODEREG_BURST_LENGTH_8             ((uint16_t)0x0004)
#define SDRAM_MODEREG_BURST_TYPE_SEQUENTIAL      ((uint16_t)0x0000)
#define SDRAM_MODEREG_BURST_TYPE_INTERLEAVED     ((uint16_t)0x0008)
#define SDRAM_MODEREG_CAS_LATENCY_2              ((uint16_t)0x0020)
#define SDRAM_MODEREG_CAS_LATENCY_3              ((uint16_t)0x0030)
#define SDRAM_MODEREG_OPERATING_MODE_STANDARD    ((uint16_t)0x0000)
#define SDRAM_MODEREG_WRITEBURST_MODE_PROGRAMMED ((uint16_t)0x0000)
#define SDRAM_MODEREG_WRITEBURST_MODE_SINGLE     ((uint16_t)0x0200)


    /* 配置模式寄存器,SDRAM的bit0~bit2为指定突发访问的长度，
     * bit3为指定突发访问的类型，bit4~bit6为CAS值，bit7和bit8为运行模式
     * bit9为指定的写突发模式，bit10和bit11位保留位 */
    uint32_t temp = (uint32_t)SDRAM_MODEREG_BURST_LENGTH_1  |                  /* 设置突发长度:1(可以是1/2/4/8) */
              SDRAM_MODEREG_BURST_TYPE_SEQUENTIAL  |                  /* 设置突发类型:连续(可以是连续/交错) */
              SDRAM_MODEREG_CAS_LATENCY_3          |                  /* 设置CAS值:3(可以是2/3) */
              SDRAM_MODEREG_OPERATING_MODE_STANDARD|                  /* 设置操作模式:0,标准模式 */
              SDRAM_MODEREG_WRITEBURST_MODE_SINGLE;                   /* 设置突发写模式:1,单点访问 */
    sdram_send_cmd( FMC_SDRAM_CMD_LOAD_MODE, 1, temp);              /* 设置SDRAM的模式寄存器 */    
    
}




const struct __bsp_fmc_drv BSP_FMC_DRV =
{
    .lcd_init = fmc_lcd_init,
    .sdram_init = fmc_sdram_init,
};















#include "touch_resistive.h"
#include "stm32f4xx.h"
#include "bsp_gpio.h"
#include "bsp_uart.h"
#include "bsp_sys.h"
#include "bsp_nvic.h"
#include "bsp_fmc.h"
#include "time_delay.h"


#define RTOUCH_PEN_PIN      GET_PIN(H,7)

#define RTOUCH_CS_PIN       GET_PIN(I,8)
#define RTOUCH_CLK_PIN      GET_PIN(H,6)
#define RTOUCH_MISO_PIN     GET_PIN(G,3)
#define RTOUCH_MOSI_PIN     GET_PIN(I,3)

#define RTOUCH_PEN_R()      BSP_GPIO_DRV.pin_read(RTOUCH_PEN_PIN)


#define SPI_CS(x)           BSP_GPIO_DRV.pin_write(RTOUCH_CS_PIN,x)
#define SPI_CLK(x)          BSP_GPIO_DRV.pin_write(RTOUCH_CLK_PIN,x)
#define SPI_MOSI(x)         BSP_GPIO_DRV.pin_write(RTOUCH_MOSI_PIN,x)
#define SPI_MISO_R()        BSP_GPIO_DRV.pin_read(RTOUCH_MISO_PIN)


void touch_resistive_init(void)
{
    BSP_GPIO_DRV.pin_mode(RTOUCH_PEN_PIN, PIN_Mode_IN, PIN_PullUp, 0);
    BSP_GPIO_DRV.pin_mode(RTOUCH_MISO_PIN, PIN_Mode_IN, PIN_PullUp, 0);
    BSP_GPIO_DRV.pin_mode(RTOUCH_CS_PIN, PIN_Mode_Out_PP, PIN_NoPull, 0);
    BSP_GPIO_DRV.pin_mode(RTOUCH_CLK_PIN, PIN_Mode_Out_PP, PIN_NoPull, 0);
    BSP_GPIO_DRV.pin_mode(RTOUCH_MOSI_PIN, PIN_Mode_Out_PP, PIN_NoPull, 0);
    SPI_CS(1);
    SPI_CLK(0);
    SPI_MOSI(0);
    TimeDelay.delay_ms(1);
}

#define __CLK_DELAY()   TimeDelay.delay_us(1)



#define GET_CMD(A,SER,PD) (0X80|((A&0X7)<<4)|(PD&0x3))

#define CMD_READ_X     GET_CMD(5, 0, 0)
#define CMD_READ_Y     GET_CMD(1, 0, 0)
#define CMD_READ_Z1    GET_CMD(3, 0, 0)
#define CMD_READ_Z2    GET_CMD(4, 0, 0)

static uint16_t xpt2046_read(uint8_t cmd)
{
    int i = 0;
    uint16_t rdata = 0;
    SPI_CS(0);
    __CLK_DELAY() ;

    cmd |= 0X80;
    for(i = 0; i < 8; i++)
    {
        if(cmd & 0x80)
        {
            SPI_MOSI(1);
        }
        else
        {
            SPI_MOSI(0);
        }
        cmd <<= 1;
        SPI_CLK(1);
        __CLK_DELAY() ;
        SPI_CLK(0);
        __CLK_DELAY() ;
    }
    SPI_CLK(1);
    __CLK_DELAY() ;
    SPI_CLK(0);
    __CLK_DELAY() ;
    for(i = 0; i < 16; i++)
    {
        rdata <<= 1;
        SPI_CLK(1);
        __CLK_DELAY() ;
        if(SPI_MISO_R())
        {
            rdata |= 1;
        }
        SPI_CLK(0);
        __CLK_DELAY();
    }
    rdata >>= 4;
    SPI_CS(1);
    __CLK_DELAY();
    return rdata;
}

void touch_read_xy(uint16_t* x, uint16_t* y)
{
    *x = xpt2046_read(CMD_READ_X);
    *y = xpt2046_read(CMD_READ_Y);
}

//void touch_read_rp(uint16_t x)
//{
//    uint16_t z1 = xpt2046_read(CMD_READ_Z1);
//    uint16_t z2 = xpt2046_read(CMD_READ_Z2);
//    
//}

void touch_test(void)
{
    u8 cmd = 0;
    uint16_t x,y,z1,z2;
    float p = 0;
    touch_resistive_init();

    while(1)
    {
//        cmd = GET_CMD(0, 1, 0);
//        res = xpt2046_read(cmd);
//        LOG_D("cmd: %02x  0x%04x \n", cmd, res);
//        TimeDelay.delay_ms(100);
//        cmd = GET_CMD(7, 1, 0);
//        res = xpt2046_read(cmd);
//        LOG_D("cmd: %02x  0x%04x \n", cmd, res);
//        TimeDelay.delay_ms(100);

        x = xpt2046_read(CMD_READ_X);
        y = xpt2046_read(CMD_READ_Y);
        z1 = xpt2046_read(CMD_READ_Z1);
        z2 = xpt2046_read(CMD_READ_Z2);  
        p = x*1.0*(z2/z1-1)/4096.0;
        LOG_D("0x%04x 0x%04x 0x%04x 0x%04x   %f\n", x, y,z1,z2,p);
       // printf("PEN: %d", RTOUCH_PEN_R());
       // printf("\n");
        TimeDelay.delay_ms(100);
    }
}
#include "touch_resistive.h"
#include "bsp_gpio.h"
#include "bsp_uart.h"
#include "bsp_sys.h"
#include "bsp_nvic.h"
#include "bsp_fmc.h"
#include "time_delay.h"

#include "mcu_lcd.h"


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

#define __CLK_DELAY()   TimeDelay.delay_us(1)

#define GET_CMD(A,SER,PD) (0X80|((A&0X7)<<4)|(PD&0x3))
#define CMD_READ_X     GET_CMD(5, 0, 0)
#define CMD_READ_Y     GET_CMD(1, 0, 0)
#define CMD_READ_Z1    GET_CMD(3, 0, 0)
#define CMD_READ_Z2    GET_CMD(4, 0, 0)



static float xfac_g = 0;
static float yfac_g = 0;
static uint16_t xlc_g = 0;
static uint16_t ylc_g = 0;

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
    int16_t xl,yl;
    xl = xpt2046_read(CMD_READ_X);
    yl = xpt2046_read(CMD_READ_Y);
    *x = (xl-xlc_g)/xfac_g+(LCD_HOR_SIZE>>1);
    *y = (yl-ylc_g)/yfac_g+(LCD_VER_SIZE>>1);
}

uint8_t touch_is_pressed(void)
{
    if(RTOUCH_PEN_R() == 0)
    {
        return 1;
    }
    return 0;
}



static void show_touch_point(uint16_t x, uint16_t y, uint16_t size, uint16_t color)
{
    for(uint16_t i = x - size; i <= x + size; i++)
    {
        lcd_draw_point(i, y, color);
    }
    for(uint16_t i = y - size; i <= y + size; i++)
    {
        lcd_draw_point(x, i, color);
    }
}

void touch_screen_calibration(void)
{
    int16_t x[5];
    int16_t y[5];
    int16_t s1, s2, s3, s4;
    double px, py;
    while(1)
    {
        lcd_printf(LCD_HOR_SIZE / 10, LCD_VER_SIZE / 4, 12, RED, "Screen calibration has started.");
        show_touch_point(20, 20, 10, RED);
        while(RTOUCH_PEN_R() == 1);
        TimeDelay.delay_ms(10);
        while(RTOUCH_PEN_R() == 1);
        x[0] = xpt2046_read(CMD_READ_X);
        y[0] = xpt2046_read(CMD_READ_Y);
        show_touch_point(20, 20, 10, WHITE);
        LOG_D("1. %04d   %04d\n", x[0], y[0]);
        while(RTOUCH_PEN_R() == 0);
        TimeDelay.delay_ms(10);
        while(RTOUCH_PEN_R() == 0);

        show_touch_point(LCD_HOR_SIZE - 20, 20, 10, RED);
        while(RTOUCH_PEN_R() == 1);
        TimeDelay.delay_ms(10);
        while(RTOUCH_PEN_R() == 1);
        x[1] = xpt2046_read(CMD_READ_X);
        y[1] = xpt2046_read(CMD_READ_Y);
        show_touch_point(LCD_HOR_SIZE - 20, 20, 10, WHITE);
        LOG_D("2. %04d   %04d\n", x[1], y[1]);
        while(RTOUCH_PEN_R() == 0);
        TimeDelay.delay_ms(10);
        while(RTOUCH_PEN_R() == 0);


        show_touch_point(20, LCD_VER_SIZE - 20, 10, RED);
        while(RTOUCH_PEN_R() == 1);
        TimeDelay.delay_ms(10);
        while(RTOUCH_PEN_R() == 1);
        x[2] = xpt2046_read(CMD_READ_X);
        y[2] = xpt2046_read(CMD_READ_Y);
        show_touch_point(20, LCD_VER_SIZE - 20, 10, WHITE);
        LOG_D("3. %04d   %04d\n", x[2], y[2]);
        while(RTOUCH_PEN_R() == 0);
        TimeDelay.delay_ms(10);
        while(RTOUCH_PEN_R() == 0);

        show_touch_point(LCD_HOR_SIZE - 20, LCD_VER_SIZE - 20, 10, RED);
        while(RTOUCH_PEN_R() == 1);
        TimeDelay.delay_ms(10);
        while(RTOUCH_PEN_R() == 1);
        x[3] = xpt2046_read(CMD_READ_X);
        y[3] = xpt2046_read(CMD_READ_Y);
        show_touch_point(LCD_HOR_SIZE - 20, LCD_VER_SIZE - 20, 10, WHITE);
        LOG_D("4. %04d   %04d\n", x[3], y[3]);
        while(RTOUCH_PEN_R() == 0);
        TimeDelay.delay_ms(10);
        while(RTOUCH_PEN_R() == 0);


        show_touch_point(LCD_HOR_SIZE >> 1, LCD_VER_SIZE >> 1, 10, RED);
        while(RTOUCH_PEN_R() == 1);
        TimeDelay.delay_ms(10);
        while(RTOUCH_PEN_R() == 1);
        x[4] = xpt2046_read(CMD_READ_X);
        y[4] = xpt2046_read(CMD_READ_Y);
        show_touch_point(LCD_HOR_SIZE >> 1, LCD_VER_SIZE >> 1, 10, WHITE);
        LOG_D("5. %04d   %04d\n", x[4], y[4]);
        while(RTOUCH_PEN_R() == 0);
        TimeDelay.delay_ms(10);
        while(RTOUCH_PEN_R() == 0);

        s1 = x[1] - x[0];                                     /* 第2个点和第1个点的X轴物理坐标差值(AD值) */
        s3 = x[3] - x[2];                                     /* 第4个点和第3个点的X轴物理坐标差值(AD值) */
        s2 = y[3] - y[1];                                     /* 第4个点和第2个点的Y轴物理坐标差值(AD值) */
        s4 = y[2] - y[0];                                     /* 第3个点和第1个点的Y轴物理坐标差值(AD值) */

        px = (double)s1 / s3;                                           /* X轴比例因子 */
        py = (double)s2 / s4;                                           /* Y轴比例因子 */

        if(px < 0)
        {
            px = -px;
        }
        if(py < 0)
        {
            py = -py;
        }
        LOG_D("px:%02f  py:%02f \n", px, py);
        if((px < 0.95) || (px > 1.05) || (py < 0.95) || (py > 1.05))
        {

            lcd_printf(LCD_HOR_SIZE / 10, LCD_VER_SIZE / 4, 12, RED, "px:%02f  py:%02f   ERR\n", px, py);
            continue;
        }
        lcd_printf(LCD_HOR_SIZE / 10, LCD_VER_SIZE / 4, 12, RED, "px:%02f  py:%02f   Ok\n", px, py);
        xfac_g = (float)(s1 + s3) / (2 * (LCD_HOR_SIZE - 40));
        yfac_g = (float)(s2 + s4) / (2 * (LCD_VER_SIZE - 40));
        xlc_g = x[4];
        ylc_g = y[4];
        break;
    }
}


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
    touch_screen_calibration();
}







void touch_test(void)
{
//    uint16_t rx,ry;
//    int16_t x[5];
//    int16_t y[5];
//    int16_t s1, s2, s3, s4;
//    double px, py;

//    lcd_init();
//    touch_resistive_init();




//    while(1)
//    {
//        lcd_printf(LCD_HOR_SIZE / 10, LCD_VER_SIZE / 4, 12, RED, "Screen calibration has started.");
//        show_touch_point(20, 20, 10, RED);
//        while(RTOUCH_PEN_R() == 1);
//        TimeDelay.delay_ms(10);
//        while(RTOUCH_PEN_R() == 1);
//        x[0] = xpt2046_read(CMD_READ_X);
//        y[0] = xpt2046_read(CMD_READ_Y);
//        show_touch_point(20, 20, 10, WHITE);
//        LOG_D("1. %04d   %04d\n", x[0], y[0]);
//        while(RTOUCH_PEN_R() == 0);
//        TimeDelay.delay_ms(10);
//        while(RTOUCH_PEN_R() == 0);

//        show_touch_point(LCD_HOR_SIZE - 20, 20, 10, RED);
//        while(RTOUCH_PEN_R() == 1);
//        TimeDelay.delay_ms(10);
//        while(RTOUCH_PEN_R() == 1);
//        x[1] = xpt2046_read(CMD_READ_X);
//        y[1] = xpt2046_read(CMD_READ_Y);
//        show_touch_point(LCD_HOR_SIZE - 20, 20, 10, WHITE);
//        LOG_D("2. %04d   %04d\n", x[1], y[1]);
//        while(RTOUCH_PEN_R() == 0);
//        TimeDelay.delay_ms(10);
//        while(RTOUCH_PEN_R() == 0);


//        show_touch_point(20, LCD_VER_SIZE - 20, 10, RED);
//        while(RTOUCH_PEN_R() == 1);
//        TimeDelay.delay_ms(10);
//        while(RTOUCH_PEN_R() == 1);
//        x[2] = xpt2046_read(CMD_READ_X);
//        y[2] = xpt2046_read(CMD_READ_Y);
//        show_touch_point(20, LCD_VER_SIZE - 20, 10, WHITE);
//        LOG_D("3. %04d   %04d\n", x[2], y[2]);
//        while(RTOUCH_PEN_R() == 0);
//        TimeDelay.delay_ms(10);
//        while(RTOUCH_PEN_R() == 0);

//        show_touch_point(LCD_HOR_SIZE - 20, LCD_VER_SIZE - 20, 10, RED);
//        while(RTOUCH_PEN_R() == 1);
//        TimeDelay.delay_ms(10);
//        while(RTOUCH_PEN_R() == 1);
//        x[3] = xpt2046_read(CMD_READ_X);
//        y[3] = xpt2046_read(CMD_READ_Y);
//        show_touch_point(LCD_HOR_SIZE - 20, LCD_VER_SIZE - 20, 10, WHITE);
//        LOG_D("4. %04d   %04d\n", x[3], y[3]);
//        while(RTOUCH_PEN_R() == 0);
//        TimeDelay.delay_ms(10);
//        while(RTOUCH_PEN_R() == 0);


//        show_touch_point(LCD_HOR_SIZE >> 1, LCD_VER_SIZE >> 1, 10, RED);
//        while(RTOUCH_PEN_R() == 1);
//        TimeDelay.delay_ms(10);
//        while(RTOUCH_PEN_R() == 1);
//        x[4] = xpt2046_read(CMD_READ_X);
//        y[4] = xpt2046_read(CMD_READ_Y);
//        show_touch_point(LCD_HOR_SIZE >> 1, LCD_VER_SIZE >> 1, 10, WHITE);
//        LOG_D("5. %04d   %04d\n", x[4], y[4]);
//        while(RTOUCH_PEN_R() == 0);
//        TimeDelay.delay_ms(10);
//        while(RTOUCH_PEN_R() == 0);

//        s1 = x[1] - x[0];                                     /* 第2个点和第1个点的X轴物理坐标差值(AD值) */
//        s3 = x[3] - x[2];                                     /* 第4个点和第3个点的X轴物理坐标差值(AD值) */
//        s2 = y[3] - y[1];                                     /* 第4个点和第2个点的Y轴物理坐标差值(AD值) */
//        s4 = y[2] - y[0];                                     /* 第3个点和第1个点的Y轴物理坐标差值(AD值) */

//        px = (double)s1 / s3;                                           /* X轴比例因子 */
//        py = (double)s2 / s4;                                           /* Y轴比例因子 */

//        if(px < 0)
//        {
//            px = -px;
//        }
//        if(py < 0)
//        {
//            py = -py;
//        }
//        LOG_D("px:%02f  py:%02f \n", px, py);
//        if((px < 0.95) || (px > 1.05) || (py < 0.95) || (py > 1.05))
//        {

//            lcd_printf(LCD_HOR_SIZE / 10, LCD_VER_SIZE / 4, 12, RED, "px:%02f  py:%02f   ERR\n", px, py);
//            continue;
//        }
//        lcd_printf(LCD_HOR_SIZE / 10, LCD_VER_SIZE / 4, 12, RED, "px:%02f  py:%02f   Ok\n", px, py);
//        xfac_g = (float)(s1 + s3) / (2 * (LCD_HOR_SIZE - 40));
//        yfac_g = (float)(s2 + s4) / (2 * (LCD_VER_SIZE - 40));
//        xlc_g = x[4];
//        ylc_g = y[4];
//        TimeDelay.delay_ms(500);
//        
//        
//        while(1)
//        {
//            while(RTOUCH_PEN_R() == 1);
//            TimeDelay.delay_ms(10);
//            while(RTOUCH_PEN_R() == 1);
//            touch_read_xy(&rx,&ry);
//            LOG_D("%d  %d\n",rx,ry);
//        }
//    }
}
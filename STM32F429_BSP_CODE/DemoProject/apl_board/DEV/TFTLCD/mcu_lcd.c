#include "mcu_lcd.h"
#include "stm32f4xx.h"
#include "bsp_gpio.h"
#include "bsp_uart.h"
#include "bsp_sys.h"
#include "bsp_nvic.h"
#include "bsp_fmc.h"
#include "time_delay.h"
#include "st7789_drv_font.h"

#include "stdarg.h"
//#define LCD_RST_PIN     GET_PIN()
#define LCD_CS_PIN      FMC_NE1_PIN     
#define LCD_WR_PIN      FMC_NWE_PIN     
#define LCD_RD_PIN      FMC_NOE_PIN     
#define LCD_RS_PIN      FMC_A18_PIN     
#define LCD_BL_PIN      GET_PIN(B,5)
#define LCD_BL(x)	    BSP_GPIO_DRV.pin_write(LCD_BL_PIN,x)


static st7789_handle_t gs_handle;        /**< st7789 handle */
const u8 p_gamma_control_buf[14] = {0xd0, 0x00, 0x02, 0x07, 0x0a, 0x28, 0x32, 0x44, 0x42, 0x06, 0x0e, 0x12, 0x14, 0x17,};
const u8 n_gamma_control_buf[14] = {0xd0, 0x00, 0x02, 0x07, 0x0a, 0x28, 0x31, 0x54, 0x47, 0x0e, 0x1c, 0x17, 0x1b, 0x1e,};




static void lcd_ex_st7789_reginit(void)
{
    st7789_exit_sleep_mode(&gs_handle);
    st7789_set_memory_data_access_control(&gs_handle, 0x08);
    st7789_set_interface_pixel_format(&gs_handle,
                                      ST7789_RGB_INTERFACE_COLOR_FORMAT_65K,
                                      ST7789_CONTROL_INTERFACE_COLOR_FORMAT_16_BIT);
    st7789_set_porch(&gs_handle,
                     0x0C,
                     0x0C,
                     ST7789_BOOL_FALSE, 3, 3, 3, 3);
    
    st7789_set_gate_control(&gs_handle, ST7789_VGHS_13P26_V, ST7789_VGLS_NEGATIVE_10P43);
    st7789_set_vcoms(&gs_handle, 0x35);
    st7789_set_lcm_control(&gs_handle,
                           ST7789_BOOL_FALSE,
                           ST7789_BOOL_FALSE,
                           ST7789_BOOL_FALSE,
                           ST7789_BOOL_TRUE,
                           ST7789_BOOL_TRUE,
                           ST7789_BOOL_FALSE,
                           ST7789_BOOL_FALSE);
    st7789_set_vdv_vrh_from(&gs_handle, ST7789_VDV_VRH_FROM_CMD);
    st7789_set_vrhs(&gs_handle, 0x10);
    st7789_set_vdv(&gs_handle, 0x20);
    st7789_set_frame_rate(&gs_handle,
                          ST7789_INVERSION_SELECTION_DOT,
                          ST7789_FRAME_RATE_60_HZ);
    st7789_set_power_control_1(&gs_handle,
                               ST7789_AVDD_6P8_V,
                               ST7789_AVCL_NEGTIVE_4P8_V,
                               ST7789_VDS_2P3_V);
    st7789_set_positive_voltage_gamma_control(&gs_handle, (uint8_t *)p_gamma_control_buf);
    st7789_set_negative_voltage_gamma_control(&gs_handle, (uint8_t *)n_gamma_control_buf);
    st7789_set_column_address(&gs_handle, 0, gs_handle.column-1);
    st7789_set_row_address(&gs_handle, 0, gs_handle.row-1);
    st7789_display_on(&gs_handle);
}





static void lcd_cmd(uint8_t regno)
{
    LCD->LCD_REG = regno;
}
static void lcd_write_byte(uint8_t data)
{
    LCD->LCD_RAM = data;
}
static void lcd_write_16b(uint16_t data)
{
    LCD->LCD_RAM = data;
}
static void lcd_write_bytes(uint8_t* buf, uint16_t len)
{
    for(int i = 0 ; i < len; i++)
    {
        lcd_write_byte(buf[i]);
    }
}

static uint8_t lcd_read_byte(void)
{
    volatile uint8_t ram; 
    ram = LCD->LCD_RAM;
    return ram;
}

static void lcd_read_bytes(uint8_t* buf, uint16_t len)
{
    for(int i = 0 ; i < len; i++)
    {
        buf[i] = lcd_read_byte();
    }
}


void lcd_init(void)
{
    BSP_GPIO_DRV.pin_mode(LCD_BL_PIN, PIN_Mode_Out_PP, PIN_NoPull, 0);
    BSP_GPIO_DRV.pin_mode(LCD_CS_PIN, PIN_Mode_AF_PP, PIN_PullUp, GPIO_AF12_FMC); 
    BSP_GPIO_DRV.pin_mode(LCD_WR_PIN, PIN_Mode_AF_PP, PIN_PullUp, GPIO_AF12_FMC); 
    BSP_GPIO_DRV.pin_mode(LCD_RD_PIN, PIN_Mode_AF_PP, PIN_PullUp, GPIO_AF12_FMC); 
    BSP_GPIO_DRV.pin_mode(LCD_RS_PIN, PIN_Mode_AF_PP, PIN_PullUp, GPIO_AF12_FMC); 
    BSP_GPIO_DRV.pin_mode(FMC_D0_PIN, PIN_Mode_AF_PP, PIN_PullUp, GPIO_AF12_FMC); 
    BSP_GPIO_DRV.pin_mode(FMC_D1_PIN, PIN_Mode_AF_PP, PIN_PullUp, GPIO_AF12_FMC); 
    BSP_GPIO_DRV.pin_mode(FMC_D2_PIN, PIN_Mode_AF_PP, PIN_PullUp, GPIO_AF12_FMC); 
    BSP_GPIO_DRV.pin_mode(FMC_D3_PIN, PIN_Mode_AF_PP, PIN_PullUp, GPIO_AF12_FMC); 
    BSP_GPIO_DRV.pin_mode(FMC_D4_PIN, PIN_Mode_AF_PP, PIN_PullUp, GPIO_AF12_FMC); 
    BSP_GPIO_DRV.pin_mode(FMC_D5_PIN, PIN_Mode_AF_PP, PIN_PullUp, GPIO_AF12_FMC); 
    BSP_GPIO_DRV.pin_mode(FMC_D6_PIN, PIN_Mode_AF_PP, PIN_PullUp, GPIO_AF12_FMC); 
    BSP_GPIO_DRV.pin_mode(FMC_D7_PIN, PIN_Mode_AF_PP, PIN_PullUp, GPIO_AF12_FMC); 
    BSP_GPIO_DRV.pin_mode(FMC_D8_PIN, PIN_Mode_AF_PP, PIN_PullUp, GPIO_AF12_FMC); 
    BSP_GPIO_DRV.pin_mode(FMC_D9_PIN, PIN_Mode_AF_PP, PIN_PullUp, GPIO_AF12_FMC); 
    BSP_GPIO_DRV.pin_mode(FMC_D10_PIN, PIN_Mode_AF_PP, PIN_PullUp, GPIO_AF12_FMC);
    BSP_GPIO_DRV.pin_mode(FMC_D11_PIN, PIN_Mode_AF_PP, PIN_PullUp, GPIO_AF12_FMC);
    BSP_GPIO_DRV.pin_mode(FMC_D12_PIN, PIN_Mode_AF_PP, PIN_PullUp, GPIO_AF12_FMC);
    BSP_GPIO_DRV.pin_mode(FMC_D13_PIN, PIN_Mode_AF_PP, PIN_PullUp, GPIO_AF12_FMC);
    BSP_GPIO_DRV.pin_mode(FMC_D14_PIN, PIN_Mode_AF_PP, PIN_PullUp, GPIO_AF12_FMC);
    BSP_GPIO_DRV.pin_mode(FMC_D15_PIN, PIN_Mode_AF_PP, PIN_PullUp, GPIO_AF12_FMC);
    BSP_FMC_DRV.lcd_init();
    
    gs_handle.write_cmd = lcd_cmd;
    gs_handle.write_byte = lcd_write_byte;
    gs_handle.write_bytes = lcd_write_bytes;
    gs_handle.write_16b = lcd_write_16b;
    gs_handle.read_byte = lcd_read_byte;
    gs_handle.read_bytes = lcd_read_bytes;
    gs_handle.delay_ms = TimeDelay.delay_ms;
    gs_handle.column = 240;
    gs_handle.row = 320;
    gs_handle.format = 0x5;
    lcd_ex_st7789_reginit();      
}




void lcd_backlight(uint8_t en)
{
    LCD_BL(en);
}

void lcd_clear(uint16_t color)
{
    st7789_clear(&gs_handle,color);  
}

void lcd_fill_rect(uint16_t sx, uint16_t sy, uint16_t ex, uint16_t ey, uint16_t color)
{
    st7789_fill_rect(&gs_handle,sx,sy,ex,ey,color);
}






void lcd_show_char(uint16_t x, uint16_t y, uint8_t chr, uint8_t size, uint32_t color)
{
    uint8_t temp, t, t1;
    uint16_t y0 = y;
    uint8_t csize = (size / 8 + ((size % 8) ? 1 : 0)) * (size / 2);                 /* get size */

    chr = chr - ' ';                                                                /* get index */
    for(t = 0; t < csize; t++)                                                      /* write size */
    {
        if(size == 12)                                                              /* if size 12 */
        {
            temp = gsc_st7789_ascii_1206[chr][t];                                   /* get ascii 1206 */
        }
        else if(size == 16)                                                         /* if size 16 */
        {
            temp = gsc_st7789_ascii_1608[chr][t];                                   /* get ascii 1608 */
        }
        else if(size == 24)                                                         /* if size 24 */
        {
            temp = gsc_st7789_ascii_2412[chr][t];                                   /* get ascii 2412 */
        }
        else
        {
            return;                                                                 /* return error */
        }
        for(t1 = 0; t1 < 8; t1++)                                                   /* write one line */
        {
            if((temp & 0x80) != 0)                                                  /* if 1 */
            {
                st7789_draw_point(&gs_handle, x, y, color);                           /* draw point */
            }
            else
            {
                st7789_draw_point(&gs_handle, x, y, BACKGROUND_COLOR);
            }
            temp <<= 1;                                                             /* left shift 1 */
            y++;
            if((y - y0) == size)                                                    /* reset size */
            {
                y = y0;                                                             /* set y */
                x++;                                                                /* x++ */

                break;                                                              /* break */
            }
        }
    }
}

/**
 * @brief  在 LCD 上实现类似 printf 的功能
 * @param  handle 指向 st7789_handle_t 结构体的指针
 * @param  x 显示起始位置的 x 坐标
 * @param  y 显示起始位置的 y 坐标
 * @param  size 字符显示大小
 * @param  color 字符显示颜色
 * @param  format 格式化字符串，类似于 printf 的格式化字符串
 * @return 成功显示的字符数
 */
int lcd_printf(uint16_t x, uint16_t y, uint8_t size, uint32_t color, const char* format, ...) 
{
    char buffer[256];  // 假设最大长度为 256，可根据实际情况调整
    va_list args;
    va_start(args, format);
    int len = vsnprintf(buffer, sizeof(buffer), format, args);
    va_end(args);

    if (len < 0) {
        return -1;  // 格式化失败
    }

    int char_count = 0;
    for (int i = 0; i < len; i++) {
        if (buffer[i] == '\n') {
            // 处理换行符
            y += size;
            x = 0;
        } else {
            lcd_show_char(x, y, buffer[i], size, color);
            x += size / 2;  // 假设字符宽度是高度的一半，可根据实际情况调整
            char_count++;
        }
    }

    return char_count;
}









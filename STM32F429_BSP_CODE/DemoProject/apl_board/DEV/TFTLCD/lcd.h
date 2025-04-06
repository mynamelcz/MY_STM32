#ifndef __LCD_H
#define __LCD_H

#include "lcd.h"
#include "stm32f4xx.h"
#include "bsp_gpio.h"
#include "bsp_uart.h"
#include "bsp_sys.h"
#include "bsp_nvic.h"
#include "bsp_fmc.h"
#include "time_delay.h"
#include "st7789_drv.h"


#define LCD_FMC_NEX         1             
#define LCD_FMC_AX          18            

typedef struct
{
    volatile uint16_t LCD_REG;
    volatile uint16_t LCD_RAM;
} LCD_TypeDef;


#define LCD_BASE        (uint32_t)((0X60000000 + (0X4000000 * (LCD_FMC_NEX - 1))) | (((1 << LCD_FMC_AX) * 2) -2))
#define LCD             ((LCD_TypeDef *) LCD_BASE)

#define WHITE           0xFFFF      
#define BLACK           0x0000      
#define RED             0xF800      
#define GREEN           0x07E0      
#define BLUE            0x001F      
#define MAGENTA         0xF81F      
#define YELLOW          0xFFE0      
#define CYAN            0x07FF      

#define BROWN           0xBC40      
#define BRRED           0xFC07      
#define GRAY            0x8430      
#define DARKBLUE        0x01CF      
#define LIGHTBLUE       0x7D7C      
#define GRAYBLUE        0x5458      
#define LIGHTGREEN      0x841F      
#define LGRAY           0xC618      
#define LGRAYBLUE       0xA651      
#define LBBLUE          0x2B12      

#define BACKGROUND_COLOR WHITE

void lcd_init(void);
void lcd_backlight(uint8_t en);
void lcd_clear(uint16_t color);
void lcd_fill_rect(uint16_t sx, uint16_t sy, uint16_t ex, uint16_t ey, uint16_t color);
void lcd_show_string(uint16_t x, uint16_t y, char* str, uint32_t color, st7789_font_t font);
int lcd_printf(uint16_t x, uint16_t y, uint8_t size, uint32_t color, const char* format, ...);
#endif


















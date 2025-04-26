/**
 * Copyright (c) 2015 - present LibDriver All rights reserved
 *
 * The MIT License (MIT)
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 * @file      driver_st7789.c
 * @brief     driver st7789 source file
 * @version   1.0.0
 * @author    Shifeng Li
 * @date      2023-04-15
 *
 * <h3>history</h3>
 * <table>
 * <tr><th>Date        <th>Version  <th>Author      <th>Description
 * <tr><td>2023/04/15  <td>1.0      <td>Shifeng Li  <td>first upload
 * </table>
 */

#include "st7789_drv.h"
#include "st7789_drv_font.h"



/**
 * @brief chip command definition
 */
#define ST7789_CMD_NOP             0x00        /**< 无操作命令 */
#define ST7789_CMD_SWRESET         0x01        /**< 软件复位命令 */
#define ST7789_CMD_RDDID           0x04        /**< 读取显示 ID 命令 */
#define ST7789_CMD_RDDST           0x09        /**< 读取显示状态命令 */
#define ST7789_CMD_RDDPM           0x0A        /**< 读取显示电源模式命令 */
#define ST7789_CMD_RDDMADCTL       0x0B        /**< 读取显示内存数据访问控制命令 */
#define ST7789_CMD_RDDCOLMOD       0x0C        /**< 读取显示像素格式命令 */
#define ST7789_CMD_RDDIM           0x0D        /**< 读取显示图像模式命令 */
#define ST7789_CMD_RDDSM           0x0E        /**< 读取显示信号模式命令 */
#define ST7789_CMD_RDDSDR          0x0F        /**< 读取显示自诊断结果命令 */
#define ST7789_CMD_SLPIN           0x10        /**< 进入睡眠模式命令 */
#define ST7789_CMD_SLPOUT          0x11        /**< 退出睡眠模式命令 */
#define ST7789_CMD_PTLON           0x12        /**< 部分模式开启命令 */
#define ST7789_CMD_NORON           0x13        /**< 正常显示模式开启命令 */
#define ST7789_CMD_INVOFF          0x20        /**< 显示反转关闭命令 */
#define ST7789_CMD_INVON           0x21        /**< 显示反转开启命令 */
#define ST7789_CMD_GAMSET          0x26        /**< 伽马设置命令 */
#define ST7789_CMD_DISPOFF         0x28        /**< 显示关闭命令 */
#define ST7789_CMD_DISPON          0x29        /**< 显示开启命令 */
#define ST7789_CMD_CASET           0x2A        /**< 列地址设置命令 */
#define ST7789_CMD_RASET           0x2B        /**< 行地址设置命令 */
#define ST7789_CMD_RAMWR           0x2C        /**< 内存写入命令 */
#define ST7789_CMD_RAMRD           0x2E        /**< 内存读取命令 */
#define ST7789_CMD_PTLAR           0x30        /**< 部分区域设置命令 */
#define ST7789_CMD_VSCRDEF         0x33        /**< 垂直滚动定义命令 */
#define ST7789_CMD_TEOFF           0x34        /**< 撕裂效应线关闭命令 */
#define ST7789_CMD_TEON            0x35        /**< 撕裂效应线开启命令 */
#define ST7789_CMD_MADCTL          0x36        /**< 内存数据访问控制命令 */
#define ST7789_CMD_VSCSAD          0x37        /**< 垂直滚动 RAM 起始地址命令 */
#define ST7789_CMD_IDMOFF          0x38        /**< 空闲模式关闭命令 */
#define ST7789_CMD_IDMON           0x39        /**< 空闲模式开启命令 */
#define ST7789_CMD_COLMOD          0x3A        /**< 接口像素格式命令 */
#define ST7789_CMD_WRMEMC          0x3C        /**< 继续写入内存命令 */
#define ST7789_CMD_RDMEMC          0x3E        /**< 继续读取内存命令 */
#define ST7789_CMD_TESCAN          0x44        /**< 设置撕裂扫描线命令 */
#define ST7789_CMD_GSCAN           0x45        /**< 获取扫描线命令 */
#define ST7789_CMD_WRDISBV         0x51        /**< 写入显示亮度命令 */
#define ST7789_CMD_RDDISBV         0x52        /**< 读取显示亮度值命令 */
#define ST7789_CMD_WRCTRLD         0x53        /**< 写入显示控制命令 */
#define ST7789_CMD_RDCTRLD         0x54        /**< 读取显示控制值命令 */
#define ST7789_CMD_WRCACE          0x55        /**< 写入内容自适应亮度控制和颜色增强命令 */
#define ST7789_CMD_RDCABC          0x56        /**< 读取内容自适应亮度控制命令 */
#define ST7789_CMD_WRCABCMB        0x5E        /**< 写入 CABC 最小亮度命令 */
#define ST7789_CMD_RDCABCMB        0x5F        /**< 读取 CABC 最小亮度命令 */
#define ST7789_CMD_RDABCSDR        0x68        /**< 读取自动亮度控制自诊断结果命令 */
#define ST7789_CMD_RAMCTRL         0xB0        /**< 内存控制命令 */
#define ST7789_CMD_RGBCTRL         0xB1        /**< RGB 控制命令 */
#define ST7789_CMD_PORCTRL         0xB2        /**< 前沿控制命令 */
#define ST7789_CMD_FRCTRL1         0xB3        /**< 帧率控制 1 命令 */
#define ST7789_CMD_PARCTRL         0xB5        /**< 部分模式控制命令 */
#define ST7789_CMD_GCTRL           0xB7        /**< 门控控制命令 */
#define ST7789_CMD_GTADJ           0xB8        /**< 门开启时间调整命令 */
#define ST7789_CMD_DGMEN           0xBA        /**< 数字伽马启用命令 */
#define ST7789_CMD_VCOMS           0xBB        /**< VCOM 设置命令 */
#define ST7789_CMD_LCMCTRL         0xC0        /**< LCM 控制命令 */
#define ST7789_CMD_IDSET           0xC1        /**< ID 设置命令 */
#define ST7789_CMD_VDVVRHEN        0xC2        /**< VDV 和 VRH 命令启用命令 */
#define ST7789_CMD_VRHS            0xC3        /**< VRH 设置命令 */
#define ST7789_CMD_VDVSET          0xC4        /**< VDV 设置命令 */
#define ST7789_CMD_VCMOFSET        0xC5        /**< VCOM 偏移设置命令 */
#define ST7789_CMD_FRCTR2          0xC6        /**< 帧率控制 2 命令 */
#define ST7789_CMD_CABCCTRL        0xC7        /**< CABC 控制命令 */
#define ST7789_CMD_REGSEL1         0xC8        /**< 寄存器值选择 1 命令 */
#define ST7789_CMD_REGSEL2         0xCA        /**< 寄存器值选择 2 命令 */
#define ST7789_CMD_PWMFRSEL        0xCC        /**< PWM 频率选择命令 */
#define ST7789_CMD_PWCTRL1         0xD0        /**< 电源控制 1 命令 */
#define ST7789_CMD_VAPVANEN        0xD2        /**< 启用 VAP/VAN 信号输出命令 */
#define ST7789_CMD_CMD2EN          0xDF        /**< 命令 2 启用命令 */
#define ST7789_CMD_PVGAMCTRL       0xE0        /**< 正电压伽马控制命令 */
#define ST7789_CMD_NVGAMCTRL       0xE1        /**< 负电压伽马控制命令 */
#define ST7789_CMD_DGMLUTR         0xE2        /**< 红色数字伽马查找表命令 */
#define ST7789_CMD_DGMLUTB         0xE3        /**< 蓝色数字伽马查找表命令 */
#define ST7789_CMD_GATECTRL        0xE4        /**< 门控控制命令 */
#define ST7789_CMD_SPI2EN          0xE7        /**< SPI2 命令 */
#define ST7789_CMD_PWCTRL2         0xE8        /**< 电源控制 2 命令 */
#define ST7789_CMD_EQCTRL          0xE9        /**< 均衡时间控制命令 */
#define ST7789_CMD_PROMCTRL        0xEC        /**< 编程控制命令 */
#define ST7789_CMD_PROMEN          0xFA        /**< 编程模式启用命令 */
#define ST7789_CMD_NVMSET          0xFC        /**< NVM 设置命令 */
#define ST7789_CMD_PROMACT         0xFE        /**< 编程操作命令 */
#define ST7789_CMD_RDID1           0xDA        /**< 读取 ID1 命令 */
#define ST7789_CMD_RDID2           0xDB        /**< 读取 ID2 命令 */
#define ST7789_CMD_RDID3           0xDC        /**< 读取 ID3 命令 */



/**
 * @brief     空指令
 * @param[in] *handle pointer to an st7789 handle structure
 * @return    none
 * */
void st7789_nop(st7789_handle_t* handle)
{
    handle->write_cmd(ST7789_CMD_NOP);
}

/**
 * @brief     软件复位
 * @param[in] *handle pointer to an st7789 handle structure
 * @return    none
 * */
void st7789_software_reset(st7789_handle_t* handle)
{
    handle->write_cmd(ST7789_CMD_SWRESET);
    handle->delay_ms(5);                                                       /* delay 5ms */
}

/**
 * @brief     读取ID
 * @param[in] *handle pointer to an st7789 handle structure
 * @return    id
 * */
uint32_t st7789_read_id(st7789_handle_t* handle)
{
    uint8_t id[3];                                                             /* id buffer */
    handle->write_cmd(ST7789_CMD_RDDID);                                        /* read ID command */
    handle->read_byte();                                                       /* read dummy byte */
    handle->read_bytes(id, 3);                                                 /* read id data */
    return ((uint32_t)id[0] << 16) | ((uint32_t)id[1] << 8) | (uint32_t)id[2];  /* return id */
}

/**
 * @brief     读取显示状态
 * @param[in] *handle pointer to an st7789 handle structure
 * @return    status
 * */
void st7789_read_display_status(st7789_handle_t* handle, uint8_t status[4])
{
    handle->write_cmd(ST7789_CMD_RDDST);                                        /* read display status command */
    handle->read_byte();                                                       /* read dummy byte */
    handle->read_bytes(status, 4);                                             /* read status data */
}

/**
 * @brief     读取显示电源模式
 * @param[in] *handle pointer to an st7789 handle structure
 * @return    power mode
 * */
uint8_t st7789_read_display_power_mode(st7789_handle_t* handle)
{
    handle->write_cmd(ST7789_CMD_RDDPM);                                        /* read display power mode command */
    handle->read_byte();                                                       /* read dummy byte */
    return handle->read_byte();                                                /* read power mode data */
}
/**
 * @brief     读取显示内存数据访问控制
 * @param[in] *handle pointer to an st7789 handle structure
 * @return    memory data access control
 * */
uint8_t st7789_read_display_memory_data_access_control(st7789_handle_t* handle)
{
    handle->write_cmd(ST7789_CMD_RDDMADCTL);                                    /* read display memory data access control command */
    handle->read_byte();                                                       /* read dummy byte */
    return handle->read_byte();                                                /* read memory data access control data */
}

/**
 * @brief     读取显示像素格式
 * @param[in] *handle pointer to an st7789 handle structure
 * @return    pixel format
 * */
uint8_t st7789_read_display_pixel_format(st7789_handle_t* handle)
{
    handle->write_cmd(ST7789_CMD_RDDCOLMOD);                                    /* read display pixel format command */
    handle->read_byte();                                                       /* read dummy byte */
    return handle->read_byte();                                                /* read pixel format data */
}
/**
 * @brief     读取显示图像模式
 * @param[in] *handle pointer to an st7789 handle structure
 * @return    image mode
 * */
uint8_t st7789_read_display_image_mode(st7789_handle_t* handle)
{
    handle->write_cmd(ST7789_CMD_RDDIM);                                        /* read display image mode command */
    handle->read_byte();                                                       /* read dummy byte */
    return handle->read_byte();                                                /* read image mode data */
}
/**
 * @brief     读取显示信号模式
 * @param[in] *handle pointer to an st7789 handle structure
 * @return    signal mode
 * */
uint8_t st7789_read_display_signal_mode(st7789_handle_t* handle)
{
    handle->write_cmd(ST7789_CMD_RDDSM);                                        /* read display signal mode command */
    handle->read_byte();                                                       /* read dummy byte */
    return handle->read_byte();                                                /* read signal mode data */
}
/**
 * @brief     读取显示自诊断结果
 * @param[in] *handle pointer to an st7789 handle structure
 * @return    self diagnostic result
 * */
uint8_t st7789_read_display_self_diagnostic_result(st7789_handle_t* handle)
{
    handle->write_cmd(ST7789_CMD_RDDSDR);                                        /* read display self diagnostic result command */
    handle->read_byte();                                                       /* read dummy byte */
    return handle->read_byte();                                                /* read self diagnostic result data */
}

/**
 * @brief     进入睡眠模式
 * @param[in] *handle pointer to an st7789 handle structure
 * @return    none
 * */
void st7789_enter_sleep_mode(st7789_handle_t* handle)
{
    handle->write_cmd(ST7789_CMD_SLPIN);                                        /* enter sleep mode command */
    handle->delay_ms(5);
}

/**
 * @brief     退出睡眠模式
 * @param[in] *handle pointer to an st7789 handle structure
 * @return    none
 * */
void st7789_exit_sleep_mode(st7789_handle_t* handle)
{
    handle->write_cmd(ST7789_CMD_SLPOUT);                                       /* exit sleep mode command */
    handle->delay_ms(120);                                                     /* delay 5ms */
}

/**
 * @brief     部分显示模式
 * @param[in] *handle pointer to an st7789 handle structure
 * @return    none
 * */
void st7789_partial_display_mode_on(st7789_handle_t* handle)
{
    handle->write_cmd(ST7789_CMD_PTLON);
}

/**
 * @brief     正常显示模式
 * @param[in] *handle pointer to an st7789 handle structure
 * @return    none
 * */
void st7789_normal_display_mode_on(st7789_handle_t* handle)
{
    handle->write_cmd(ST7789_CMD_NORON);
}

/**
 * @brief     设置显示反转
 * @param[in] *handle pointer to an st7789 handle structure
 * @return    none
 * */
void st7789_display_inversion_on(st7789_handle_t* handle)
{
    handle->write_cmd(ST7789_CMD_INVON);
}

/**
 * @brief     关闭显示反转
 * @param[in] *handle pointer to an st7789 handle structure
 * @return    none
 * */
void st7789_display_inversion_off(st7789_handle_t* handle)
{
    handle->write_cmd(ST7789_CMD_INVOFF);
}

/**
 * @brief     设置伽马曲线
 * @param[in] *handle pointer to an st7789 handle structure
 * @param[in] gamma set gamma
 * @return    none
 * */
void st7789_set_gamma(st7789_handle_t* handle, uint8_t gamma)
{
    handle->write_cmd(ST7789_CMD_GAMSET);                /* set gamma command */
    handle->write_byte(gamma & 0x0F);                    /* write gamma data */
}

/**
 * @brief     关闭显示
 * @param[in] *handle pointer to an st7789 handle structure
 * @return    none
 * */
void st7789_display_off(st7789_handle_t* handle)
{
    handle->write_cmd(ST7789_CMD_DISPOFF);                /* display off command */
}

/**
 * @brief     打开显示
 * @param[in] *handle pointer to an st7789 handle structure
 * @return    none
 * */
void st7789_display_on(st7789_handle_t* handle)
{
    handle->write_cmd(ST7789_CMD_DISPON);                /* display on command */
}

/**
 * @brief     设置列地址 X
 * @param[in] *handle pointer to an st7789 handle structure
 * @param[in] start_address start address
 * @param[in] end_address end address
 * @return    none
 * */
void st7789_set_column_address(st7789_handle_t* handle, uint16_t start_address, uint16_t end_address)
{
    handle->write_cmd(ST7789_CMD_CASET);                                        /* set column address command */
    handle->write_byte((start_address >> 8) & 0xFF);                              /* write data */
    handle->write_byte((start_address >> 0) & 0xFF);                              /* write data */
    handle->write_byte((end_address >> 8) & 0xFF);                              /* write data */
    handle->write_byte((end_address >> 0) & 0xFF);                              /* write data */
}

/**
 * @brief     设置行地址 Y
 * @param[in] *handle pointer to an st7789 handle structure
 * @param[in] start_address start address
 * @param[in] end_address end address
 * @return    none
 * */
void st7789_set_row_address(st7789_handle_t* handle, uint16_t start_address, uint16_t end_address)
{
    handle->write_cmd(ST7789_CMD_RASET);                                        /* set row address command */
    handle->write_byte((start_address >> 8) & 0xFF);                              /* write data */
    handle->write_byte((start_address >> 0) & 0xFF);                              /* write data */
    handle->write_byte((end_address >> 8) & 0xFF);                              /* write data */
    handle->write_byte((end_address >> 0) & 0xFF);                              /* write data */
}

/**
 * @brief     内存写入
 * @param[in] *handle pointer to an st7789 handle structure
 * @param[in] *data pointer to a data buffer
 * @param[in] len data length
 * @return    none
 * */
void st7789_memory_write(st7789_handle_t* handle, uint8_t* data, uint16_t len)
{
    handle->write_cmd(ST7789_CMD_RAMWR);                     /* memory write command */
    handle->write_bytes(data, len);                           /* write data */
}

/**
 * @brief     内存读取
 * @param[in] *handle pointer to an st7789 handle structure
 * @param[in] *data pointer to a data buffer
 * @param[in] len data length
 * @return    none
 * */
void st7789_memory_read(st7789_handle_t* handle, uint8_t* data, uint16_t len)
{
    handle->write_cmd(ST7789_CMD_RAMRD);                     /* memory read command */
    handle->read_bytes(data, len);                            /* read data */
}

/**
 * @brief     设置部分显示区域
 * @param[in] *handle pointer to an st7789 handle structure
 * @param[in] start_row start row
 * @param[in] end_row end row
 * @return    none
 * */
void st7789_set_partial_areas(st7789_handle_t* handle, uint16_t start_row, uint16_t end_row)
{
    handle->write_cmd(ST7789_CMD_PTLAR);                    /* set partial areas command */
    handle->write_byte((start_row >> 8) & 0xFF);
    handle->write_byte((start_row >> 0) & 0xFF);
    handle->write_byte((end_row >> 8) & 0xFF);
    handle->write_byte((end_row >> 0) & 0xFF);
}

/**
 * @brief     设置垂直滚动
 * @param[in] *handle pointer to an st7789 handle structure
 * @param[in] top_fixed_area 顶部固定区域
 * @param[in] scrolling_area 滚动区域
 * @param[in] bottom_fixed_area 底部固定区域
 * @return    none
 * */
void st7789_set_vertical_scrolling(st7789_handle_t* handle, uint16_t top_fixed_area, uint16_t scrolling_area, uint16_t bottom_fixed_area)
{
    handle->write_cmd(ST7789_CMD_VSCRDEF);
    handle->write_byte((top_fixed_area >> 8) & 0xFF);
    handle->write_byte((top_fixed_area >> 0) & 0xFF);
    handle->write_byte((scrolling_area >> 8) & 0xFF);
    handle->write_byte((scrolling_area >> 0) & 0xFF);
    handle->write_byte((bottom_fixed_area >> 8) & 0xFF);
    handle->write_byte((bottom_fixed_area >> 0) & 0xFF);
}

/**
 * @brief     关闭 tearing effect line
 * @param[in] *handle pointer to an st7789 handle structure
 * @return    none
 * */
void st7789_tearing_effect_line_off(st7789_handle_t* handle)
{
    handle->write_cmd(ST7789_CMD_TEOFF);                     /* tearing effect line off command */
}

/**
 * @brief     打开 tearing effect line
 * @param[in] *handle pointer to an st7789 handle structure
 * @param[in] effect effect
 * @return    none
 * */
void st7789_tearing_effect_line_on(st7789_handle_t* handle, uint8_t effect)
{
    handle->write_cmd(ST7789_CMD_TEON);                      /* tearing effect line on command */
    handle->write_byte(effect);                               /* write data */
}



/**
 * @brief     设置内存数据访问控制
 * @param[in] *handle pointer to an st7789 handle structure
 * @param[in] order order
 * @return    none
 * */
void st7789_set_memory_data_access_control(st7789_handle_t* handle, uint8_t order)
{
    handle->write_cmd(ST7789_CMD_MADCTL);  // 发送内存数据访问控制命令
    handle->write_byte(order);             // 发送设置参数
}


/**
 * @brief     设置垂直滚动起始地址
 * @param[in] *handle pointer to an st7789 handle structure
 * @param[in] address address
 * @return    none
 * */
void st7789_set_vertical_scrolling_start_address(st7789_handle_t* handle, uint16_t address)
{
    handle->write_cmd(ST7789_CMD_VSCSAD);                   /* set vertical scrolling start address command */
    handle->write_byte((address >> 8) & 0xFF);
    handle->write_byte((address >> 0) & 0xFF);
}

/**
 * @brief     关闭空闲模式
 * @param[in] *handle pointer to an st7789 handle structure
 * @return    none
 * */
void st7789_idle_mode_off(st7789_handle_t* handle)
{
    handle->write_cmd(ST7789_CMD_IDMOFF);                    /* idle mode off command */
    handle->delay_ms(5);
}

/**
 * @brief     开启空闲模式
 * @param[in] *handle pointer to an st7789 handle structure
 * @return    none
 * */
void st7789_idle_mode_on(st7789_handle_t* handle)
{
    handle->write_cmd(ST7789_CMD_IDMON);                     /* idle mode on command */
    handle->delay_ms(5);
}

/**
 * @brief     设置接口像素格式
 * @param[in] *handle pointer to an st7789 handle structure
 * @param[in] rgb rgb interface color format
 * @param[in] control control interface color format
 * @return    none
 * */
void st7789_set_interface_pixel_format(st7789_handle_t* handle, st7789_rgb_interface_color_format_t rgb, st7789_control_interface_color_format_t control)
{
    handle->write_cmd(ST7789_CMD_COLMOD);                    /* set interface pixel format command */
    handle->write_byte((rgb << 4) | (control << 0));          /* write data */
}


/**
 * @brief     内存连续写入
 * @param[in] *handle pointer to an st7789 handle structure
 * @param[in] *data pointer to a data buffer
 * @param[in] len data length
 * @return    none
 * */
void st7789_memory_continue_write(st7789_handle_t* handle, uint8_t* data, uint16_t len)
{
    handle->write_cmd(ST7789_CMD_WRMEMC);                     /* write memory continue command */
    handle->write_bytes(data, len);                           /* write data */
}

/**
 * @brief     内存连续读取
 * @param[in] *handle pointer to an st7789 handle structure
 * @param[in] *data pointer to a data buffer
 * @param[in] len data length
 * @return    none
 * */
void st7789_memory_continue_read(st7789_handle_t* handle, uint8_t* data, uint16_t len)
{
    handle->write_cmd(ST7789_CMD_RDMEMC);                     /* read memory continue command */
    handle->read_bytes(data, len);                            /* read data */
}



/**
 * @brief     设置撕裂扫描线
 * @param[in] *handle pointer to an st7789 handle structure
 * @param[in] l tear line
 * @return    none
 * */
void st7789_set_tear_scanline(st7789_handle_t* handle, uint16_t l)
{
    handle->write_cmd(ST7789_CMD_TESCAN);                    /* set tear scanline command */
    handle->write_byte((l >> 8) & 0xFF);
    handle->write_byte((l >> 0) & 0xFF);
}

/**
 * @brief     获取扫描线
 * @param[in] *handle pointer to an st7789 handle structure
 * @return    scan line
 * */
uint8_t st7789_get_scanline(st7789_handle_t* handle)
{
    uint8_t data;                                             /* data buffer */
    handle->write_cmd(ST7789_CMD_GSCAN);                      /* get scan line command */
    handle->read_byte();                                      /* read dummy byte */
    data = handle->read_byte();                               /* read scan line data */
    return data;                                              /* return scan line */
}

/**
 * @brief     设置显示亮度
 * @param[in] *handle pointer to an st7789 handle structure
 * @param[in] brightness display brightness
 * @return    none
 */
void st7789_set_display_brightness(st7789_handle_t* handle, uint8_t brightness)
{
    handle->write_cmd(ST7789_CMD_WRDISBV);                    /* set display brightness command */
    handle->write_byte(brightness);                           /* write brightness data */
}
/**
 * @brief     读取显示亮度
 * @param[in] *handle pointer to an st7789 handle structure
 * @return    display brightness
 * */
uint8_t st7789_read_display_brightness(st7789_handle_t* handle)
{
    uint8_t data;                                             /* data buffer */
    handle->write_cmd(ST7789_CMD_RDDISBV);                    /* read display brightness command */
    handle->read_byte();                                      /* read dummy byte */
    data = handle->read_byte();                               /* read brightness data */
    return data;                                              /* return brightness */
}

/**
 * @brief     set display control
 * @param[in] *handle pointer to an st7789 handle structure
 * @param[in] brightness_control_block bool value
 * @param[in] display_dimming bool value
 * @param[in] backlight_control bool value
 * @return    none
 */
void st7789_set_display_control(st7789_handle_t* handle, st7789_bool_t brightness_control_block,
                                st7789_bool_t display_dimming, st7789_bool_t backlight_control)
{
    uint8_t data;                                                 /* data buffer */
    handle->write_cmd(ST7789_CMD_WRCTRLD);                       /* set display control command */
    data = (brightness_control_block << 7) | (display_dimming << 6) |
           (backlight_control << 5);                              /* set control data */
    handle->write_byte(data);                                    /* write data */
}

/**
 * @brief     read display control
 * @param[in] *handle pointer to an st7789 handle structure
 * @return    display control
 * */
uint8_t st7789_read_display_control(st7789_handle_t* handle)
{
    uint8_t data;                                                 /* data buffer */
    handle->write_cmd(ST7789_CMD_RDCTRLD);                       /* read display control command */
    handle->read_byte();                                          /* read dummy byte */
    data = handle->read_byte();                                   /* read display control data */
    return data;                                                  /* return display control */
}

/**
 * @brief     set brightness control and color enhancement
 * @param[in] *handle pointer to an st7789 handle structure
 * @param[in] color_enhancement bool value
 * @param[in] mode color enhancement mode
 * @param[in] level color enhancement level
 * @return    none
 * @note      none
 */
void st7789_set_brightness_control_and_color_enhancement(st7789_handle_t* handle, st7789_bool_t color_enhancement,
        st7789_color_enhancement_mode_t mode, st7789_color_enhancement_level_t level)
{
    uint8_t data;                                                 /* data buffer */
    handle->write_cmd(ST7789_CMD_WRCACE);                         /* set brightness control and color enhancement command */
    data = (color_enhancement << 7) | (mode << 4) | (level << 0); /* set control data */
    handle->write_byte(data);                                      /* write data */
}

/**
 * @brief     set cabc minimum brightness
 * @param[in] *handle pointer to an st7789 handle structure
 * @param[in] brightness display brightness
 * @return    none
 * @note      none
 */
void st7789_set_cabc_minimum_brightness(st7789_handle_t* handle, uint8_t brightness)
{
    handle->write_cmd(ST7789_CMD_WRCABCMB);                     /* set cabc minimum brightness command */
    handle->write_byte(brightness);                               /* write brightness data */
}

/**
 * @brief     set ram control
 * @param[in] *handle pointer to an st7789 handle structure
 * @param[in] ram_mode ram mode
 * @param[in] display_mode display mode
 * @param[in] frame_type frame type
 * @param[in] data_mode data mode
 * @param[in] bus_width bus width
 * @param[in] pixel_type pixel type
 * @return    none
 * @note      none
 */
void st7789_set_ram_control(st7789_handle_t* handle,
                            st7789_ram_access_t ram_mode,
                            st7789_display_mode_t display_mode,
                            st7789_frame_type_t frame_type,
                            st7789_data_mode_t data_mode,
                            st7789_rgb_bus_width_t bus_width,
                            st7789_pixel_type_t pixel_type)
{
    uint8_t buf[2];                                          /* data buffer */
    handle->write_cmd(ST7789_CMD_RAMCTRL);                     /* set ram control command */
    buf[0] = (ram_mode << 4) | (display_mode << 0);           /* set param1 */
    buf[1] = (frame_type << 4) | (data_mode << 3) |
             (bus_width << 2) | (pixel_type << 0);            /* set param2 */
    handle->write_bytes(buf, 2);                               /* write data */
}

/**
 * @brief     set rgb interface control
 * @param[in] *handle pointer to an st7789 handle structure
 * @param[in] rgb_mode rgb mode
 * @param[in] rgb_if_mode rgb if enable mode
 * @param[in] vspl vspl active level
 * @param[in] hspl hspl active level
 * @param[in] dpl dpl active level
 * @param[in] epl epl active level
 * @param[in] vbp rgb interface vsync back porch setting
 * @param[in] hbp rgb interface hsync back porch setting
 * @return    none
 * @note      0x02 <= vbp <= 0x7F
 *            0x02 <= hbp <= 0x1F
 */
void st7789_set_rgb_interface_control(st7789_handle_t* handle,
                                      st7789_direct_rgb_mode_t rgb_mode,
                                      st7789_rgb_if_enable_mode_t rgb_if_mode,
                                      st7789_pin_level_t vspl,
                                      st7789_pin_level_t hspl,
                                      st7789_pin_level_t dpl,
                                      st7789_pin_level_t epl,
                                      uint8_t vbp,
                                      uint8_t hbp)
{
    uint8_t buf[3];
    handle->write_cmd(ST7789_CMD_RGBCTRL);                     /* set rgb interface control command */
    buf[0] = (rgb_mode << 7) | (rgb_if_mode << 5) |
             (vspl << 3) | (hspl << 2) | (dpl << 1) | (epl << 0); /* set param1 */
    buf[1] = vbp & 0x7F;                                        /* set param2 */
    buf[2] = hbp & 0x1F;                                        /* set param3 */
    handle->write_bytes(buf, 3);                               /* write data */
}

/**
 * @brief     set porch
 * @param[in] *handle pointer to an st7789 handle structure
 * @param[in] back_porch_normal back porch setting in normal mode
 * @param[in] front_porch_normal front porch setting in normal mode
 * @param[in] separate_porch_enable bool value
 * @param[in] back_porch_idle back porch setting in idle mode
 * @param[in] front_porch_idle front porch setting in idle mode
 * @param[in] back_porch_partial back porch setting in partial mode
 * @param[in] front_porch_partial front porch setting in partial mode
 * @return    none
 * @note      0x01 <= back_porch_normal <= 0x7F
 *            0x01 <= front_porch_normal <= 0x7F
 *            0x01 <= back_porch_idle <= 0xF
 *            0x01 <= front_porch_idle <= 0xF
 *            0x01 <= back_porch_partial <= 0xF
 *            0x01 <= front_porch_partial <= 0xF
 */
void st7789_set_porch(st7789_handle_t* handle,
                      uint8_t back_porch_normal,
                      uint8_t front_porch_normal,
                      st7789_bool_t separate_porch_enable,
                      uint8_t back_porch_idle,
                      uint8_t front_porch_idle,
                      uint8_t back_porch_partial,
                      uint8_t front_porch_partial)
{
    uint8_t buf[5];
    handle->write_cmd(ST7789_CMD_PORCTRL);                     /* set porch command */
    buf[0] = back_porch_normal;                                 /* set param1 */
    buf[1] = front_porch_normal;                                /* set param2 */
    buf[2] = separate_porch_enable;                             /* set param3 */
    buf[3] = (back_porch_idle & 0xF) << 4 | (front_porch_idle & 0xF); /* set param4 */
    buf[4] = (back_porch_partial & 0xF) << 4 | (front_porch_partial & 0xF); /* set param5 */
    handle->write_bytes(buf, 5);                               /* write data */
}

/**
 * @brief     set frame rate control
 * @param[in] *handle pointer to an st7789 handle structure
 * @param[in] separate_fr_control bool value
 * @param[in] div_control frame rate divided control
 * @param[in] idle_mode inversion idle mode
 * @param[in] idle_frame_rate idle frame rate
 * @param[in] partial_mode inversion partial mode
 * @param[in] partial_frame_rate partial frame rate
 * @return    none
 * @note      0 <= idle_frame_rate <= 0x1F
 *            0 <= partial_frame_rate <= 0x1F
 */
void st7789_set_frame_rate_control(st7789_handle_t* handle,
                                   st7789_bool_t separate_fr_control,
                                   st7789_frame_rate_divided_control_t div_control,
                                   st7789_inversion_idle_mode_t idle_mode,
                                   uint8_t idle_frame_rate,
                                   st7789_inversion_partial_mode_t partial_mode,
                                   uint8_t partial_frame_rate)
{
    uint8_t buf[3];
    handle->write_cmd(ST7789_CMD_FRCTRL1);                       /* set frame rate control command */
    buf[0] = (separate_fr_control << 4) | (div_control << 0);   /* set param1 */
    buf[1] = (idle_mode << 5) | ((idle_frame_rate & 0x1F) << 0); /* set param2 */
    buf[2] = (partial_mode << 5) | ((partial_frame_rate & 0x1F) << 0); /* set param3 */
    handle->write_bytes(buf, 3);                                /* write data */
}

/**
 * @brief     set partial mode control
 * @param[in] *handle pointer to an st7789 handle structure
 * @param[in] level non-display source output level
 * @param[in] mode non-display area scan mode
 * @param[in] frequency non-display frame frequency
 * @return    none
 * @note      none
 */
void st7789_set_partial_mode_control(st7789_handle_t* handle,
                                     st7789_non_display_source_output_level_t level,
                                     st7789_non_display_area_scan_mode_t mode,
                                     st7789_non_display_frame_frequency_t frequency)
{
    uint8_t reg;
    handle->write_cmd(ST7789_CMD_PARCTRL);                     /* set partial mode control command */
    reg = (level << 7) | (mode << 4) | (frequency << 0);       /* set param */
    handle->write_byte(reg);                                  /* write data */

}

/**
 * @brief     set gate control
 * @param[in] *handle pointer to an st7789 handle structure
 * @param[in] vghs vghs level
 * @param[in] vgls vgls level
 * @return    none
 * @note      none
 */
void st7789_set_gate_control(st7789_handle_t* handle, st7789_vghs_t vghs, st7789_vgls_t vgls)
{
    uint8_t reg;
    handle->write_cmd(ST7789_CMD_GCTRL);                     /* set gate control command */
    reg = (vghs << 4) | (vgls << 0);                           /* set param */
    handle->write_byte(reg);                                  /* write data */
}

/**
 * @brief     set gate on timing adjustment
 * @param[in] *handle pointer to an st7789 handle structure
 * @param[in] gate_on_timing_adjustment gate on timing adjustment
 * @param[in] gate_off_timing_adjustment_rgb gate off timing adjustment in rgb interface
 * @param[in] gate_off_timing_adjustment gate off timing adjustment
 * @return    none

 * @note      gate_on_timing_adjustment <= 0x3F
 *            gate_off_timing_adjustment_rgb <= 0xF
 *            gate_off_timing_adjustment <= 0xF
 */
void st7789_set_gate_on_timing_adjustment(st7789_handle_t* handle,
        uint8_t gate_on_timing_adjustment,
        uint8_t gate_off_timing_adjustment_rgb,
        uint8_t gate_off_timing_adjustment)
{
    uint8_t buf[4];
    handle->write_cmd(ST7789_CMD_GTADJ);                       /* set gate on timing adjustment command */
    buf[0] = 0x2A;                                              /* set param1 */
    buf[1] = 0x2B;                                              /* set param2 */
    buf[2] = gate_on_timing_adjustment & 0x3F;                  /* set param3 */
    buf[3] = ((gate_off_timing_adjustment_rgb & 0xF) << 4) |
             ((gate_off_timing_adjustment & 0xF) << 0);        /* set param4 */
    handle->write_bytes(buf, 4);                               /* write data */
}


/**
 * @brief     enable or disable digital gamma
 * @param[in] *handle pointer to an st7789 handle structure
 * @param[in] enable bool value
 * @return    none

 * @note      none
 */
void st7789_set_digital_gamma(st7789_handle_t* handle, st7789_bool_t enable)
{
    uint8_t reg;
    handle->write_cmd(ST7789_CMD_DGMEN);                     /* set digital gamma command */
    reg = enable << 2;                                        /* set param */
    handle->write_byte(reg);                                  /* write data */
}

/**
 * @brief     set vcoms
 * @param[in] *handle pointer to an st7789 handle structure
 * @param[in] vcoms set vcoms
 * @return    none

 * @note      0 <= vcoms <= 0x3F
 */
void st7789_set_vcoms(st7789_handle_t* handle, uint8_t vcoms)
{
    uint8_t reg;
    handle->write_cmd(ST7789_CMD_VCOMS);                     /* set vcoms command */
    reg = vcoms & 0x3F;                                        /* set param */
    handle->write_byte(reg);                                  /* write data */
}


/**
 * @brief      convert the vcom to the register raw data
 * @param[in]  *handle pointer to an st7789 handle structure
 * @param[in]  v vcom
 * @param[out] *reg pointer to a register raw buffer
 * @return    none
 * @note       none
 */
void st7789_vcom_convert_to_register(st7789_handle_t* handle, float v, uint8_t* reg)
{
    *reg = (uint8_t)((v - 0.1f) / 0.025f);        /* convert real data to register data */
}

/**
 * @brief      convert the register raw data to the vcom
 * @param[in]  *handle pointer to an st7789 handle structure
 * @param[in]  reg register raw data
 * @param[out] *v pointer to a vcom buffer
 * @return    none

 * @note       none
 */
void st7789_vcom_convert_to_data(st7789_handle_t* handle, uint8_t reg, float* v)
{
    *v = (uint8_t)((float)(reg) * 0.025f + 0.1f);        /* convert raw data to real data */
}

/**
 * @brief     set lcm control
 * @param[in] *handle pointer to an st7789 handle structure
 * @param[in] xmy bool value
 * @param[in] xbgr bool value
 * @param[in] xinv bool value
 * @param[in] xmx bool value
 * @param[in] xmh bool value
 * @param[in] xmv bool value
 * @param[in] xgs bool value
 * @return    none

 * @note      none
 */
void st7789_set_lcm_control(st7789_handle_t* handle,
                            st7789_bool_t xmy,
                            st7789_bool_t xbgr,
                            st7789_bool_t xinv,
                            st7789_bool_t xmx,
                            st7789_bool_t xmh,
                            st7789_bool_t xmv,
                            st7789_bool_t xgs)
{
    uint8_t reg;
    handle->write_cmd(ST7789_CMD_LCMCTRL);                     /* set lcm control command */
    reg = (xmy << 6) | (xbgr << 5) | (xinv << 4) | (xmx << 3) |
          (xmh << 2) | (xmv << 1) | (xgs << 0);                   /* set param */
    handle->write_byte(reg);                                    /* write data */
}


/**
 * @brief     set id code setting
 * @param[in] *handle pointer to an st7789 handle structure
 * @param[in] *id pointer to an id buffer
 * @return    none
 * @note      none
 */
void st7789_set_id_code_setting(st7789_handle_t* handle, uint8_t id[3])
{
    handle->write_cmd(ST7789_CMD_IDSET);                     /* set id code setting command */
    handle->write_byte(id[0]);                                /* write data */
    handle->write_byte(id[1]);                                /* write data */
    handle->write_byte(id[2]);                                /* write data */
}

/**
 * @brief     set vdv vrh from
 * @param[in] *handle pointer to an st7789 handle structure
 * @param[in] from vdv and vrh from
 * @return    none
 * @note      none
 */
void st7789_set_vdv_vrh_from(st7789_handle_t* handle, st7789_vdv_vrh_from_t from)
{
    handle->write_cmd(ST7789_CMD_VDVVRHEN);                    /* set vdv and vrh from command */
    handle->write_byte(from);
    handle->write_byte(0xff);
}

/**
 * @brief     set vrhs
 * @param[in] *handle pointer to an st7789 handle structure
 * @param[in] vrhs set vrhs
 * @return    none
 * @note      none
 */
void st7789_set_vrhs(st7789_handle_t* handle, uint8_t vrhs)
{
    uint8_t reg;
    handle->write_cmd(ST7789_CMD_VRHS);                       /* set vrh command */
    reg = vrhs & 0x3F;                                        /* set param */
    handle->write_byte(reg);                                  /* write data */
}

/**
 * @brief      convert the vrhs to the register raw data
 * @param[in]  *handle pointer to an st7789 handle structure
 * @param[in]  v vcom
 * @param[out] *reg pointer to a register raw buffer
 * @return    none
 * @note      none
 */
void st7789_vrhs_convert_to_register(st7789_handle_t* handle, float v, uint8_t* reg)
{
    *reg = (uint8_t)((v - 3.55f) / 0.05f);        /* convert real data to register data */
}

/**
 * @brief      convert the register raw data to the vrhs
 * @param[in]  *handle pointer to an st7789 handle structure
 * @param[in]  reg register raw data
 * @param[out] *v pointer to a vcom buffer
 * @return    none
 * @note      none
 */
void st7789_vrhs_convert_to_data(st7789_handle_t* handle, uint8_t reg, float* v)
{
    *v = (uint8_t)((float)(reg) * 0.05f + 3.55f);        /* convert raw data to real data */
}

/**
 * @brief     set vdv
 * @param[in] *handle pointer to an st7789 handle structure
 * @param[in] vdv set vdv
 * @return    none
 * @note      none
 */
void st7789_set_vdv(st7789_handle_t* handle, uint8_t vdv)
{
    uint8_t reg;
    handle->write_cmd(ST7789_CMD_VDVSET);                     /* set vdv command */
    reg = vdv & 0x3F;                                          /* set param */
    handle->write_byte(reg);                                  /* write data */
}

/**
 * @brief      convert the vdv to the register raw data
 * @param[in]  *handle pointer to an st7789 handle structure
 * @param[in]  v vcom
 * @param[out] *reg pointer to a register raw buffer
 * @return    none
 * @note      none
 */
void st7789_vdv_convert_to_register(st7789_handle_t* handle, float v, uint8_t* reg)
{
    *reg = (uint8_t)((v + 0.8f) / 0.025f);        /* convert real data to register data */
}

/**
 * @brief      convert the register raw data to the vdv
 * @param[in]  *handle pointer to an st7789 handle structure
 * @param[in]  reg register raw data
 * @param[out] *v pointer to a vcom buffer
 * @return    none
 * @note      none
 */
void st7789_vdv_convert_to_data(st7789_handle_t* handle, uint8_t reg, float* v)
{
    *v = (uint8_t)((float)(reg) * 0.025f - 0.8f);        /* convert raw data to real data */
}

/**
 * @brief     set vcoms offset
 * @param[in] *handle pointer to an st7789 handle structure
 * @param[in] offset vcoms offset
 * @return    none
 * @note      none
 */
void st7789_set_vcoms_offset(st7789_handle_t* handle, uint8_t offset)
{
    uint8_t reg;
    handle->write_cmd(ST7789_CMD_VCMOFSET);                     /* set vcoms offset command */
    reg = offset & 0x3F;                                        /* set param */
    handle->write_byte(reg);                                  /* write data */
}


/**
 * @brief      convert the vcoms offset to the register raw data
 * @param[in]  *handle pointer to an st7789 handle structure
 * @param[in]  v vcoms offset
 * @param[out] *reg pointer to a register raw buffer
 * @return    none
 * @note      none
 */
void st7789_vcoms_offset_convert_to_register(st7789_handle_t* handle, float v, uint8_t* reg)
{
    *reg = (uint8_t)((v + 0.8f) / 0.025f);        /* convert real data to register data */
}

/**
 * @brief      convert the register raw data to the vcoms offset
 * @param[in]  *handle pointer to an st7789 handle structure
 * @param[in]  reg register raw data
 * @param[out] *v pointer to a vcoms offset buffer
 * @return    none
 * @note      none
 */
void st7789_vcoms_offset_convert_to_data(st7789_handle_t* handle, uint8_t reg, float* v)
{
    *v = (uint8_t)((float)(reg) * 0.025f - 0.8f);        /* convert raw data to real data */
}

/**
 * @brief     set frame rate
 * @param[in] *handle pointer to an st7789 handle structure
 * @param[in] selection inversion selection
 * @param[in] rate frame rate
 * @return    none
 * @note      none
 */
void st7789_set_frame_rate(st7789_handle_t* handle, st7789_inversion_selection_t selection, st7789_frame_rate_t rate)
{
    uint8_t reg;
    handle->write_cmd(ST7789_CMD_FRCTR2);                     /* set frame rate command */
    reg = (selection << 5) | (rate << 0);                       /* set param */
    handle->write_byte(reg);                                  /* write data */
}

/**
 * @brief     set cabc control
 * @param[in] *handle pointer to an st7789 handle structure
 * @param[in] led_on bool value
 * @param[in] led_pwm_init bool value
 * @param[in] led_pwm_fix bool value
 * @param[in] led_pwm_polarity bool value
 * @return    none
 * @note      none
 */
void st7789_set_cabc_control(st7789_handle_t* handle,
                             st7789_bool_t led_on,
                             st7789_bool_t led_pwm_init,
                             st7789_bool_t led_pwm_fix,
                             st7789_bool_t led_pwm_polarity)
{
    uint8_t reg;
    handle->write_cmd(ST7789_CMD_CABCCTRL);                     /* set cabc control command */
    reg = (led_on << 3) | (led_pwm_init << 2) |
          (led_pwm_fix << 1) | (led_pwm_polarity << 0);           /* set param */
    handle->write_byte(reg);                                  /* write data */
}

/**
 * @brief     set pwm frequency
 * @param[in] *handle pointer to an st7789 handle structure
 * @param[in] frequency pwm frequency
 * @return    none
 * @note      none
 */
void st7789_set_pwm_frequency(st7789_handle_t* handle, st7789_pwm_frequency_t frequency)
{
    uint8_t reg;
    handle->write_cmd(ST7789_CMD_PWMFRSEL);                     /* set pwm frequency command */
    reg = frequency;                                          /* set param */
    handle->write_byte(reg);                                  /* write data */
}

/**
 * @brief     set power control 1
 * @param[in] *handle pointer to an st7789 handle structure
 * @param[in] avdd avdd param
 * @param[in] avcl avcl param
 * @param[in] vds vds param
 * @return    none
 * @note      none
 */
void st7789_set_power_control_1(st7789_handle_t* handle, st7789_avdd_t avdd, st7789_avcl_t avcl, st7789_vds_t vds)
{
    uint8_t buf[2];
    handle->write_cmd(ST7789_CMD_PWCTRL1);                     /* set power control 1 command */
    buf[0] = 0xA4;                                            /* set param 1 */
    buf[1] = (avdd << 6) | (avcl << 4) | (vds << 0);            /* set param 2 */
    handle->write_bytes(buf, 2);                               /* write data */
}

/**
 * @brief     enable vap van signal output
 * @param[in] *handle pointer to an st7789 handle structure
 * @return    none
 * @note      none
 */
void st7789_enable_vap_van_signal_output(st7789_handle_t* handle)
{
    uint8_t reg;
    handle->write_cmd(ST7789_CMD_VAPVANEN);                     /* set vap/van signal output command */
    reg = 0x4C;                                               /* set param */
    handle->write_byte(reg);                                  /* write data */
}

/**
 * @brief     enable or disable command 2
 * @param[in] *handle pointer to an st7789 handle structure
 * @param[in] enable bool value
 * @return    none
 * @note      none
 */
void st7789_set_command_2_enable(st7789_handle_t* handle, st7789_bool_t enable)
{
    uint8_t buf[4];
    handle->write_cmd(ST7789_CMD_CMD2EN);                     /* set command 2 enable command */
    buf[0] = 0x5A;                                            /* set param 1 */
    buf[1] = 0x69;                                            /* set param 2 */
    buf[2] = 0x02;                                            /* set param 3 */
    buf[3] = enable;                                          /* set param 4 */
    handle->write_bytes(buf, 4);                               /* write data */
}

/**
 * @brief     set positive voltage gamma control
 * @param[in] *handle pointer to an st7789 handle structure
 * @param[in] *param pointer to a param buffer
 * @return    none
 * @note      none
 */
void st7789_set_positive_voltage_gamma_control(st7789_handle_t* handle, uint8_t param[14])
{
    handle->write_cmd(ST7789_CMD_PVGAMCTRL);                     /* set positive voltage gamma control command */
    handle->write_bytes(param, 14);                             /* write data */
}

/**
 * @brief     set negative voltage gamma control
 * @param[in] *handle pointer to an st7789 handle structure
 * @param[in] *param pointer to a param buffer
 * @return    none
 * @note      none
 */
void st7789_set_negative_voltage_gamma_control(st7789_handle_t* handle, uint8_t param[14])
{
    handle->write_cmd(ST7789_CMD_NVGAMCTRL);                     /* set negative voltage gamma control command */
    handle->write_bytes(param, 14);                             /* write data */
}

/**
 * @brief     set red digital gamma look up table
 * @param[in] *handle pointer to an st7789 handle structure
 * @param[in] *param pointer to a param buffer
 * @return    none
 * @note      none
 */
void st7789_set_digital_gamma_look_up_table_red(st7789_handle_t* handle, uint8_t param[64])
{
    handle->write_cmd(ST7789_CMD_DGMLUTR);                     /* set digital gamma look-up table for red command */
    handle->write_bytes(param, 64);                             /* write data */
}

/**
 * @brief     set blue digital gamma look up table
 * @param[in] *handle pointer to an st7789 handle structure
 * @param[in] *param pointer to a param buffer
 * @return    none
 * @note      none
 */
void st7789_set_digital_gamma_look_up_table_blue(st7789_handle_t* handle, uint8_t param[64])
{
    handle->write_cmd(ST7789_CMD_DGMLUTB);                     /* set digital gamma look-up table for blue command */
    handle->write_bytes(param, 64);                             /* write data */
}


/**
 * @brief     set gate
 * @param[in] *handle pointer to an st7789 handle structure
 * @param[in] gate_line_number gate line number
 * @param[in] first_scan_line_number first scan line number
 * @param[in] mode gate scan mode
 * @param[in] direction gate scan direction
 * @return    none
 * @note      0 <= gate_line_number <= 0x3F
 *            0 <= first_scan_line_number 0x3F
 */
void st7789_set_gate(st7789_handle_t* handle,
                     uint8_t gate_line_number,
                     uint8_t first_scan_line_number,
                     st7789_gate_scan_mode_t mode,
                     st7789_gate_scan_direction_t direction)
{
    uint8_t buf[3];
    handle->write_cmd(ST7789_CMD_GATECTRL);                     /* set gate control command */
    buf[0] = gate_line_number;                                  /* set param 1 */
    buf[1] = first_scan_line_number;                            /* set param 2 */
    buf[2] = 0x10 | (mode << 2) | (direction << 0);             /* set param 3 */
    handle->write_bytes(buf, 3);                                /* write data */
}

/**
 * @brief      convert the gate line to the register raw data
 * @param[in]  *handle pointer to an st7789 handle structure
 * @param[in]  l gate line
 * @param[out] *reg pointer to a register raw buffer
 * @return    none
 * @note       none
 */
void st7789_gate_line_convert_to_register(st7789_handle_t* handle, uint16_t l, uint8_t* reg)
{

    *reg = (uint8_t)((l / 8) - 1);            /* convert real data to register data */

}

/**
 * @brief      convert the register raw data to the gate line
 * @param[in]  *handle pointer to an st7789 handle structure
 * @param[in]  reg register raw data
 * @param[out] *l pointer to a gate line buffer
 * @return    none
 * @note       none
 */
void st7789_gate_line_convert_to_data(st7789_handle_t* handle, uint8_t reg, uint16_t* l)
{
    *l = (uint8_t)(reg * 8 + 8);           /* convert raw data to real data */
}

/**
 * @brief     set spi2 enable
 * @param[in] *handle pointer to an st7789 handle structure
 * @param[in] date_lane bool value
 * @param[in] command_table_2 bool value
 * @return    none
 * @note       none
 */
void st7789_set_spi2_enable(st7789_handle_t* handle, st7789_bool_t date_lane, st7789_bool_t command_table_2)
{
    uint8_t reg;
    handle->write_cmd(ST7789_CMD_SPI2EN);                     /* set spi2 enable command */
    reg = (date_lane << 4) | (command_table_2 << 0);           /* set param */
    handle->write_byte(reg);                                  /* write data */
}

/**
 * @brief     set power control 2
 * @param[in] *handle pointer to an st7789 handle structure
 * @param[in] sbclk sbclk div
 * @param[in] stp14ck stp14ck div
 * @return    none
 * @note       none
 */
void st7789_set_power_control_2(st7789_handle_t* handle, st7789_sbclk_div_t sbclk, st7789_stp14ck_div_t stp14ck)
{
    uint8_t reg;
    handle->write_cmd(ST7789_CMD_PWCTRL2);                     /* set power control 2 command */
    reg = (sbclk << 4) | (stp14ck << 0);                        /* set param */
    handle->write_byte(reg);                                  /* write data */
}


/**
 * @brief     set equalize time control
 * @param[in] *handle pointer to an st7789 handle structure
 * @param[in] source_equalize_time source equalize time
 * @param[in] source_pre_drive_time source pre drive time
 * @param[in] gate_equalize_time gate equalize time
 * @return    none
 * @note      0 <= source_equalize_time <= 0x1F
 */
void st7789_set_equalize_time_control(st7789_handle_t* handle,
                                      uint8_t source_equalize_time,
                                      uint8_t source_pre_drive_time,
                                      uint8_t gate_equalize_time)
{
    handle->write_cmd(ST7789_CMD_EQCTRL);                     /* set equalize time control command */
    handle->write_byte(source_equalize_time);
    handle->write_byte(source_pre_drive_time);
    handle->write_byte(gate_equalize_time);

}


/**
 * @brief     set program mode control
 * @param[in] *handle pointer to an st7789 handle structure
 * @return    none
 * @note       none
 */
void st7789_set_program_mode_control(st7789_handle_t* handle)
{
    uint8_t reg;
    handle->write_cmd(ST7789_CMD_PROMCTRL);                     /* set program mode control command */
    reg = 0x01;                                               /* set param */
    handle->write_byte(reg);                                  /* write data */
}

/**
 * @brief     enable or disable program mode
 * @param[in] *handle pointer to an st7789 handle structure
 * @param[in] enable bool value
 * @return    none
 * @note       none
 */
void st7789_set_program_mode_enable(st7789_handle_t* handle, st7789_bool_t enable)
{
    uint8_t buf[4];
    handle->write_cmd(ST7789_CMD_PROMEN);                     /* set program mode enable command */
    buf[0] = 0x5A;                                            /* set param 1 */
    buf[1] = 0x69;                                            /* set param 2 */
    buf[2] = 0xEE;                                            /* set param 3 */
    buf[3] = enable << 2;                                     /* set param 4 */
    handle->write_bytes(buf, 4);                               /* write data */
}


/**
 * @brief     set nvm setting
 * @param[in] *handle pointer to an st7789 handle structure
 * @param[in] addr nvm address
 * @param[in] data nvm set data
 * @return    none
 * @note       none
 */
void st7789_set_nvm_setting(st7789_handle_t* handle, uint8_t addr, uint8_t data)
{
    handle->write_cmd(ST7789_CMD_NVMSET);                     /* set nvm setting command */
    handle->write_byte(addr);
    handle->write_byte(data);

}


/**
 * @brief     set program action
 * @param[in] *handle pointer to an st7789 handle structure
 * @return    none
 * @note       none
 */
void st7789_set_program_action(st7789_handle_t* handle)
{
    handle->write_cmd(ST7789_CMD_PROMACT);                     /* set program action command */
    handle->write_byte(0x29);
    handle->write_byte(0xA5);
}

/**
 * @brief     clear the display
 * @param[in] *handle pointer to an st7789 handle structure
 * @param[in] color display color
 * @note      none
 */
void st7789_clear(st7789_handle_t* handle, uint16_t color)
{

    st7789_set_column_address(handle, 0,  handle->column - 1);
    st7789_set_row_address(handle, 0, handle->row - 1);
    handle->write_cmd(ST7789_CMD_RAMWR);
    for(int i = 0; i < handle->column* handle->row; i++)
    {
        handle->write_16b(color);
    }
}

/**
 * @brief     fill the rect 指定矩形区域填充颜色
 * @param[in] *handle pointer to an st7789 handle structure
 * @param[in] left left coordinate x
 * @param[in] top top coordinate y
 * @param[in] right right coordinate x
 * @param[in] bottom bottom coordinate y
 * @param[in] color display color
 * @note      left <= column && right <= column && left < right && top <= row && bottom <= row && top < bottom
 */
void st7789_fill_rect(st7789_handle_t* handle, uint16_t left, uint16_t top, uint16_t right, uint16_t bottom, uint16_t color)
{
    uint32_t i;
    uint32_t j;
    st7789_set_column_address(handle, left, right);                     /* set column address */
    st7789_set_row_address(handle, top, bottom);                       /* set row address */
    handle->write_cmd(ST7789_CMD_RAMWR);                                /* set memory write command */
    for(i = left; i <= right; i++)
    {
        for(j = top; j <= bottom; j++)
        {
            handle->write_16b(color);
        }
    }
}

/**
 * @brief     draw a point in the display
 * @param[in] *handle pointer to an st7789 handle structure
 * @param[in] x coordinate x
 * @param[in] y coordinate y
 * @param[in] color point color
 * @return    status code
 *            - 0 success
 *            - 1 draw point failed
 * @note      none
 */
void st7789_draw_point(st7789_handle_t* handle, uint16_t x, uint16_t y, uint32_t color)
{
    handle->write_cmd(ST7789_CMD_CASET);                                /* set column address command */
    handle->write_byte((x >> 8) & 0xFF);                                /* write data */
    handle->write_byte((x >> 0) & 0xFF);                                /* write data */
    handle->write_cmd(ST7789_CMD_RASET);                                /* set row address command */
    handle->write_byte((y >> 8) & 0xFF);                                /* write data */
    handle->write_byte((y >> 0) & 0xFF);                                /* write data */
    handle->write_cmd(ST7789_CMD_RAMWR);                                /* set memory write command */
    handle->write_16b(color);
}




/**
 * @brief     draw a char in the display
 * @param[in] *handle pointer to an st7789 handle structure
 * @param[in] x coordinate x
 * @param[in] y coordinate y
 * @param[in] chr display char
 * @param[in] size display size
 * @param[in] color display color
 * @return    status code
 *            - 0 success
 *            - 1 show char failed
 * @note      none
 */
void st7789_show_char(st7789_handle_t* handle, uint16_t x, uint16_t y, uint8_t chr, uint8_t size, uint32_t color)
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
                st7789_draw_point(handle, x, y, color);                           /* draw point */
            }
            else
            {
            
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
 * @brief     write a string in the display
 * @param[in] *handle pointer to an st7789 handle structure
 * @param[in] x coordinate x
 * @param[in] y coordinate y
 * @param[in] *str pointer to a write string address
 * @param[in] len length of the string
 * @param[in] color display color
 * @param[in] font string font
 * @return    status code
 *            - 0 success
 *            - 1 draw point failed
 *            - 2 handle is NULL
 *            - 3 handle is not initialized
 *            - 4 x or y is invalid
 * @note      x < column && y < row
 */
void st7789_write_string(st7789_handle_t* handle, uint16_t x, uint16_t y, char* str, uint32_t color, st7789_font_t font)
{
    while((*str <= '~') && (*str >= ' '))                      /* write all string */
    {
        if(x >= (handle->column - (font / 2)))                               /* check x point */
        {
            x = 0;                                                           /* set x */
            y += (uint8_t)font;                                              /* set next row */
        }
        if(y >= (handle->row - font))                                        /* check y pont */
        {
            y = x = 0;                                                       /* reset to 0 */
        }
        st7789_show_char(handle, x, y, *str, font, color);       /* show a char */
        x += (uint8_t)(font / 2);                                            /* x + font/2 */
        str++;                                                               /* str address++ */
    }
}




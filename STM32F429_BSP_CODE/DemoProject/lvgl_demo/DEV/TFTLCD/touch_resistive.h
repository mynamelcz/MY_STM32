#ifndef __TOUCH_R_H
#define __TOUCH_R_H

#include "stm32f4xx.h"


void touch_resistive_init(void);
uint8_t touch_is_pressed(void);
void touch_read_xy(uint16_t* x, uint16_t* y);

#endif



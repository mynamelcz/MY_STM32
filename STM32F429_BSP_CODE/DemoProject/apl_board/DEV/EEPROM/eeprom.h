#ifndef __EEPROM_H
#define __EEPROM_H
#include "includes.h"


void eep_write_byte(u16 addr, u8 data);
u8 eep_read_byte(u16 addr);
void eep_write(u16 addr, u8 *buf, u8 len);
void eep_read(u16 addr, u8 *buf, u8 len);


#endif



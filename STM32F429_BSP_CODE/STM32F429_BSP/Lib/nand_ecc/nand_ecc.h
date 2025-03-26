#ifndef __NAND_ECC_H__
#define __NAND_ECC_H__

//#define __BIG_ENDIAN
//#define CONFIG_MTD_NAND_ECC_SMC


/**
 * __nand_calculate_ecc - [NAND Interface] Calculate 3-byte ECC for 256/512-byte
 *			 block
 * @buf:	input buffer with raw data
 * @eccsize:	data bytes per ECC step (256 or 512)
 * @code:	output buffer with ECC
 */
void __nand_calculate_ecc(const unsigned char *buf, unsigned int eccsize,
		       unsigned char *code);



/**
 * __nand_correct_data - [NAND Interface] Detect and correct bit error(s)
 * @buf:	raw data read from the chip
 * @read_ecc:	ECC from the chip
 * @calc_ecc:	the ECC calculated from raw data
 * @eccsize:	data bytes per ECC step (256 or 512)
 *
 * Detect and correct a 1 bit error for eccsize byte block
state:
	0-> No ERROR
	1-> 1bit ERROR
    2-> >= 2bit ERROR
return: byte_addr(16) | bit (8) | state(8)
 */
unsigned int __nand_check_data(unsigned char *read_ecc, unsigned char *calc_ecc,unsigned int eccsize);




#endif

#ifndef __CBUF_H
#define __CBUF_H
#include "typdef.h"

struct cbuf_t
{
	unsigned char *buffer;			  //循环buffer指针
	unsigned int   size;            //循环buffer空间大小
	unsigned int   in;              //输入数据偏移索引
	unsigned int   out;             //输出数据偏移索引
	int (*lock)(int flag);
};

unsigned int get_fifo_size(struct cbuf_t *cbuf);
unsigned int put_fifo(struct cbuf_t *cbuf, const unsigned char* data_in, unsigned int len);
unsigned int get_fifo(struct cbuf_t *cbuf,       unsigned char *data_out,unsigned int len);
unsigned int get_fifo_no_remove(struct cbuf_t *cbuf,  unsigned char* data_out, unsigned int len);
unsigned int get_fifo_roll(struct cbuf_t *cbuf,unsigned char *data_out,  unsigned int len);
unsigned int cbuffer_init(struct cbuf_t *cbuf,u8 *buf, u32 size, int(*lock_fun)(int));



#endif






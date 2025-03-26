#ifndef __TIMER_DELAY_H
#define __TIMER_DELAY_H

#include "includes.h"
#include "linux_list.h"

typedef struct __timer_opt{
	void (*init)(u16 sys_clk_mhz);
	void (*delay_ms)(u32 ms);
	void (*delay_us)(u32 us);
	void (*clear_timer)(void);
	u32 (*get_time_us)(void);
	u32 (*get_sys_time_ms)(void);
}timer_opt_t;
extern const timer_opt_t TimeDelay;



#ifdef LOOP_FUN_TIMER_INDEX

typedef struct{
	u32  time;
	u32  cnt;
	void (*hdl_fun)(void);
	struct list_head list;
}Tirq_hd_t;

typedef struct{
	u32  time;
	u32  cnt;
	void (*hdl_fun)(void);
}Tirq_sec_hd_t;


#define __IRQ_HdlTypedef(fun, times) 	   	\
Tirq_hd_t fun##irq = {			  			\
	 .time  = times,					   	\
	 .cnt   = 0,						   	\
	 .hdl_fun = fun,          			   	\
	 .list = LIST_HEAD_INIT(fun##irq.list) 	\
}

#define T_IRQ_Hdl(fun)	    	   &(fun##irq)	

void timer_loop_init(void);	
void timer_loop_callback(void);
void register_timer_handler(Tirq_hd_t *hd_t);
void register_timer_handler_malloc(void(*fun)(void), u32 time);
void unregister_timer_handler(void(*fun)(void));

#endif











#endif



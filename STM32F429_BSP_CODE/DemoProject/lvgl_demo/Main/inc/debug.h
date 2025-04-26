#ifndef __DEBUG_H
#define __DEBUG_H


#include "stdio.h"

#define __ASSERT_PARAM
#define __DBG_ENABLE






#ifdef __DBG_ENABLE


#define DBUG_Printf 	printf		// MY_RTT_printf

extern int my_printhex(const char *buf, unsigned int len);
#define DBUG_Put_hex 	my_printhex	

#else
#define DBUG_Printf(...) 	
#define DBUG_Put_hex(...) 	
#endif


#define ERR_printf(res)		 DBUG_Printf("__file:%s, __line:%d, __fun:%s, Res: %d\n",__FILE__,__LINE__,__func__,res)
#define ERR_log				 DBUG_Printf



/* DEBUG level */
#define DBG_LOG             0
#define DBG_INFO            1
#define DBG_WARNING         2
#define DBG_ERROR           3

#ifdef __DBG_ENABLE
	#define DBG_LEVEL         DBG_LOG
	
	
	#if (DBG_LOG >= DBG_LEVEL)
		#define LOG_FUN(...)			DBUG_Printf("[fun]:%s\n",__FUNCTION__);
		#define LOG_D(...)				DBUG_Printf("[log]:"__VA_ARGS__)
		#define LOG_HEX(inf,dat,len)    DBUG_Printf("[hex]:%s",inf);DBUG_Put_hex((const char *)dat,len)
	#else
		#define LOG_D(...)
		#define LOG_FUN(...)
		#define LOG_HEX(...)
	#endif

	#if (DBG_INFO >= DBG_LEVEL)
		#define LOG_I(...)          DBUG_Printf("[inf]:"__VA_ARGS__)
	#else
		#define LOG_I(...)
	#endif
	
	#if (DBG_WARNING >= DBG_LEVEL)
		#define LOG_W(...)          DBUG_Printf("[Warning][%d]:"__VA_ARGS__,__LINE__)
	#else
		#define LOG_W(...)
	#endif
	
	#if (DBG_ERROR >= DBG_LEVEL)
		#define LOG_E(...)     		DBUG_Printf("[err addr]:\n\t__file:%s\n\t__line:%d\n\t__fun:%s\n[err inf]:\n\t",__FILE__,__LINE__,__func__);\
									DBUG_Printf(__VA_ARGS__)
									
		#define LOG_ErrTag()		DBUG_Printf("[err addr]:\n\t__file:%s\n\t__line:%d\n\t__fun:%s\n",__FILE__,__LINE__,__func__)					
									
   
	#else
		#define LOG_E(...)
		#define LOG_ErrTag()
	#endif

#else
	
	
	#define LOG_D(...)
	#define LOG_FUN(...)
	#define LOG_I(...) 
	#define LOG_W(...)
	#define LOG_E(...)
    #define LOG_ErrTag()
	#define LOG_HEX(...)
#endif







#ifdef __ASSERT_PARAM
#include "typdef.h"
extern void my_assert_failed(u8* file, u32 line);
#define ASSERT(expr)  \
do{					\
	if(!expr) my_assert_failed((u8 *)__FILE__, __LINE__);	\
}while(0);


#else
#define ASSERT(expr) ((void)0U)	 
#endif





#endif















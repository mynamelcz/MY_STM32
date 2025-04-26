#ifndef _TYPEDF_H
#define _TYPEDF_H

#undef NULL
#define NULL 0                   /* see <stddef.h> */



#define TRUE	(0)
#define FALSE	(!TRUE)


#define __AT_SEC(X)			__attribute__((section(X)))
#define __AT_ADDR(X)	  __attribute__((AT(X)))
#define __USED          __attribute__((used))
#define __ALIGN(n)      __attribute__((aligned(n)))

//typedef char			bool;			

/* exact-width signed integer types */
typedef signed           char s8;
typedef signed short     int s16;
typedef signed           int s32;


/* exact-width unsigned integer types */
typedef unsigned          char u8;
typedef unsigned short    int u16;
typedef unsigned          int u32;
typedef unsigned long long	  u64;


/* exact-width unsigned integer types */
typedef unsigned          char BOOLEAN;
typedef unsigned          char UINT8;
typedef unsigned short    int UINT16;
typedef unsigned          int UINT32;

typedef signed           char INT8;
typedef signed short     int INT16;
typedef signed           int INT32;




typedef unsigned          char uint8_t;
typedef unsigned short    int uint16_t;
typedef unsigned          int uint32_t;

typedef signed           char int8_t;
typedef signed short     int int16_t;
typedef signed           int int32_t;

#endif















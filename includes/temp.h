/*
*********************************************************************************************************
*											        ePOS
*						           the Easy Portable/Player Operation System
*									           XXXX sub-system
*
*						        (c) Copyright 2006-2007, Steven.ZGJ China
*											All	Rights Reserved
*
* File   : XXXX.h
* Version: V1.0
* By     : steven.zgj
*********************************************************************************************************
*/

#ifndef _XXXX_H_
#define _XXXX_H_

#include "typedef.h"
#include "cfgs.h"

#ifdef EPDK_USED_BY_KRNL
#define __swi(x)
#endif
//**********************************************************************************************************
//* define level 0( system level)
//************************************************
// 常数定义

//************************************************
// 数据类型定义

//************************************************
// 变量定义
/* GLOBAL VARIABLES */

//************************************************
// 函数定义
/* system call table */
typedef struct
{
    __esswi esXXXX_fun0                   ;
    __esswi esXXXX_fun1                   ;
} SWIHandler_XXXX_t;
#define SYSCALL_XXXX(x,y) __swi(SWINO(SWINO_XXXX, SWIHandler_XXXX_t, y))x y
SYSCALL_DMA(void,  esXXXX_fun0)(void);
SYSCALL_DMA(__u32, esXXXX_fun1)(__u32 p0, __u32 p1, __u32 p2, __u32 p3);
//**********************************************************************************************************

//**********************************************************************************************************
//* define level 1( system level)
//************************************************
// 常数定义

//************************************************
// 数据类型定义

//************************************************
// 变量定义

extern SWIHandler_XXXX_t SWIHandler_XXXX;
//************************************************
// 函数定义
__u32 XXXX_init	(void);
__u32 XXXX_exit (void);

//**********************************************************************************************************

#endif  /* _XXXX_H_ */


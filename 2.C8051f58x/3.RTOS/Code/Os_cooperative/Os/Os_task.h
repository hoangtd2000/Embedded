/*
 *  Created on: Apr 21, 2025
 *      Author: Hoangtd2000
 */
#ifndef _OS_TASK_H_
#define _OS_TASK_H_
#include "Service.h"
#include "Os_config.h"

typedef struct{
	U32 block_count;
	U8 current_state;
	void (*task_handler)(void);
} TCB_t;

void Create_task(U8 id , void(*task_handler)(void));
void Unblock_task(void);
void Os_delay(U32 time);
#endif

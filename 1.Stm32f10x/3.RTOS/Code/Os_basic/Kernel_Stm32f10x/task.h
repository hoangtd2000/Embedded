/*
 * task.h
 *
 *  Created on: Apr 7, 2025
 *      Author: MCNEX
 */

#ifndef TASK_H_
#define TASK_H_
#include "stdint.h"
typedef struct {
	uint32_t psp_value;
	uint32_t block_count;
	uint8_t current_state;
	void (*task_handler)(void);
} TCB_t;

int create_task(void (*task_handler)(void), uint32_t stack_size);


#endif /* TASK_H_ */

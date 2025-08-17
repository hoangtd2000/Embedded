/*
 * scheduler.h
 *
 *  Created on: Apr 7, 2025
 *      Author: MCNEX
 */

#ifndef SCHEDULER_H_
#define SCHEDULER_H_
#include "rtos_config.h"
#include "task.h"
#include "stdint.h"
__attribute__((naked)) void scheduler_init(uint32_t top_of_stack);
__attribute__((naked)) void switch_msp_to_psp(void);
#endif /* SCHEDULER_H_ */

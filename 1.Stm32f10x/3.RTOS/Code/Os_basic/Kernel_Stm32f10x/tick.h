/*
 * tick.h
 *
 *  Created on: Apr 7, 2025
 *      Author: MCNEX
 */

#ifndef TICK_H_
#define TICK_H_
#include "rtos_config.h"
#include "task.h"
#include "stm32f10x_conf.h"
void task_delay(uint32_t tick_count);

#endif /* TICK_H_ */

/*
 *  Created on: Apr 21, 2025
 *      Author: Hoangtd2000
 */
#ifndef _APPLICATION_H_
#define _APPLICATION_H_

#include "Os_scheduler.h"
#include "Os_config.h"
#include "Os_task.h"
#include "Service.h"
#include <compiler_defs.h>
#include <C8051F580_defs.h> // SFR declarations

void Os_start(void);
void idle_task(void);
void task1_handler(void);
void task2_handler(void);
void task3_handler(void);
void Callback_timer2(void);
void Callback_ext0(void);
#endif
#ifndef TICK_H_
#define TICK_H_
#include <compiler_defs.h>
#include <C8051F580_defs.h>            // SFR declarations
#include "rtos_config.h"
#include "Task.h"
void TIMER2_Init (U16 counts);
void task_delay(U32 tick_count);
void unblock_task();
void context_switching();
#endif /* TICK_H_ */
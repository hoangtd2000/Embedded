#ifndef TASK_H_
#define TASK_H_
#include <compiler_defs.h>
#include <C8051F580_defs.h>            // SFR declarations
#include "rtos_config.h"
#include "Tick.h"
#include <stdio.h>
typedef struct {
    U16 psp_value;                // Stack pointer (XRAM)
    U32 block_count;              // Số tick bị block (nếu có)
    U8 current_state;             // Ready / Blocked / Running
    void (*task_handler)(void);   // Entry function của task
} TCB_t;

// U8 create_task(void (*task_handler)(void), U32 stack_size);
// void port_prepare_stack(U8 *stack_top, void (*handler)(void));
U8 create_task(void (*task_handler)(void), U32 stack_size) ;
void port_prepare_stack(U8 **stack_ptr, void (*handler)(void)) ;
void start_scheduler(void);
void update_next_task(void) ;
void portCOPY_STACK_TO_XRAM(void);
void portCOPY_XRAM_TO_STACK(void);
void TIMER2_Init (U16 counts);
#endif /* TASK_H_ */
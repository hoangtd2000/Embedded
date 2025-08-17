/*
 * task.c
 *
 *  Created on: Apr 7, 2025
 *      Author: MCNEX
 */
#include "rtos_config.h"
#include "stdio.h"
#include "task.h"
#include "tick.h"
TCB_t user_tasks[MAX_STACKS];
uint32_t current_task = 1;


static uint32_t next_stack_addr = (SRAM_END- SIZE_SCHED_STACK);
static uint32_t task_count = 0;

int create_task(void (*task_handler)(void), uint32_t stack_size)
{
    if ((task_count >= MAX_STACKS) || (next_stack_addr < SRAM_START)) {
        return -1;
    }

    uint32_t *pPSP = (uint32_t *)next_stack_addr;
    pPSP--;
    *pPSP = DUMMY_XPSR;
    pPSP--;
    *pPSP = (uint32_t)task_handler;
    pPSP--;
    *pPSP = EXC_RETURN;
    for (int i = 0; i < 13; i++) {
        pPSP--;
        *pPSP = 0;
    }

    user_tasks[task_count] = (TCB_t){
        .psp_value = (uint32_t)pPSP,
        .current_state = TASK_RUNNING_STATE,
        .block_count = 0,
        .task_handler = task_handler
    };

    next_stack_addr -= stack_size;
    task_count++;
    return 0;
}

uint32_t get_psp_value(void) {
	return user_tasks[current_task].psp_value;
}

void save_psp_value(uint32_t current_psp_value) {
	user_tasks[current_task].psp_value = current_psp_value;
}

void update_next_task(void) {
	for (int i = 0; i < MAX_STACKS; i++) {
		uint8_t next = (current_task + i + 1) % MAX_STACKS;
		if (user_tasks[next].current_state == TASK_RUNNING_STATE && next != 0) {
			current_task = next;
			return;
		}
	}
	current_task = 0; // Quay về idle nếu không có task nào ready
}


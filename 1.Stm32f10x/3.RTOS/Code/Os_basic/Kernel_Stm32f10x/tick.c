/*
 * tick.c
 *
 *  Created on: Apr 7, 2025
 *      Author: MCNEX
 */


#include "tick.h"
extern uint32_t g_SysTick;
extern uint32_t current_task;
extern TCB_t user_tasks[MAX_STACKS];
void update_g_systick(void) {
	g_SysTick++;
}

void unblock_task(){
	for(uint8_t i = 1 ; i < MAX_STACKS ; i++){ // bỏ qua task 0 ;
		if (user_tasks[i].current_state != TASK_RUNNING_STATE){
			if (user_tasks[i].block_count == g_SysTick){ // đủ thời gian block thì sẽ chuyển state thành RUNNING
				user_tasks[i].current_state = TASK_RUNNING_STATE;
			}
		}
	}
}

void task_delay(uint32_t tick_count) {
	INTERRUPT_DISABLE();
	if (current_task) {
		user_tasks[current_task].block_count = g_SysTick + tick_count; // dánh dấu thời điểm mà task được chạy . nếu như  g_SysTick = với block_count thì sẽ mở trạng thái cho task đó
		user_tasks[current_task].current_state = TASK_BLOCKED_STATE;
		SCB->ICSR |= (1 << 28); // Trigger PendSV
	}
	INTERRUPT_ENABLE();
}

void SysTick_Handler(void) {
	update_g_systick();
	unblock_task();// kiểm tra xem task đó có bị block hay không .
	SCB->ICSR |= (1 << 28); // PendSV
}

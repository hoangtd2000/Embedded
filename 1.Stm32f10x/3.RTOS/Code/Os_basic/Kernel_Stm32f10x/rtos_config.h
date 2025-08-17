/*
 * rtos_config.h
 *
 *  Created on: Apr 7, 2025
 *      Author: MCNEX
 */

#ifndef RTOS_CONFIG_H
#define RTOS_CONFIG_H

#define SIZE_IDLE_STACK 	(500U)
#define SIZE_TASK_STACK 	(2*1024U)
#define SIZE_SCHED_STACK 	(4*1024U)

#define SRAM_START 			(0x20000000U)
#define SIZE_SRAM			(20*1024U)
#define SRAM_END 			(SRAM_START + SIZE_SRAM)

#define TICK_HZ 			1000U
#define MAX_STACKS 			5

#define DUMMY_XPSR 			0x01000000
#define EXC_RETURN			0xFFFFFFFD

// các trạng thái của task
#define TASK_RUNNING_STATE 	0
#define TASK_BLOCKED_STATE 	1
#define TASK_READY_STATE 	2

#define INTERRUPT_DISABLE() do{__asm volatile("MOV R0, #0x1");__asm volatile("MSR PRIMASK,R0");} while(0)
#define INTERRUPT_ENABLE()  do{__asm volatile ("MOV R0, #0x0");__asm volatile ("MSR PRIMASK,R0");} while(0)

#endif

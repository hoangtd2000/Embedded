#ifndef RTOS_CONFIG_H
#define RTOS_CONFIG_H

#define MAX_TASK (3U)
#define SIZE_IDLE_STACK 	(256U)
#define SIZE_TASK_STACK 	(512U)
#define SIZE_SCHED_STACK 	(1024U)

#define SRAM_START 			(0x0000U)
#define SIZE_SRAM			(8*1024U)
#define SRAM_END 			(SRAM_START + SIZE_SRAM)

#define TASK_RUNNING_STATE 	0
#define TASK_BLOCKED_STATE 	1
#define TASK_READY_STATE 	2 

// Địa chỉ bắt đầu stack nội (trong IRAM)
#define configSTACK_START    0x30

#define INTERRUPT_DISABLE (EA = 0)
#define INTERRUPT_ENABLE  (EA = 1)

#endif
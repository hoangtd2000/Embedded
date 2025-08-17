/*
 * user_tasks.c
 *
 *  Created on: Apr 8, 2025
 *      Author: MCNEX
 */
#include <stdio.h>
#include "tick.h"
void idle_task(void) {
	while (1);
}

void task1_handler(void) {
	while (1) {
		printf("Task1_handler \n");
		task_delay(450);
	}
}

void task2_handler(void) {
	while (1) {
		printf("Task2_handler \n");
		task_delay(1100);
	}
}

void task3_handler(void) {
	while (1) {
		printf("Task3_handler \n");
		task_delay(2200);
	}
}

void task4_handler(void) {
	while (1) {
		printf("Task4_handler \n");
		task_delay(3400);
	}
}



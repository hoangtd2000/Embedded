/*
 * scheduler.c
 *
 *  Created on: Apr 7, 2025
 *      Author: MCNEX
 */
#include "scheduler.h"

extern uint32_t current_task;

__attribute__((naked)) void scheduler_init(uint32_t top_of_stack) {
    __asm__ volatile ("MSR MSP, %0" :: "r"(top_of_stack));
    __asm__ volatile ("BX LR");
}

__attribute__((naked)) void switch_msp_to_psp(void) {
    __asm__ volatile ("PUSH {LR}"); // lưu giá trị LR lên MSP
    __asm__ volatile ("BL get_psp_value"); // lấy giá trị của PSP hiện tại
    __asm__ volatile ("MSR PSP, R0");
    __asm__ volatile ("POP {LR}");
    __asm__ volatile ("MOV R0, #0x02");
    __asm__ volatile ("MSR CONTROL, R0");
    __asm__ volatile ("BX LR");
}

__attribute__((naked)) void PendSV_Handler(void) {
    // 1. Lưu các thanh ghi R4-R11 vào stack của task hiện tại (dùng PSP)
    __asm__ volatile ("MRS R0, PSP");              // R0 = PSP hiện tại
    __asm__ volatile ("STMDB R0!, {R4-R11}");       // push R4-R11 lên stack

    // 2. Gọi hàm để lưu giá trị PSP lại vào mảng task
    __asm__ volatile ("PUSH {LR}");
    __asm__ volatile ("BL save_psp_value");        // lưu PSP vào user_tasks[i].psp_value

    // 3. Cập nhật task tiếp theo sẽ chạy
    __asm__ volatile ("BL update_next_task");

    // 4. Lấy lại PSP của task tiếp theo
    __asm__ volatile ("BL get_psp_value");         // trả về PSP mới trong R0

    // 5. Khôi phục R4–R11 của task mới từ stack
    __asm__ volatile ("LDMIA R0!, {R4-R11}");
    __asm__ volatile ("MSR PSP, R0");              // Gán PSP mới

    // 6. Quay lại tiếp tục task mới
    __asm__ volatile ("POP {LR}");
    __asm__ volatile ("BX LR");
}



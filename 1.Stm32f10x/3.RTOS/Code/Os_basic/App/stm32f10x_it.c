/*
 * stm32f10x_it.c
 *
 *  Created on: Mar 30, 2025
 *      Author: Hoang
 */
/* Includes ------------------------------------------------------------------*/
#include "stm32f10x_it.h"
#include "stdio.h"
uint32_t g_SysTick = 0  ;
/**
  * @brief  This function handles HardFault Handler.
  * @param  None
  * @retval None
  */
//void SVC_Handler(void) {
//    // Đặt Breakpoint ở đây để kiểm tra
//    volatile uint32_t svc_number = 0;
//    svc_number++;
//}
void HardFault_Handler(void){
	printf("Exception : HardFault_Handler \n");
	while(1);
}
/**
  * @brief  This function handles MemManage Handler.
  * @param  None
  * @retval None
  */
void MemManage_Handler(void){
	printf("Exception : MemManage_Handler \n");
	while(1);
}
/**
  * @brief  This function handles MemManage Handler.
  * @param  None
  * @retval None
  */
void BusFault_Handler(void){
	printf("Exception : BusFault_Handler \n");
	while(1);

}
/**
  * @brief  This function handles SysTick Handler.
  * @param  None
  * @retval None
  */
//void SysTick_Handler(void){
//	update_g_systick();
//}

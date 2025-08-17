/*
 * stm32f10x_it.h
 *
 *  Created on: Mar 30, 2025
 *      Author: Hoang
 */

#ifndef STM32F10X_IT_H_
#define STM32F10X_IT_H_


/* Includes ------------------------------------------------------------------*/
#include "stm32f10x.h"

/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */

void NMI_Handler(void);
void HardFault_Handler(void);
void MemManage_Handler(void);
void BusFault_Handler(void);
void UsageFault_Handler(void);
void SVC_Handler(void);
void DebugMon_Handler(void);
void PendSV_Handler(void);
void SysTick_Handler(void);


#endif /* STM32F10X_IT_H_ */

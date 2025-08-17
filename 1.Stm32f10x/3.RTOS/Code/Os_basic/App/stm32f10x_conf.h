/*
 * stm32f10x_conf.h
 *
 *  Created on: Mar 27, 2025
 *      Author: MCNEX
 */

#ifndef STM32F10X_CONF_H_
#define STM32F10X_CONF_H_
//standard library
#include <stdio.h>
#include <stdint.h>
// core
#include "system_stm32f10x.h"

//driver
#include "stm32f10x_gpio.h"
#include "stm32f10x_rcc.h"
#include "stm32f10x_usart.h"
#include "misc.h"
#include "stm32f10x.h"

//RTOS mini kernel
#include "rtos_config.h"
#include "scheduler.h"
#include "task.h"
#include "tick.h"
#include "user_tasks.h"
#ifdef  USE_FULL_ASSERT

/**
  * @brief  The assert_param macro is used for function's parameters check.
  * @param  expr: If expr is false, it calls assert_failed function which reports
  *         the name of the source file and the source line number of the call
  *         that failed. If expr is true, it returns no value.
  * @retval None
  */
  #define assert_param(expr) ((expr) ? (void)0 : assert_failed((uint8_t *)__FILE__, __LINE__))
/* Exported functions ------------------------------------------------------- */
  void assert_failed(uint8_t* file, uint32_t line);
#else
  #define assert_param(expr) ((void)0)
#endif /* USE_FULL_ASSERT */

#endif /* STM32F10X_CONF_H_ */

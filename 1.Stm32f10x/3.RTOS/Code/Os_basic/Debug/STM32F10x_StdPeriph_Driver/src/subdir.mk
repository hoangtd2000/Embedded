################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../STM32F10x_StdPeriph_Driver/src/misc.c \
../STM32F10x_StdPeriph_Driver/src/stm32f10x_gpio.c \
../STM32F10x_StdPeriph_Driver/src/stm32f10x_rcc.c \
../STM32F10x_StdPeriph_Driver/src/stm32f10x_usart.c 

OBJS += \
./STM32F10x_StdPeriph_Driver/src/misc.o \
./STM32F10x_StdPeriph_Driver/src/stm32f10x_gpio.o \
./STM32F10x_StdPeriph_Driver/src/stm32f10x_rcc.o \
./STM32F10x_StdPeriph_Driver/src/stm32f10x_usart.o 

C_DEPS += \
./STM32F10x_StdPeriph_Driver/src/misc.d \
./STM32F10x_StdPeriph_Driver/src/stm32f10x_gpio.d \
./STM32F10x_StdPeriph_Driver/src/stm32f10x_rcc.d \
./STM32F10x_StdPeriph_Driver/src/stm32f10x_usart.d 


# Each subdirectory must supply rules for building sources it contributes
STM32F10x_StdPeriph_Driver/src/%.o STM32F10x_StdPeriph_Driver/src/%.su STM32F10x_StdPeriph_Driver/src/%.cyclo: ../STM32F10x_StdPeriph_Driver/src/%.c STM32F10x_StdPeriph_Driver/src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -c -I../Inc -I../CMSIS -I../STM32F10x_StdPeriph_Driver/inc -I"C:/Users/MCNEX/STM32CubeIDE/workspace_1.16.1/Os_basic/Kernel_Stm32f10x" -I"C:/Users/MCNEX/STM32CubeIDE/workspace_1.16.1/Os_basic/Kernel_Stm32f10x" -I"C:/Users/MCNEX/STM32CubeIDE/workspace_1.16.1/Os_basic/App" -O0 -ffunction-sections -fdata-sections -Wall -fomit-frame-pointer -fno-inline-functions -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-STM32F10x_StdPeriph_Driver-2f-src

clean-STM32F10x_StdPeriph_Driver-2f-src:
	-$(RM) ./STM32F10x_StdPeriph_Driver/src/misc.cyclo ./STM32F10x_StdPeriph_Driver/src/misc.d ./STM32F10x_StdPeriph_Driver/src/misc.o ./STM32F10x_StdPeriph_Driver/src/misc.su ./STM32F10x_StdPeriph_Driver/src/stm32f10x_gpio.cyclo ./STM32F10x_StdPeriph_Driver/src/stm32f10x_gpio.d ./STM32F10x_StdPeriph_Driver/src/stm32f10x_gpio.o ./STM32F10x_StdPeriph_Driver/src/stm32f10x_gpio.su ./STM32F10x_StdPeriph_Driver/src/stm32f10x_rcc.cyclo ./STM32F10x_StdPeriph_Driver/src/stm32f10x_rcc.d ./STM32F10x_StdPeriph_Driver/src/stm32f10x_rcc.o ./STM32F10x_StdPeriph_Driver/src/stm32f10x_rcc.su ./STM32F10x_StdPeriph_Driver/src/stm32f10x_usart.cyclo ./STM32F10x_StdPeriph_Driver/src/stm32f10x_usart.d ./STM32F10x_StdPeriph_Driver/src/stm32f10x_usart.o ./STM32F10x_StdPeriph_Driver/src/stm32f10x_usart.su

.PHONY: clean-STM32F10x_StdPeriph_Driver-2f-src


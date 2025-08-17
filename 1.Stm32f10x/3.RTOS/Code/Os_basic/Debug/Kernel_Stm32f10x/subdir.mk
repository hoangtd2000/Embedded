################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Kernel_Stm32f10x/scheduler.c \
../Kernel_Stm32f10x/task.c \
../Kernel_Stm32f10x/tick.c 

OBJS += \
./Kernel_Stm32f10x/scheduler.o \
./Kernel_Stm32f10x/task.o \
./Kernel_Stm32f10x/tick.o 

C_DEPS += \
./Kernel_Stm32f10x/scheduler.d \
./Kernel_Stm32f10x/task.d \
./Kernel_Stm32f10x/tick.d 


# Each subdirectory must supply rules for building sources it contributes
Kernel_Stm32f10x/%.o Kernel_Stm32f10x/%.su Kernel_Stm32f10x/%.cyclo: ../Kernel_Stm32f10x/%.c Kernel_Stm32f10x/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -c -I../Inc -I../CMSIS -I../STM32F10x_StdPeriph_Driver/inc -I"C:/Users/MCNEX/STM32CubeIDE/workspace_1.16.1/Os_basic/Kernel_Stm32f10x" -I"C:/Users/MCNEX/STM32CubeIDE/workspace_1.16.1/Os_basic/Kernel_Stm32f10x" -I"C:/Users/MCNEX/STM32CubeIDE/workspace_1.16.1/Os_basic/App" -O0 -ffunction-sections -fdata-sections -Wall -fomit-frame-pointer -fno-inline-functions -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Kernel_Stm32f10x

clean-Kernel_Stm32f10x:
	-$(RM) ./Kernel_Stm32f10x/scheduler.cyclo ./Kernel_Stm32f10x/scheduler.d ./Kernel_Stm32f10x/scheduler.o ./Kernel_Stm32f10x/scheduler.su ./Kernel_Stm32f10x/task.cyclo ./Kernel_Stm32f10x/task.d ./Kernel_Stm32f10x/task.o ./Kernel_Stm32f10x/task.su ./Kernel_Stm32f10x/tick.cyclo ./Kernel_Stm32f10x/tick.d ./Kernel_Stm32f10x/tick.o ./Kernel_Stm32f10x/tick.su

.PHONY: clean-Kernel_Stm32f10x


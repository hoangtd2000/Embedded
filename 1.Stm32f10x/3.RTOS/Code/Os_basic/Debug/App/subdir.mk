################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../App/main.c \
../App/stm32f10x_it.c \
../App/syscalls.c \
../App/sysmem.c \
../App/user_tasks.c 

OBJS += \
./App/main.o \
./App/stm32f10x_it.o \
./App/syscalls.o \
./App/sysmem.o \
./App/user_tasks.o 

C_DEPS += \
./App/main.d \
./App/stm32f10x_it.d \
./App/syscalls.d \
./App/sysmem.d \
./App/user_tasks.d 


# Each subdirectory must supply rules for building sources it contributes
App/%.o App/%.su App/%.cyclo: ../App/%.c App/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -c -I../Inc -I../CMSIS -I../STM32F10x_StdPeriph_Driver/inc -I"C:/Users/MCNEX/STM32CubeIDE/workspace_1.16.1/Os_basic/Kernel_Stm32f10x" -I"C:/Users/MCNEX/STM32CubeIDE/workspace_1.16.1/Os_basic/Kernel_Stm32f10x" -I"C:/Users/MCNEX/STM32CubeIDE/workspace_1.16.1/Os_basic/App" -O0 -ffunction-sections -fdata-sections -Wall -fomit-frame-pointer -fno-inline-functions -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-App

clean-App:
	-$(RM) ./App/main.cyclo ./App/main.d ./App/main.o ./App/main.su ./App/stm32f10x_it.cyclo ./App/stm32f10x_it.d ./App/stm32f10x_it.o ./App/stm32f10x_it.su ./App/syscalls.cyclo ./App/syscalls.d ./App/syscalls.o ./App/syscalls.su ./App/sysmem.cyclo ./App/sysmem.d ./App/sysmem.o ./App/sysmem.su ./App/user_tasks.cyclo ./App/user_tasks.d ./App/user_tasks.o ./App/user_tasks.su

.PHONY: clean-App


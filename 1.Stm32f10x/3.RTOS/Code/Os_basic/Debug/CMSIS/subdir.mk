################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../CMSIS/core_cm3.c \
../CMSIS/system_stm32f10x.c 

OBJS += \
./CMSIS/core_cm3.o \
./CMSIS/system_stm32f10x.o 

C_DEPS += \
./CMSIS/core_cm3.d \
./CMSIS/system_stm32f10x.d 


# Each subdirectory must supply rules for building sources it contributes
CMSIS/%.o CMSIS/%.su CMSIS/%.cyclo: ../CMSIS/%.c CMSIS/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -c -I../Inc -I../CMSIS -I../STM32F10x_StdPeriph_Driver/inc -I"C:/Users/MCNEX/STM32CubeIDE/workspace_1.16.1/Os_basic/Kernel_Stm32f10x" -I"C:/Users/MCNEX/STM32CubeIDE/workspace_1.16.1/Os_basic/Kernel_Stm32f10x" -I"C:/Users/MCNEX/STM32CubeIDE/workspace_1.16.1/Os_basic/App" -O0 -ffunction-sections -fdata-sections -Wall -fomit-frame-pointer -fno-inline-functions -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-CMSIS

clean-CMSIS:
	-$(RM) ./CMSIS/core_cm3.cyclo ./CMSIS/core_cm3.d ./CMSIS/core_cm3.o ./CMSIS/core_cm3.su ./CMSIS/system_stm32f10x.cyclo ./CMSIS/system_stm32f10x.d ./CMSIS/system_stm32f10x.o ./CMSIS/system_stm32f10x.su

.PHONY: clean-CMSIS


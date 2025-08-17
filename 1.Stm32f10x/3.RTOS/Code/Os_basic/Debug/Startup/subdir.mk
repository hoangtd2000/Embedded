################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Startup/startup.c 

OBJS += \
./Startup/startup.o 

C_DEPS += \
./Startup/startup.d 


# Each subdirectory must supply rules for building sources it contributes
Startup/%.o Startup/%.su Startup/%.cyclo: ../Startup/%.c Startup/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -c -I../Inc -I../CMSIS -I../STM32F10x_StdPeriph_Driver/inc -I"C:/Users/MCNEX/STM32CubeIDE/workspace_1.16.1/Os_basic/Kernel_Stm32f10x" -I"C:/Users/MCNEX/STM32CubeIDE/workspace_1.16.1/Os_basic/Kernel_Stm32f10x" -I"C:/Users/MCNEX/STM32CubeIDE/workspace_1.16.1/Os_basic/App" -O0 -ffunction-sections -fdata-sections -Wall -fomit-frame-pointer -fno-inline-functions -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Startup

clean-Startup:
	-$(RM) ./Startup/startup.cyclo ./Startup/startup.d ./Startup/startup.o ./Startup/startup.su

.PHONY: clean-Startup


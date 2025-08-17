################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_SRCS += \
../Port/Start_up.s 

OBJS += \
./Port/Start_up.o 

S_DEPS += \
./Port/Start_up.d 


# Each subdirectory must supply rules for building sources it contributes
Port/%.o: ../Port/%.s Port/subdir.mk
	arm-none-eabi-gcc -mcpu=cortex-m3 -g3 -DDEBUG -c -x assembler-with-cpp -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@" "$<"

clean: clean-Port

clean-Port:
	-$(RM) ./Port/Start_up.d ./Port/Start_up.o

.PHONY: clean-Port


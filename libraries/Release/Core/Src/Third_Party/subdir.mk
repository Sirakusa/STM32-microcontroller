################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/Third_Party/led.c 

OBJS += \
./Core/Src/Third_Party/led.o 

C_DEPS += \
./Core/Src/Third_Party/led.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/Third_Party/%.o Core/Src/Third_Party/%.su Core/Src/Third_Party/%.cyclo: ../Core/Src/Third_Party/%.c Core/Src/Third_Party/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -DUSE_HAL_DRIVER -DSTM32L476xx -c -I../Core/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-Third_Party

clean-Core-2f-Src-2f-Third_Party:
	-$(RM) ./Core/Src/Third_Party/led.cyclo ./Core/Src/Third_Party/led.d ./Core/Src/Third_Party/led.o ./Core/Src/Third_Party/led.su

.PHONY: clean-Core-2f-Src-2f-Third_Party


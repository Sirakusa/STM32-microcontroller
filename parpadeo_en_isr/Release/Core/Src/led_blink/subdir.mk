################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/led_blink/led_blink.c 

OBJS += \
./Core/Src/led_blink/led_blink.o 

C_DEPS += \
./Core/Src/led_blink/led_blink.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/led_blink/%.o Core/Src/led_blink/%.su Core/Src/led_blink/%.cyclo: ../Core/Src/led_blink/%.c Core/Src/led_blink/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -DUSE_HAL_DRIVER -DSTM32L476xx -c -I../Core/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-led_blink

clean-Core-2f-Src-2f-led_blink:
	-$(RM) ./Core/Src/led_blink/led_blink.cyclo ./Core/Src/led_blink/led_blink.d ./Core/Src/led_blink/led_blink.o ./Core/Src/led_blink/led_blink.su

.PHONY: clean-Core-2f-Src-2f-led_blink


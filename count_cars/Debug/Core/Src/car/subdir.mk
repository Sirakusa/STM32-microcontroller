################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/car/car.c 

OBJS += \
./Core/Src/car/car.o 

C_DEPS += \
./Core/Src/car/car.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/car/%.o Core/Src/car/%.su Core/Src/car/%.cyclo: ../Core/Src/car/%.c Core/Src/car/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L476xx -c -I../Core/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-car

clean-Core-2f-Src-2f-car:
	-$(RM) ./Core/Src/car/car.cyclo ./Core/Src/car/car.d ./Core/Src/car/car.o ./Core/Src/car/car.su

.PHONY: clean-Core-2f-Src-2f-car


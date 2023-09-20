#include "stm32l4xx_hal.h"
#include "delay_ms.h"
// variable defined in stm32f4xx_it .c
extern volatile uint32_t uwTick;

void delay_Init(void){
	// 1 milisecond per tick
	// SysTick_Config ( SystemCoreClock / 1000); // notacion CMSIS
	HAL_SYSTICK_Config(SystemCoreClock / 1000);
}

void delay_ms(uint32_t miliseconds){
	uint32_t ticks_end;
	ticks_end = uwTick + miliseconds ;

	while (uwTick < ticks_end) {};
}

uint32_t get_ValueTick(void){
	uint32_t valuetick;

	valuetick = uwTick;
	return valuetick;
}

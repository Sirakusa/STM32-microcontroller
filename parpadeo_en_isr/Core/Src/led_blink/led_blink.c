#include "led_blink.h"
#include "stm32l4xx_hal.h"

extern volatile uint32_t uwTick;
volatile uint32_t time_delay, next_delay = 0;

void HAL_IncTick(void){

	uwTick += (uint32_t)uwTickFreq;

	if (((uwTick - time_delay) >= 3000) && (next_delay == 0)) {
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5,0);
	  time_delay = uwTick;
	  next_delay = 1;
	}

	if (((uwTick - time_delay) >= 5000) && (next_delay == 1)) {
	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5,1);
	  time_delay = uwTick;
	  next_delay = 2;
	}

	if (((uwTick - time_delay) >= 3000) && (next_delay == 2)) {
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5,0);
	  time_delay = uwTick;
	  next_delay = 3;
	}

	if (((uwTick - time_delay) >= 8000) && (next_delay == 3)) {
	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5,1);
	  time_delay = uwTick;
	  next_delay = 0;
	}
}

void Init_Blink_Led(void){
	time_delay = uwTick;
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, 1);
}

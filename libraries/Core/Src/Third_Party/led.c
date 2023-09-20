#include "led.h"
#include "stm32l4xx_hal.h"

void Led_On(void){
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5,1);
}

void Led_Off(void){
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5,0);
}

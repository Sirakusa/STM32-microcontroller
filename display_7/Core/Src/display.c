#include "display.h"
#include "stm32l4xx_hal.h"

void Display_i(void){
	GPIO_InitTypeDef GPIO_InitStruct;

	GPIO_InitStruct.Pin = GPIO_PIN_0 | GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3 | GPIO_PIN_4 | GPIO_PIN_5 | GPIO_PIN_6;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_MEDIUM;
	HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);
}

void Reproduce_display(uint32_t out){
	GPIOB -> BSRR = (((~out) & 0x7F) << 16) | out;
}

void Display_Off(void){
	GPIOB -> ODR = 0x0000;
}







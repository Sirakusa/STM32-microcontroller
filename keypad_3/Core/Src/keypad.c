#include "keypad.h"
#include "stm32l4xx_hal.h"

void Keypad_Init_PULLUP(void){

	GPIO_InitTypeDef GPIOC_PULLUP;

	GPIOC_PULLUP.Pin = GPIO_PIN_0 | GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3;
	GPIOC_PULLUP.Mode = GPIO_MODE_INPUT;
	GPIOC_PULLUP.Pull = GPIO_PULLDOWN;
	GPIOC_PULLUP.Speed = GPIO_SPEED_FREQ_MEDIUM;
	HAL_GPIO_Init(GPIOC, &GPIOC_PULLUP);
}

void Keypad_Init_OUT(void){

	GPIO_InitTypeDef GPIOA_OUTPUT;

	GPIOA_OUTPUT.Pin = GPIO_PIN_0 | GPIO_PIN_1 | GPIO_PIN_4 | GPIO_PIN_9;
	GPIOA_OUTPUT.Mode = GPIO_MODE_OUTPUT_PP;
	GPIOA_OUTPUT.Pull = GPIO_NOPULL;
	GPIOA_OUTPUT.Speed = GPIO_SPEED_FREQ_MEDIUM;
	HAL_GPIO_Init(GPIOA, &GPIOA_OUTPUT);
}

uint16_t Keypad_Scan(void){

	uint8_t row,col = 4;
	uint16_t IDR_REGISTER;

	for(row = 0; row < 4;row++){

		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0 | GPIO_PIN_1 | GPIO_PIN_4 | GPIO_PIN_9,0);

		switch (row){
		case 0:
			HAL_GPIO_WritePin(GPIOA,GPIO_PIN_0,1);
			break;
		case 1:
			HAL_GPIO_WritePin(GPIOA,GPIO_PIN_1,1);
			break;
		case 2:
			HAL_GPIO_WritePin(GPIOA,GPIO_PIN_4,1);
			break;
		case 3:
			HAL_GPIO_WritePin(GPIOA,GPIO_PIN_9,1);
			break;
		}

		HAL_Delay(2);

		IDR_REGISTER = GPIOC -> IDR;

		IDR_REGISTER = IDR_REGISTER & 0x000F;

		switch(IDR_REGISTER){
		case 0x0001 :
			col = 0;
			break;
		case 0x0002 :
			col = 1;
			break;
		case 0x0004 :
			col = 2;
			break;
		case 0x0008 :
			col = 3;
			break;
		}

		if(col <  4){
			return keypad[row][col];
		}
	}
	return 1000;
}

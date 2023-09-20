#include "keypad.h"
#include "stm32l4xx_hal.h"

void Keypad_Init(void){

	GPIO_InitTypeDef GPIOB_PULLUP, GPIOB_OUTPUT;

	GPIOB_PULLUP.Pin = GPIO_PIN_0 | GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3;
	GPIOB_PULLUP.Mode = GPIO_MODE_INPUT;
	GPIOB_PULLUP.Pull = GPIO_PULLUP;
	GPIOB_PULLUP.Speed = GPIO_SPEED_FREQ_MEDIUM;
	HAL_GPIO_Init(GPIOB, &GPIOB_PULLUP);

	GPIOB_OUTPUT.Pin = GPIO_PIN_4 | GPIO_PIN_5 | GPIO_PIN_6 | GPIO_PIN_7;
	GPIOB_OUTPUT.Mode = GPIO_MODE_OUTPUT_PP;
	GPIOB_OUTPUT.Pull = GPIO_NOPULL;
	GPIOB_OUTPUT.Speed = GPIO_SPEED_FREQ_MEDIUM;
	HAL_GPIO_Init(GPIOB, &GPIOB_OUTPUT);
}

uint8_t Keypad_Scan(void){

	uint8_t i;
	uint16_t IDR_REGISTER;

	GPIOB -> ODR = 0x00F0;

	for(i = 0; i < 4;i++){

		GPIOB -> BSRR = (mask[i] << 20) | ((0x0F & (~mask[i])) << 4);


		IDR_REGISTER = GPIOB -> IDR;

		switch(IDR_REGISTER){
		case 0x0001 :
			return key_table[0][i];
			break;
		case 0x0002 :
			return key_table[1][i];
			break;
		case 0x0004 :
			return key_table[2][i];
			break;
		case 0x0008 :
			return key_table[3][i];
			break;
		}
	}

	return 0;
}

#include "stm32l4xx_hal.h"
#include "lavador.h"

void selector_Init(void){

GPIO_InitTypeDef port ;
	port.Pin = GPIO_PIN_12 | GPIO_PIN_11 | GPIO_PIN_10
				| GPIO_PIN_9 | GPIO_PIN_8 | GPIO_PIN_7
				| GPIO_PIN_6 | GPIO_PIN_5 | GPIO_PIN_4
				| GPIO_PIN_3 | GPIO_PIN_2 | GPIO_PIN_1 | GPIO_PIN_0;

	port.Mode = GPIO_MODE_INPUT;
	port.Pull = GPIO_PULLUP;
	HAL_GPIO_Init ( GPIOA ,&port);
}


TSelectorStatus selector_Read(void){
	uint16_t data ;
	TSelectorStatus value;
	data = GPIOA -> IDR;
	data = data & 0x0FFF;

	switch ( data ) {
	case 0x0FFE :
		value = SELECTOR_OFF;
		break;
	case 0x0FFD :
		value = SELECTOR_COTTON_1;
		break;
	case 0x0FFB :
		value = SELECTOR_COTTON_2;
		break;
	case 0x0FF7 :
		value = SELECTOR_SYNTHETIC;
		break;
	case 0x0FEF :
		value = SELECTOR_QUICK;
		break;
	case 0x0FDF :
		value = SELECTOR_DELICATE;
		break;
	case 0x0FBF :
		value = SELECTOR_WOOL;
		break;
	case 0x0F7F :
		value = SELECTOR_CARE;
		break;
	case 0x0EFF :
		value = SELECTOR_DESAGUE ;
		break;
	case 0x0DFF :
		value = SELECTOR_OFF ;
		break;
	case 0x0BFF :
		value = SELECTOR_SPIN_1 ;
		break;
	case 0x07FF :
		value = SELECTOR_SPIN_2 ;
		break;
	case 0x0FFF :
		value = SELECTOR_ACLARADO;
		break;
	default :
		value = SELECTOR_UNDEFINED;
		break;
	}
	return value ;
}

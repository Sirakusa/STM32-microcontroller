#include "stm32l4xx_hal.h"
#include "lavador.h"

void Led_Init(void){
	GPIO_InitTypeDef port_led;

	port_led.Pin = GPIO_PIN_8;
	port_led.Mode = GPIO_MODE_OUTPUT_PP;
	port_led.Pull = GPIO_NOPULL;
	port_led.Speed = GPIO_SPEED_FREQ_MEDIUM;
	HAL_GPIO_Init(GPIOB, &port_led);
}


void Led_On(TSelectorStatus status){

	for(TSelectorStatus i = SELECTOR_OFF; i <= status; i++){
		HAL_GPIO_TogglePin (GPIOB, GPIO_PIN_8);
		HAL_Delay(1000);
	}
	HAL_Delay(20000);
}

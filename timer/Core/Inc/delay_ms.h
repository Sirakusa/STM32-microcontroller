#ifndef DELAY_MS_H
#define DELAY_MS_H

#include <stdint.h>

void delay_Init(void);
void delay_ms(uint32_t miliseconds);
uint32_t get_ValueTick(void);

#endif

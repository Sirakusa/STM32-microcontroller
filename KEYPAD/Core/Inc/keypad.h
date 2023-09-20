#ifndef KEYPAD_H
#define KEYPAD_H

#include <stdint.h>

void Keypad_Init(void);

static const uint8_t key_table[4][4] =  {{'1', '2', '3', 'A'},
										 {'4', '5', '6', 'B'},
										 {'7', '8', '9', 'C'},
										 {'*', '0', '#', 'D'}};

static const uint8_t mask[4] = {0b00000001,0b00000010,0b00000100,0b00001000};

uint8_t Keypad_Scan(void);

#endif

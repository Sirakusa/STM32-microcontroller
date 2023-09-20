#ifndef KEYPAD_H
#define KEYPAD_H

#include <stdint.h>

void Keypad_Init_PULLUP(void);
void Keypad_Init_OUT(void);

static const uint16_t keypad[4][4] = {{49, 50, 51, 65},     // ASCII de '1', '2', '3', 'A'
									  {52, 53, 54, 66},     // ASCII de '4', '5', '6', 'B'
									  {55, 56, 57, 67},     // ASCII de '7', '8', '9', 'C'
									  {42, 48, 35, 68}};    // ASCII de '*', '0', '#', 'D'

uint16_t Keypad_Scan(void);

#endif

#ifndef DISPLAY_H
#define DISPLAY_H

#include <stdint.h>


static const uint8_t value_display[10] = {0x3F ,0x06 ,0x5B ,0x4F ,0x66 ,0x6D ,0x7D ,0x07 ,0x7F ,0x6F };

void Display_i(void);
void Reproduce_display(uint32_t out);
void Display_Off(void);

#endif

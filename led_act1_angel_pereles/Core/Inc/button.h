#ifndef BUTTON_H
#define BUTTON_H

#include <stdint.h>

void button_Init(void);
typedef enum {BUTTON_PRESSED ,BUTTON_RELEASED} TButtonState ;
TButtonState button_Read(void);

#endif

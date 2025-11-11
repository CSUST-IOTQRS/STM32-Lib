#ifndef __KEY_H
#define __KEY_H

#ifdef __cplusplus
extern "C" {
#endif

#include "stm32f1xx_hal.h"

void Key_Init(void);
uint8_t Key_GetNum(void);

#endif

#ifndef __TIMER_H
#define __TIMER_H

#ifdef __cplusplus
extern "C" {
#endif

#include "stm32f1xx_hal.h"

void Timer_Init(void);
uint16_t Timer_GetCounter(void);

#ifdef __cplusplus
}
#endif

#endif

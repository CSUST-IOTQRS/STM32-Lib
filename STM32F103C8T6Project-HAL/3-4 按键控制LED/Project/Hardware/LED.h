#ifndef __LED_H
#define __LED_H

#ifdef __cplusplus
extern "C" {
#endif

#include "stm32f1xx_hal.h"

void LED_Init(void);

void LED1_ON(void);
void LED1_OFF(void);
void LED1_Turn(void);

void LED2_ON(void);
void LED2_OFF(void);
void LED2_Turn(void);

#ifdef __cplusplus
}
#endif

#endif

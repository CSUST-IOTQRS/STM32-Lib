#ifndef __BUZZER_H
#define __BUZZER_H

#ifdef __cplusplus
extern "C" {
#endif

#include "stm32f1xx_hal.h"

void Buzzer_Init(void);

void Buzzer_ON(void);
void Buzzer_OFF(void);
void Buzzer_Turn(void);

#ifdef __cplusplus
}
#endif

#endif

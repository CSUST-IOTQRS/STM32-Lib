#ifndef __PWM_H
#define __PWM_H

#ifdef __cplusplus
extern "C" {
#endif
	
#include "stm32f1xx_hal.h"

void PWM_Init(void);
void PWM_SetCompare1(uint16_t Compare);
	
#ifdef __cplusplus
}
#endif

#endif

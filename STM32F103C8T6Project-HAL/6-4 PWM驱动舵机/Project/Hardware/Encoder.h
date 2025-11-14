#ifndef __ENCODER_H
#define __ENCODER_H

#ifdef __cplusplus
extern "C" {
#endif

#include "stm32f1xx.h"

void Encoder_Init(void);
int16_t Encoder_Get(void);

#ifdef __cplusplus
}
#endif

#endif

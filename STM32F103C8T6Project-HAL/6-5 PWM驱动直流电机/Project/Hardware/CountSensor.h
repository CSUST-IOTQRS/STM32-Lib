#ifndef __COUNT_SENSOR_H
#define __COUNT_SENSOR_H


#ifdef __cplusplus
extern "C" {
#endif

#include "stm32f1xx_hal.h"

void CountSensor_Init(void);
uint16_t CountSensor_Get(void);

#ifdef __cplusplus
}
#endif

#endif

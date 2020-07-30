#ifndef __VALUE_H_
#define __VALUE_H_
#include "main.h"
#include "stm32f1xx.h"
#include "adc.h"
#include "pd.h"
#include "led.h"

extern void adc_get_avg(uint8_t num,float *avg_value,uint8_t ch);

#endif

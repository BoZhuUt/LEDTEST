#ifndef __PD_H_
#define __PD_H_
#include "main.h"
#include "stm32f1xx.h"
#include "adc.h"

//#define PD_1SWITCH ADC_CHANNEL_10
//#define PD_2SWITCH ADC_CHANNEL_11
//#define PD_3SWITCH ADC_CHANNEL_12
//#define PD_4SWITCH ADC_CHANNEL_13
//#define PD_5SWITCH ADC_CHANNEL_14
//#define PD_6SWITCH ADC_CHANNEL_15
//#define PD_7SWITCH ADC_CHANNEL_8
//#define PD_8SWITCH ADC_CHANNEL_9
//#define PD_9SWITCH ADC_CHANNEL_0
//#define PD_10SWITCH ADC_CHANNEL_6

/*
enum
{
	PD_1SWITCH = ADC_CHANNEL_10,
	PD_2SWITCH = ADC_CHANNEL_11,
	PD_3SWITCH = ADC_CHANNEL_12,
	PD_4SWITCH = ADC_CHANNEL_13,
	PD_5SWITCH = ADC_CHANNEL_14,
	PD_6SWITCH = ADC_CHANNEL_15,
	PD_7SWITCH = ADC_CHANNEL_8,
	PD_8SWITCH = ADC_CHANNEL_9,
	PD_9SWITCH = ADC_CHANNEL_0,
	PD_10SWITCH = ADC_CHANNEL_6,	
};
*/
//void PD_SWITCH(uint8_t ch);
float Get_ADC_volage(uint16_t n);
uint32_t Get_PD_Vol(void);



#endif
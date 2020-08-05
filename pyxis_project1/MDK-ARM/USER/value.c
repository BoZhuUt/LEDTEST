#include "value.h"

//extern void adc_get_avg(uint8_t num,float *avg_value,uint8_t ch)//得出来的是num次对应通道转换的数据多次采样求平均，首先是不是要得出来值
//{
//	int sum = 0;
//	HAL_ADC_Stop(&hadc1);
//	PD_SWITCH(ch);//这里就能选择相应的PD对应的ADC通道；并且配置
//	HAL_ADC_Start(&hadc1);
//#if 0
//	HAL_ADC_PollForConversion(&hadc1,10);//转换时间不能超过10ms，否则。。。 
//	
//	if(HAL_IS_BIT_SET(HAL_ADC_GetState(&hadc1), HAL_ADC_STATE_REG_EOC))//这里判断的是转换完成，转换完成后才能读出值来
//	{
//		for(uint8_t i=0;i<num;i++)
//		{
//			sum+=HAL_ADC_GetValue(&hadc1);//这里的是12位。
//		}
//	}
//	avg_value[ch]=sum/num;
//#else 

//	for(uint8_t i = 0; i < num; i++)
//	{
//		HAL_ADC_PollForConversion(&hadc1,10);
//		if((HAL_ADC_GetState(&hadc1) & HAL_ADC_STATE_REG_EOC) == HAL_ADC_STATE_REG_EOC)
//		{
//			sum += HAL_ADC_GetValue(&hadc1);
//		}
//	}
//	*(avg_value + ch) = (float)sum/num*3.3/4095;
//	
//#endif
//}
////首先是LED，和PD进行选择，选择完PD之后，就要开启相应的通道（配置相应的通道目的是让他将模拟信号进行转换AD）那么就要打开

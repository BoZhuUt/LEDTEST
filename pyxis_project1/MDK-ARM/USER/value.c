#include "value.h"

//extern void adc_get_avg(uint8_t num,float *avg_value,uint8_t ch)//�ó�������num�ζ�Ӧͨ��ת�������ݶ�β�����ƽ���������ǲ���Ҫ�ó���ֵ
//{
//	int sum = 0;
//	HAL_ADC_Stop(&hadc1);
//	PD_SWITCH(ch);//�������ѡ����Ӧ��PD��Ӧ��ADCͨ������������
//	HAL_ADC_Start(&hadc1);
//#if 0
//	HAL_ADC_PollForConversion(&hadc1,10);//ת��ʱ�䲻�ܳ���10ms�����򡣡��� 
//	
//	if(HAL_IS_BIT_SET(HAL_ADC_GetState(&hadc1), HAL_ADC_STATE_REG_EOC))//�����жϵ���ת����ɣ�ת����ɺ���ܶ���ֵ��
//	{
//		for(uint8_t i=0;i<num;i++)
//		{
//			sum+=HAL_ADC_GetValue(&hadc1);//�������12λ��
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
////������LED����PD����ѡ��ѡ����PD֮�󣬾�Ҫ������Ӧ��ͨ����������Ӧ��ͨ��Ŀ����������ģ���źŽ���ת��AD����ô��Ҫ��

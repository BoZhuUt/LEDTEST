#include "pd.h"
#include "stdint.h"
//void PD_SWITCH(uint8_t ch)//如果选用对应的PD，那么其对应的adc1通道就会开启,继而开始进行AD转换
//{
//	switch(ch)
//	{
//		case 0:
//			vADCSwitchCH(PD_1SWITCH);//这个就是选择通道1
//			break;
//		case 1:
//			vADCSwitchCH(PD_2SWITCH);//这个就是选择通道2
//			break;
//		case 2:
//			vADCSwitchCH(PD_3SWITCH);//这个就是选择通道3
//			break;
//		case 3:
//			vADCSwitchCH(PD_4SWITCH);//这个就是选择通道4
//			break;
//		case 4:
//			vADCSwitchCH(PD_5SWITCH);//这个就是选择通道5
//			break;
//		case 5:
//			vADCSwitchCH(PD_6SWITCH);//这个就是选择通道6
//			break;
//		case 6:
//			vADCSwitchCH(PD_7SWITCH);//这个就是选择通道7
//			break;
//		case 7:
//			vADCSwitchCH(PD_8SWITCH);//这个就是选择通道8
//			break;
//		case 8:
//			vADCSwitchCH(PD_9SWITCH);//这个就是选择通道9
//			break;
//		case 9:
//			vADCSwitchCH(PD_10SWITCH);//这个就是选择通道10
//			break;
//	  default:
//			break;
//	}

//}
//这里只使用了一个通道
//ADC_HandleTypeDef hadc1;
uint32_t Get_PD_Vol(void)
{
	uint16_t vol;
	HAL_ADC_Stop(&hadc1);
	__NOP();
	__NOP();
	HAL_ADC_Start(&hadc1);
	HAL_ADC_PollForConversion(&hadc1,10);
	vol=HAL_ADC_GetValue(&hadc1);
	return vol;
}

//得到ADC的十二位数据，之后进行数据的转换
float Get_ADC_volage(uint16_t n)
{
	uint32_t sum=0;
	int i;
	for(i=0;i<n;i++)
	{
		sum+=Get_PD_Vol();
	}
	sum/=n;
	float aveADC=(float)sum/4096*3.3;
	return aveADC;
}


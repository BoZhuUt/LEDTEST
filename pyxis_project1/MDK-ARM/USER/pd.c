#include "pd.h"
#include "stdint.h"
//void PD_SWITCH(uint8_t ch)//���ѡ�ö�Ӧ��PD����ô���Ӧ��adc1ͨ���ͻῪ��,�̶���ʼ����ADת��
//{
//	switch(ch)
//	{
//		case 0:
//			vADCSwitchCH(PD_1SWITCH);//�������ѡ��ͨ��1
//			break;
//		case 1:
//			vADCSwitchCH(PD_2SWITCH);//�������ѡ��ͨ��2
//			break;
//		case 2:
//			vADCSwitchCH(PD_3SWITCH);//�������ѡ��ͨ��3
//			break;
//		case 3:
//			vADCSwitchCH(PD_4SWITCH);//�������ѡ��ͨ��4
//			break;
//		case 4:
//			vADCSwitchCH(PD_5SWITCH);//�������ѡ��ͨ��5
//			break;
//		case 5:
//			vADCSwitchCH(PD_6SWITCH);//�������ѡ��ͨ��6
//			break;
//		case 6:
//			vADCSwitchCH(PD_7SWITCH);//�������ѡ��ͨ��7
//			break;
//		case 7:
//			vADCSwitchCH(PD_8SWITCH);//�������ѡ��ͨ��8
//			break;
//		case 8:
//			vADCSwitchCH(PD_9SWITCH);//�������ѡ��ͨ��9
//			break;
//		case 9:
//			vADCSwitchCH(PD_10SWITCH);//�������ѡ��ͨ��10
//			break;
//	  default:
//			break;
//	}

//}
//����ֻʹ����һ��ͨ��
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

//�õ�ADC��ʮ��λ���ݣ�֮��������ݵ�ת��
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


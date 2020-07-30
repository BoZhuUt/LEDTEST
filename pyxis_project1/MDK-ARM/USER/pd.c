#include "pd.h"

void PD_SWITCH(uint8_t ch)//如果选用对应的PD，那么其对应的adc1通道就会开启,继而开始进行AD转换
{
	switch(ch)
	{
		case 0:
			vADCSwitchCH(PD_1SWITCH);//这个就是选择通道1
			break;
		case 1:
			vADCSwitchCH(PD_2SWITCH);//这个就是选择通道2
			break;
		case 2:
			vADCSwitchCH(PD_3SWITCH);//这个就是选择通道3
			break;
		case 3:
			vADCSwitchCH(PD_4SWITCH);//这个就是选择通道4
			break;
		case 4:
			vADCSwitchCH(PD_5SWITCH);//这个就是选择通道5
			break;
		case 5:
			vADCSwitchCH(PD_6SWITCH);//这个就是选择通道6
			break;
		case 6:
			vADCSwitchCH(PD_7SWITCH);//这个就是选择通道7
			break;
		case 7:
			vADCSwitchCH(PD_8SWITCH);//这个就是选择通道8
			break;
		case 8:
			vADCSwitchCH(PD_9SWITCH);//这个就是选择通道9
			break;
		case 9:
			vADCSwitchCH(PD_10SWITCH);//这个就是选择通道10
			break;
	  default:
			break;
	}

}
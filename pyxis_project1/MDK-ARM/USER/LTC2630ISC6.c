/**
  ******************************************************************************
  * @file    LTC2630ISC6.h
  * @author  Zhibin.Wen
  * @version V1.0
  * @date    2020-7-16
  * @brief   
  ******************************************************************************
  * @attention
  *
  *  
  ******************************************************************************
  */ 
#include "LTC2630ISC6.h"
//已经有了IO口的初始化配置，因此不需写 LTC2630ISC6的GPIO初始化函数
//第一个时钟是先把有效命令送进去
void dacWriteByte(uint8_t byte)//这里一次向DAC写入一个字节(这里是先把最高位放进去)
{
	uint8_t i;
	//给出时钟的上升沿才能发送一个字节
	SPI_CLOCK_LOW;
	for(i=0;i<8;i++)
	{
		if(byte&(0x80>>i))
		{
				SPI_MASTER_OUT_BB_HIGH;
		}
		else
		{
				SPI_MASTER_OUT_BB_LOW;
		}
		SPI_CLOCK_HIGH;
		HAL_Delay(5);
		SPI_CLOCK_LOW;
		HAL_Delay(5);
	}
}
void write_to_LTC2630ISC6(uint8_t Cmd,uint16_t Data)//这里一定要使能2630(因为是12位的DAC)//就看给出
{
		if(Data>4095)
		{
			Data=4095;
		}
		Data<<=4;
		DAC_CS_LOW;//使能端是低电平有效
		dacWriteByte(Cmd);
		dacWriteByte(Data>>8);//高八位之前的数据是0
		dacWriteByte(Data|0x00ff);
		DAC_CS_HIGH;
}

void LTC2630ISC6_init(void)
{
	 //LTC2630ISC6_GPIO_INIT();
	 write_to_LTC2630ISC6(0X60,0); //select internal reference(power-on reset default)
	 write_to_LTC2630ISC6(0X30,1000); //write to and update(power up)DAC register, 1000/4095*2.5=0.61v
}
//HAL_SPI_Transmit
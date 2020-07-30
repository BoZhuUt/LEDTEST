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
//�Ѿ�����IO�ڵĳ�ʼ�����ã���˲���д LTC2630ISC6��GPIO��ʼ������
//��һ��ʱ�����Ȱ���Ч�����ͽ�ȥ
void dacWriteByte(uint8_t byte)//����һ����DACд��һ���ֽ�(�������Ȱ����λ�Ž�ȥ)
{
	uint8_t i;
	//����ʱ�ӵ������ز��ܷ���һ���ֽ�
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
void write_to_LTC2630ISC6(uint8_t Cmd,uint16_t Data)//����һ��Ҫʹ��2630(��Ϊ��12λ��DAC)//�Ϳ�����
{
		if(Data>4095)
		{
			Data=4095;
		}
		Data<<=4;
		DAC_CS_LOW;//ʹ�ܶ��ǵ͵�ƽ��Ч
		dacWriteByte(Cmd);
		dacWriteByte(Data>>8);//�߰�λ֮ǰ��������0
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
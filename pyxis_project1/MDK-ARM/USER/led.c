#include "led.h"

//是把是个LED挨个拿出来测
void LED_SWITCH(uint8_t num)
{
	switch(num)
	{
		case 0:
			LED_SWITCH1_ON;
			LED_SWITCH2_OFF;
			LED_SWITCH3_OFF;
			LED_SWITCH4_OFF;
			LED_SWITCH5_OFF;
			LED_SWITCH6_OFF;
			break;
		case 1:
			LED_SWITCH1_ON;
			LED_SWITCH2_OFF;
			LED_SWITCH3_OFF;
			LED_SWITCH4_ON;
			LED_SWITCH5_OFF;
			LED_SWITCH6_OFF;
			break;
		case 2:
			LED_SWITCH1_ON;
			LED_SWITCH2_OFF;
			LED_SWITCH3_ON;
			LED_SWITCH4_OFF;
			LED_SWITCH5_OFF;
			LED_SWITCH6_OFF;
			break;
		case 3:
			LED_SWITCH1_ON;
			LED_SWITCH2_OFF;
			LED_SWITCH3_ON;
			LED_SWITCH4_ON;
			LED_SWITCH5_OFF;
			LED_SWITCH6_OFF;
			break;
		case 4:
			LED_SWITCH1_ON;
			LED_SWITCH2_ON;
			LED_SWITCH3_OFF;
			LED_SWITCH4_OFF;
			LED_SWITCH5_OFF;
			LED_SWITCH6_OFF;
			break;
		case 5:
			LED_SWITCH1_ON;
			LED_SWITCH2_ON;
			LED_SWITCH3_OFF;
			LED_SWITCH4_ON;
			LED_SWITCH5_OFF;
			LED_SWITCH6_OFF;
			break;
		case 6:
			LED_SWITCH1_ON;
			LED_SWITCH2_ON;
			LED_SWITCH3_ON;
			LED_SWITCH4_OFF;
			LED_SWITCH5_OFF;
			LED_SWITCH6_OFF;
			break;
		case 7:
			LED_SWITCH1_ON;
			LED_SWITCH2_ON;
			LED_SWITCH3_ON;
			LED_SWITCH4_ON;
			LED_SWITCH5_OFF;
			LED_SWITCH6_OFF;
			break;
		case 8:
			LED_SWITCH1_OFF;
			LED_SWITCH2_OFF;
			LED_SWITCH3_OFF;
			LED_SWITCH4_OFF;
			LED_SWITCH5_ON;
			LED_SWITCH6_OFF;
			break;
		case 9:
			LED_SWITCH1_OFF;
			LED_SWITCH2_OFF;
			LED_SWITCH3_OFF;
			LED_SWITCH4_OFF;
			LED_SWITCH5_ON;
			LED_SWITCH6_ON;
			break;
	}
	
}

void TURN_OFF_LED(void)
{
	LED_SWITCH1_OFF;
	LED_SWITCH5_OFF;
}
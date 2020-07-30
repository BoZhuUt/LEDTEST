/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "adc.h"
#include "spi.h"
#include "usart.h"
#include "gpio.h"
#include "led.h"
#include "LTC2630ISC6.h"
#include "value.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */
	uint8_t i;
	float avg_value[10];
  /* USER CODE END 1 */
	
  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */
	LTC2630ISC6_init();
	HAL_ADC_MspInit(&hadc1);
  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  //MX_ADC1_Init();
 // MX_SPI1_Init();
  MX_USART2_UART_Init();
 // MX_USART1_UART_Init();
  /* USER CODE BEGIN 2 */
//	HAL_SPI_MspInit(&hspi1);
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
	write_to_LTC2630ISC6(0x30,2000);		
  while (1)
  {
    /* USER CODE END WHILE */
//		for(i=8;i<10;i++)
//		{
//			LED_SWITCH(i);
////			PD_SWITCH(i);
////			HAL_Delay(10);
//			
////			adc_get_avg(5,avg_value,i);
//			HAL_Delay(500);
//			//TURN_OFF_LED();
//		}
		LED_SWITCH(8);
		HAL_Delay(500);
		LED_SWITCH(9);
		HAL_Delay(500);
    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

//uint8_t HAL_IS_BIT_SET 
//#define HAL_IS_BIT_SET(x , y) ()

//uint16_t vTest(void)
//{
//	uint16_t AD_Value = 0;
//	HAL_ADC_Start(&hadc1);
//	HAL_ADC_PollForConversion(&hadc1,10);    //等待转换完成，第二个参数表示超时时间，单位ms        
////	if(HAL_IS_BIT_SET(HAL_ADC_GetState(&hadc1), HAL_ADC_STATE_REG_EOC))
////	{
////			AD_Value = HAL_ADC_GetValue(&hadc1);
////	}   
//	do
//	{
//		__NOP();
//	}while(HAL_IS_BIT_SET(HAL_ADC_GetState(&hadc1), HAL_ADC_STATE_REG_EOC) == RESET);
//	AD_Value = HAL_ADC_GetValue(&hadc1);
//  return AD_Value;						
//}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};
  RCC_PeriphCLKInitTypeDef PeriphClkInit = {0};

  /** Initializes the CPU, AHB and APB busses clocks 
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV1;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL9;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB busses clocks 
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
  PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_ADC;
  PeriphClkInit.AdcClockSelection = RCC_ADCPCLK2_DIV6;
  if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */

  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{ 
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     tex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/


///*##-2- Configure ADC regular channel ######################################*/  
//  sConfig.Channel      = ADCx_CHANNEL;
//  sConfig.Rank         = 1;
//  sConfig.SamplingTime = ADC_SAMPLETIME_3CYCLES;
//  sConfig.Offset       = 0;
//  
//  if(HAL_ADC_ConfigChannel(&AdcHandle, &sConfig) != HAL_OK)
//  {
//    /* Channel Configuration Error */
//    Error_Handler();
//  }
//  

//  /*##-3- Start the conversion process #######################################*/  
//  if(HAL_ADC_Start(&AdcHandle) != HAL_OK)
//  {
//    /* Start Conversation Error */
//    Error_Handler();
//  }
//  
//  /*##-4- Wait for the end of conversion #####################################*/  
//   /*  Before starting a new conversion, you need to check the current state of 
//        the peripheral; if it抯 busy you need to wait for the end of current
//        conversion before starting a new one.
//        For simplicity reasons, this example is just waiting till the end of the 
//        conversion, but application may perform other tasks while conversion 
//        operation is ongoing. */
//  HAL_ADC_PollForConversion(&AdcHandle, 10);
//  
//  /* Check if the continuous conversion of regular channel is finished */
//  if((HAL_ADC_GetState(&AdcHandle) & HAL_ADC_STATE_EOC_REG) == HAL_ADC_STATE_EOC_REG)
//  {
//    /*##-5- Get the converted value of regular channel #######################*/
//    uhADCxConvertedValue = HAL_ADC_GetValue(&AdcHandle);
//  }

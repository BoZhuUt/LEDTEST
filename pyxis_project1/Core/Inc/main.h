/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define ADC_IN_1_Pin GPIO_PIN_0
#define ADC_IN_1_GPIO_Port GPIOC
#define ADC_IN_2_Pin GPIO_PIN_1
#define ADC_IN_2_GPIO_Port GPIOC
#define ADC_IN_3_Pin GPIO_PIN_2
#define ADC_IN_3_GPIO_Port GPIOC
#define ADC_IN_4_Pin GPIO_PIN_3
#define ADC_IN_4_GPIO_Port GPIOC
#define ADC_IN_9_Pin GPIO_PIN_0
#define ADC_IN_9_GPIO_Port GPIOA
#define RTS_DE_Pin GPIO_PIN_1
#define RTS_DE_GPIO_Port GPIOA
#define TXD_Pin GPIO_PIN_2
#define TXD_GPIO_Port GPIOA
#define RXD_Pin GPIO_PIN_3
#define RXD_GPIO_Port GPIOA
#define DAC_2630_CS_Pin GPIO_PIN_4
#define DAC_2630_CS_GPIO_Port GPIOA
#define SPI1_CLK_2630_Pin GPIO_PIN_5
#define SPI1_CLK_2630_GPIO_Port GPIOA
#define ADC_IN_10_Pin GPIO_PIN_6
#define ADC_IN_10_GPIO_Port GPIOA
#define SPI1_MOSI_2630_Pin GPIO_PIN_7
#define SPI1_MOSI_2630_GPIO_Port GPIOA
#define ADC_IN_5_Pin GPIO_PIN_4
#define ADC_IN_5_GPIO_Port GPIOC
#define ADC_IN_6_Pin GPIO_PIN_5
#define ADC_IN_6_GPIO_Port GPIOC
#define ADC_IN_7_Pin GPIO_PIN_0
#define ADC_IN_7_GPIO_Port GPIOB
#define ADC_IN_8_Pin GPIO_PIN_1
#define ADC_IN_8_GPIO_Port GPIOB
#define LED_SWITCH1_Pin GPIO_PIN_2
#define LED_SWITCH1_GPIO_Port GPIOB
#define LED_SWITCH2_Pin GPIO_PIN_3
#define LED_SWITCH2_GPIO_Port GPIOB
#define LED_SWITCH3_Pin GPIO_PIN_4
#define LED_SWITCH3_GPIO_Port GPIOB
#define LED_SWITCH4_Pin GPIO_PIN_5
#define LED_SWITCH4_GPIO_Port GPIOB
#define LED_SWITCH5_Pin GPIO_PIN_6
#define LED_SWITCH5_GPIO_Port GPIOB
#define LED_SWITCH6_Pin GPIO_PIN_7
#define LED_SWITCH6_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/

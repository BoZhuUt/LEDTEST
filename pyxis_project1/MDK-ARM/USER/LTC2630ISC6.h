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

#ifndef __LTC2630ISC6_H__
#define __LTC2630ISC6_H__
#include "stm32f1xx.h"
#include "main.h"
#include "gpio.h"

void LTC2630ISC6_init(void);
void write_to_LTC2630ISC6(uint8_t Cmd, uint16_t Dat);
void dacWriteByte(uint8_t byte);

#define DAC_CS_HIGH                 HAL_GPIO_WritePin(DAC_2630_CS_GPIO_Port,DAC_2630_CS_Pin,GPIO_PIN_SET);
#define DAC_CS_LOW                  HAL_GPIO_WritePin(DAC_2630_CS_GPIO_Port,DAC_2630_CS_Pin,GPIO_PIN_RESET);

#define SPI_MASTER_OUT_BB_HIGH      HAL_GPIO_WritePin(SPI1_MOSI_2630_GPIO_Port,SPI1_MOSI_2630_Pin,GPIO_PIN_SET);
#define SPI_MASTER_OUT_BB_LOW       HAL_GPIO_WritePin(SPI1_MOSI_2630_GPIO_Port,SPI1_MOSI_2630_Pin,GPIO_PIN_RESET);

#define SPI_CLOCK_HIGH              HAL_GPIO_WritePin(SPI1_CLK_2630_GPIO_Port,SPI1_CLK_2630_Pin,GPIO_PIN_SET);
#define SPI_CLOCK_LOW               HAL_GPIO_WritePin(SPI1_CLK_2630_GPIO_Port,SPI1_CLK_2630_Pin,GPIO_PIN_RESET);


#endif
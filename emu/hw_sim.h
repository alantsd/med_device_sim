// Author: Alan Sing Teik, 2025
// function: HW register emulation layer
// Emulating typical STM32 MCU

#ifndef HW_SIM_H
#define HW_SIM_H

#include <cstdint>

typedef enum 
{
  HAL_OK       = 0x00U,
  HAL_ERROR    = 0x01U,
  HAL_BUSY     = 0x02U,
  HAL_TIMEOUT  = 0x03U
} HAL_StatusTypeDef;

struct ADC_HandleTypeDef
{
	volatile uint32_t value; // 24-bit ADC value
};

struct DAC_HandleTypeDef
{
	volatile uint32_t value; // 24-bit DAC value
};

extern ADC_HandleTypeDef hadc1;
extern ADC_HandleTypeDef hadc2;
extern DAC_HandleTypeDef hdac1;

void				HAL_Init();
void				HAL_Delay(uint32_t);
void				SystemClock_Config();
void				MX_GPIO_Init();
void				MX_ADC1_Init();
void				MX_ADC2_Init();
void				HAL_ADC_Start(ADC_HandleTypeDef* handle);
HAL_StatusTypeDef 	HAL_ADC_PollForConversion(ADC_HandleTypeDef* handle, uint32_t timeout);
uint32_t			HAL_ADC_GetValue(ADC_HandleTypeDef* handle);

#endif //HW_SIM_H
#include <random>
#include <cstdint>

#include "hw_sim.h"

ADC_HandleTypeDef hadc1;
ADC_HandleTypeDef hadc2;
DAC_HandleTypeDef hdac1;

void HAL_Init()
{
}

void SystemClock_Config()
{
}

void MX_GPIO_Init()
{
}

void MX_ADC1_Init()
{
}

void MX_ADC2_Init()
{
}

uint32_t HAL_ADC_GetValue(ADC_HandleTypeDef* handle)
{
	static std::mt19937 rng{std::random_device{}()};
	static std::uniform_int_distribution<int> delta(-10, 10);
	return delta(rng) + handle->value;
}

void HAL_Delay(uint32_t)
{
}

void HAL_ADC_Start(ADC_HandleTypeDef* handle)
{
}

HAL_StatusTypeDef HAL_ADC_PollForConversion(ADC_HandleTypeDef* handle, uint32_t timeout)
{
	return HAL_OK;
}

void HAL_DAC_SetValue(DAC_HandleTypeDef* handle, uint32_t value)
{
	handle->value = value;
}
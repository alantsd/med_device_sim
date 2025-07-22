// Author: Alan Sing Teik, 2025
// function: Application layer

#ifndef TEMPERATURE_CONTROLLER_H
#define TEMPERATURE_CONTROLLER_H

#include <iomanip>

#include "hw_sim.h"
#include "rtos_sim.h"
#include "sensor_data.h"
#include "controller.h"

class TemperatureSensorController_t : public Controller_t
{
public:
	uint32_t getTemperature()
	{
		std::optional<uint32_t> result = TemperatureSensorBuffer.pop();
		if(result.has_value())
			return result.value();

		return 0;
	}
	virtual uint32_t getData() override
	{
		return getTemperature();
	}
	void run() override
	{
		HAL_StatusTypeDef hal_error = HAL_ADC_PollForConversion(&hadc1, 0);
		if(HAL_OK == hal_error)
		{
			uint32_t temperature_adc_value = HAL_ADC_GetValue(&hadc1);
			TemperatureSensorBuffer.push(temperature_adc_value);
		}
	}
};

#endif //TEMPERATURE_CONTROLLER_H
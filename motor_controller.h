// Author: Alan Sing Teik, 2025
// function: Application layer

#ifndef MOTOR_CONTROLLER_H
#define MOTOR_CONTROLLER_H

#include <iomanip>

#include "hw_sim.h"
#include "rtos_sim.h"
#include "sensor_data.h"
#include "controller.h"

class MotorController_t : public Controller_t
{
public:
	uint32_t getSpeed()
	{
		std::optional<uint32_t> result = MotorSensorBuffer.pop();
		if(result.has_value())
			return result.value();

		return 0;
	}
	void setSpeed(uint32_t rpm)
	{
		hdac1.value = rpm;
	}
	virtual uint32_t getData() override
	{
		return getSpeed();
	}
	void run() override
	{
		HAL_StatusTypeDef hal_error = HAL_ADC_PollForConversion(&hadc2, 0);
		if(HAL_OK == hal_error)
		{
			uint32_t motor_adc_value = HAL_ADC_GetValue(&hadc2);
			MotorSensorBuffer.push(motor_adc_value);
		}
	}
};

#endif //MOTOR_CONTROLLER_H
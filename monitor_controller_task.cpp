// Author: Alan Sing Teik, 2025
// function: Aplication layer

#include <iomanip>

#include "hw_sim.h"
#include "rtos_sim.h"
#include "sensor_data.h"
#include "monitor_controller.h"

TemperatureSensorController_t	tc1;
MotorController_t				mc1;
MonitorController_t				m1(tc1, mc1);

Task temperature_sensor_task()
{
	MX_GPIO_Init();
	MX_ADC1_Init();

	// Start temp sensor ADC Conversion
	HAL_ADC_Start(&hadc1);

	//uint32_t run = 0;
	while(1)
	{
		//Read temperature sensor ADC
		vTaskDelay(200ms);
		//std::cout << __func__ << " " << ++run << "\n";
		tc1.run();
	}
}

Task motor_speed_sensor_task()
{
	MX_GPIO_Init();
	MX_ADC2_Init();

	// Start motor ADC Conversion
	HAL_ADC_Start(&hadc2);

	//uint32_t run = 0;
	while(1)
	{
		vTaskDelay(500ms);
		//std::cout << __func__ << " " << ++run << "\n";
		mc1.run();
	}
}

Task monitor_controller_task()
{
	while(1)
	{
		vTaskDelay(900ms);
		m1.run();
	}
}

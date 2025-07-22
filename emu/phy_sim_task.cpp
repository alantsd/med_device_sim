// Author: Alan Sing Teik, 2025
// function: Physical emulation layer
// This manage emulating what is at the connected at PCB
// emulating their function like motor response, wire connection
// ADC sampling pin voltage level

#include "hw_sim.h"
#include "rtos_sim.h"

#define		AVERAGE_TEMPERATURE_SENSOR_ADC_VALUE		30
#define		AVERAGE_MOTOR_SENSOR_ADC_VALUE				2000


Task sim_phy_task()
{
	hadc1.value = AVERAGE_TEMPERATURE_SENSOR_ADC_VALUE;
	hadc2.value = AVERAGE_MOTOR_SENSOR_ADC_VALUE;
	hdac1.value = AVERAGE_MOTOR_SENSOR_ADC_VALUE;

	while(1)
    {
		//std::cout << __func__ << "\n";
		vTaskDelay(500ms);

		// Motor is controlled by DAC1, it's speed is sensed via ADC2
		hadc2.value = hdac1.value;
	}
}
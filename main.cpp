#include <stdio.h>
#include "hw_sim.h"
#include "rtos_sim.h"
#include "phy_sim_task.h"
#include "sensor_task.h"
#include "monitor_controller_task.h"
 
 #define tskIDLE_PRIORITY	0
 #define STACK_SIZE			0
 
int main(int argc, char **argv)
{
	HAL_Init();
	SystemClock_Config();

	TaskHandle_t T1_handle;
	xTaskCreate( sim_phy_task,            "phy sim    ", STACK_SIZE, NULL, tskIDLE_PRIORITY, &T1_handle );

	TaskHandle_t T2_handle;
	xTaskCreate( temperature_sensor_task, "Temperature", STACK_SIZE, NULL, tskIDLE_PRIORITY, &T2_handle );
	
	TaskHandle_t T3_handle;
	xTaskCreate( motor_speed_sensor_task, "Motor Speed", STACK_SIZE, NULL, tskIDLE_PRIORITY, &T3_handle );

	TaskHandle_t T4_handle;
	xTaskCreate( monitor_controller_task, "Monitor    ", STACK_SIZE, NULL, tskIDLE_PRIORITY, &T4_handle );

	vTaskResume(T1_handle);
	vTaskResume(T2_handle);
	vTaskResume(T3_handle);
	vTaskResume(T4_handle);

	vTaskStartScheduler();

	return 0;
}

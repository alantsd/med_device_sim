// Author: Alan Sing Teik, 2025
// function: middleware layer
// OS task to collect sensor data

#ifndef SENSOR_TASK_H
#define SENSOR_TASK_H

#include "rtos_sim.h"

Task temperature_sensor_task();
Task motor_speed_sensor_task();


#endif //SENSOR_TASK_H
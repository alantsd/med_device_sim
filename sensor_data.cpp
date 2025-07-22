// Author: Alan Sing Teik, 2025
// Middleware layer
// function: intantiotion for sensor data
//

#include "sensor_data.h"

CircularBuffer_t<uint32_t, 100> 	TemperatureSensorBuffer;
CircularBuffer_t<uint32_t, 100> 	MotorSensorBuffer;

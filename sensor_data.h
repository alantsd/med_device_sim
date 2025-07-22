// Author: Alan Sing Teik, 2025
// Middleware layer
// function: foward declation for sensor data

#include <cstdint>

#include "circular_buffer.h"

extern CircularBuffer_t<uint32_t, 100> 	TemperatureSensorBuffer;
extern CircularBuffer_t<uint32_t, 100> 	MotorSensorBuffer;
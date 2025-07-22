// Author: Alan Sing Teik, 2025
// function: Application layer
#ifndef MONITOR_CONTROLLER_H
#define MONITOR_CONTROLLER_H

#include <iomanip>

#include "hw_sim.h"
#include "rtos_sim.h"
#include "sensor_data.h"
#include "temperature_sensor_controller.h"
#include "motor_controller.h"

class MonitorController_t : public Controller_t
{
	Controller_t& m_c1;
	Controller_t& m_c2;

public:
	MonitorController_t(Controller_t& c1, Controller_t& c2)
	: m_c1(c1), m_c2(c2)
	{
	}
	virtual uint32_t getData() override
	{
		return 0;
	}
	void run() override
	{
		auto now = std::chrono::system_clock::now();
		std::time_t now_c = std::chrono::system_clock::to_time_t(now);
		std::tm local_tm = *std::localtime(&now_c);

		std::cout 
		<< "[Time: "
		<< std::put_time(&local_tm, "%H:%M:%S")
		<< "] "
		<< "Temperature: "   << m_c1.getData() << " C "
		<< "| Motor Speed: " << m_c2.getData()       << " RPM"
		<< "\n";
	}
};

#endif //MONITOR_CONTROLLER_H
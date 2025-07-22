
#include <vector>
#include "rtos_sim.h"

std::vector<BlockedTask> task_list;

void TimeoutAwaitable::await_suspend(std::coroutine_handle<> h) const
{
	task_list.push_back({h, std::chrono::steady_clock::now() + timeout});
}

void vTaskResume( TaskHandle_t xTaskToResume )
{
	xTaskToResume.resume();
}

//Resume tasks if deadline is exceeded
void vTaskStartScheduler()
{
	while (true)
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
		auto now = std::chrono::steady_clock::now();
		//auto since_start = now.time_since_epoch();
		//auto millis = std::chrono::duration_cast<std::chrono::milliseconds>(since_start).count();
		//std::cout << millis << " scanning overdue task, task count:" << task_list.size() << "\n" ;
		for (auto it = task_list.begin(); it != task_list.end();) 
		{
			//auto target = it->deadline.time_since_epoch();
			//auto millis = std::chrono::duration_cast<std::chrono::milliseconds>(target).count();
			//std::cout << millis << " task target...\n" ;
			if (now >= it->deadline && !it->handle.done())
			{
				//std::cout << "Resuming overdue task...\n";
				std::coroutine_handle<> h = it->handle;
				it = task_list.erase(it);
				h.resume();
			} 
			else
			{
				++it;
			}
		}
	}
}

// Author: Alan Sing Teik, 2025
// function: FreeRTOs V10 emulation layer
// minimal implementation to support Task creation and resume.
// under the hood it is using C++20 coroutine support for task switching
// Task is stackless.
// no priority support for simplicity

#ifndef RTOS_SIM_H
#define RTOS_SIM_H

#include <coroutine>
#include <iostream>
#include <thread>
#include <chrono>

using namespace std::chrono_literals;

struct BlockedTask
{
    std::coroutine_handle<>					handle;
    std::chrono::steady_clock::time_point	deadline;
};

struct Task
{
    struct promise_type
	{
		Task get_return_object()
		{
			return Task{std::coroutine_handle<promise_type>::from_promise(*this)};
		}
		std::suspend_always initial_suspend() { return {}; }
		std::suspend_always final_suspend() noexcept { return {}; }
		void return_void() {}
		void unhandled_exception() { std::terminate(); }
    };

    std::coroutine_handle<promise_type> handle;

    Task(std::coroutine_handle<promise_type> h) : handle(h) {}

	~Task() 
	{
		if (handle) 
			handle.destroy();
	}
	void resume()
	{
		if(handle)
			handle.resume();
	}
};

struct TimeoutAwaitable
{
	std::chrono::milliseconds timeout;

	bool await_ready() const noexcept { return false; }

	void await_suspend(std::coroutine_handle<> h) const;

	void await_resume() const noexcept {}
};

typedef uint32_t TickType_t;
typedef uint32_t BaseType_t;
typedef uint32_t UBaseType_t;
typedef uint32_t configSTACK_DEPTH_TYPE;
typedef std::coroutine_handle<> TaskHandle_t;

#define xTaskCreate( pvTaskCode,                             \
                         pcName,                             \
						uxStackDepth, \
                         pvParameters,                       \
                          uxPriority,                        \
                          pxCreatedTask                     \
                       )                                     \
					   Task pvTaskCode ## code = pvTaskCode(); \
					   *pxCreatedTask = pvTaskCode ## code.handle; \
					   
					   
void vTaskResume( TaskHandle_t xTaskToResume );
void vTaskStartScheduler();

#define vTaskYield()				co_await TimeoutAwaitable{0ms}
#define vTaskDelay(xTicksToDelay)	co_await TimeoutAwaitable{xTicksToDelay}

#endif //SIM_RTOS_H
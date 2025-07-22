// Author: Alan Sing Teik, 2025
// middleware layer
// function: circular buffer that overwrite old data on overflow
#ifndef CIRCULAR_BUFFER_H
#define CIRCULAR_BUFFER_H

#include <array>
#include <optional>
#include <atomic>

template<typename T, size_t N>
class CircularBuffer_t
{
public:
	CircularBuffer_t() : head_(0), tail_(0) 
	{
	}

	// Attempts to enqueue; returns false if buffer is full
	bool push(const T& item)
	{
		size_t head = head_.load(std::memory_order_relaxed);
		size_t tail = tail_.load(std::memory_order_acquire);

		if (head - tail == N)
		{
			return false;  // full
		}

		buffer_[head % N] = item;
		head_.store(head + 1, std::memory_order_release);
		return true;
	}

	// Attempts to dequeue; returns nullopt if buffer is empty
	std::optional<T> pop()
	{
		size_t tail = tail_.load(std::memory_order_relaxed);
		size_t head = head_.load(std::memory_order_acquire);

		if (head == tail) 
		{
			return std::nullopt;  // empty
		}

		T item = buffer_[tail % N];
		tail_.store(tail + 1, std::memory_order_release);
		return item;
	}

	bool empty() const 
	{
		return head_.load(std::memory_order_acquire)
			== tail_.load(std::memory_order_acquire);
	}

	bool full() const
	{
		return (head_.load(std::memory_order_acquire)
				- tail_.load(std::memory_order_acquire)) == N;
	}

	// Current number of stored elements
	size_t size() const 
	{
		return head_.load(std::memory_order_acquire)
				- tail_.load(std::memory_order_acquire);
	}

private:
	std::array<T, N>		buffer_;
	std::atomic<size_t>		head_;
	std::atomic<size_t>		tail_;
};

#endif //CIRCULAR_BUFFER_H
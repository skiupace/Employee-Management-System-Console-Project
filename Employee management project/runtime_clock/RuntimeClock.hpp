#pragma once
#include <chrono>

struct RuntimeClock {
	std::chrono::steady_clock::time_point start, end;
	std::chrono::duration<float> duration;

	RuntimeClock() {
		start = std::chrono::steady_clock::now();
	}

	~RuntimeClock() {
		end = std::chrono::steady_clock::now();
		duration = end - start;

		float milliseconds = duration.count() * 1000.0f;
		std::cout << "Total runtime: " << milliseconds << "ms\n";
	}
};
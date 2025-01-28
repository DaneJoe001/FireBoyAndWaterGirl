#pragma once 

#include <chrono>
#include <thread>

class UtilTimer
{
public:
	void set_fps(std::size_t fps);
	void wait_update();
	bool can_update();

private:
	std::chrono::nanoseconds get_real_interval();
private:
	// 设置默认帧率
	std::size_t m_fps = 12;
	std::chrono::nanoseconds m_interval = std::chrono::nanoseconds(1000000000 / 12);
	std::chrono::steady_clock::time_point m_last_time = std::chrono::steady_clock::now();
};
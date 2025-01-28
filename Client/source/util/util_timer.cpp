#include <util/util_timer.h>

void UtilTimer::set_fps(std::size_t fps)
{
	m_fps = fps;
	m_interval = std::chrono::nanoseconds(1000000000 / m_fps);
}

void UtilTimer::wait_update()
{
	auto duration = get_real_interval();
	if (duration < m_interval)
	{
		std::this_thread::sleep_for(m_interval - duration);
	}
	m_last_time= std::chrono::steady_clock::now();
}

bool UtilTimer::can_update()
{
	auto duration = get_real_interval();
	if (duration < m_interval)
	{
		return false;
	}
	return true;
}

std::chrono::nanoseconds UtilTimer::get_real_interval()
{
	std::chrono::steady_clock::time_point current_time = std::chrono::steady_clock::now();
	return current_time - m_last_time;
}
#pragma once 

#include <chrono>
#include <thread>

/**
* @class UtilTimer
* @brief 计时器类
**/
class UtilTimer
{
public:
	/**
	* @brief 设置帧率
	* @param fps 帧率
	**/
	void set_fps(std::size_t fps);
	/**
	* @brief 等待下一帧
	**/
	void wait_update();
	/**
	* @brief 是否可以更新
	* @return 是否可以更新
	**/
	bool can_update();

private:
	/**
	* @brief 获取真实间隔
	* @return 真实间隔
	**/
	std::chrono::nanoseconds get_real_interval();

private:
	// 帧率，默认设置12
	std::size_t m_fps = 12;
    // 帧间隔
	std::chrono::nanoseconds m_interval = std::chrono::nanoseconds(1000000000 / 12);
    // 上一帧时间
	std::chrono::steady_clock::time_point m_last_time = std::chrono::steady_clock::now();
};
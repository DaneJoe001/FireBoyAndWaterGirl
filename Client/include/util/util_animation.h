#pragma once

#include <SDL2/SDL.h>

#include <util/util_vector.h>

class UtilTimer;
class UtilCamera;
class ResourceAtlas;

/**
* @class UtilAnimation
* @brief 动画类，用于播放动画
**/
class UtilAnimation
{
public:
	/**
	* @brief 构造函数
	* @param atlas 动画资源指针
	* @param loop 是否循环播放
	**/
	UtilAnimation(ResourceAtlas* atlas, bool loop);
	/**
	* @brief 获取是否循环播放
	**/
	bool is_loop();
    /**
	* @brief 绘制当前帧
	**/
	void draw_frame(UtilCamera* camera);
	/**
	* @brief 设置是否循环播放
	**/
	void set_loop(bool loop);
	/**
	* @brief 更新当前帧
	**/
	void on_update();
    /**
	* @brief 设置当前动画位置
	* @param x x坐标
	* @param y y坐标
	**/
	void set_position(int x, int y);
    /**
	* @brief 设置当前动画位置
	* @param pos 位置
	**/
	void set_position(UtilVector<int> pos);
    /**
	* @brief 更新当前动画位置
	* @param velocity 速度
	**/
	void update_position(UtilVector<int> velocity);

private:
	// 是否循环播放
	bool m_is_loop = false;
    // 动画资源指针
	ResourceAtlas* m_atlas=nullptr;
    // 时间计时器
	UtilTimer* m_timer = nullptr;
    // 当前位置
	UtilVector<int> m_pos = UtilVector(0,0);
    // 当前帧序号
	std::size_t m_current_index = 0;
};
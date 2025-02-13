#pragma once

#include <vector>
#include <string>

#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>
#include <SDL_image.h>

class AtlasFrame;

/**
* @class ResourceAtlas
* @brief 图集资源类
**/
class ResourceAtlas
{
public:
	/**
	* @brief 构造函数
	**/
	ResourceAtlas();
	~ResourceAtlas();
	/**
	* @brief 添加帧信息
	* @param info 帧信息
	**/
	void add_frame_info(AtlasFrame& info);
    /**
	* @brief 获取帧信息
	* @param index 帧索引
	* @return AtlasFrame 帧信息
	**/
	AtlasFrame get_frame(int index);
    /**
	* @brief 获取帧数量
	* @return int 帧数量
	**/
	int get_frame_quantity();

private:
	// 帧信息列表
	std::vector<AtlasFrame> m_atlas;
};
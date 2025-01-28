#pragma once

#include <SDL2/SDL.h>

#include <util/util_vector.h>

class UtilTimer;
class UtilCamera;
class ResourceAtlas;

class UtilAnimation
{
public:
	UtilAnimation(ResourceAtlas* atlas, bool loop);
	bool is_loop();
	void draw_frame(UtilCamera* camera);
	void set_loop(bool loop);
	// 直接由外部调用更新，避免计算帧间隔
	void on_update();
	void set_position(int x, int y);
	void set_position(UtilVector<int> pos);
private:
	bool m_is_loop = false;
	ResourceAtlas* m_atlas=nullptr;
	UtilTimer* m_timer = nullptr;
	UtilVector<int> m_pos = UtilVector(0,0);
	std::size_t m_current_index = 0;
};
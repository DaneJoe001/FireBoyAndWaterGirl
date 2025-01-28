#pragma once

#include <vector>
#include <string>

#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>
#include <SDL_image.h>

class AtlasFrame;
class ResourceAtlas
{
public:
	ResourceAtlas();
	~ResourceAtlas();
	void add_frame_info(AtlasFrame& info);
	AtlasFrame get_frame(int index);
	int get_frame_quantity();
private:
	std::vector<AtlasFrame> m_atlas;
};
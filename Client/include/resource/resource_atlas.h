#pragma once

#include <list>
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
private:
	std::list<AtlasFrame&> m_atlas;
};
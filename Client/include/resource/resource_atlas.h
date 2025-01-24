#pragma once

#include <vector>
#include <string>

#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>
#include <SDL_image.h>

class ResourceAtlas
{
public:
	ResourceAtlas();
	~ResourceAtlas();
	void add_texture(SDL_Texture* texture);
	void init_atlas(SDL_Renderer* renderer, std::string path);
private:
	std::vector<SDL_Texture*> m_textures;
};
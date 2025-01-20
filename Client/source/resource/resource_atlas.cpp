#include <resource/resource_atlas.h>

ResourceAtlas::ResourceAtlas()
{
}

ResourceAtlas::~ResourceAtlas()
{

}

void ResourceAtlas::init_atlas(SDL_Renderer* renderer, std::string path)
{
    SDL_Texture* texture =IMG_LoadTexture(renderer,path.c_str());
}
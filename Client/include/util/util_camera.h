#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <util/util_vector.h>
#include <resource/resource_definition.h>

class UtilCamera
{
public:
    UtilCamera();
    void init(SDL_Renderer* renderer);
    void render_texture(SDL_Texture* texture, const SDL_Rect* src_rect, const SDL_Rect* dst_rect);
    // void set_camera_position(UtilVector pos);
    // void set_camera_position(SDL_Rect rect);
    // void set_camera_position(SDL_Point point);
    // void set_camera_position(SDL_FPoint point);
    void adaptive_render_texture(TextureInfo& texture_info, UtilVector<int> pos);
private:
    SDL_Renderer* m_renderer = nullptr;
    UtilVector<int> m_camera_position;
};
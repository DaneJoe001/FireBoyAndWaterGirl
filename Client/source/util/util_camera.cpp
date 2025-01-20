#include <iostream>
#include <util/util_camera.h>

UtilCamera::UtilCamera() :m_camera_position() {}

void UtilCamera::init(SDL_Renderer* renderer) {
    m_camera_position.set_vector(0, 0);
    m_renderer = renderer;
}

void UtilCamera::render_texture(SDL_Texture* texture, const SDL_Rect* src_rect, const SDL_Rect* dst_rect) 
{
    if (texture == nullptr)
    {
        std::cout << "ERROR: texture is nullptr" << std::endl;
        return;
    }
    int check_render = SDL_RenderCopy(m_renderer, texture, src_rect, dst_rect);
    if (check_render != 0)
    {
        std::cout << "Erender copy error:" << SDL_GetError() << std::endl;
    }
    std::cout << "render texture successfully!" << std::endl;
}
#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <util/util_vector.h>
#include <resource/resource_definition.h>

//TODO:添加开发者模式，展示碰撞箱信息
//在渲染素材时，绘制边框

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
    void switch_development_mode();
private:
    SDL_Renderer* m_renderer = nullptr;
    UtilVector<int> m_camera_position;
    bool m_is_development_mode = false;
};
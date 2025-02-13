#include <iostream>
#include <util/util_camera.h>
#include <util/util_log.h>

UtilCamera::UtilCamera() :m_camera_position() {}

void UtilCamera::init(SDL_Renderer* renderer) {
    m_camera_position.set_vector(0, 0);
    m_renderer = renderer;
}

void UtilCamera::render_texture(SDL_Texture* texture, const SDL_Rect* src_rect, const SDL_Rect* dst_rect)
{
    if (texture == nullptr)
    {
        UtilLog::log(LogLevel::USER, LOG_STR("ERROR", "texture is nullptr!"));
        return;
    }
    int check_render = SDL_RenderCopy(m_renderer, texture, src_rect, dst_rect);
    if (check_render != 0)
    {
        UtilLog::log(LogLevel::USER, LOG_STR("ERROR", "render texture failed!"));
    }
    if (m_is_development_mode)
    {
        SDL_SetRenderDrawColor(m_renderer, 255, 0, 0, 255);
        int check_rect = SDL_RenderDrawRect(m_renderer, dst_rect);
        if (check_rect != 0)
        {
            UtilLog::log(LogLevel::USER, LOG_STR("ERROR", "render rect failed!"));
        }
    }
}

void UtilCamera::adaptive_render_texture(TextureInfo* texture_info, UtilVector<int> pos)
{
    if (texture_info == nullptr)
    {
        UtilLog::log(LogLevel::USER, LOG_STR("ERROR", "texture is nullptr!"));
        return;
    }
    SDL_Rect dst_rect;
    dst_rect.x = pos.x;
    dst_rect.y = pos.y;
    dst_rect.w = texture_info->dst.size.x;
    dst_rect.h = texture_info->dst.size.y;
    SDL_Rect src_rect;
    src_rect.x = texture_info->src.pos.x;
    src_rect.y = texture_info->src.pos.y;
    src_rect.w = texture_info->src.size.x;
    src_rect.h = texture_info->src.size.y;
    int check_render = SDL_RenderCopy(m_renderer, texture_info->texture, &src_rect, &dst_rect);
    if (check_render != 0)
    {
        UtilLog::log(LogLevel::USER, LOG_STR("ERROR", "render texture failed!"));
    }
    if (m_is_development_mode)
    {
        SDL_SetRenderDrawColor(m_renderer, 255, 0, 0, 255);
        int check_rect = SDL_RenderDrawRect(m_renderer, &dst_rect);
        if (check_rect != 0)
        {
            UtilLog::log(LogLevel::USER, LOG_STR("ERROR", "render rect failed!"));
        }
    }
}

void UtilCamera::switch_development_mode()
{
    m_is_development_mode = !m_is_development_mode;
}
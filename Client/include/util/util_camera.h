#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <util/util_vector.h>
#include <resource/resource_definition.h>

//TODO:添加开发者模式，展示碰撞箱信息,在渲染素材时，绘制边框
//TODO: void set_camera_position(UtilVector pos);
//TODO: void set_camera_position(SDL_Rect rect);
//TODO: void set_camera_position(SDL_Point point);
//TODO: void set_camera_position(SDL_FPoint point);

/**
* @class UtilCamera
* @brief 摄像机类
**/
class UtilCamera
{
public:
    /**
    * @brief 构造函数
    **/
    UtilCamera();
    /**
    * @brief 初始化
    * @param renderer 渲染器
    **/
    void init(SDL_Renderer* renderer);
    /**
    * @brief 渲染
    * @param texture 纹理
    * @param src_rect 源矩形
    * @param dst_rect 目标矩形
    **/
    void render_texture(SDL_Texture* texture, const SDL_Rect* src_rect, const SDL_Rect* dst_rect);
    /**
    * @brief 适配渲染
    * @param texture_info 纹理信息
    * @param pos 位置
    **/
    void adaptive_render_texture(TextureInfo* texture_info, UtilVector<int> pos);
    /**
    * @brief 开发者模式开关
    **/
    void switch_development_mode();

private:
    // 渲染器指针
    SDL_Renderer* m_renderer = nullptr;
    // 摄像机位置
    UtilVector<int> m_camera_position;
    // 开发者模式开关
    bool m_is_development_mode = false;
};
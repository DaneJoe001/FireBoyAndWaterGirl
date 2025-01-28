#pragma once

#include <string>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>

#include <manager/manage_resource.h>
#include <manager/manage_scene.h>
#include <manager/manage_button.h>
#include <util/util_camera.h>
#include <util/util_timer.h>


class GameStructure
{
public:
    GameStructure();
    ~GameStructure();

    bool init();
    void quit();
    /**
    * @brief 游戏主循环。
    *
    * 在循环中执行事务处理，绘制，帧率设置。
    *
    */
    void circle();
    void update();
    void render();

private:
    UtilCamera* m_camera = nullptr;
    SDL_Window* m_window = nullptr;
    SDL_Renderer* m_renderer = nullptr;
    SDL_Surface* m_icon = nullptr;
    SDL_Event m_event = SDL_Event();
    std::string m_title = u8"新·森林冰火人";
    //std::size_t m_fps = 15;
    UtilTimer m_frame_rate_control;
    bool is_running = true;
};
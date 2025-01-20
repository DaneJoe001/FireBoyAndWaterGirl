#pragma once

#include <string>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <manager/manage_resource.h>
#include <manager/manage_scene.h>
#include <util/util_camera.h>


class GameStructure
{
public:
    GameStructure();
    ~GameStructure();

    bool init();
    void quit();
    void circle();
    void update();
    void render();
    void release();

private:
    ManageResource& m_resource_manager;
    ManageScene& m_scene_manager;
    UtilCamera* m_camera = nullptr;
    SDL_Window* m_window = nullptr;
    SDL_Renderer* m_renderer = nullptr;
    SDL_Surface* m_icon = nullptr;
    SDL_Event m_event;
    std::string m_title = u8"新·森林冰火人";
    std::size_t m_fps = 25;
    const int m_width = 1080;
    const int m_height = 720;
    bool is_running = true;
};
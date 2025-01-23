﻿#pragma once

#include <string>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>

#include <manager/manage_resource.h>
#include <manager/manage_scene.h>
#include <manager/manage_button.h>
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

private:
    ManageResource& m_resource_manager;
    ManageScene& m_scene_manager;
    ManageButton& m_button_manager;
    UtilCamera* m_camera = nullptr;
    SDL_Window* m_window = nullptr;
    SDL_Renderer* m_renderer = nullptr;
    SDL_Surface* m_icon = nullptr;
    SDL_Event m_event;
    std::string m_title = u8"新·森林冰火人";
    std::size_t m_fps = 25;
    bool is_running = true;
};
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

/**
* @class GameStructure
* @brief 游戏主框架。
**/
class GameStructure
{
public:
    /**
    * @brief 构造函数，初始化游戏主摄像机。
    **/
    GameStructure();
    /**
    * @brief 析构函数，释放游戏主摄像机。
    **/
    ~GameStructure();
    /**
    * @brief 初始化游戏，设置游戏窗口，游戏图标，游戏标题，游戏渲染器，游戏帧率。
    **/
    bool init();
    /**
    * @brief 退出游戏，释放游戏资源，关闭游戏窗口，关闭游戏渲染器，关闭游戏帧率控制器。
    **/
    void quit();
    /**
    * @brief 游戏主循环，在循环中执行事务处理，绘制，帧率设置。
    **/
    void circle();
    /**
    * @brief 更新游戏状态，更新游戏按钮状态，更新游戏场景状态，更新游戏资源状态。
    **/
    void update();
    /**
    * @brief 绘制游戏，绘制游戏按钮，绘制游戏场景，绘制游戏资源。
    **/
    void render();

private:
    // 游戏主摄像机
    UtilCamera* m_camera = nullptr;
    // 游戏窗口指针
    SDL_Window* m_window = nullptr;
    // 游戏渲染器指针
    SDL_Renderer* m_renderer = nullptr;
    // 游戏图标指针
    SDL_Surface* m_icon = nullptr;
    // 游戏事件
    SDL_Event m_event = SDL_Event();
    // 游戏标题
    std::string m_title = u8"新·森林冰火人";
    // 游戏帧率控制器
    UtilTimer m_frame_rate_control;
    // 游戏是否正在运行
    bool is_running = true;
};
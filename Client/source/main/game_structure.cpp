#include <iostream>
#include <chrono>

#include <main/game_structure.h>
#include <util/util_log.h>

GameStructure::GameStructure() :m_resource_manager(ManageResource::get_instance()), m_scene_manager(ManageScene::get_instance()), m_button_manager(ManageButton::get_instance()) {}

GameStructure::~GameStructure() {}

bool GameStructure::init()
{
    UtilVector<int> size = ManageResource::get_window_size();
    m_window = SDL_CreateWindow(m_title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, int(size.x), int(size.y), SDL_WINDOW_SHOWN);
    if (!m_window)
    {
        UtilLog::log(LogLevel::DEVELOPPER, LOG_STR("ERROR", SDL_GetError()));
        SDL_Quit();
        return false;
    }
    if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG))
    {
        UtilLog::log(LogLevel::DEVELOPPER, LOG_STR("ERROR", IMG_GetError()));
        SDL_DestroyWindow(m_window);
        SDL_Quit();
        return false;
    }
    if (SDL_Init(SDL_INIT_AUDIO) < 0)
    {
        UtilLog::log(LogLevel::DEVELOPPER, LOG_STR("ERROR", SDL_GetError()));
        SDL_DestroyWindow(m_window);
        SDL_Quit();
        return false;
    }
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
    {
        UtilLog::log(LogLevel::DEVELOPPER, LOG_STR("ERROR", Mix_GetError()));
        SDL_DestroyWindow(m_window);
        SDL_Quit();
        return false;
    }
    m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED);
    if (!m_renderer)
    {
        UtilLog::log(LogLevel::DEVELOPPER, LOG_STR("ERROR", SDL_GetError()));
        SDL_DestroyWindow(m_window);
        SDL_Quit();
        return false;
    }
    ManageResource::init(m_renderer);
    ManageResource::get_instance().load_resource();
    m_icon = m_resource_manager.get_surface("window_icon");
    if (!m_icon)
    {
        UtilLog::log(LogLevel::DEVELOPPER, LOG_STR("ERROR", SDL_GetError()));
    }
    SDL_SetWindowIcon(m_window, m_icon);
    m_camera = new UtilCamera();
    m_camera->init(m_renderer);

    m_scene_manager.init();
    m_scene_manager.set_current_scene(SceneType::MAIN);
    return true;
}

void GameStructure::circle()
{
    int frame_time = 1000 / m_fps;
    bool is_init = init();
    if (!is_init)
    {
        return;
    }
    Mix_Music* music = m_resource_manager.get_music("background");
    if (Mix_PlayMusic(music, -1) == -1)
    {
        std::cerr << "Failed to play music! SDL_mixer Error: " << Mix_GetError() << std::endl;
    }
    while (is_running)
    {
        Uint32 frame_start = SDL_GetTicks();
        while (SDL_PollEvent(&m_event))
        {
            switch (m_event.type)
            {
            case SDL_QUIT:
                is_running = false;
                break;
            case SDL_MOUSEBUTTONDOWN:
                //std::cout<<"clicked"<<std::endl;
                if (m_event.button.button == SDL_BUTTON_LEFT)
                {
                    UtilVector<int> mouse_pos = UtilVector<int>(m_event.button.x, m_event.button.y);
                    m_button_manager.check_press(mouse_pos);
                }
                break;
            case SDL_MOUSEBUTTONUP:
                if (m_event.button.button == SDL_BUTTON_LEFT)
                {
                    UtilVector<int> mouse_pos = UtilVector<int>(m_event.button.x, m_event.button.y);
                    m_button_manager.check_release(mouse_pos);
                }
                break;
            }
        }
        SDL_RenderClear(m_renderer);
        m_scene_manager.get_current_scene()->enter();
        m_scene_manager.get_current_scene()->update();
        m_scene_manager.get_current_scene()->draw(m_camera);
        SDL_RenderPresent(m_renderer);
        Uint32 frame_end = SDL_GetTicks();
        if (frame_end - frame_start < frame_time)
        {
            SDL_Delay(frame_time - (frame_end - frame_start));
        }
    }
    quit();
}

void GameStructure::quit()
{
    if (m_camera != nullptr)
    {
        delete m_camera;
    }
    SDL_FreeSurface(m_icon);
    SDL_DestroyRenderer(m_renderer);
    SDL_DestroyWindow(m_window);
    Mix_CloseAudio();
    IMG_Quit();
    SDL_Quit();
}

void GameStructure::update()
{

}

void GameStructure::render()
{

}
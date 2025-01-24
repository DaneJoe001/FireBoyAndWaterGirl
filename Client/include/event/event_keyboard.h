#pragma once

#include <functional>

#include <SDL2/SDL.h>

class SceneBase;

class EventKeyboard
{
public:
    //引入场景指针
    EventKeyboard(SceneBase* scene,std::function<void(SDL_Keycode)> on_press);
    ~EventKeyboard() = default;
    virtual void on_press(SDL_Keycode key);
    virtual void on_release(SDL_Keycode key);
    bool is_active();
    bool is_set_on_press();
    bool is_set_on_release();
    void set_status(bool status);
private:
    //是否处于激活状态
    bool m_is_active = false;
    bool m_is_set_on_press = false;
    bool m_is_set_on_release = false;
    std::function<void(SDL_Keycode)> m_on_press;
    std::function<void(SDL_Keycode)> m_on_release;
};
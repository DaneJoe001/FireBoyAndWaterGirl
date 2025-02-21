#pragma once

#include <functional>

#include <SDL2/SDL.h>

class SceneBase;

enum class EventKeyboardType
{
    PRESS,
    RELEASE
};

/**
* @class EventKeyboard
* @brief 键盘事件类
**/
class EventKeyboard
{
public:
    /**
     * @brief 键盘事件
     * @param scene 绑定的场景
     * @param on_press 按下事件
     **/
    EventKeyboard(SceneBase* scene, EventKeyboardType type,std::function<void(SDL_Keycode)> callback);
    /**
     * @brief 键盘事件析构函数
     **/
    ~EventKeyboard() = default;
    /**
     * @brief 处理键盘按下事件
     * @param key 按键编号
     **/
    virtual void on_press(SDL_Keycode key);
    /**
     * @brief 处理键盘松开事件
     * @param key 按键编号
     **/
    virtual void on_release(SDL_Keycode key);
    /**
     * @brief 判断当前键盘事件是否处于激活状态
     **/
    bool is_enable();
    /**
     * @brief 判断是否设置了按下事件
     **/
    bool is_set_on_press();
    /**
     * @brief 判断是否设置了松开事件
     **/
    bool is_set_on_release();
    /**
     * @brief 设置当前键盘事件是否处于激活状态
     **/
    void set_enable(bool enable);

private:
    // 是否处于激活状态
    bool m_is_enable = false;
    // 是否设置了按下事件
    bool m_is_set_on_press = false;
    // 是否设置了松开事件
    bool m_is_set_on_release = false;
    // 按下事件的回调函数
    std::function<void(SDL_Keycode)> m_on_press;
    // 松开事件的回调函数
    std::function<void(SDL_Keycode)> m_on_release;
};
#pragma once

#include <list>

#include <SDL2/SDL.h>

class EventKeyboard;

/**
* @class ManageKeyEvent
* @brief 管理键盘事件
**/
class ManageKeyEvent
{
public:
	/**
	* @brief 获取按键管理单例引用
	**/
	static ManageKeyEvent& get_instance();
	/**
	* @brief 添加键盘事件
	* @param key_event 键盘事件
	**/
	void add_key_event(EventKeyboard* key_event);
	/**
	* @brief 检查按键按下
	* @param key 键值
	**/
	void check_key_press(SDL_Keycode key);
	/**
	* @brief 检查按键抬起
	* @param key 键值
	**/
    void check_key_release(SDL_Keycode key);

private:
	// 键盘事件列表
	std::list<EventKeyboard*> m_key_event_list;
};
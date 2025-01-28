#pragma once

#include <list>

#include <SDL2/SDL.h>

class EventKeyboard;

class ManageKeyEvent
{
public:
	static ManageKeyEvent& get_instance();
	void add_key_event(EventKeyboard* key_event);
	void check_key_press(SDL_Keycode key);
    void check_key_release(SDL_Keycode key);
private:
	std::list<EventKeyboard*> m_key_event_list;
};
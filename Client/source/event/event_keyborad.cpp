#include <event/event_keyboard.h>
#include <scene/scene_base.h>
#include <manager/manage_key_event.h>

EventKeyboard::EventKeyboard(SceneBase* scene, std::function<void(SDL_Keycode)> on_press)
{
	scene->add_keyboard_event(this);
	m_is_active = true;
	m_is_set_on_press = true;
	m_on_press = on_press;
	ManageKeyEvent::get_instance().add_key_event(this);
}

void EventKeyboard::on_press(SDL_Keycode key)
{
	std::cout << "keyboard event" << std::endl;
	if (m_is_set_on_press)
	{
		m_on_press(key);
	}
}

void EventKeyboard::on_release(SDL_Keycode key)
{
	std::cout << "keyboard event" << std::endl;
    if (m_is_set_on_release)
    {
        m_on_release(key);
    }
}

bool EventKeyboard::is_active()
{
	return m_is_active;
}

bool EventKeyboard::is_set_on_press()
{
	return m_is_set_on_press;
}

bool EventKeyboard::is_set_on_release()
{
    return m_is_set_on_release;
}

void EventKeyboard::set_status(bool status)
{
	m_is_active = status;
}
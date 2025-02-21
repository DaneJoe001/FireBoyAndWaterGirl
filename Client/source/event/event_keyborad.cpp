#include <event/event_keyboard.h>
#include <scene/scene_base.h>
#include <manager/manage_key_event.h>

EventKeyboard::EventKeyboard(SceneBase* scene,EventKeyboardType type, std::function<void(SDL_Keycode)> callback)
{
	scene->add_keyboard_event(this);
	switch (type)
	{
	case EventKeyboardType::PRESS:
		m_is_set_on_press = true;
        m_on_press = callback;
		break;
	case EventKeyboardType::RELEASE:
		m_is_set_on_release = true;
        m_on_release = callback;
		break;
	default:
		break;
	}
	ManageKeyEvent::get_instance().add_key_event(this);
}

void EventKeyboard::on_press(SDL_Keycode key)
{
	if (m_is_set_on_press)
	{
		m_on_press(key);
	}
}

void EventKeyboard::on_release(SDL_Keycode key)
{
    if (m_is_set_on_release)
    {
        m_on_release(key);
    }
}

bool EventKeyboard::is_enable()
{
	return m_is_enable;
}

bool EventKeyboard::is_set_on_press()
{
	return m_is_set_on_press;
}

bool EventKeyboard::is_set_on_release()
{
    return m_is_set_on_release;
}

void EventKeyboard::set_enable(bool status)
{
	m_is_enable = status;
}
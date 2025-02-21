#include <manager/manage_key_event.h>
#include <event/event_keyboard.h>
#include <util/util_log.h>

ManageKeyEvent& ManageKeyEvent::get_instance()
{
	static ManageKeyEvent instance;
	return instance;
}

void ManageKeyEvent::add_key_event(EventKeyboard* key_event)
{
	if (key_event == nullptr)
	{
        UtilLog::log(LogLevel::DEVELOPPER, LOG_STR("ERROR","key_event is nullptr!"));
		return;
	}
	m_key_event_list.push_back(key_event);
}

void ManageKeyEvent::check_key_press(SDL_Keycode key)
{
	for (auto& key_event : m_key_event_list)
	{
		if (key_event->is_enable())
		{
			key_event->on_press(key);
		}
	}
}

void ManageKeyEvent::check_key_release(SDL_Keycode key)
{
	for (auto& key_event : m_key_event_list)
    {
        if (key_event->is_enable())
        {
            key_event->on_release(key);
        }
    }
}
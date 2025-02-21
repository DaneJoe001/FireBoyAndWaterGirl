#include <scene/scene_base.h>
#include <button/button_base.h>
#include <event/event_keyboard.h>
#include <manager/manage_scene.h>

SceneBase::~SceneBase()
{
    for (auto& button : m_button_list)
    {
        if (button != nullptr)
        {
            delete button;
            button = nullptr;
        }
        continue;
    }
    for (auto& event : m_event_list)
    {
        if (event != nullptr)
        {
            delete event;
            event = nullptr;
        }
        continue;
    }
}

void SceneBase::enter()
{
    for (auto& button : m_button_list)
    {
        if (button != nullptr)
        {
            button->set_enable(true);
        }
        continue;
    }
    for (auto& event : m_event_list)
    {
        if (event != nullptr)
        {
            event->set_enable(true);
        }
        continue;
    }
}

void SceneBase::exit()
{
    for (auto& button : m_button_list)
    {
        if (button != nullptr)
        {
            button->set_enable(false);
        }
        continue;
    }
    for (auto& event : m_event_list)
    {
        if (event != nullptr)
        {
            event->set_enable(false);
        }
        continue;
    }

}

void SceneBase::add_button(ButtonBase* button)
{
    if (button != nullptr)
    {
        m_button_list.push_back(button);
    }
}

void SceneBase::remove_button(ButtonBase* button)
{
    if (button != nullptr)
    {
        delete button;
        button = nullptr;
    }
}

void SceneBase::add_keyboard_event(EventKeyboard* key_event)
{
    if (key_event != nullptr)
    {
        m_event_list.push_back(key_event);
    }
}

void SceneBase::remove_keyboard_event(EventKeyboard* key_event)
{

}
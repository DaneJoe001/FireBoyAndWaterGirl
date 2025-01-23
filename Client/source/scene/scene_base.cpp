#include <scene/scene_base.h>
#include <button/button_base.h>
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
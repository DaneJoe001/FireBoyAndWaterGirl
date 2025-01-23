#include <button/button_base.h>
#include <manager/manage_button.h>

ManageButton& ManageButton::get_instance()
{
    static ManageButton instance;
    return instance;
}

void ManageButton::add_button(ButtonBase* button)
{
    if (button != nullptr)
    {
        m_button_list.push_back(button);
    }
}

void ManageButton::check_press(UtilVector<int> mouse_pos)
{
    for (auto button : m_button_list)
    {
        if (!button->is_valid())
        {
            continue;
        }
        if (button->is_on_button(mouse_pos))
        {
            button->on_press();
        }
    }
}

void ManageButton::check_release(UtilVector<int> mouse_pos)
{
    for (auto button : m_button_list)
    {
        if (!button->is_valid())
        {
            continue;
        }
        if (button->is_on_button(mouse_pos))
        {
            button->on_release();
        }
    }
}
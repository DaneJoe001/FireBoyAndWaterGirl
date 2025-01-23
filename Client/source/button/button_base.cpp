#include <button/button_base.h>
#include <scene/scene_base.h>

ButtonBase::ButtonBase(SceneBase* scene,UtilVector pos)
{
    scene->add_button(this);
    
    m_pos = pos;
    m_normal_texture = m_resource_manager.get_texture("button_normal");
    m_pressed_texture = m_resource_manager.get_texture("button_pressed");
    m_button_manager.add_button(this);
}

ButtonBase::ButtonBase(SceneBase* scene, SDL_Texture* normal_texture, SDL_Texture* pressed_texture, UtilVector pos, UtilVector size)
{
    scene->add_button(this);
    m_normal_texture = normal_texture;
    m_pressed_texture = pressed_texture;
    m_pos = pos;
    m_button_manager.add_button(this);
}

ButtonBase::~ButtonBase()
{

}

void ButtonBase::on_clicked()
{
    std::cout << "ButtonBase::on_clicked()" << std::endl;
}

bool ButtonBase::is_pressed(UtilVector mouse_pos)
{
    return m_pos.is_within(mouse_pos, m_pos + m_size);
}

bool ButtonBase::is_valid()
{
    return m_is_valid;
}

void ButtonBase::set_valid(bool is_valid)
{
    m_is_valid = is_valid;
}

void ButtonBase::draw(UtilCamera* camera)
{
    SDL_Rect m_pressed_dst = { m_pos.x, m_pos.y, m_size.x, m_size.y };
    if (m_pressed_texture != nullptr && m_normal_texture != nullptr)
    {
        if (m_is_pressed)
        {
            camera->render_texture(m_pressed_texture, nullptr, &m_pressed_dst);
        }
        else
        {
            camera->render_texture(m_normal_texture, nullptr, &m_pressed_dst);
        }
        return;
    }
    // TODO: 无素材时，绘制矩形作为按钮
}
#include <manager/manage_resource.h>
#include <manager/manage_button.h>
#include <manager/manage_scene.h>
#include <button/button_base.h>
#include <scene/scene_base.h>

ButtonBase::ButtonBase(SceneBase* scene,UtilVector<int> pos, std::function<void()>call_back)
{
    scene->add_button(this);
    
    m_pos = pos;
    m_normal_texture = ManageResource::get_instance().get_texture_info("button_normal");
    m_pressed_texture = ManageResource::get_instance().get_texture_info("button_pressed");
    m_size = m_normal_texture->dst.size;

    m_on_clicked = call_back;
    ManageButton::get_instance().add_button(this);
}

ButtonBase::ButtonBase(SceneBase* scene,
    TextureInfo* normal_texture_info,
    TextureInfo* pressed_texture_info,
    UtilVector<int> pos,
    std::function<void()>call_back)
{
    scene->add_button(this);
    m_pos = pos;
    m_normal_texture = normal_texture_info;
    m_pressed_texture = pressed_texture_info;

    m_size = m_normal_texture->dst.size;

    m_on_clicked = call_back;
    ManageButton::get_instance().add_button(this);
}

ButtonBase::~ButtonBase(){}

void ButtonBase::on_press()
{
    m_is_pressed = true;
}

void ButtonBase::on_release()
{
    m_is_pressed = false;
    m_on_clicked();
}

bool ButtonBase::is_on_button(UtilVector<int> mouse_pos)
{
    return mouse_pos.is_within(m_pos, m_pos + m_size);
}

bool ButtonBase::is_valid()
{
    return m_is_valid;
}

void ButtonBase::set_status(bool is_valid)
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
            camera->adaptive_render_texture(m_pressed_texture, m_pos);
        }
        else
        {
            camera->adaptive_render_texture(m_normal_texture, m_pos);
        }
        return;
    }
    // TODO: 无素材时，绘制矩形作为按钮
}
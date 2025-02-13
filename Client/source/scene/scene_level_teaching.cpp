#include <scene/scene_level_teaching.h>
#include <manager/manage_resource.h>
#include <manager/manage_scene.h>
#include <button/button_base.h>
#include <event/event_keyboard.h>
#include <util/util_animation.h>

SceneLevelTeaching::SceneLevelTeaching()
{
    m_animation = new UtilAnimation(
        ManageResource::get_instance().get_atlas("water_head_idle"), true
    );
    m_background = ManageResource::get_instance().get_texture("background_3");
    m_animation->set_position(pos);
    EventKeyboard* key_event_direct = new EventKeyboard(this, [&](SDL_Keycode key)
        {
            switch (key)
            {
            case SDLK_UP:
                pos += UtilVector<int>(0, -5);
                m_animation->set_position(pos);
                break;
            case SDLK_DOWN:
                pos += UtilVector<int>(0, 5);
                m_animation->set_position(pos);
                break;
            case SDLK_LEFT:
                pos += UtilVector<int>(-5, 0);
                m_animation->set_position(pos);
                break;
            case SDLK_RIGHT:
                pos += UtilVector<int>(5, 0);
                m_animation->set_position(pos);
                break;
            }
        });
}

void SceneLevelTeaching::enter()
{
    for (auto& button : m_button_list)
    {
        button->set_status(true);
    }
}

void SceneLevelTeaching::exit()
{
    for (auto& button : m_button_list)
    {
        button->set_status(false);
    }
}

void SceneLevelTeaching::draw(UtilCamera* camera)
{
    m_animation->draw_frame(camera);
    for (auto button : m_button_list)
    {
        button->draw(camera);
    }
}

void SceneLevelTeaching::update()
{
    m_animation->on_update();
}
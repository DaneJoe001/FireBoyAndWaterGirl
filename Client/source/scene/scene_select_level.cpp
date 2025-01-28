#include <manager/manage_resource.h>
#include <manager/manage_scene.h>
#include <button/button_base.h>
#include <event/event_keyboard.h>
#include <scene/scene_select_level.h>
#include <util/util_animation.h>

SceneSelectLevel::SceneSelectLevel()
{
    m_background = ManageResource::get_instance().get_texture("background_3");
    m_animation = new UtilAnimation(
        &ManageResource::get_instance().get_atlas("water_head_idle"), true
    );
    m_animation->set_position(pos);
    ButtonBase* button = new ButtonBase(this, { 30,30 }, [&]()
        {
            ManageScene::get_instance().set_current_scene(SceneType::MAIN);
        });
    EventKeyboard* key_event_esc = new EventKeyboard(this, [&](SDL_Keycode key)
        {
            if (key == SDLK_ESCAPE)
            {
                ManageScene::get_instance().set_current_scene(SceneType::MAIN);
            }
        });
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

SceneSelectLevel::~SceneSelectLevel()
{

}

void SceneSelectLevel::draw(UtilCamera* camera)
{
    UtilVector<int> window_size = ManageResource::get_window_size();
    SDL_Rect background_rect = { 0, 0, window_size.x, window_size.y };

    camera->render_texture(m_background, nullptr, &background_rect);
    for (auto button : m_button_list)
    {
        button->draw(camera);
    }
    m_animation->draw_frame(camera);
}

void SceneSelectLevel::enter()
{
    for (auto& button : m_button_list)
    {
        button->set_status(true);
    }
}

void SceneSelectLevel::exit()
{
    for (auto& button : m_button_list)
    {
        button->set_status(false);
    }
}

void SceneSelectLevel::update()
{
    m_animation->on_update();
}
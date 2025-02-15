#include <scene/scene_level_teaching.h>
#include <manager/manage_resource.h>
#include <manager/manage_scene.h>
#include <button/button_base.h>
#include <event/event_keyboard.h>
#include <util/util_animation.h>

SceneLevelTeaching::SceneLevelTeaching()
{
    m_background = ManageResource::get_instance().get_texture("background_3");
    //TODO: 添加角色管理
    m_fire_boy_player = new PlayerFireBoy();
    EventKeyboard* key_event_direct = new EventKeyboard(this, [&](SDL_Keycode key)
        {
            switch (key)
            {
            case SDLK_UP:
                break;
            case SDLK_DOWN:
                break;
            case SDLK_LEFT:
                break;
            case SDLK_RIGHT:
                break;
            }
        });
    EventKeyboard* key_event_escape = new EventKeyboard(this, [&](SDL_Keycode key)
        {
            if (key == SDLK_ESCAPE)
            {
                ManageScene::get_instance().set_current_scene(SceneType::SELECT_LEVEL);
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
    camera->render_texture(m_background, nullptr, nullptr);
    m_fire_boy_player->draw(camera);
    for (auto button : m_button_list)
    {
        button->draw(camera);
    }
}

void SceneLevelTeaching::update()
{
    
}
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
    EventKeyboard* key_event_direct_press = new EventKeyboard(this, EventKeyboardType::PRESS,[&](SDL_Keycode key)
        {
            m_fire_boy_player->event_keyboad(EventKeyboardType::PRESS,key);
        });
    EventKeyboard* key_event_direct_release = new EventKeyboard(this, EventKeyboardType::RELEASE, [&](SDL_Keycode key)
        {
            m_fire_boy_player->event_keyboad(EventKeyboardType::RELEASE, key);
        });
    EventKeyboard* key_event_escape = new EventKeyboard(this, EventKeyboardType::PRESS,[&](SDL_Keycode key)
        {
            if (key == SDLK_ESCAPE)
            {
                ManageScene::get_instance().set_current_scene(SceneType::SELECT_LEVEL);
            }
        });
}

void SceneLevelTeaching::enter()
{
    SceneLevelBase::enter();
}

void SceneLevelTeaching::exit()
{
    SceneLevelBase::exit();
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
    m_fire_boy_player->update();
}
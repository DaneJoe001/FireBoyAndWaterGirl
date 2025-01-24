#include <manager/manage_resource.h>
#include <manager/manage_scene.h>
#include <button/button_base.h>
#include <scene/scene_select_level.h>

SceneSelectLevel::SceneSelectLevel()
{
    m_background = ManageResource::get_instance().get_texture("background_3");
    ButtonBase* button = new ButtonBase(this, { 30,30 }, [&]()
        {
            ManageScene::get_instance().set_current_scene(SceneType::MAIN);
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
}

void SceneSelectLevel::enter()
{
    for (auto& button : m_button_list)
    {
        button->set_valid(true);
    }
}

void SceneSelectLevel::exit()
{
    for (auto& button : m_button_list)
    {
        button->set_valid(false);
    }
}

void SceneSelectLevel::update()
{

}
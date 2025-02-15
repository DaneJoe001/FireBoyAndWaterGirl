#include <manager/manage_resource.h>
#include <manager/manage_scene.h>
#include <button/button_base.h>
#include <event/event_keyboard.h>
#include <scene/scene_select_level.h>
#include <util/util_animation.h>

SceneSelectLevel::SceneSelectLevel()
{
    m_background = ManageResource::get_instance().get_texture("background_3");
    m_board= new UtilAnimation(
        ManageResource::get_instance().get_atlas("PopupBackground"), true
    );
    m_board->set_position({ 0, 80 });
    ButtonBase* button = new ButtonBase(this, 
        ManageResource::get_instance().get_texture_info("BackButtonFull0000"),
        ManageResource::get_instance().get_texture_info("BackButtonFull0001"),
        { 20,10 }, [&]()
        {
            ManageScene::get_instance().set_current_scene(SceneType::MAIN);
        });
    ButtonBase* button_level_teaching = new ButtonBase(this,
        ManageResource::get_instance().get_texture_info("FinishStone0000"),
        ManageResource::get_instance().get_texture_info("FinishStone0021"),
        { 120,180 }, [&]()
        {
           ManageScene::get_instance().set_current_scene(SceneType::LEVEL_TEACHING);
            std::cout<<"enter level teaching"<<std::endl;
        });
    EventKeyboard* key_event_esc = new EventKeyboard(this, [&](SDL_Keycode key)
        {
            if (key == SDLK_ESCAPE)
            {
                ManageScene::get_instance().set_current_scene(SceneType::MAIN);
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
    
    m_board->draw_frame(camera);
    
    for (auto button : m_button_list)
    {
        button->draw(camera);
    }
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

}
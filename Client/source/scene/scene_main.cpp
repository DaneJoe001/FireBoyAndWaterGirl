#include <iostream>

#include <scene/scene_main.h>
#include <button/button_base.h>
#include <event/event_keyboard.h>
#include <manager/manage_resource.h>
#include <manager/manage_scene.h>

SceneMain::SceneMain()
{
	m_background = ManageResource::get_instance().get_texture("background_1");
	m_title = ManageResource::get_instance().get_texture("title_crystal");
	m_beam_cone_shaped = ManageResource::get_instance().get_texture("beam_cone_shaped");

	ButtonBase* button = new ButtonBase(this,
		ManageResource::get_instance().get_texture_info("ToggleControlButtonSingle0000"),
		ManageResource::get_instance().get_texture_info("ToggleControlButtonSingle0001"),
		{ 465,460 },[&]()
		{
			std::cout << "Enter Level Selection!" << std::endl;
			ManageScene::get_instance().set_current_scene(SceneType::SELECT_LEVEL);
		}); 
}

SceneMain::~SceneMain(){}

void SceneMain::enter()
{
	SceneBase::enter();
}

void SceneMain::exit()
{
	SceneBase::exit();
}

void SceneMain::update()
{
	//std::cout << "Update the main scene!" << std::endl;
}

void SceneMain::draw(UtilCamera* camera)
{
	UtilVector<int> window_size = ManageResource::get_window_size();
	SDL_Rect background_rect = { 0, 0, window_size.x, window_size.y };

	UtilVector<int> title_pos;
	title_pos.set_vector(window_size.x / 2 - 430, window_size.y / 3 - 135);
	SDL_Rect ttile_rect = { title_pos.x,title_pos.y, 860, 270 };

	UtilVector<int> beam_cone_shaped_pos;
	beam_cone_shaped_pos.set_vector(window_size.x / 2 - 80, window_size.y - 846);
	SDL_Rect beam_cone_shaped_rect = { beam_cone_shaped_pos.x,beam_cone_shaped_pos.y, 159, 846 };

	camera->render_texture(m_background, nullptr, &background_rect);
	camera->render_texture(m_beam_cone_shaped, nullptr, &beam_cone_shaped_rect);
	camera->render_texture(m_title, nullptr, &ttile_rect);
	for (auto button : m_button_list)
	{
		button->draw(camera);
	}
}
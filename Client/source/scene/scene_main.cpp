#include <iostream>

#include <scene/scene_main.h>
#include <button/button_base.h>

SceneMain::SceneMain()
{
	m_background = m_resource_manager.get_texture("background_1");
	m_title = m_resource_manager.get_texture("title_crystal");
	m_beam_cone_shaped = m_resource_manager.get_texture("beam_cone_shaped");

	ButtonBase* button = new ButtonBase(this, { 490,480 }, [&]()
		{
			std::cout << "Start the game!" << std::endl;
		});
	add_button(button);
}

SceneMain::~SceneMain()
{
	// 调整基类析构和派生类析构
	for (auto& button : m_button_list)
	{
		remove_button(button);
	}
}

void SceneMain::enter()
{
	for (auto& button : m_button_list)
	{
		button->set_valid(true);
	}
}

void SceneMain::exit()
{
	std::cout << "Exit the main scene!" << std::endl;
	for (auto& button : m_button_list)
	{
		button->set_valid(false);
	}
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
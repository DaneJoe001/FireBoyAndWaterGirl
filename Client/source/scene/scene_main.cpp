#include <iostream>

#include <scene/scene_main.h>

SceneMain::SceneMain()
{
	m_background = m_resource_manager.get_texture("TempleHall");
	m_title = m_resource_manager.get_texture("GameNameCrystal");
}

void SceneMain::enter()
{
	std::cout << "Enter the main scene!" << std::endl;
}

void SceneMain::exit()
{
	std::cout << "Exit the main scene!" << std::endl;
}

void SceneMain::update()
{
	std::cout << "Update the main scene!" << std::endl;
}

void SceneMain::draw(UtilCamera* camera)
{
	SDL_Rect background_rect = { 0, 0, 1080, 720 };
	SDL_Rect ttile_rect = { 50, 100, 860, 270 };
	camera->render_texture(m_background, nullptr, &background_rect);
	camera->render_texture(m_title, nullptr, &ttile_rect);
}
#include <iostream>

#include <scene/scene_setting.h>

void SceneSetting::enter()
{
	std::cout << "Enter the setting scene!" << std::endl;
}

void SceneSetting::exit()
{
	std::cout << "Exit the setting scene!" << std::endl;
}

void SceneSetting::update()
{
	std::cout << "Update the setting scene!" << std::endl;
}

void SceneSetting::draw(UtilCamera* camera)
{
	std::cout << "Draw the setting scene!" << std::endl;
}
#include <iostream>

#include <scene/scene_setting.h>

void SceneSetting::enter()
{
	SceneBase::enter();
}

void SceneSetting::exit()
{
	SceneBase::exit();
}

void SceneSetting::update()
{
	std::cout << "Update the setting scene!" << std::endl;
}

void SceneSetting::draw(UtilCamera* camera)
{
	std::cout << "Draw the setting scene!" << std::endl;
}
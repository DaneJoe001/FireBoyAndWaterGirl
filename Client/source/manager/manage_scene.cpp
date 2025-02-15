#include <iostream>

#include <manager/manage_scene.h>

ManageScene& ManageScene::get_instance()
{
	std::lock_guard<std::mutex> lock(m_mutex);
	static ManageScene m_instance;
	return m_instance;
}

void ManageScene::init()
{
	create_scene(SceneType::MAIN);
	create_scene(SceneType::SETTING);
	create_scene(SceneType::SELECT_LEVEL);
    create_scene(SceneType::LEVEL_TEACHING);
}

ManageScene::ManageScene() {}

ManageScene::~ManageScene()
{
	for (const auto& it : m_scene_map)
	{
		if (it.second != nullptr)
		{
			delete it.second;
		}
	}
}

void ManageScene::check_scene()
{
	for (const auto& it : m_scene_map)
	{
		it.second->enter();
	}
}

SceneBase* ManageScene::create_scene(SceneType type)
{
	switch (type)
	{
	case SceneType::MAIN:
		m_scene_map[type] = new SceneMain();
		return m_scene_map[type];
		break;
	case SceneType::SETTING:
		m_scene_map[type] = new SceneSetting();
		return m_scene_map[type];
		break;
	case SceneType::SELECT_LEVEL:
		m_scene_map[type] = new SceneSelectLevel();
		return m_scene_map[type];
        break;
    case SceneType::LEVEL_TEACHING:
        m_scene_map[type] = new SceneLevelTeaching();
        return m_scene_map[type];
        break;
	default:
		return nullptr;
		break;
	}
}

SceneBase* ManageScene::get_scene(SceneType type)
{
	return m_scene_map.at(type);
}

void ManageScene::set_current_scene(SceneBase* scene)
{
	if (scene != get_current_scene())
	{
		m_current_scene->exit();
		m_current_scene = scene;
	}
}

void ManageScene::set_current_scene(SceneType type)
{
	m_current_scene = m_scene_map.at(type);
}

SceneBase* ManageScene::get_current_scene()
{
	return m_current_scene;
}

std::mutex ManageScene::m_mutex;
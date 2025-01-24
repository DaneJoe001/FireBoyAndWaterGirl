#pragma once

#include <unordered_map>
#include <mutex>

#include <scene/scene_base.h>
#include <scene/scene_main.h>
#include <scene/scene_select_level.h>
#include <scene/scene_setting.h>

enum class SceneType
{
	MAIN = 0,
	SETTING = 1,
	SELECT_LEVEL = 2,
};

class ManageScene
{
public:
	static ManageScene& get_instance();
	void init();
	void check_scene();
	SceneBase* create_scene(SceneType type);
	SceneBase* get_scene(SceneType type);
	void set_current_scene(SceneBase* scene);
	void set_current_scene(SceneType type);
	SceneBase* get_current_scene();

private:
	ManageScene();
	~ManageScene();
	ManageScene(const ManageScene&) = delete;
	ManageScene& operator=(const ManageScene&) = delete;
	ManageScene(ManageScene&&) = delete;
	ManageScene& operator=(ManageScene&&) = delete;
private:
	static std::mutex m_mutex;
	std::unordered_map<SceneType, SceneBase*>m_scene_map;
	SceneBase* m_current_scene;
};
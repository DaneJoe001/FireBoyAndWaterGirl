#pragma once

#include <unordered_map>
#include <mutex>

#include <scene/scene_base.h>
#include <scene/scene_main.h>
#include <scene/scene_select_level.h>
#include <scene/scene_setting.h>

/**
* @class ManageScene
* @brief 场景枚举类
**/
enum class SceneType
{
	MAIN = 0,
	SETTING = 1,
	SELECT_LEVEL = 2,
};

/**
* @class ManageScene
* @brief 场景管理类
**/
class ManageScene
{
public:
	/**
	* @brief 获取场景管理类单例引用
	**/
	static ManageScene& get_instance();
	/**
	* @brief 初始化场景管理类
	**/
	void init();
	/**
	* @brief 检查场景
	**/
	void check_scene();
	/**
	* @brief 创建场景
	* @param type 场景类型
	**/
	SceneBase* create_scene(SceneType type);
	/**
	* @brief 获取场景
	* @param type 场景类型
	**/
	SceneBase* get_scene(SceneType type);
	/**
	* @brief 设置当前场景
	* @param scene 场景
	**/
	void set_current_scene(SceneBase* scene);
	/**
	* @brief 设置当前场景
	* @param type 场景类型
	**/
	void set_current_scene(SceneType type);
	/**
	* @brief 获取当前场景
	**/
	SceneBase* get_current_scene();

private:
	/**
	* @brief 构造函数
	**/
	ManageScene();
	/**
	* @brief 析构函数
	**/
	~ManageScene();
	ManageScene(const ManageScene&) = delete;
	ManageScene& operator=(const ManageScene&) = delete;
	ManageScene(ManageScene&&) = delete;
	ManageScene& operator=(ManageScene&&) = delete;
private:
	// 互斥锁，线程安全
	static std::mutex m_mutex;
	// 场景指针资源
	std::unordered_map<SceneType, SceneBase*>m_scene_map;
	// 当前场景指针
	SceneBase* m_current_scene;
};
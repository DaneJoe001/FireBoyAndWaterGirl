#pragma once
#include <scene/scene_base.h>

/**
* @class SceneSetting
* @brief 设置场景类
**/
class SceneSetting :public SceneBase
{
public:
	/**
	* @brief 进入场景
	**/
	void enter()override;
    /**
	* @brief 退出场景
	**/
	void exit()override;
    /**
	* @brief 更新场景
	**/
	void update()override;
    /**
	* @brief 绘制场景
	* @param camera 相机
	**/
	void draw(UtilCamera* camera)override;
};
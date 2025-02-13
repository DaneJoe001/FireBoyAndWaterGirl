#pragma once

#include <scene/scene_level_base.h>

class UtilAnimation;

/**
* @class SceneLevelTeaching
* @brief 教学测试关卡场景
**/
class SceneLevelTeaching : public SceneLevelBase
{
public:
	/**
	* @brief 构造函数
	**/
    SceneLevelTeaching();
	/**
	* @brief 进入场景
	**/
	void enter();
    /**
	* @brief 退出场景
	**/
	void exit();
	/**
	* @brief 更新场景
	**/
	void update();
    /**
	* @brief 绘制场景
	* @param camera 相机
	**/
	void draw(UtilCamera* camera);

private:
	// 动画指针
    UtilAnimation* m_animation=nullptr;
	// 位置
	UtilVector<int> pos{ 50,50 };
};
#pragma once

#include <scene/scene_level_base.h>
#include <player/player_fire_boy.h>

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

private:
    // 玩家指针
    PlayerFireBoy* m_fire_boy_player=nullptr;

};
#pragma once

#include <scene/scene_base.h>

/**
* @class SceneLevelBase
* @brief 关卡场景基类
**/
class SceneLevelBase : public SceneBase
{
public:
	/**
	* @brief 构造函数
	**/
    SceneLevelBase();
	/**
	* @brief 进入关卡场景
	**/
	virtual void enter()override;
    /**
	* @brief 退出关卡场景
	**/
	virtual void exit()override;
    /**
	* @brief 更新关卡场景
	**/
	virtual void update() = 0;
    /**
	* @brief 绘制关卡场景
	**/
	virtual void draw(UtilCamera* camera) = 0;

protected:
	// 背景纹理指针
    SDL_Texture* m_background=nullptr;
};
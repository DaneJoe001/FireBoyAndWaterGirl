#pragma once
#include <scene/scene_base.h>

/**
* @class SceneMain
* @brief 主场景类
**/
class SceneMain :public SceneBase
{
public:
	/**
	* @brief 构造函数
	**/
	SceneMain();
	/**
	* @brief 析构函数
	**/
	~SceneMain();
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
	// 背景纹理指针
	SDL_Texture* m_background = nullptr;
	// 标题纹理指针
	SDL_Texture* m_title = nullptr;
	// 光束纹理指针
	SDL_Texture* m_beam_cone_shaped = nullptr;
    // 开始按钮纹理指针
	SDL_Texture* m_start_button = nullptr;
    // 开始按钮图标信息
	TextureInfo* m_start_icon = nullptr;
};
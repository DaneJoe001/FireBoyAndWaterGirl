#pragma once

#include <functional>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <util/util_vector.h>
#include <util/util_camera.h>
#include <manager/manage_resource.h>
#include <manager/manage_button.h>

class SceneBase;

class ButtonBase
{
public:
	//引入场景指针，标识按钮所有权
	ButtonBase(SceneBase* scene, UtilVector pos);
	ButtonBase(SceneBase* scene,
		SDL_Texture* normal_texture,
		SDL_Texture* pressed_texture,
		UtilVector pos, UtilVector size);
	virtual ~ButtonBase();
	virtual void on_clicked();
	bool is_pressed(UtilVector mouse_pos);
	bool is_valid();
	void set_valid(bool is_valid);
	void draw(UtilCamera* camera);

protected:
	ManageResource& m_resource_manager = ManageResource::get_instance();
	ManageButton& m_button_manager = ManageButton::get_instance();
	// 默认尺寸，当图像未设置时
	// 使用SDL直接绘制按钮图案
	SDL_Texture* m_pressed_texture = nullptr;
	SDL_Texture* m_normal_texture = nullptr;
	// 考虑是否使用序列帧动画
	UtilVector m_pos = { 0,0 };
	UtilVector m_size = { 100,50 };
	bool m_is_pressed = false;
	bool m_is_valid = false;
	std::function<void()> m_on_clicked;
};
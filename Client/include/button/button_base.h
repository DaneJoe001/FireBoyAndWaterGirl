#pragma once

#include <functional>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <util/util_vector.h>
#include <util/util_camera.h>

//TODO: 添加动画类按钮
class SceneBase;

/**
* @class ButtonBase
* @brief 按钮基类,按钮在场景类中实现绘制,在管理类中实现点击事件
**/
class ButtonBase
{
public:
	/**
	 * @brief 使用默认按钮构造函数
	 * @param scene 按钮场景归属
	 * @param pos 设置动画绘制位置
	 * @param call_back 回调函数执行按钮逻辑
	 */
	ButtonBase(SceneBase* scene, UtilVector<int> pos,std::function<void()>call_back);
	/**
	 * @brief 使用自定义按钮构造函数
	 * @param scene 按钮场景归属
	 * @param normal_texture_info 正常状态按钮纹理
	 * @param pressed_texture_info 按下状态按钮纹理
	 * @param pos 设置动画绘制位置
	 * @param call_back 回调函数执行按钮逻辑
	 */
	ButtonBase(SceneBase* scene,
		TextureInfo* normal_texture_info,
		TextureInfo* pressed_texture_info,
		UtilVector<int> pos,
		std::function<void()>call_back);
	/**
	 * @brief 按钮析构函数
	 */
	virtual ~ButtonBase();
	/**
	* @brief 按钮点击事件
	**/
	virtual void on_press();
	/**
	* @brief 按钮释放事件
	**/
	virtual void on_release();
	/**
	 * @brief 判断鼠标是否在按钮上
	 * @param mouse_pos 鼠标位置
	 * @return true 在按钮上
	 * @return false 不在按钮上
	 */
	bool is_on_button(UtilVector<int> mouse_pos);
	/**
	 * @brief 判断按钮是否有效
	 * @return true 有效
	 * @return false 无效
	 */
	bool is_enable();
	/**
	 * @brief 设置按钮状态
	 * @param enable true 按钮可点击状态
	 * @param enable false 按钮不可点击状态
	 */
	void set_enable(bool enable);
	/**
	 * @brief 绘制按钮
	 * @param camera 绘制按钮的相机
	 */
	void draw(UtilCamera* camera);

protected:
	// 按钮按压状态纹理
	TextureInfo* m_pressed_texture = nullptr;
    // 按钮正常状态纹理
	TextureInfo* m_normal_texture = nullptr;
	// 按钮位置
	UtilVector<int> m_pos = { 0,0 };
	// 按钮尺寸
	UtilVector<int> m_size = { 100,50 };
	// 判断按钮是否按压
	bool m_is_pressed = false;
	// 判断当前按钮是否处于有效状态
	bool m_is_enable = false;
    // 按钮点击回调函数
	std::function<void()> m_on_clicked;
};
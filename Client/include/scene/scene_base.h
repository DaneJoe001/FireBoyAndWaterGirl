#pragma once

#include <vector>

#include <manager/manage_resource.h>
#include <util/util_camera.h>
//写一个连接管理类，连接信号与槽

class ButtonBase;

class SceneBase
{
public:
	virtual void enter() = 0;
	virtual void exit() = 0;
	virtual void update() = 0;
	virtual void draw(UtilCamera* camera) = 0;
	void add_button(ButtonBase* button);
	void remove_button(ButtonBase* button);
protected:
	ManageResource& m_resource_manager = ManageResource::get_instance();
	// 需要遍历按钮列表，检查是否有按钮被触发
	// 按钮本身和场景是关联的
	// 所以连接函数可以放在场景基类中
	// 但是每一个按钮都得连接一个处理函数
	// 最好将处理函数放在按钮的类成员中
	// 可能会存在一个问题，按钮的实现函数可能要访问场景成员等其他内容，可能会缺少权限
	std::vector<ButtonBase*> m_button_list;

};
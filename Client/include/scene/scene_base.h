#pragma once

#include <vector>
#include <manager/manage_resource.h>
#include <util/util_camera.h>

//TODO: 写一个连接管理类，连接信号与槽

class ButtonBase;
class EventKeyboard;

/**
* @class SceneBase
* @brief 场景基类，所有场景都继承于该类
* 需要遍历按钮列表，检查是否有按钮被触发
* 按钮本身和场景是关联的,所以连接函数可以
* 放在场景基类中但是每一个按钮都得连接一个
* 处理函数最好将处理函数放在按钮的类成员中
* 可能会存在一个问题，按钮的实现函数可能要
* 访问场景成员等其他内容，可能会缺少权限
**/
class SceneBase
{
public:
	~SceneBase();
	/**
	* @brief 进入场景，初始化场景，加载资源，设置场景参数，设置场景事件
	**/
	virtual void enter();
    /**
	* @brief 退出场景，释放资源，清理场景参数，清理场景事件
	**/
	virtual void exit();
    /**
	* @brief 更新场景，更新场景参数，更新场景事件
	**/
	virtual void update() = 0;
	/**
	* @brief 绘制场景，绘制场景参数，绘制场景事件
	**/
	virtual void draw(UtilCamera* camera) = 0;
	/**
	* @brief 添加按钮，添加按钮到按钮列表中
	* @param button 按钮指针
	**/
	void add_button(ButtonBase* button);
	/**
	* @brief 删除按钮，从按钮列表中删除按钮
	* @param button 按钮指针
	**/
	void remove_button(ButtonBase* button);
    /**
	* @brief 添加键盘事件，添加键盘事件到键盘事件列表中
	* @param key_event 键盘事件指针
	**/
	void add_keyboard_event(EventKeyboard* key_event);
    /**
	* @brief 删除键盘事件，从键盘事件列表中删除键盘事件
	* @param key_event 键盘事件指针
	**/
    void remove_keyboard_event(EventKeyboard* key_event);

protected:
	// 按钮列表
	std::vector<ButtonBase*> m_button_list;
	// 键盘事件列表
    std::vector<EventKeyboard*> m_event_list;

};
#pragma once

#include <list>

#include <util/util_vector.h>
class ButtonBase;

/**
* @class ManageButton
* @brief 按钮管理类
**/
class ManageButton
{
public:
    /**
    * @brief 获取按钮管理类单例引用
    * @return ManageButton& 单例
    **/
    static ManageButton& get_instance();
    /**
    * @brief 添加按钮
    * @param button 按钮指针
    **/
    void add_button(ButtonBase* button);
    /**
    * @brief 检查鼠标按下
    * @param mouse_pos 鼠标坐标
    **/
    void check_press(UtilVector<int> mouse_pos);
    /**
    * @brief 检查鼠标释放
    * @param mouse_pos 鼠标坐标
    **/
    void check_release(UtilVector<int> mouse_pos);

private:
    ManageButton() = default;
    ~ManageButton() = default;
    ManageButton(const ManageButton&) = delete;
    ManageButton(const ManageButton&&) = delete;
    ManageButton& operator=(const ManageButton&) = delete;
    ManageButton& operator=(const ManageButton&&) = delete;

private:
    // 按钮列表
    std::list<ButtonBase*> m_button_list;
};
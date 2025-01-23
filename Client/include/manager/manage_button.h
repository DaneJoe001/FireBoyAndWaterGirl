#pragma once

//按钮在场景类中实现绘制
//在管理类中实现点击事件
#include <list>

#include <util/util_vector.h>
#include <button/button_base.h>

class ManageButton
{
public:
    static ManageButton& get_instance();
    void add_button(ButtonBase* button);
    void check_clicked(UtilVector mouse_pos);
private:
    ManageButton() = default;
    ~ManageButton() = default;
    ManageButton(const ManageButton&) = delete;
    ManageButton(const ManageButton&&) = delete;
    ManageButton& operator=(const ManageButton&) = delete;
    ManageButton& operator=(const ManageButton&&) = delete;

private:
    std::list<ButtonBase*> m_button_list;

};
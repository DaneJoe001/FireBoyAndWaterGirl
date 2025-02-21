#pragma once

#include <unordered_map>
#include <string>

#include <util/util_animation.h>
#include <util/util_vector.h>
#include <util/util_camera.h>
#include <event/event_keyboard.h>

//TODO: 考虑是否添加角色速度限制。
//TODO: 添加角色移动屏障限制。

/**
* @class PlayerBase
* @brief 角色基类
* 角色的速度实现存在缺陷
* 键盘控制事件我觉得还是得像按钮一样
* 在构造函数进行键盘事件注册，而不是
* 维持一个键盘事件函数，我现在只实现
* 了场景中注册事件和按钮，没有在玩家
* 类中添加实现
**/
class PlayerBase
{
    public:
        /**
        * @brief 构造函数
        **/
        PlayerBase();
        /**
        * @brief 初始化角色,加载动画，
        * 设置角色位置，速度，加速度，大小等
        **/
        virtual void init()=0;
        /**
        * @brief 加载动画
        **/
        virtual void load_animation(std::string name,UtilVector<int> animation_pos);
        /**
        * @brief 角色事件处理
        **/
        virtual void event_keyboad(EventKeyboardType type, SDL_Keycode key);
        /**
        * @brief 设置角色位置
        **/
        void set_position(int x, int y);
        /**
        * @brief 设置角色速度
        **/
        void set_velocity(const int* x, const int* y);
        /**
        * @brief 设置角色加速度
        **/
        void set_acceleration(int x, int y);
        /**
        * @brief 获取角色位置
        **/
        UtilVector<int> get_position() const;
        /**
         *@brief 添加动画至当前动画列表
        **/
        void add_animation(std::string name);
        /**
         *@brief 从当前动画列表删除动画
        **/
        void remove_animation(std::string name);
        /**
         *@brief 绘制当前动画组
        **/
        void draw(UtilCamera* camera);
        /**
         *@brief 更新角色
        **/
        void update();

    protected:
        // 角色是否正在移动
        bool m_is_up = false;
        bool m_is_down = false;
        bool m_is_left = false;
        bool m_is_right = false;

    private:
        // 与角色有关的所有动画列表
        std::unordered_map<std::string, UtilAnimation> m_animations;
        // 当前角色动画列表
        std::unordered_map<std::string, UtilAnimation*> m_currentAnimation;
        // 角色位置
        UtilVector<int> m_pos=UtilVector<int>(0,0);
        // 角色大小
        UtilVector<int> m_size=UtilVector<int>(0,0);
        // 角色速度
        UtilVector<int> m_velocity=UtilVector<int>(0,0);
        // 角色加速度
        UtilVector<int> m_acceleration=UtilVector<int>(0,0);
};
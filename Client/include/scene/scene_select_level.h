#pragma once

#include <util/util_vector.h>

class UtilAnimation;

/**
* @class SceneSelectLevel
* @brief 关卡选择场景
**/
class SceneSelectLevel :public SceneBase
{
public:
    /**
    * @brief 构造函数
    **/
    SceneSelectLevel();
    /**
    * @brief 析构函数
    **/
    ~SceneSelectLevel();
    /**
    * @brief 绘制场景
    **/
    void draw(UtilCamera* camera)override;
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

private:
    // 背景图纹理指针
    SDL_Texture* m_background = nullptr;
    // 背景板动画指针
    UtilAnimation* m_board = nullptr;
};
#pragma once

#include <util/util_vector.h>

class UtilAnimation;

class SceneSelectLevel :public SceneBase
{
public:
    SceneSelectLevel();
    ~SceneSelectLevel();
    void draw(UtilCamera* camera)override;
    void enter()override;
    void exit()override;
    void update()override;
private:
    SDL_Texture* m_background = nullptr;
    UtilAnimation* m_animation = nullptr;
    UtilVector<int> pos{ 50,50 };
};
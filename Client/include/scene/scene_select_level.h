#include <scene/scene_base.h>

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
};
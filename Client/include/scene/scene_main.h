#pragma once
#include <scene/scene_base.h>

class SceneMain :public SceneBase
{
public:
	SceneMain();
	~SceneMain();
	void enter()override;
	void exit()override;
	void update()override;
	void draw(UtilCamera* camera)override;
private:
	SDL_Texture* m_background = nullptr;
	SDL_Texture* m_title = nullptr;
	SDL_Texture* m_beam_cone_shaped = nullptr;
};
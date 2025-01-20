#pragma once
#include <scene/scene_base.h>

class SceneSetting :public SceneBase
{
public:
	void enter()override;
	void exit()override;
	void update()override;
	void draw(UtilCamera* camera)override;
};
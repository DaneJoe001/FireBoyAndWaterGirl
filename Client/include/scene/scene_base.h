#pragma once

#include <manager/manage_resource.h>
#include <util/util_camera.h>

class SceneBase
{
public:
	virtual void enter() = 0;
	virtual void exit() = 0;
	virtual void update() = 0;
	virtual void draw(UtilCamera* camera) = 0;
protected:
	ManageResource& m_resource_manager = ManageResource::get_instance();
};
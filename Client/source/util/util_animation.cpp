#include <util/util_animation.h>
#include <util/util_timer.h>
#include <util/util_camera.h>
#include <resource/resource_definition.h>
#include <resource/resource_atlas.h>

UtilAnimation::UtilAnimation(ResourceAtlas* atlas, bool loop)
	:m_is_loop(loop),m_atlas(atlas)
{

}

bool UtilAnimation::is_loop()
{
	return m_is_loop;
}

void UtilAnimation::set_loop(bool loop)
{
	m_is_loop = loop;
}

void UtilAnimation::draw_frame(UtilCamera* camera)
{
	AtlasFrame frame = m_atlas->get_frame(m_current_index);
	if (frame.index == -1)
	{
		return;
	}
	TextureInfo& info = frame.texture;
	SDL_Rect dst = { m_pos.x,m_pos.y,info.dst.size.x,info.dst.size.y };
	SDL_Rect src = info.src.to_rect();
	camera->render_texture(info.texture, &src, &dst);
}

void UtilAnimation::on_update()
{
	if (m_current_index < m_atlas->get_frame_quantity()-1)
	{
		m_current_index++;
		return;
	}
	if (m_is_loop)
	{
		m_current_index = 0;
	}
}

void UtilAnimation::set_position(int x, int y)
{
	m_pos = { x,y };
}

void UtilAnimation::set_position(UtilVector<int> pos)
{
	m_pos = pos;
}

void UtilAnimation::update_position(UtilVector<int> velocity)
{
	m_pos += velocity;
}
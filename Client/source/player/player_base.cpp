#include <player/player_base.h>
#include <manager/manage_resource.h>
#include <util/util_animation.h>
#include <util/util_log.h>

PlayerBase::PlayerBase(){}

void PlayerBase::load_animation(std::string name,UtilVector<int> animation_pos)
{
	ResourceAtlas* atlas = ManageResource::get_instance().get_atlas(name);
	UtilAnimation animation(atlas, true);
    animation.set_position(animation_pos);
	m_animations.insert({ name, std::move(animation) });
}

void PlayerBase::set_position(int x, int y)
{
	m_pos={x,y};
}

void PlayerBase::set_velocity(int x, int y)
{
	m_velocity={x,y};
}

void PlayerBase::set_acceleration(int x, int y)
{
    m_acceleration={x,y};
}

UtilVector<int> PlayerBase::get_position() const
{
	return m_pos;
}

void PlayerBase::add_animation(std::string name)
{
	auto temp=m_animations.find(name);
	if (temp == m_animations.end())
	{
		std::string msg=LOG_STR("ERROR","Not found animation ");
		msg+=name;
		UtilLog::log(LogLevel::USER, msg.c_str());
		return;
	}
	m_currentAnimation[name] = &(temp->second);
}

void PlayerBase::remove_animation(std::string name)
{
	auto temp= m_currentAnimation.find(name);
	if (temp != m_currentAnimation.end())
	{
		m_currentAnimation.erase(temp);
	}
}

void PlayerBase::draw(UtilCamera* camera)
{
    for (auto& i : m_currentAnimation)
    {
		(i.second)->draw_frame(camera);
    }
}

void PlayerBase::update()
{
    for (auto& i : m_currentAnimation)
    {
		i.second->update_position(m_velocity);
    }
}
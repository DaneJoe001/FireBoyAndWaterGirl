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

void PlayerBase::set_velocity(const int* x,const int* y)
{
	if (x != nullptr)
	{
		m_velocity.x = *x;
	}
    if (y != nullptr)
    {
        m_velocity.y = *y;
    }
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
	int y= m_is_down-m_is_up;
	int x=m_is_right-m_is_left;
    //m_velocity.x=x*m_acceleration.x;
    //m_velocity.y=y*m_acceleration.y;
	m_velocity = { x,y };
    for (auto& i : m_currentAnimation)
    {
		i.second->update_position(m_velocity*6);
		i.second->on_update();
    }
}

void PlayerBase::event_keyboad(EventKeyboardType type, SDL_Keycode key)
{
    if (type == EventKeyboardType::PRESS)
    {
        switch (key)
        {
        case SDLK_UP:
            m_is_up = true;
            break;
        case SDLK_DOWN:
            m_is_down = true;
            break;
        case SDLK_LEFT:
            m_is_left = true;
            break;
        case SDLK_RIGHT:
            m_is_right = true;
            break;
        default:
            break;
        }
    }
    else if (type == EventKeyboardType::RELEASE)
    {
        switch (key)
        {
        case SDLK_UP:
            m_is_up = false;
            break;
        case SDLK_DOWN:
            m_is_down = false;
            break;
        case SDLK_LEFT:
            m_is_left = false;
            break;
        case SDLK_RIGHT:
            m_is_right = false;
            break;
        default:
            break;
        }
    }
}
#include "Moving_object.h"
#include "Controller.h"




Moving_object::Moving_object(object_code obj, int col, int row) 
	: Object(Resources::getInstance().getTextureAt(obj), Resources::getInstance().getSoundBuffer(obj), col, row)
{
	m_original_loc = get_sprite().getPosition();
	m_previous_loc = m_original_loc;
}


Moving_object::~Moving_object()
{
}


void Moving_object::reset_location()
{
	set_position(m_original_loc);
}

void Moving_object::set_prev_loc(sf::Vector2f data)
{
	m_previous_loc = data;
}

bool Moving_object::collision(Door& obj)
{
	set_position(m_previous_loc);
	return false;
}

bool Moving_object::collision(Wall& obj)
{
	set_position(get_previous_loc());

	return false;
};

sf::Vector2f Moving_object::get_previous_loc() const
{
	return m_previous_loc;
}

bool Moving_object::freeze_status() const
{
	return m_freeze;
}

void Moving_object::set_freeze(bool status)
{
	m_freeze = status;

	set_color((status) ? sf::Color::Color(40, 200, 245, 100) : sf::Color::White);
}


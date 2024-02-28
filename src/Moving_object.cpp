#include "Moving_object.h"
#include "Controller.h"




Moving_object::Moving_object(object_code obj, int col, int row) 
	: Object(Resources::getTextureAt(obj), Resources::getSoundBuffer(obj), col, row)
{
	m_original_loc = get_position();
	m_previous_loc = m_original_loc;
}


Moving_object::~Moving_object()
{
}


void Moving_object::reset_location()
{
	set_position(m_original_loc);
}

//void Moving_object::move(sf::Vector2f v2d)
//{
//	Object::move(v2d);
//}

void Moving_object::set_prev_loc(sf::Vector2f data)
{
	m_previous_loc = data;
}

bool Moving_object::collision(Door& obj)
{
	return ((Wall*)&obj)->collision(*this);
	//set_position(m_previous_loc);
	//return false;
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



 
//bool Moving_object::collision(Wall& wall)
//{
//	set_position(m_previous_loc);
//
//	return false;
//}

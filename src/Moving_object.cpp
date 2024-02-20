#include "Moving_object.h"
#include "Controller.h"


Moving_object::Moving_object(object_code obj, int col, int row) 
	: Object(Controller::getTexutre(obj), col, row)
{
	m_original_loc = get_position();
}


Moving_object::~Moving_object()
{
}

void Moving_object::reset_location()
{
	set_position(m_original_loc);
}

void Moving_object::move(sf::Vector2f v2d)
{
	Object::move(v2d);
}

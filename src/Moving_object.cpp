#include "Moving_object.h"


Moving_object::Moving_object(object_code obj, int col, int row) 
	: Object(/*m_texurs[obj]*/, int col, int row)
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

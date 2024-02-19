#include "Static_object.h"


Static_object::Static_object(object_code obj, int col, int row)
	: Object(const sf::m_texures[obj], int col, int row)
{
}


Static_object::~Static_object()
{
}

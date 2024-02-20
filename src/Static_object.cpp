#include "Static_object.h"


Static_object::Static_object(object_code obj, int col, int row)
	: Object(m_texures[obj], col, row)
{
}

Static_object::~Static_object()
{
}

void Static_object::draw(sf::RenderWindow& wind)
{
	Object::draw(wind);
}
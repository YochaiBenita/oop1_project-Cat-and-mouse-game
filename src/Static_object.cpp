#include "Static_object.h"
#include "Controller.h"


Static_object::Static_object(object_code obj, int col, int row)
	: Object(Resources::getInstance().getTextureAt(obj), Resources::getInstance().getSoundBuffer(obj), col, row)
{
}

Static_object::Static_object(object_code txture_code, object_code sound_code, int col, int row)
	:Object(Resources::getInstance().getTextureAt(txture_code), Resources::getInstance().getSoundBuffer(sound_code), col, row)
{
}

Static_object::~Static_object()
{
}

//void Static_object::to_delete()
//{
//	m_to_delete = true;
//}

//bool Static_object::to_erase()
//{
//	return m_to_delete;
//}

//void Static_object::draw(sf::RenderWindow& wind)
//{
//	Object::draw(wind);
//}
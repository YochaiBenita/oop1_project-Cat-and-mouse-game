#include "Static_object.h"
#include "Controller.h"


Static_object::Static_object(object_code obj, int col, int row)
	: Object(Resources::getInstance().getTextureAt(obj), col, row),
	m_sound(*Resources::getInstance().getSoundBuffer(obj))
{}

Static_object::Static_object(object_code txture_code, object_code sound_code, int col, int row)
	:Object(Resources::getInstance().getTextureAt(txture_code), col, row),
	m_sound(*Resources::getInstance().getSoundBuffer(sound_code))
{}

Static_object::~Static_object()
{
}

const sf::SoundBuffer* Static_object::get_sound()const
{
	return m_sound.getBuffer();
}

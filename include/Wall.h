#pragma once
#include <SFML/Graphics.hpp>
#include "Static_object.h"
//#include "Resources.h"
class Moving_object;

class Wall :public Static_object
{
public:
	Wall(int, int);

	virtual bool collision(Object& obj);
	virtual bool collision(Cat& catPlayer);
	virtual bool collision(Mouse& mousePlayer);

};
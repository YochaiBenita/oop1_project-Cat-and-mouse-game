#pragma once
#include <SFML/Graphics.hpp>
#include "Static_object.h"

class Door :public Static_object
{
public:
	Door(int, int);

	virtual bool collision(Object&);
	virtual bool collision(Cat&);
	virtual bool collision(Mouse&);

};
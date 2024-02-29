#pragma once
#include <SFML/Graphics.hpp>
#include "Static_object.h"

class Key :public Static_object
{
public:
	Key(int, int);

	virtual bool collision(Object&);
	virtual bool collision(Cat&);
	virtual bool collision(Mouse&);

};
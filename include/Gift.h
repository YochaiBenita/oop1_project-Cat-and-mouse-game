#pragma once
#include <SFML/Graphics.hpp>
#include "Static_object.h"
#include "Cat.h"
#include "Mouse.h"

class Gift : public Static_object
{
public:
	Gift(object_code obj, int col, int row);
	virtual ~Gift() = default;

	virtual void collision(Object& obj) { obj.collision(*this); }
	virtual void collision(Cat& catPlayer) { catPlayer.collision(*this); }
	virtual void collision(Mouse& mousePlayer) { mousePlayer.collision(*this); }

	//virtual void 
};
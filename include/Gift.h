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

	virtual void handleCollision(Cat& catPlayer) { catPlayer.handleCollision(*this); }
	virtual void handleCollision(Mouse& mousePlayer) { mousePlayer.handleCollision(*this); }

	virtual void 
};
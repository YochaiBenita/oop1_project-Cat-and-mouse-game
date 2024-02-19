#pragma once
#include <SFML/Graphics.hpp>
#include "Static_object.h"
#include "Cat.h"
#include "Mouse.h"
#include "Resources.h"

class Gfreeze :public Static_object
{
public:
	Gfreeze(int col, int row) : Static_object(freeze, col, row) {};
	virtual ~Gfreeze();

	void handleCollision(Object& obj) { obj.handleCollision(*this); }
	void handleCollision(Cat& catPlayer) { catPlayer.handleCollision(*this); }
	void handleCollision(Mouse& mousePlayer) { mousePlayer.handleCollision(*this); }

private:

};
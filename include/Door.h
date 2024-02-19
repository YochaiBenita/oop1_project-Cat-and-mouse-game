#pragma once
#include <SFML/Graphics.hpp>
#include "Static_object.h"
#include "Cat.h"
#include "Mouse.h"
#include "Resources.h"

class Door :public Static_object
{
public:
	Door(int col, int row) :Static_object(door, col, row) {};
	virtual ~Door();

	void handleCollision(Object& obj) { obj.handleCollision(*this); }
	void handleCollision(Cat& catPlayer) { catPlayer.handleCollision(*this); }
	void handleCollision(Mouse& mousePlayer) { mousePlayer.handleCollision(*this); }

private:

};
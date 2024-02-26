#pragma once
#include "Wall.h"
#include "Mouse.h"
#include "Cat.h"

Wall(int col, int row)
	:Static_object(Wall_t, col, row)
{
}

bool Wall::collision(Object& obj)
{
	return obj.collision(*this);
}

bool Wall::collision(Cat& catPlayer)
{
	return catPlayer.collision(*this);
}

bool Wall::collision(Mouse& mousePlayer)
{
	return mousePlayer.collision(*this);
}
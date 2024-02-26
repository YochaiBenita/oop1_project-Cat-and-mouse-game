#pragma once
#include "Wall.h"
#include "Mouse.h"
#include "Cat.h"

#include <iostream>

Wall::Wall(int col, int row)
	:Static_object(wall_t, col, row)
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
	std::cout << "blabla\n";
	return mousePlayer.collision(*this);
}



//bool Wall::collision(Moving_object& catPlayer)
//{
//	return catPlayer.collision(*this);
//}
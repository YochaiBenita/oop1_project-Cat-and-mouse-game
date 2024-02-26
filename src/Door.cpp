#pragma once
#include "Door.h"
#include "Mouse.h"
#include "Cat.h"

Door(int col, int row) 
	:Static_object(door_t, col, row) 
{
}

bool Door::collision(Object& obj)
{
	return obj.collision(*this);
}

bool Door::collision(Cat& catPlayer)
{
	return catPlayer.collision(*this);
}

bool Door::collision(Mouse& mousePlayer)
{
	return mousePlayer.collision(*this);
}
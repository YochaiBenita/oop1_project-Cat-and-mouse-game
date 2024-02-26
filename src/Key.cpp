#pragma once
#include "Key.h"
#include "Mouse.h"
#include "Cat.h"

Key::Key(int col, int row)
	:Static_object(key_t, col, row)
{
}

bool Key::collision(Object& obj)
{
	return obj.collision(*this);
}

bool Key::collision(Cat& catPlayer)
{
	return catPlayer.collision(*this);
}

bool Key::collision(Mouse& mousePlayer)
{
	return mousePlayer.collision(*this);
}
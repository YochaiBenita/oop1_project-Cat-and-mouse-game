#include "Glife.h"

Glife::Glife(int col, int row) : Gift(Glife_t, col, row) {};

bool Glife::collision(Object& obj)
{
	return obj.collision(*this);
}

bool Glife::collision(Cat& catPlayer) 
{
	return catPlayer.collision(*this);
}

bool Glife::collision(Mouse& mousePlayer) 
{
	return mousePlayer.collision(*this);
}
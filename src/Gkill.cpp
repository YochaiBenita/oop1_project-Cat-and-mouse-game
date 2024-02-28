#include "Gkill.h"

Gkill::Gkill(int col, int row) : Gift(Gkill_t, col, row) {};

bool Gkill::collision(Object& obj)
{
	return obj.collision(*this);
}

bool Gkill::collision(Cat& catPlayer)
{
	return catPlayer.collision(*this);
}

bool Gkill::collision(Mouse& mousePlayer)
{
	return mousePlayer.collision(*this);
}

void Gkill::open_gift()
{
	
}

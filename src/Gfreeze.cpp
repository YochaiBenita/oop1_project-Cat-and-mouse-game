#include "Gfreeze.h"
#include "Controller.h"

Gfreeze::Gfreeze(int col, int row) : Gift(Gfreeze_t, col, row) {};
//
//bool Gfreeze::collision(Object& obj)
//{
//	return obj.collision(*this);
//}
//
//bool Gfreeze::collision(Cat& catPlayer)
//{
//	return catPlayer.collision(*this);
//}
//
//bool Gfreeze::collision(Mouse& mousePlayer)
//{
//	return mousePlayer.collision(*this);
//}

void Gfreeze::open_gift()
{
	//std::cout << "freeze\n";
	Controller::freeze_gift();
}

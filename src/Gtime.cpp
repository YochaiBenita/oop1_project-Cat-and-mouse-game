#include "Gtime.h"
#include "Controller.h"

Gtime::Gtime(int col, int row) : Gift(Gtime_t, col, row)
{}

void Gtime::open_gift()
{
	Controller::time_gift();
}


//bool Gtime::collision(Object& obj)
//{
//	return obj.collision(*this);
//}
//
//bool Gtime::collision(Cat& catPlayer)
//{
//	return catPlayer.collision(*this);
//}
//
//bool Gtime::collision(Mouse& mousePlayer)
//{
//	return mousePlayer.collision(*this);
//}
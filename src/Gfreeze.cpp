#include "Gfreeze.h"
#include "Controller.h"

Gfreeze::Gfreeze(int col, int row) : Gift(Gfreeze_t, col, row) {};

void Gfreeze::open_gift()
{
	Controller::freeze_gift();
}

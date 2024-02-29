#include "Glife.h"
#include "Controller.h"


Glife::Glife(int col, int row) : Gift(Glife_t, col, row) {}

void Glife::open_gift()
{
	Controller::life_gift();
}


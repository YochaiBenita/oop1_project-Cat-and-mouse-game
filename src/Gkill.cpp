#include "Gkill.h"
#include "Controller.h"

Gkill::Gkill(int col, int row) : Gift(Gkill_t, col, row) {};

void Gkill::open_gift()
{
	Controller::kill_gift();
}

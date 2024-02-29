#include "Gtime.h"
#include "Controller.h"

Gtime::Gtime(int col, int row) : Gift(Gtime_t, col, row)
{}

void Gtime::open_gift()
{
	Controller::time_gift();
}


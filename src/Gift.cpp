#include "Gift.h"
#include "Controller.h"

Gift::Gift(object_code obj, int col, int row)
	:Static_object(obj, gift_t, col, row)
{
}

bool Gift::collision(Object& obj)
{
	return obj.collision(*this);
}

bool Gift::collision(Cat& catPlayer)
{
	return catPlayer.collision(*this);
}

bool Gift::collision(Mouse& mousePlayer)
{
	return mousePlayer.collision(*this);
}
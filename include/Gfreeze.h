#pragma once
#include <SFML/Graphics.hpp>
#include "Gift.h"
//#include "Resources.h"

class Gfreeze :public Gift
{
public:
	Gfreeze(int col, int row) : Gift (Gfreeze_t, col, row) {};
	virtual ~Gfreeze() = default;

	virtual void collision(Object& obj) { obj.collision(*this); }
	virtual void collision(Cat& catPlayer) { catPlayer.collision(*this); }
	virtual void collision(Mouse& mousePlayer) { mousePlayer.collision(*this); }

private:

};
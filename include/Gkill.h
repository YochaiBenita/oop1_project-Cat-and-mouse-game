#pragma once
#include <SFML/Graphics.hpp>
#include "Gift.h"
//#include "Resources.h"

class Gkill :public Gift
{
public:
	Gkill(int col, int row) : Gift (Gkill_t, col, row) {};
	virtual ~Gkill() = default;

	virtual bool collision(Object& obj) { obj.collision(*this); }
	virtual bool collision(Cat& catPlayer) { catPlayer.collision(*this); }
	virtual bool collision(Mouse& mousePlayer) { mousePlayer.collision(*this); }

private:

};

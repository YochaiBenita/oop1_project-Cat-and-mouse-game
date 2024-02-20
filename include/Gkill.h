#pragma once
#include <SFML/Graphics.hpp>
#include "Gift.h"
//#include "Resources.h"

class Gkill :public Gift
{
public:
	Gkill(int col, int row) : Gift (Gkill_t, col, row) {};
	virtual ~Gkill() = default;

	//void handleCollision(Object& obj) { obj.handleCollision(*this); }
	virtual void handleCollision(Cat& catPlayer) { catPlayer.handleCollision(*this); }
	virtual void handleCollision(Mouse& mousePlayer) { mousePlayer.handleCollision(*this); }

private:

};

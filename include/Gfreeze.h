#pragma once
#include <SFML/Graphics.hpp>
#include "Gift.h"
//#include "Resources.h"

class Gfreeze :public Gift
{
public:
	Gfreeze(int col, int row) : Gift (Gfreeze_t, col, row) {};
	virtual ~Gfreeze() = default;

	//void handleCollision(Object& obj) { obj.handleCollision(*this); }
	virtual void handleCollision(Cat& catPlayer) { catPlayer.handleCollision(*this); }
	virtual void handleCollision(Mouse& mousePlayer) { mousePlayer.handleCollision(*this); }

private:

};
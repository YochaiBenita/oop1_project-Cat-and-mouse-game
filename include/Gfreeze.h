#pragma once
#include <SFML/Graphics.hpp>
#include "Gift.h"
#include "Resources.h"

class Gfreeze :public Gift
{
public:
	Gfreeze(int col, int row) : Gift (freeze, col, row) {};
	virtual ~Gfreeze();

	//void handleCollision(Object& obj) { obj.handleCollision(*this); }
	void handleCollision(Cat& catPlayer) { catPlayer.handleCollision(*this); }
	void handleCollision(Mouse& mousePlayer) { mousePlayer.handleCollision(*this); }

private:

};
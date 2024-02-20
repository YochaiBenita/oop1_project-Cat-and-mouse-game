#pragma once
#include <SFML/Graphics.hpp>
#include "Gift.h"
#include "Resources.h"

class Gkill :public Gift
{
public:
	Gkill(int col, int row) : Gift (kill, col, row) {};
	//virtual ~Gkill();

	//void handleCollision(Object& obj) { obj.handleCollision(*this); }
	void handleCollision(Cat& catPlayer) { catPlayer.handleCollision(*this); }
	void handleCollision(Mouse& mousePlayer) { mousePlayer.handleCollision(*this); }

private:

};

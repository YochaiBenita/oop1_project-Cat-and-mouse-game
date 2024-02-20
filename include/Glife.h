#pragma once
#include <SFML/Graphics.hpp>
#include "Gift.h"
#include "Resources.h"

class Glife :public Gift
{
public:
	Glife(int col, int row) : Gift(life, col, row) {};
	virtual ~Glife();

	//void handleCollision(Object& obj) { obj.handleCollision(*this); }
	void handleCollision(Cat& catPlayer) { catPlayer.handleCollision(*this); }
	void handleCollision(Mouse& mousePlayer) { mousePlayer.handleCollision(*this); }

private:

};
#pragma once
#include <SFML/Graphics.hpp>
#include "Gift.h"
//#include "Resources.h"

class Glife :public Gift
{
public:
	Glife(int col, int row) : Gift(Glife_t, col, row) {};
	virtual ~Glife() = default;

	//void handleCollision(Object& obj) { obj.handleCollision(*this); }
	virtual void handleCollision(Cat& catPlayer) { catPlayer.handleCollision(*this); }
	virtual void handleCollision(Mouse& mousePlayer) { mousePlayer.handleCollision(*this); }

private:

};
#pragma once
#include <SFML/Graphics.hpp>
#include "Gift.h"
#include "Resources.h"

class Gtime :public Gift
{
public:
	Gtime(int col, int row) : Gift (time, col, row) {};
	//virtual ~Gtime();

	//void handleCollision(Object& obj) { obj.handleCollision(*this); }
	void handleCollision(Cat& catPlayer) { catPlayer.handleCollision(*this); }
	void handleCollision(Mouse& mousePlayer) { mousePlayer.handleCollision(*this); }

private:

};
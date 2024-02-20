#pragma once
#include <SFML/Graphics.hpp>
#include "Static_object.h"
#include "Resources.h"

class Wall :public Static_object
{
public:
	Wall(int col, int row) : Static_object(wall_t, col, row) {};
	virtual ~Wall() {};

	//void handleCollision(Object& obj) { obj.handleCollision(*this); }
	void handleCollision(Cat& catPlayer) { catPlayer.handleCollision(*this); }
	void handleCollision(Mouse& mousePlayer) { mousePlayer.handleCollision(*this); }

private:

};
#pragma once
#include <SFML/Graphics.hpp>
#include "Static_object.h"
#include "Resources.h"

class Cheese :public Static_object
{
public:
	Cheese(int col, int row) : Static_object(cheese, col, row) {};
	virtual ~Cheese();

	//void handleCollision(Object& obj) { obj.handleCollision(*this); }
	void handleCollision(Cat& catPlayer) { catPlayer.handleCollision(*this); }
	void handleCollision(Mouse& mousePlayer) { mousePlayer.handleCollision(*this); }

private:

};
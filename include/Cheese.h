#pragma once
#include <SFML/Graphics.hpp>
#include "Static_object.h"
//#include "Resources.h"

class Cheese :public Static_object
{
public:
	Cheese(int col, int row) : Static_object(cheese_t, col, row) {};
	//virtual ~Cheese() {};

	virtual void collision(Object& obj) { obj.collision(*this); }
	virtual void collision(Cat& catPlayer) { catPlayer.collision(*this); }
	virtual void collision(Mouse& mousePlayer) { mousePlayer.collision(*this); }

private:

};
#pragma once
#include <SFML/Graphics.hpp>
#include "Static_object.h"
//#include "Resources.h"

class Wall :public Static_object
{
public:
	Wall(int col, int row) : Static_object(wall_t, col, row) {};
	//virtual ~Wall() = default;

	virtual void collision(Object& obj) { obj.collision(*this); }
	virtual void collision(Cat& catPlayer) { catPlayer.collision(*this); }
	virtual void collision(Mouse& mousePlayer) { mousePlayer.collision(*this); }

private:

};
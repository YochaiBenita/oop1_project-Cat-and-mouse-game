#pragma once
#include <SFML/Graphics.hpp>
#include "Gift.h"
//#include "Resources.h"

class Gtime :public Gift
{
public:
	Gtime(int col, int row) : Gift (time, col, row) {};
	virtual ~Gtime() = default;

	virtual bool collision(Object& obj) { obj.collision(*this); }
	virtual bool collision(Cat& catPlayer) { catPlayer.collision(*this); }
	virtual bool collision(Mouse& mousePlayer) { mousePlayer.collision(*this); }

private:

};
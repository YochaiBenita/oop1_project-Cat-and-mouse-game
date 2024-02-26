#pragma once
#include <SFML/Graphics.hpp>
#include "Gift.h"
//#include "Resources.h"

class Glife :public Gift
{
public:
	Glife(int col, int row) : Gift(Glife_t, col, row) {};
	virtual ~Glife() = default;

	virtual bool collision(Object& obj) { obj.collision(*this); }
	virtual bool collision(Cat& catPlayer) { catPlayer.collision(*this); }
	virtual bool collision(Mouse& mousePlayer) { mousePlayer.collision(*this); }

private:

};
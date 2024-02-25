#pragma once
#include <SFML/Graphics.hpp>
#include "Gift.h"
//#include "Resources.h"

class Glife :public Gift
{
public:
	Glife(int col, int row) : Gift(Glife_t, col, row) {};
	virtual ~Glife() = default;

	virtual void collision(Object& obj) { obj.collision(*this); }
	virtual void collision(Cat& catPlayer) { catPlayer.collision(*this); }
	virtual void collision(Mouse& mousePlayer) { mousePlayer.collision(*this); }

private:

};
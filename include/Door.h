#pragma once
#include <SFML/Graphics.hpp>
#include "Static_object.h"
//#include "Resources.h"

const int SCORE_OF_DOOR = 2;

class Door :public Static_object
{
public:
	Door(int col, int row) :Static_object(door_t, col, row) {};
	//virtual ~Door() = default;

	virtual void collision(Object& obj) { obj.collision(*this); }
	virtual void collision(Cat& catPlayer) { catPlayer.collision(*this); }
	virtual void collision(Mouse& mousePlayer) { mousePlayer.collision(*this); }

	virtual void to_delete() { m_to_delete = true; }


private:

};
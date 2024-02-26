#pragma once
#include <SFML/Graphics.hpp>
#include "Static_object.h"
//#include "Resources.h"

const int SCORE_OF_DOOR = 2;

class Door :public Static_object
{
public:
	Door(int col, int row);
	//virtual ~Door() = default;

	virtual bool collision(Object& obj);
	virtual bool collision(Cat& catPlayer);
	virtual bool collision(Mouse& mousePlayer);

	//virtual void to_delete() { m_to_delete = true; }


private:

};